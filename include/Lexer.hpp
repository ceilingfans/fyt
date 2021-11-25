#ifndef FYT_LEXER
#define FYT_LEXER

#include <vector>
#include <string>

#include "Token.hpp"

namespace Fyt
{
	namespace Lexer
	{
		std::vector<Token> parse(const std::string& p_source);
		void endToken(Token& p_token, std::vector<Token>& p_tokens);
	} /* namespace Lexer */
} /* namespace Fyt */

#endif /* FYT_LEXER */