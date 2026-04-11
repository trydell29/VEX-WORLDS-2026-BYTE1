#include "main.h"

static lv_obj_t* scr = nullptr;
static lv_obj_t* logoScr = nullptr;

static lv_obj_t* btnLeft = nullptr;
static lv_obj_t* btnRight = nullptr;

static lv_obj_t* labelLeft = nullptr;
static lv_obj_t* labelRight = nullptr;

std::atomic<int> auton = 0;

void selectorEvent(lv_event_t * e){
    if(lv_event_get_code(e) == LV_EVENT_PRESSED){
        int autonNumber = (int)(uintptr_t) lv_event_get_user_data(e);
        auton.store(autonNumber);

        lv_label_set_text(lv_obj_get_child(btnLeft, 0),  autonNumber == 1 ? "Left Selected"  : "Left");
        lv_label_set_text(lv_obj_get_child(btnRight, 0), autonNumber == 2 ? "Right Selected" : "Right");

        printf("Auton set to %d\n", autonNumber);
    }
}

void selectorButtons(void){

    lvglMutex.take(TIMEOUT_MAX);

    scr = lv_obj_create(nullptr);
    lv_obj_set_style_bg_color(scr, lv_color_hex(0xB0E0E6), LV_PART_MAIN);
    lv_screen_load(scr);

    btnLeft = lv_button_create(scr);
    lv_obj_set_pos(btnLeft, 80, 80);
    lv_obj_set_size(btnLeft, 100, 80);
    lv_obj_set_style_bg_color(btnLeft, lv_color_hex(0xFF991C), LV_PART_MAIN);
    lv_obj_add_event_cb(btnLeft, selectorEvent, LV_EVENT_PRESSED, (void *)1);

    lv_obj_t * labelLeft = lv_label_create(btnLeft);
    lv_label_set_text(labelLeft, "Left");
    lv_obj_center(labelLeft);

    btnRight = lv_button_create(scr);
    lv_obj_set_pos(btnRight, 300, 80);
    lv_obj_set_size(btnRight, 100, 80);
    lv_obj_set_style_bg_color(btnRight, lv_color_hex(0x800080), LV_PART_MAIN);
    lv_obj_add_event_cb(btnRight, selectorEvent, LV_EVENT_PRESSED, (void *)2);

    lv_obj_t * labelRight = lv_label_create(btnRight);
    lv_label_set_text(labelRight, "Right");
    lv_obj_center(labelRight);

    lvglMutex.give();

}

void logoDisplay(void){

    lv_obj_t* logoScr = lv_obj_create(nullptr);
    lv_screen_load(logoScr);

    lv_obj_t* img = lv_image_create(logoScr);
    lv_image_set_src(img, &bulldogBackground);
    lv_obj_center(img);

}