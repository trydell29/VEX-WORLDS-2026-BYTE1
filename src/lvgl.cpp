#include "main.h"

pros::Mutex lvglMutex;
std::atomic<bool> showLogoFlag{false};

void lvglTask(void*) {
    while (true){
        if (showLogoFlag.load()){
            logoDisplay();
            showLogoFlag.store(false);
        }
        lvglMutex.take(TIMEOUT_MAX);
        lv_tick_inc(5);
        lv_timer_handler();
        lvglMutex.give();
        pros::delay(5);
    }
}