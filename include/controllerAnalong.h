#include "main.h"



#pragma once


extern pros::Controller master;

extern lemlib::Chassis chassis;

extern std::atomic<bool> controllerAnalogFlag;

void controllerAnalogChecker(void* param); 