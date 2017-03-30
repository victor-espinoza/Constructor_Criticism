/* Victor Espinoza
* CECS 282, Section 1
* Spring 2014
* Due Date: 3/20/14
* Lab #4 - Constructor Criticism
*/

#include "Complex.h"            
#include <iostream>

#define _USE_MATH_DEFINES
#include <math.h>

#include <string>
#include <sstream> // for ostringstream

using namespace std;

Complex::Complex() : mReal(0), mImaginary(0) {
   cout <<"Default construct " << toString() << endl;
}//close Complex() default constructor


Complex::Complex(double real, double imaginary) : mReal(real), 
   mImaginary(imaginary) {
      cout << "Construct " << toString() << endl;
}//close Complex(...) constructor


Complex::~Complex(){
   cout << "Destruct " << toString() << endl;
}//close ~Complex()	deconstructor


Complex::Complex(const Complex &other) : mReal(other.mReal), 
   mImaginary(other.mImaginary){
      cout << "Copy construct " << toString() << endl;
}//close Complex(...) copy constructor


Complex & Complex::operator=(const Complex &other){
   cout << "Operator= "  << toString() << " ==> "; 
   mReal = other.mReal;
   mImaginary = other.mImaginary;
   cout << toString() << endl;
   return *this;
}// close operator=(...)


double Complex::getReal() const {
   return mReal;
}//close getReal() const


void Complex::setReal(double real) {
   cout << "Mutate " << toString() << " to ";
   mReal = real;
   cout << toString() << endl;
}//close setReal(...)


double Complex::getImaginary() const {
   return mImaginary;
}//close getImaginary() const


void Complex::setImaginary(double imaginary) {
   cout << "Mutate " << toString() << " to ";
   mImaginary = imaginary;
   cout << toString() << endl;
}//close setImaginary(...)


double Complex::absoluteValue() const {
   cout << "AbsoluteValue" << endl;
   return sqrt((mReal * mReal) + (mImaginary * mImaginary));
}//close absoluteValue() const


bool Complex::equals(const Complex &other) const {
   return ((mReal == other.mReal) && (mImaginary == other.mImaginary));
}//close equals(...) const


string Complex::toString() const {
   ostringstream format;
   mImaginary >= 0 ? (format << mReal << "+" << mImaginary << "i") : 
    (format << mReal << mImaginary << "i");
   return format.str(); // converts back to string type
}//close toString() const


Complex Complex::conjugate() const{
   cout << "Conjugate" << endl;
   return Complex(mReal, -mImaginary);
}//close conjugate() const


Complex Complex::multiply(const Complex &other) const{
   cout << "Multiply" << endl;
   return Complex(((mReal * other.mReal) - (mImaginary * other.mImaginary)),
    ((mReal * other.mImaginary) + (other.mReal * mImaginary)));
}//close multiply(...) const