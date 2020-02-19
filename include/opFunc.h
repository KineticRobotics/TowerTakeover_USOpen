#include "motors.h"
#include "macro.h"
#include "okapi/api.hpp"
#include "main.h"

bool intakeControl(int R2, int R1, bool isZero){
    if(R2 == 1 && R1 == 0){
        intake.moveVelocity(100);
        isZero = false;
    } else if(R2 == 0 && R1 == 1){
        intake.moveVelocity(-100);
        isZero = false;
    } else {
        if (isZero == false){
            intake.moveVelocity(0);
            isZero = true;
        }
    }
    return isZero;
}

bool tilterControl(float speed, bool isZero2) {
    if(speed > .10 || speed < -.10){
        tilter.moveVelocity(100*speed);
        isZero2 = false;
    } else {
        if (isZero2 == false){
            tilter.moveVelocity(0);
            isZero2 = true;}
    }
    return isZero2;
}

void fullPowerTilter() {
  while(tilterEncoder.get() < 700.0)
  {
    tilter.moveVelocity(100);
  }
  tilter.moveVelocity(0);
}

bool dr4bControl(int L1, int L2, int buttonB, bool isZero3){ //change variable names?
    if(L1 == 1 && L2 == 0 && buttonB == 0){
        dr4b.moveVelocity(200);
        isZero3 = false;
    } else if(L1 == 0 && L2 == 1 && buttonB == 0){
        dr4b.moveVelocity(-200);
        isZero3 = false;
    } else if(L1 == 0 && L2 == 0 && buttonB == 0){
        if (isZero3 == false){
            dr4b.moveVelocity(0);
            isZero3 = true;
        }
    } else if(L1 == 1 && L2 == 0 && buttonB == 1){
        dr4b.moveVelocity(70);
        isZero3 = false;
    } else if(L1 == 0 && L2 == 1 && buttonB == 1){
        dr4b.moveVelocity(-70);
        isZero3 = false;
    } else {
        if (isZero3 == false){
            dr4b.moveVelocity(0);
            isZero3 = true;
        }
    }
    return isZero3;
}

void forward(float distance, float max_power){
   //distance = distance + .0451 * distance - .427;
    rightDTEnc.reset();
    leftDTEnc.reset();
    float dist_traveled_left;
    float power_right;
    float power_left;
    while (dist_traveled_left < distance){
        //dist_traveled_right = rightDTEnc.get() * (3.14159265 / 180) * 2.125;
        //dist_traveled_left = leftDTEnc.get() * (3.14159265 / 180.0) * 2.0;
        dist_traveled_left = leftDTEnc.get() * (3.14159265 / 180) * 1.2; //FIX!
        //power_right = (dist_traveled_right * 2 * (10 - max_power)) / distance + 2 * max_power - 10;
        //power_left = (((-max_power) / (distance/3)) * dist_traveled_left) + ((3*max_power));
        power_left = max_power;
        chassis.arcade(0, power_left/100.0);
    }

    chassis.arcade(0,0);
}

void backward(float distance, int max_power){
   //distance = distance + .0451 * distance - .427;
    rightDTEnc.reset();
    leftDTEnc.reset();
    float dist_traveled_right = 0;
    float power_right;
    float power_left;
    while (dist_traveled_right < distance){
        //dist_traveled_right = rightDTEnc.get() * (3.14159265 / 180) * 2.125;
        //dist_traveled_right = rightDTEnc.get() * (3.14159265 / 180) * 2.0;
        dist_traveled_right = rightDTEnc.get() * (3.14159265 / 180) * 1.2; //FIX!
        //power_right = (dist_traveled_right * 2 * (10 - max_power)) / distance + 2 * max_power - 10;
        //power_left = (((-max_power) / (distance/3)) * dist_traveled_left) + ((3*max_power));
        power_right = max_power;
        chassis.arcade(0, -power_right/100.0);
    }
    chassis.arcade(0,0);
}

void leftTurn(float angle, int max_power, double scale) {
    float angle_traveled = 0;
    int power;
    gyro.reset();
    while(angle_traveled > -angle){
        angle_traveled = gyro.get() * scale;
        power = max_power;
        chassis.arcade(-power/100.0, 0);
    }
    chassis.arcade(0, 0);
}

void rightTurn(float angle, int max_power, double scale) {
    float angle_traveled = 0;
    int power;
    gyro.reset();
    while(angle_traveled < angle){
        angle_traveled = gyro.get() * scale;
        power = max_power;
        chassis.arcade(power/100.0, 0);
    }
    chassis.arcade(0, 0);
}

