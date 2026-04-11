#pragma once

#include "main.h"

extern pros::Controller master;

extern std::atomic<bool> controllerDigitalFlag;

void controllerDigitalChecker(void* param); 