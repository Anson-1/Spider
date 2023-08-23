#ifdef ESP32
#include <ESP32Servo.h>
#include "gait.h"
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


#include "ROSserial.hpp"
#include <std_msgs/String.h>
#include <geometry_msgs/Twist.h>

ros::MyNodeHandle nh;
// std_msgs::String str_msg;
// ros::Publisher chatter("arduino", &str_msg);

// char hello[13] = "hello Nano!";
int movex = 0;
volatile bool commandUpdate = false;
int turn = 0;
void chatterCallback(const geometry_msgs::Twist &msg)
{
  int x = int(msg.linear.x * 2);
  int z = int(msg.angular.z);
  if(movex != x){
    commandUpdate = true;
    movex = x;
  }
  if(turn != z){
    commandUpdate = true;
    turn = z;
  }
}

ros::Subscriber<geometry_msgs::Twist> sub("cmd_vel", &chatterCallback);

void setup(){
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
  nh.initNode();
  nh.subscribe(sub);
  // Stand
  stand();

  delay(2000);
}

void loop(){
  // if(movex > 0){
  //   Forward(movex);
  //   if(i == movex){
  //     resetF();
  //   }
  // }else if(movex < 0){
  //   Backward(abs(movex));
  //   if(j == abs(movex)){
  //     resetB();
  //   }
  // }else if(turn > 0){
  //   TurnLeft();
  // }else if(turn < 0){
  //   TurnRight();
  // }
  // nh.spinOnce();
  // Forward(1);
  // if(i == 1){
  //   resetF();
  // }
  TurnLeft();
}