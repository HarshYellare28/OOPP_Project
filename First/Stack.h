// NAME: HARSH YELLARE
// ROLL_NO: BT19CSE124
// ASSIGNMENT NUMBER: 2
// QUESTION NUMBER: 1
// DATE OF SUBMISSION: 26-03-2021

// DESCRIPTION : Implementation of a class to evaluate a given postfix expression using stack and operator overloading.

#include <iostream>
#include "Complex.h"
#define ITEMTYPE Complex
using namespace std;

#ifndef Stack_H
#define Stack_H
 
class Node
{
public:
    Complex data;
    Node* next;
};
 
class Stack
{
private:
    Node* top;

public:
    Stack(); // default Constructor
    ~Stack(); // destructor
    void push(Complex x);
    Complex pop();
    bool isEmpty();
    bool isFull();
    Complex stackTop();
};

#endif