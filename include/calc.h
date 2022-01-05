#ifndef CALC_H
#define CALC_H

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <random>
#include <numeric>
#include <bitset>
#include <sstream>
#include <cstring>
#include "math.h"

#include "utils.h"
using std::string; using std::vector;


/* Class E_Calc is a representation, of a simple electronics calculator to perform some basic operations */
class E_Calc {

private:

	/* for hex and sometimes bin representation */
	string a;
	string b;

	/* for dec and sometimes bin representation */
	int b1 = {};
	int b2 = {};

public:

	/* setters */
	void setA(string a_);
	void setB(string b_);

	void setb1(int b1_);
	void setb2(int b2_);

	/* getters */
	string getA();
	string getB();

	int getb1();
	int getb2();

		// HEX functions //
	
    /*  hex2dec() function converts hexadecimal input(string) into a decimal value(unsigned long) */ 
	double hex2dec(E_Calc& calc);

	/*  hex2bin() function converts hexadecimal input(string) into a string binary value */
	string hex2bin(E_Calc &calc);

		// BIN functions //

	/*  bin2hex() function converts string binary input into a string hex value */
	string bin2hex(E_Calc &calc);

	/*  bin2dec() function converts string binary input into a decimal value(unsigned long) */
	double bin2dec(E_Calc& calc);

		// DEC functions //

	/* dec2hex function converts a decimal integer input into a string hexadecimal value */
	string dec2hex(E_Calc& calc);

	/* dec2bin function converts a decimal integer input into a vector of ints,  binary output */
	vector<int> dec2bin(E_Calc& calc);
	

};

/* calc.h */
#endif 
