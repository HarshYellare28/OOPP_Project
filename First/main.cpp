// NAME: HARSH YELLARE
// ROLL_NO: BT19CSE124
// ASSIGNMENT NUMBER: 2
// QUESTION NUMBER: 1
// DATE OF SUBMISSION: 26-03-2021

// DESCRIPTION : Implementation of a class to evaluate a given postfix expression using stack and operator overloading.

#include<iostream>
#include"Complex.h"
#include"Stack.h"
#include<string>
#define SIZE 100000 //Assumed input max size
using namespace std;

char input[SIZE];//Global declaration of input string 
// string input;

//Complex Number generator function from the particular parts of the string  
Complex complexGenerator(int real_offset,int* next_index)
{
    // j at MSD of real part
    int temp;
    temp = real_offset;

    while (input[temp] != ' ')
    {
        temp++;
    }
    
    // temp at ' '
    int img_offset = temp + 1;
    temp--;// temp at LSD of real part
    int real_val=0;
    int multiplier=1;    
    while (temp != (real_offset - 1))
    {
        real_val += ((int)input[temp] - 48)*multiplier;
        multiplier *= 10;
        temp--;
        if((temp == real_offset) && (input[real_offset] == '-'))
        {
            real_val = (-1)*real_val; 
            break;
        }
    }
    // imaginary part calculation
    temp = img_offset;
    while (input[temp] != ')')
    {
        temp++;
    }
    
    *next_index = temp + 2;
    temp--;// temp at LSD of img part
    multiplier=1; 
    //img_val => imaginary value
    int img_val=0; 
      
    while (temp != (img_offset - 1))
    {
        img_val += ((int)input[temp] - 48)*multiplier;
        multiplier *= 10;
        temp--;
        if((temp == img_offset) && (input[img_offset] == '-'))
        {
            img_val = (-1)*img_val; 
            break;
        }
    }   
    
    Complex num;
    num.setComplex(real_val,img_val);
    return num;
}

int main()
{
    Stack myStack;
    int i=0;
    cout<<"Enter the input line"<<endl;
    cin.getline(input,SIZE);
    i=0;
    Complex temp;
    Complex operand_add1,operand_add2,operand_sub1,operand_sub2,operand_mul1,operand_mul2,operand_div1,operand_div2;
    while ((input[i] != '\0') && (input[i] != '\n'))
    {
        if (input[i] == '(')
        {
            temp = complexGenerator(i+1, &i);//passed &i to update the index to the next offset  
            myStack.push(temp);
                
        }
        else if(input[i] == '+')
        {
            operand_add2 = myStack.pop();
            operand_add1 = myStack.pop();
            operand_add1.add(operand_add2);
            myStack.push(operand_add1);
            i=i+2;
        }
        else if(input[i] == '-')
        {
            operand_sub2 = myStack.pop();
            operand_sub1 = myStack.pop();
            operand_sub1.subtract(operand_sub2);
            myStack.push(operand_sub1);
            i=i+2;
        }
        else if(input[i] == '*')
        {
            operand_mul2 = myStack.pop();
            operand_mul1 = myStack.pop();
            operand_mul1.multiply(operand_mul2);
            myStack.push(operand_mul1);
            i=i+2;
        }
        else if(input[i] == '/')
        {
            operand_div2 = myStack.pop();
            operand_div1 = myStack.pop();
            operand_div1.dividedBy(operand_div2);           
            myStack.push(operand_div1);
            i=i+2;
        }
        else
        {
            break;
        }      
    }
    Complex result ;
    result = myStack.pop();     
    cout<<"The resulting Complex number is: "<<result<<endl; // use of overloading of cout 
    return 0;
}