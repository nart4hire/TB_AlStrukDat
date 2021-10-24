// File: point.h
// Tanggal: 28 Agustus 2016
// *** Definisi ABSTRACT DATA TYPE POINT ***

#include <stdio.h>
#include <math.h>
#include "point.h"

// typedef struct {
// 	float X; // absis
// 	float Y; // ordinat
// } POINT;

// *** Notasi Akses: Selektor POINT ***
// #define Absis(P) (P).X
// #define Ordinat(P) (P).Y

// *** DEFINISI PROTOTIPE PRIMITIF ***
// *** Konstruktor membentuk POINT ***


POINT MakePOINT(float X, float Y)
{
    POINT P;
    Absis(P) = X;
    Ordinat(P) = Y;
    return P;
}
// Membentuk sebuah POINT dari komponen-komponennya

// *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  ***


void BacaPOINT(POINT *P)
{
    float x, y;
    scanf("%f %f", &x, &y);
    Absis(*P) = x;
    Ordinat(*P) = y;
}
// Membaca nilai absis dan ordinat dari keyboard dan membentuk
// POINT P berdasarkan dari nilai absis dan ordinat tersebut
// Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi
// Contoh: 1 2
// akan membentuk POINT <1,2>
// I.S. Sembarang
// F.S. P terdefinisi


void TulisPOINT(POINT P)
{
    printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}
// Nilai P ditulis ke layar dengan format "(X,Y)"
// tanpa spasi, enter, atau karakter lain di depan, belakang,
// atau di antaranya
// Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
// I.S. P terdefinisi
// F.S. P tertulis di layar dengan format "(X,Y)"


// *** Kelompok operasi relasional terhadap POINT ***


boolean EQ(POINT P1, POINT P2)
{
    return (Absis(P1) == Absis(P2) && Ordinat(P1) == Ordinat(P2));
}
// Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama


boolean NEQ(POINT P1, POINT P2)
{
    return (!EQ(P1, P2));
}
// Mengirimkan true jika P1 tidak sama dengan P2


// *** Kelompok menentukan di mana P berada ***


boolean IsOrigin(POINT P)
{
    POINT Ori = MakePOINT(0.0f, 0.0f);
    return EQ(P, Ori);
}
// Menghasilkan true jika P adalah titik origin


boolean IsOnSbX(POINT P)
{
    return (Ordinat(P) == 0.0f);
}
// Menghasilkan true jika P terletak Pada sumbu X


boolean IsOnSbY(POINT P)
{
    return (Absis(P) == 0.0f);
}
// Menghasilkan true jika P terletak pada sumbu Y


int Kuadran(POINT P)
{
    int kuadran = ((Absis(P) > 0) << 1) + (Ordinat(P) > 0);
    switch (kuadran)
    {
    case 3:
        return 1;
        break;
    
    case 1:
        return 2;
        break;

    case 0:
        return 3;
        break;

    case 2:
        return 4;
        break;

    default:
        return 0;
        break;
    }
}
// Menghasilkan kuadran dari P: 1, 2, 3, atau 4
// Prekondisi : P bukan titik origin,
//              dan P tidak terletak di salah satu sumbu


// *** KELOMPOK OPERASI LAIN TERHADAP TYPE ***


POINT NextX(POINT P)
{
    POINT Copy;
    Absis(Copy) = Absis(P) + 1;
    Ordinat(Copy) = Ordinat(P);
    return Copy;
}
// Mengirim salinan P dengan absis ditambah satu


POINT NextY(POINT P)
{
    POINT Copy;
    Absis(Copy) = Absis(P);
    Ordinat(Copy) = Ordinat(P) + 1;
    return Copy;
}
// Mengirim salinan P dengan ordinat ditambah satu


POINT PlusDelta(POINT P, float deltaX, float deltaY)
{
    POINT Copy;
    Absis(Copy) = Absis(P) + deltaX;
    Ordinat(Copy) = Ordinat(P) + deltaY;
    return Copy;
}
// Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY


POINT MirrorOf(POINT P, boolean SbX)
{
    POINT Copy;
    Absis(Copy) = Absis(P);
    Ordinat(Copy) = Ordinat(P);
    if (SbX)
        Ordinat(Copy) = -Ordinat(Copy);
    else
        Absis(Copy) = -Absis(Copy);
    return Copy;
}
// Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu
// Jika SbX bernilai true, maka dicerminkan terhadap sumbu X
// Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y


float Jarak0(POINT P)
{
    float x = Absis(P), y = Ordinat(P), hsl = pow(x, 2) + pow(y, 2);
    return sqrt(hsl);
}
// Menghitung jarak P ke (0,0)


float Panjang(POINT P1, POINT P2)
{
    float x = Absis(P2) - Absis(P1), y = Ordinat(P2) - Ordinat(P1), hsl = pow(x, 2) + pow(y, 2);
    return sqrt(hsl);
}
// Menghitung panjang garis yang dibentuk P1 dan P2
// Perhatikanlah bahwa di sini spec fungsi kurang baik sebab menyangkut ADT Garis.
// Tuliskan spec fungsi yang lebih tepat.


void Geser(POINT *P, float deltaX, float deltaY)
{
    Absis(*P) += deltaX;
    Ordinat(*P) += deltaY;
}
// I.S. P terdefinisi
// F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY


void GeserKeSbX(POINT *P)
{
    Ordinat(*P) = 0.0f;
}
// I.S. P terdefinisi
// F.S. P berada pada sumbu X dengan absis sama dengan absis semula.
// Proses : P digeser ke sumbu X.
// Contoh : Jika koordinat semula (9,9), maka menjadi (9,0)


void GeserKeSbY(POINT *P)
{
    Absis(*P) = 0.0f;
}
// I.S. P terdefinisi
// F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula.
// Proses : P digeser ke sumbu Y.
// Contoh : Jika koordinat semula (9,9), maka menjadi (0,9)


void Mirror(POINT *P, boolean SbX)
{
    if (SbX)
        Ordinat(*P) = -Ordinat(*P);
    else
        Absis(*P) = -Absis(*P);
}
// I.S. P terdefinisi
// F.S. P dicerminkan tergantung nilai SbX atau SbY
// Jika SbX true maka dicerminkan terhadap sumbu X
// Jika SbX false maka dicerminkan terhadap sumbu Y


void Putar(POINT *P, float Sudut)
{
    double radians;
    float nx, ny;
    radians = Sudut / 180 * M_PI;
    nx = Absis(*P) * cos(radians) + Ordinat(*P) * sin(radians);
    ny = Ordinat(*P) * cos(radians) - Absis(*P) * sin(radians);
    *P = MakePOINT(nx, ny);
}
// I.S. P terdefinisi
// F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0)

