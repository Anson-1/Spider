#ifndef GAIT_H
#define GAIT_H
#include "Leg.h"
Leg L1;
Leg L2;
Leg L3;
Leg L4;

bool For_step1 = false;
bool For_step2 = false;
bool For_step3 = false;
bool For_step4 = false;
bool For_step5 = false;
bool For_step6 = false;
bool For_step7 = false;
bool For_step8 = false;
bool For_step9 = false;
bool For_step10 = false;
bool For_step11 = false;
bool For_step12 = false;
bool Back_step1 = false;
bool Back_step2 = false;
bool Back_step3 = false;
bool Back_step4 = false;
bool Back_step5 = false;
bool Back_step6 = false;
bool Back_step7 = false;
bool Back_step8 = false;
bool Back_step9 = false;
bool Back_step10 = false;
bool Back_step11 = false;
bool Back_step12 = false;
bool Left_step1 = false;
bool Left_step2 = false;
bool Left_step3 = false;
bool Left_step4 = false;
bool Left_step5 = false;
bool Left_step6 = false;
bool Left_step7 = false;
bool Left_step8 = false;
bool Left_step9 = false;
bool Right_step1 = false;
bool Right_step2 = false;
bool Right_step3 = false;
bool Right_step4 = false;
bool Right_step5 = false;
bool Right_step6 = false;
bool Right_step7 = false;
bool Right_step8 = false;
bool Right_step9 = false;

void stand()
{
    L1.calculateIK(sqrt(252), 6, 20);
    L1.update1();
    L2.calculateIK(9, 9, 8);
    L2.update2();
    L3.calculateIK(sqrt(252), 6, 20);
    L3.update3();
    L4.calculateIK(9, 9, 8);
    L4.update4();
}

