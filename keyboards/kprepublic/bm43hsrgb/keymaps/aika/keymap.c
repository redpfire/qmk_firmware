/* Copyright 2021 bitstarr
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "aika.h"

const uint16_t PROGMEM layer_symbols_combo[]  = {KC_N, KC_E, COMBO_END};
const uint16_t PROGMEM layer_fun_combo[]  = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM layer_num_combo[]  = {KC_S, KC_T, COMBO_END};

const uint16_t PROGMEM dquote_combo[]  = {KC_R, KC_S, COMBO_END};
const uint16_t PROGMEM squote_combo[]  = {KC_E, KC_I, COMBO_END};

const uint16_t PROGMEM home_combo[]  = {KC_G, KC_M, COMBO_END};
const uint16_t PROGMEM end_combo[]  = {KC_V, KC_K, COMBO_END};
const uint16_t PROGMEM caps_word_combo[]  = {KC_X, KC_D, COMBO_END};

enum combos {
    NUM_LAYER_COMBO,
    SYM_LAYER_COMBO,
    FUN_LAYER_COMBO,
    DQUOTE_CMB,
    SQUOTE_CMB,
    HOME_CMB,
    END_CMB,
    CAPS_WORD_CMB,
    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

combo_t key_combos[] = {
    [SYM_LAYER_COMBO] = COMBO(layer_symbols_combo, OSL(_SYMBOLS)),
    [FUN_LAYER_COMBO] = COMBO(layer_fun_combo, OSL(_FUN)),
    [NUM_LAYER_COMBO] = COMBO(layer_num_combo, OSL(_NUM)),

    [DQUOTE_CMB] = COMBO(dquote_combo, KC_DQT),
    [SQUOTE_CMB] = COMBO(squote_combo, KC_QUOT),

    [HOME_CMB] = COMBO(home_combo, KC_HOME),
    [END_CMB] = COMBO(end_combo, KC_END),

    [CAPS_WORD_CMB] = COMBO(caps_word_combo, CW_TOGG),
};

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
  switch (index) {
      case NUM_LAYER_COMBO:
      case FUN_LAYER_COMBO:
        return 350;
      default:
        return COMBO_TERM;
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_ESC,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    TD(TD_MINUS),    KC_BSPC,
        LT(_NAVIGATION, KC_TAB),    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,
        LSFT_T(KC_Z),        KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H, KC_COMM,    RSFT_T(KC_DOT), KC_UP,   LT(_FUN, KC_SLSH),
        KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,                 KC_ENT,              KC_RALT,   KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [_SYMBOLS] = LAYOUT(
        _______, KC_AT, KC_LT,   KC_DLR, KC_GT,  KC_GRAVE, KC_PERC, KC_LBRC, KC_UNDS, KC_RBRC, KC_SCLN, _______,
        _______, KC_BSLS,   KC_LPRN,    KC_DQT,    KC_RPRN,    KC_HASH,    KC_EXLM,    KC_LCBR,    KC_EQL,    KC_RCBR,    KC_PIPE,
        _______, KC_COLON, KC_QUOTE, KC_ASTR, KC_PLUS, KC_QUES, KC_AMPR, KC_MINS, KC_TILD, KC_SLASH, _______,
        _______, _______, _______, _______,                 _______,              _______,   _______, _______, _______
    ),
    [_NUM] = LAYOUT(
        _______,   _______, _______, _______, _______, _______, _______, KC_7, KC_8, KC_9, _______, _______,
        _______,   _______, _______, _______, _______, _______, KC_0, KC_4, KC_5, KC_6, _______,
        _______,   _______, _______, _______, _______, _______, _______, KC_1, KC_2, KC_3, _______,
        _______, _______, _______, _______,                _______,             _______, _______, _______, _______
    ),
    [_NAVIGATION] = LAYOUT(
        _______, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, _______,
        _______,   _______, _______, _______, _______, _______, KC_H, KC_J, KC_K, KC_L, _______,
        _______,   _______, _______, _______, _______, _______, _______, _______, _______, KC_PGUP, _______,
        _______, _______, _______, _______,                _______,             _______, KC_HOME, KC_PGDN, KC_END
    ),
    [_FUN] = LAYOUT(
        QK_BOOT,   KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
        _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_F12,
        _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______,
        _______, _______, _______, _______,                _______,             _______, _______, _______, _______
    ),
};
