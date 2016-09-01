//main.cpp - Demo203
//CPET-321 Computational Problem Solving II Fall 2013
//F.R.Hubbell                              09/08/2013
//Title: Lab03 Solution - Fraction Class	  
//Platform: C++ Win32 Console Visual Studio 2012
#include <iostream>
#include <conio.h>
#include <string>
#include "fraction.h"

using namespace std;

int main()
{
	CFraction x(1,2);
	cout << "Regular assignment test:" << endl;
	cout << "\tx = " << x.ToString() << endl;
	cout << "Invalid assignment test:" << endl << "\t";
	x.assign(1, 0);
	cout << "Negative value assignment test:" << endl;
	x.assign(1, -2);
	cout << "\tx = " << x.ToString() << endl;
	cout << "Convert to decimal test:" << endl;
	cout << "\tx = " << x.ToDouble() << endl;
	cout << "Inversion test:" << endl;
	x.invert();
	cout << "\tx = " << x.ToString() << endl;

	cout << "Negation test:" << endl;
	x.negate();
	cout << "\tx = " << x.ToString() << endl;

	cout << "Addition test:" << endl;
	CFraction y(10, 3);
	cout << "\tx = " << x.ToString() << endl;
	cout << "\ty = " << y.ToString() << endl;
	CFraction z = x + y;
	cout << "\tx + y = " << z.ToString() << endl;

	cout << "Subtraction test:" << endl;
	cout << "\tx = " << x.ToString() << endl;
	cout << "\ty = " << y.ToString() << endl;
	z = x - y;
	cout << "\tx - y = " << z.ToString() << endl;

	cout << "Multiplication test:" << endl;
	cout << "\tx = " << x.ToString() << endl;
	cout << "\ty = " << y.ToString() << endl;
	z = x * y;
	cout << "\tx * y = " << z.ToString() << endl;

	cout << "Division test:" << endl;
	cout << "\tx = " << x.ToString() << endl;
	cout << "\ty = " << y.ToString() << endl;
	z = x / y;
	cout << "\tx / y = " << z.ToString() << endl;

	cout << "Simplification test:" << endl;
	x.assign(8, 10);
	cout << "\tx = " << x.ToString() << " -> x = ";
	x.simplify();
	cout << x.ToString() << endl;

	cout << "GCD test:" << endl;
	cout << "\tUndoable because gcd() was declared as private" << endl;

	cout << "Negation test:" << endl;
	cout << "\tx = " << x.ToString() << " -> x = ";
	x.negate();
	cout << x.ToString() << endl;

	cout << "Decimal to fraction conversion test:" << endl;
	x.ToFraction(0.2);
	cout << "\t0.2 = " << x.ToString() << endl;
	cout << endl;
	
	/*add methods for the following functionalities.
	1. Rounding up a real number
	2. Rounding down a real number
	3. Calculating the integer power of a real number.
	4. Create an array of fractions objects.
	5. Read a file with fractions into list (each line has to have two integers, i.e. numerator & denominator)
	6. Find the maximum fraction among the inputs read from the file.	*/

	system("pause");
	return 0;
}