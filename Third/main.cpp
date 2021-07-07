// NAME: HARSH YELLARE
// ROLL_NO: BT19CSE124
// ASSIGNMENT NUMBER: 2
// QUESTION NUMBER: 3
// DATE OF SUBMISSION: 26-03-2021

// DESCRIPTION : Implementation of a MATRIX class containing ComplexInteger objects and demonstration of operator overloading 


#include<iostream>
#include"Matrix.h"

using namespace std ;

int main()
{
    ComplexInteger temp;
    int nr, nc;
    cout<<"Enter Number of rows and columns for Matrix1"<<endl;
    cin>>nr>>nc;
    Matrix M1(nr,nc);
    cout<<"Enter First Matrix elements"<<endl;
    for (int i = 0; i < M1.getNumRows(); i++)
    {
        for (int j = 0; j < M1.getNumCols(); j++)
        {
            cout<<"Enter Complex Number(p + qi) in the form p<space>q :\n";
            cin>>temp;
            M1.setValue(i,j,temp);
        }        
    }
    cout<<"Enter Number of rows and columns for Matrix2"<<endl;
    cin>>nr>>nc;
    Matrix M2(nr,nc);    
    cout<<"Enter Second Matrix Elements"<<endl;
    for (int i = 0; i < M2.getNumRows(); i++)
    {
        for (int j = 0; j < M2.getNumCols(); j++)
        {
            cout<<"Enter Complex Number(p + qi) in the form p<space>q :\n";
            cin>>temp;
            M2.setValue(i,j,temp);
        }        
    }
    cout<<"The contents of M1 is :"<<endl;
    displayContents(M1);
    cout<<"The contents of M2 is :"<<endl;
    displayContents(M2);

    ComplexInteger key;
    cout<<"Enter key (Complex Integer in the form p<space>q ) to search a number in first matrix: "<<endl;
    cin>>key;
    bool ans = searchInMatrix(M1,key);
    if(ans==true)
    {
        cout<<"Element Found\n";
    }
    else
    {
        cout<<"Ëlement Not found\n"<<endl;
    }

    Matrix result;
    cout<<"Enter a Complex Integer p + qi in the form (p<space>q) to demonstrate its addition/subtraction/multiplication to a matrix"<<endl;
    ComplexInteger c;
    cin>>c;
    result = c + M1;
    cout<<"The result of Complex Integer + Matrix is :\n";
    displayContents(result);
    result = M1 + c;
    cout<<"The result of Matrix + Complex Integer is :\n";
    displayContents(result);
    result = M1 + M2;
    cout<<"The result of Matrix + Matrix is :\n";
    displayContents(result);
    cout<<"Ënter a real integer value to demonstrate its addition/subtraction/multiplication to a matrix"<<endl;
    int int_val;
    cin>>int_val;
    result = M1 + int_val;
    cout<<"The result of Matrix + Real Integer is :\n";
    displayContents(result);
    result = int_val + M1;
    cout<<"The result of Real Integer +  Matrix is :\n";
    displayContents(result);
    result = c - M1;
    cout<<"The result of Complex Integer - Matrix is :\n";
    displayContents(result);
    result = M1 - c;
    cout<<"The result of Matrix - Complex Integer is :\n";
    displayContents(result);
    result = M1 - M2;
    cout<<"The result of Matrix - Matrix is :\n";
    displayContents(result);
    result = M1 - int_val;
    cout<<"The result of  Matrix - Real Integer is :\n";
    displayContents(result);
    result = int_val - M1;
    cout<<"The result of Real Integer - Matrix is :\n";
    displayContents(result); 
    result = c * M1;
    cout<<"The result of Complex Integer * Matrix is :\n";
    displayContents(result);
    result = M1 * c;
    cout<<"The result of Matrix * Complex Integer is :\n";
    displayContents(result);
    result = M1 * M2;
    cout<<"The result of Matrix * Matrix is :\n";
    displayContents(result);
    result = M1 * int_val;
    cout<<"The result of  Matrix * Real Integer is :\n";
    displayContents(result);
    result = int_val * M1;
    cout<<"The result of Real Integer * Matrix is :\n";
    displayContents(result);
    cout<<"Enter intger x for M^x i.e set x th location in M to 0:\n";
    int x;
    cin>>x;
    M1^x;
    cout<<"The result of ^ on M1 is: \n";
    displayContents(M1);
    return 0;
}