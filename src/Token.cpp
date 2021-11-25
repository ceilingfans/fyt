#include <utility>
#include <iostream>

#include "Token.hpp"

namespace Fyt
{
	template <typename E>
	constexpr typename std::underlying_type<E>::type to_underlying(E e) noexcept {
		return static_cast<typename std::underlying_type<E>::type>(e);
	}

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

	void Token::print() {
		std::cout << "{ " << "type: " << TokenTypeStringified[to_underlying(getType()) + 1] << ", literal: " << getLiteral() << " }" << std::endl;
	}

} /* namespace Fyt */