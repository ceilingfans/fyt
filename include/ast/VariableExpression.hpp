#ifndef FYT_VAR_EXPR
#define FYT_VAR_EXPR

#include <utility>

#include "ast/BaseExpression.hpp"
#include "Logger.hpp"

namespace Fyt
{
	class VariableExpression : public Expression
	{
	public:
		explicit VariableExpression(std::string name)
		: Name(std::move(name)) {};
		llvm::Value* codegen() override;
	private:
		std::string Name;
	};
}

#endif /* FYT_VAR_EXPR */