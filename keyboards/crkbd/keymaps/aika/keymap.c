#include QMK_KEYBOARD_H
#include "aika.h"

#define LALTA LALT_T(KC_A)
#define LALTO LALT_T(KC_O)
#define LALTMPRV LALT_T(KC_MPRV)

#define RALTR RALT_T(KC_R)
#define RALTI RALT_T(KC_I)

#define LSFTS LSFT_T(KC_S)
#define LSFTE LSFT_T(KC_E)
#define LSFTMSTP LSFT_T(KC_MSTP)
#define LSFT5 LSFT_T(KC_5)

#define LCTLT LCTL_T(KC_T)
#define LCTLN LCTL_T(KC_N)
#define LCTLMNXT LCTL_T(KC_MNXT)
#define LCTL6 LCTL_T(KC_6)

#define GUI_ESC LGUI_T(KC_ESC)
#define L2_SPC LT(2, KC_SPC)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// [_BASE] = LAYOUT_split_3x6_3(
//   LLOCK,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    OSMLGUI,
//   OSMLCTL, KC_A,   SFT_S,   ALT_D,   CTL_F,   KC_G,                         KC_H,    CTL_J,   ALT_K,   SFT_L,   TD_QUOT, OSMRALT,
//   OSMLALT, KC_Z,   KC_X,    KC_C,    GUI_V,   KC_B,                         KC_N,    GUI_M,   KC_COMM, KC_DOT,  KC_SLSH, OSMRCTL,
//                                      MOD_KEY, TAB_NUM, CAP_KEY,    BSP_SYM, SPC_MAC, ENT_FUN
// ),

[_BASE] = LAYOUT_split_3x6_3(
  _______, KC_Q,   KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y,    KC_MINS, _______,
  _______, LALTA,  RALTR,   LSFTS,   LCTLT,   KC_G,                         KC_M,    LCTLN,   LSFTE,   RALTI,   LALTO,   _______,
  _______, KC_Z,   KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, _______,
                                     GUI_ESC, L2_SPC,  KC_TAB,     KC_BSPC, KC_ENT,  TO(1)
),

[_SYMBOLS] = LAYOUT_split_3x6_3(
  _______, KC_AT,   KC_LT,   KC_DLR,  KC_GT,   KC_GRV,                      KC_PERC, KC_LBRC, KC_UNDS, KC_RBRC, KC_SCLN, _______,
  _______, KC_BSLS, KC_LPRN, KC_DQUO, KC_RPRN, KC_HASH,                     KC_EXLM, KC_LCBR, KC_EQL,  KC_RCBR, KC_PIPE, _______,
  _______, _______, KC_COLN, KC_QUOT, KC_ASTR, KC_PLUS,                     KC_QUES, KC_AMPR, KC_CIRC, KC_TILD, KC_SLSH, _______,
                                     TO(0),   KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, _______
),

[_NAVIGATION] = LAYOUT_split_3x6_3(
  _______, _______, KC_VOLD, KC_MUTE, KC_VOLU, _______,                     _______, KC_PGDN, KC_UP,   KC_PGUP, KC_DEL,  _______,
  _______, LALTMPRV,KC_MPLY, LSFTMSTP, LCTLMNXT, _______,                   KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  _______,
  _______, _______, _______, _______, KC_PSCR, _______,                     _______, _______, _______, _______, _______, _______,
                                     _______, _______, _______,     _______, _______, _______
),

[_NUMPAD] = LAYOUT_split_3x6_3(
  _______, _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,                      KC_PPLS, KC_7,    KC_8,    KC_9,    KC_PSLS, _______,
  _______, _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,                       KC_0,    KC_4,    KC_5,    KC_6,    KC_DOT,  _______,
  _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,                       KC_PMNS, KC_1,    KC_2,    KC_3,    KC_4,    _______,
                                     TO(0),   TO(1),   KC_TRNS,     KC_TRNS, KC_TRNS, _______
),

[_VIM] = LAYOUT_split_3x6_3(
  _______, _______, KC_7,    KC_8,    KC_9,    _______,                     _______, _______, _______, _______, VIM_QAE, _______,
  _______, KC_LALT, KC_4,    LSFT5,   LCTL6,   KC_0,                        KC_H,    KC_J,    KC_K,    KC_L,    VIM_CW,  _______,
  _______, _______, KC_1,    KC_2,    KC_3,    _______,                     _______, _______, _______, _______, VIM_FMT, _______,
                                     TO(0),   KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, _______
),

};

// clang-format on
