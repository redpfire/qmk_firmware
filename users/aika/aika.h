#pragma once

#include "quantum.h"

enum layers {
    _BASE,
    _SYMBOLS,
    _NAVIGATION,
    _NUMPAD,
    _VIM,
};

enum custom_keycodes {
    VIM_CW = SAFE_RANGE,
    VIM_FMT,
    VIM_QAE,
};

enum combo_events {
    NUM_LAYER,
    NUM_LAYER_SYM,
    VIM_LAYER,
    VIM_LAYER_SYM,
    KEYLOCK_CAPS,
    COMBO_LENGTH
};

bool process_record_user(uint16_t keycode, keyrecord_t *record);
