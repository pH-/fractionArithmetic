//============================================================================
// Name        : Fraction.cpp
// Author      : pH
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include "frac.h"
#include "expressionParser.h"
#include "expressionSolver.h"


typedef boost::shared_ptr<frac> fracSharedPtr;


/*! \mainpage Fraction Expression Solver
 *
 * \section intro_sec Introduction
 *
 * This code solves an arithmetic expression. It makes calculations in fractions
 * and computes the result as a fraction. The Expression is parsed using Shunting Yard algorithm.
 *
 *
 * \section Usage
 * The following restrictions apply while providing an expression.
 * 1. Operands can be Integers or Fractions
 * 2. Fractions can be specified as 3/4
 * 3. Operators Supported: /, *, +, -, unary -
 * 4. To use a unary -(minus) please use brackes. Ex: (-12)
 * 5. Spaces cannot be part of the expression.
 */
void terminator()
{
	std::cerr << "There was an unknown Exception\n";
	abort();  // forces abnormal termination
}
int main() {
	std::set_terminate (terminator);

	std::string expr;
	std::cout << "Fraction Arithmetic" << std::endl;
	std::cout << "Restrictions:"<<std::endl;
	std::cout << "1. Operands: integers or fractions."<<std::endl;
	std::cout << "2. Fractions can be specified as 3/4"<<std::endl;
	std::cout << "3. Operators Supported: /, *, +, -, unary -"<<std::endl;
	std::cout << "4. To use a unary -(minus) please use brackes. Ex: (-12)"<<std::endl;

	std::cout << "Enter an expression:"<<std::endl;
	std::cin>>expr;

	expressionParser *fraction = new expressionParser(expr);

	std::string postFixExpr;

	try {
		postFixExpr = fraction->getPostFixedExpression();
	}
	catch(char const* e)
	{
		delete(fraction);
		std::cerr<<e<<std::endl;
	}

	expressionSolver *solver = new expressionSolver(postFixExpr);

//	frac* res;
	fracSharedPtr result;
	try {
		result = solver->solveExpression();
		std::cout<<"result:"<<std::endl;
		result->display();
	}
	catch(char const* e)
	{
		delete(solver);
		std::cerr<<e<<std::endl;
	}
	return 0;
}
