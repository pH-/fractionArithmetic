/*
 *  expressionParser.cpp
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
			if(expectedOperatorType==expressionParser::NONE)
				throw "Parse Error. Invalid operator usage";

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
			expectedOperatorType = expressionParser::NONE;
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
					throw "Invalid Expression: Unbalanced brackets";
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
		else if(currChar==' ')
		{
			std::cout<<"found a space"<<std::endl;
		}
		else
		{
			throw "Parse Error. Invalid character in input Expression";
		}
		prevChar = currChar;
	}
	while(!operatorStack.empty())
	{
		if(isOperator(operatorStack.top()[0]))
		{
			outputQueue.push_back(operatorStack.top()[0]);
			outputQueue.push_back(' ');
			operatorStack.pop();
		}
		else
		{
			throw "Parse Error. Unbalanced Brackets";
		}
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