int i = 0;
void Forward(int x)
{
    unsigned long curr = millis();
    if (curr - prevtime > 5)
    {
        if (For_step1 == false)
        {
            L2.calculateIK(-4, sqrt(146), 8);
            L2.update2();
            if (L2.prev1 == int(L2.J1) && L2.prev2 == int(L2.J2) && L2.prev3 == int(L2.J3))
            {
                For_step1 = true;
            }
        }

        if (For_step1 == true && For_step2 == false)
        {
            L4.calculateIK(-4, sqrt(272), 20);
            L4.update4();
            if (L4.prev1 == int(L4.J1) && L4.prev2 == int(L4.J2) && L4.prev3 == int(L4.J3))
            {
                For_step2 = true;
            }
        }
        if (For_step1 == true && For_step2 == true && For_step3 == false)
        {
            L4.calculateIK(-4, sqrt(146), 8);
            L4.update4();
            if (L4.prev1 == int(L4.J1) && L4.prev2 == int(L4.J2) && L4.prev3 == int(L4.J3))
            {
                For_step3 = true;
            }
        }
        if (For_step1 == true && For_step2 == true && For_step3 == true && For_step4 == false)
        {
            L2.calculateIK(sqrt(252), 6, 20);
            L2.update2();
            if (L2.prev1 == int(L2.J1) && L2.prev2 == int(L2.J2) && L2.prev3 == int(L2.J3))
            {
                For_step4 = true;
            }
        }
        if (For_step1 == true && For_step2 == true && For_step3 == true && For_step4 == true && For_step5 == false)
        {
            L2.calculateIK(sqrt(252), 6, 8);
            L2.update2();
            if (L2.prev1 == int(L2.J1) && L2.prev2 == int(L2.J2) && L2.prev3 == int(L2.J3))
            {
                For_step5 = true;
            }
        }
        if (For_step1 == true && For_step2 == true && For_step3 == true && For_step4 == true && For_step5 == true && For_step6 == false)
        {
            L1.calculateIK(-4, sqrt(146), 8);
            L2.calculateIK(9, 9, 8);
            L3.calculateIK(sqrt(252), 6, 8);
            L4.calculateIK(9, 9, 8);
            L1.update1();
            L2.update2();
            L3.update3();
            L4.update4();
            if (L1.prev1 == int(L1.J1) && L1.prev2 == int(L1.J2) && L1.prev3 == int(L1.J3) && L2.prev1 == int(L2.J1) && L2.prev2 == int(L2.J2) && L2.prev3 == int(L2.J3) &&
                L3.prev1 == int(L3.J1) && L3.prev2 == int(L3.J2) && L3.prev3 == int(L3.J3) && L4.prev1 == int(L4.J1) && L4.prev2 == int(L4.J2) && L4.prev3 == int(L4.J3))
            {
                For_step6 = true;
            }
        }
        if (For_step1 == true && For_step2 == true && For_step3 == true && For_step4 == true && For_step5 == true && For_step6 == true && For_step7 == false)
        {
            L3.calculateIK(-4, sqrt(272), 20);
            L3.update3();
            if (L3.prev1 == int(L3.J1) && L3.prev2 == int(L3.J2) && L3.prev3 == int(L3.J3))
            {
                For_step7 = true;
            }
        }
        if (For_step1 == true && For_step2 == true && For_step3 == true && For_step4 == true && For_step5 == true && For_step6 == true && For_step7 == true && For_step8 == false)
        {
            L3.calculateIK(-4, sqrt(146), 8);
            L3.update3();
            if (L3.prev1 == int(L3.J1) && L3.prev2 == int(L3.J2) && L3.prev3 == int(L3.J3))
            {
                For_step8 = true;
            }
        }
        if (For_step1 == true && For_step2 == true && For_step3 == true && For_step4 == true && For_step5 == true && For_step6 == true && For_step7 == true && For_step8 == true && For_step9 == false)
        {
            L1.calculateIK(-4, sqrt(272), 20);
            L1.update1();
            if (L1.prev1 == int(L1.J1) && L1.prev2 == int(L1.J2) && L1.prev3 == int(L1.J3))
            {
                For_step9 = true;
            }
        }
        if (For_step1 == true && For_step2 == true && For_step3 == true && For_step4 == true && For_step5 == true && For_step6 == true && For_step7 == true && For_step8 == true && For_step9 == true && For_step10 == false)
        {
            L1.calculateIK(sqrt(252), 6, 20);
            L1.update1();
            if (L1.prev1 == int(L1.J1) && L1.prev2 == int(L1.J2) && L1.prev3 == int(L1.J3))
            {
                For_step10 = true;
            }
        }
        if (For_step1 == true && For_step2 == true && For_step3 == true && For_step4 == true && For_step5 == true && For_step6 == true && For_step7 == true && For_step8 == true && For_step9 == true && For_step10 == true && For_step11 == false)
        {
            L1.calculateIK(sqrt(252), 6, 8);
            L1.update1();
            if (L1.prev1 == int(L1.J1) && L1.prev2 == int(L1.J2) && L1.prev3 == int(L1.J3))
            {
                For_step11 = true;
            }
        }
        if (For_step1 == true && For_step2 == true && For_step3 == true && For_step4 == true && For_step5 == true && For_step6 == true && For_step7 == true && For_step8 == true && For_step9 == true && For_step10 == true && For_step11 == true && For_step12 == false)
        {
            L1.calculateIK(9, 9, 8);
            L2.calculateIK(-4, sqrt(146), 8);
            L3.calculateIK(9, 9, 8);
            L4.calculateIK(sqrt(252), 6, 8);
            L1.update1();
            L2.update2();
            L3.update3();
            L4.update4();
            if (L1.prev1 == int(L1.J1) && L1.prev2 == int(L1.J2) && L1.prev3 == int(L1.J3) && L2.prev1 == int(L2.J1) && L2.prev2 == int(L2.J2) && L2.prev3 == int(L2.J3) &&
                L3.prev1 == int(L3.J1) && L3.prev2 == int(L3.J2) && L3.prev3 == int(L3.J3) && L4.prev1 == int(L4.J1) && L4.prev2 == int(L4.J2) && L4.prev3 == int(L4.J3))
            {
                For_step12 = true;
                i++;
            }
        }

        if (For_step1 == true && For_step2 == true && For_step3 == true && For_step4 == true && For_step5 == true && For_step6 == true && For_step7 == true && For_step8 == true && For_step9 == true && For_step10 == true && For_step11 == true && For_step12 == true && i < x)
        {
            For_step1 = false;
            For_step2 = false;
            For_step3 = false;
            For_step4 = false;
            For_step5 = false;
            For_step6 = false;
            For_step7 = false;
            For_step8 = false;
            For_step9 = false;
            For_step10 = false;
            For_step11 = false;
            For_step12 = false;
        }
        prevtime = curr;
    }
}
int j = 0;
void Backward(int x)
{
    unsigned long curr = millis();
    if (curr - prevtime > 5)
    {
        if (Back_step1 == false)
        {
            L4.calculateIK(-4, sqrt(146), 8);
            L4.update4();
            if (L4.prev1 == int(L4.J1) && L4.prev2 == int(L4.J2) && L4.prev3 == int(L4.J3))
            {
                Back_step1 = true;
            }
        }

        if (Back_step1 == true && Back_step2 == false)
        {
            L2.calculateIK(-4, sqrt(272), 20);
            L2.update2();
            if (L2.prev1 == int(L2.J1) && L2.prev2 == int(L2.J2) && L2.prev3 == int(L2.J3))
            {
                Back_step2 = true;
            }
        }
        if (Back_step1 == true && Back_step2 == true && Back_step3 == false)
        {
            L2.calculateIK(-4, sqrt(146), 8);
            L2.update2();
            if (L2.prev1 == int(L2.J1) && L2.prev2 == int(L2.J2) && L2.prev3 == int(L2.J3))
            {
                Back_step3 = true;
            }
        }
        if (Back_step1 == true && Back_step2 == true && Back_step3 == true && Back_step4 == false)
        {
            L4.calculateIK(sqrt(252), 6, 20);
            L4.update4();
            if (L4.prev1 == int(L4.J1) && L4.prev2 == int(L4.J2) && L4.prev3 == int(L4.J3))
            {
                Back_step4 = true;
            }
        }
        if (Back_step1 == true && Back_step2 == true && Back_step3 == true && Back_step4 == true && Back_step5 == false)
        {
            L4.calculateIK(sqrt(252), 6, 8);
            L4.update4();
            if (L4.prev1 == int(L4.J1) && L4.prev2 == int(L4.J2) && L4.prev3 == int(L4.J3))
            {
                Back_step5 = true;
            }
        }
        if (Back_step1 == true && Back_step2 == true && Back_step3 == true && Back_step4 == true && Back_step5 == true && Back_step6 == false)
        {
            L3.calculateIK(-4, sqrt(146), 8);
            L4.calculateIK(9, 9, 8);
            L1.calculateIK(sqrt(252), 6, 8);
            L2.calculateIK(9, 9, 8);
            L1.update1();
            L2.update2();
            L3.update3();
            L4.update4();
            if (L1.prev1 == int(L1.J1) && L1.prev2 == int(L1.J2) && L1.prev3 == int(L1.J3) && L2.prev1 == int(L2.J1) && L2.prev2 == int(L2.J2) && L2.prev3 == int(L2.J3) &&
                L3.prev1 == int(L3.J1) && L3.prev2 == int(L3.J2) && L3.prev3 == int(L3.J3) && L4.prev1 == int(L4.J1) && L4.prev2 == int(L4.J2) && L4.prev3 == int(L4.J3))
            {
                Back_step6 = true;
            }
        }
        if (Back_step1 == true && Back_step2 == true && Back_step3 == true && Back_step4 == true && Back_step5 == true && Back_step6 == true && Back_step7 == false)
        {
            L1.calculateIK(-4, sqrt(272), 20);
            L1.update1();
            if (L1.prev1 == int(L1.J1) && L1.prev2 == int(L1.J2) && L1.prev3 == int(L1.J3))
            {
                Back_step7 = true;
            }
        }
        if (Back_step1 == true && Back_step2 == true && Back_step3 == true && Back_step4 == true && Back_step5 == true && Back_step6 == true && Back_step7 == true && Back_step8 == false)
        {
            L1.calculateIK(-4, sqrt(146), 8);
            L1.update1();
            if (L1.prev1 == int(L1.J1) && L1.prev2 == int(L1.J2) && L1.prev3 == int(L1.J3))
            {
                Back_step8 = true;
            }
        }
        if (Back_step1 == true && Back_step2 == true && Back_step3 == true && Back_step4 == true && Back_step5 == true && Back_step6 == true && Back_step7 == true && Back_step8 == true && Back_step9 == false)
        {
            L3.calculateIK(-4, sqrt(272), 20);
            L3.update3();
            if (L3.prev1 == int(L3.J1) && L3.prev2 == int(L3.J2) && L3.prev3 == int(L3.J3))
            {
                Back_step9 = true;
            }
        }
        if (Back_step1 == true && Back_step2 == true && Back_step3 == true && Back_step4 == true && Back_step5 == true && Back_step6 == true && Back_step7 == true && Back_step8 == true && Back_step9 == true && Back_step10 == false)
        {
            L3.calculateIK(sqrt(252), 6, 20);
            L3.update3();
            if (L3.prev1 == int(L3.J1) && L3.prev2 == int(L3.J2) && L3.prev3 == int(L3.J3))
            {
                Back_step10 = true;
            }
        }
        if (Back_step1 == true && Back_step2 == true && Back_step3 == true && Back_step4 == true && Back_step5 == true && Back_step6 == true && Back_step7 == true && Back_step8 == true && Back_step9 == true && Back_step10 == true && Back_step11 == false)
        {
            L3.calculateIK(sqrt(252), 6, 8);
            L3.update3();
            if (L3.prev1 == int(L3.J1) && L3.prev2 == int(L3.J2) && L3.prev3 == int(L3.J3))
            {
                Back_step11 = true;
            }
        }
        if (Back_step1 == true && Back_step2 == true && Back_step3 == true && Back_step4 == true && Back_step5 == true && Back_step6 == true && Back_step7 == true && Back_step8 == true && Back_step9 == true && Back_step10 == true && Back_step11 == true && Back_step12 == false)
        {
            L3.calculateIK(9, 9, 8);
            L4.calculateIK(-4, sqrt(146), 8);
            L1.calculateIK(9, 9, 8);
            L2.calculateIK(sqrt(252), 6, 8);
            L1.update1();
            L2.update2();
            L3.update3();
            L4.update4();
            if (L1.prev1 == int(L1.J1) && L1.prev2 == int(L1.J2) && L1.prev3 == int(L1.J3) && L2.prev1 == int(L2.J1) && L2.prev2 == int(L2.J2) && L2.prev3 == int(L2.J3) &&
                L3.prev1 == int(L3.J1) && L3.prev2 == int(L3.J2) && L3.prev3 == int(L3.J3) && L4.prev1 == int(L4.J1) && L4.prev2 == int(L4.J2) && L4.prev3 == int(L4.J3))
            {
                Back_step12 = true;
                j++;
            }
        }

        if (Back_step1 == true && Back_step2 == true && Back_step3 == true && Back_step4 == true && Back_step5 == true && Back_step6 == true && Back_step7 == true && Back_step8 == true && Back_step9 == true && Back_step10 == true && Back_step11 == true && Back_step12 == true && j < x)
        {
            Back_step1 = false;
            Back_step2 = false;
            Back_step3 = false;
            Back_step4 = false;
            Back_step5 = false;
            Back_step6 = false;
            Back_step7 = false;
            Back_step8 = false;
            Back_step9 = false;
            Back_step10 = false;
            Back_step11 = false;
            Back_step12 = false;
        }
        prevtime = curr;
    }
}


