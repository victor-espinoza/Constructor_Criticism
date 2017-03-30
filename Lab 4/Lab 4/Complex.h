/* Victor Espinoza
* CECS 282, Section 1
* Spring 2014
* Due Date: 3/20/14
* Lab #4 - Constructor Criticism
*/

#ifndef __Complex_H
#define __Complex_H

#include <string>

class Complex {
private:
   //Private member variables for the Complex class
   double mReal, mImaginary;

public:
   //Default constructor and constructor that takes 2 parameters
   Complex();
   Complex(double, double);

   //Destructor function for the Complex class.
   ~Complex();

   //Copy constructor for the Complex class.
   Complex(const Complex &other);

   //operator= function
   Complex & operator=(const Complex &other);

   //Accessor and mutator methods for the real and imaginary components
   double getReal() const;
   void setReal(double);
   double getImaginary() const;
   void setImaginary(double);

   //Returns absolute value of the complex number
   double absoluteValue() const;

   //Determines if the two complex numbers are equal or not
   bool equals(const Complex &other) const;

   //Returns a string representation of the Complex number
   std::string toString() const;

   //Returns a Complex object that stores the value of the complex 
   //conjugate of the complex number that the function calls.
   Complex conjugate() const;                      

   //Returns a Complex object equal to the complex product of two
   //Complex numbers. (a x c - b x d) + (a x d + c x b)i
   Complex multiply(const Complex &other) const;

};//close Complex Class

#endif
