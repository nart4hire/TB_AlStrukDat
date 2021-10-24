// ********** Definisi TYPE Matrix dengan Index dan elemen integer **********

#include <stdio.h>
#include "matrix.h"

// Ukuran minimum dan maksimum baris dan kolom
// #define ROW_CAP 100
// #define COL_CAP 100

// typedef int Index; // Index baris, kolom
// typedef int ElType;
// typedef struct
// {
//    ElType contents[ROW_CAP][COL_CAP];
//    int rowEff; // banyaknya/ukuran baris yg terdefinisi
//    int colEff; // banyaknya/ukuran kolom yg terdefinisi
// } Matrix;
// rowEff >= 1 dan colEff >= 1
// Indeks matriks yang digunakan: [0..ROW_CAP-1][0..COL_CAP-1]
// Memori matriks yang dipakai selalu di "ujung kiri atas"

// ********** DEFINISI PROTOTIPE PRIMITIF **********
// *** Konstruktor membentuk Matrix ***

void CreateMatrix(int nRow, int nCol, Matrix *m)
{
    ROWS(*m) = nRow;
    COLS(*m) = nCol;
}
// Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori
// I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat
// F.S. Matriks m sesuai dengan definisi di atas terbentuk

// *** Selektor ***

// #define ROWS(M) (M).rowEff
// #define COLS(M) (M).colEff
// #define ELMT_MATRIX(M, i, j) (M).contents[(i)][(j)]

// *** Selektor "DUNIA Matrix" ***

boolean isIdxValid_Matrix(int i, int j)
{
    return (i > -1 && i < ROW_CAP && j > -1 && j < ROW_CAP);
}
// Mengirimkan true jika i, j adalah Index yang valid untuk matriks apa pun

// *** Selektor: Untuk sebuah matriks m yang terdefinisi: ***

Index getLastIdxRow(Matrix m)
{
    return (ROWS(m) - 1);
}
// Mengirimkan Index baris terbesar m

Index getLastIdxCol(Matrix m)
{
    return (COLS(m) - 1);
}
// Mengirimkan Index kolom terbesar m

boolean isIdxEff_Matrix(Matrix m, Index i, Index j)
{
    return (i > -1 && i < ROWS(m) && j > -1 && j < COLS(m));
}
// Mengirimkan true jika i, j adalah Index efektif bagi m

ElType getElmtDiagonal(Matrix m, Index i)
{
    return (ELMT_MATRIX(m, i, i));
}
// Mengirimkan elemen m(i,i)

// ********** Assignment  Matrix **********

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
// Melakukan assignment MRes = MIn

// ********** KELOMPOK BACA/TULIS **********

void readMatrix(Matrix *m, int nRow, int nCol)
{
    int x;
    CreateMatrix(nRow, nCol, m);
    for (int i = 0; i < ROWS(*m); i++)
    {
        for (int j = 0; j < COLS(*m); j++)
        {
            scanf("%d", &x);
            ELMT_MATRIX(*m, i, j) = x;
        }
    }
}
// I.S. isIdxValid_Matrix(nRow,nCol)
// F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol
// Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya
// Selanjutnya membaca nilai elemen per baris dan kolom
// Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
// 1 2 3
// 4 5 6
// 8 9 10

void displayMatrix(Matrix m)
{
    for (int i = 0; i < ROWS(m); i++)
    {
        for (int j = 0; j < COLS(m); j++)
        {
            printf("%d", ELMT_MATRIX(m, i, j));
            if (j < COLS(m) - 1)
            {
                printf(" ");
            }
            else if (i != ROWS(m) - 1)
            {
                printf("\n");
            }
        }
    }
}
// I.S. m terdefinisi
// F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
// dipisahkan sebuah spasi
// Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom
// Contoh: Menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
// 1 2 3
// 4 5 6
// 8 9 10

// ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE **********

Matrix addMatrix(Matrix m1, Matrix m2)
{
    Matrix mhas;
    CreateMatrix(ROWS(m1), COLS(m1), &mhas);
    for (int i = 0; i < ROWS(m1); i++)
    {
        for (int j = 0; j < COLS(m1); j++)
        {
            ELMT_MATRIX(mhas, i, j) = ELMT_MATRIX(m1, i, j) + ELMT_MATRIX(m2, i, j);
        }
    }
    return mhas;
}
// Prekondisi : m1 berukuran sama dengan m2
// Mengirim hasil penjumlahan matriks: m1 + m2

