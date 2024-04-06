#ifndef GAIT_H
#define GAIT_H
#include "Leg.h"
Leg L1;
Leg L2;
Leg L3;
Leg L4;

int standclimb_step = 0;
int climb_step = 0;
int turn_left = 0;
int turn_right = 0;
int back_step = 0;
int stand_walk = 0;
int execution_time = 5;
void stand()
{
    L1.calculateIK(9, 9, 11.3);
    L1.update1();
    L2.calculateIK(0, sqrt(162), 11.3);
    L2.update2();
    L3.calculateIK(9, 9, 11.3);
    L3.update3();
    L4.calculateIK(0, sqrt(162), 11.3);
    L4.update4();
    standclimb_step = 0;
}
void standwalk(){
    unsigned long curr = millis();
    if (curr - prevtime > 5)
    {
       if (stand_walk == 0)
        {
            L1.calculateIK(3, 8, 24);
            L2.calculateIK(0, 8, 24);
            L3.calculateIK(3, 8, 24);
            L4.calculateIK(0, 8, 24);
            L1.update1();
            L2.update2();
            L3.update3();
            L4.update4();
            if (L1.prev1 == int(L1.J1) && L1.prev2 == int(L1.J2) && L1.prev3 == int(L1.J3) && L2.prev1_r == int(L2.J1) && L2.prev2 == int(L2.J2) && L2.prev3 == int(L2.J3) &&
                L3.prev1 == int(L3.J1) && L3.prev2 == int(L3.J2) && L3.prev3 == int(L3.J3) && L4.prev1_r == int(L4.J1) && L4.prev2 == int(L4.J2) && L4.prev3 == int(L4.J3))
            {
                stand_walk++;
            }
        }
        if(stand_walk == 1){
            L4.calculateIK(0, 12, 13);
            L4.update4();
            if (L4.prev1_r == int(L4.J1) && L4.prev2 == int(L4.J2) && L4.prev3 == int(L4.J3))
            {
                stand_walk++;
            }
        }
        if(stand_walk == 2){
            L4.calculateIK(5, 8, 24);
            L4.update4();
            if (L4.prev1_r == int(L4.J1) && L4.prev2 == int(L4.J2) && L4.prev3 == int(L4.J3))
            {
                stand_walk++;
            }
        }
        if (stand_walk == 3)
        {
            L1.calculateIK(5, 8, 24);
            L2.calculateIK(3, 8, 24);
            L3.calculateIK(0, 8, 24);
            L4.calculateIK(3, 8, 24);
            L1.update1();
            L2.update2();
            L3.update3();
            L4.update4();
            if (L1.prev1 == int(L1.J1) && L1.prev2 == int(L1.J2) && L1.prev3 == int(L1.J3) && L2.prev1_r == int(L2.J1) && L2.prev2 == int(L2.J2) && L2.prev3 == int(L2.J3) &&
                L3.prev1 == int(L3.J1) && L3.prev2 == int(L3.J2) && L3.prev3 == int(L3.J3) && L4.prev1_r == int(L4.J1) && L4.prev2 == int(L4.J2) && L4.prev3 == int(L4.J3))
            {
                stand_walk++;
            }
        }
        if(stand_walk == 4){
            L1.calculateIK(5, 12, 13);
            L1.update1();
            if (L1.prev1 == int(L1.J1) && L1.prev2 == int(L1.J2) && L1.prev3 == int(L1.J3))
            {
                stand_walk++;
            }
        }
        if(stand_walk == 5){
            L1.calculateIK(0, 8, 24);
            L1.update1();
            if (L1.prev1 == int(L1.J1) && L1.prev2 == int(L1.J2) && L1.prev3 == int(L1.J3))
            {
                stand_walk++;
            }
        }
        if(stand_walk == 6){
            L3.calculateIK(0, 12, 13);
            L3.update3();
            if (L3.prev1 == int(L3.J1) && L3.prev2 == int(L3.J2) && L3.prev3 == int(L3.J3))
            {
                stand_walk++;
            }
        }
        if(stand_walk == 7){
            L3.calculateIK(5, 8, 24);
            L3.update3();
            if (L3.prev1 == int(L3.J1) && L3.prev2 == int(L3.J2) && L3.prev3 == int(L3.J3))
            {
                stand_walk++;
            }
        }
        if(stand_walk == 8){
            L1.calculateIK(3, 8, 24);
            L2.calculateIK(5, 8, 24);
            L3.calculateIK(3, 8, 24);
            L4.calculateIK(0, 8, 24);
            L1.update1();
            L2.update2();
            L3.update3();
            L4.update4();
            if (L1.prev1 == int(L1.J1) && L1.prev2 == int(L1.J2) && L1.prev3 == int(L1.J3) && L2.prev1_r == int(L2.J1) && L2.prev2 == int(L2.J2) && L2.prev3 == int(L2.J3) &&
                L3.prev1 == int(L3.J1) && L3.prev2 == int(L3.J2) && L3.prev3 == int(L3.J3) && L4.prev1_r == int(L4.J1) && L4.prev2 == int(L4.J2) && L4.prev3 == int(L4.J3))
            {
                stand_walk++;
            }
        }
        if(stand_walk == 9){
            stand_walk = 0;
        }

      
        
    prevtime = curr;
    }
}
void standclimb(){
    unsigned long curr = millis();
    if (curr - prevtime > 3)
    {
        if(standclimb_step == 0){
            L3.calculateIK(1.2, sqrt(162), 11.3);
            L3.update3();
            if (L3.prev1 == int(L3.J1) && L3.prev2 == int(L3.J2) && L3.prev3 == int(L3.J3))
            {
                standclimb_step++;
            }
        }
        if (standclimb_step == 1)
        {
            L1.calculateIK(1.2, sqrt(162), 11.3);
            L1.update1();
            if (L1.prev1 == int(L1.J1) && L1.prev2 == int(L1.J2) && L1.prev3 == int(L1.J3))
            {
                standclimb_step++;
            }
        }
        if (standclimb_step == 2)
        {
            L1.calculateIK(0.5, 2, 24);
            L2.calculateIK(0, 2, 24);
            L3.calculateIK(0.5, 2, 22.5);
            L4.calculateIK(0, 2, 22.5);
            L1.update1();
            L2.update2();
            L3.update3();
            L4.update4();
            if (L1.prev1 == int(L1.J1) && L1.prev2 == int(L1.J2) && L1.prev3 == int(L1.J3) && L2.prev1_r == int(L2.J1) && L2.prev2 == int(L2.J2) && L2.prev3 == int(L2.J3) &&
                L3.prev1 == int(L3.J1) && L3.prev2 == int(L3.J2) && L3.prev3 == int(L3.J3) && L4.prev1_r == int(L4.J1) && L4.prev2 == int(L4.J2) && L4.prev3 == int(L4.J3))
            {
                standclimb_step++;
            }
        }
        if(standclimb_step == 3){
            climb_step = 0;
        }
    prevtime = curr;
    }
}
void climb(){
    unsigned long curr = millis();
    if (curr - prevtime > execution_time)
    {
        if(climb_step == 0){
            L4.calculateIK(0, 15, 4);
            L4.update4();
            if (L4.prev1_r == int(L4.J1) && L4.prev2 == int(L4.J2) && L4.prev3 == int(L4.J3))
            {
                climb_step++;
            }
        }
        if(climb_step == 1){
            // L4.calculateIK(20, 15, 4);
            // L4.calculateIK(20, 15, 4);
            L4.update4();
            if (L4.prev1_r == int(L4.J1) && L4.prev2 == int(L4.J2) && L4.prev3 == int(L4.J3))
            {
                climb_step++;
            }
        }
         if(climb_step == 2){
            L4.calculateIK(20, 15, 6);
            // L4.calculateIK(20, 15, 10);
            L4.update4();
            if (L4.prev1_r == int(L4.J1) && L4.prev2 == int(L4.J2) && L4.prev3 == int(L4.J3))
            {
                climb_step++;
            }
        }
        if(climb_step == 3){
            L1.calculateIK(3.2, 2, 24);
            L2.calculateIK(2, 2, 24);
            L3.calculateIK(0, 2, 24);
            L4.calculateIK(10, 10, 6);
            // L4.calculateIK(12, 12, 10);
            L1.update1();
            L2.update2();
            L3.update3();
            L4.update4();
            if (L1.prev1 == int(L1.J1) && L1.prev2 == int(L1.J2) && L1.prev3 == int(L1.J3) && L2.prev1_r == int(L2.J1) && L2.prev2 == int(L2.J2) && L2.prev3 == int(L2.J3) &&
                L3.prev1 == int(L3.J1) && L3.prev2 == int(L3.J2) && L3.prev3 == int(L3.J3) && L4.prev1_r == int(L4.J1) && L4.prev2 == int(L4.J2) && L4.prev3 == int(L4.J3))
            {
                climb_step++;
            }
        }
        if(climb_step == 4){
            L1.calculateIK(3.2, 2, 14);
            L1.update1();
            if (L1.prev1 == int(L1.J1) && L1.prev2 == int(L1.J2) && L1.prev3 == int(L1.J3))
            {
                climb_step++;
            }
        }
        if(climb_step == 5){
            L1.calculateIK(0, 2, 24);
            L1.update1();
            if (L1.prev1 == int(L1.J1) && L1.prev2 == int(L1.J2) && L1.prev3 == int(L1.J3))
            {
                climb_step++;
            }
        }
        if(climb_step == 6){
            L3.calculateIK(0, 15, 4);
            L3.update3();
            if (L3.prev1 == int(L3.J1) && L3.prev2 == int(L3.J2) && L3.prev3 == int(L3.J3))
            {
                climb_step++;
            }
        }
        if(climb_step == 7){
            L3.calculateIK(18, 10, 6);
            L3.update3();
            if (L3.prev1 == int(L3.J1) && L3.prev2 == int(L3.J2) && L3.prev3 == int(L3.J3))
            {
                climb_step++;
            }
        }
        if(climb_step == 8){
            L3.calculateIK(12, 6, 10);
            L3.update3();
            if (L3.prev1 == int(L3.J1) && L3.prev2 == int(L3.J2) && L3.prev3 == int(L3.J3))
            {
                climb_step++;
            }
        }
        if(climb_step == 9){
            L1.calculateIK(2, 2, 24);
            L2.calculateIK(4, 2, 24);
            L3.calculateIK(8, 8, 10);
            L4.calculateIK(5, 15, 10);
            L1.update1();
            L2.update2();
            L3.update3();
            L4.update4();
            if (L1.prev1 == int(L1.J1) && L1.prev2 == int(L1.J2) && L1.prev3 == int(L1.J3) && L2.prev1_r == int(L2.J1) && L2.prev2 == int(L2.J2) && L2.prev3 == int(L2.J3) &&
                L3.prev1 == int(L3.J1) && L3.prev2 == int(L3.J2) && L3.prev3 == int(L3.J3) && L4.prev1_r == int(L4.J1) && L4.prev2 == int(L4.J2) && L4.prev3 == int(L4.J3))
            {
                climb_step++;
            }
        }
        if(climb_step == 10){
            L2.calculateIK(0, 2, 24);
            L2.update2();
            if (L2.prev1_r == int(L2.J1) && L2.prev2 == int(L2.J2) && L2.prev3 == int(L2.J3))
            {
                climb_step++;
            }
        }
        if(climb_step == 11){
            L4.calculateIK(18, 10, 2);
            L4.update4();
            if (L4.prev1_r == int(L4.J1) && L4.prev2 == int(L4.J2) && L4.prev3 == int(L4.J3))
            {
                climb_step++;
            }
        }
        if(climb_step == 12){
            // L4.calculateIK(18, 10, 8);
            L4.calculateIK(18, 10, 10);
            L4.update4();
            if (L4.prev1_r == int(L4.J1) && L4.prev2 == int(L4.J2) && L4.prev3 == int(L4.J3))
            {
                climb_step++;
            }
        }
        if(climb_step == 13){
            L1.calculateIK(3.2, 2, 24);
            L2.calculateIK(2, 2, 24);
            L3.calculateIK(0, 15, 10);
            // L4.calculateIK(10, 10, 8);
            L4.calculateIK(10, 10, 10);
            L1.update1();
            L2.update2();
            L3.update3();
            L4.update4();
            if (L1.prev1 == int(L1.J1) && L1.prev2 == int(L1.J2) && L1.prev3 == int(L1.J3) && L2.prev1_r == int(L2.J1) && L2.prev2 == int(L2.J2) && L2.prev3 == int(L2.J3) &&
                L3.prev1 == int(L3.J1) && L3.prev2 == int(L3.J2) && L3.prev3 == int(L3.J3) && L4.prev1_r == int(L4.J1) && L4.prev2 == int(L4.J2) && L4.prev3 == int(L4.J3))
            {
                climb_step++;
            }
        }
        if(climb_step == 14){
            L1.calculateIK(3.2, 2, 15);
            L1.update1();
            if (L1.prev1 == int(L1.J1) && L1.prev2 == int(L1.J2) && L1.prev3 == int(L1.J3))
            {
                climb_step++;
            }
        }
        if(climb_step == 15){
            L1.calculateIK(0, 2, 24);
            L1.update1();
            if (L1.prev1 == int(L1.J1) && L1.prev2 == int(L1.J2) && L1.prev3 == int(L1.J3))
            {
                climb_step++;
            }
        }
        if(climb_step == 16)
        {
            L3.calculateIK(0, 15, 4);
            L3.update3();
            if (L3.prev1 == int(L3.J1) && L3.prev2 == int(L3.J2) && L3.prev3 == int(L3.J3))
            {
                climb_step++;
            }
        }
        if(climb_step == 17)
        {

            L3.calculateIK(12, 8, 10);
            L3.update3();
            if (L3.prev1 == int(L3.J1) && L3.prev2 == int(L3.J2) && L3.prev3 == int(L3.J3))
            {
               climb_step++;
            }
        }
        if(climb_step == 18)
        {
            L1.calculateIK(2, 0, 24);
            L2.calculateIK(2, 0, 24);
            L3.calculateIK(0, 8, 10);
            L4.calculateIK(-2, 8, 10);
            L1.update1();
            L2.update2();
            L3.update3();
            L4.update4();
            if (L1.prev1 == int(L1.J1) && L1.prev2 == int(L1.J2) && L1.prev3 == int(L1.J3) && L2.prev1_r == int(L2.J1) && L2.prev2 == int(L2.J2) && L2.prev3 == int(L2.J3) &&
                L3.prev1 == int(L3.J1) && L3.prev2 == int(L3.J2) && L3.prev3 == int(L3.J3) && L4.prev1_r == int(L4.J1) && L4.prev2 == int(L4.J2) && L4.prev3 == int(L4.J3))
            {
                climb_step++;
                execution_time = 10;
            }

            
        }
        if(climb_step == 19)
        {
            L1.calculateIK(10, 0, 15);
            L2.calculateIK(10, 0, 15);
            L3.calculateIK(0, 18, -2);
            L4.calculateIK(0, 18, -2);
            L1.update1();
            L2.update2();
            L3.update3();
            L4.update4();
            if (L1.prev1 == int(L1.J1) && L1.prev2 == int(L1.J2) && L1.prev3 == int(L1.J3) && L2.prev1_r == int(L2.J1) && L2.prev2 == int(L2.J2) && L2.prev3 == int(L2.J3) &&
                L3.prev1 == int(L3.J1) && L3.prev2 == int(L3.J2) && L3.prev3 == int(L3.J3) && L4.prev1_r == int(L4.J1) && L4.prev2 == int(L4.J2) && L4.prev3 == int(L4.J3))
            {
                climb_step++;
                execution_time = 5;
            }

        }
        if(climb_step == 20)
        {
            // L1.calculateIK(20, 0, 0);
            L1.calculateIK(18, 0, -4);
            L1.update1();
            if (L1.prev1 == int(L1.J1) && L1.prev2 == int(L1.J2) && L1.prev3 == int(L1.J3))
            {
                climb_step++;
            }
        }
        if(climb_step == 21)
        {
            // L1.calculateIK(0, 15, 0);
            L1.calculateIK(0, 18, -4);
            L1.update1();
            if (L1.prev1 == int(L1.J1) && L1.prev2 == int(L1.J2) && L1.prev3 == int(L1.J3))
            {
                climb_step++;
            }
        }
        if(climb_step == 22)
        {
            // L2.calculateIK(20, 0, 0);
            L2.calculateIK(18, 0, -4);
            L2.update2();
            if (L2.prev1_r == int(L2.J1) && L2.prev2 == int(L2.J2) && L2.prev3 == int(L2.J3))
            {
                climb_step++;
            }
        }
        if(climb_step == 23)
        {
            // L2.calculateIK(0, 15, 0);
            L2.calculateIK(0, 18, -4);
            L2.update2();
            if (L2.prev1_r == int(L2.J1) && L2.prev2 == int(L2.J2) && L2.prev3 == int(L2.J3))
            {
                climb_step++;
            }
        }
        if(climb_step == 24){
            L1.calculateIK(2, 8, 12);
            L1.update1();
            L2.calculateIK(0, 8, 12);
            L2.update2();
            L3.calculateIK(0, 8, 11);
            L3.update3();
            L4.calculateIK(0, 8, 11);
            L4.update4();
            if (L1.prev1 == int(L1.J1) && L1.prev2 == int(L1.J2) && L1.prev3 == int(L1.J3) && L2.prev1_r == int(L2.J1) && L2.prev2 == int(L2.J2) && L2.prev3 == int(L2.J3) &&
                L3.prev1 == int(L3.J1) && L3.prev2 == int(L3.J2) && L3.prev3 == int(L3.J3) && L4.prev1_r == int(L4.J1) && L4.prev2 == int(L4.J2) && L4.prev3 == int(L4.J3))
            {
                climb_step++;
            }
        }
        if(climb_step == 25)
        {
            standclimb_step = 0;
        }


    prevtime = curr;
    }
}

