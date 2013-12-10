/*
 * fracParser.cpp
 *
 *  Created on: Dec 7, 2013
 *      Author: phanindrabhagavatula
 */

#include "expressionParser.h"
#include <sstream>
#include <iostream>
#include <stack>

expressionParser::expressionParser(std::string exp) :
expectedOperatorType(expressionParser::UNARY),
inFixExpression(exp)
{
	std::pair<char, int> p1('/',2);
	std::pair<char, int> p2('*',2);
	std::pair<char, int> p3('+',1);
	std::pair<char, int> p4('-',1);
	operatorPrecedence.insert(p1);
	operatorPrecedence.insert(p2);
	operatorPrecedence.insert(p3);
	operatorPrecedence.insert(p4);
}

expressionParser::~expressionParser() {
//	delete(op1);
//	delete(op2);
}

std::string expressionParser::getPostFixedExpression()
{
	if(postFixExpression.empty())
		shuntingYard();

	return postFixExpression;
}

void expressionParser::shuntingYard()
{
	std::string outputQueue;
	std::stack<std::string> operatorStack;
	int exprLen = inFixExpression.length();
	for(int i=0; i<exprLen; i++)
	{
		char currChar = inFixExpression[i];
		std::cout<<"currChar:"<<currChar<<std::endl;
		if(isOperand(currChar))
		{
			outputQueue.push_back(currChar);
			expectedOperatorType = expressionParser::BINARY;
		}
		else if(isOperator(currChar))
		{
			char operatorStackTop = operatorStack.top()[0];
			while(isOperator(operatorStackTop) &&
				  getPrecedence(currChar)<=getPrecedence(operatorStackTop))
			{
				outputQueue.push_back(operatorStackTop);
				operatorStack.pop();
				operatorStackTop = operatorStack.top()[0];
			}
			std::string currCharStrObj(1,currChar);
			operatorStack.push(currCharStrObj);
		}
		else if(currChar=='(')
		{
			std::string currCharStrObj(1,currChar);
			operatorStack.push(currCharStrObj);
			expectedOperatorType = expressionParser::UNARY;
		}
		else if(currChar==')')
		{
			char topOperator=operatorStack.top()[0];
			while(topOperator!='(')
			{
				if(operatorStack.empty())
				{
					std::cout<<"flag error and exit::::";
					break;
				}
				outputQueue.push_back(topOperator);
				operatorStack.pop();
				topOperator=operatorStack.top()[0];
			}
			if(!operatorStack.empty())
			{
				operatorStack.pop();
			}
		}
	}
	while(!operatorStack.empty() && isOperator(operatorStack.top()[0]))
	{
		outputQueue.push_back(operatorStack.top()[0]);
		outputQueue.pop_back();
	}
	postFixExpression = outputQueue;
}

bool expressionParser::isOperator(char o)
{
	return (o=='+' || o=='-' || o== '*' || o=='/');
}

bool expressionParser::isOperand(char o)
{
	return (o>='0' && o<='9');
}

int expressionParser::getPrecedence(char o)
{
	if(expectedOperatorType == expressionParser::UNARY)
		return 3;
	else
		return operatorPrecedence[o];
}
//void expressionParser::displayFirstOperand() const
//{
//	op1->display();
//}

//void expressionParser::displaySecondOperand() const
//{
//	op2->display();
//}

//void expressionParser::displayOperator() const
//{
//	std::cout<<"operator:"<<oprtr<<std::endl;
//}

//frac* expressionParser::computeExpression()
//{
//	parseBinaryExpression();
//	switch(oprtr)
//	{
//	case '+':
//		return *op1+*op2;
//	case '-':
//		return *op1-*op2;
//	case '*':
//		return *op1 * *op2;
//	case '/':
//		return *op1/ *op2;
//	default:
//		return NULL;
//	}
//}
//frac* expressionParser::getFractionFromString(std::string fractionStr)
//{
//	_DATATYPE_ numerator, dinominator;
//
//	size_t separatorPosition = fractionStr.find('\\');
//	std::istringstream iss (fractionStr.substr(0,separatorPosition));
//	iss>>numerator;
//	iss.clear();
//	iss.str(fractionStr.substr(separatorPosition+1, std::string::npos));
//	iss>>dinominator;
//	frac *fterm = new frac(numerator, dinominator);
//	std::cout<<"fraction formed:";
//	fterm->display();
//	return fterm;
//}
//
//void expressionParser::parseBinaryExpression()
//{
//	char operators[] = {'+', '-', '*', '/'};
//	std::string operand1, operand2;
//	size_t oprtrlocation;
//	for(int i=0; i<4; i++)
//	{
//		oprtrlocation = expression.find(operators[i]);
//		if(oprtrlocation!=std::string::npos)
//		{
//			std::istringstream iss (expression.substr(0,oprtrlocation));
//			iss>>operand1;
//			iss.clear();
//			iss.str(expression.substr(oprtrlocation+1, std::string::npos));
//			iss>>operand2;
//			break;
//		}
//	}
//
//	op1 	= getFractionFromString(operand1);
//	op2 	= getFractionFromString(operand2);
//	oprtr 	= expression[oprtrlocation];
//}
