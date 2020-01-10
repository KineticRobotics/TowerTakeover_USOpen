//#include "motors.h"
#include "okapi/api.hpp"
#include "main.h"

void macro1()
{
    /*while (condition) //This is where the condition for the macro will go. E.g) While DR4B not in position
    {
        Macro code here.
    }*/
    //Motors.setVelocity(0);
}

void macroTask(void *) //Separate thread from the main thread that will house all the macro calls.
{
    Controller masterController;
    int oldstate = 0;
    int newstate = 0;
    int currentState;
    while (true)
    {
        currentState = masterController.getDigital(ControllerDigital::up);
        oldstate = newstate;
        newstate = currentState;
        if (oldstate == 1 && newstate == 0)
        {
            macro1();
            oldstate = 0;
            newstate = 0;
        }
    }
}