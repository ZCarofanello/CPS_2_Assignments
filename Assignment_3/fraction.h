// fraction.h
#pragma once
#include <string>
#include <iostream>
using namespace std;

class CFraction
{
private:
	int m_numerator;
	int m_denominator;
	int gcd(int numerator, int denominator);
public:
	CFraction(int numerator=0, int denominator=1);
	~CFraction(void);
	void assign(int numerator, int denominator=1);
	void invert(void);
	void negate(void);
	CFraction operator-(CFraction& rhs);
	CFraction operator*(CFraction& rhs);
	CFraction operator/(CFraction& rhs);
	CFraction operator+(CFraction& rhs);
	void simplify(void);
	double ToDouble(void);
	string ToString(void);
	void ToFraction(double value);
};
