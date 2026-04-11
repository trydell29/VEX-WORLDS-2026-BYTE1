#pragma once

#include "main.h"

extern std::atomic<bool> liftState;
extern std::atomic<bool> liftFlag;
extern std::atomic<bool> loaderState;
extern std::atomic<bool> loaderFlag;
extern std::atomic<bool> doorState;
extern std::atomic<bool> doorFlag;

extern pros::ADIDigitalOut liftSolenoid;
extern pros::ADIDigitalOut loaderSolenoid;
extern pros::ADIDigitalOut doorSolenoid;

void liftCallback(void* param);
void loaderCallback(void* param);
void doorCallback(void* param);