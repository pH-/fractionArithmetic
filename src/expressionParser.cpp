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
	char prevChar = ' ';
	char currChar;
	for(int i=0; i<exprLen; i++)
	{
		currChar = inFixExpression[i];
		if(isOperand(currChar))
		{
			if(isOperand(prevChar))
				outputQueue.erase(outputQueue.length()-1,std::string::npos);
			outputQueue.push_back(currChar);
			outputQueue.push_back(' ');
			expectedOperatorType = expressionParser::BINARY;
		}
		else if(isOperator(currChar))
		{
			while(!operatorStack.empty() &&
				  isOperator(operatorStack.top()[0]) &&
				  getPrecedence(currChar)<=getPrecedence(operatorStack.top()[0]))
			{
				outputQueue.push_back(operatorStack.top()[0]);
				outputQueue.push_back(' ');
				operatorStack.pop();
			}

			if(expectedOperatorType==expressionParser::UNARY && currChar=='-')
				currChar = 'u';
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
				outputQueue.push_back(' ');
				operatorStack.pop();
				topOperator=operatorStack.top()[0];
			}
			if(!operatorStack.empty())
			{
				operatorStack.pop();
			}
		}
		prevChar = currChar;
	}
	while(!operatorStack.empty() && isOperator(operatorStack.top()[0]))
	{
		outputQueue.push_back(operatorStack.top()[0]);
		outputQueue.push_back(' ');
		operatorStack.pop();
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
