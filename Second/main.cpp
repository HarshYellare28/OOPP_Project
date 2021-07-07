// NAME: HARSH YELLARE
// ROLL_NO: BT19CSE124
// ASSIGNMENT NUMBER: 2
// QUESTION NUMBER: 2
// DATE OF SUBMISSION: 26-03-2021

// DESCRIPTION : Implementation of a ComplexInteger class and demonstration of operator overloading 


#include<iostream>
#include"ComplexInteger.h"
using namespace std ;
ComplexInteger& conjugate(ComplexInteger& );// A non member function


ComplexInteger& conjugate(ComplexInteger& c)// Non member function
{
    int img_temp;//temp variable for imaginary part
    img_temp = (-1)*(c.getImaginary());
    c.setImaginary(img_temp); 
    return c;
}

int main()
{
    ComplexInteger input1(0,0),input2(0,0);
    cout<<"Enter the inputs: \n";
    cout<<"Enter first operand in the form (p q) where ComplexInteger is p+qi \n";
    cin>>input1;
    cout<<"Enter second operand: \n";
    cin>>input2;
    ComplexInteger result;
    int input3;
    result = input1 + input2 ;
    cout<<"The result of addition is: "<<result<<endl;  
    result = input1 - input2 ;
    cout<<"The result of subtraction is: "<<result<<endl;  
    result = input1 * input2 ;
    cout<<"The result of multiplication is: "<<result<<endl;    
    result = input1 / input2 ; //Floor division on complex number 
    cout<<"The result of division is: "<<result<<endl;
    result = input1; // demo of assignment operator
    cout<<"The result of assignment operator is: "<<result<<endl;
    cout<<"Enter any integer value:\n";
    cout<<"This is to show that the assignment operator is overloaded such that we can assign integer object to ComplexInteger Object\n";
    cin>>input3;
    result = input3; // demo of assignment operator
    cout<<"The result of assignment operator is: "<<result<<endl;
    result = ~input1; // demo of ~ unary operator
    cout<<"The result of ~ operator is: "<<result<<endl;
    result = input2^(conjugate(input2));
    cout<<"The result of ^ on input2 is: "<<result<<endl;

    return 0;
}