#ifndef FYT
#define FYT

#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"

namespace Fyt
{
	extern llvm::LLVMContext Context;
	extern llvm::IRBuilder<> Builder;
	extern std::unique_ptr<llvm::Module> Module;
	extern std::map<std::string, llvm::Value*> NamedValues;
}

#endif /* FYT */