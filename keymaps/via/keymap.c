#include QMK_KEYBOARD_H
#include "raw_hid.h"
#include "quantum.h"


#define ____ KC_TRNS
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
       	KC_B, KC_D, KC_F, ____,
        KC_A, KC_C, KC_E, KC_MUTE
    ),

    [1] = LAYOUT(
        ____, ____, ____, ____,
        ____, ____, ____, ____
    ),

    [2] = LAYOUT(
        ____, ____, ____, ____,
        ____, ____, ____, ____
    ),

    [3] = LAYOUT(
        ____, ____, ____, ____,
        ____, ____, ____, ____

    ),

};

void raw_hid_receive_kb(uint8_t *data, uint8_t length) {
    if(data[0] == 0xFC){
        switch (data[1]) {
            case 0x01:{
                // move to layer
                data[1] = 0xFD;
                layer_move(data[2]);
                break;
            }
            case 0x02:{
                // turn on layer
                data[1] = 0xFD;
                layer_on(data[2]);
                break;
            }
            case 0x03:{
                // turn off layer
                data[1] = 0xFD;
                layer_off(data[2]);
                break;
            }
        }
    }
    raw_hid_send(data, length);
}



/*#ifdef OLED_ENABLE

void oled_task_user(void) {
 // Host Keyboard Layer Status
  oled_write_ln_P(PSTR("3by2"), false);
  oled_write_P(PSTR("Active layer: "), false);

  switch (get_highest_layer(layer_state)) {
    case 0:
      oled_write_ln_P(PSTR("Main"), false);
      break;
    case 1:
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
*/    
/*    return false; */
/*} 
#endif */
