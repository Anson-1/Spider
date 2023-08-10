#ifndef LEG_H
#define LEG_H
#include <ESP32Servo.h>
#include <Math.h>
// Servos
Servo Front_Left1;
Servo Front_Left2;
Servo Front_Left3;

Servo Front_Right1;
Servo Front_Right2;
Servo Front_Right3;

Servo Back_Right1;
Servo Back_Right2;
Servo Back_Right3;

Servo Back_Left1;
Servo Back_Left2;
Servo Back_Left3;

// Constants
const double J1L = 4;
const double J2L = 8;
const double J3L = 13;
double J1;
double D;
double d;
double Z_offset;
double Alpha_1;
double Alpha_2;
double R;
double J2;
double J3;
unsigned long interval = 1;
unsigned long prevtime = 0;
unsigned long prevtime2 = 0;

float Ground = 13;

const double J3_LegAngle = 10;
unsigned long __angleTimeGap = 10;

double angle1 = 45;
double angle2 = 146;
double angle3 = 59;

class Leg
{
public:
  double prev1 = 45;
  double prev2 = 146;
  double prev3 = 59;
  double J1;
  double J2;
  double J3;
  Leg()
  {
  }
  void calculateIK(double X, double Y, double Z)
  {
    if (X > 0)
    {
      J1 = atan(Y / X) * (180 / PI);
      D = sqrt((Y * Y) + (X * X));
      d = D - J1L;
      Z_offset = Ground - Z;
      R = sqrt((d * d) + (Z_offset * Z_offset));
      Alpha_1 = acos(Z_offset / R) * (180 / PI);
      Alpha_2 = acos(((J2L * J2L) + (R * R) - (J3L * J3L)) / (2 * J2L * R)) * (180 / PI);
      J2 = (Alpha_1 + Alpha_2);
      J3 = acos(((J2L * J2L) + (J3L * J3L) - (R * R)) / (2 * J2L * J3L)) * (180 / PI);
    }
    else if (X == 0)
    {
      J1 = 90;
      D = sqrt((Y * Y) + (X * X));
      d = D - J1L;
      Z_offset = Ground - Z;
      R = sqrt((d * d) + (Z_offset * Z_offset));
      Alpha_1 = acos(Z_offset / R) * (180 / PI);
      Alpha_2 = acos(((J2L * J2L) + (R * R) - (J3L * J3L)) / (2 * J2L * R)) * (180 / PI);
      J2 = (Alpha_1 + Alpha_2);
      J3 = acos(((J2L * J2L) + (J3L * J3L) - (R * R)) / (2 * J2L * J3L)) * (180 / PI);
    }
    else if (X < 0)
    {
      J1 = 90 + (90 - abs((atan(Y / X)) * (180 / PI)));
      D = sqrt((Y * Y) + (X * X));
      d = D - J1L;
      Z_offset = Ground - Z;
      R = sqrt((d * d) + (Z_offset * Z_offset));
      Alpha_1 = acos(Z_offset / R) * (180 / PI);
      Alpha_2 = acos(((J2L * J2L) + (R * R) - (J3L * J3L)) / (2 * J2L * R)) * (180 / PI);
      J2 = (Alpha_1 + Alpha_2);
      J3 = acos(((J2L * J2L) + (J3L * J3L) - (R * R)) / (2 * J2L * J3L)) * (180 / PI);
    }
  }

  void update1()
  {
    if (prev1 < int(J1))
    {
      prev1++;
    }
    else if (prev1 > int(J1))
    {
      prev1--;
    }
    if (prev2 < int(J2))
    {
      prev2++;
    }
    else if (prev2 > int(J2))
    {
      prev2--;
    }
    if (prev3 < int(J3))
    {
      prev3++;
    }
    else if (prev3 > int(J3))
    {
      prev3--;
    }
    Front_Left3.write(180 - prev3);
    Front_Left2.write(prev2);
    Front_Left1.write(prev1);
  }

  void update2()
  {
    if (prev1 < int(J1))
    {
      prev1++;
    }
    else if (prev1 > int(J1))
    {
      prev1--;
    }
    if (prev2 < int(J2))
    {
      prev2++;
    }
    else if (prev2 > int(J2))
    {
      prev2--;
    }
    if (prev3 < int(J3))
    {
      prev3++;
    }
    else if (prev3 > int(J3))
    {
      prev3--;
    }
    Front_Right1.write(180 - prev1);
    Front_Right2.write(180 - prev2);
    Front_Right3.write(prev3);
  }
  void update3()
  {
    if (prev1 < int(J1))
    {
      prev1++;
    }
    else if (prev1 > int(J1))
    {
      prev1--;
    }
    if (prev2 < int(J2))
    {
      prev2++;
    }
    else if (prev2 > int(J2))
    {
      prev2--;
    }
    if (prev3 < int(J3))
    {
      prev3++;
    }
    else if (prev3 > int(J3))
    {
      prev3--;
    }
    Back_Left1.write(180 - prev1);
    Back_Left2.write(180 - prev2);
    Back_Left3.write(prev3);
  }
  void update4()
  {
    if (prev1 < int(J1))
    {
      prev1++;
    }
    else if (prev1 > int(J1))
    {
      prev1--;
    }
    if (prev2 < int(J2))
    {
      prev2++;
    }
    else if (prev2 > int(J2))
    {
      prev2--;
    }
    if (prev3 < int(J3))
    {
      prev3++;
    }
    else if (prev3 > int(J3))
    {
      prev3--;
    }
    Back_Right1.write(prev1);
    Back_Right2.write(prev2);
    Back_Right3.write(180 - prev3);
  }

private:
};
#endif


