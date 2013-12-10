/*
 * expressionSolver.h
 *
 *  Created on: Dec 10, 2013
 *      Author: pbhagava
 */

#ifndef EXPRESSIONSOLVER_H_
#define EXPRESSIONSOLVER_H_
#include <string>
#include <stack>

class expression;

class expressionSolver {
public:
	expressionSolver(std::string expr);
	virtual 		~expressionSolver();
	expression*&	 	solveExpression();
private:  //private functions
	bool 			isOperator(std::string o);
	bool 			isOperand(std::string o);
	void 			useOperator(std::string o, std::stack<expression*>& postFixExprStack);
	void 			pushOperandToStack(std::string o, std::stack<expression*>& postFixExprStack);

private:
	std::string		postFixedExpression;

};

#endif /* EXPRESSIONSOLVER_H_ */
