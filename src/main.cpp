#include "main.h"

//call pathing files

//ASSET(leftpathV1_txt);


//instantiation of non drivetrain vex devices here

pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::Imu imu(18);

//insatntiate PROS and Lemlib objects


pros::MotorGroup leftDrive({1, -2, 3, -4, 5}, pros::MotorGearset::blue);
pros::MotorGroup rightDrive({6, -7, 8, -9, 10}, pros::MotorGearset::blue);

lemlib::Drivetrain drivetrain(&leftDrive, // left motor group
                              &rightDrive, // right motor group
                              11.75, // 10 inch track width
                              lemlib::Omniwheel::NEW_325, // using new 4" omnis
                              360, // drivetrain rpm is 3
                              2 // horizontal drift is 2 (for now)
);


lemlib::OdomSensors sensors(nullptr, // vertical tracking wheel 1, set to null
                            nullptr, // vertical tracking wheel 2, set to nullptr as we are using IMEs
                            nullptr, // horizontal tracking wheel 1
                            nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
                            &imu // inertial sensor
);

lemlib::ControllerSettings lateral_controller(10, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              3, // derivative gain (kD)
                                              3, // anti windup
                                              1, // small error range, in inches
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in inches
                                              500, // large error range timeout, in milliseconds
                                              20 // maximum acceleration (slew)
);

lemlib::ControllerSettings angular_controller(2, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              10, // derivative gain (kD)
                                              3, // anti windup
                                              1, // small error range, in inches
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in inches
                                              500, // large error range timeout, in milliseconds
                                              0 // maximum acceleration (slew)
);

lemlib::ExpoDriveCurve throttle_curve(2, // joystick deadband out of 127 // snaps to zero from here and not out of zero until this value is reached
                                     10, // minimum output where drivetrain will move out of 127 // Once out of deadzone, move the minimum of this much
                                     1.020 // expo curve gain // how much the input scales the farther from zero we are
);

lemlib::ExpoDriveCurve steer_curve(2, // joystick deadband out of 127 (Deadzone) // snaps to zero from here and not out of zero until this value is reached
                                  10, // minimum output where drivetrain will move out of 127 // Once out of deadzone, move the minimum of this much
                                  1.015 // expo curve gain // how much the input scales the farther from zero we are
);

lemlib::Chassis chassis(
    drivetrain,
    lateral_controller,
    angular_controller,
    sensors,
    &throttle_curve,
    &steer_curve
);

void initialize() {

    //hardware intialization
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);

    //task creation

static pros::Task intakeTask (
    intakeCallback, 
    (void*)"PROS", 
    TASK_PRIORITY_DEFAULT, 
    TASK_STACK_DEPTH_DEFAULT, 
    "intakeTask");

static pros::Task controllerDigitalTask (
    controllerDigitalChecker, 
    (void*)"PROS", 
    TASK_PRIORITY_DEFAULT, 
    TASK_STACK_DEPTH_DEFAULT, 
    "controllerDigitalTask");

static pros::Task controllerAnalogTask (
    controllerAnalogChecker, 
    (void*)"PROS", 
    TASK_PRIORITY_DEFAULT, 
    TASK_STACK_DEPTH_DEFAULT, 
    "controllerAnalogTask");

static pros::Task lvglTimerTask (
    lvglTask,
    (void*)"PROS",
    TASK_PRIORITY_DEFAULT,
    TASK_STACK_DEPTH_DEFAULT,
    "lvglTimerTask");

static pros::Task liftTask (
    liftCallback,
    (void*)"PROS",
    TASK_PRIORITY_DEFAULT,
    TASK_STACK_DEPTH_DEFAULT,
    "liftTask");

static pros::Task loaderTask (
    loaderCallback,
    (void*)"PROS",
    TASK_PRIORITY_DEFAULT,
    TASK_STACK_DEPTH_DEFAULT,
    "loaderTask");

static pros::Task doorTask (
    doorCallback,
    (void*)"PROS",
    TASK_PRIORITY_DEFAULT,
    TASK_STACK_DEPTH_DEFAULT,
    "doorTask");

//sensor data output loop
/*

    pros::lcd::initialize(); // initialize brain screen
    chassis.calibrate();
        while (true) {
            // print robot location to the brain screen
            pros::lcd::print(0, "X: %f", chassis.getPose().x); // x
            pros::lcd::print(1, "Y: %f", chassis.getPose().y); // y
            pros::lcd::print(2, "Theta: %f", chassis.getPose().theta); // heading
            // delay to save resources
            pros::delay(20);
        }
*/

    showLogoFlag.store(true);

}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */

void competition_initialize() {

    showLogoFlag.store(false);
    selectorButtons();

}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
            /*
            leftIntake.move_voltage(12000);
            rightIntake.move_voltage(12000);
            pros::delay(1000);
            leftIntake.move_velocity(0);
            rightIntake.move_velocity(0);

            //chassis.follow(leftpathV1_txt, 15, 20000);
            */

    }

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */

void opcontrol() {

    showLogoFlag.store(true);

    //enable tasks
    controllerAnalogFlag.store(true);
    controllerDigitalFlag.store(true);
    intakeFlag.store(true);
    liftFlag.store(true);
    loaderFlag.store(true);
    doorFlag.store(true);


    while (true) {

        pros::delay(25);

    }
}