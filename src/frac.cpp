/*
 * Frac.cpp
 *
 *  Created on: Dec 7, 2013
 *      Author: phanindrabhagavatula
 */

#include "frac.h"
#include <iostream>
#include <cmath>

frac::frac(int n, int d):numerator(n), dinominator(d)
{
	if(dinominator==0)
	{
		std::cout<<"throw error"<<std::endl;
	}
	this->reduceFraction();
}
frac::frac(frac& f): numerator(f.getNumerator()), dinominator(f.getDinominator())
{
}
frac::frac(frac* f): numerator(f->getNumerator()), dinominator(f->getDinominator())
{
}
frac::~frac() {
	// TODO Auto-generated destructor stub
}

int frac::getNumerator()
{
	return numerator;
}

int frac::getDinominator()
{
	return dinominator;
}

void frac::display() const
{
	if(std::abs(dinominator)!=1)
	{
		if(numerator<dinominator)
			std::cout<<numerator<<"/"<<dinominator<<std::endl;
		else
		{
			std::cout<<numerator/dinominator<<" "<<numerator%dinominator<<"/"<<dinominator<<std::endl;
		}
	}
	else
		std::cout<<numerator<<std::endl;
}

void frac::reduceFraction()
{
	bool negative = ((numerator<0 && dinominator>0)||(numerator>0 && dinominator<0));
	bool positive = numerator<0 && dinominator<0;
	int gcdOfNumDinom = getGcd(std::abs(numerator), std::abs(dinominator));
	if(gcdOfNumDinom!=1)
	{
		numerator/=gcdOfNumDinom;
		dinominator/=gcdOfNumDinom;
	}
	if(negative)
	{
		numerator = -std::abs(numerator);
		dinominator = std::abs(dinominator);
	}
	if(positive)
	{
		numerator = std::abs(numerator);
		dinominator = std::abs(dinominator);
	}
}
frac* frac::clone()
{
	return new frac(*this);
}
frac& frac::operator+(frac& secondOperand)
{
	frac *f = dynamic_cast<frac*> (&secondOperand);
	int resultNumerator, resultDinominator;
	resultDinominator = getLcm(this->getDinominator(), f->getDinominator());
	resultNumerator   = this->getNumerator()*(resultDinominator/this->getDinominator()) +
							f->getNumerator()*(resultDinominator/f->getDinominator());

	numerator = resultNumerator;
	dinominator = resultDinominator;
	reduceFraction();
	return *this;
}

frac& frac::operator-(frac& secondOperand)
{
	frac *f = dynamic_cast<frac*> (&secondOperand);
	int resultNumerator, resultDinominator;
	resultDinominator = getLcm(this->getDinominator(), f->getDinominator());
	resultNumerator   = this->getNumerator()*(resultDinominator/this->getDinominator()) -
							f->getNumerator()*(resultDinominator/f->getDinominator());

	numerator = resultNumerator;
	dinominator = resultDinominator;
	reduceFraction();
	return *this;
}
frac& frac::operator*(frac& secondOperand)
{
	frac *f = dynamic_cast<frac*> (&secondOperand);
	int resultNumerator, resultDinominator;

	resultDinominator = this->getDinominator()*f->getDinominator();
	resultNumerator   = this->getNumerator()*f->getNumerator();

	numerator = resultNumerator;
	dinominator = resultDinominator;
	reduceFraction();
	return *this;
}
frac& frac::operator/(frac& secondOperand)
{
	frac *f = dynamic_cast<frac*> (&secondOperand);
	int resultNumerator, resultDinominator;

	resultDinominator = this->getDinominator()*f->getNumerator();
	resultNumerator   = this->getNumerator()*f->getDinominator();

	numerator = resultNumerator;
	dinominator = resultDinominator;
	reduceFraction();
	return *this;
}

frac& frac::operator-()
{
	numerator = -numerator;
	return *this;
}

int frac::getLcm(int a, int b)
{
	return (a*b)/getGcd(a, b);
}

int frac::getGcd(int a, int b)
{
	if(b>a)
	{
		a^=b;
		b^=a;
		a^=b;
//		std::cout<<"a:"<<a<<" b:"<<b<<std::endl;
	}
	while(b>0)
	{
		int temp = b;
		b		 = a%b;
		a		 = temp;
	}
//	std::cout<<"calculated gcd:"<<a<<std::endl;
	return a;
}