void bigRed(){
  forward(10.0, 100);
  backward(10.0, 100);
  while(tilterEncoder.get() < 700.0)
    {tilter.moveVelocity(100);}
  intake.moveVelocity(100);
  pros::delay(200);
  intake.moveVelocity(0);
  dr4bDownMacro();

  intake.moveVelocity(-100);
  forward(24, 60);
  intake.moveVelocity(0);
  rightTurn(90, 80, 1.0);

  intake.moveVelocity(-100);
  forward(18.0, 60);
  intake.moveVelocity(0);

  backward(10.0, 80);
  rightTurn(170, 80, 1.0);

  intake.moveVelocity(-100);
  forward(26.0, 60);
  intake.moveVelocity(0);

  leftTurn(50, 80, 1.0);
  forward(13.5, 120);
  intake.moveVelocity(100);
  pros::delay(300);
  intake.moveVelocity(0);
  tilterMacro();
  backward(10.0, 80);
}

void smallRed(){
  forward(10.0, 100);
  backward(10.0, 100);
  while(tilterEncoder.get() < 700.0)
    {tilter.moveVelocity(100);}
  intake.moveVelocity(100);
  pros::delay(200);
  intake.moveVelocity(0);
  dr4bDownMacro();
  intake.moveVelocity(-100);
  forward(38, 60);
  pros::delay(200);
  leftTurn(6, 80, 1.0);
  pros::delay(500);
  forward(11, 80);
  pros::delay(500);
  backward(11, 80);
  intake.moveVelocity(0);
  rightTurn(6, 80, 1.0);
  backward(10, 120);
  rightTurn(120, 80, 1.0);
  forward(13.5, 120);
  intake.moveVelocity(100);
  pros::delay(100);
  intake.moveVelocity(0);
  tilterMacro();
  backward(10.0, 80);
}

void bigBlue(){

  forward(10.0, 100);
  backward(10.0, 100);
  while(tilterEncoder.get() < 700.0)
    {tilter.moveVelocity(100);}
  intake.moveVelocity(100);
  pros::delay(200);
  intake.moveVelocity(0);
  dr4bDownMacro();

  intake.moveVelocity(-100);
  forward(24, 60);
  intake.moveVelocity(0);
  leftTurn(90, 80, 1.0);

  intake.moveVelocity(-100);
  forward(12.0, 60);
  pros::delay(500);
  intake.moveVelocity(0);

  backward(10.0, 80);
  leftTurn(155, 80, 1.0);

  intake.moveVelocity(-100);
  forward(20.0, 60);
  intake.moveVelocity(0);

  rightTurn(30, 80, 1.0);
  forward(13, 120);
  intake.moveVelocity(100);
  pros::delay(300);
  intake.moveVelocity(0);
  fullPowerTilter();
  backward(10.0, 80);
}

void smallBlue(){
  forward(10.0, 100);
  backward(10.0, 100);
  while(tilterEncoder.get() < 700.0)
    {tilter.moveVelocity(100);}
  intake.moveVelocity(100);
  pros::delay(200);
  intake.moveVelocity(0);
  dr4bDownMacro();
  intake.moveVelocity(-100);
  forward(38, 60);
  pros::delay(200);
  rightTurn(6, 80, 1.0);
  pros::delay(500);
  forward(11, 80);
  pros::delay(500);
  backward(11, 80);
  intake.moveVelocity(0);
  leftTurn(6, 80, 1.0);
  backward(10, 120);
  leftTurn(120, 80, 1.0);
  forward(13.5, 120);
  intake.moveVelocity(100);
  pros::delay(100);
  intake.moveVelocity(0);
  tilterMacro();
  backward(10.0, 80);
}

void skillsAuton(){
  forward(10.0, 100);
  backward(10.0, 100);
  while(tilterEncoder.get() < 700.0)
    {tilter.moveVelocity(100);}
  intake.moveVelocity(100);
  pros::delay(200);
  intake.moveVelocity(0);
  dr4bDownMacro();

  intake.moveVelocity(-100);
  forward(38, 60);
  backward(10, 80);
  leftTurn(25, 100, 1.0);
  backward(33, 80);
  rightTurn(25, 100, 1.0);
  forward(38, 60);
  backward(10, 80);
  rightTurn(120, 80, 1.0);
  forward(20, 120);
  intake.moveVelocity(100);
  pros::delay(100);
  intake.moveVelocity(0);
  tilterMacro();
  backward(10.0, 80);
}
