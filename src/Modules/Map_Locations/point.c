#include <stdio.h>
#include "point.h"

POINT MakePOINT(Eltype_Point X, Eltype_Point Y)
{
    POINT P;
    Absis(P) = X;
    Ordinat(P) = Y;
    return P;
}

void TulisPOINT(POINT P)
{
    printf("(%d, %d)", Absis(P), Ordinat(P));
}

boolean EQ(POINT P1, POINT P2)
{
    return (Absis(P1) == Absis(P2) && Ordinat(P1) == Ordinat(P2));
}

boolean NEQ(POINT P1, POINT P2)
{
    return (!EQ(P1, P2));
}

boolean IsOrigin(POINT P)
{
    POINT Ori = MakePOINT(0, 0);
    return EQ(P, Ori);
}

boolean IsOnSbX(POINT P)
{
    return (Ordinat(P) == 0);
}

boolean IsOnSbY(POINT P)
{
    return (Absis(P) == 0);
}

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

POINT NextX(POINT P)
{
    POINT Copy;
    Absis(Copy) = Absis(P) + 1;
    Ordinat(Copy) = Ordinat(P);
    return Copy;
}

POINT NextY(POINT P)
{
    POINT Copy;
    Absis(Copy) = Absis(P);
    Ordinat(Copy) = Ordinat(P) + 1;
    return Copy;
}

POINT PlusDelta(POINT P, Eltype_Point deltaX, Eltype_Point deltaY)
{
    POINT Copy;
    Absis(Copy) = Absis(P) + deltaX;
    Ordinat(Copy) = Ordinat(P) + deltaY;
    return Copy;
}

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

void Geser(POINT *P, Eltype_Point deltaX, Eltype_Point deltaY)
{
    Absis(*P) += deltaX;
    Ordinat(*P) += deltaY;
}

void GeserKeSbX(POINT *P)
{
    Ordinat(*P) = 0;
}

void GeserKeSbY(POINT *P)
{
    Absis(*P) = 0;
}

void Mirror(POINT *P, boolean SbX)
{
    if (SbX)
        Ordinat(*P) = -Ordinat(*P);
    else
        Absis(*P) = -Absis(*P);
}