Matrix subtractMatrix(Matrix m1, Matrix m2)
{
    Matrix mhas;
    CreateMatrix(ROWS(m1), COLS(m1), &mhas);
    for (int i = 0; i < ROWS(m1); i++)
    {
        for (int j = 0; j < COLS(m1); j++)
        {
            ELMT_MATRIX(mhas, i, j) = ELMT_MATRIX(m1, i, j) - ELMT_MATRIX(m2, i, j);
        }
    }
    return mhas;
}
// Prekondisi : m1 berukuran sama dengan m2
// Mengirim hasil pengurangan matriks: salinan m1 – m2

Matrix multiplyMatrix(Matrix m1, Matrix m2)
{
    Matrix mhas;
    CreateMatrix(ROWS(m1), COLS(m2), &mhas);
    for (int i = 0; i < ROWS(m1); i++)
    {
        for (int j = 0; j < COLS(m2); j++)
        {
            ELMT_MATRIX(mhas, i, j) = 0;
            for (int k = 0; k < ROWS(m2); k++)
            {
                ELMT_MATRIX(mhas, i, j) += ELMT_MATRIX(m1, i, k) * ELMT_MATRIX(m2, k, j);
            }
        }
    }
    return mhas;
}
// Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2
// Mengirim hasil perkalian matriks: salinan m1 * m2

Matrix multiplyConst(Matrix m, ElType x)
{
    Matrix mhas;
    CreateMatrix(ROWS(m), COLS(m), &mhas);
    for (int i = 0; i < ROWS(m); i++)
    {
        for (int j = 0; j < COLS(m); j++)
        {
            ELMT_MATRIX(mhas, i, j) = ELMT_MATRIX(m, i, j) * x;
        }
    }
    return mhas;
}
// Mengirim hasil perkalian setiap elemen m dengan x

void pMultiplyConst(Matrix *m, ElType k)
{
    for (int i = 0; i < ROWS(*m); i++)
    {
        for (int j = 0; j < COLS(*m); j++)
        {
            ELMT_MATRIX(*m, i, j) = ELMT_MATRIX(*m, i, j) * k;
        }
    }
}
// I.S. m terdefinisi, k terdefinisi
// F.S. Mengalikan setiap elemen m dengan k

// ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix **********

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
// Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan
// untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j)
// Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2)

boolean isNotEqual(Matrix m1, Matrix m2)
{
    return (!isEqual(m1, m2));
}
// Mengirimkan true jika m1 tidak sama dengan m2

boolean isSizeEqual(Matrix m1, Matrix m2)
{
    return (ROWS(m1) == ROWS(m2) && COLS(m1) == COLS(m2));
}
// Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2

// ********** Operasi lain **********

int count(Matrix m)
{
    return (ROWS(m) * COLS(m));
}
// Mengirimkan banyaknya elemen m

// ********** KELOMPOK TEST TERHADAP Matrix **********

boolean isSquare(Matrix m)
{
    return (ROWS(m) == COLS(m));
}
// Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama

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
// Mengirimkan true jika m adalah matriks simetri : isSquare(m)
// dan untuk setiap elemen m, m(i,j)=m(j,i)

