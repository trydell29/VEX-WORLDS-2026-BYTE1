#include "main.h"

std::atomic<bool> liftState{false}; 
std::atomic<bool> liftFlag{false};
std::atomic<bool> loaderState{false}; 
std::atomic<bool> loaderFlag{false};
std::atomic<bool> doorState{false};
std::atomic<bool> doorFlag{false};
std::atomic<bool> descoreWingState{false};
std::atomic<bool> descoreWingFlag{false};

pros::adi::DigitalOut liftSolenoid('A');
pros::adi::DigitalOut loaderSolenoid('B');
pros::adi::DigitalOut doorSolenoid('C');
pros::adi::DigitalOut descoreWingSolenoid('D');

void liftCallback(void* param){
    while (true){
        if (liftFlag.load()){
        if (liftState == true){
            liftSolenoid.set_value(true);
        }
        if (liftState == false){
            liftSolenoid.set_value(false);
        }
    }
        pros::delay(25);
    }
}

void loaderCallback(void* param){
    while (true){
        if (loaderFlag.load()){
        if (loaderState == true){
            loaderSolenoid.set_value(true);
        }
        if (loaderState == false){
            loaderSolenoid.set_value(false);
        }
    }
        pros::delay(25);
    }
}

void doorCallback(void* param){
    while (true){
        if (doorFlag.load()){

        if (doorState == true){
            doorSolenoid.set_value(true);
        }
        if (doorState == false){
            doorSolenoid.set_value(false);
        }
        }
        pros::delay(25);
    }
}

void descoreWingCallback(void* param){
    while (true){
        if (descoreWingFlag.load()){
        if (descoreWingState == true){
            descoreWingSolenoid.set_value(true);
        }
        if (descoreWingState == false){
            descoreWingSolenoid.set_value(false);
        }
        }
        pros::delay(25);
    }
}
