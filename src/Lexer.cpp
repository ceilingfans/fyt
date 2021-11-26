#include <iostream>
#include <cstdlib>

#include "Lexer.hpp"

namespace Fyt
{
	namespace Lexer
	{
		std::vector<Token> parse(const std::string &p_source)
		{
			size_t index = 0;
			size_t line = 0;
			std::vector<Token> tokens;
			Token currentToken;

			for (const char &current: p_source)
			{
				++index;
				if (currentToken.getType() == TokenType::STRING_ESCAPE_SEQUENCE)
				{
					switch (current)
					{
						case 'n': // newline
							currentToken.setLiteral(currentToken.getLiteral().append(1, '\n'));
							break;
						case 't': // tab
							currentToken.setLiteral(currentToken.getLiteral().append(1, '\t'));
							break;
						case 'r': // carriage return
							currentToken.setLiteral(currentToken.getLiteral().append(1, '\r'));
							break;
						case '\\': // backlash
							currentToken.setLiteral(currentToken.getLiteral().append(1, '\\'));
							break;
						default:
							// TODO: error message
							std::cout << "Fyt: Invalid string escape sequence '" << current << "'" << std::endl;
							exit(-1);
					}
					currentToken.setType(TokenType::STRING_LITERAL);
					continue;
				} else if (currentToken.getType() == TokenType::COMMENT_POTENTIAL && current != '/')
				{
					currentToken.setType(TokenType::OPERATOR);
					endToken(currentToken, tokens);
					continue;
				}

//				if (isdigit(current))
//				{
//					if (currentToken.getType() == TokenType::INVALID)
//					{
//						currentToken.setType(TokenType::INTEGER_LITERAL);
//					} else if (currentToken.getType() == TokenType::DOUBLE_POTENTIAL)
//					{
//						currentToken.setType(TokenType::DOUBLE_LITERAL);
//					}
//					currentToken.setLiteral(currentToken.getLiteral().append(1, current));
//				}

				switch (current)
				{
					case '0':
					case '1':
					case '2':
					case '3':
					case '4':
					case '5':
					case '6':
					case '7':
					case '8':
					case '9':
						if (currentToken.getType() == TokenType::INVALID)
						{
							currentToken.setType(TokenType::INTEGER_LITERAL);
						} else if (currentToken.getType() == TokenType::DOUBLE_POTENTIAL)
						{
							currentToken.setType(TokenType::DOUBLE_LITERAL);
						} else if (currentToken.getType() == TokenType::COMMENT_POTENTIAL)
						{
							currentToken.setType(TokenType::OPERATOR);
							endToken(currentToken, tokens);
							currentToken.setType(TokenType::INTEGER_LITERAL);
						}
						currentToken.setLiteral(currentToken.getLiteral().append(1, current));
						break;
					case '.':
						if (currentToken.getType() == TokenType::INVALID)
						{
							currentToken.setType(TokenType::DOUBLE_POTENTIAL);
							currentToken.setLiteral(currentToken.getLiteral().append(1, current));
						} else if (currentToken.getType() == TokenType::INTEGER_LITERAL)
						{
							currentToken.setType(TokenType::DOUBLE_LITERAL);
							currentToken.setLiteral(currentToken.getLiteral().append(1, current));
						} else if (currentToken.getType() == TokenType::STRING_LITERAL)
						{
							currentToken.setLiteral(currentToken.getLiteral().append(1, current));
						} else if (currentToken.getType() == TokenType::DOUBLE_LITERAL)
						{
							// TODO: error message
							std::cout << "Fyt: Unexpected token '.' in a double literal" << std::endl;
							exit(-1);
						} else
						{
							endToken(currentToken, tokens);
							currentToken.setType(TokenType::OPERATOR);
							currentToken.setLiteral(".");
							endToken(currentToken, tokens);
						}
						break;
					case '{':
					case '}':
					case '(':
					case ')':
					case '[':
					case ']':
					case '=':
					case '-':
					case '+':
					case '*':
					case '>':
					case '<':
					case ';':
					case ',':
						if (currentToken.getType() != TokenType::STRING_LITERAL)
						{
							endToken(currentToken, tokens);
							currentToken.setType(TokenType::OPERATOR);
							currentToken.setLiteral(currentToken.getLiteral().append(1, current));
							endToken(currentToken, tokens);
						} else
						{
							currentToken.setLiteral(currentToken.getLiteral().append(1, current));
						}
						break;
					case ' ':
					case '\t':
						if (currentToken.getType() == TokenType::STRING_LITERAL || currentToken.getType() == TokenType::COMMENT)
						{
							currentToken.setLiteral(currentToken.getLiteral().append(1, current));
						} else
						{
							endToken(currentToken, tokens);
						}
						break;
					case '\r':
					case '\n':
						endToken(currentToken, tokens);
						++line;
						break;
					case '"':
					case '\'':
						if (currentToken.getType() != TokenType::STRING_LITERAL)
						{
							endToken(currentToken, tokens);
							currentToken.setType(TokenType::STRING_LITERAL);
						} else if (currentToken.getType() == TokenType::STRING_LITERAL)
						{
							endToken(currentToken, tokens);
						}
						break;
					case '\\':
						if (currentToken.getType() == TokenType::STRING_LITERAL)
						{
							currentToken.setType(TokenType::STRING_ESCAPE_SEQUENCE);
						} else
						{
							// TODO: error message
							throw std::runtime_error("invalid operator");
						}
						break;
					case '/':
						if (currentToken.getType() == TokenType::STRING_LITERAL)
						{
							currentToken.setLiteral(currentToken.getLiteral().append(1, current));
						} else if (currentToken.getType() == TokenType::COMMENT_POTENTIAL)
						{
							currentToken.setType(TokenType::COMMENT);
						} else
						{
							endToken(currentToken, tokens);
							currentToken.setType(TokenType::COMMENT_POTENTIAL);
							currentToken.setLiteral(currentToken.getLiteral().append(1, current));
						}
						break;
					default:
						if (currentToken.getType() == TokenType::INVALID || currentToken.getType() == TokenType::INTEGER_LITERAL || currentToken.getType() == TokenType::DOUBLE_LITERAL)
						{
							endToken(currentToken, tokens);
							currentToken.setType(TokenType::IDENTIFIER);
						}
						currentToken.setLiteral(currentToken.getLiteral().append(1, current));
						break;
				}
			}
			endToken(currentToken, tokens);
			return tokens;
		}

		void endToken(Token& p_token, std::vector<Token>& p_tokens)
		{
			if (p_token.getType() == TokenType::COMMENT)
			{
				// TODO: implement logger
			} else if (p_token.getType() != TokenType::INVALID)
			{
				p_tokens.push_back(p_token);
			}
			if (p_token.getType() == TokenType::DOUBLE_POTENTIAL)
			{
				if (p_token.getLiteral() == ".")
				{
					p_token.setType(TokenType::OPERATOR);
				} else
				{
					p_token.setType(TokenType::DOUBLE_LITERAL);
				}
			}

			p_token.setType(TokenType::INVALID);
			p_token.setLiteral("");
		}
	} /* namespace Lexer */
} /* namespace Fyt */