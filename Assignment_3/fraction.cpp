s// fraction.cpp
#include "fraction.h"

CFraction::CFraction(int numerator, int denominator)
{
	assign(numerator,denominator);
}

CFraction::~CFraction(void)
{
}

void CFraction::assign(int numerator, int denominator)
{
	m_numerator = numerator;
	if (denominator != 0)
	{
		m_denominator = denominator;

		// take postive numerator and denominator if both of them are negative
		if (m_numerator < 0 && m_denominator < 0) {
			m_numerator = abs(m_numerator);
			m_denominator = abs(m_denominator);
		}
		else if (m_denominator < 0)
		{
			m_denominator = -m_denominator;
			m_numerator = -m_numerator;
		}		
	}
	else
	{
		cerr << "Error: CFraction denominator must not ";
		cerr << "be zero" << endl;
	}
}

double CFraction::ToDouble(void)
{
	return double(m_numerator)/m_denominator;
}

void CFraction::invert(void)
{
	int temp = m_numerator;
	m_numerator = m_denominator;
	m_denominator = temp;
	if(m_denominator < 0) {
		m_denominator = -m_denominator;
		m_numerator = -m_numerator;
	}
}

string CFraction::ToString(void)
{
	char x[10];
	snprintf(x,10,"%d",m_numerator);
	char y[10];
	snprintf(y,10,"%d",m_denominator);
	string z = x;
	z += "/";
	z += y;
	return z;
}

CFraction CFraction::operator+(CFraction& rhs)
{
	CFraction result;
	result.m_denominator = m_denominator * rhs.m_denominator;
	result.m_numerator = m_numerator * rhs.m_denominator + 
		                  rhs.m_numerator * m_denominator;
	result.simplify();
	return result;
}

void CFraction::simplify(void)
{
	int d = gcd(m_numerator, m_denominator);
	m_numerator /= d;
	m_denominator /= d;
}

int CFraction::gcd(int numerator, int denominator)
{

	int big = abs(numerator);
	int small = abs(denominator);
	int remainder = big % small;
	while (remainder != 0)
	{
		big = small;
		small = remainder;
		remainder = big % small;
	}
	return small;

/*	
	// different algorithm using recursion
	if (numerator == denominator)
	{
		return numerator;
	}
	if (numerator < denominator)
	{
		return gcd(denominator, numerator);
	}
	return gcd(denominator,numerator-denominator);
*/
/*
	// yet another recursion algorithm
	if (numerator % denominator == 0)
	{
		return denominator;
	}
	return gcd(denominator, numerator % denominator);
*/
}

void CFraction::negate(void)
{
	m_numerator = -m_numerator;
	
}

CFraction CFraction::operator-(CFraction& rhs)
{
	CFraction result;
	result.m_denominator = m_denominator * rhs.m_denominator;
	result.m_numerator = m_numerator * rhs.m_denominator - 
		                  rhs.m_numerator * m_denominator;
	result.simplify();
	return result;
}

CFraction CFraction::operator*(CFraction& rhs)
{
	CFraction result;
	result.m_numerator   = m_numerator * rhs.m_numerator;
	result.m_denominator = m_denominator * rhs.m_denominator;
	result.simplify();
	return result;
}

CFraction CFraction::operator/(CFraction& rhs)
{
	CFraction result;
	result.m_numerator = m_numerator * rhs.m_denominator;
	result.m_denominator = m_denominator * rhs.m_numerator;
	result.simplify();
	return result;
}

void CFraction::ToFraction(double value)
{
	m_numerator = int(value*1000000);
	m_denominator = 1000000;
	simplify();
}
