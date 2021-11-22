#include <utility>

#include "Token.hpp"

namespace Fyt
{
	Token::Token(TokenType p_type, TokenName p_name, std::string p_literal) : type(p_type), name(p_name), literal(std::move(p_literal)) {}

	TokenType Token::getType() const { return type; }
	TokenName Token::getName() const { return name; }
	std::string Token::getLiteral() const { return literal; }

} /* namespace Fyt */