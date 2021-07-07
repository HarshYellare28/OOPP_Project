// NAME: HARSH YELLARE
// ROLL_NO: BT19CSE124
// ASSIGNMENT NUMBER: 2
// QUESTION NUMBER: 1
// DATE OF SUBMISSION: 26-03-2021

// DESCRIPTION : Implementation of a class to evaluate a given postfix expression using stack and operator overloading.

#include<iostream>
using namespace std;
#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{
    friend ostream& operator<<(ostream& out, const Complex& c);
    friend istream& operator>>(istream& in, Complex& c);

private:
    int real;
    int imaginary;

public:
    Complex(); // Default Constructor
    Complex(int , int); // Paramterized Constructor
    Complex(const Complex& ); // Copy Constructor
    // ~Complex(); // Since we have not declared anything on heap hence no need of destructor
    Complex& operator=(const Complex& ); 
    void setComplex(int , int );
    void display() const;
    void setReal(int );
    void setImaginary(int );
    int getReal() const;
    int getImaginary() const;
    Complex& add(const Complex& );
    Complex& subtract(const Complex& ); // a.subtract(b) => a-b
    Complex& multiply(const Complex& );
    // Floor Division it might happen that (5 + 6i)/10 => 0
    Complex& dividedBy(const Complex& );// a.dividedBy(b) => a/b 
};

#endif