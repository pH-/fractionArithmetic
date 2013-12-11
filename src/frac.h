/*
 * Frac.h
 *
 *  Created on: Dec 7, 2013
 *      Author: phanindrabhagavatula
 */

#ifndef FRAC_H_
#define FRAC_H_

class frac
{

public:
	frac(int n, int d);
	frac(frac& f);
	frac(frac* f);

	~frac();

	void  display() const;
	int   getDinominator();
	int   getNumerator();
	void  reduceFraction();


	frac* clone();
	frac& operator+(frac& f);
	frac& operator-(frac& f);
	frac& operator*(frac& f);
	frac& operator/(frac& f);
	frac& operator-();

private: //private functions

	int  getLcm(int dinominator1, int dinominator2);
	int  getGcd(int a, int b);
private:
	int  numerator;
	int  dinominator;

};

#endif /* FRAC_H_ */
