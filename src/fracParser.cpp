/*
 * fracParser.cpp
 *
 *  Created on: Dec 7, 2013
 *      Author: phanindrabhagavatula
 */

#include "fracParser.h"
#include <sstream>
#include <iostream>

fracParser::fracParser() {
	// TODO Auto-generated constructor stub

}

fracParser::~fracParser() {
	// TODO Auto-generated destructor stub
}

frac*& fracParser::getFractionFromString(std::string fraction)
{
	_DATATYPE_ numerator, dinominator;

	size_t separatorPosition = fraction.find('/');

//	std::cout<<"separatorPos:"<<separatorPosition<<std::endl;
//	std::cout<<"numer:"<<fraction.substr(0,separatorPosition)<<std::endl;

	std::istringstream iss (fraction.substr(0,separatorPosition));
	iss>>numerator;
//	std::cout<<"dinom:"<<fraction.substr(separatorPosition+1, std::string::npos)<<std::endl;
	iss.clear();
	iss.str(fraction.substr(separatorPosition+1, std::string::npos));
	iss>>dinominator;
//	std::cout<<"parsed numer:"<<numerator<<std::endl;
//	std::cout<<"parsed dinom:"<<dinominator<<std::endl;
	frac *fterm = new frac(numerator, dinominator);
	return fterm;

}

