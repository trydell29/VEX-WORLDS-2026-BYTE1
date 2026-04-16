#include "main.h"

//intake flags

std::atomic<bool> intakeRunning{false};
std::atomic<bool> intakeSpitRunning{false};
std::atomic<bool> intakeFlag{false};
std::atomic<bool> outtakeRunning{false};

//instantiation of intake and outtake dual motors
pros::Motor ml1(11, pros::MotorGearset::blue);
pros::Motor ml2(-12, pros::MotorGearset::red);
pros::Motor ml3(13, pros::MotorGearset::blue);
pros::Motor ml4(-14, pros::MotorGearset::blue);
pros::Motor ml5(15, pros::MotorGearset::red);
pros::Motor ml6(-16, pros::MotorGearset::blue);

void runIntake(){
    ml1.move_voltage(12000);
    ml2.move_voltage(12000);
    ml3.move_voltage(12000);
    ml4.move_voltage(12000);
    ml5.move_voltage(12000);
    ml6.move_voltage(12000);
    doorSolenoid.set_value(false);
}

void runIntakeSpit(){
    ml1.move_voltage(-12000);
    ml2.move_voltage(-12000);
    ml3.move_voltage(-12000);
    ml4.move_voltage(-12000);
    ml5.move_voltage(-12000);
    ml6.move_voltage(-12000);
    doorSolenoid.set_value(false);
}

void runOuttake(){
    ml1.move_voltage(12000);
    ml2.move_voltage(12000);
    ml3.move_voltage(12000);
    ml4.move_voltage(12000);
    ml5.move_voltage(12000);
    ml6.move_voltage(12000);
    doorSolenoid.set_value(true);
}

void stopIndexer(){
    ml1.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    ml2.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    ml3.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    ml4.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    ml5.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    ml6.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    ml1.move_voltage(0);
    ml2.move_voltage(0);
    ml3.move_voltage(0);
    ml4.move_voltage(0);
    ml5.move_voltage(0);
    ml6.move_voltage(0);
    doorSolenoid.set_value(false);
}

void intakeCallback(void* param){
    while (true){
        if (intakeFlag.load()){
            if ((intakeRunning.load() && intakeSpitRunning.load()) || (intakeRunning.load() && outtakeRunning.load()) || (intakeSpitRunning.load() && outtakeRunning.load())){
                stopIndexer();
            }
            else if (intakeRunning.load()){
                runIntake();
            }
            else if (intakeSpitRunning.load()){
                runIntakeSpit();
            }
            else if (outtakeRunning.load()){
                runOuttake();
            }
            else {
                stopIndexer();
            }
        }
        pros::delay(25);
    }
}