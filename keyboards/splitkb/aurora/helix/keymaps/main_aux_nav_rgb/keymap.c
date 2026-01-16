#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#include "keymap.h"
#endif
#include "gpio.h"

enum layers {
    _BAS,
    _AUX,
    _NAV,
    _RGB,
    _PRS
};

// Define a new custom keycode for toggling the persistent layer
enum custom_keycodes {
    PERS_TG = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BAS] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                    KC_6,  KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                    KC_Y,  KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_LGUI, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                    KC_H,  KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,  KC_LBRC, KC_RBRC, KC_N,  KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
        KC_LCTL, KC_LBRC, KC_RBRC, KC_LALT, KC_LGUI, MO(1), KC_SPC,  KC_SPC,  MO(2), KC_RGUI, KC_RALT, KC_PMNS, KC_PPLS,  KC_RSFT
    ),

    [_AUX] = LAYOUT(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,         KC_F5,         KC_F6,                           KC_F7,   KC_F8,         KC_F9,         KC_F10,  KC_F11,  KC_F12,
        KC_GRV,  KC_TRNS, KC_TRNS, KC_BSLS,       LSFT(KC_BSLS), KC_TRNS,                         KC_CIRC, LSFT(KC_9),    LSFT(KC_0),    KC_TRNS, KC_TRNS, KC_BSPC,
        KC_CAPS, KC_TRNS, KC_TRNS, KC_MINS,       KC_EQL,        KC_BSLS,                         KC_TRNS, KC_LBRC,       KC_RBRC,       KC_TRNS, KC_TRNS, KC_BSLS,
        KC_TRNS, KC_TRNS, KC_TRNS, LSFT(KC_MINS), LSFT(KC_EQL),  LSFT(KC_NUHS), MS_BTN1, MS_BTN2, KC_TRNS, LSFT(KC_LBRC), LSFT(KC_RBRC), KC_TRNS, KC_TRNS, LSFT(KC_BSLS),
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS, KC_TRNS, MO(3),   KC_TRNS,       KC_TRNS,       KC_TRNS, KC_TRNS, KC_PSCR
    ),

    [_NAV] = LAYOUT(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        KC_TRNS, KC_7,    KC_8,    KC_9,    KC_TRNS, KC_TRNS,                   KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_TRNS, KC_BSPC,
        KC_TRNS, KC_4,    KC_5,    KC_6,    KC_TRNS, KC_TRNS,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS, KC_DEL,
        KC_TRNS, KC_1,    KC_2,    KC_3,    KC_TRNS, KC_TRNS, MS_BTN1, MS_BTN2, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_TRNS, KC_TRNS,
        KC_TRNS, KC_0,    KC_COMM, KC_DOT,  KC_TRNS, MO(3),   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_COMM, KC_DOT,  KC_TRNS
    ),

    [_RGB] = LAYOUT(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        KC_TRNS, QK_BOOT, KC_TRNS, EE_CLR,  KC_TRNS, KC_TRNS,                   KC_TRNS, QK_BOOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, AG_NORM,                   AG_SWAP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RM_TOGG,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MUTE, KC_TRNS, KC_TRNS, RM_SPDU, RM_HUEU, RM_SATU, RM_VALU,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RM_SPDD, RM_HUED, RM_SATD, RM_VALD
    ),

    [_PRS] = LAYOUT(
        KC_ESC,  LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5),                     LSFT(KC_6),  LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), LSFT(KC_0), KC_DEL,
        KC_TAB,  LSFT(KC_Q), LSFT(KC_W), LSFT(KC_E), LSFT(KC_R), LSFT(KC_T),                     LSFT(KC_Y),  KC_U,       KC_I,       KC_O,       KC_P,       KC_BSPC,
        KC_LGUI, KC_A,       KC_S,       KC_D,       KC_F,       KC_G,                           KC_H,        KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,
        KC_LSFT, KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       TG(_PRS), TG(_PRS), KC_N,        KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_ENT,
        KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    MO(1),      KC_TRNS,  KC_TRNS,  MO(2),       KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS
    )
};


