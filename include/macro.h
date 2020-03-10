#include "okapi/api.hpp"
#include "main.h"

void tilterMacro(){
  //This is where the condition for the macro will go. E.g) While DR4B not in position
    while (tilterEncoder.get() < 450.0)
    {
     //thinking about tilter stuff; made by Vincent 1/16
        tilter.moveVelocity(100);
    }
    intake.setBrakeMode(AbstractMotor::brakeMode::coast);
    while (tilterEncoder.get() < 710.0)
    {
        tilter.moveVelocity(60);
    }
    while (tilterEncoder.get() < 900.0)
    {
        tilter.moveVelocity(30);
    }
    tilter.moveVelocity(0);
    intake.setBrakeMode(AbstractMotor::brakeMode::hold);
}

void dr4bDownMacro(){
    while (dr4bSensor.get_value() == 0)
    {
        dr4b.moveVelocity(-200);
        tilter.moveVelocity(-30);
    }
    dr4b.moveVelocity(0);
    while(tilterSensor.get_value() != 1)
      {tilter.moveVelocity(-200);}
      tilter.moveVelocity(0);
}

void lineSensorMacro() {
    //while (lineSensor.get_value() < 2800 && lineSensor.get_value() > 2600)

      //printf("%d", lineSensor.get_value());

      intake.moveVelocity(100);
      pros::delay(200);
      intake.moveVelocity(0);


}

void DR4BMacro1(){  ///Low Tower; 18.83 inches
    while(tilterEncoder.get() < 280){
        tilter.moveVelocity(100);
    }
    tilter.moveVelocity(0);
    while(dr4bEncoder.get() < 330.0){
        dr4b.moveVelocity(100);
    }
    dr4b.moveVelocity(0);
    //printf("%d",1);
}

void DR4BMacro2(){  ///Medium Tower; 24.66 inches
    while(tilterEncoder.get() < 370){
        tilter.moveVelocity(100);
    }
    tilter.moveVelocity(0);
    while(dr4bEncoder.get()){
        dr4b.moveVelocity(100);
    }
    dr4b.moveVelocity(0);
    //printf("%d",1);
}

void DR4BMacro3(){  ///Medium Tower; 24.66 inches
  while(tilterEncoder.get() < 370){
      tilter.moveVelocity(100);
  }
  tilter.moveVelocity(0);
  while(dr4bEncoder.get()){
      dr4b.moveVelocity(100);
  }
  dr4b.moveVelocity(0);

  while(tilterEncoder.get() < 515){
      tilter.moveVelocity(100);
  }
  tilter.moveVelocity(0);
  while(dr4bEncoder.get()){
      dr4b.moveVelocity(70);
  }
  dr4b.moveVelocity(0);
    //printf("%d",1);
}

void macroTask(void *) //Separate thread from the main thread that will house all the macro calls.
{
    Controller masterController;

    int oldTilter = 0;
    int newTilter = 0;
    int curTilter;

    int oldDr4bDown = 0;
    int newDr4bDown = 0;
    int curDr4bDown;

    int oldLineSensor = 0;
    int newLineSensor = 0;
    int curLineSensor;

    int oldLift = 0;
    int newLift = 0;
    int curLift = 0;

    int oldLift2 = 0;
    int newLift2 = 0;
    int curLift2 = 0;

    int oldLift3 = 0;
    int newLift3 = 0;
    int curLift3 = 0;
    while (true)
    {
      //Tilter
        curTilter = masterController.getDigital(ControllerDigital::Y);
        oldTilter = newTilter;
        newTilter = curTilter;
        if (oldTilter == 1 && newTilter == 0)
        {
            tilterMacro();
            oldTilter = 0;
            newTilter = 0;
        }

        //dr4b Down
        curDr4bDown = masterController.getDigital(ControllerDigital::A);
        oldDr4bDown = newDr4bDown;
        newDr4bDown = curDr4bDown;
        if (oldDr4bDown == 1 && newDr4bDown == 0)
        {
            dr4bDownMacro();
            oldDr4bDown = 0;
            newDr4bDown = 0;
        }


        curLineSensor = masterController.getDigital(ControllerDigital::X);
        oldLineSensor = newLineSensor;
        newLineSensor = curLineSensor;
        if (oldLineSensor == 1 && newLineSensor == 0)
        {
            lineSensorMacro();
            oldLineSensor = 0;
            newLineSensor = 0;
        }

        //Low Tower
        oldLift = newLift;
        newLift = masterController.getDigital(ControllerDigital::down);
        if (oldLift == 1 && newLift == 0)
        {
            DR4BMacro1();
            oldLift = 0;
            newLift = 0;
        }

        //Medium Tower
        oldLift2 = newLift2;
        newLift2 = masterController.getDigital(ControllerDigital::B);
        if (oldLift2 == 1 && newLift2 == 0)
        {
          DR4BMacro2();
          oldLift2 = 0;
          newLift2 = 0;
        }

        //High Tower
        oldLift3 = newLift3;
        newLift3 = masterController.getDigital(ControllerDigital::right);
        if (oldLift3 == 1 && newLift3 == 0)
        {
          DR4BMacro3();
          oldLift3 = 0;
          newLift3 = 0;
        }
    }


}
