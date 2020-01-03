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

void tilterControl(int speed){
    if(speed > 20){ //untested-- There *should* be an abs() there.
        tilter.moveVelocity(speed);
    } else{
        tilter.moveVelocity(0);
    }
}