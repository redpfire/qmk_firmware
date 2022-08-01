#include "aika.h"
#ifdef OLED_ENABLE
    #include "oled.h"
    #include "ocean_dream.h"
#endif

const uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM numbers_combo[] = {KC_H, KC_COMMA, COMBO_END};
const uint16_t PROGMEM numbers_combo_sym[] = {KC_AMPR, KC_CIRC, COMBO_END};
const uint16_t PROGMEM vim_combo[] = {KC_H, KC_COMMA, KC_DOT, COMBO_END};
const uint16_t PROGMEM vim_combo_sym[] = {KC_AMPR, KC_CIRC, KC_TILD, COMBO_END};
const uint16_t PROGMEM keylock_combo[] = {KC_X, KC_C, KC_D, COMBO_END};

combo_t key_combos[] = {
    [NUM_LAYER] = COMBO(numbers_combo, TO(3)),
    [NUM_LAYER_SYM] = COMBO(numbers_combo_sym, TO(3)),
    [VIM_LAYER] = COMBO(vim_combo_sym, TO(4)),
    [VIM_LAYER_SYM] = COMBO(vim_combo, TO(4)),
    [KEYLOCK_CAPS] = COMBO(keylock_combo, KC_CAPS),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case VIM_CW:
            SEND_STRING(":w\n");
            break;

        case VIM_QAE:
            SEND_STRING(":qa!\n");
            break;

        case VIM_FMT:
            SEND_STRING(":silent lua vim.lsp.buf.formatting()\n");
            break;

#ifdef OLED_ENABLE
        case KC_LCTL:
        case KC_RCTL:
            is_calm = record->event.pressed;
#endif
    }

    return true;
};
