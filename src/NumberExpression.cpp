#include "ast/NumberExpression.hpp"

namespace Fyt
{
	llvm::Value *NumberExpression::codegen()
	{
		return llvm::ConstantFP::get(Context, llvm::APFloat(val));
	}
}