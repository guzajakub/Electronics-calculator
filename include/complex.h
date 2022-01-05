#ifndef COMPLEX_H
#define COMPLEX_H

#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <numeric>
#include <istream>
#include <ostream>
#include <fstream>
#include <iostream>
#include "math.h"

using std::istream; using std::ostream;

/* Complex class, which represents a complex number */
class Complex {

private:
	/* private data, realis and imaginalis */
	double re = {};
	double im = {};


public:
	/* constructor */
	Complex(double im_, double re_);


	/* getters */
	double getRe() const;
	double getIm() const;
	/* setters */
	void setRe(double re_);
	void setIm(double im_);

	
	/* overloading some operators for a switch-case scenario*/
	friend istream& operator>> (istream& in, Complex& c);
	friend ostream& operator<< (ostream& o, Complex& c);
	friend Complex operator+(const Complex &c1, const Complex &c2);
	friend Complex operator-(const Complex &c1, const Complex &c2);
    friend Complex operator*(const Complex &c1, const Complex &c2);
	
	/* computing module of a complex number*/
	double ComplexModule(Complex& c);

};


/* complex.h */
#endif