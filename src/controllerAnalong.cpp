#include "main.h"

std::atomic<bool> controllerAnalogFlag {false};

void controllerAnalogChecker(void* param){
    while (true){

            //drive function
            // get left y and right y positions
            int leftY = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
            int rightX = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

            // move the robot
            chassis.arcade(leftY, rightX, false, 0.35);

        pros::delay(25);
    }
}
