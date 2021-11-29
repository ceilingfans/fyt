#include "ast/BinaryExpression.hpp"

namespace Fyt
{

	llvm::Value *BinaryExpression::codegen()
	{
		llvm::Value* l = left->codegen();
		llvm::Value* r = right->codegen();

		if (!l || !r)
			return nullptr;

		switch (op)
		{
			case '+':
				return Builder.CreateFAdd(l, r, "addtmp");
			case '-':
				return Builder.CreateFSub(l, r, "subtmp");
			case '*':
				return Builder.CreateFMul(l, r, "multmp");
			case '<':
				l = Builder.CreateFCmpULT(l, r, "cmptmp");
				return Builder.CreateUIToFP(l, llvm::Type::getDoubleTy(Context), "booltmp");
			default:
				return LogErrorV("invalid binary operator");
		}
	}
}
