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

bool tilterControl(float speed, bool isZero2){
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

void polynomialPrecise(float distance, int max_power){
    rightDTEnc.reset();
    leftDTEnc.reset();
    float dist_traveled_left = 0;
    int power;
    while (dist_traveled_left < (distance / 3.0)){
        dist_traveled_left = leftDTEnc.get() * (3.14159265 / 180) * 2.0;
        power = (((3*(max_power - 20))/distance) * dist_traveled_left) + 40;
        chassis.arcade(0, (power / 200.0));
    }
    
    while ((dist_traveled_left < (2*distance) / 3.0))
    {
        dist_traveled_left = leftDTEnc.get() * (3.14159265 / 180) * 2.0;
        power = max_power;
        chassis.arcade(0, (power / 200.0));
    }

    while (dist_traveled_left < distance){
        dist_traveled_left = leftDTEnc.get() * (3.14159265 / 180) * 2.0;
        power = (((10-max_power) / (distance/3)) * dist_traveled_left) + ((3*max_power+20));
        chassis.arcade(0, power/200.0);
    }

    chassis.arcade(0,0);
}

void polynomialFast(float distance, int max_power){
    rightDTEnc.reset();
    leftDTEnc.reset();
    float dist_traveled_left = 0;
    int power;
    while (dist_traveled_left < distance){
        dist_traveled_left = leftDTEnc.get() * (3.14159265 / 180) * 2.0;
        power = max_power;
        chassis.arcade(0, power / 100.0);
    }

    chassis.arcade(0, 0);
}

void polynomialBackPrecise(float distance, int max_power){
    rightDTEnc.reset();
    leftDTEnc.reset();
    float dist_traveled_right = 0;
    int power;
    while (dist_traveled_right < (distance / 3.0)){
        dist_traveled_right = rightDTEnc.get() * (3.14159265 / 180) * 2.0;
        power = (((3 * (max_power - 20)) / distance) * dist_traveled_right) + 40;
        chassis.arcade(0, (-1 * power / 100.0));
    }

    while ((dist_traveled_right < (2 * distance) / 3.0)){
        dist_traveled_right = rightDTEnc.get() * (3.14159265 / 180) * 2.0;
        power = max_power;
        chassis.arcade(0, (-1*power / 100.0));
    }

    while (dist_traveled_right < distance){
        dist_traveled_right = rightDTEnc.get() * (3.14159265 / 180) * 2.0;
        power = (((10-max_power) / (distance / 3)) * dist_traveled_right) + ((3 * max_power+20));
        chassis.arcade(0, -1* power / 100.0);
    }

    chassis.arcade(0, 0);
}

void polynomialBackFast(float distance, int max_power){
    rightDTEnc.reset();
    leftDTEnc.reset();
    float dist_traveled_right = 0;
    int power;

    while (dist_traveled_right < distance){
        dist_traveled_right = rightDTEnc.get() * (3.14159265 / 180) * 2.0;
        power = max_power;
        chassis.arcade(0, -1 * power / 100.0);
    }

    chassis.arcade(0, 0);
}

void Turn(float angle, float power, float direction, float scale){
    float angle_traveled;;
    angle = angle*direction;
    gyro.reset();
    while (fabs(angle_traveled) < fabs(angle)){
        angle_traveled = gyro.get()*scale*direction;
        chassis.arcade((direction*power)/100.0, 0);
    }
    chassis.arcade(0,0);
}

void flipOut() {
    int happensOnce =1;
    while (tilterEncoder.get() < 650.0)
        tilter.moveVelocity(200);
    tilter.moveVelocity(0);
    intake.moveVelocity(100);
    pros::delay(200);
    tilter.moveVelocity(-200);
    while (tilterEncoder.get() > 20){
        tilter.moveVelocity(-200);
        if (happensOnce==1 && tilterEncoder.get() < 300){
            dr4b.moveVelocity(200);
            pros::delay(100);
            dr4b.moveVelocity(-200);
            pros::delay(200);
            dr4b.moveVelocity(0);
            happensOnce = 0;
        }}
    tilter.moveVelocity(0);
}