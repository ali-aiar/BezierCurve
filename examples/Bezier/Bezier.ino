#include <Bezier.h>
#define ArrSample 16
short DownPathY[ArrSample];
short DownPathZ[ArrSample];
short LeftPathY[ArrSample];
short LeftPathZ[ArrSample];
short RightPathY[ArrSample];
short RightPathZ[ArrSample];

void setup()
{
  Serial.begin(9600);
  BezierCurve BezierDownY, BezierDownZ, BezierLeftY, BezierLeftZ, BezierRightY, BezierRightZ;
  BezierDownY.point(20, -20, 0, 0, 0);
  BezierDownZ.point(-70, -70, 0, 0, 0);
  BezierLeftY.point(20, 27, 34, 10, 0);
  BezierLeftZ.point(-70, -70, -70, -60, -60);
  BezierRightY.point(-20, -27, -34, -10, 0);
  BezierRightZ.point(-70, -70, -70, -60, -60);

  BezierDownY.getPosLin(ArrSample, &DownPathY[0]);
  BezierDownZ.getPosLin(ArrSample, &DownPathZ[0]);

  BezierLeftY.getPosCub(ArrSample, &LeftPathY[0]);
  BezierLeftZ.getPosQuad(ArrSample, &LeftPathZ[0]);

  BezierRightY.getPosO4(ArrSample, &RightPathY[0]);
  BezierRightZ.getPosO4(ArrSample, &RightPathZ[0]);

  for (short i = 0; i < ArrSample; i++)
  {
    Serial.print(DownPathY[i]);
    Serial.print(", ");
  }
  Serial.println("; ");
  for (short i = 0; i < ArrSample; i++)
  {
    Serial.print(DownPathZ[i]);
    Serial.print(", ");
  }
  Serial.println("; ");
  for (short i = 0; i < ArrSample; i++)
  {
    Serial.print(LeftPathY[i]);
    Serial.print(", ");
  }
  Serial.println("; ");
  for (short i = 0; i < ArrSample; i++)
  {
    Serial.print(LeftPathZ[i]);
    Serial.print(", ");
  }
  Serial.println("; ");
  for (short i = 0; i < ArrSample; i++)
  {
    Serial.print(RightPathY[i]);
    Serial.print(", ");
  }
  Serial.println("; ");
  for (short i = 0; i < ArrSample; i++)
  {
    Serial.print(RightPathZ[i]);
    Serial.print(", ");
  }
  Serial.println("; ");
}

void loop()
{
  // put your main code here, to run repeatedly:
}