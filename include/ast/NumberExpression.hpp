#ifndef FYT_NUM_EXPR
#define FYT_NUM_EXPR

#include "ast/BaseExpression.hpp"

namespace Fyt
{
	class NumberExpression : public Expression
	{
	public:
		explicit NumberExpression(double val) : val(val) {}
		llvm::Value* codegen() override;
	private:
		double val;
	};
}

#endif /* FYT_NUM_EXPR */