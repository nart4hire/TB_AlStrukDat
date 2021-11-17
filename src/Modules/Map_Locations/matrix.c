#include <stdio.h>
#include "matrix.h"

char mobita = '8';

void CreateMatrix(int nRow, int nCol, Matrix *m)
{
    ROWS(*m) = nRow;
    COLS(*m) = nCol;
}

boolean isIdxValid_Matrix(int i, int j)
{
    return (i > -1 && i < ROW_CAP && j > -1 && j < ROW_CAP);
}

Index getLastIdxRow(Matrix m)
{
    return (ROWS(m) - 1);
}

Index getLastIdxCol(Matrix m)
{
    return (COLS(m) - 1);
}

boolean isIdxEff_Matrix(Matrix m, Index i, Index j)
{
    return (i > -1 && i < ROWS(m) && j > -1 && j < COLS(m));
}

ElType_Matrix getElmtDiagonal(Matrix m, Index i)
{
    return (ELMT_MATRIX(m, i, i));
}

void copyMatrix(Matrix mIn, Matrix *mRes)
{
    CreateMatrix(ROWS(mIn), COLS(mIn), mRes);
    for (int i = 0; i < ROWS(mIn); i++)
    {
        for (int j = 0; j < COLS(mIn); j++)
        {
            ELMT_MATRIX(*mRes, i, j) = ELMT_MATRIX(mIn, i, j);
        }
    }
}

void readMatrix(Matrix *m, int nRow, int nCol)
{
    char x;
    CreateMatrix(nRow, nCol, m);
    for (int i = 0; i < ROWS(*m); i++)
    {
        for (int j = 0; j < COLS(*m); j++)
        {
            scanf("%c", &x);
            ELMT_MATRIX(*m, i, j) = x;
        }
    }
}

void displayMatrix(Matrix m)
{
    for (int i = 0; i < ROWS(m); i++)
    {
        for (int j = 0; j < COLS(m); j++)
            printf("%c ", ELMT_MATRIX(m, i, j));
        printf("\n");
    }
}

boolean isEqual(Matrix m1, Matrix m2)
{
    if (ROWS(m1) == ROWS(m2) && COLS(m1) == COLS(m2))
    {
        for (int i = 0; i < ROWS(m1); i++)
        {
            for (int j = 0; j < COLS(m1); j++)
            {
                if (ELMT_MATRIX(m1, i, j) != ELMT_MATRIX(m2, i, j))
                {
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}

boolean isNotEqual(Matrix m1, Matrix m2)
{
    return (!isEqual(m1, m2));
}

boolean isSizeEqual(Matrix m1, Matrix m2)
{
    return (ROWS(m1) == ROWS(m2) && COLS(m1) == COLS(m2));
}

int count(Matrix m)
{
    return (ROWS(m) * COLS(m));
}

boolean isSquare(Matrix m)
{
    return (ROWS(m) == COLS(m));
}

boolean isSymmetric(Matrix m)
{
    if (isSquare(m))
    {
        for (int i = 0; i < ROWS(m) - 1; i++)
        {
            for (int j = i + 1; j < COLS(m); j++)
            {
                if (ELMT_MATRIX(m, i, j) != ELMT_MATRIX(m, j, i))
                {
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}

void transpose(Matrix *m)
{
    if (isSquare(*m))
    {
        int temp;
        for (int i = 0; i < ROWS(*m) - 1; i++)
        {
            for (int j = i + 1; j < COLS(*m); j++)
            {
                temp = ELMT_MATRIX(*m, i, j);
                ELMT_MATRIX(*m, i, j) = ELMT_MATRIX(*m, j, i);
                ELMT_MATRIX(*m, j, i) = temp;
            }
        }
    }
}

int countValOnRow(Matrix m, Index i, ElType_Matrix val)
{
    int count = 0;
    for (int j = 0; j < COLS(m); j++)
    {
        if (ELMT_MATRIX(m, i, j) == val)
        {
            count++;
        }
    }
    return count;
}

int countValOnCol(Matrix m, Index j, ElType_Matrix val)
{
    int count = 0;
    for (int i = 0; i < ROWS(m); i++)
    {
        if (ELMT_MATRIX(m, i, j) == val)
        {
            count++;
        }
    }
    return count;
}