#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BAS] = { ENCODER_CCW_CW(MS_WHLL, MS_WHLR), ENCODER_CCW_CW(MS_WHLU, MS_WHLD) }, // Mouse scroll left/right, up/down
    [_AUX] = { ENCODER_CCW_CW(MS_LEFT, MS_RGHT), ENCODER_CCW_CW(MS_UP, MS_DOWN) },
    [_NAV] = { ENCODER_CCW_CW(MS_LEFT, MS_RGHT), ENCODER_CCW_CW(MS_UP, MS_DOWN) },
    [_RGB] = { ENCODER_CCW_CW(RM_PREV, RM_NEXT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_PRS] = { ENCODER_CCW_CW(RM_PREV, RM_NEXT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
};
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case PERS_TG:
            if (record->event.pressed) {
                layer_invert(_PRS); // Toggle the persistent layer
            }
            return false;
        case KC_SPC:
            // Check if Layer 1 is active
            if (IS_LAYER_ON(_AUX) && record->event.pressed) {
                layer_invert(_PRS); // Toggle the persistent layer
                return false; // Don't send the Space key
            }
            return true; // Otherwise process Space normally
        default:
            return true;
    }
}

// Disable microcontroller power LEDs
// https://docs.splitkb.com/product-guides/liatris/power-led
void keyboard_pre_init_user(void) {
    gpio_set_pin_output(24);
    gpio_write_pin_high(24);
}

// Set lighting schema at startup
void eeconfig_init_user(void) {
    rgb_matrix_enable();
    rgb_matrix_mode(RGB_MATRIX_GRADIENT_UP_DOWN);
    rgb_matrix_sethsv(HSV_PURPLE);
}


// 0-5 are underglow LEDs
// For left split, indices look like this:
// 11 10  9  8  7  6
// 17 16 15 14 13 12
// 23 22 21 20 19 18
// 30 29 28 27 26 25 24
// 37 36 35 34 33 32 31
// TODO: to avoid led mirroring on both splits,
// either look into g_led_config or handedness
// Also check this: https://docs.qmk.fm/features/rgb_matrix
bool rgb_matrix_indicators_user(void) {
    const uint8_t r = 255;
    const uint8_t g = 255;
    const uint8_t b = 255;

    if (host_keyboard_led_state().caps_lock) {
        // Highlight bottom row when capslock is pressed
        rgb_matrix_set_color(37, r, g, b);
        rgb_matrix_set_color(36, r, g, b);
        rgb_matrix_set_color(35, r, g, b);
        rgb_matrix_set_color(34, r, g, b);
        rgb_matrix_set_color(33, r, g, b);
        rgb_matrix_set_color(32, r, g, b);
        rgb_matrix_set_color(31, r, g, b);
    }
    return false;
}

// // Light LEDs 9 & 10 in cyan when keyboard layer 1 (_AUX) is active
// const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {9, 2, HSV_CYAN}
// );
// // Light LEDs 11 & 12 in purple when keyboard layer 2 (_NAV) is active
// const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {11, 2, HSV_PURPLE}
// );
// // Light LEDs 13 & 14 in green when keyboard layer 3 (_RGB) is active
// const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {13, 2, HSV_GREEN}
// );
// // Light LEDs 0-5 in orange when keyboard layer 4 (_PERS) is active
// const rgblight_segment_t PROGMEM my_layer4_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {0, 6, HSV_ORANGE}
// );
//
// // Now define the array of layers. Later layers take precedence
// const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
//     my_capslock_layer,
//     my_layer1_layer,    // Overrides caps lock layer
//     my_layer2_layer,    // Overrides other layers
//     my_layer3_layer,    // Overrides other layers
//     my_layer4_layer     // Overrides other layers
// );
//
// void keyboard_post_init_user(void) {
//     // Enable the LED layers
//     rgblight_layers = my_rgb_layers;
// }
//
// // Layer state changed
// layer_state_t layer_state_set_user(layer_state_t state) {
//     // Both layers will light up if both kb layers are active
//     rgblight_set_layer_state(1, layer_state_cmp(state, _AUX));
//     rgblight_set_layer_state(2, layer_state_cmp(state, _NAV));
//     rgblight_set_layer_state(3, layer_state_cmp(state, _RGB));
//     rgblight_set_layer_state(4, layer_state_cmp(state, _PRS));
//     return state;
// }
//
// // LED update based on capslock state
// bool led_update_user(led_t led_state) {
//     rgblight_set_layer_state(0, led_state.caps_lock);
//     return true;
// }
