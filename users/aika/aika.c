// Copyright 2022 Piotr Szczurkowski (@redpfire)
// SPDX-License-Identifier: GPL-2.0-or-later
#include "aika.h"
#ifdef OLED_ENABLE
    #include "oled.h"
    #include "ocean_dream.h"
#endif

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

tap_dance_action_t tap_dance_actions[] = {
    [TD_QUOTE]      = ACTION_TAP_DANCE_DOUBLE(KC_QUOTE, KC_DQUO),
    [TD_SEMI]       = ACTION_TAP_DANCE_DOUBLE(KC_SEMICOLON, KC_COLON),
    [TD_BACKSLASH]  = ACTION_TAP_DANCE_DOUBLE(KC_BACKSLASH, KC_PIPE),
    [TD_EQUAL]      = ACTION_TAP_DANCE_DOUBLE(KC_EQUAL, KC_PLUS),
    [TD_MINUS]      = ACTION_TAP_DANCE_DOUBLE(KC_MINUS, KC_UNDERSCORE),
    [TD_GRAVE]      = ACTION_TAP_DANCE_DOUBLE(KC_GRAVE, KC_TILDE),
    [TD_BRACES]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_braces_finished, dance_braces_reset),
    [TD_RBRACES]    = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_rbraces_finished, dance_braces_reset),
};

void dance_braces_finished(tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code16(KC_LPRN); // One tap for Left Parenthesis
  } else if (state->count == 2) {
    register_code16(KC_LBRC); // Two taps for Left Bracket
  } else if (state->count == 3) {
    register_code16(KC_LCBR); // Three taps for Left Curly Brace
  }
}

void dance_braces_reset(tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code16(KC_LPRN);
  } else if (state->count == 2) {
    unregister_code16(KC_LBRC);
  } else if (state->count == 3) {
    unregister_code16(KC_LCBR);
  }
}

void dance_rbraces_finished(tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code16(KC_RPRN); // One tap for Left Parenthesis
  } else if (state->count == 2) {
    register_code16(KC_RBRC); // Two taps for Left Bracket
  } else if (state->count == 3) {
    register_code16(KC_RCBR); // Three taps for Left Curly Brace
  }
}

void dance_rbraces_reset(tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code16(KC_RPRN);
  } else if (state->count == 2) {
    unregister_code16(KC_RBRC);
  } else if (state->count == 3) {
    unregister_code16(KC_RCBR);
  }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_SPACE):
        case RSFT_T(KC_ENTER):
            // Immediately select the hold action when another key is pressed.
             return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

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

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;
        // Keycodes that continue Caps Word, without shifting.
        case KC_BSPC:
        case KC_DEL:
            return true;
        default:
            return false;  // Deactivate Caps Word.
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_LGUI_B:
        case KC_RGUI_J:
            return 500;
        default:
            return TAPPING_TERM;
    }
}
