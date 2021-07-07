// NAME: HARSH YELLARE
// ROLL_NO: BT19CSE124
// ASSIGNMENT NUMBER: 2
// QUESTION NUMBER: 2
// DATE OF SUBMISSION: 26-03-2021

// DESCRIPTION : Implementation of a ComplexInteger class and demonstration of operator overloading 



#include<iostream>
using namespace std;
#ifndef COMPLEX_INTEGER_H
#define COMPLEX_INTEGER_H



class ComplexInteger
{
    friend ostream& operator<<(ostream& out, const ComplexInteger& c);
    friend istream& operator>>(istream& in, ComplexInteger& c);
    friend void displayContents(const ComplexInteger& );
    // friend functions to overload binary operators
    friend ComplexInteger operator+(ComplexInteger , ComplexInteger );
    friend ComplexInteger operator-(ComplexInteger , ComplexInteger );
    friend ComplexInteger operator*(ComplexInteger , ComplexInteger );
    friend ComplexInteger operator/(ComplexInteger , ComplexInteger );
    friend bool operator==(ComplexInteger ,ComplexInteger ); // Additional if required
private:
    int real;
    int imaginary;

public:

    ComplexInteger(); // Default Constructor
    ComplexInteger(int , int); // Paramterized Constructor
    ComplexInteger(const ComplexInteger& ); // Copy Constructor
    ~ComplexInteger(); // Destructor

    void setReal(int );
    void setImaginary(int );
    int getReal() const;
    int getImaginary() const;
 
    // ComplexInteger& operator+(const ComplexInteger& );
    // ComplexInteger& operator-(const ComplexInteger& );
    // ComplexInteger& operator*(const ComplexInteger& );
    // ComplexInteger& operator/(const ComplexInteger& );
    ComplexInteger& operator=(const ComplexInteger& );    
    ComplexInteger& operator=(const int& ); // overloaded function
    ComplexInteger& operator~();
    ComplexInteger& operator^(const ComplexInteger& ); 
};

#endif