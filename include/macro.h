//#include "motors.h"
#include "okapi/api.hpp"
#include "main.h"

void tilterMacro(){
  //This is where the condition for the macro will go. E.g) While DR4B not in position
    while (tilterEncoder.get() < 450.0)
    {
     //thinking about tilter stuff; made by Vincent 1/16
        tilter.moveVelocity(100);
    }
    while (tilterEncoder.get() < 600.0)
    {
        tilter.moveVelocity(30);
    }
    while (tilterEncoder.get() < 700.0)
    {
        tilter.moveVelocity(15);
    }
    tilter.moveVelocity(0);
}

void DR4BMacro1(){  ///Low Tower; 18.83 inches
    while(tilterEncoder.get() < 280){
        tilter.moveVelocity(100);
    }
    tilter.moveVelocity(0);
    while(dr4bLEncoder.get() < 330.0 || dr4bREncoder.get() <  330.0){
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
    while(dr4bLEncoder.get() < 430.0 || dr4bREncoder.get() <  430.0){
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
  while(dr4bLEncoder.get() < 430.0 || dr4bREncoder.get() <  430.0){
      dr4b.moveVelocity(100);
  }
  dr4b.moveVelocity(0);

  while(tilterEncoder.get() < 515){
      tilter.moveVelocity(100);
  }
  tilter.moveVelocity(0);
  while(dr4bLEncoder.get() < 700.0 || dr4bREncoder.get() <  700.0){
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
        curTilter = masterController.getDigital(ControllerDigital::up);
        oldTilter = newTilter;
        newTilter = curTilter;
        if (oldTilter == 1 && newTilter == 0)
        {
            tilterMacro();
            oldTilter = 0;
            newTilter = 0;
        }

        //Low Tower
        oldLift = newLift;
        newLift = masterController.getDigital(ControllerDigital::left);
        if (oldLift == 1 && newLift == 0)
        {
            DR4BMacro1();
            oldLift = 0;
            newLift = 0;
        }

        //Medium Tower
        oldLift2 = newLift2;
        newLift2 = masterController.getDigital(ControllerDigital::down);
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
