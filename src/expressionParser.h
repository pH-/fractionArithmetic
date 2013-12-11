/*
 *  expressionParser.h
 *
 *  Created on: Dec 7, 2013
 *      Author: phanindrabhagavatula
 */

#ifndef EXPRESSIONPARSER_H_
#define EXPRESSIONPARSER_H_

#include <string>
#include <map>

#include "frac.h"

class expressionParser {

public:
	expressionParser(std::string exp);
	virtual 	~expressionParser();
	std::string getPostFixedExpression();

private:
	void 		shuntingYard();
	bool     	isOperator(char o);
	bool		isOperand(char o);
	int			getPrecedence(char o);

private:
	enum operatorType
	{
		NONE,
		UNARY,
		BINARY
	};

	std::map<char,int> operatorPrecedenceTable;

	enum operatorType expectedOperatorType;

	std::string 	inFixExpression;
	std::string 	postFixExpression;
};

#endif /* EXPRESSIONPARSER_H_ */
