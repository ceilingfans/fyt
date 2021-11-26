#ifndef FYT_TOKEN
#define FYT_TOKEN

#include <string>

namespace Fyt
{
	enum class TokenType
	{
		INVALID = -1,
		KEYWORD,
		OPERATOR,
		STRING_LITERAL,
		STRING_ESCAPE_SEQUENCE,
		INTEGER_LITERAL,
		DOUBLE_LITERAL,
		IDENTIFIER,
		COMMENT_POTENTIAL,
		DOUBLE_POTENTIAL,
		COMMENT,
	};

	static const char* TokenTypeStringified[] = {
		"INVALID",
		"KEYWORD",
		"OPERATOR",
		"STRING_LITERAL",
		"STRING_ESCAPE_SEQUENCE",
		"INTEGER_LITERAL",
		"DOUBLE_LITERAL",
		"IDENTIFIER",
		"COMMENT_POTENTIAL",
		"DOUBLE_POTENTIAL",
		"COMMENT",
	};

	class Token
	{
	public:
		Token();
		TokenType getType() const;
		std::string getLiteral() const;
		void setType(TokenType p_type);
		void setLiteral(std::string p_literal);
		void print() const;
	private:
		TokenType type { TokenType::INVALID };
		std::string literal;
	};
} /* namespace Fyt */

#endif /* FYT_TOKEN */