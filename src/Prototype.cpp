#include "ast/Prototype.hpp"

namespace Fyt
{

	llvm::Function *Prototype::codegen()
	{
		std::vector<llvm::Type*> doubles(args.size(), llvm::Type::getDoubleTy(Context));
		llvm::FunctionType* fnT = llvm::FunctionType::get(llvm::Type::getDoubleTy(Context), doubles, false);
		llvm::Function* fn = llvm::Function::Create(fnT, llvm::Function::ExternalLinkage, name, Module.get());

		size_t i = 0;
		for (auto &arg : fn->args())
		{
			arg.setName(args[i++]);
		}

		return fn;
	}

	std::string Prototype::getName() const
	{
		return name;
	}
}