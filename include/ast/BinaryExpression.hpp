#ifndef FYT_BIN_EXPR
#define FYT_BIN_EXPR

#include "Logger.hpp"
#include "ast/BaseExpression.hpp"

namespace Fyt
{
	class BinaryExpression : public Expression
	{
	public:
		BinaryExpression(char op, std::unique_ptr<Expression> left, std::unique_ptr<Expression> right)
		: op(op), left(std::move(left)), right(std::move(right)) {}
		llvm::Value* codegen() override;
	private:
		char op;
		std::unique_ptr<Expression> left, right;
	};
}

#endif /* FYT_BIN_EXPR */