#include "motors.h"
#include "okapi/api.hpp"
#include "main.h"

bool intakeControl(int stateIn, int stateOut, bool isZero){
    if(stateIn == 1 && stateOut == 0){
        intake.moveVelocity(100);
        isZero = false;
    } else if(stateIn == 0 && stateOut == 1){
        intake.moveVelocity(-100);
        isZero = false;
    } else{
        if (isZero == false)
        {
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
    } else{
        if (isZero2 == false){
            tilter.moveVelocity(0);
            isZero2 = true;}
    }
    return isZero2;
}

bool dr4bControl(int L1, int L2, int buttonB, bool isZero3) { //change variable names?
    if(L1 == 1 && L2 == 0 && buttonB == 0){
        dr4b.moveVelocity(200);
        isZero3 = false;}
    else if(L1 == 0 && L2 == 1 && buttonB == 0){
        dr4b.moveVelocity(-200);
        isZero3 = false;}
    else if(L1 == 0 && L2 == 0 && buttonB == 0){
        if (isZero3 == false){
            dr4b.moveVelocity(0);
            isZero3 = true;}}
    else if(L1 == 1 && L2 == 0 && buttonB == 1){
        dr4b.moveVelocity(100);
        isZero3 = false;}
    else if(L1 == 0 && L2 == 1 && buttonB == 1){
        dr4b.moveVelocity(-100);
        isZero3 = false;}
    else{
        if (isZero3 == false){
            dr4b.moveVelocity(0);
            isZero3 = true;}}
}