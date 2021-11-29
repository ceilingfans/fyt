#ifndef FYT_CALL_EXPR
#define FYT_CALL_EXPR

#include <utility>

#include "BaseExpression.hpp"
#include "Logger.hpp"

namespace Fyt
{
	class CallExpression : public Expression
	{
	public:
		CallExpression(std::string callee, std::vector<std::unique_ptr<Expression>> args)
		: Callee(std::move(callee)), Args(std::move(args)) {};
		llvm::Value* codegen() override;
	private:
		std::string Callee;
		std::vector<std::unique_ptr<Expression>> Args;
	};
}

#endif /* FYT_CALL_EXPR */