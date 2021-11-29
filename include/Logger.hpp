#ifndef FYT_LOGGER
#define FYT_LOGGER

#include "ast/BaseExpression.hpp"
#include "ast/Prototype.hpp"

namespace Fyt
{
	std::unique_ptr<Expression> LogError(const char* s);
	std::unique_ptr<Prototype> LogErrorP(const char* s);
	llvm::Value* LogErrorV(const char* s);
}

#endif /* FYT_LOGGER */