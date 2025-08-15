/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#define CTL_ESC MT(MOD_LCTL, KC_ESC)
// Those work on US international keyboard layout
#define SHARPS ALGR(KC_S)
#define AE ALGR(KC_Q)
#define OE ALGR(KC_P)
#define UE ALGR(KC_Y)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      CTL_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,  KC_LALT, MO(1),     MO(2),     KC_SPC,  KC_ENT
                                      //`--------------------------'  `--------------------------'

  ),

    [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______,  SHARPS,      UE,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT,      OE,      AE,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, KC_LBRC, KC_RBRC, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         _______, _______,  _______,    MO(3), _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_GRV,  KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TILD,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,   KC_0,  _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_BSLS, _______, _______,  KC_EQL, KC_PLUS,                     KC_MINUS, KC_UNDS, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,   MO(3),    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RM_TOGG, RM_HUEU, RM_SATU, RM_VALU, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RM_NEXT, RM_HUED, RM_SATD, RM_VALD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  )
};
// clang-format on
#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] =
        {
            ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
            ENCODER_CCW_CW(KC_MPRV, KC_MNXT),
            ENCODER_CCW_CW(RM_VALD, RM_VALU),
            ENCODER_CCW_CW(KC_RGHT, KC_LEFT),
        },
    [1] =
        {
            ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
            ENCODER_CCW_CW(KC_MPRV, KC_MNXT),
            ENCODER_CCW_CW(RM_VALD, RM_VALU),
            ENCODER_CCW_CW(KC_RGHT, KC_LEFT),
        },
    [2] =
        {
            ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
            ENCODER_CCW_CW(KC_MPRV, KC_MNXT),
            ENCODER_CCW_CW(RM_VALD, RM_VALU),
            ENCODER_CCW_CW(KC_RGHT, KC_LEFT),
        },
    [3] =
        {
            ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
            ENCODER_CCW_CW(KC_MPRV, KC_MNXT),
            ENCODER_CCW_CW(RM_VALD, RM_VALU),
            ENCODER_CCW_CW(KC_RGHT, KC_LEFT),
        },
};
#endif

#ifdef OLED_ENABLE
#    include "oled_driver.h"
#    include "images.h"

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

void oled_render_layer_state(void) {
    oled_write_P(PSTR("LAYER\n"), false);
    oled_advance_page(false);
    oled_advance_page(false);
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_raw_P(layer_1, sizeof(layer_1));
            oled_set_cursor(0, 10);
            oled_write_raw_P(sym_layer_1, sizeof(sym_layer_1));
            oled_set_cursor(0, 14);
            oled_write_P(PSTR("BASE\n"), false);
            break;
        case 1:
            oled_write_raw_P(layer_2, sizeof(layer_2));
            oled_set_cursor(0, 10);
            oled_write_raw_P(sym_layer_2, sizeof(sym_layer_2));
            oled_set_cursor(0, 14);
            oled_write_P(PSTR(" NAV\n"), false);
            break;
        case 2:
            oled_write_raw_P(layer_3, sizeof(layer_3));
            oled_set_cursor(0, 10);
            oled_write_raw_P(sym_layer_3, sizeof(sym_layer_3));
            oled_set_cursor(0, 14);
            oled_write_P(PSTR(" SYM\n"), false);
            break;
        case 3:
            oled_write_raw_P(layer_4, sizeof(layer_4));
            oled_set_cursor(0, 10);
            oled_write_raw_P(sym_layer_4, sizeof(sym_layer_4));
            oled_set_cursor(0, 14);
            oled_write_P(PSTR(" ADJ\n"), false);
            break;
        default:
            oled_write_raw_P(layer_1, sizeof(layer_1));
            oled_set_cursor(0, 10);
            oled_write_raw_P(sym_layer_1, sizeof(sym_layer_1));
            oled_set_cursor(0, 14);
            oled_write_P(PSTR("???\n"), false);
            break;
    }
}

void oled_render_wpm_gauge(void) {
    const uint8_t wpm = get_current_wpm();
    oled_write_P(PSTR(" WPM"), false);
    oled_advance_page(false);
    oled_write(get_u8_str(wpm, ' '), false);
    oled_advance_page(false);
    oled_advance_page(false);
    if (wpm < 25) {
        oled_write_raw_P(gauge_0, sizeof(gauge_0));
        return;
    }
    if (wpm < 50) {
        oled_write_raw_P(gauge_1, sizeof(gauge_1));
        return;
    }
    if (wpm < 75) {
        oled_write_raw_P(gauge_2, sizeof(gauge_2));
        return;
    }
    if (wpm < 100) {
        oled_write_raw_P(gauge_3, sizeof(gauge_3));
        return;
    } else {
        oled_write_raw_P(gauge_4, sizeof(gauge_4));
        return;
    }
}

void oled_render_aum(void) {
    oled_write_raw_P(aum, sizeof(aum));
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_set_cursor(0, 0);
        oled_render_aum();
        oled_set_cursor(0, 9);
        oled_render_wpm_gauge();
    } else {
        oled_render_layer_state();
    }
    return false;
}
#endif
