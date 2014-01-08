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
#include "boost/shared_ptr.hpp"
class frac;
typedef boost::shared_ptr<frac> fracSharedPtr;
class expressionSolver {
public:
	expressionSolver(std::string expr);
	virtual 		~expressionSolver();
	fracSharedPtr 	solveExpression();

private:  //private functions
	bool 			isOperator(std::string o);
	void 			useOperator(std::string o, std::stack<fracSharedPtr>& postFixExprStack);
	void 			pushOperandToStack(std::string o, std::stack<fracSharedPtr>& postFixExprStack);

private:
	std::string		postFixedExpression;

};

#endif /* EXPRESSIONSOLVER_H_ */