int j = 0;
void Backward(int x)
{
    unsigned long curr = millis();
    if (curr - prevtime > 2)
    {
        if (back_step == 0)
        {
            L4.calculateIK(0, sqrt(162), 11.3);
            L4.update4();
            if (L4.prev1_r == int(L4.J1) && L4.prev2 == int(L4.J2) && L4.prev3 == int(L4.J3))
            {
                back_step++;
            }
        }

        if (back_step == 1)
        {
            L4.calculateIK(0, sqrt(162), 6);
            L4.update4();
            if (L4.prev1_r == int(L4.J1) && L4.prev2 == int(L4.J2) && L4.prev3 == int(L4.J3))
            {
                back_step++;
            }
        }
        if (back_step == 2)
        {
            L4.calculateIK(18, 9, 6);
            L4.update4(); 
            if (L4.prev1_r == int(L4.J1) && L4.prev2 == int(L4.J2) && L4.prev3 == int(L4.J3))
            {
                back_step++;
            }
        }
        if (back_step == 3)
        {
            L4.calculateIK(18, 9, 11.3);
            L4.update4();
            if (L4.prev1_r == int(L4.J1) && L4.prev2 == int(L4.J2) && L4.prev3 == int(L4.J3))
            {
                back_step++;
            }
        }
        if (back_step == 4)
        {
            L3.calculateIK(0, sqrt(162), 11.3);
            L4.calculateIK(9, 9, 11.3);
            L1.calculateIK(18, 9, 11.3);
            L2.calculateIK(9, 9, 11.3);
            L1.update1();
            L2.update2();
            L3.update3();
            L4.update4();
            if (L1.prev1 == int(L1.J1) && L1.prev2 == int(L1.J2) && L1.prev3 == int(L1.J3) && L2.prev1_r == int(L2.J1) && L2.prev2 == int(L2.J2) && L2.prev3 == int(L2.J3) &&
                L3.prev1 == int(L3.J1) && L3.prev2 == int(L3.J2) && L3.prev3 == int(L3.J3) && L4.prev1_r == int(L4.J1) && L4.prev2 == int(L4.J2) && L4.prev3 == int(L4.J3))
            {
                back_step++;
            }
        }
        if (back_step == 5)
        {
            L1.calculateIK(18, 9, 6);
            L1.update1();
            if (L1.prev1 == int(L1.J1) && L1.prev2 == int(L1.J2) && L1.prev3 == int(L1.J3))
            {
                back_step++;
            }
        }
        if (back_step == 6)
        {
            L1.calculateIK(0, sqrt(162), 6);
            L1.update1();
            if (L1.prev1 == int(L1.J1) && L1.prev2 == int(L1.J2) && L1.prev3 == int(L1.J3))
            {
               back_step++;
            }
        }
        if (back_step == 7)
        {
            L1.calculateIK(0, sqrt(162), 11.3);
            L1.update1();
            if (L1.prev1 == int(L1.J1) && L1.prev2 == int(L1.J2) && L1.prev3 == int(L1.J3))
            {
                back_step++;
            }
        }
        if (back_step == 8)
        {
            L3.calculateIK(0, sqrt(162), 6); 
            L3.update3();
            if (L3.prev1 == int(L3.J1) && L3.prev2 == int(L3.J2) && L3.prev3 == int(L3.J3))
            {
                back_step++;
            }
        }
        if (back_step == 9)
        {
            L3.calculateIK(18, 9, 6); 
            L3.update3();
            if (L3.prev1 == int(L3.J1) && L3.prev2 == int(L3.J2) && L3.prev3 == int(L3.J3))
            {
                back_step++;
            }
        }
        if (back_step == 10)
        {
            L3.calculateIK(18, 9, 11.3);
            L3.update3();
            if (L3.prev1 == int(L3.J1) && L3.prev2 == int(L3.J2) && L3.prev3 == int(L3.J3))
            {
                back_step++;
            }
        }
        if (back_step == 11)
        {
            L3.calculateIK(9, 9, 11.3);
            L4.calculateIK(0, sqrt(162), 11.3);
            L1.calculateIK(9, 9, 11.3);
            L2.calculateIK(18, 9, 11.3);
            L1.update1();
            L2.update2();
            L3.update3();
            L4.update4();
            if (L1.prev1 == int(L1.J1) && L1.prev2 == int(L1.J2) && L1.prev3 == int(L1.J3) && L2.prev1_r == int(L2.J1) && L2.prev2 == int(L2.J2) && L2.prev3 == int(L2.J3) &&
                L3.prev1 == int(L3.J1) && L3.prev2 == int(L3.J2) && L3.prev3 == int(L3.J3) && L4.prev1_r == int(L4.J1) && L4.prev2 == int(L4.J2) && L4.prev3 == int(L4.J3))
            {
                back_step++;
            }
        }
        if (back_step == 12)
        {
            L2.calculateIK(18, 9, 6);
            L2.update2();
            if (L2.prev1_r == int(L2.J1) && L2.prev2 == int(L2.J2) && L2.prev3 == int(L2.J3))
            {
                back_step++;
            }
        }
        if (back_step == 13)
        {
            L2.calculateIK(0, sqrt(162), 6);
            L2.update2();
            if (L2.prev1_r == int(L2.J1) && L2.prev2 == int(L2.J2) && L2.prev3 == int(L2.J3))
            {
                back_step++;
            }
        }
        if (back_step == 14)
        {
            L2.calculateIK(0, sqrt(162), 11.3);
            L2.update2();
            if (L2.prev1_r == int(L2.J1) && L2.prev2 == int(L2.J2) && L2.prev3 == int(L2.J3))
            {
                back_step++;
                j++;
            }
        }
        if (back_step == 15 && j < x)
        {
            back_step = 0;
        }
        prevtime = curr;
    }
}

