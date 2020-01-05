#include "main.h"
#include "opFunc.h"
using namespace okapi;

void task1(void *) //Separate thread from the main thread. Simply a proof of concept. Later use for macros to avoid getting stuck.
{
    while(true) {
        Controller masterController; //Maybe this can go in motor.h?
        intakeControl(masterController.getDigital(ControllerDigital::R2), masterController.getDigital(ControllerDigital::R1));
    }
}


void initialize()
{
}   


void disabled() {} //Runs while robot is disabled. Not sure if we're gonna use this

void competition_initialize() {} //Probably put an autonomous selector here

void autonomous() {} //Maybe make one of those...

void opcontrol()
{
    intakeLeft.setBrakeMode(AbstractMotor::brakeMode::hold); //set all motors to specific brake types here. Dont know why but this doesn't work in motor.h
    intakeRight.setBrakeMode(AbstractMotor::brakeMode::hold);
    tilter.setBrakeMode(AbstractMotor::brakeMode::hold);

    Controller masterController; //Maybe this can go in motor.h?
    pros::Task my_task(task1, (void *)"PROS", TASK_PRIORITY_DEFAULT,
                       TASK_STACK_DEPTH_DEFAULT, "My Task");
    while(true){
        //intakeControl(masterController.getDigital(ControllerDigital::R2), masterController.getDigital(ControllerDigital::R1)); //Intake is currently in a task alone

        chassis.arcade(masterController.getAnalog(ControllerAnalog::leftX),
                       masterController.getAnalog(ControllerAnalog::leftY));

        tilterControl(masterController.getAnalog(ControllerAnalog::rightY));

        dr4bControl(masterController.getDigital(ControllerDigital::L1), masterController.getDigital(ControllerDigital::L2), masterController.getDigital(ControllerDigital::B));
    }
}


