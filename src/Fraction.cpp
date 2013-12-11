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
#include "frac.h"
void terminator()
{
	std::cerr << "There was an unknown Exception\n";
	abort();  // forces abnormal termination
}
int main() {
	std::set_terminate (terminator);

	std::string expr;
	std::cout << "Fraction Arithmetic" << std::endl;
	std::cout << "Enter a binary fraction frac :"<<std::endl;
	std::cin>>expr;
	//std::cout<<expr<<std::endl;
	expressionParser *frac = new expressionParser(expr);

	std::string postFixExpr;

	try {
		postFixExpr = frac->getPostFixedExpression();
	}
	catch(char const* e)
	{
		delete(frac);
		std::cerr<<e<<std::endl;
	}

	expressionSolver *solver = new expressionSolver(postFixExpr);
	frac* res = solver->solveExpression();
	std::cout<<"result:"<<std::endl;

//	res->display();

	return 0;
}
