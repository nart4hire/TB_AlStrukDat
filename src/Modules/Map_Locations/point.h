

#ifndef POINT_H
#define POINT_H

#include "boolean.h"

typedef int Eltype_Point;
typedef struct
{
   Eltype_Point X;
   Eltype_Point Y;
} POINT;

#define Absis(P) (P).X
#define Ordinat(P) (P).Y

POINT MakePOINT(Eltype_Point X, Eltype_Point Y);

void TulisPOINT(POINT P);

boolean EQ(POINT P1, POINT P2);

boolean NEQ(POINT P1, POINT P2);

boolean IsOrigin(POINT P);

boolean IsOnSbX(POINT P);

boolean IsOnSbY(POINT P);

int Kuadran(POINT P);

POINT NextX(POINT P);

POINT NextY(POINT P);

POINT PlusDelta(POINT P, Eltype_Point deltaX, Eltype_Point deltaY);

POINT MirrorOf(POINT P, boolean SbX);

void Geser(POINT *P, Eltype_Point deltaX, Eltype_Point deltaY);

void GeserKeSbX(POINT *P);

void GeserKeSbY(POINT *P);

void Mirror(POINT *P, boolean SbX);

#endif