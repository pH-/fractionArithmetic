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

class fracParser {

public:
	static frac*& getFractionFromString(std::string fraction);
	fracParser();
	virtual ~fracParser();
};

#endif /* FRACPARSER_H_ */
