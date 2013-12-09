/*
 * fracParser.cpp
 *
 *  Created on: Dec 7, 2013
 *      Author: phanindrabhagavatula
 */

#include "expressionParser.h"
#include <sstream>
#include <iostream>

expressionParser::expressionParser(std::string exp) : expression(exp), op1(NULL), op2(NULL), oprtr(' ')
{
}

expressionParser::~expressionParser() {
	delete(op1);
	delete(op2);
}

void expressionParser::displayFirstOperand() const
{
	op1->display();
}

void expressionParser::displaySecondOperand() const
{
	op2->display();
}

void expressionParser::displayOperator() const
{
	std::cout<<"operator:"<<oprtr<<std::endl;
}

frac* expressionParser::computeExpression()
{
	parseBinaryExpression();
	switch(oprtr)
	{
	case '+':
		return *op1+*op2;
	case '-':
		return *op1-*op2;
	case '*':
		return *op1 * *op2;
	case '/':
		return *op1/ *op2;
	default:
		return NULL;
	}
}
frac* expressionParser::getFractionFromString(std::string fractionStr)
{
	_DATATYPE_ numerator, dinominator;

	size_t separatorPosition = fractionStr.find('\\');
	std::istringstream iss (fractionStr.substr(0,separatorPosition));
	iss>>numerator;
	iss.clear();
	iss.str(fractionStr.substr(separatorPosition+1, std::string::npos));
	iss>>dinominator;
	frac *fterm = new frac(numerator, dinominator);
	return fterm;
}

void expressionParser::parseBinaryExpression()
{
	char operators[] = {'+', '-', '*', '/'};
	std::string operand1, operand2;
	size_t oprtrlocation;
	for(int i=0; i<4; i++)
	{
		oprtrlocation = expression.find(operators[i]);
		if(oprtrlocation!=std::string::npos)
		{
			std::istringstream iss (expression.substr(0,oprtrlocation));
			iss>>operand1;
			iss.clear();
			iss.str(expression.substr(oprtrlocation+1, std::string::npos));
			iss>>operand2;
			break;
		}
	}

	op1 	= getFractionFromString(operand1);
	op2 	= getFractionFromString(operand2);
	oprtr 	= expression[oprtrlocation];
}
