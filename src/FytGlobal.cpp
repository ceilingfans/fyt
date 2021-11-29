#include "FytGlobal.hpp"

namespace Fyt
{
	extern llvm::LLVMContext Context;
	extern llvm::IRBuilder<> Builder;
	extern std::unique_ptr<llvm::Module> Module;
	extern std::map<std::string, llvm::Value*> NamedValues;
}