boolean isIdentity(Matrix m)
{
    if (isSquare(m))
    {
        for (int i = 0; i < ROWS(m); i++)
        {
            if (ELMT_MATRIX(m, i, i) == 1)
            {
                for (int j = i + 1; j < COLS(m); j++)
                {
                    if (ELMT_MATRIX(m, i, j) != 0 || ELMT_MATRIX(m, j, i) != 0)
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
    return false;
}
// Mengirimkan true jika m adalah matriks satuan: isSquare(m) dan
// setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0

boolean isSparse(Matrix m)
{
    float percentage, c = 0;
    for (int i = 0; i < ROWS(m); i++)
    {
        for (int j = 0; j < COLS(m); j++)
        {
            if (ELMT_MATRIX(m, i, j) > 0)
            {
                c++;
            }
        }
    }
    percentage = (c * 100 / count(m));
    return (percentage <= 5);
}
// Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi:
// hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0

Matrix inverse1(Matrix m)
{
    Matrix mhas;
    CreateMatrix(ROWS(m), COLS(m), &mhas);
    for (int i = 0; i < ROWS(m); i++)
    {
        for (int j = 0; j < COLS(m); j++)
        {
            ELMT_MATRIX(mhas, i, j) = ELMT_MATRIX(m, i, j) * (-1);
        }
    }
    return mhas;
}
// Menghasilkan salinan m dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1)

void pInverse1(Matrix *m)
{
    for (int i = 0; i < ROWS(*m); i++)
    {
        for (int j = 0; j < COLS(*m); j++)
        {
            ELMT_MATRIX(*m, i, j) = ELMT_MATRIX(*m, i, j) * (-1);
        }
    }
}
// I.S. m terdefinisi
// F.S. m di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1)

float determinant(Matrix m)
{
    float tally = 0;
    int sign = 1;
    Matrix mtemp;
    switch (ROWS(m))
    {
    case 1:
        return (ELMT_MATRIX(m, 0, 0));
    case 2:
        return (ELMT_MATRIX(m, 0, 0) * ELMT_MATRIX(m, 1, 1) - ELMT_MATRIX(m, 0, 1) * ELMT_MATRIX(m, 1, 0));
    default:
        CreateMatrix(ROWS(m) - 1, COLS(m) - 1, &mtemp);
        int row = 0;
        for (int k = 0; k < ROWS(m); k++)
        {
            for (int i = 0; i < ROWS(m); i++)
            {
                if (i != k)
                {
                    for (int j = 1; j < COLS(m); j++)
                    {
                        ELMT_MATRIX(mtemp, row, (j - 1)) = ELMT_MATRIX(m, i, j);
                    }
                    row++;
                }
            }
            row = 0;
            tally += sign * ELMT_MATRIX(m, k, 0) * determinant(mtemp);
            sign = -sign;
        }
        return tally;
    }
}
// Prekondisi: isSquare(m)
// Menghitung nilai determinan m

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
// I.S. m terdefinisi dan isSquare(m)
// F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i)

// Tambahan

float rowMean(Matrix m, Index i)
{
    int count = 0;
    float tally = 0;
    while (count < COLS(m))
    {
        tally += ELMT_MATRIX(m, i, count);
        count++;
    }
    return (tally / COLS(m));
}
// Menghasilkan rata-rata dari elemen pada baris ke-i
// Prekondisi: i adalah indeks baris efektif dari M

float colMean(Matrix m, Index j)
{
    int count = 0;
    float tally = 0;
    while (count < ROWS(m))
    {
        tally += ELMT_MATRIX(m, count, j);
        count++;
    }
    return (tally / ROWS(m));
}
// Menghasilkan rata-rata dari elemen pada kolom ke-j
// Prekondisi: j adalah indeks kolom efektif dari M

void rowExtremes(Matrix m, Index i, ElType *max, ElType *min)
{
    *max = ELMT_MATRIX(m, i, 0);
    *min = ELMT_MATRIX(m, i, 0);
    for (int j = 1; j < COLS(m); j++)
    {
        if (*max < ELMT_MATRIX(m, i, j))
        {
            *max = ELMT_MATRIX(m, i, j);
        }
        if (*min > ELMT_MATRIX(m, i, j))
        {
            *min = ELMT_MATRIX(m, i, j);
        }
    }
}
// I.S. i adalah indeks baris efektif dari M, M terdefinisi
// F.S. max berisi elemen maksimum pada baris i dari M
//         min berisi elemen minimum pada baris i dari M

void colExtremes(Matrix m, Index j, ElType *max, ElType *min)
{
    *max = ELMT_MATRIX(m, 0, j);
    *min = ELMT_MATRIX(m, 0, j);
    for (int i = 1; i < ROWS(m); i++)
    {
        if (*max < ELMT_MATRIX(m, i, j))
        {
            *max = ELMT_MATRIX(m, i, j);
        }
        if (*min > ELMT_MATRIX(m, i, j))
        {
            *min = ELMT_MATRIX(m, i, j);
        }
    }
}
// I.S. j adalah indeks kolom efektif dari M, M terdefinisi
// F.S. max berisi elemen maksimum pada kolom j dari M
//         min berisi elemen minimum pada kolom j dari M

int countValOnRow(Matrix m, Index i, ElType val)
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
// Menghasilkan banyaknya kemunculan X pada baris i dari M

int countValOnCol(Matrix m, Index j, ElType val)
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
// Menghasilkan banyaknya kemunculan X pada kolom j dari M
