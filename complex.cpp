/* Amanda Falke 2013 C++ OOP Project covering these topics:

C++ Rule of Three or "The Big Three:"
Destructor, copy constructor, and copy assignment operator

Operator Overloading / Encapsulation / Friend Classes

Const Correctness

Imaginary numbers and cmath library


Dependencies: complex.cpp, complex.h, main.cpp, and cmath lib.

File: complex.cpp
This file contains the class implementations for the Complex class

FRIEND implementations of accessor functions that do not modify operands, and return object
	stream insertion operator <<
	stream extraction operator >>
	binary arithmetic operators  +  -  *  /
	unary negation   -		
		
MEMBER implementations of modifier / mutator functions:
	compound arithmetic assignment operators      +=  -=  *=  /=

NON-MEMBER function implementations of:		
	boolean comparison operators for the class	 ==  !=  <  <=  >  >=

*/


#include <cmath>
#include "complex.h"

//
// ctor
//	
Complex::Complex( float realNum, float imaginaryNum ) :
m_real(realNum), m_imaginary(imaginaryNum)
{
	m_dummyChar = 'i';
}


/* stream operators - friend classes */

// define natural, intuitive behavior such as cout << objectName 
std::ostream & operator<<(std::ostream & os, const Complex & rhs)
{
//  if the real portion (a) is zero, then the real portion and the operator should not be displayed.	
	if ( rhs.real() == 0 )
	{
		os << rhs.imaginary() << "i" << std::endl;	
	}
	
// 	if the imaginary portion (b) is zero, then only the real portion should be displayed.
	else if ( rhs.imaginary() == 0 )
	{
		os << rhs.real() << std::endl;
	}
	
// 	if the imaginary portion (b) is one, then only "i"  should be displayed, not b.
	else if (  rhs.imaginary() == 1 )
	{
		os << rhs.real() << " + " << "i" << std::endl;
	}
	
	else
	{
		os << rhs.real() << " + " << rhs.imaginary() << "i" << std::endl;
	}
    return os; // return os reference in order to chain like built in primitive types.
}




std::istream & operator>>(std::istream & is, Complex & rhs)
{
		is >> rhs.m_real; // a
		//is >> " "; // space
		//is >> "+"; // operator
		//is >> " "; // space
		is >> rhs.m_imaginary; //b
		is >> rhs.m_dummyChar; // i

	return is;
}



//
// addition
// (a + bi) + (c + di) = (a + c) + (b + d)i
// in other words:   ( a+c, b+d )i
// 
Complex operator+(const Complex &lhs, const Complex & rhs)
{

// THESE REFERENCES ENSURE IT'S NOT COMPILER DETERMINATE:
	const float &a = lhs.real();
	const float &b = lhs.imaginary();
	const float &c = rhs.real();
	const float &d = rhs.imaginary();
	
	return  Complex(  a + c, b + d  );	// non member
	
}


//
// subtraction
// (a + bi) - (c + di)= (a - c) + (b - d)i
//
Complex operator-(const Complex &lhs, const Complex & rhs)
{
	const float &a = lhs.real();
	const float &b = lhs.imaginary();
	const float &c = rhs.real();
	const float &d = rhs.imaginary();
	
// previous use:
//	return  Complex(  lhs.real() - rhs.real(),
//		lhs.imaginary() - rhs.imaginary()  );
		
// simplified using local const floats:		
	return  Complex(  a - c, b - d  );
}


//
// multiplication
//   (a + bi)(c + di) = (ac - bd) + (ad + bc)i
//
Complex operator*(const Complex &lhs, const Complex & rhs)
{
	const float &a = lhs.real();
	const float &b = lhs.imaginary();
	const float &c = rhs.real();
	const float &d = rhs.imaginary();
		
	return Complex
	(  ( (a * c) - (b * d) ) ,
	   ( (a * d) + (b * c) )  
	);
}


//
// division
/*
(a + bi)     (ac + bd)   (bc - ad)i            3*1 + 2*1         3*1 - 3*1 
  --------  =  --------- + ----------              
  (c + di)     (c2 + d2)   (c2 + d2)               2                 2
*/
// using power function: double pow (double base, double exponent);
Complex operator/(const Complex &lhs, const Complex & rhs)
{	 
	const float &a = lhs.real();
	const float &b = lhs.imaginary();
	const float &c = rhs.real();
	const float &d = rhs.imaginary();

	return Complex
	(  
	 (  ( (a * c) + (b * d) ) /  ( (pow(c, 2.0)) + (pow(d, 2.0)) )  
	 ) ,
	
	 (  ( (b * c) - (a * d) ) /  ( (pow(c, 2.0)) + (pow(d, 2.0))  )  
	 )
	);
}


//
// unary negation
Complex operator-(const Complex&rhs)
{
	const float &c = -rhs.real();
	const float &d = -rhs.imaginary();
	
	return Complex( c , d );
}




/* non member function accessors: comparison operators */

bool operator==(const Complex &lhs, const Complex &rhs)
{
	const float &a = lhs.real();
	const float &b = lhs.imaginary();
	const float &c = rhs.real();
	const float &d = rhs.imaginary();
	
	return ( (a==c) && (b==d) ); 
}


bool operator!=(const Complex &lhs, const Complex &rhs)
{
	return !(lhs == rhs);
	// OR:
	//return !(*this == rhs); with a ptr-to-this-returning function signature.
}


bool operator>(const Complex &lhs, const Complex &rhs)
{
	const float &a = lhs.real();
	const float &b = lhs.imaginary();
	const float &c = rhs.real();
	const float &d = rhs.imaginary();
	
	return (   (a > c) || ((a==c) && (b > d)) );	
}

bool operator>=(const Complex &lhs, const Complex &rhs) 
{
	const float &a = lhs.real();
	const float &b = lhs.imaginary();
	const float &c = rhs.real();
	const float &d = rhs.imaginary();
	
// >= is the OR of > and == 
//	return ( (a==c) && (b==d) ) ||  ( (a > c) || ((a==c) && (b > d)) ) ; //compiles but duplicates code
	return ( (operator>(lhs, rhs)) || (operator==(lhs, rhs)) );
}

bool operator<(const Complex &lhs, const Complex &rhs)
{
	const float &a = lhs.real();
	const float &b = lhs.imaginary();
	const float &c = rhs.real();
	const float &d = rhs.imaginary();

	return (   (a < c) || ((a==c) && (b < d)) ); 
}

bool operator<=(const Complex &lhs, const Complex &rhs)
{
	const float &a = lhs.real();
	const float &b = lhs.imaginary();
	const float &c = rhs.real();
	const float &d = rhs.imaginary();
	
// <= is the OR of < and == 
//	return ( (a==c) && (b==d) ) ||  ( (a < c) || ((a==c) && (b < d)) ) ; // compiles but duplicates code
	return ( (operator<(lhs, rhs)) || (operator==(lhs,rhs)) );
}






/* compound assignment operators */

Complex & Complex::operator+=(const Complex & rhs)
{
	*this = *this + rhs; //MIK says: same as *this += rhs
	return *this;
}


Complex & Complex::operator-=(const Complex & rhs)
{		
	*this = *this - rhs;
	return *this;
}


Complex & Complex::operator*=(const Complex & rhs)
{
	*this = *this * rhs;
	return *this;
}


Complex & Complex::operator/=(const Complex & rhs)
{
	*this = *this / rhs;
	return *this;
}





