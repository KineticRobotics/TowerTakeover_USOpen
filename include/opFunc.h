#include "motors.h"
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

void forward(float distance, int max_power){
   //distance = distance + .0451 * distance - .427;
    rightDTEnc.reset();
    leftDTEnc.reset();
    float dist_traveled_left = 0;
    int power_right;
    int power_left;
    while (dist_traveled_left < distance){
        //dist_traveled_right = rightDTEnc.get() * (3.14159265 / 180) * 2.125;
        //dist_traveled_left = leftDTEnc.get() * (3.14159265 / 180) * 2.0;
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
    int power_right;
    int power_left;
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
