#pragma once

#include "main.h"

extern pros::Controller master;

extern lemlib::Chassis chassis;

extern std::atomic<bool> controllerAnalogFlag;

void controllerAnalogChecker(void* param); 