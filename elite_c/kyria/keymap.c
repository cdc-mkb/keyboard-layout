/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#ifdef OSX
#include "keymap_german_osx.h"
#else
#include "keymap_german.h"
#endif

enum layers {
    _MINE = 0,
    _SYM,
    _NUM,
    _FUN
};

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MINE] = LAYOUT(
       _______,        DE_Z,        DE_L,    DE_U,            DE_A,     DE_J,                                                DE_W,        DE_B,        DE_D,       DE_G,         DE_Y, _______,
       _______, CTL_T(DE_C), ALT_T(DE_R), GUI_T(DE_I), SFT_T(DE_E),     DE_O,                                                DE_M, SFT_T(DE_N), GUI_T(DE_T), ALT_T(DE_S), CTL_T(DE_H), _______,
       _______,        DE_V,        DE_X,   OSL(_NUM),      KC_DOT,     DE_Q, _______, _______, _______,   _______,          DE_W,        DE_F,   OSL(_NUM),     KC_COMM,        DE_K, _______,
                                              _______,     _______,   KC_SPC, KC_BSPC, _______, _______, OSL(_SYM), OSM(MOD_LSFT),     _______,     _______
    ),

    [_SYM] = LAYOUT(
       _______,        DE_EURO,        DE_UNDS,        DE_LBRC,        DE_RBRC, DE_ACUT,                                        DE_EXLM,        DE_LABK,        DE_RABK,         DE_EQL,          DE_AT, _______,
       _______, CTL_T(DE_BSLS), ALT_T(DE_SLSH), GUI_T(DE_LCBR), SFT_T(DE_RCBR), DE_ASTR,                                        DE_QUES, SFT_T(DE_LPRN), GUI_T(DE_RPRN), ALT_T(DE_MINS), CTL_T(DE_COLN), _______,
       _______,        DE_HASH,         DE_DLR,        DE_PIPE,        DE_TILD,  DE_GRV, _______, _______, _______,   _______,  DE_PLUS,        DE_PERC,        DE_DQUO,        DE_QUOT,        DE_SCLN, _______,
                                                       _______,        _______, _______, _______, _______, _______, OSL(_FUN), TO(_MINE),       _______,        _______
    ),

    [_NUM] = LAYOUT(
       _______, KC_PGDN, KC_DEL, KC_UP, KC_BSPC, KC_PGUP,/*                                        */  KC_PEQL,    KC_P7,    KC_P8,    KC_P9, KC_PSLS, _______,
       _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END,/*                                        */  KC_PPLS,    KC_P4,    KC_P5,    KC_P6,    KC_P0, _______,
       _______, KC_ESC, KC_TAB, TO(_NUM),  KC_ENT, TO(_MINE), _______, _______,/*    */  _______, _______, KC_PMNS,    KC_P1,    KC_P2,    KC_P3, KC_PAST, _______,
                         _______, _______,  DE_ADIA, DE_ODIA, _______,/*    */  _______, DE_UDIA, DE_SS, _______, _______
    ),

    [_FUN] = LAYOUT(
       _______, _______, _______, KC_BRMD, KC_BRMU, _______,/*                                        */  _______, KC_F7, KC_F8, KC_F9,KC_F12, _______,
       _______,   KC_MPRV, KC_MNXT, KC_VOLD, KC_VOLU, _______,/*                                        */  _______, KC_F4, KC_F5, KC_F6, KC_F10, _______,
       _______, _______, _______, KC_MPLY, KC_MUTE, _______, _______, _______,/*    */  _______, _______,  _______, KC_F1, KC_F2, KF_C3, KC_F11, _______,
                         _______, _______,  _______, _______, _______,/*    */  _______, _______, _______, _______, _______
    ),

};

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
   return true;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
  /* With an if statement we can check which encoder was turned. */
  if (index == 0) { /* First encoder */
    /* And with another if statement we can check the direction. */
    if (clockwise) {
      /* This is where the actual magic happens: this bit of code taps on the
         Page Down key. You can do anything QMK allows you to do here.
         You'll want to replace these lines with the things you want your
         encoders to do. */
      tap_code(KC_RIGHT);
    } else {
      /* And likewise for the other direction, this time Page Down is pressed. */
      tap_code(KC_LEFT);
    }
  /* You can copy the code and change the index for every encoder you have. Most
     keyboards will only have two, so this piece of code will suffice. */
  } else if (index == 1) { /* Second encoder */
    if (clockwise) {
      tap_code(KC_WH_D);
    } else {
      tap_code(KC_WH_U);
    }
  }
  return true;
}