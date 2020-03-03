#include "main.h"
#include "opFunc.h"
#include "macro.h"

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
    /* 6pt pseudo auton on aditya's newest code*/


/* Red Small Side
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
    rightTurn(3, 80, 1.0);
    //backward(37, 120);
    backward(10, 120);
    rightTurn(120, 80, 1.0);
    //rightTurn(90, 80, 1.1);
    forward(13.5, 120);
    intake.moveVelocity(100);
    pros::delay(100);
    intake.moveVelocity(0);
    //forward(5.0, 80);
    tilterMacro();
    backward(10.0, 80);
*/

    // /*Red Big Side
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
    // */

    //SKILLS AUTON
    /*
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
`   */

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
