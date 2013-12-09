/*
 * fracParser.h
 *
 *  Created on: Dec 7, 2013
 *      Author: phanindrabhagavatula
 */

#ifndef FRACPARSER_H_
#define FRACPARSER_H_

#include <string>
#include "frac.h"
#define _DATATYPE_ int

class expressionParser {

public:
	expressionParser(std::string exp);
	virtual ~expressionParser();

	frac*		 computeExpression();

	void		 displayFirstOperand() const;
	void		 displaySecondOperand() const;
	void	     displayOperator()const;

private:
	void 		 parseBinaryExpression();
	frac*		 getFractionFromString(std::string fractionStr);

private:
	std::string 	expression;
	frac*           op1;
	frac*    		op2;
	char			oprtr;
};

#endif /* FRACPARSER_H_ */
