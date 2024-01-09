// Copyright 2022 Piotr Szczurkowski (@redpfire)
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

#include "quantum.h"

enum layers {
    _BASE,
    _SYMBOLS,
    _NAVIGATION,
    _NUMPAD,
    _VIM,
};

enum combos {
    NUM_LAYER,
    NUM_LAYER_SYM,
    VIM_LAYER,
    VIM_LAYER_SYM,
    KEYLOCK_CAPS,
    COMBO_LENGTH
};

extern combo_t key_combos[COMBO_LENGTH];
