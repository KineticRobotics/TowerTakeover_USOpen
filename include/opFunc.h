#include "main.h"
#include "opFunc.h"
//#include "macro.h"

using namespace okapi;

void initialize() {
  pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS User!");
  pros::lcd::set_text(2, std::to_string(intake.getTemperature()));
}//Don't know if this is really gonna be used

void disabled() {} //Runs while robot is disabled. Not sure if we're gonna use this

void competition_initialize() {} //Probably put an autonomous selector here

void autonomous() {
    chassis.setBrakeMode(AbstractMotor::brakeMode::brake);
    //Red6();
    Red4();
    //Blue6();
    //Blue4();
    //skillsAuton();

} //Maybe make one of those...

void opcontrol()
{
    bool isZero = false;
    bool isZero2 = false;
    bool isZero3 = false;
    intakeLeft.setBrakeMode(AbstractMotor::brakeMode::hold); //set all motors to specific brake types here. Dont know why but this doesn't work in motor.h
    intakeRight.setBrakeMode(AbstractMotor::brakeMode::hold);
    tilter.setBrakeMode(AbstractMotor::brakeMode::hold);
    tilter2.setBrakeMode(AbstractMotor::brakeMode::hold);
    intake.setBrakeMode(AbstractMotor::brakeMode::coast);
    dr4b.setBrakeMode(AbstractMotor::brakeMode::hold);

    Controller masterController; //Maybe this can go in motor.h?
    pros::Task my_task(macroTask, (void *)"PROS", TASK_PRIORITY_DEFAULT, //start running the macro task. For this build, it WILL get stuck in macro1();. However, operator control should still work
                       TASK_STACK_DEPTH_DEFAULT, "My Task");

    while(true){
        masterController.setText(0,0,std::to_string(tilter.getTemperature()));
        isZero = intakeControl(masterController.getDigital(ControllerDigital::R2), masterController.getDigital(ControllerDigital::R1), isZero); //Intake is currently in a task alone

        chassis.arcade(masterController.getAnalog(ControllerAnalog::leftX),
                       masterController.getAnalog(ControllerAnalog::leftY));

        isZero2 = tilterControl(masterController.getAnalog(ControllerAnalog::rightY), isZero2);

        isZero3 = dr4bControl(masterController.getDigital(ControllerDigital::L1), masterController.getDigital(ControllerDigital::L2), masterController.getDigital(ControllerDigital::B), isZero3);
    }
}
