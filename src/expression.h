/*
 * expression.h
 *
 *  Created on: Dec 9, 2013
 *      Author: pbhagava
 */

#ifndef EXPRESSION_H_
#define EXPRESSION_H_

class expression {
public:
	expression();
	virtual ~expression();

	virtual void display() const =0;

	virtual expression& operator+(expression& op)=0;
	virtual expression& operator-(expression& op)=0;
	virtual expression& operator*(expression& op)=0;
	virtual expression& operator/(expression& op)=0;
	virtual expression& operator-()=0;

};

#endif /* EXPRESSION_H_ */
