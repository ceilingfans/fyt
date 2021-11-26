#include <utility>
#include <iostream>

#include "Token.hpp"

namespace Fyt
{
	template <typename E>
	constexpr typename std::underlying_type<E>::type to_underlying(E e) noexcept {
		return static_cast<typename std::underlying_type<E>::type>(e);
	}

	Token::Token() = default;

	/* Getters */
	TokenType Token::getType() const { return type; }
	std::string Token::getLiteral() const { return literal; }

	/* Setters */
	void Token::setType(TokenType p_type) { type = p_type; }
	void Token::setLiteral(std::string p_literal) { literal = std::move(p_literal); }

	void Token::print() const {
		std::cout << "{ " << R"("type": ")" << TokenTypeStringified[to_underlying(getType()) + 1] << R"(", "literal": ")" << getLiteral() << "\" }," << std::endl;
	}

} /* namespace Fyt */