#include "main.h"
#include "okapi/api.hpp"

using namespace okapi;

Motor dtLF = 18; //dt = drive Train
Motor dtLB = 10; //dt = drive Train
Motor dtRF = 1;
Motor dtRB = 13;

MotorGroup leftDrive({dtLF, dtLB});
MotorGroup rightDrive({dtRF, dtRB});

auto chassis = ChassisControllerFactory::create(
    leftDrive, rightDrive,
    AbstractMotor::gearset::green,
    {4.25, 12.0});
auto leftDTEnc = IntegratedEncoder(dtLF);
auto rightDTEnc = IntegratedEncoder(dtRF);

Motor dr4b(11, false, AbstractMotor::gearset::green);
auto dr4bEncoder = IntegratedEncoder(dr4b);

Motor intakeLeft(14, false, AbstractMotor::gearset::red);
Motor intakeRight(17, true, AbstractMotor::gearset::red);

MotorGroup intake({intakeLeft,intakeRight});

Motor tilter(3, true, AbstractMotor::gearset::red);
auto tilterEncoder = IntegratedEncoder(tilter);

pros::ADIDigitalIn tilterSensor ('B');
pros::ADIDigitalIn dr4bSensor ('D');
//lineTracker.get_value() (0 --> 4095): 0 being light and 4095 being dark

/*----------TEMPLATES------------------
okapi::MotorGroup right2({10, 20});
auto rightEB2 = IntegratedEncoder(11);
auto chassis2 = ChassisControllerFactory::create(
    left2, right2,
    AbstractMotor::gearset::green,
    {wheel diameter, 1.0});
};
Motor dr4bL2 = 15;
auto dr4b2 = ChassisControllerFactory::create(
    dr4bL2, dr4bR2,
    AbstractMotor::gearset::red
    );
*/
ADIGyro gyro = ADIGyro('A', .1);
