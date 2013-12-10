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
#include "expression.h"

int main() {
	std::string expr;
	std::cout << "Fraction Arithmetic" << std::endl;
	std::cout << "Enter a binary fraction expression :"<<std::endl;
	std::cin>>expr;
	std::cout<<expr<<std::endl;
	expressionParser *expression = new expressionParser(expr);
	std::cout<<expression->getPostFixedExpression()<<std::endl;

	expressionSolver *solver = new expressionSolver(expression->getPostFixedExpression());
	std::cout<<"result:";
	solver->solveExpression()->display();

	return 0;
}
