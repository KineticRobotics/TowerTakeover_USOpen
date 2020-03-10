#include "motors.h"
#include "okapi/api.hpp"
#include "main.h"

bool intakeControl(int R2, int R1, bool isZero){
    if(R2 == 1 && R1 == 0){
        intake.moveVelocity(100);
        isZero = false;
    } else if(R2 == 0 && R1 == 1){
        intake.moveVelocity(-100);
        isZero = false;
    } else {
        if (isZero == false){
            intake.moveVelocity(0);
            isZero = true;
        }
    }
    return isZero;
}

bool tilterControl(float speed, bool isZero2) {
    if(speed > .10 || speed < -.10){
        tilter.moveVelocity(100*speed);
        isZero2 = false;
    } else {
        if (isZero2 == false){
            tilter.moveVelocity(0);
            isZero2 = true;}
    }
    return isZero2;
}

bool dr4bControl(int L1, int L2, int buttonB, bool isZero3){ //change variable names?
    if(L1 == 1 && L2 == 0){
        dr4b.moveVelocity(200);
        isZero3 = false;
    } else if(L1 == 0 && L2 == 1){
        dr4b.moveVelocity(-200);
        isZero3 = false;
    } else if(L1 == 0 && L2 == 0){
        if (isZero3 == false){
            dr4b.moveVelocity(0);
            isZero3 = true;
        }}
    return isZero3;
}


void backward(float distance, int max_power){
   //distance = distance + .0451 * distance - .427;
    rightDTEnc.reset();
    leftDTEnc.reset();
    float dist_traveled_right = 0;
    int power_right;
    int power_left;
    while (dist_traveled_right < distance){
        //dist_traveled_right = rightDTEnc.get() * (3.14159265 / 180) * 2.125;
        //dist_traveled_right = rightDTEnc.get() * (3.14159265 / 180) * 2.0;
        dist_traveled_right = rightDTEnc.get() * (3.14159265 / 180) * 1.2; //FIX!
        //power_right = (dist_traveled_right * 2 * (10 - max_power)) / distance + 2 * max_power - 10;
        //power_left = (((-max_power) / (distance/3)) * dist_traveled_left) + ((3*max_power));
        power_right = max_power;
        chassis.arcade(0, -power_right/100.0);
    }
    chassis.arcade(0,0);
}

void leftTurn(float angle, int max_power, double scale) {
    float angle_traveled = 0;
    int power;
    gyro.reset();
    while(angle_traveled > -angle){
        angle_traveled = gyro.get() * scale;
        power = max_power;
        chassis.arcade(-power/100.0, 0);
    }
    chassis.arcade(0, 0);
}

void rightTurn(float angle, int max_power, double scale) {
    float angle_traveled = 0;
    int power;
    gyro.reset();
    while(angle_traveled < angle){
        angle_traveled = gyro.get() * scale;
        power = max_power;
        chassis.arcade(power/100.0, 0);
    }
    chassis.arcade(0, 0);
}

void slopeTesting(float slope){
    rightDTEnc.reset();
    leftDTEnc.reset();
    float dist_traveled_left = 0;
    int power_right;
    int power_left;
    while (dist_traveled_left < 10.0){
        //dist_traveled_right = rightDTEnc.get() * (3.14159265 / 180) * 2.125;
        //dist_traveled_left = leftDTEnc.get() * (3.14159265 / 180) * 2.0;
        dist_traveled_left = leftDTEnc.get() * (3.14159265 / 180) * 2.125; //FIX!
        //power_right = (dist_traveled_right * 2 * (10 - max_power)) / distance + 2 * max_power - 10;
        //power_left = (((-max_power) / (distance/3)) * dist_traveled_left) + ((3*max_power));
        power_left = slope * sqrt(dist_traveled_left) + 26.0;
        chassis.arcade(0, power_left/200.0);
    }

    chassis.arcade(0,0);
}

/*testing minimum power*/
void minPowerTesting(){
  double x = 0;
  while(true) {
      chassis.arcade(0, x);
      pros::lcd::set_text(1, std::to_string(x));
      pros::delay(1500);
      x += 0.13;
  }
}

void forward(float distance){
    float distance_traveled_left = 0.0;
    rightDTEnc.reset();
    leftDTEnc.reset();
    float power;
    float maxPower = 80.0*sqrt(distance/3.0)+26;
    if (maxPower > 200.0){
      maxPower = 200.0;
    }
    while (distance_traveled_left < distance/3.0){
      distance_traveled_left = leftDTEnc.get()*(3.14159265/180.0)*2.0;
      power = 80.0 * sqrt(distance_traveled_left) + 26.0;
      chassis.arcade(0, power/200.0);
    }
    while (distance_traveled_left < 2*distance/3.0){
      distance_traveled_left = leftDTEnc.get()*(3.14159265/180.0)*2.0;
      power = maxPower;
      chassis.arcade(0, power/200.0);
    }
    distance_traveled_left = 0.0;
    rightDTEnc.reset();
    leftDTEnc.reset();
    while (distance_traveled_left < distance/3){
      distance_traveled_left = leftDTEnc.get()*(3.14159265/180.0)*2.0;
      power = maxPower - sqrt(distance_traveled_left)*sqrt((3.0*(maxPower)*(maxPower))/(distance));
      chassis.arcade(0, power/200.0);
    }
    chassis.arcade(0,0);
}

/*toggle increase and decrease
//how to use this:
//chassis.arcade(0, toggleIncrease(power_left));
//can be used for any value-find testing (must be in op control or somewhere where it do be reading the button)

double toggleIncrease(double value){
  //condition button is for the button pressed
  //increment is the increment for now is 1
  double increment = 1.0;
  if(button)
    return value+increment;
  else
    return value;
}

double toggleDecrease(double value){
  //condition button is for the button pressed
  //increment is the increment
  double increment = 1.0;
  if(button)
    return value+increment;
  else
    return value;
}

*/
