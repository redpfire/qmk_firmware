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

bool process_record_user(uint16_t keycode, keyrecord_t *record);
