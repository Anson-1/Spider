#include <Ramp.h>
#include <Math.h>

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
unsigned long previousMillis = 0;

float Ground = 13;

const double J3_LegAngle = 10;


 
class Joint
{
private:
  int angle;
  unsigned long prevTime;
  Servo _Servo;
  uint8_t _Pin;

public:
  bool Inverted;

  Joint()
  {
    Inverted = false;
  }

  void Setup(uint8_t Pin, bool I)
  {
    _Pin = Pin;
    Inverted = I;
    _Servo.attach(_Pin);
    _Servo.write(angle = 90);
    prevTime = millis();
  }

  bool Update(int targetAngle, unsigned long __angleTimeGap = 10)
  {
    if (angle == targetAngle)
    {
      return true;
    }
    if (millis() - prevTime >= __angleTimeGap)
    {
      prevTime = millis();
      if (targetAngle < angle)
      {
        angle--;
        if (angle < 0)
        {
          angle = 0;
        }
      }
      else
      {
        angle++;
        if (angle > 180)
        {
          angle = 180;
        }
      }
      if (Inverted)
      {
        _Servo.write(180 - angle);
      }
      else
      {
        _Servo.write(angle);
      }
    }
    return false;
  }
};

class Leg
{
public:
  Leg()
  {
    doIK = true;
    _LegAngle = 0;
  }

  void Setup(double Angle = 0)
  {
    _LegAngle = Angle;
    doIK = true;
  }

  bool CartesianMove(double X, double Y, double Z, Joint *Joint1, Joint *Joint2, Joint *Joint3)
  {
    if (doIK)
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
      doIK = false;
    }
    bool l = true;
    if(!doIK){
      l &= Joint1->Update(J1);
      l &= Joint2->Update(J2);
      l &= Joint3->Update(J3);
      if(l){
        doIK = true;
      }
    }
    return l;
  }

private:
  double _LegAngle;
  bool doIK;
  double J1;
  double J2;
  double J3;
};

Leg L1;
Leg L2;
Leg L3;
Leg L4;

Joint L1J1;
Joint L1J2;
Joint L1J3;

Joint L2J1;
Joint L2J2;
Joint L2J3;

Joint L3J1;
Joint L3J2;
Joint L3J3;

Joint L4J1;
Joint L4J2;
Joint L4J3;

double AXAct = 0.0;
double AYAct = 0.0;
double AZAct = 0.0;

uint8_t commandStep = 0;




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
  Serial.println("J1");
  Serial.println(J1);
  Serial.println("D");
  Serial.println(D);
  Serial.println("d");
  Serial.println(d);
  Serial.println("Z_offset");
  Serial.println(Z_offset);
  Serial.println("R");
  Serial.println(R);
  Serial.println("Alpha_1");
  Serial.println(Alpha_1);
  Serial.println("Alpha_2");
  Serial.println(Alpha_2);
  Serial.println("J2");
  Serial.println(J2);
  Serial.println("J3");
  Serial.println(J3);
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

void stand()
{
  Move(1, 10, 10, 8);
  Move(2, 10, 10, 8);
  Move(3, 10, 10, 8);
  Move(4, 10, 10, 8);
}

void setup()
{
  Serial.begin(19200);
  L1J1.Setup(Front_L1, false);
  L1J2.Setup(Front_L2, false);
  L1J3.Setup(Front_L3, true);
  L2J1.Setup(Front_R1, true);
  L2J2.Setup(Front_R2, true);
  L2J3.Setup(Front_R3, false);
  L3J1.Setup(Back_L1, true);
  L3J2.Setup(Back_L2, true);
  L3J3.Setup(Back_L3, false);
  L4J1.Setup(Back_R1, false);
  L4J2.Setup(Back_R2, false);
  L4J3.Setup(Back_R3, true);

  // Stand
  bool l = false;
  while (!l)
  {
    l = true;
    l &= L1.CartesianMove(10, 10, 8, &L1J1, &L1J2, &L1J3);
    l &= L2.CartesianMove(10, 10, 8, &L2J1, &L2J2, &L2J3);
    l &= L3.CartesianMove(10, 10, 8, &L3J1, &L3J2, &L3J3);
    l &= L4.CartesianMove(10, 10, 8, &L4J1, &L4J2, &L4J3);
  }
  
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

void loop()
{
  // for(int i=0; i<2; i++){
  //   Forward();
  // }
  // for(int i=0; i<5; i++){
  //   TurnLeft();
  // }
  // for(int i=0; i<2; i++){
  //   Backward();
  // }
  // for(int i=0; i<5; i++){
  //   TurnRight();
  // }
//   Front_Left2.write(180);
//   Front_Right2.write(0);
}
