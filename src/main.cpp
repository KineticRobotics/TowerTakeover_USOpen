#include "main.h"
#include "opFunc.h"
#include "macro.h"

using namespace okapi;

void initialize() {}//Don't know if this is really gonna be used

void disabled() {} //Runs while robot is disabled. Not sure if we're gonna use this

void competition_initialize() {} //Probably put an autonomous selector here

void autonomous() {
    // ~20 second working (without goal wall)

    //4 + PRELOAD REDSIDE 
    /* 
    polynomialFast(7.0, 80);
    polynomialBackFast(5.0, 80);
    flipOut();
    intake.moveVelocity(100);
    pros::delay(200);
    intake.moveVelocity(0);
    chassis.setBrakeMode(AbstractMotor::brakeMode::hold);
    intake.moveVelocity(-100);
    polynomialFast(38.0, 60);
    polynomialBackFast(23.0, 120);
    intake.moveVelocity(0);
    Turn(135.0, 50, 1.0, 1.1);
    polynomialFast(7.0, 80);
    pros::delay(100);
    intake.moveVelocity(100);
    pros::delay(200);
    intake.moveVelocity(0);
    tilterMacro();
    intake.moveVelocity(100);
    pros::delay(200);
    intake.moveVelocity(0);
    polynomialBackFast(15.0, 120);
    */

    //Skulls 8Point  Blue
    /*
    polynomialFast(7.0, 80);
    polynomialBackFast(5.0, 80);
    flipOut();
    intake.moveVelocity(100);
    pros::delay(200);
    intake.moveVelocity(0);
    chassis.setBrakeMode(AbstractMotor::brakeMode::hold);
    intake.moveVelocity(-100);
    polynomialFast(40.0, 60);
    intake.moveVelocity(0);
    Turn(35.0, 50, -1.0, 1.1);
    polynomialFast(7.0, 60);
    Turn(35.0, 50, 1.0, 1.1);
    polynomialFast(17.0, 60);
    Turn(35.0, 50, 1.0, 1.1);
    polynomialFast(7.0, 60);
    Turn(35.0, 50, -1.0, 1.1);
    intake.moveVelocity(-100);
    polynomialFast(30.0, 60);
    pros::delay(100);
    intake.moveVelocity(0);
    Turn(45.0, 50, -1.0, 1.1);
    polynomialFast(15.0, 60);
    intake.moveVelocity(100);
    pros::delay(120);
    intake.moveVelocity(0);
    tilterMacro();
    intake.moveVelocity(100);
    pros::delay(200);
    intake.moveVelocity(0);
    polynomialBackFast(15.0, 120);
    */

    //Skills 7Point Blue
    /*
    polynomialFast(12.0, 80);
    polynomialBackFast(10.0, 80);
    flipOut();
    intake.moveVelocity(100);
    pros::delay(200);
    intake.moveVelocity(0);
    chassis.setBrakeMode(AbstractMotor::brakeMode::hold);
    intake.moveVelocity(-100);
    polynomialFast(38.0, 60);
    polynomialBackFast(20.0, 120);
    intake.moveVelocity(0);
    Turn(40.0, 100, 1.0, 1.1);
    polynomialBackFast(28.5, 120); //was 30 in original
    Turn(40.0, 100, -1.0, 1.1);
    intake.moveVelocity(-100);
    polynomialFast(30.0, 100);
    polynomialBackFast(23.0, 120);
    intake.moveVelocity(0);
    Turn(135.0, 50, -1.0, 1.1);
    polynomialFast(7.0, 80);
    intake.moveVelocity(100);
    pros::delay(120);
    intake.moveVelocity(0);
    tilterMacro();
    intake.moveVelocity(100);
    pros::delay(200);
    intake.moveVelocity(0);
    polynomialBackFast(15.0, 120);
    */

    //4 + PreLoad BLUESIDE
    polynomialFast(7.0, 80);
    polynomialBackFast(5.0, 80);
    flipOut();
    intake.moveVelocity(100);
    pros::delay(200);
    intake.moveVelocity(0);
    chassis.setBrakeMode(AbstractMotor::brakeMode::hold);
    intake.moveVelocity(-100);
    polynomialFast(38.0, 60);
    polynomialBackFast(23.0, 120);
    intake.moveVelocity(0);
    Turn(135.0, 50, -1.0, 1.1);
    polynomialFast(7.0, 80);
    pros::delay(100);
    intake.moveVelocity(100);
    pros::delay(200);
    intake.moveVelocity(0);
    tilterMacro();
    intake.moveVelocity(100);
    pros::delay(200);
    intake.moveVelocity(0);
    polynomialBackFast(15.0, 120);
    

    //1 point Auton
    /*polynomialBackFast(10, 120);
    polynomialFast(10, 120);
    flipOut();
    intake.moveVelocity(0);
    */

    /*6 + PRELOAD
    //NOT TESTED
    flipOut();
    intake.moveVelocity(100);
    pros::delay(200);
    intake.moveVelocity(0);
    chassis.setBrakeMode(AbstractMotor::brakeMode::hold);
    intake.moveVelocity(-100);
    polynomialFast(30.0, 120);
    intake.moveVelocity(0);
    polynomialBackFast(20.0, 120);
    Turn(40.0, 100, -1.0, 1.1);
    polynomialBackFast(28.5, 120); //was 30 in original
    Turn(40.0, 100, 1.0, 1.1);
    intake.moveVelocity(-100);
    polynomialFast(43.0, 100);
    pros::delay(200);
    intake.moveVelocity(0);
    polynomialBackFast(28.0, 120);
    Turn(145.0, 100, 1.0, 1.1);
    polynomialFast(8.0, 80);
    tilterMacro();
    intake.moveVelocity(100);
    pros::delay(200);
    intake.moveVelocity(0);
    polynomialBackFast(15.0, 120);
    */

    /*
    intake.moveVelocity(100);
    pros::delay(200);
    intake.moveVelocity(0);
    chassis.setBrakeMode(AbstractMotor::brakeMode::hold);
    intake.moveVelocity(-100);
    polynomialFast(46.0, 120);
    intake.moveVelocity(0);
    polynomialBackFast(20.0, 120);
    Turn(40.0, 100, -1.0, 1.1);
    polynomialBackFast(28.5, 120); //was 30 in original
    Turn(40.0, 100, 1.0, 1.1);
    intake.moveVelocity(-100);
    polynomialFast(43.0, 100);
    pros::delay(200);
    intake.moveVelocity(0);
    polynomialBackFast(28.0, 120);
    Turn(145.0, 100, 1.0, 1.1);
    polynomialFast(8.0, 80);
    tilterMacro();
    intake.moveVelocity(100);
    pros::delay(200);
    intake.moveVelocity(0);
    polynomialBackFast(15.0, 120);
    */

    /*
    Work in progress version
    chassis.setBrakeMode(AbstractMotor::brakeMode::brake);
    intake.moveVelocity(-100);
    polynomial(48.0, 170);
    intake.moveVelocity(0);
    polynomialBack(20.0, 170);
    Turn(40.0, 150, -1.0, 1.1);
    polynomialBack(25.0, 170);
    Turn(40.0, 150, 1.0, 1.1);
    intake.moveVelocity(-100);
    polynomial(39.0, 150);
    pros::delay(200);
    intake.moveVelocity(0);
    polynomialBack(26.0, 170);
    Turn(145.0, 200, 1.0, 1.1);
    polynomial(8.0, 80);
    tilterMacro();
    intake.moveVelocity(100);
    pros::delay(200);
    intake.moveVelocity(0);
    polynomialBack(15.0, 120);*/

    //pros::delay(100);
    //intake.moveVelocity(0);

} //Maybe make one of those...

