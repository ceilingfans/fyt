#include "ast/Function.hpp"

namespace Fyt
{
	llvm::Function *Function::codegen()
	{
		llvm::Function* fn = Module->getFunction(Proto->getName());
		if (!fn)
			fn = Proto->codegen();

		if (!fn)
			return nullptr;

		llvm::BasicBlock* bb = llvm::BasicBlock::Create(Context, "entry", fn);
		Builder.SetInsertPoint(bb);
		NamedValues.clear();
		for (auto &arg : fn->args())
			NamedValues.insert(std::make_pair(arg.getName(), &arg));

		if (llvm::Value* returnValue = Body->codegen())
		{
			Builder.CreateRet(returnValue);
			llvm::verifyFunction(*fn);

			return fn;
		}

		fn->eraseFromParent();
		return nullptr;
	}
}