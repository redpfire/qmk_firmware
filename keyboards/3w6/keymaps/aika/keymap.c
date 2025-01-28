// Copyright 2022 Piotr Szczurkowski (@redpfire)
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H
#include "aika.h"

enum combos {
    NUM_LAYER_COMBO,
    VIM_LAYER_COMBO,
    FUN_LAYER_COMBO,
    NAV_LAYER_COMBO,

    OSL_NUM_LAYER_COMBO,
    OSL_VIM_LAYER_COMBO,
    OSL_FUN_LAYER_COMBO,
    OSL_NAV_LAYER_COMBO,

    DOUBLEQ_COMBO,
    SINGLEQ_COMBO,
    DEL_COMBO,
    CAPSWORD_COMBO,
    HOME_COMBO,
    END_COMBO,

    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

// quotes

const uint16_t PROGMEM doubleq_combo[]  = {KC_RALT_S, KC_LCTRL_T, COMBO_END};
const uint16_t PROGMEM singleq_combo[]  = {KC_RCTRL_N, KC_RALT_E, COMBO_END};

// layers

const uint16_t PROGMEM numbers_combo[] = {KC_RSHCTRL_M, KC_RCTRL_N, COMBO_END};
const uint16_t PROGMEM osl_numbers_combo[] = {KC_RSHCTRL_M, KC_RCTRL_N, KC_RALT_E, COMBO_END};

const uint16_t PROGMEM fun_combo[] = {KC_RSHALT_K, KC_LALT_H, COMBO_END};
const uint16_t PROGMEM osl_fun_combo[] = {KC_RSHALT_K, KC_LALT_H, KC_COMM, COMBO_END};

const uint16_t PROGMEM vim_combo[] = {KC_LALT_H, KC_COMM, COMBO_END};
const uint16_t PROGMEM osl_vim_combo[] = {KC_LALT_H, KC_COMM, KC_DOT, COMBO_END};

const uint16_t PROGMEM nav_combo[] = {KC_RCTRLALT_L, KC_U, COMBO_END};
const uint16_t PROGMEM osl_nav_combo[] = {KC_RCTRLALT_L, KC_U, KC_Y, COMBO_END};

// behavioral

const uint16_t PROGMEM del_combo[]        = {KC_RALT_S, KC_LSHCTRL_G, COMBO_END};
const uint16_t PROGMEM capsword_combo[]   = {KC_X, KC_LALT_D, COMBO_END};
const uint16_t PROGMEM home_combo[]       = {KC_LSHCTRL_G, KC_RSHCTRL_M, COMBO_END};
const uint16_t PROGMEM end_combo[]        = {KC_LSHALT_V, KC_RSHALT_K, COMBO_END};


combo_t key_combos[] = {
    [NUM_LAYER_COMBO] = COMBO(numbers_combo, TO(_SYMBOLS)),
    [VIM_LAYER_COMBO] = COMBO(vim_combo, TO(_VIM)),
    [FUN_LAYER_COMBO] = COMBO(fun_combo, TO(_FUN)),
    [NAV_LAYER_COMBO] = COMBO(nav_combo, TO(_NAVIGATION)),

    [OSL_NUM_LAYER_COMBO] = COMBO(osl_numbers_combo, OSL(_SYMBOLS)),
    [OSL_VIM_LAYER_COMBO] = COMBO(osl_vim_combo, OSL(_VIM)),
    [OSL_FUN_LAYER_COMBO] = COMBO(osl_fun_combo, OSL(_FUN)),
    [OSL_NAV_LAYER_COMBO] = COMBO(osl_nav_combo, OSL(_NAVIGATION)),

    [DOUBLEQ_COMBO] = COMBO(doubleq_combo, KC_DQUO),
    [SINGLEQ_COMBO] = COMBO(singleq_combo, KC_QUOT),
    [DEL_COMBO] = COMBO(del_combo, KC_DEL),
    [CAPSWORD_COMBO] = COMBO(capsword_combo, CW_TOGG),
    [HOME_COMBO] = COMBO(home_combo, KC_HOME),
    [END_COMBO] = COMBO(end_combo, KC_END),
};

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
  switch (index) {
      case NUM_LAYER_COMBO:
      case VIM_LAYER_COMBO:
      case FUN_LAYER_COMBO:
      case NAV_LAYER_COMBO:
      case OSL_NUM_LAYER_COMBO:
      case OSL_VIM_LAYER_COMBO:
      case OSL_FUN_LAYER_COMBO:
      case OSL_NAV_LAYER_COMBO:
        return 350;
      default:
        return COMBO_TERM;
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*  Layer 0 Colemak DH
*   _____________________________________________________________________     _____________________________________________________________________
*  |      Q      |      W      |  F          | P-ctrlalt   | B-gui       |   |  J-gui      | L-ctrltalt  |   U         |      Y      |      -      |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  |      A      |      R      |  S-altgr    | T-ctrl      | G-ctrlshift |   | M-ctrlshift |  N-ctrl     |   E-altgr   |      I      |      O      |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  |      Z      |      X      |      C      | D-alt       | V-SHALT     |   |   K-SHALT   |  H-ALT      |      ,<     |      .>     |      /?     |
*  '---------------------------|-------------|-------------|-------------|   |-------------|-------------|-------------|---------------------------'
*                              |    ESC      | SPACE       | TAB         |   | BACKSPACE   | ENTER       |   DEFAULT   |
*                              |_____________|_____________|_____________|   |_____________|_____________|_____________|
*/

[0] = LAYOUT(
  KC_Q, KC_W,   KC_F,       KC_LCTRLALT_P,      KC_LGUI_B,      /*-*/ KC_RGUI_J,    KC_RCTRLALT_L,      KC_U,       KC_Y,   TD(KC_MINS),
  KC_A, KC_R,   KC_RALT_S,  KC_LCTRL_T,         KC_LSHCTRL_G,   /*-*/ KC_RSHCTRL_M, KC_RCTRL_N,         KC_RALT_E,  KC_I,   KC_O,
  KC_Z, KC_X,   KC_C,       KC_LALT_D,          KC_LSHALT_V,    /*-*/ KC_RSHALT_K,  KC_LALT_H,          KC_COMM,    KC_DOT, KC_SLSH,
                KC_ESC,     LSFT_T(KC_SPACE),   KC_TAB,         /*-*/ KC_BSPC,      RSFT_T(KC_ENTER),   TO(_BASE)
),

/*  Layer 1 Symbol
*   _____________________________________________________________________     _____________________________________________________________________
*  |      !      |      @      |      #      |     $       |      %      |   |      ^      |       &     |      *      |      (      |      )      |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  |      1      |      2      |      3      |     4       |      5      |   |      6      |       7     |      8      |      9      |      0      |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  |     ` ~     |      +      |      =      |     ;       |      _      |   |     ' "     |      \ |    |      ,<     |      .>     |      /?     |
*  '---------------------------|-------------|-------------|-------------|   |-------------|-------------|-------------|---------------------------'
*                              |   KC_TRNS   |  KC_TRNS    |   KC_TRNS   |   |   KC_TNRS   |   KC_TRNS   |  KC_TRNS    |
*                              |_____________|_____________|_____________|   |_____________|_____________|_____________|
*/

[1] = LAYOUT(
  KC_EXLM,      KC_AT,   KC_HASH,       KC_DLR,         KC_PERC,        /*-*/ KC_CIRC,      KC_AMPR,            KC_ASTR,    TD(TD_BRACES),  TD(TD_RBRACES),
  KC_1,         KC_2,    KC_3,          KC_4,           KC_5,           /*-*/ KC_6,         KC_7,               KC_8,       KC_9,           KC_0,
  TD(TD_GRAVE), TD(KC_SEMICOLON), TD(TD_EQUAL),  KC_NO,   KC_UNDS,        /*-*/ TD(TD_QUOTE), TD(TD_BACKSLASH),   KC_TRNS,    KC_TRNS,        KC_TRNS,
                         KC_TRNS,       KC_TRNS,        KC_TRNS,        /*-*/ KC_TRNS,      KC_TRNS,            KC_TRNS
),

/*  Layer 2 Navigation TODO
*   _____________________________________________________________________     _____________________________________________________________________
*  |      !      |      @      |      #      |     $       |      %      |   |      ^      |       &     |      *      |      (      |      )      |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  |      1      |      2      |      3      |     4       |      5      |   |      6      |       7     |      8      |      9      |      0      |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  |     ` ~     |      +      |      =      |     ;       |      _      |   |     ' "     |      \ |    |      ,<     |      .>     |      /?     |
*  '---------------------------|-------------|-------------|-------------|   |-------------|-------------|-------------|---------------------------'
*                              |   KC_TRNS   |  KC_TRNS    |   KC_TRNS   |   |   KC_TNRS   |   KC_TRNS   |  KC_TRNS    |
*                              |_____________|_____________|_____________|   |_____________|_____________|_____________|
*/
/* [2] = LAYOUT( */
/* ), */

/*  Layer 3 Functions TODO
*   _____________________________________________________________________     _____________________________________________________________________
*  |      !      |      @      |      #      |     $       |      %      |   |      ^      |       &     |      *      |      (      |      )      |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  |      1      |      2      |      3      |     4       |      5      |   |      6      |       7     |      8      |      9      |      0      |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  |     ` ~     |      +      |      =      |     ;       |      _      |   |     ' "     |      \ |    |      ,<     |      .>     |      /?     |
*  '---------------------------|-------------|-------------|-------------|   |-------------|-------------|-------------|---------------------------'
*                              |   KC_TRNS   |  KC_TRNS    |   KC_TRNS   |   |   KC_TNRS   |   KC_TRNS   |  KC_TRNS    |
*                              |_____________|_____________|_____________|   |_____________|_____________|_____________|
*/
/* [3] = LAYOUT( */
/* ), */

/*  Layer 4 VIM
*   _____________________________________________________________________     _____________________________________________________________________
*  |             |             |             |             |             |   |             |             |             |             |             |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  |             |             |             |             |             |   |             |      H      |      J      |      K      |      L      |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  |             |             |             |             |             |   |             |             |             |             |             |
*  '---------------------------|-------------|-------------|-------------|   |-------------|-------------|-------------|---------------------------'
*                              |   KC_TRNS   |  KC_TRNS    |   KC_TRNS   |   |   KC_TNRS   |   KC_TRNS   |  KC_TRNS    |
*                              |_____________|_____________|_____________|   |_____________|_____________|_____________|
*/
[4] = LAYOUT(
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_H,   KC_J,    KC_K,    KC_L,    KC_NO,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
};

/* const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { */
/*     [0] = LAYOUT(KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_MINS, */
/*                  LALT_T(KC_A), RALT_T(KC_R), LSFT_T(KC_S), LCTL_T(KC_T), KC_G, */
/*                  KC_M, LCTL_T(KC_N), LSFT_T(KC_E), RALT_T(KC_I), LALT_T(KC_O), */
/*                  KC_Z, KC_X, KC_C, KC_D, KC_V, KC_K, KC_H, KC_COMM, KC_DOT, */
/*                  KC_SLSH, LGUI_T(KC_ESC), LT(2, KC_SPC), KC_TAB, KC_BSPC, */
/*                  KC_ENT, TO(1)), */
/*     [1] = LAYOUT(KC_AT, KC_LT, KC_DLR, KC_GT, KC_GRV, KC_PERC, KC_LBRC, KC_UNDS, */
/*                  KC_RBRC, KC_SCLN, KC_BSLS, KC_LPRN, KC_DQUO, KC_RPRN, KC_HASH, */
/*                  KC_EXLM, KC_LCBR, KC_EQL, KC_RCBR, KC_PIPE, KC_NO, KC_COLN, */
/*                  KC_QUOT, KC_ASTR, KC_PLUS, KC_QUES, KC_AMPR, KC_CIRC, KC_TILD, */
/*                  KC_SLSH, TO(0), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO), */
/*     [2] = LAYOUT(KC_NO, KC_VOLD, KC_MUTE, KC_VOLU, KC_NO, KC_NO, KC_PGDN, KC_UP, */
/*                  KC_PGUP, KC_DEL, LALT_T(KC_MPRV), KC_MPLY, LSFT_T(KC_MSTP), */
/*                  LCTL_T(KC_MNXT), KC_NO, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, */
/*                  KC_END, KC_NO, KC_NO, KC_NO, KC_PSCR, KC_NO, KC_NO, KC_NO, */
/*                  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO), */
/*     [3] = LAYOUT(KC_NO, KC_F9, KC_F10, KC_F11, KC_F12, KC_PPLS, KC_7, KC_8, */
/*                  KC_9, KC_PSLS, KC_NO, KC_F5, KC_F6, KC_F7, KC_F8, KC_0, LCTL_T(KC_4), */
/*                  LSFT_T(KC_5), LALT_T(KC_6), KC_DOT, KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_PMNS, */
/*                  KC_1, KC_2, KC_3, KC_PAST, TO(0), TO(1), KC_TRNS, KC_TRNS, */
/*                  KC_TRNS, KC_NO), */
/*     [4] = LAYOUT(KC_NO, KC_1, KC_2, KC_3, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, */
/*                  KC_NO, KC_LALT, KC_4, LSFT_T(KC_5), LCTL_T(KC_6), KC_0, KC_H, */
/*                  KC_J, KC_K, KC_L, KC_NO, KC_NO, KC_7, KC_8, KC_9, KC_NO, KC_NO, */
/*                  KC_NO, KC_NO, KC_NO, KC_NO, TO(0), KC_TRNS, KC_TRNS, KC_TRNS, */
/*                  KC_TRNS, KC_NO)}; */
