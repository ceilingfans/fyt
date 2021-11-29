#include "ast/VariableExpression.hpp"

namespace Fyt
{
	llvm::Value *VariableExpression::codegen()
	{
		llvm::Value* v = NamedValues[Name];
		if (!v)
			return LogErrorV("Fyt: reference error: unknown variable"); // TODO: implement better error message

		return v;
	}
}