void TurnLeft()
{
    unsigned long curr = millis();
    if (curr - prevtime > 10)
    {
        if (Left_step1 == false)
        {
            L1.calculateIK(sqrt(153), 3, 8);
            L2.calculateIK(-4, sqrt(146), 8);
            L3.calculateIK(-4, sqrt(146), 8);
            L4.calculateIK(sqrt(153), 3, 8);
            L1.update1();
            L2.update2();
            L3.update3();
            L4.update4();
            if (L1.prev1 == int(L1.J1) && L1.prev2 == int(L1.J2) && L1.prev3 == int(L1.J3) && L2.prev1 == int(L2.J1) && L2.prev2 == int(L2.J2) && L2.prev3 == int(L2.J3) &&
                L3.prev1 == int(L3.J1) && L3.prev2 == int(L3.J2) && L3.prev3 == int(L3.J3) && L4.prev1 == int(L4.J1) && L4.prev2 == int(L4.J2) && L4.prev3 == int(L4.J3))
            {
                Left_step1 = true;
            }
        }

        if (Left_step1 == true && Left_step2 == false)
        {
            L1.calculateIK(12, 12, 20);
            L1.update1();
            if (L1.prev1 == int(L1.J1) && L1.prev2 == int(L1.J2) && L1.prev3 == int(L1.J3))
            {
                Left_step2 = true;
            }
        }
        if (Left_step1 == true && Left_step2 == true && Left_step3 == false)
        {
            L1.calculateIK(9, 9, 8);
            L1.update1();
            if (L1.prev1 == int(L1.J1) && L1.prev2 == int(L1.J2) && L1.prev3 == int(L1.J3))
            {
                Left_step3 = true;
            }
        }
        if (Left_step1 == true && Left_step2 == true && Left_step3 == true && Left_step4 == false)
        {
            L3.calculateIK(12, 12, 20);
            L3.update3();
            if (L3.prev1 == int(L3.J1) && L3.prev2 == int(L3.J2) && L3.prev3 == int(L3.J3))
            {
                Left_step4 = true;
            }
        }
        if (Left_step1 == true && Left_step2 == true && Left_step3 == true && Left_step4 == true && Left_step5 == false)
        {
            L3.calculateIK(9, 9, 8);
            L3.update3();
            if (L3.prev1 == int(L3.J1) && L3.prev2 == int(L3.J2) && L3.prev3 == int(L3.J3))
            {
                Left_step5 = true;
            }
        }
        if (Left_step1 == true && Left_step2 == true && Left_step3 == true && Left_step4 == true && Left_step5 == true && Left_step6 == false)
        {
            L4.calculateIK(12, 12, 20);
            L4.update4();
            if (L4.prev1 == int(L4.J1) && L4.prev2 == int(L4.J2) && L4.prev3 == int(L4.J3))
            {
                Left_step6 = true;
            }
        }
        if (Left_step1 == true && Left_step2 == true && Left_step3 == true && Left_step4 == true && Left_step5 == true && Left_step6 == true && Left_step7 == false)
        {
            L4.calculateIK(9, 9, 8);
            L4.update4();
            if (L4.prev1 == int(L4.J1) && L4.prev2 == int(L4.J2) && L4.prev3 == int(L4.J3))
            {
                Left_step7 = true;
            }
        }
        if (Left_step1 == true && Left_step2 == true && Left_step3 == true && Left_step4 == true && Left_step5 == true && Left_step6 == true && Left_step7 == true && Left_step8 == false)
        {
            L2.calculateIK(12, 12, 20);
            L2.update2();
            if (L2.prev1 == int(L2.J1) && L2.prev2 == int(L2.J2) && L2.prev3 == int(L2.J3))
            {
                Left_step8 = true;
            }
        }
        if (Left_step1 == true && Left_step2 == true && Left_step3 == true && Left_step4 == true && Left_step5 == true && Left_step6 == true && Left_step7 == true && Left_step8 == true && Left_step9 == false)
        {
            L2.calculateIK(9, 9, 8);
            L2.update2();
            if (L2.prev1 == int(L2.J1) && L2.prev2 == int(L2.J2) && L2.prev3 == int(L2.J3))
            {
                Left_step9 = true;
            }
        }
        if (Left_step1 == true && Left_step2 == true && Left_step3 == true && Left_step4 == true && Left_step5 == true && Left_step6 == true && Left_step7 == true && Left_step8 == true && Left_step9 == true)
        {
            Left_step1 = false;
            Left_step2 = false;
            Left_step3 = false;
            Left_step4 = false;
            Left_step5 = false;
            Left_step6 = false;
            Left_step7 = false;
            Left_step8 = false;
            Left_step9 = false;
        }
        prevtime = curr;
    }
}

