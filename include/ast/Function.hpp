#ifndef FYT_FN
#define FYT_FN

#include "ast/Prototype.hpp"

namespace Fyt
{
	class Function
	{
	public:
		Function(std::unique_ptr<Prototype> proto, std::unique_ptr<Expression> body)
		: Proto(std::move(proto)), Body(std::move(body)) {};
		llvm::Function* codegen();
	private:
		std::unique_ptr<Prototype> Proto;
		std::unique_ptr<Expression> Body;
	};
}

#endif /* FYT_FN */