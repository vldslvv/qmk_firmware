#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#    include "keymap.h"
#endif
#include "gpio.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                    KC_6,  KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
                 KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                    KC_Y,  KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
                 KC_LGUI, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                    KC_H,  KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
                 KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,  KC_LBRC, KC_RBRC, KC_N,  KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
                 // KC_LCTL, KC_LBRC, KC_RBRC, KC_LALT, MO(3),   MO(1), KC_SPC,  KC_SPC,  MO(2), KC_RGUI, KC_RALT, KC_MINS, KC_EQL,  MO(3)),
                 KC_LCTL, KC_LBRC, KC_RBRC, KC_LALT, KC_LGUI, MO(1), KC_SPC,  KC_SPC,  MO(2), KC_RGUI, KC_RALT, KC_MINS, KC_EQL,  KC_RCTL),

    [1] = LAYOUT(KC_F1,   KC_F2,   KC_F3,   KC_F4,         KC_F5,         KC_F6,                           KC_F7,   KC_F8,         KC_F9,         KC_F10,  KC_F11,  KC_F12,
                 KC_GRV,  KC_TRNS, KC_TRNS, KC_BSLS,       LSFT(KC_BSLS), KC_TRNS,                         KC_CIRC, LSFT(KC_9),    LSFT(KC_0),    KC_TRNS, KC_TRNS, KC_BSPC,
                 KC_CAPS, KC_TRNS, KC_TRNS, KC_MINS,       KC_EQL,        KC_BSLS,                         KC_TRNS, KC_LBRC,       KC_RBRC,       KC_TRNS, KC_TRNS, KC_BSLS,
                 KC_TRNS, KC_TRNS, KC_TRNS, LSFT(KC_MINS), LSFT(KC_EQL),  LSFT(KC_NUHS), MS_BTN1, MS_BTN2, KC_TRNS, LSFT(KC_LBRC), LSFT(KC_RBRC), KC_TRNS, KC_TRNS, LSFT(KC_BSLS),
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS, KC_TRNS, MO(3),   KC_TRNS,       KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS),

    [2] = LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSPC,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_TRNS, KC_DEL,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MS_BTN1, MS_BTN2, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(3),   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    [3] = LAYOUT(KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,
                 KC_TRNS, QK_BOOT, KC_TRNS, EE_CLR,  KC_TRNS, KC_TRNS,                   KC_TRNS, QK_BOOT, KC_TRNS, KC_TRNS, KC_TRNS,  KC_DEL,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, AG_NORM,                   AG_SWAP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  RGB_TOG,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_SPI, RGB_MOD,  RGB_HUI, RGB_SAI, RGB_VAI,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_SPD, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD)
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(MS_WHLL, MS_WHLR), ENCODER_CCW_CW(MS_WHLU, MS_WHLD) }, // Mouse scroll left/right, up/down
    [1] = { ENCODER_CCW_CW(MS_LEFT, MS_RGHT), ENCODER_CCW_CW(MS_UP, MS_DOWN) },
    [2] = { ENCODER_CCW_CW(MS_LEFT, MS_RGHT), ENCODER_CCW_CW(MS_UP, MS_DOWN) },
    [3] = { ENCODER_CCW_CW(UG_PREV, UG_NEXT), ENCODER_CCW_CW(KC_RGHT, KC_LEFT) },
};
#endif

// Disable microcontroller power LEDs
// https://docs.splitkb.com/product-guides/liatris/power-led
void keyboard_pre_init_user(void) {
    gpio_set_pin_output(24);
    gpio_write_pin_high(24);
}

// // Light LEDs 6 to 9 and 12 to 15 red when caps lock is active. Hard to ignore!
// const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {6, 4, HSV_RED},       // Light 4 LEDs, starting with LED 6
//     {12, 4, HSV_RED}       // Light 4 LEDs, starting with LED 12
// );
// // Light LEDs 9 & 10 in cyan when keyboard layer 1 is active
// const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {9, 2, HSV_CYAN}
// );
// // Light LEDs 11 & 12 in purple when keyboard layer 2 is active
// const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {11, 2, HSV_PURPLE}
// );
// // Light LEDs 13 & 14 in green when keyboard layer 3 is active
// const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {13, 2, HSV_GREEN}
// );
// //
// // Now define the array of layers. Later layers take precedence
// const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
//     my_capslock_layer,
//     my_layer1_layer,    // Overrides caps lock layer
//     my_layer2_layer,    // Overrides other layers
//     my_layer3_layer     // Overrides other layers
// );
//
// void keyboard_post_init_user(void) {
//     // Enable the LED layers
//     rgblight_layers = my_rgb_layers;
// }
//
