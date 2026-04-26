#include "main.h"

std::atomic<bool> controllerDigitalFlag {false};

void controllerDigitalChecker(void* param){ 
    while (true){
        if (controllerDigitalFlag.load()){
                      
            //intake + outtake functionality
        if (master.get_digital_new_press(DIGITAL_R1)){
            if (!intakeRunning.load()){
                intakeRunning.store(true);
            }
        }
        if (master.get_digital_new_release(DIGITAL_R1)){
            intakeRunning.store(false);
        }
        if (master.get_digital_new_press(DIGITAL_L1)){
            if (!intakeSpitRunning.load()){
                intakeSpitRunning.store(true);
            }
        }
        if (master.get_digital_new_release(DIGITAL_L1)){
            intakeSpitRunning.store(false);
        }

        if (master.get_digital_new_press(DIGITAL_R2)){
            if (!outtakeRunning.load()){
                outtakeRunning.store(true);
                doorState.store(true);
            }
        }
        if (master.get_digital_new_release(DIGITAL_R2)){
            outtakeRunning.store(false);
            doorState.store(false);
        }   


        //lift functionality
        if (master.get_digital_new_press(DIGITAL_L2)){
            liftState.store(!liftState.load());
        }

        //loader functionality
        if (master.get_digital_new_press(DIGITAL_UP)){
            loaderState.store(!loaderState.load());
        }

        //descoreWing functionality
        if (master.get_digital_new_press(DIGITAL_X)){
            descoreWingState.store(!descoreWingState.load());
        }

    }
    pros::delay(25);
}
}