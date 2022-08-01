#include "aika.h"
#ifdef OLED_ENABLE
    #include "oled.h"
    #include "ocean_dream.h"
#endif

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
