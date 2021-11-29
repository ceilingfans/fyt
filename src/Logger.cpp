#include "Logger.hpp"

namespace Fyt
{
	std::unique_ptr<Expression> LogError(const char* s)
	{
		fprintf(stderr, "Fyt: Log: error: %s\n", s);
		return nullptr;
	}

	std::unique_ptr<Prototype> LogErrorP(const char* s)
	{
		LogError(s);
		return nullptr;
	}

	llvm::Value* LogErrorV(const char* s)
	{
		LogError(s);
		return nullptr;
	}
}