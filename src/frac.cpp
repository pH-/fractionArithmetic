/*
 * Frac.cpp
 *
 *  Created on: Dec 7, 2013
 *      Author: phanindrabhagavatula
 */

#include "frac.h"
#include <iostream>
#include <cmath>

/** Constructs Fraction
 *
 * The function creates the fraction object and stores it in its reduced form.
 */
frac::frac(int n, int d):numerator(n), dinominator(d)
{
	if(dinominator==0)
	{
		std::cout<<"throw error"<<std::endl;
	}
	this->reduceFraction();
}
/**
 * Copy Constructor: Copies and creates a frac object using reference to frac object
 */
frac::frac(frac& f): numerator(f.getNumerator()), dinominator(f.getDinominator())
{
}

/**
 *
 * Copy Constructor: Copies and creates a frac object using pointer to another frac object
 */
frac::frac(frac* f): numerator(f->getNumerator()), dinominator(f->getDinominator())
{
}

/**  Clones an object
 *
 */
frac* frac::clone()
{
	return new frac(*this);
}

/**  Destructor
 *
 */
frac::~frac()
{
}
/**  Retrieves Numerator
 *
 */
int frac::getNumerator()
{
	return numerator;
}
/** Retrieves Dinominator
 *
 */
int frac::getDinominator()
{
	return dinominator;
}

/**
 * The function displays the fraction in proper form. An improper
 * fraction is converted to mixed form
 */
void frac::display() const
{
	if(std::abs(dinominator)!=1)
	{
		if(std::abs(numerator)<std::abs(dinominator))
			std::cout<<numerator<<"/"<<dinominator<<std::endl;
		else
		{
			std::cout<<numerator/dinominator<<" "<<std::abs(numerator)%dinominator<<"/"<<dinominator<<"  (Improper fraction converted to mixed form)"<<std::endl;
		}
	}
	else
		std::cout<<numerator<<std::endl;
}
/**
 * The function reduces a fraction to its lowest form by dividing both numerator
 * and dinominator by their GCD.
 */
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

/**
 * This function adds two fractions and modifies the first operand to the result
 */
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

/**
 * This function subtracts second fraction from first and modifies the first operand to the result
 */
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

/**
 * This function multiplies two fractions and modifies the first operand to the result
 */
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

/**
 * This function divides first fraction by second and modifies the first operand to the result
 */
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

/** \brief unary - operator overload
 *
 * This function negates the fraction (argument)
 */
frac& frac::operator-()
{
	numerator = -numerator;
	return *this;
}
/** \brief Get LCM
 *
 */
int frac::getLcm(int a, int b)
{
	return (a*b)/getGcd(a, b);
}

/** \brief Get GCD
 *
 */
int frac::getGcd(int a, int b)
{
	if(b>a)
	{
		a^=b;
		b^=a;
		a^=b;
	}
	while(b>0)
	{
		int temp = b;
		b		 = a%b;
		a		 = temp;
	}
	return a;
}
