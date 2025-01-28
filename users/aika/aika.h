// Copyright 2022 Piotr Szczurkowski (@redpfire)
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

#include "quantum.h"

#define KC_LCTRL_T       MT(MOD_LCTL, KC_T)
#define KC_RCTRL_N       MT(MOD_RCTL, KC_N)
#define KC_LALT_D        MT(MOD_LALT, KC_D)
#define KC_LALT_H        MT(MOD_LALT, KC_H)
#define KC_RALT_S        MT(MOD_RALT, KC_S)
#define KC_RALT_E        MT(MOD_RALT, KC_E)
#define KC_LGUI_B        MT(MOD_LGUI, KC_B)
#define KC_RGUI_J        MT(MOD_LGUI, KC_J)

#define KC_LSHCTRL_G     MT(MOD_LCTL | MOD_LSFT, KC_G)
#define KC_RSHCTRL_M     MT(MOD_RCTL | MOD_RSFT, KC_M)
#define KC_LSHALT_V     MT(MOD_LALT | MOD_LSFT, KC_V)
#define KC_RSHALT_K     MT(MOD_LALT | MOD_LSFT, KC_K)

#define KC_LCTRLALT_P    MT(MOD_LCTL | MOD_LALT, KC_P)
#define KC_RCTRLALT_L    MT(MOD_RCTL | MOD_LALT, KC_L)

enum layers {
    _BASE,
    _SYMBOLS,
    _NUM,
    _NAVIGATION,
    _FUN,
};

enum tapdances {
  TD_QUOTE,
  TD_SEMI,
  TD_BACKSLASH,
  TD_EQUAL,
  TD_MINUS,
  TD_COMMA,
  TD_SLASH,
  TD_GRAVE,
  TD_BRACES,
  TD_RBRACES,
  TAPDANCE_LENGTH
};

extern tap_dance_action_t tap_dance_actions[TAPDANCE_LENGTH];
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record);
bool caps_word_press_user(uint16_t keycode);
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record);

void dance_braces_finished(tap_dance_state_t *state, void *user_data);
void dance_braces_reset(tap_dance_state_t *state, void *user_data);
void dance_rbraces_finished(tap_dance_state_t *state, void *user_data);
void dance_rbraces_reset(tap_dance_state_t *state, void *user_data);
