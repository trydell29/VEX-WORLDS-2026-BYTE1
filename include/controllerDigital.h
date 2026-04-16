#include "main.h"



#pragma once


extern pros::Controller master;

extern std::atomic<bool> controllerDigitalFlag;

void controllerDigitalChecker(void* param); 