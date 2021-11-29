#ifndef FYT_PROTO
#define FTY_PROTO

#include <utility>

#include "ast/BaseExpression.hpp"

namespace Fyt
{
	class Prototype : public Expression
	{
	public:
		Prototype(std::string name, std::vector<std::string> args)
		: name(std::move(name)), args(std::move(args)) {};
		llvm::Function* codegen() override;
		std::string getName() const;
	private:
		std::string name;
		std::vector<std::string> args;
	};
}

#endif /* FYT_PROTO */