void opcontrol(){
    bool isZero = false;
    bool isZero2 = false;
    bool isZero3 = false;
    intakeLeft.setBrakeMode(AbstractMotor::brakeMode::coast); //set all motors to specific brake types here. Dont know why but this doesn't work in motor.h
    intakeRight.setBrakeMode(AbstractMotor::brakeMode::coast);
    tilter.setBrakeMode(AbstractMotor::brakeMode::hold);
    dr4bL.setBrakeMode(AbstractMotor::brakeMode::hold);
    dr4bR.setBrakeMode(AbstractMotor::brakeMode::hold);

    Controller masterController; //Maybe this can go in motor.h?

    pros::Task my_task(macroTask, (void *)"PROS", TASK_PRIORITY_DEFAULT, //start running the macro task. For this build, it WILL get stuck in macro1();. However, operator control should still work
                       TASK_STACK_DEPTH_DEFAULT, "My Task");

    while(true){
        isZero = intakeControl(masterController.getDigital(ControllerDigital::R2), masterController.getDigital(ControllerDigital::R1), isZero); //Intake is currently in a task alone

        chassis.arcade(masterController.getAnalog(ControllerAnalog::leftX),
                       masterController.getAnalog(ControllerAnalog::leftY));

        isZero2 = tilterControl(masterController.getAnalog(ControllerAnalog::rightY), isZero2);

        isZero3 = dr4bControl(masterController.getDigital(ControllerDigital::L1), masterController.getDigital(ControllerDigital::L2), masterController.getDigital(ControllerDigital::B), isZero3);
    }
}