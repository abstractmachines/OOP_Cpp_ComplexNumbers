/* Amanda Falke 2013 C++ OOP Project covering these topics:

C++ Rule of Three or "The Big Three:"
Destructor, copy constructor, and copy assignment operator

Operator Overloading / Encapsulation / Friend Classes

Const Correctness

Imaginary numbers and cmath library


Dependencies: complex.cpp, complex.h, main.cpp, and cmath lib.

File: complex.h
This file contains the class declarations for the Complex class


The following operators need to be provided for your Complex class
  - stream insertion operator: <<
  - stream extraction operator:  >>
  - these four arithmetic operators: +  -  *  /
  - these four arithmetic assignment operators:  +=  -=  *=  /=
  - these comparison operators for the class:  ==  !=  <  <=  >  >=
  - unary negation:  -
*/


#include <iostream>

#ifndef  array_H
#define  array_H

#define i sqrt( -1 )


class Complex
{
	// stream operators << >>
	friend std::ostream& operator<<(std::ostream & os, const Complex & rhs);
	friend std::istream& operator>>(std::istream & is, Complex & rhs);

	// binary arithmetic operators + - *  /
	friend Complex operator+(const Complex &lhs, const Complex & rhs);
	friend Complex operator-(const Complex &lhs, const Complex & rhs);
	friend Complex operator*(const Complex &lhs, const Complex & rhs);
	friend Complex operator/(const Complex &lhs, const Complex & rhs);
	
	// unary negation
	friend Complex operator-(const Complex &rhs);
	
	
	public :

	Complex( float realNum = 0.0, float imaginaryNum = 0.0 );
	//Complex()    Constructor: takes a real and an imaginary floating
    //           point value. Both values should be defaulted to 0.0.

	float real () const { return m_real; }
	
	float imaginary () const { return m_imaginary; }	
	
	/* compound assignment operators */
	Complex & operator+=(const Complex & rhs); 
	Complex & operator-=(const Complex & rhs); 
	Complex & operator*=(const Complex & rhs); 
	Complex & operator/=(const Complex & rhs); 
	// a reference is returned by the assignment operator to allow operator chaining
	// Take a const-reference to the right-hand side of the assignment.
   // Return a non-const reference to the left-hand side.
	// is good to return a non const reference from operator, to allow for chaining.
	
	private :
	float m_real; // a
	float m_imaginary; // b
	char m_dummyChar; // i
};



/*  comparison operators */
bool operator==(const Complex &lhs, const Complex &rhs);
bool operator!=(const Complex &lhs, const Complex &rhs); // ! a==c etc
bool operator>(const Complex &lhs, const Complex &rhs);
bool operator>=(const Complex &lhs, const Complex &rhs); // or of > and ==
bool operator<(const Complex &lhs, const Complex &rhs);
bool operator<=(const Complex &lhs, const Complex &rhs); // or of < and ==



#endif
