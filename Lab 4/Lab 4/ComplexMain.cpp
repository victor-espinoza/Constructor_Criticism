#include "Complex.h"
#include <iostream>

using namespace std;

void compareComplex(Complex first, const Complex& second);

int main() {
   //create complex variables
   Complex c1(1.5, 2);
   Complex c2(-3, 4);
   Complex *cPtr;

   cout << endl;

   if(true) {
      //create complex variable that resides in the scope of if statement
      Complex c3(c2);
      //create a complex variable and put it on the heap w/ new keyword
      cPtr = new Complex(5, 5);
      cout << "The conjugate of " << c3.toString() << " is " << 
       c3.conjugate().toString() << endl;
   }//end if 

   //use the copy constructor and the setReal function
   cout << endl;
   Complex copy1 = c2;
   copy1.setReal(10);
   Complex copy2(copy1);

   //re-assign the value in copy1 Complex value
   cout << endl;
   copy1 = c2;
   copy1 = c2.conjugate();

   //create a new complex value and compare it to another
   //complex value
   cout << endl;
   Complex c3(-3, -4);
   compareComplex(c3, copy1);
   cout << endl;
}//close main()


//compare two complex values with one another
void compareComplex(Complex first, const Complex& second) {
   cout << first.equals(second) << endl;
}//close compareComplex
                                                      
/*Output
1. Annotate each line of text from your output:

Construct 1.5+2i (ComplexMain.cpp - Line 9, Complex.cpp - Function: Complex(double real, double imaginary))
Construct -3+4i (ComplexMain.cpp - Line 10, Complex.cpp - Function: Complex(double real, double imaginary))

Copy construct -3+4i (ComplexMain.cpp - Line 16, Complex.cpp - Function: Complex(const Complex &other))
Construct 5+5i (ComplexMain.cpp - Line 17, Complex.cpp - Function: Complex(double real, double imaginary))
Conjugate (ComplexMain.cpp - Line 19, Complex.cpp - Function: Complex Conjugate() const)
Construct -3-4i (ComplexMain.cpp - Line 19, Complex.cpp - Function: Complex(double real, double imaginary))
The conjugate of -3+4i is -3-4i (ComplexMain.cpp - Lines 18 & 19)
Destruct -3-4i (ComplexMain.cpp - Line 20, Complex.cpp - Function: ~Complex()) //Complex conjugate object goes out of scope after the cout statement, so it is popped from the stack.
Destruct -3+4i (ComplexMain.cpp - Line 20, Complex.cpp - Function: ~Complex()) //at the end of the if statement, the variable c3 goes out of scope, where it is then popped from the stack.

Copy construct -3+4i (ComplexMain.cpp - Line 23, Complex.cpp - Function: Complex(const Complex &other))
Mutate -3+4i to 10+4i (ComplexMain.cpp - Line 24, Complex.cpp - Function: void SetReal(double real))
Copy construct 10+4i (ComplexMain.cpp - Line 25, Complex.cpp - Function: Complex(const Complex &other))

Operator= 10+4i ==> -3+4i (ComplexMain.cpp - Line 28, Complex.cpp - Function: Complex & operator=(const Complex &other))
Conjugate (ComplexMain.cpp - Line 29, Complex.cpp - Function: Complex Conjugate() const)
Construct -3-4i (ComplexMain.cpp - Line 29, Complex.cpp - Function: Complex(double real, double imaginary))//Conjugate returns a Complex object
Operator= -3+4i ==> -3-4i (ComplexMain.cpp - Line 29, Complex.cpp - Function: Complex & operator=(const Complex &other))
Destruct -3-4i (ComplexMain.cpp - Line 30, Complex.cpp - Function: ~Complex())//After the variable is updated, we no longer need the Conjugate object that was returned, so we pop it from the stack.

Construct -3-4i (ComplexMain.cpp - Line 32, Complex.cpp - Function: Complex(double real, double imaginary))
Copy construct -3-4i (ComplexMain.cpp - Line 33, Complex.cpp - Function: Complex(const Complex &other))//The CompareComplex function takes an object as a perameter, so it makes a copy of the c3 variable
1 (ComplexMain.cpp - Line 33, ComplexMain.cpp - Function: void CompareComplex(Complex first, const Complex& second))
Destruct -3-4i (ComplexMain.cpp - Line 34, Complex.cpp - Function: ~Complex())//After the CompareComplex function ends, the copy of the c3 variable goes out of scope, so it is popped from the stack.

Destruct -3-4i (ComplexMain.cpp - Line 35, Complex.cpp - Function: ~Complex())//The main program has ended, so any local variables begin to get popped from the stack.
Destruct 10+4i (ComplexMain.cpp - Line 35, Complex.cpp - Function: ~Complex())//The main program has ended, so any local variables begin to get popped from the stack.
Destruct -3-4i (ComplexMain.cpp - Line 35, Complex.cpp - Function: ~Complex())//The main program has ended, so any local variables begin to get popped from the stack.
Destruct -3+4i (ComplexMain.cpp - Line 35, Complex.cpp - Function:  ~Complex()//The main program has ended, so any local variables begin to get popped from the stack.
Destruct 1.5+2i (ComplexMain.cpp - Line 35, Complex.cpp - Function: ~Complex())//The main program has ended, so any local variables begin to get popped from the stack.
Press any key to continue . . .

2. Locate the line where the Complex 5+5i is constructed. Explain why there is no output regarding the destruction of that object:

The *cPtr variable is constructed in the if statement on line 24. Because it was declared outside of the if statement, the construction of this Complex pointer does not go out of scope when the if statement ends. The reason that there is no output regarding the destruction of *ptr is because we used the "new" keyword to construct it, which puts the variable into the heap instead of the stack. When we "new" a variable, we are responsible for the memory management of its lifetime. When we are done with the variable on the heap, we have to use the "delete" keyword to delete the variable off of the stack. Since we did not use this keyword at the end of the program, the *cPtr variable still resides in the heap because it was never deleted. It will stay there indefinitely because we never deleted it, resulting in memory leakage.

*/
