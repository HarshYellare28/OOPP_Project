// NAME: HARSH YELLARE
// ROLL_NO: BT19CSE124
// ASSIGNMENT NUMBER: 2
// QUESTION NUMBER: 3
// DATE OF SUBMISSION: 26-03-2021

// DESCRIPTION : Implementation of a MATRIX class containing ComplexInteger objects and demonstration of operator overloading 


#include<iostream>
#include"ComplexInteger.h"
using namespace std;

#define NUM_ROWS 10000;
#define NUM_COLS 10000; // Assumed max size

#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
    friend void displayContents(const Matrix& );
    friend bool searchInMatrix(const Matrix&  ,const ComplexInteger& );
    friend Matrix operator+(const Matrix& ,const ComplexInteger& ); // M + c
    friend Matrix operator+(const ComplexInteger& ,const Matrix& ); // c + M
    friend Matrix operator+(const Matrix& ,const Matrix& ); // M1 + M2
    friend Matrix operator+(const Matrix& ,const int& ); // M + i
    friend Matrix operator+(const int& ,const Matrix& ); // i + M
    friend Matrix operator-(const Matrix& ,const ComplexInteger& ); // M - c
    friend Matrix operator-(const ComplexInteger&,const Matrix& ); // c - M
    friend Matrix operator-(const Matrix& ,const Matrix& ); // M1 - M2
    friend Matrix operator-(const Matrix& ,const int& ); // M - x
    friend Matrix operator-(const int& ,const Matrix& ); // x - M
    friend Matrix operator*(const Matrix& ,const ComplexInteger& ); // M * c
    friend Matrix operator*(const ComplexInteger&, const Matrix& ); // c * M
    friend Matrix operator*(const Matrix& ,const Matrix&); // M1 * M2
    friend Matrix operator*(const Matrix& ,const int& ); // M * i
    friend Matrix operator*(const int&, const Matrix& ); // i * M
    
private:
    int num_rows,num_cols;
    ComplexInteger** array;

public:
    Matrix();
    Matrix(int , int );
    Matrix(int , int, const ComplexInteger& );
    Matrix(const Matrix& );
    ~Matrix();
    void setNumRows(const int& );
    void setNumCols(const int& );
    int getNumRows() const;
    int getNumCols() const;
    void setValue(const int& , const int& ,const ComplexInteger& ); // sets a ComplexInteger at location i , j 
    ComplexInteger getValue(int , int ) const ;// returns ComplexInteger at location i, j
    Matrix& operator^(const int& );
    Matrix& operator=(const Matrix& );
    // Matrix& operator=(ComplexInteger ,int , int );
};

#endif