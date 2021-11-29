#ifndef FYT_EXPR_AST
#define FYT_EXPR_AST

#include "llvm/IR/IRBuilder.h"
#include "FytGlobal.hpp"

namespace Fyt
{
	class Expression
	{
	public:
		virtual ~Expression() = default;
		virtual llvm::Value* codegen() = 0;
	};
}

#endif /* FYT_EXPR_AST */