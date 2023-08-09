#include <Ramp.h>
#include <Math.h>
#include "ROSserial.hpp"

#ifdef ESP32
#include <ESP32Servo.h>
#define Back_L1 12
#define Back_L2 14
#define Back_L3 27

#define Front_L1 25
#define Front_L2 33
#define Front_L3 32

#define Front_R1 5
#define Front_R2 18
#define Front_R3 19

#define Back_R1 15
#define Back_R2 2
#define Back_R3 4

#endif

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
  unsigned long prevTime = 0;
  double angle1 = 45;
  double angle2 = 146;
  double angle3 = 59;
  Leg()
  {
  }
  void calculate(double X, double Y, double Z)
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

  void move()
  {
    unsigned long current = millis();
    if (current - prevTime >= __angleTimeGap)
    {
      prevTime = current;
      if (J3 < angle3)
      {
        this->angle3--;
      }
      else
      {
        this->angle3++;
      }
      if (J2 < angle2)
      {
        this->angle2--;
      }
      else
      {
        this->angle2++;
      }
      if (J1 < angle1)
      {
        this->angle1--;
      }
      else
      {
        this->angle1++;
      }
      Front_Left3.write(180 - angle3);
      Front_Left2.write(angle2);
      Front_Left1.write(angle1);
    }
  }

private:
  double J1;
  double J2;
  double J3;
};

Leg L1;
Leg L2;
Leg L3;
Leg L4;

void Move(int leg, double X, double Y, double Z)
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
  // Serial.println("J1");
  // Serial.println(J1);
  // Serial.println("D");
  // Serial.println(D);
  // Serial.println("d");
  // Serial.println(d);
  // Serial.println("Z_offset");
  // Serial.println(Z_offset);
  // Serial.println("R");
  // Serial.println(R);
  // Serial.println("Alpha_1");
  // Serial.println(Alpha_1);
  // Serial.println("Alpha_2");
  // Serial.println(Alpha_2);
  // Serial.println("J2");
  // Serial.println(J2);
  // Serial.println("J3");
  // Serial.println(J3);
  switch (leg)
  {
  case 1:
    if (!isnanf(J1))
    {
      Front_Left1.write(J1);
    }
    if (!isnanf(J2))
    {
      Front_Left2.write(J2);
    }
    if (!isnanf(J3))
    {
      Front_Left3.write(180 - J3);
    }
    break;
  case 2:
    if (!isnanf(J1))
    {
      Front_Right1.write(180 - J1);
    }
    if (!isnanf(J2))
    {
      Front_Right2.write(180 - J2);
    }
    if (!isnanf(J3))
    {
      Front_Right3.write(J3);
    }
    break;
  case 3:
    if (!isnanf(J1))
    {
      Back_Left1.write(180 - J1);
    }
    if (!isnanf(J2))
    {
      Back_Left2.write(180 - J2);
    }
    if (!isnanf(J3))
    {
      Back_Left3.write(J3);
    }
    break;
  case 4:
    if (!isnanf(J1))
    {
      Back_Right1.write(J1);
    }
    if (!isnanf(J2))
    {
      Back_Right2.write(J2);
    }
    if (!isnanf(J3))
    {
      Back_Right3.write(180 - J3);
    }
    break;
  default:
    break;
  }
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

double prev1 = 45;
double prev2 = 146;
double prev3 = 59;

void move(double J1, double J2, double J3, double &prevangle1, double &prevangle2, double &prevangle3)
{
  unsigned long current = millis();
  if (current - prevtime >= 10)
  {
    prevtime = current;
    if (J3 < prevangle3)
    {
      prevangle3--;
    }
    else
    {
      prevangle3++;
    }
    if (J2 < prevangle2)
    {
      prevangle2--;
    }
    else
    {
      prevangle2++;
    }
    if (J1 < prevangle1)
    {
      prevangle1--;
    }
    else
    {
      prevangle1++;
    }
    Front_Left3.write(180 - prevangle3);
    Front_Left2.write(prevangle2);
    Front_Left1.write(prevangle1);
  }
}

void stand()
{
  // calculateIK(10, 10, 8);
  // move(J1, J2, J3, prev1, prev2, prev3);
  Move(1, 10, 10, 8);
  Move(2, 10, 10, 8);
  Move(3, 10, 10, 8);
  Move(4, 10, 10, 8);
}

void setup()
{
  Serial.begin(19200);
  Front_Left1.attach(Front_L1);
  Front_Left2.attach(Front_L2);
  Front_Left3.attach(Front_L3);

  Front_Right1.attach(Front_R1);
  Front_Right2.attach(Front_R2);
  Front_Right3.attach(Front_R3);

  Back_Left1.attach(Back_L1);
  Back_Left2.attach(Back_L2);
  Back_Left3.attach(Back_L3);

  Back_Right1.attach(Back_R1);
  Back_Right2.attach(Back_R2);
  Back_Right3.attach(Back_R3);

  // Stand
  stand();

  delay(2000);
}

