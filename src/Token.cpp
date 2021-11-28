#include <utility>
#include <iostream>
#include <fstream>

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

	std::string Token::debugInfo() const
	{
		return std::string("type: ") + TokenTypeStringified[to_underlying(getType()) + 1] + "\nliteral:\n" + getLiteral();
	}
} /* namespace Fyt */