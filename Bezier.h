#ifndef Bezier_h
#define Bezier_h

#define DEC1 10
#define DEC2 100
#define DEC3 1000
#define DEC4 10000
#define DEC6 1000000

class BezierCurve
{
private:
    short Point[5];

public:
    short t;
    void point(short P0, short P1, short P2, short P3, short P4);
    void getPosO4(unsigned short arrayLength, short *ret);
    void getPosCub(unsigned short arrayLength, short *ret);
    void getPosQuad(unsigned short arrayLength, short *ret);
    void getPosLin(unsigned short arrayLength, short *ret);
};
#endif