// NAME: HARSH YELLARE
// ROLL_NO: BT19CSE124
// ASSIGNMENT NUMBER: 2
// QUESTION NUMBER: 2
// DATE OF SUBMISSION: 26-03-2021

// DESCRIPTION : Implementation of a ComplexInteger class and demonstration of operator overloading 
#include<iostream>
#include"ComplexInteger.h"
using namespace std;

ComplexInteger::ComplexInteger()
{
    real = 0;
    imaginary = 0;
}
//Parameterized Constructor
ComplexInteger::ComplexInteger(int real_val ,int imaginary_val)
{
    real = real_val;
    imaginary = imaginary_val;
}

//Copy Constructor
ComplexInteger::ComplexInteger(const ComplexInteger& complexInteger)
{
    real = complexInteger.real;
    imaginary = complexInteger.imaginary;
}

// anyway no use of destructor .....check again
ComplexInteger::~ComplexInteger()
{
    real = 0;
    imaginary = 0;
}

void ComplexInteger::setReal(int real_val)
{
    real = real_val;
}

void ComplexInteger::setImaginary(int imaginary_val)
{
    imaginary = imaginary_val;
}

int ComplexInteger::getReal() const
{
    return real;
}   

int ComplexInteger::getImaginary() const
{
    return imaginary;
}  

// output operator overloaded
ostream& operator<<(ostream& out, const ComplexInteger& c)
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
istream& operator>>(istream& in, ComplexInteger& c)
{
    int real_val,imaginary_val;
    in>>real_val>>imaginary_val;
    c.setReal(real_val);
    c.setImaginary(imaginary_val);
    return in;
}

void displayContents(const ComplexInteger& c)
{
    // three different case according the value of the imaginary part 
    if ((c.imaginary)<0)
    {
        cout<<c.real<<" - "<<((-1)*(c.imaginary))<<"i"<<endl;
    }
    else if(c.imaginary>0)
    {
        cout<<c.real<<" + "<<c.imaginary<<"i"<<endl;
    }
    else
    {
        cout<<c.real<<endl;
    }
}

// ComplexInteger& ComplexInteger::operator+(const ComplexInteger& c)
// {
//     this->real += c.getReal();
//     this->imaginary += c.getImaginary();
//     return *this;
// }

ComplexInteger operator+(ComplexInteger c1, ComplexInteger c2) // + overloaded using a friend function 
{
    ComplexInteger temp;
    temp.real = c1.real + c2.real;
    temp.imaginary = c1.imaginary + c2.imaginary;
    return temp;
}

// ComplexInteger& ComplexInteger::operator-(const ComplexInteger& c)
// {
//     this->real -= c.getReal();
//     this->imaginary -= c.getImaginary();
//     return *this;
// }
ComplexInteger operator-(ComplexInteger c1, ComplexInteger c2) // - overloaded using a friend function 
{
    ComplexInteger temp;
    temp.real = c1.real - c2.real;
    temp.imaginary = c1.imaginary - c2.imaginary;
    return temp;
}


// ComplexInteger& ComplexInteger::operator*(const ComplexInteger& c)
// {
//     // (a + ib)*(c + id) = (ac-bd) + (bc+ad)
//     int real_temp,imaginary_temp;// temporary vars
//     real_temp = ((this->real)*(c.getReal()) - (this->imaginary)*(c.getImaginary())); 
//     imaginary_temp = ((this->real)*(c.getImaginary()) + (this->imaginary)*(c.getReal()));
//     real = real_temp;
//     imaginary = imaginary_temp;
//     return *this;
// }

ComplexInteger operator*(ComplexInteger c1, ComplexInteger c2) // * overloaded using a friend function 
{
    // (a + ib)*(c + id) = (ac-bd) + (bc+ad)i
    ComplexInteger temp;
    temp.real = ((c1.real)*(c2.real)) - ((c1.imaginary)*(c2.imaginary));
    temp.imaginary = ((c1.real)*(c2.imaginary)) + ((c1.imaginary)*(c2.real));
    return temp;
}

// ComplexInteger& ComplexInteger::operator/(const ComplexInteger& c)
// {
//     // using a/b = a*(conjugate of b)
//     ComplexInteger conjugate(c); // conjugate of ComplexInteger c created using a copy constructor
//     int conj_imaginary = (-1)*(c.getImaginary());
//     conjugate.setImaginary(conj_imaginary); // since imaginary part of conjugate of c is (-1)*(imaginary part of c) 
//     int real_temp,imaginary_temp;// temporary vars
//     real_temp = ((this->real)*(conjugate.getReal()) - (this->imaginary)*(conjugate.getImaginary()));
//     imaginary_temp = ((this->real)*(conjugate.getImaginary()) + (this->imaginary)*(conjugate.getReal()));
//     this->real = real_temp;
//     this->imaginary = imaginary_temp;
//     return *this;
// }

ComplexInteger operator/(ComplexInteger c1, ComplexInteger c2) // / overloaded using a friend function 
{
    // using a/b = a*(conjugate of b)
    ComplexInteger conjugate;
    int abs_val = (c2.real)*(c2.real) + (c2.imaginary)*(c2.imaginary);
    conjugate = c2; //deep copy using overloaded assignment operator
    conjugate.imaginary = (-1)*(c2.imaginary);
    ComplexInteger temp;
    temp.real = (((c1.real)*(conjugate.real)) - ((c1.imaginary)*(conjugate.imaginary)))/abs_val;
    temp.imaginary = (((c1.real)*(conjugate.imaginary)) + ((c1.imaginary)*(conjugate.real)))/abs_val;
    return temp;
}

ComplexInteger& ComplexInteger::operator=(const ComplexInteger& c)
{
    if (&c == this)
    {
        return *this;
    }
    this->real = c.getReal();
    this->imaginary = c.getImaginary();
    return *this;
}
ComplexInteger& ComplexInteger::operator=(const int& c)
{    
    this->real = c;
    this->imaginary = 0;
    return *this;
}
ComplexInteger& ComplexInteger::operator~()
{
    int temp;
    temp = this->real;
    this->real = this->imaginary;
    this->imaginary = temp;
    return *this;
}

ComplexInteger& ComplexInteger::operator^(const ComplexInteger& c)
{
    // (a+ib)(a-ib) = a power 2 + b power 2
    int value;
    value = (this->imaginary)*(this->imaginary) + (this->real)*(this->real);
    this->real = value;
    this->imaginary = 0;
    return *this;
}

bool operator==(ComplexInteger c1,ComplexInteger c2)
{
    bool ret_val;
    if ((c1.real == c2.real) && (c1.imaginary == c2.imaginary))
    {
        ret_val = true;
    }
    else
    {
        ret_val = false;
    }
    return ret_val;
}




