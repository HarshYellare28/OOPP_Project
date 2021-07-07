// NAME: HARSH YELLARE
// ROLL_NO: BT19CSE124
// ASSIGNMENT NUMBER: 2
// QUESTION NUMBER: 1
// DATE OF SUBMISSION: 26-03-2021

// DESCRIPTION : Implementation of a class to evaluate a given postfix expression using stack and operator overloading.

#include"Stack.h"
using namespace std;

Stack::Stack()
{
    top = NULL;
}
 
Stack::~Stack()
{
    Node* p = top;
    while (top != NULL)
    {
        top = top->next;
        delete p; //deletion of memory allocated on heap
        p = top; 
    }
}
 
void Stack::push(Complex x)
{
    Node* t = new Node;
    if (t == NULL)
    {
        cout << "Stack Overflow!" << endl;
    } 
    else
    {
        t->data = x; // overloaded assignment operator coming into work
        t->next = top;
        top = t;
    }
}
 
Complex Stack::pop() 
{
    Node* p;
    Complex x(0,0);
    if (top == NULL)
    {
        cout << "Stack Underflow!" << endl;
    } 
    else 
    {
        p = top;
        x = p->data;
        top = top->next;
        delete p;
    }
    return x;
}
 
bool Stack::isFull()
{
    Node* t = new Node;
    bool ret_val = (t!=NULL) ? true : false;
    delete t;
    return ret_val;
}
 
bool Stack::isEmpty() 
{
    return (top!=NULL) ? false : true;
}

Complex Stack::stackTop() 
{
    if (top!=NULL)
    {
        return top->data;
    }
    else
    {
        cout<<"Stack is empty"<<endl;
    }    
}
