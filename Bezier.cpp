#include "Bezier.h"
void BezierCurve::point(short P0, short P1, short P2, short P3, short P4)
{
    Point[0] = P0;
    Point[1] = P1;
    Point[2] = P2;
    Point[3] = P3;
    Point[4] = P4;
};

/*Bezier Curve Order 4*/
void BezierCurve::getPosO4(unsigned short arrayLength, short *ret)
{
    t = 0;
    for (short i = 0; i < arrayLength; i++)
    {
        ret[i] = (((long)(100 - t) * (100 - t) * (100 - t) / DEC4 * (100 - t) * Point[0]) / DEC4 +
                  ((long)4 * t * (100 - t) * (100 - t) / DEC4 * (100 - t) * Point[1]) / DEC4 +
                  ((long)6 * t * t * (100 - t) / DEC4 * (100 - t) * Point[2]) / DEC4 +
                  ((long)4 * t * t * t / DEC4 * (100 - t) * Point[3]) / DEC4 +
                  ((long)t * t * t / DEC4 * t * Point[4]) / DEC4);
        t += 100 / (arrayLength - 1);
    }
};

/*Bezier Curve Cubic*/
void BezierCurve::getPosCub(unsigned short arrayLength, short *ret)
{
    t = 0;
    for (short i = 0; i < arrayLength; i++)
    {
        ret[i] = (((long)(100 - t) * (100 - t) * (100 - t) / DEC4 * Point[0]) +
                  ((long)3 * t * (100 - t) * (100 - t) / DEC4 * Point[1]) +
                  ((long)3 * t * t * (100 - t) / DEC4 * Point[2]) +
                  ((long)t * t * t / DEC4 * Point[3])) /
                 DEC2;
        t += 100 / (arrayLength - 1);
    }
};

/*Bezier Curve Quadratic*/
void BezierCurve::getPosQuad(unsigned short arrayLength, short *ret)
{
    t = 0;
    for (short i = 0; i < arrayLength; i++)
    {
        ret[i] = ((long)(100 - t) * (100 - t) * Point[0] / DEC4) +
                 ((long)2 * t * (100 - t) * Point[1]) / DEC4 +
                 ((long)t * t * Point[2]) / DEC4;
        t += 100 / (arrayLength - 1);
    }
};

/*Bezier Curve Linear*/
void BezierCurve::getPosLin(unsigned short arrayLength, short *ret)
{
    t = 0;
    for (short i = 0; i < arrayLength; i++)
    {
        ret[i] = ((100 - t) * Point[0] +
                  t * Point[1]) /
                 DEC2;
        t += 100 / (arrayLength - 1);
    }
};