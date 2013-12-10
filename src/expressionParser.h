/*
 *  expressionParser.h
 *
 *  Created on: Dec 7, 2013
 *      Author: phanindrabhagavatula
 */

#ifndef FRACPARSER_H_
#define FRACPARSER_H_

#include <string>
#include <map>

#include "frac.h"
#define _DATATYPE_ int

class expressionParser {

public:
	expressionParser(std::string exp);
	virtual 	~expressionParser();
	std::string getPostFixedExpression();

	//frac*		 computeExpression();
	//void		 displayFirstOperand() const;
	//void		 displaySecondOperand() const;
	//void	     displayOperator()const;

private:
	void 		shuntingYard();
	bool     	isOperator(char o);
	bool		isOperand(char o);
	int			getPrecedence(char o);
//	void 		 parseBinaryExpression();
//	frac*		 getFractionFromString(std::string fractionStr);

private:
	enum operatorType
	{
		NONE,
		UNARY,
		BINARY
	};

	std::map<char,int> operatorPrecedence;

	enum operatorType expectedOperatorType;

	std::string 	inFixExpression;
	std::string 	postFixExpression;
};

#endif /* FRACPARSER_H_ */
