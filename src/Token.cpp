#include <utility>

#include "Token.hpp"

namespace Fyt
{
	Token::Token(TokenType p_type, TokenName p_name, std::string p_literal) : type(p_type), name(p_name), literal(std::move(p_literal)) {}
	Token::Token() = default;

	/* Getters */
	TokenType Token::getType() const { return type; }
	TokenName Token::getName() const { return name; }
	std::string Token::getLiteral() const { return literal; }

	/* Setters */
	void Token::setType(TokenType p_type) { type = p_type; }
	void Token::setName(TokenName p_name) { name = p_name; }
	void Token::setLiteral(std::string p_literal) { literal = std::move(p_literal); }

} /* namespace Fyt */