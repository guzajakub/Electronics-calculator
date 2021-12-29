#ifndef COMPLEX_H
#define COMPLEX_H

class Complex {

private:

	float im;
	float re;

public:
	
	Complex(float im_, float re_);

	Complex operator+(const Complex &a, const Complex& b);

};


/* complex.h */
#endif