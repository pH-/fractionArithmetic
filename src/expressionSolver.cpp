/*
 * expressionSolver.cpp
 *
 *  Created on: Dec 10, 2013
 *      Author: pbhagava
 */

#include "expressionSolver.h"
#include <stack>
#include <iostream>
#include <vector>
#include <sstream>
#include "frac.h"

/**
 * Constructor
 */
expressionSolver::expressionSolver(std::string expr):postFixedExpression(expr)
{
}
/**
 * Destructor
 */
expressionSolver::~expressionSolver()
{
}

/**
 * Solves a Post Fix Expression. It parses the Postfix expression string, creates objects
 * for operands and uses a stack to keep track of results.
 */
frac* expressionSolver::solveExpression()
{
	std::stack<frac*>	postFixExprStack;
	std::stringstream exprstream(postFixedExpression);
	std::string currToken;
	while(exprstream>>currToken)
	{
		if(isOperator(currToken))
			useOperator(currToken, postFixExprStack);
		else
			pushOperandToStack(currToken, postFixExprStack);
	}
	frac *result = postFixExprStack.top()->clone();
	postFixExprStack.pop();
	return result;
}


/**
 * Uses Operator
 * If current token parsed is an operator, pulls required number of operands from stack and operates on them.
 */
void expressionSolver::useOperator(std::string currToken, std::stack<frac*>& postFixExprStack)
{
	frac *op1;
	frac *op2;
	switch(currToken.c_str()[0])
	{
	case '/':
		op2 = postFixExprStack.top();
		postFixExprStack.pop();
		op1 = postFixExprStack.top();
		if(op2->getNumerator()==0)
		{
			throw "Invalid Expression: Divide by 0 error";
		}
		postFixExprStack.pop();
		postFixExprStack.push(&(*op1/ *op2));
		break;
	case '*':
		op2 = postFixExprStack.top();
		postFixExprStack.pop();
		op1 = postFixExprStack.top();
		postFixExprStack.pop();
		postFixExprStack.push(&(*op1**op2));
		break;
	case '+':
		op2 = postFixExprStack.top();
		postFixExprStack.pop();
		op1 = postFixExprStack.top();
		postFixExprStack.pop();
		postFixExprStack.push(&(*op1+*op2));
		break;
	case '-':
		op2 = postFixExprStack.top();
		postFixExprStack.pop();
		op1 = postFixExprStack.top();
		postFixExprStack.pop();
		postFixExprStack.push(&(*op1-*op2));
		break;
	case 'u':
		frac *op1 = postFixExprStack.top();
		postFixExprStack.pop();
		postFixExprStack.push(&(-(*op1)));
		break;
	}
}

/**
 * Push Operand to Stack.
 * This function converts each integer obtained to a fraction class object. This facilitates
 * use of operators on operands without checking if its a fraction or an integer.
 */
void expressionSolver::pushOperandToStack(std::string currToken, std::stack<frac*>& postFixExprStack)
{
	int operand;
	std::stringstream optrss(currToken);
	optrss>>operand;
	frac *currOperand = new frac(operand,1);
	postFixExprStack.push(currOperand);
}
/**
 * Checks if current token is an operator
 */
bool expressionSolver::isOperator(std::string o)
{
	return (o.c_str()[0]=='+' ||
			o.c_str()[0]=='-' ||
			o.c_str()[0]=='*' ||
			o.c_str()[0]=='/' ||
			o.c_str()[0]=='u');
}
