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
	std::cout<<expr<<std::endl;
	expressionParser *expression = new expressionParser(expr);
	std::cout<<expression->getPostFixedExpression()<<std::endl;



//	std::cout<<"result:";
//	result->display();

	return 0;
}