void TurnLeft(){
    unsigned long curr = millis();
    if (curr - prevtime > 1)
    {
        if (turn_left == 0)
        {
            L3.calculateIK(6, sqrt(126), 11.3);
            L4.calculateIK(6, sqrt(126), 11.3);
            L1.calculateIK(sqrt(126), 6, 11.3);
            L2.calculateIK(0, sqrt(162), 6);
            L1.update1();
            L2.update2();
            L3.update3();
            L4.update4();
            if (L1.prev1 == int(L1.J1) && L1.prev2 == int(L1.J2) && L1.prev3 == int(L1.J3) && L2.prev1_r == int(L2.J1) && L2.prev2 == int(L2.J2) && L2.prev3 == int(L2.J3) &&
                L3.prev1 == int(L3.J1) && L3.prev2 == int(L3.J2) && L3.prev3 == int(L3.J3) && L4.prev1_r == int(L4.J1) && L4.prev2 == int(L4.J2) && L4.prev3 == int(L4.J3))
            {
                turn_left++;
            }
        }

        if (turn_left == 1)
        {
            L2.calculateIK(sqrt(126), 6, 6);
            L2.update2();
            if (L2.prev1_r == int(L2.J1) && L2.prev2 == int(L2.J2) && L2.prev3 == int(L2.J3))
            {
                turn_left++;
            }
        }
        if (turn_left == 2)
        {
            L2.calculateIK(sqrt(126), 6, 11.3);
            L2.update2();
            if (L2.prev1_r == int(L2.J1) && L2.prev2 == int(L2.J2) && L2.prev3 == int(L2.J3))
            {
                turn_left++;
            }
        }
        if (turn_left == 3)
        {
            L3.calculateIK(0, sqrt(162), 11.3);
            L4.calculateIK(9, 9, 11.3);
            L1.calculateIK(sqrt(126), 6, 6);
            L2.calculateIK(9, 9, 11.3);
            L1.update1();
            L2.update2();
            L3.update3();
            L4.update4();
            if (L1.prev1 == int(L1.J1) && L1.prev2 == int(L1.J2) && L1.prev3 == int(L1.J3) && L2.prev1_r == int(L2.J1) && L2.prev2 == int(L2.J2) && L2.prev3 == int(L2.J3) &&
                L3.prev1 == int(L3.J1) && L3.prev2 == int(L3.J2) && L3.prev3 == int(L3.J3) && L4.prev1_r == int(L4.J1) && L4.prev2 == int(L4.J2) && L4.prev3 == int(L4.J3))
            {
                turn_left++;
            }
        }
        if (turn_left == 4)
        {
            L1.calculateIK(0, sqrt(162), 6);
            L1.update1();
            if (L1.prev1 == int(L1.J1) && L1.prev2 == int(L1.J2) && L1.prev3 == int(L1.J3))
            {
                turn_left++;
            }
        }
        if (turn_left == 5)
        {
            L1.calculateIK(0, sqrt(162), 11.3);
            L1.update1();
            if (L1.prev1 == int(L1.J1) && L1.prev2 == int(L1.J2) && L1.prev3 == int(L1.J3))
            {
                turn_left++;
            }
        }
        if (turn_left == 6)
        {
            L3.calculateIK(0, sqrt(162), 6);
            L4.calculateIK(sqrt(126), 6, 11.3);
            L1.calculateIK(6, sqrt(126), 11.3);
            L2.calculateIK(6, sqrt(126), 11.3);
            L1.update1();
            L2.update2();
            L3.update3();
            L4.update4();
            if (L1.prev1 == int(L1.J1) && L1.prev2 == int(L1.J2) && L1.prev3 == int(L1.J3) && L2.prev1_r == int(L2.J1) && L2.prev2 == int(L2.J2) && L2.prev3 == int(L2.J3) &&
                L3.prev1 == int(L3.J1) && L3.prev2 == int(L3.J2) && L3.prev3 == int(L3.J3) && L4.prev1_r == int(L4.J1) && L4.prev2 == int(L4.J2) && L4.prev3 == int(L4.J3))
            {
                turn_left++;
            }
        }
        if (turn_left == 7)
        {
            L3.calculateIK(sqrt(126), 6, 6);
            L3.update3();
            if (L3.prev1 == int(L3.J1) && L3.prev2 == int(L3.J2) && L3.prev3 == int(L3.J3))
            {
                turn_left++;
            }
        }
        if (turn_left == 8)
        {
            L3.calculateIK(sqrt(126), 6, 11.3);
            L3.update3();
            if (L3.prev1 == int(L3.J1) && L3.prev2 == int(L3.J2) && L3.prev3 == int(L3.J3))
            {
                turn_left++;
            }
        }
        if (turn_left == 9)
        {
            L3.calculateIK(9, 9, 11.3);
            L4.calculateIK(sqrt(126), 6, 6);
            L1.calculateIK(9, 9, 11.3);
            L2.calculateIK(0, sqrt(162), 11.3);
            L1.update1();
            L2.update2();
            L3.update3();
            L4.update4();
            if (L1.prev1 == int(L1.J1) && L1.prev2 == int(L1.J2) && L1.prev3 == int(L1.J3) && L2.prev1_r == int(L2.J1) && L2.prev2 == int(L2.J2) && L2.prev3 == int(L2.J3) &&
                L3.prev1 == int(L3.J1) && L3.prev2 == int(L3.J2) && L3.prev3 == int(L3.J3) && L4.prev1_r == int(L4.J1) && L4.prev2 == int(L4.J2) && L4.prev3 == int(L4.J3))
            {
                turn_left++;
            }
        }
        if (turn_left == 10)
        {
            L4.calculateIK(0, sqrt(162), 6);
            L4.update4();
            if (L4.prev1_r == int(L4.J1) && L4.prev2 == int(L4.J2) && L4.prev3 == int(L4.J3))
            {
                turn_left++;
            }
        }
        if (turn_left == 11)
        {
            L4.calculateIK(0, sqrt(162), 11.3);
            L4.update4();
            if (L4.prev1_r == int(L4.J1) && L4.prev2 == int(L4.J2) && L4.prev3 == int(L4.J3))
            {
                turn_left++;
            }
        }
        if (turn_left == 12)
        {
            turn_left = 0;
        }
        prevtime = curr;
    }

}
void TurnRight(){
    unsigned long curr = millis();
    if (curr - prevtime > 1)
    {
        if (turn_right == 0)
        {
            L1.calculateIK(6, sqrt(126), 11.3);
            L2.calculateIK(6, sqrt(126), 11.3);
            L3.calculateIK(sqrt(126), 6, 11.3);
            L4.calculateIK(0, sqrt(162), 6);
            L1.update1();
            L2.update2();
            L3.update3();
            L4.update4();
            if (L1.prev1 == int(L1.J1) && L1.prev2 == int(L1.J2) && L1.prev3 == int(L1.J3) && L2.prev1_r == int(L2.J1) && L2.prev2 == int(L2.J2) && L2.prev3 == int(L2.J3) &&
                L3.prev1 == int(L3.J1) && L3.prev2 == int(L3.J2) && L3.prev3 == int(L3.J3) && L4.prev1_r == int(L4.J1) && L4.prev2 == int(L4.J2) && L4.prev3 == int(L4.J3))
            {
                turn_right++;
            }
        }

        if (turn_right == 1)
        {
            L4.calculateIK(sqrt(126), 6, 6);
            L4.update4();
            if (L4.prev1_r == int(L4.J1) && L4.prev2 == int(L4.J2) && L4.prev3 == int(L4.J3))
            {
                turn_right++;
            }
        }
        if (turn_right == 2)
        {
            L4.calculateIK(sqrt(126), 6, 11.3);
            L4.update4();
            if (L4.prev1_r == int(L4.J1) && L4.prev2 == int(L4.J2) && L4.prev3 == int(L4.J3))
            {
                turn_right++;
            }
        }
        if (turn_right == 3)
        {
            L1.calculateIK(0, sqrt(162), 11.3);
            L2.calculateIK(9, 9, 11.3);
            L3.calculateIK(sqrt(126), 6, 6);
            L4.calculateIK(9, 9, 11.3);
            L1.update1();
            L2.update2();
            L3.update3();
            L4.update4();
            if (L1.prev1 == int(L1.J1) && L1.prev2 == int(L1.J2) && L1.prev3 == int(L1.J3) && L2.prev1_r == int(L2.J1) && L2.prev2 == int(L2.J2) && L2.prev3 == int(L2.J3) &&
                L3.prev1 == int(L3.J1) && L3.prev2 == int(L3.J2) && L3.prev3 == int(L3.J3) && L4.prev1_r == int(L4.J1) && L4.prev2 == int(L4.J2) && L4.prev3 == int(L4.J3))
            {
                turn_right++;
            }
        }
        if (turn_right == 4)
        {
            L3.calculateIK(0, sqrt(162), 6);
            L3.update3();
            if (L3.prev1 == int(L3.J1) && L3.prev2 == int(L3.J2) && L3.prev3 == int(L3.J3))
            {
                turn_right++;
            }
        }
        if (turn_right == 5)
        {
            L3.calculateIK(0, sqrt(162), 11.3);
            L3.update3();
            if (L3.prev1 == int(L3.J1) && L3.prev2 == int(L3.J2) && L3.prev3 == int(L3.J3))
            {
                turn_right++;
            }
        }
        if (turn_right == 6)
        {
            L1.calculateIK(0, sqrt(162), 6);
            L2.calculateIK(sqrt(126), 6, 11.3);
            L3.calculateIK(6, sqrt(126), 11.3);
            L4.calculateIK(6, sqrt(126), 11.3);
            L1.update1();
            L2.update2();
            L3.update3();
            L4.update4();
            if (L1.prev1 == int(L1.J1) && L1.prev2 == int(L1.J2) && L1.prev3 == int(L1.J3) && L2.prev1_r == int(L2.J1) && L2.prev2 == int(L2.J2) && L2.prev3 == int(L2.J3) &&
                L3.prev1 == int(L3.J1) && L3.prev2 == int(L3.J2) && L3.prev3 == int(L3.J3) && L4.prev1_r == int(L4.J1) && L4.prev2 == int(L4.J2) && L4.prev3 == int(L4.J3))
            {
                turn_right++;
            }
        }
        if (turn_right == 7)
        {
            L1.calculateIK(sqrt(126), 6, 6);
            L1.update1();
            if (L1.prev1 == int(L1.J1) && L1.prev2 == int(L1.J2) && L1.prev3 == int(L1.J3))
            {
                turn_right++;
            }
        }
        if (turn_right == 8)
        {
            L1.calculateIK(sqrt(126), 6, 11.3);
            L1.update1();
            if (L1.prev1 == int(L1.J1) && L1.prev2 == int(L1.J2) && L1.prev3 == int(L1.J3))
            {
                turn_right++;
            }
        }
        if (turn_right == 9)
        {
            L1.calculateIK(9, 9, 11.3);
            L2.calculateIK(sqrt(126), 6, 6);
            L3.calculateIK(9, 9, 11.3);
            L4.calculateIK(0, sqrt(162), 11.3);
            L1.update1();
            L2.update2();
            L3.update3();
            L4.update4();
            if (L1.prev1 == int(L1.J1) && L1.prev2 == int(L1.J2) && L1.prev3 == int(L1.J3) && L2.prev1_r == int(L2.J1) && L2.prev2 == int(L2.J2) && L2.prev3 == int(L2.J3) &&
                L3.prev1 == int(L3.J1) && L3.prev2 == int(L3.J2) && L3.prev3 == int(L3.J3) && L4.prev1_r == int(L4.J1) && L4.prev2 == int(L4.J2) && L4.prev3 == int(L4.J3))
            {
                turn_right++;
            }
        }
        if (turn_right == 10)
        {
            L2.calculateIK(0, sqrt(162), 6);
            L2.update2();
            if (L2.prev1_r == int(L2.J1) && L2.prev2 == int(L2.J2) && L2.prev3 == int(L2.J3))
            {
                turn_right++;
            }
        }
        if (turn_right == 11)
        {
            L2.calculateIK(0, sqrt(162), 11.3);
            L2.update2();
            if (L2.prev1_r == int(L2.J1) && L2.prev2 == int(L2.J2) && L2.prev3 == int(L2.J3))
            {
                turn_right++;
            }
        }
        if (turn_right == 12)
        {
            turn_right = 0;
        }
        prevtime = curr;
    }
}


void resetB()
{
    j = 0;
    back_step = 0;
}
#endif