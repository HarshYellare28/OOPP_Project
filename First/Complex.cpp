
// NAME: HARSH YELLARE
// ROLL_NO: BT19CSE124
// ASSIGNMENT NUMBER: 2
// QUESTION NUMBER: 1
// DATE OF SUBMISSION: 26-03-2021

// DESCRIPTION : Implementation of a class to evaluate a given postfix expression using stack and operator overloading.

#include<iostream>
#include"Complex.h"
#include<stdexcept>
using namespace std;

//Default Constructor
Complex::Complex()
{
    real = 0;
    imaginary = 0;
}
//Parameterized Constructor
Complex::Complex(int real_val ,int imaginary_val)
{
    real = real_val;
    imaginary = imaginary_val;
}

//Copy Constructor
Complex::Complex(const Complex& complex)
{
    real = complex.real;
    imaginary = complex.imaginary;
}

void Complex::setReal(int real_val)
{
    real = real_val;
}

void Complex::setImaginary(int imaginary_val)
{
    imaginary = imaginary_val;
}

int Complex::getReal() const
{
    return real;
}   

int Complex::getImaginary() const
{
    return imaginary;
}  

void Complex::setComplex(int real_val,int imaginary_val)
{
    real = real_val; 
    imaginary = imaginary_val;   
}

// output operator overloaded
ostream& operator<<(ostream& out, const Complex& c)
{
    int real_val , imaginary_val;
    real_val = c.getReal();
    imaginary_val = c.getImaginary();
    // three different case according the value of the imaginary part 
    if (imaginary_val<0)
    {
        out<<real_val<<" - "<<(-1)*imaginary_val<<"i"<<endl;
    }
    else if(imaginary_val>0)
    {
        out<<real_val<<" + "<<imaginary_val<<"i"<<endl;
    }
    else
    {
        out<<real_val<<endl;
    }
    return out;    
}

// input operator overloaded
istream& operator>>(istream& in, Complex& c)
{
    int real_val,imaginary_val;
    in>>real_val>>imaginary_val;
    c.setReal(real_val);
    c.setImaginary(imaginary_val);
    return in;
}

// assignment operator overloaded
Complex& Complex::operator=(const Complex& c)
{
    if (&c == this)
    {
        return *this;
    }
    this->real = c.getReal();
    this->imaginary = c.getImaginary();
    return *this;
}

void Complex::display() const
{
    cout<<(*this)<<endl;
}

Complex& Complex::add(const Complex& c)
{
    this->real += c.getReal();
    this->imaginary += c.getImaginary();
    return *this;
} 

Complex& Complex::subtract(const Complex& c)
{
    this->real -= c.getReal();
    this->imaginary -= c.getImaginary();
    return *this;
} 

Complex& Complex::multiply(const Complex& c)
{
    // (a + ib)*(c + id) = (ac-bd) + (bc+ad)
    int real_temp,imaginary_temp;// temporary vars
    real_temp = ((this->real)*(c.getReal()) - (this->imaginary)*(c.getImaginary())); 
    imaginary_temp = ((this->real)*(c.getImaginary()) + (this->imaginary)*(c.getReal()));
    real = real_temp;
    imaginary = imaginary_temp;
    return *this;
} 

Complex& Complex::dividedBy(const Complex& c)
{
    // using a/b = a*(conjugate of b)
    try
    {
        int abs_val = (c.real)*(c.real) + (c.imaginary)*(c.imaginary);
        if(abs_val == 0)
        {
            throw runtime_error("Error: Attempted to divide by Zero\n");
        }
        Complex conjugate(c); // conjugate of Complex number c created using a copy constructor
        int conj_imaginary = (-1)*(c.getImaginary());
        conjugate.setImaginary(conj_imaginary); // since imaginary part of conjugate of c is (-1)*(imaginary part of c) 
        int real_temp,imaginary_temp;// temporary vars
        real_temp = (((this->real)*(conjugate.getReal()) - (this->imaginary)*(conjugate.getImaginary()))/abs_val);
        imaginary_temp = ((this->real)*(conjugate.getImaginary()) + (this->imaginary)*(conjugate.getReal()))/abs_val;
        this->real = real_temp;
        this->imaginary = imaginary_temp;
        return *this;
    }
    catch (runtime_error& e)
    {  
        // calls the what function
        // using runtime_error object
        cout << "Exception occurred" << endl
             << e.what();       
    }
    
}

  




