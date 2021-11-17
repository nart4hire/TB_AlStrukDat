#ifndef Matrix_H
#define Matrix_H

#include "boolean.h"

#define ROW_CAP 100
#define COL_CAP 100

typedef int Index;
typedef char ElType_Matrix;
typedef struct
{
   ElType_Matrix contents[ROW_CAP][COL_CAP];
   int rowEff;
   int colEff;
} Matrix;

#define ROWS(M) (M).rowEff
#define COLS(M) (M).colEff
#define ELMT_MATRIX(M, i, j) (M).contents[(i)][(j)]

void CreateMatrix(int nRow, int nCol, Matrix *m);

boolean isIdxValid_Matrix(int i, int j);

Index getLastIdxRow(Matrix m);

Index getLastIdxCol(Matrix m);

boolean isIdxEff_Matrix(Matrix m, Index i, Index j);

ElType_Matrix getElmtDiagonal(Matrix m, Index i);

void copyMatrix(Matrix mIn, Matrix *mRes);

void readMatrix(Matrix *m, int nRow, int nCol);

void displayMatrix(Matrix m);

boolean isEqual(Matrix m1, Matrix m2);

boolean isNotEqual(Matrix m1, Matrix m2);

boolean isSizeEqual(Matrix m1, Matrix m2);

int count(Matrix m);

boolean isSquare(Matrix m);

boolean isSymmetric(Matrix m);

void transpose(Matrix *m);

int countValOnRow(Matrix m, Index i, ElType_Matrix val);

int countValOnCol(Matrix m, Index j, ElType_Matrix val);

#endif