#include "main.h"

extern pros::Mutex lvglMutex;
extern std::atomic<bool> showLogoFlag;

void lvglTask(void* param);