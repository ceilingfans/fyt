#ifndef FYT_TOKEN
#define FYT_TOKEN

#include <string>

namespace Fyt
{
	enum class TokenType
	{
		INVALID = -1,
		KEYWORDS,
		OPERATORS,
		STRING_LITERAL,
		NUMBER_LITERAL,
		IDENTIFIERS,
	};

	enum class TokenName
	{
		/*
		 * OP = OPERATOR
		 */
		INVALID = -1,
		OP_ARITHMETIC_PLUS,
		OP_ARITHMETIC_MINUS,
		OP_ARITHMETIC_DIVIDE,
		OP_ARITHMETIC_MULTIPLY,
		NUMBER_INTEGER32,
		NUMBER_DOUBLE,
	};

	class Token
	{
	public:
		Token(TokenType p_type, TokenName p_name, std::string p_literal);
		TokenType getType() const;
		TokenName getName() const;
		std::string getLiteral() const;
	private:
		TokenType type;
		TokenName name;
		std::string literal;
	};
} /* namespace Fyt */

#endif /* FYT_TOKEN */