/*
 * Frac.cpp
 *
 *  Created on: Dec 7, 2013
 *      Author: phanindrabhagavatula
 */

#include "frac.h"
#include <iostream>

frac::frac(int n, int d):numerator(n), dinominator(d)
{
}
frac::frac(frac& f): numerator(f.getNumerator()), dinominator(f.getDinominator())
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

frac& frac::operator+(frac& f)
{
	int resultNumerator, resultDinominator;

	resultDinominator = getLcm(this->getDinominator(), f.getDinominator());

//	std::cout<<"result dinom:"<<resultDinominator<<std::endl;
//
//	std::cout<<"f1:"<<this->getNumerator()<<"/"<<this->getDinominator()<<std::endl;
//	std::cout<<"f2:"<<f.getNumerator()<<"/"<<f.getDinominator()<<std::endl;

	resultNumerator   = this->getNumerator()*(resultDinominator/this->getDinominator()) +
							f.getNumerator()*(resultDinominator/f.getDinominator());
	frac *result = new frac(resultNumerator, resultDinominator);
	return *result;
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
