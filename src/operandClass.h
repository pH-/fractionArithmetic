/*
 * terminal.h
 *
 *  Created on: Dec 9, 2013
 *      Author: pbhagava
 */

#ifndef OPERANDCLASS_H_
#define OPERANDCLASS_H_

#include "expression.h"
class operandClass : public expression
{
public:
	operandClass();
	virtual ~operandClass();

	virtual void display() const =0;

	virtual expression& operator+(expression& op)=0;
	virtual expression& operator-(expression& op)=0;
	virtual expression& operator*(expression& op)=0;
	virtual expression& operator/(expression& op)=0;
	virtual expression& operator-()=0;
};

#endif /* TERMINAL_H_ */
