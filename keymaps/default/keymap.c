#include QMK_KEYBOARD_H
/* #include "raw_hid.h" */
/* #include "quantum.h" */
 
#define _MAIN 0
#define _FN 1

#define ____ KC_TRNS
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_MAIN] = LAYOUT(
       	KC_B, KC_D, KC_F, ____,
        KC_A, KC_C, KC_E, KC_G
    ),

    [_FN] = LAYOUT(
        ____, ____, ____, ____,
        ____, ____, ____, ____
    ),

};

#ifdef OLED_ENABLE
void oled_task_user(void) {
  // Host Keyboard Layer Status
  oled_write_ln_P(PSTR("3by2"), false);
  oled_write_P(PSTR("Active layer: "), false);

  switch (get_highest_layer(layer_state)) {
    case _MAIN:
      oled_write_ln_P(PSTR("Main"), false);
      break;
    case _FN:
      oled_write_ln_P(PSTR("FN"), false);
      break;
    default:
      // Or use the write_ln shortcut over adding '\n' to the end of your string
      oled_write_ln_P(PSTR("N/A"), false);
  }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("Off"), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("Off"), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("Off"), false);
    
/*    return false; */
}
#endif
