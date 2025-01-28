// Copyright 2022 Piotr Szczurkowski (@redpfire)
// SPDX-License-Identifier: GPL-2.0-or-later
#include "aika.h"
#ifdef OLED_ENABLE
    #include "oled.h"
    #include "ocean_dream.h"
#endif

tap_dance_action_t tap_dance_actions[] = {
    [TD_QUOTE]      = ACTION_TAP_DANCE_DOUBLE(KC_QUOTE, KC_DQUO),
    [TD_SEMI]       = ACTION_TAP_DANCE_DOUBLE(KC_SEMICOLON, KC_COLON),
    [TD_BACKSLASH]  = ACTION_TAP_DANCE_DOUBLE(KC_BACKSLASH, KC_PIPE),
    [TD_EQUAL]      = ACTION_TAP_DANCE_DOUBLE(KC_EQUAL, KC_PLUS),
    [TD_MINUS]      = ACTION_TAP_DANCE_DOUBLE(KC_MINUS, KC_UNDERSCORE),
    [TD_GRAVE]      = ACTION_TAP_DANCE_DOUBLE(KC_TILDE, KC_GRAVE),
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
