//#include "motors.h"
#include "okapi/api.hpp"
#include "main.h"

void tilterMacro(){
    while (tilterEncoder.get() < 350.0) //This is where the condition for the macro will go. E.g) While DR4B not in position
    {
     //thinking about tilter stuff; made by Vincent 1/16
        tilter.moveVelocity(70);
    }
    while (tilterEncoder.get() < 550.0)
    {
        tilter.moveVelocity(30);
    }
    while (tilterEncoder.get() < 700.0)
    {
        tilter.moveVelocity(15);
    }
    tilter.moveVelocity(0);
}

void DR4BMacro(){
    /*while(encoder.get() < value.0){
        tilter.moveVelocity();
    }
    tilter.moveVelocity(0);
    while(encoder.get() < value.0){
        dr4b.moveVelocity();
    }
    dr4b.moveVelocity(0);
    */
    printf("%d",1);
}

void macroTask(void *) //Separate thread from the main thread that will house all the macro calls.
{
    Controller masterController;

    int oldTilter = 0;
    int newTilter = 0;
    int curTilter;

    int oldLift = 0;
    int newLift = 0;
    int curLift = 0;
    while (true)
    {
        curTilter = masterController.getDigital(ControllerDigital::up);
        oldTilter = newTilter;
        newTilter = curTilter;
        if (oldTilter == 1 && newTilter == 0)
        {
            tilterMacro();
            oldTilter = 0;
            newTilter = 0;
        }

        oldLift = newLift;
        newLift = masterController.getDigital(ControllerDigital::left);
        if (oldLift == 1 && newLift == 0)
        {
            DR4BMacro();
            oldLift = 0;
            newLift = 0;
        }
    }


}