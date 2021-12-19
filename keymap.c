/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"
#include "keymap_german.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _UMLAUT,
  _PLOVER,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  PLOVER,
  BACKLIT,
  EXT_PLV
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define UMLAUT MO(_UMLAUT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |  ß ? | + *  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  - _ |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt |  Gui  |Umlaut| Lower|   Space     | Raise| Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_ESC,  DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,    DE_Z,    DE_U,    DE_I,    DE_O,    DE_P,    KC_BSPC,
    KC_TAB,  DE_A,    DE_S,    DE_D,    DE_F,    DE_G,    DE_H,    DE_J,    DE_K,    DE_L,    DE_SS, KC_RBRC,
    KC_LSFT, DE_Y,    DE_X,    DE_C,    DE_V,    DE_B,    DE_N,    DE_M,    DE_COMM, DE_DOT,  DE_MINS, KC_ENT ,
    KC_LCTL, KC_LGUI, KC_LALT, UMLAUT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Umlaut
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |   Ü  |      |  Ö   |      | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  Ä   |  ß   |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_UMLAUT] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______,  _______, _______, DE_UDIA,   _______,    DE_ODIA, _______, KC_BSPC,
    _______,  DE_ADIA,  DE_SS, _______, _______, _______, _______, _______, _______,    _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______,  _______,
    _______, _______, _______, _______, _______, _______, _______, _______,    _______,    _______, _______, _______
),

/* Lower
 * ,-----------------------------------------------Í------------------------------------.
 * |   ~  |   !  |   "  |   §  |   $  |   %  |   &  |   /  |   (  |   )  |   =  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   @  |   ?  |      |   €  |      |      |   \  |   {  |   }  |   +  |   *  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   <  |   >  |      |      |      |   ~  |   |  |   [  |   ]  |   #  |   '  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    DE_CIRC, DE_EXLM, DE_DQUO, DE_SECT, DE_DLR,  DE_PERC, DE_AMPR, DE_SLSH, DE_LPRN, DE_RPRN, DE_EQL, KC_BSPC,
    KC_DEL,  DE_AT  , DE_QUES, _______, DE_EURO, _______, _______, DE_BSLS, DE_LCBR, DE_RCBR, DE_PLUS, DE_ASTR,
    _______, DE_LABK , DE_RABK, _______, _______, _______, DE_TILD, DE_PIPE, DE_LBRC, DE_RBRC, DE_HASH, DE_QUOT,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),


/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_DEL,  _______, _______, _______, _______, _______,   _______,   _______, _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Plover layer (http://opensteno.org)
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_PLOVER] = LAYOUT_planck_grid(
    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1   ,
    XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
    XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    EXT_PLV, XXXXXXX, XXXXXXX, KC_C,    KC_V,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |      |      |      |      |  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      |      |Plover|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      | Reset|Debug |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, KC_F1,   KC_F2,   KC_F3, KC_F4, KC_F5, KC_F6, _______, _______,  _______, _______, KC_DEL ,
    _______, KC_F7, KC_F8,  KC_F9,   KC_F10,  KC_F11, KC_F12, _______,  _______,  _______,  PLOVER,  _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  RESET,   DEBUG,   _______
)

};
