// NAME: HARSH YELLARE
// ROLL_NO: BT19CSE124
// ASSIGNMENT NUMBER: 2
// QUESTION NUMBER: 3
// DATE OF SUBMISSION: 26-03-2021

// DESCRIPTION : Implementation of a MATRIX class containing ComplexInteger objects and demonstration of operator overloading 


#include<iostream>
#include"Matrix.h"
using namespace std;

Matrix::Matrix()// Default Constructor
{
    num_rows = NUM_ROWS;
    num_cols = NUM_COLS;
    array = (ComplexInteger** )malloc(sizeof(ComplexInteger)*num_rows);
    for (int i = 0; i < num_rows; i++)
    {
        array[i] = (ComplexInteger*)malloc(sizeof(ComplexInteger)*num_cols);
    }
}

Matrix::Matrix(int r,int c)// Parameterized Constructor
{
    num_rows = r;
    num_cols = c;
    array = (ComplexInteger** )malloc(sizeof(ComplexInteger)*num_rows);
    for (int i = 0; i < num_rows; i++)
    {
        array[i] = (ComplexInteger* )malloc(sizeof(ComplexInteger)*num_cols);
    }    
}

Matrix::Matrix(int r,int c,const ComplexInteger& populate) // Parameterized Constructor
{
    num_rows = r;
    num_cols = c;
    array = (ComplexInteger** )malloc(sizeof(ComplexInteger)*num_rows);
    for (int i = 0; i < num_rows; i++)
    {
        array[i] = (ComplexInteger* )malloc(sizeof(ComplexInteger)*num_cols);
    }
    for (int i = 0; i < num_rows; i++)
    {
        for (int j = 0; j < num_cols; j++)
        {
            array[i][j] = populate;
        }        
    }
}

Matrix::Matrix(const Matrix& M) // Copy Constructor
{
    num_rows = M.num_rows;
    num_cols = M.num_cols;
    for (int i = 0; i < num_rows; i++)
    {
        for (int j = 0; j < num_cols; j++)
        {
            array[i][j] = M.array[i][j];
        }        
    }    
}

Matrix::~Matrix() // Destructor
{
    num_cols = num_rows = 0;
    free(array);
    array = NULL;
}

void Matrix::setNumRows(const int& r)
{
    num_rows = r;
}

void Matrix::setNumCols(const int& c)
{
    num_cols = c;
}

void Matrix::setValue(const int& i,const int& j ,const ComplexInteger& c)
{
    array[i][j] = c;
}

int Matrix::getNumRows() const 
{
    return num_rows;
}

int Matrix::getNumCols() const 
{
    return num_cols;
}

ComplexInteger Matrix::getValue(int i, int j) const
{
    return array[i][j];
}

void displayContents(const Matrix& M)
{
    cout<<endl;
    for (int i = 0; i < M.num_rows; i++)
    {
        for (int j = 0; j < M.num_cols; j++)
        {
            cout<<M.array[i][j]<<" ";
        }
        cout<<endl;        
    }
    cout<<endl;    
}

bool searchInMatrix(const Matrix& M,const ComplexInteger& c)
{
    int found = 0;
    bool ret_val ;
    for (int i = 0;( i < M.num_rows) && (!found) ; i++)
    {
        for (int j = 0; (j < M.num_cols) && (!found) ; j++)
        {
            if (M.array[i][j] == c)//Additional overloaded "==" operator coming into play here 
            {
                found = 1;
            }           
        }      
    }
    if(found == 1)
    {
        ret_val = true;
    }
    else
    {
        ret_val = false;
    }
    return ret_val;
}

Matrix operator+(const Matrix& M,const ComplexInteger& c) // M + c
{
    Matrix result(M.num_rows,M.num_cols);
    for (int i = 0; i < M.num_rows; i++)
    {
        for (int j = 0; j < M.num_cols; j++)
        {
            result.array[i][j] = M.array[i][j] + c; 
        }
    }  
    return result;
}
Matrix operator+(const ComplexInteger& c,const Matrix& M) // c + M
{
    Matrix result(M.num_rows,M.num_cols);
    for (int i = 0; i < M.num_rows; i++)
    {
        for (int j = 0; j < M.num_cols; j++)
        {
            result.array[i][j] = M.array[i][j] + c; 
        }
    }
    return result;
}
Matrix operator+(const Matrix& M1,const Matrix& M2) // M1 + M2
{
    Matrix result(M1.num_rows,M1.num_cols);
    // Necessary Condition Check 
    if ((M1.getNumRows() != M2.getNumRows()) || (M1.getNumCols() != M2.getNumCols()))
    {
        cout<<"Invalid operands"<<endl;
    }
    else
    {
        for (int i = 0; i < M1.num_rows; i++)
        {            
            for (int j = 0; j < M1.num_cols; j++)
            {
                result.array[i][j] = M1.array[i][j] + M2.array[i][j];  
            }
        }
        return result;
    }    
}

Matrix operator+(const Matrix& M ,const int& x ) // M + x
{
    Matrix result(M.num_rows,M.num_cols);
    ComplexInteger c ;
    c = x ;// overloaded "=" operator in ComplexInteger Class is able to handle a real integer
    result = M + c;
    return result; // returns M + x actually
}

