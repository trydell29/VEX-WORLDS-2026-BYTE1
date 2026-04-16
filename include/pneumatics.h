#pragma once

#include "main.h"


extern std::atomic<bool> liftState;
extern std::atomic<bool> liftFlag;
extern std::atomic<bool> loaderState;
extern std::atomic<bool> loaderFlag;
extern std::atomic<bool> doorState;
extern std::atomic<bool> doorFlag;
extern std::atomic<bool> descoreWingState;
extern std::atomic<bool> descoreWingFlag;

extern pros::adi::DigitalOut liftSolenoid;
extern pros::adi::DigitalOut loaderSolenoid;
extern pros::adi::DigitalOut doorSolenoid;
extern pros::adi::DigitalOut descoreWingSolenoid;

void liftCallback(void* param);
void loaderCallback(void* param);
void doorCallback(void* param);
void descoreWingCallback(void* param);