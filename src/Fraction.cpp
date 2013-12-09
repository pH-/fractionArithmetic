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

int main() {

	std::string expr;
	std::cout << "Fraction Arithmetic" << std::endl;
	std::cout << "Enter a binary fraction expression :"<<std::endl;
	std::cin>>expr;
	expressionParser *expression = new expressionParser(expr);
	frac* result = expression->computeExpression();
	expression->displayFirstOperand();
	expression->displaySecondOperand();
	expression->displayOperator();


	std::cout<<"result:";
	result->display();

	return 0;
}
