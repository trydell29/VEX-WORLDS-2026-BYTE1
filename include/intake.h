#include "main.h"

#pragma once

extern std::atomic<bool> intakeRunning;
extern std::atomic<bool> intakeSpitRunning;
extern std::atomic<bool> intakeFlag;
extern std::atomic<bool> outtakeRunning;

extern pros::Motor ml1;
extern pros::Motor ml2;
extern pros::Motor ml3;
extern pros::Motor ml4;
extern pros::Motor ml5;
extern pros::Motor ml6;

void runIntake();
void runIntakeSpit();
void runOuttake();
void stopIndexer();

void intakeCallback(void* param);