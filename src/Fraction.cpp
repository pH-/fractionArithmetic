//============================================================================
// Name        : Fraction.cpp
// Author      : pH
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include "frac.h"
#include "fracParser.h"

int main() {

	std::string f1, f2;
	std::cout << "Fraction Arithmetic" << std::endl;
	std::cout << "Enter a fraction1 :"<<std::endl;
	std::cin  >>f1;
	std::cout << "Enter a fraction2:"<<std::endl;
	std::cin  >>f2;
	frac *frac1 = fracParser::getFractionFromString(f1);
//	std::cout<<frac1->getNumerator()<<std::endl<<frac1->getDinominator()<<std::endl;
	frac *frac2 = fracParser::getFractionFromString(f2);
//	std::cout<<frac2->getNumerator()<<std::endl<<frac2->getDinominator()<<std::endl;

	frac *frac3 = new frac((*frac1)+(*frac2));
	std::cout<<std::endl<<frac3->getNumerator()<<"/"<<frac3->getDinominator()<<std::endl;

	return 0;
}