Matrix operator+(const int& x ,const Matrix& M) // M + x
{
    Matrix result(M.num_rows,M.num_cols);
    ComplexInteger c ;
    c = x ;// overloaded "=" operator in ComplexInteger Class is able to handle a real integer
    result = M + c;
    return result; // returns M + x actually
}

Matrix operator-(const Matrix& M,const ComplexInteger& c) // M - c
{
    Matrix result(M.num_rows,M.num_cols);
    for (int i = 0; i < M.num_rows; i++)
    {
        for (int j = 0; j < M.num_cols; j++)
        {
            result.array[i][j] = M.array[i][j] - c; 
        }
    } 
    return result; 
}
Matrix operator-(const ComplexInteger& c,const Matrix& M) // c - M
{
    Matrix result(M.num_rows,M.num_cols);
    for (int i = 0; i < M.num_rows; i++)
    {
        for (int j = 0; j < M.num_cols; j++)
        {
            result.array[i][j] = c - M.array[i][j] ; 
        }
    }
    return result;
}
Matrix operator-(const Matrix& M1, const Matrix& M2) // M1 - M2
{
    Matrix result(M1.num_rows,M1.num_cols);    
    // Necessary Condition Check 
    if ((M1.getNumRows() != M2.getNumRows()) || (M1.getNumCols() != M2.getNumRows()))
    {
        cout<<"Invalid operands"<<endl;
    }
    else
    {
        for (int i = 0; i < M1.num_rows; i++)
        {
            for (int j = 0; j < M1.num_cols; j++)
            {
                result.array[i][j] = M1.array[i][j] - M2.array[i][j]; 
            }
        }
        return result;
    }
    
}

Matrix operator-(const Matrix& M , const int& x ) // M - x
{
    Matrix result(M.num_rows,M.num_cols);
    ComplexInteger c ;
    c = x ;// overloaded "=" operator in ComplexInteger Class is able to handle a real integer
    result = M - c;
    return result; // returns M - x actually
}

Matrix operator-( const int& x  , const Matrix& M) // x - M
{
    Matrix result(M.num_rows,M.num_cols);
    ComplexInteger c ;
    c = x ;// overloaded "=" operator in ComplexInteger Class is able to handle a real integer
    result = c - M;
    return result; // returns x - M actually
}

Matrix& Matrix::operator^(const int& x)
{
    int i, j ;
    ComplexInteger c;
    c = 0;
    i = (x / num_cols);
    j = x - (i*num_cols);
    this->setValue(i,j,c);
    return *this;
}

Matrix& Matrix::operator=(const Matrix& M)
{
    num_rows = M.num_rows;
    num_cols = M.num_cols;
    for (int i = 0; i < num_rows; i++)
    {
        for (int j = 0; j < num_cols; j++)
        {
            array[i][j] = M.array[i][j];
        }        
    }  
    return *this;   
}

// Matrix& Matrix::operator=(ComplexInteger arr[][],int nr, int nc)
// {
//     this->num_rows = nr;
//     this->num_cols = nc;
// 	int i,j;
//     for (i = 0; i < num_rows; i++)
//     {
//         for (j = 0; j < num_cols; j++)
//         {
//         	array[i][j] = arr[i][j];
// 		}
//     }
//     return *this;
// }

Matrix operator*(const Matrix& M,const ComplexInteger& c) // M * c
{
    Matrix result(M.num_rows,M.num_cols);
    for (int i = 0; i < M.num_rows; i++)
    {
        for (int j = 0; j < M.num_cols; j++)
        {
            result.array[i][j] = M.array[i][j] * c ; 
        }
    }
    return result;  
}
Matrix operator*(const ComplexInteger& c,const Matrix& M) // c * M
{
    Matrix result(M.num_rows,M.num_cols);
    for (int i = 0; i < M.num_rows; i++)
    {
        for (int j = 0; j < M.num_cols; j++)
        {
            result.array[i][j] = M.array[i][j] * c; 
        }
    }
    return result;
}
Matrix operator*(const Matrix& M1,const Matrix& M2) // M1 * M2
{
    Matrix result(M1.num_rows,M2.num_cols);
    // Necessary Condition Check 
    if ((M1.num_cols != M2.num_rows))
    {
        cout<<"Invalid operands"<<endl;
    }
    else
    {
        for (int i = 0; i < M1.num_rows; i++)
        {
            for (int j = 0; j < M2.num_cols; j++)
            {
                result.array[i][j] = 0;
                for (int k = 0; k < M1.num_cols; k++)
                {
                    result.array[i][j] = result.array[i][j] + (M1.getValue(i,k))*(M2.getValue(k,j));
                }                 
            }
        }
        return result;
    }
    
}

Matrix operator*(const Matrix& M ,const int& x ) // M * x
{
    Matrix result(M.num_rows,M.num_cols);
    ComplexInteger c ;
    c = x ;// overloaded "=" operator in ComplexInteger Class is able to handle a real integer
    result = M * c;
    return result; // returns M * x actually
}

Matrix operator*( const int& x  , const Matrix& M) // M * x
{
    Matrix result(M.num_rows,M.num_cols);
    ComplexInteger c ;
    c = x ;// overloaded "=" operator in ComplexInteger Class is able to handle a real integer
    result = M * c;
    return result; // returns M * x actually
}


