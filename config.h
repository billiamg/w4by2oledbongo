#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xEEEE
#define PRODUCT_ID      0x2019
#define DEVICE_VER		0x0001
#define MANUFACTURER    Jan Lunge
#define PRODUCT         w3by2oled Rotary

/* key matrix size */
#define MATRIX_ROWS 2
#define MATRIX_COLS 4
#define MATRIX_ROW_PINS { F6, B2 }
#define MATRIX_COL_PINS { F7, B1, B3, B4 }
#define UNUSED_PINS

/*save space*/
#define NO_ACTION_ONESHOT

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5
#define VIAL_KEYBOARD_UID {0x6F, 0xD2, 0x03, 0xC4, 0x16, 0xAF, 0x61, 0x27}
#define VIAL_UNLOCK_COMBO_ROWS { 1, 0 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 1 }

#define ENCODERS_PAD_A { D3 }
#define ENCODERS_PAD_B { D2 }
#define VIAL_ENCODER_DEFAULT { KC_VOLD, KC_VOLU, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS }

#ifdef OLED_ENABLE
#   define OLED_DISPLAY_128X32
#   define OLED_TIMEOUT 60000
#	define OLED_BRIGHTNESS 10
#   define OLED_FONT_H "keyboards/w3by2oled/glcdfont.c"
#endif

/* oled */

/* #define I2C1_SCL_PIN D0 */
/*#define I2C1_SDA_PIN D1 */
/*#define OLED_BRIGHTNESS 128 */
/*#define OLED_DISPLAY_ADDRESS 0x3C */
/*#define OLED_FONT_H "glcdfont.c" */
/*#define OLED_FONT_START 0 */
/*#define OLED_FONT_END 0  */
/*#define OLED_FONT_WIDTH 6 */
/*#define OLED_FONT_HEIGH 8 */
/*#define OLED_TIMEOUT 600 */
/*#define OLED_IC OLED_IC_SSD1306 */

/* https://github.com/qmk/qmk_firmware/blob/master/keyboards/anavi/macropad8/config.h */

/* disable debug to save space*/
#ifndef NO_DEBUG
#define NO_DEBUG
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#define NO_PRINT
#endif // !NO_PRINT
