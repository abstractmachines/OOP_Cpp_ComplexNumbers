/* Amanda Falke 2013 C++ OOP Project covering these topics:

C++ Rule of Three or "The Big Three:"
Destructor, copy constructor, and copy assignment operator

Operator Overloading / Encapsulation / Friend Classes

Const Correctness

Imaginary numbers and cmath library


Dependencies: complex.cpp, complex.h, main.cpp, and cmath lib.

File: main.cpp
This file contains the testing program for the Complex class.
*/

#include <iostream>

#include "complex.h"

using namespace std;


int main()
{
	float real;
	float imaginary;
	
	Complex a(3.0, 2.0);
	Complex b(1, 1);

// other accepted tests
//	 a(3.0, -2.0);
//	 b(0.0, 1); 

	
	Complex c = b + a; 
	c = b - a; 
	c = a / b;
	c = b * a; 
	
	cout << " a: " << a << " b: " << b << " c: " << c  << endl; 

	
	Complex d = b - a; // subtraction 
	
	Complex e = d / a; // division
	
	Complex f = d / a - b; // chaining
	
	f = b * d * a; // multiplication and chaining
	cout << " f: " << endl << f << endl;
	
	e += a;
	cout<< " e is += a " << endl << e <<endl; // compound assignment
	
	e -= a;
	cout<< " e is -= a " << endl << e <<endl; // compound assignment
	
	a *= b;
	cout<< " a is *= b " << endl << a <<endl; // compound assignment
	
	a /= b;
	cout<< " a is /= b " << endl << a <<endl; // compound assignment
	
	
	// unary negation
	cout<<"Unary Negation Test" << endl;
		cout<< " a is a " << endl << a <<endl;
	b = -a;
		cout<< " b is - a " << endl << b <<endl;
		
	// boolean comparison
		if ( a >= b ) { cout<<"a is greater than or equal to b."; }
		else {cout<<"a is not greater than or equal to b." << endl; }
		
		if ( a == b ) { cout<<"a is  equal to b."; }
		else {cout<<"a is not  equal to b." << endl;  }
			
	
	
	return 0;
}
