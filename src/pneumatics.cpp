#include "main.h"

std::atomic<bool> liftState{false}; 
std::atomic<bool> liftFlag{false};
std::atomic<bool> loaderState{false}; 
std::atomic<bool> loaderFlag{false};
std::atomic<bool> doorState{false}; 
std::atomic<bool> doorFlag{false};

pros::ADIDigitalOut liftSolenoid('A');
pros::ADIDigitalOut loaderSolenoid('B');
pros::ADIDigitalOut doorSolenoid('C');

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
