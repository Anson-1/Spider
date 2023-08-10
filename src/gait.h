#ifndef GAIT_H
#define GAIT_H
#include "Leg.h"
Leg L1;
Leg L2;
Leg L3;
Leg L4;

bool step1 = false;
bool step2 = false;
bool step3 = false;
bool step4 = false;
bool step5 = false;
bool step6 = false;
bool step7 = false;
bool step8 = false;
bool step9 = false;
bool step10 = false;
bool step11 = false;
bool step12 = false;
bool step13 = false;
bool step14 = false;

void stand()
{
    L1.calculateIK(9, 9, 8);
    L1.update1();
    L2.calculateIK(9, 9, 8);
    L2.update2();
    L3.calculateIK(9, 9, 8);
    L3.update3();
    L4.calculateIK(9, 9, 8);
    L4.update4();
}

void Forward()
{
    unsigned long curr = millis();
    if (curr - prevtime > 10)
    {

        if (step1 == false)
        {
            L4.calculateIK(-4, sqrt(272), 20);
            L4.update4();
            if (L4.prev1 == int(L4.J1) && L4.prev2 == int(L4.J2) && L4.prev3 == int(L4.J3))
            {
                step1 = true;
            }
        }
        if (step1 == true && step2 == false)
        {
            L4.calculateIK(-4, sqrt(146), 8);
            L4.update4();
            if (L4.prev1 == int(L4.J1) && L4.prev2 == int(L4.J2) && L4.prev3 == int(L4.J3))
            {
                step2 = true;
            }
        }

        if (step1 == true && step2 == true && step3 == false)
        {
            L2.calculateIK(-4, sqrt(146), 8);
            L2.update2();
            if (L2.prev1 == int(L2.J1) && L2.prev2 == int(L2.J2) && L2.prev3 == int(L2.J3))
            {
                step3 = true;
            }
        }
        if (step1 == true && step2 == true && step3 == true && step4 == false)
        {
            L2.calculateIK(-4, sqrt(272), 20);
            L2.update2();
            if (L2.prev1 == int(L2.J1) && L2.prev2 == int(L2.J2) && L2.prev3 == int(L2.J3))
            {
                step4 = true;
            }
        }
        if (step1 == true && step2 == true && step3 == true && step4 == true && step5 == false)
        {
            L2.calculateIK(sqrt(252), 6, 20);
            L2.update2();
            if (L2.prev1 == int(L2.J1) && L2.prev2 == int(L2.J2) && L2.prev3 == int(L2.J3))
            {
                step5 = true;
            }
        }
        if (step1 == true && step2 == true && step3 == true && step4 == true && step5 == true && step6 == false)
        {
            L2.calculateIK(sqrt(252), 6, 8);
            L2.update2();
            if (L2.prev1 == int(L2.J1) && L2.prev2 == int(L2.J2) && L2.prev3 == int(L2.J3))
            {
                step6 = true;
            }
        }
        if (step1 == true && step2 == true && step3 == true && step4 == true && step5 == true && step6 == true && step7 == false)
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
                step7 = true;
            }
        }
        if (step1 == true && step2 == true && step3 == true && step4 == true && step5 == true && step6 == true && step7 == true && step8 == false)
        {
            L3.calculateIK(-4, sqrt(272), 20);
            L3.update3();
            if (L3.prev1 == int(L3.J1) && L3.prev2 == int(L3.J2) && L3.prev3 == int(L3.J3))
            {
                step8 = true;
            }
        }
        if (step1 == true && step2 == true && step3 == true && step4 == true && step5 == true && step6 == true && step7 == true && step8 == true && step9 == false)
        {
            L3.calculateIK(-4, sqrt(146), 8);
            L3.update3();
            if (L3.prev1 == int(L3.J1) && L3.prev2 == int(L3.J2) && L3.prev3 == int(L3.J3))
            {
                step9 = true;
            }
        }
        if (step1 == true && step2 == true && step3 == true && step4 == true && step5 == true && step6 == true && step7 == true && step8 == true && step9 == true && step10 == false)
        {
            L1.calculateIK(-4, sqrt(272), 20);
            L1.update1();
            if (L1.prev1 == int(L1.J1) && L1.prev2 == int(L1.J2) && L1.prev3 == int(L1.J3))
            {
                step10 = true;
            }
        }
        if (step1 == true && step2 == true && step3 == true && step4 == true && step5 == true && step6 == true && step7 == true && step8 == true && step9 == true && step10 == true && step11 == false)
        {
            L1.calculateIK(sqrt(252), 6, 20);
            L1.update1();
            if (L1.prev1 == int(L1.J1) && L1.prev2 == int(L1.J2) && L1.prev3 == int(L1.J3))
            {
                step11 = true;
            }
        }
        if (step1 == true && step2 == true && step3 == true && step4 == true && step5 == true && step6 == true && step7 == true && step8 == true && step9 == true && step10 == true && step11 == true && step12 == false)
        {
            L1.calculateIK(sqrt(252), 6, 8);
            L1.update1();
            if (L1.prev1 == int(L1.J1) && L1.prev2 == int(L1.J2) && L1.prev3 == int(L1.J3))
            {
                step12 = true;
            }
        }
        if (step1 == true && step2 == true && step3 == true && step4 == true && step5 == true && step6 == true && step7 == true && step8 == true && step9 == true && step10 == true && step11 == true && step12 == true && step13 == false)
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
                step13 = true;
            }
        }

        if (step1 == true && step2 == true && step3 == true && step4 == true && step5 == true && step6 == true && step7 == true && step8 == true && step9 == true && step10 == true && step11 == true && step12 == true && step13 == true)
        {
            step1 = false;
            step2 = false;
            step3 = false;
            step4 = false;
            step5 = false;
            step6 = false;
            step7 = false;
            step8 = false;
            step9 = false;
            step10 = false;
            step11 = false;
            step12 = false;
            step13 = false;
        }
        prevtime = curr;
    }
}
#endif