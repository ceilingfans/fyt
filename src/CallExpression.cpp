#include "ast/CallExpression.hpp"

namespace Fyt
{
	llvm::Value *CallExpression::codegen()
	{
		llvm::Function* fn = Module->getFunction(Callee);
		if (!fn)
			return LogErrorV("Fyt: reference error: unknown function"); // TODO: implement better error message

		if (fn->arg_size() != Args.size())
			return LogErrorV("Fyt: type error: incorrect number of arguments"); // TODO: implement better error message

		std::vector<llvm::Value *> ArgsV;
		for (auto& arg : Args)
		{
			ArgsV.push_back(arg->codegen());

			if (!ArgsV.back())
				return nullptr;
		}

		return Builder.CreateCall(fn, ArgsV, "calltmp");
	}
}