void TurnRight(){
    unsigned long curr = millis();
    if (curr - prevtime > 10)
    {
        if (Right_step1 == false)
        {
            L3.calculateIK(sqrt(153), 3, 8);
            L4.calculateIK(-4, sqrt(146), 8);
            L1.calculateIK(-4, sqrt(146), 8);
            L2.calculateIK(sqrt(153), 3, 8);
            L1.update1();
            L2.update2();
            L3.update3();
            L4.update4();
            if (L1.prev1 == int(L1.J1) && L1.prev2 == int(L1.J2) && L1.prev3 == int(L1.J3) && L2.prev1 == int(L2.J1) && L2.prev2 == int(L2.J2) && L2.prev3 == int(L2.J3) &&
                L3.prev1 == int(L3.J1) && L3.prev2 == int(L3.J2) && L3.prev3 == int(L3.J3) && L4.prev1 == int(L4.J1) && L4.prev2 == int(L4.J2) && L4.prev3 == int(L4.J3))
            {
                Right_step1 = true;
            }
        }

        if (Right_step1 == true && Right_step2 == false)
        {
            L3.calculateIK(12, 12, 20);
            L3.update1();
            if (L3.prev1 == int(L3.J1) && L3.prev2 == int(L3.J2) && L3.prev3 == int(L3.J3))
            {
                Right_step2 = true;
            }
        }
        if (Right_step1 == true && Right_step2 == true && Right_step3 == false)
        {
            L3.calculateIK(9, 9, 8);
            L3.update1();
            if (L3.prev1 == int(L3.J1) && L3.prev2 == int(L3.J2) && L3.prev3 == int(L3.J3))
            {
                Right_step3 = true;
            }
        }
        if (Right_step1 == true && Right_step2 == true && Right_step3 == true && Right_step4 == false)
        {
            L1.calculateIK(12, 12, 20);
            L1.update3();
            if (L1.prev1 == int(L1.J1) && L1.prev2 == int(L1.J2) && L1.prev3 == int(L1.J3))
            {
                Right_step4 = true;
            }
        }
        if (Right_step1 == true && Right_step2 == true && Right_step3 == true && Right_step4 == true && Right_step5 == false)
        {
            L1.calculateIK(9, 9, 8);
            L1.update3();
            if (L1.prev1 == int(L1.J1) && L1.prev2 == int(L1.J2) && L1.prev3 == int(L1.J3))
            {
                Right_step5 = true;
            }
        }
        if (Right_step1 == true && Right_step2 == true && Right_step3 == true && Right_step4 == true && Right_step5 == true && Right_step6 == false)
        {
            L2.calculateIK(12, 12, 20);
            L2.update4();
            if (L2.prev1 == int(L2.J1) && L2.prev2 == int(L2.J2) && L2.prev3 == int(L2.J3))
            {
                Right_step6 = true;
            }
        }
        if (Right_step1 == true && Right_step2 == true && Right_step3 == true && Right_step4 == true && Right_step5 == true && Right_step6 == true && Right_step7 == false)
        {
            L2.calculateIK(9, 9, 8);
            L2.update4();
            if (L2.prev1 == int(L2.J1) && L2.prev2 == int(L2.J2) && L2.prev3 == int(L2.J3))
            {
                Right_step7 = true;
            }
        }
        if (Right_step1 == true && Right_step2 == true && Right_step3 == true && Right_step4 == true && Right_step5 == true && Right_step6 == true && Right_step7 == true && Right_step8 == false)
        {
            L4.calculateIK(12, 12, 20);
            L4.update2();
            if (L4.prev1 == int(L4.J1) && L4.prev2 == int(L4.J2) && L4.prev3 == int(L4.J3))
            {
                Right_step8 = true;
            }
        }
        if (Right_step1 == true && Right_step2 == true && Right_step3 == true && Right_step4 == true && Right_step5 == true && Right_step6 == true && Right_step7 == true && Right_step8 == true && Right_step9 == false)
        {
            L4.calculateIK(9, 9, 8);
            L4.update2();
            if (L4.prev1 == int(L4.J1) && L4.prev2 == int(L4.J2) && L4.prev3 == int(L4.J3))
            {
                Right_step9 = true;
            }
        }
        if (Right_step1 == true && Right_step2 == true && Right_step3 == true && Right_step4 == true && Right_step5 == true && Right_step6 == true && Right_step7 == true && Right_step8 == true && Right_step9 == true)
        {
            Right_step1 = false;
            Right_step2 = false;
            Right_step3 = false;
            Right_step4 = false;
            Right_step5 = false;
            Right_step6 = false;
            Right_step7 = false;
            Right_step8 = false;
            Right_step9 = false;
        }
        prevtime = curr;
    }
}

void resetF()
{
    i = 0;
    For_step1 = false;
    For_step2 = false;
    For_step3 = false;
    For_step4 = false;
    For_step5 = false;
    For_step6 = false;
    For_step7 = false;
    For_step8 = false;
    For_step9 = false;
    For_step10 = false;
    For_step11 = false;
    For_step12 = false;
}

void resetB()
{
    j = 0;
    Back_step1 = false;
    Back_step2 = false;
    Back_step3 = false;
    Back_step4 = false;
    Back_step5 = false;
    Back_step6 = false;
    Back_step7 = false;
    Back_step8 = false;
    Back_step9 = false;
    Back_step10 = false;
    Back_step11 = false;
    Back_step12 = false;
}
#endif