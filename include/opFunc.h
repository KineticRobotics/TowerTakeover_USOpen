#include "motors.h"
#include "okapi/api.hpp"
#include "main.h"

void intakeControl(int stateIn, int stateOut){
    if(stateIn == 1 && stateOut == 0){
        intake.moveVelocity(100);
    } else if(stateIn == 0 && stateOut == 1){
        intake.moveVelocity(-100);
    } else{
        intake.moveVelocity(0);
    }
}

void tilterControl(float speed){
    if(speed > .10 || speed < -.10){ 
        tilter.moveVelocity(100*speed);
    } else{
        tilter.moveVelocity(0);
    }
}

void dr4bControl(int L1, int L2, int buttonB) { //change variable names?
    if(L1 == 1 && L2 == 0 && buttonB == 0)
        dr4b.moveVelocity(100);
    else if(L1 == 0 && L2 == 1 && buttonB == 0)
        dr4b.moveVelocity(-100);
    else if(L1 == 0 && L2 == 0 && buttonB == 0)
        dr4b.moveVelocity(0);
    else if(L1 == 1 && L2 == 0 && buttonB == 1)
        dr4b.moveVelocity(50);
    else if(L1 == 0 && L2 == 1 && buttonB == 1)
        dr4b.moveVelocity(-50);
    else
        dr4b.moveVelocity(0);
}