void Forward()
{

  // Step1
  for (int i = 0; i < 14; i++)
  {
    Move(2, 10 - i, 10, 14);
  }
  Move(2, -4, 10, 8);
  for (int i = 0; i < 14; i++)
  {
    Move(4, 10 - i, 10, 14);
  }
  Move(4, -4, 10, 8);
  // Step2
  for (int i = 0; i < 20; i++)
  {
    Move(2, -4 + i, 10, 14);
  }
  Move(2, 16, 10, 8);
  // Step3
  Move(1, -4, 10, 8);
  Move(2, 10, 10, 8);
  Move(3, 16, 10, 8);
  Move(4, 10, 10, 8);

  // Step4
  for (int i = 0; i < 20; i++)
  {
    Move(3, 16 - i, 10, 14);
  }
  Move(3, -4, 10, 8);
  // Step5
  for (int i = 0; i < 20; i++)
  {
    Move(1, -4 + i, 10, 14);
  }
  Move(1, 16, 10, 8);
  // Step 6
  Move(1, 10, 10, 8);
  Move(2, -4, 10, 8);
  Move(3, 10, 10, 8);
  Move(4, 16, 10, 8);
}

void Backward()
{

  // Step1
  for (int i = 0; i < 14; i++)
  {
    Move(2, 10 - i, 10, 14);
  }
  Move(2, -4, 10, 8);
  for (int i = 0; i < 14; i++)
  {
    Move(4, 10 - i, 10, 14);
  }
  Move(4, -4, 10, 8);
  // Step2
  for (int i = 0; i < 20; i++)
  {
    Move(4, -4 + i, 10, 14);
  }
  // Step3
  Move(1, 16, 10, 8);
  Move(2, 10, 10, 8);
  Move(3, -4, 10, 8);
  Move(4, 10, 10, 8);
  // Step4
  for (int i = 0; i < 20; i++)
  {
    Move(1, 16 - i, 10, 14);
  }
  Move(1, -4, 10, 8);
  // Step5
  for (int i = 0; i < 20; i++)
  {
    Move(3, -4 + i, 10, 14);
  }
  Move(3, 16, 10, 8);
  // Step 6
  Move(1, 10, 10, 8);
  Move(2, 16, 10, 8);
  Move(3, 10, 10, 8);
  Move(4, -4, 10, 8);
}

void TurnLeft()
{
  // Step1
  Move(1, 10, 0, 8);
  Move(2, 0, 10, 8);
  Move(3, 0, 10, 8);
  Move(4, 10, 0, 8);
  // Step2
  for (int i = 0; i < 16; i++)
  {
    if (i == 15)
    {
      Move(1, 0, 15, 13);
    }
    else
    {
      Move(1, sqrt(150 - sq(0 + i)), 0 + i, 13);
    }
  }
  Move(1, 0, 10, 8);
  // Step2
  for (int i = 0; i < 16; i++)
  {
    if (i == 15)
    {
      Move(3, 15, 0, 13);
    }
    else
    {
      Move(3, 0 + i, sqrt(100 - sq(0 + i)), 13);
    }
  }
  Move(3, 10, 0, 8);
  // Step3
  for (int i = 0; i < 16; i++)
  {
    if (i == 12)
    {
      Move(4, 0, 15, 13);
    }
    else
    {
      Move(4, sqrt(100 - sq(0 + i)), 0 + i, 13);
    }
  }
  Move(4, 0, 10, 8);
  // Step4
  for (int i = 0; i < 16; i++)
  {
    if (i == 12)
    {
      Move(2, 15, 0, 13);
    }
    else
    {
      Move(2, 0 + i, sqrt(100 - sq(0 + i)), 13);
    }
  }
  Move(2, 10, 0, 8);
}

void TurnRight()
{
  // Step1
  Move(1, 0, 10, 8);
  Move(2, 10, 0, 8);
  Move(3, 10, 0, 8);
  Move(4, 0, 10, 8);
  // Step2
  for (int i = 0; i < 16; i++)
  {
    if (i == 15)
    {
      Move(1, 15, 0, 13);
    }
    else
    {
      Move(1, 0 + i, sqrt(150 - sq(0 + i)), 13);
    }
  }
  Move(1, 10, 0, 8);
  // Step2
  for (int i = 0; i < 16; i++)
  {
    if (i == 15)
    {
      Move(3, 0, 15, 13);
    }
    else
    {
      Move(3, sqrt(100 - sq(0 + i)), 0 + i, 13);
    }
  }
  Move(3, 0, 10, 8);
  // Step3
  for (int i = 0; i < 16; i++)
  {
    if (i == 12)
    {
      Move(4, 15, 0, 13);
    }
    else
    {
      Move(4, 0 + i, sqrt(100 - sq(0 + i)), 13);
    }
  }
  Move(4, 10, 0, 8);
  // Step4
  for (int i = 0; i < 16; i++)
  {
    if (i == 12)
    {
      Move(2, 0, 15, 13);
    }
    else
    {
      Move(2, sqrt(100 - sq(0 + i)), 0 + i, 13);
    }
  }
  Move(2, 0, 10, 8);
}

const unsigned long event1 = 1000;
const unsigned long event2 = 5000;
int i = 0;
int j = 0;
void loop()
{
  unsigned long curr = millis();
 
  if(curr - prevtime > 100){
    if(i != 5){
      i = i+1;
      Move(1, 12, 12, 8+i);
    }else if(i==5){
      i = 0;
      if(j != 5){
        j++;
        Move(1, 12, 12, 13-i);
      }else if(j == 5){
        j = 0;
      }
    }
    prevtime = curr;
  }


}