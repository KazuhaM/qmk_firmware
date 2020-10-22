/* Copyright 2020 KazuhaM
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

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    TO_AUDIO_G = SAFE_RANGE,
    TO_AUDIO_Y,
    DBL_SFT,
    EXC_A1,
    EXC_A2
};

// const key_string_map_t custom_keys_user =
// {
//     .start_kc = CUSTOM_KEYCODE_START,
//     // BLE_SEL,
//     // USB_SEL,
//     // TO_AUDIO_G,
//     // TO_AUDIO_Y,
//     // DBL_SFT,
//     // EXC_A1,
//     // EXC_A2
//     .end_kc= CUSTOM_KEYCODE_START,
//     .key_strings = "\0"
//     // .key_strings = "BLE_SEL \0 USB_SEL \0 TO_AUDIO_G \0 TO_AUDIO_Y \0 DBL_SFT \0 EXC_A1 \0 EXC_A2 \0"
// };

enum layer_number {
    _GENERAL = 0,
    _CHROME,
    _EXCEL,
    _AUDIOY,
    _AUDIOYS,
    _AUDIOG,
    _WORD,
    _WORDREVIEW,
    _SHORTCUT,
    _ANDROID,
    _PASTERS,
    _WCSSET,
    _WCSFLT,
    _BLCKDSRT,
    _LAYERLIST,
    _GAMER
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_GENERAL] =LAYOUT( \
    KC_TAB         ,KC_LSFT ,KC_LALT       ,LALT(KC_LEFT)  ,KC_UP    ,LALT(KC_RGHT), \
    MO(_LAYERLIST) ,KC_BSPC    ,LSFT(KC_F10)  ,KC_LEFT        ,KC_DOWN  ,KC_RGHT \
  ),

  [_CHROME] =LAYOUT( \
    LCTL(KC_W),LCTL(KC_N),LCTL(KC_T),LALT(KC_LEFT),KC_PGUP,LALT(KC_RGHT), \
    KC_TRNS,LCTL(LSFT(KC_M)),LALT(KC_F),LCTL(LSFT(KC_TAB)),KC_PGDN,LCTL(KC_TAB)\
  ),

  [_EXCEL] =LAYOUT( \
    EXC_A1, KC_TAB,LALT(KC_3),LSFT(KC_SPC),LCTL(KC_UP),LCTL(KC_SPC), \
    KC_TRNS,LALT(KC_4),LSFT(KC_F10),LCTL(KC_PGUP),LCTL(KC_DOWN),LCTL(KC_PGDN) \
  ),

  [_AUDIOY] =LAYOUT( \
    KC_S,TO_AUDIO_G,KC_MUTE,KC_VOLD,KC_SPC,KC_VOLU, \
    KC_TRNS,LALT(KC_Y),KC_ENT,KC_K,MO(_AUDIOYS),KC_J \
  ),

  [_AUDIOYS] =LAYOUT( \
    KC_R,KC_NO,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, \
    KC_NO,KC_NO,KC_TRNS,KC_H,KC_TRNS,KC_L \
  ),

  [_AUDIOG] =LAYOUT( \
    KC_NO,LALT(KC_G),KC_MUTE,KC_VOLD,KC_MPLY,KC_VOLU, \
    KC_TRNS,TO_AUDIO_Y,KC_ENT,KC_MPRV,KC_MSTP,KC_MNXT \
  ),

  [_WORD] =LAYOUT( \
    LALT(KC_1),LALT(KC_2),LALT(KC_3),TO(_WORDREVIEW),KC_NO,KC_NO, \
    KC_TRNS,LALT(KC_4),LSFT(KC_F10),KC_HOME,KC_NO,KC_END \
  ),

  [_WORDREVIEW] =LAYOUT( \
    LALT(KC_1),LALT(KC_2),LALT(KC_3),LCA(KC_J),LCA(KC_A),LCA(KC_N), \
    KC_TRNS,LALT(KC_4),LSFT(KC_F10),LCA(KC_L),LCA(KC_B),LCA(KC_Q) \
  ),

  [_SHORTCUT] =LAYOUT( \
    KC_NO,KC_NO,LALT(KC_T),LALT(KC_E),LALT(KC_B),LALT(KC_C), \
    KC_TRNS,KC_NO,KC_ENT,KC_NO,KC_NO,KC_NO\
  ),

  [_ANDROID] =LAYOUT( \
    RGUI(KC_ENT),KC_LGUI,RGUI(KC_A),RGUI(KC_BSPC),RGUI(KC_N),RGUI(KC_B), \
    KC_TRNS,RGUI(KC_C),KC_ENT,KC_LEFT,LALT(KC_TAB),KC_RGHT\
  ),

  [_PASTERS] =LAYOUT( \
    DBL_SFT ,LCA(KC_O)  ,KC_NO  ,KC_NO     ,KC_NO       ,LCA(KC_G), \
    KC_TRNS ,LCA(KC_Y)  ,KC_NO  ,LCA(KC_P) ,LCA(KC_I)   ,LCA(KC_R)\
  ),

  [_WCSSET] =LAYOUT( \
    KC_LCTL        ,KC_LALT         ,KC_RALT    ,KC_RCTL    ,KC_RSFT, RSFT(KC_RALT),\
    KC_TRNS        ,KC_NO  ,KC_NO   ,KC_X          ,KC_W          ,KC_Z\
  ),

  [_WCSFLT] =LAYOUT( \
    KC_ESC        ,KC_NO     ,KC_NO    ,KC_NO      ,KC_NO    , KC_SPC,\
    KC_TRNS       ,KC_NO     ,KC_G     ,KC_X       ,KC_W     , KC_Z\
  ),

  [_BLCKDSRT] =LAYOUT( \
    KC_ESC        ,KC_6    ,KC_7      ,KC_8       , KC_9    , KC_0,\
    KC_TRNS       ,KC_1     ,KC_2     ,KC_3       ,KC_4     , KC_5\
  ),

  [_LAYERLIST] =LAYOUT( \
    KC_NO    ,KC_NO , TO(_ANDROID)  ,TO(_AUDIOY)  ,TO(_CHROME)  ,TO(_GENERAL), \
    KC_TRNS  ,MO(_GAMER), TO(_PASTERS)   ,TO(_WORD)    ,TO(_EXCEL)   ,TO(_SHORTCUT)\
  ),

  [_GAMER] =LAYOUT( \
    KC_NO  ,KC_NO, KC_NO  ,KC_NO ,TO(_WCSFLT)  ,TO(_WCSSET), \
    KC_TRNS  ,KC_NO, KC_NO  ,KC_NO ,KC_NO  ,TO(_BLCKDSRT)\
  ),
};

// uint32_t keymaps_len() {
//   return sizeof(keymaps)/sizeof(uint16_t);
// }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // bool continue_process = process_record_user_bmp(keycode, record);
  // if (continue_process == false)
  // {
  //   return false;
  // }
  switch (keycode) {
    case TO_AUDIO_Y:
      if (record->event.pressed) {
        layer_on(_AUDIOY);
        layer_off(_AUDIOG);
        register_code(KC_LALT);
        register_code(KC_Y);
        unregister_code(KC_Y);
        unregister_code(KC_LALT);
      };
      return false;
      break;
    case TO_AUDIO_G:
      if (record->event.pressed) {
        layer_on(_AUDIOG);
        layer_off(_AUDIOY);
        register_code(KC_LALT);
        register_code(KC_G);
        unregister_code(KC_G);
        unregister_code(KC_LALT);
      };
      return false;
      break;
    case DBL_SFT:
      if (record->event.pressed) {
        register_code(KC_LSFT);
        unregister_code(KC_LSFT);
        register_code(KC_LSFT);
        unregister_code(KC_LSFT);
      };
      return false;
      break;
    case EXC_A1:
      if (record->event.pressed) {
        register_code(KC_LALT);
        tap_code(KC_1);
        unregister_code(KC_LALT);
      };
      return false;
      break;
    case EXC_A2:
      if (record->event.pressed) {
        tap_code(KC_LALT);
        // unregister_code(KC_LALT);
      }else{
        // tap_code(KC_2);
        // tap_code(KC_M);
      };
      return false;
      break;
  }
  return true;
};

// void matrix_init_user(void) {

// }

// void matrix_scan_user(void) {

// }

// void led_set_user(uint8_t usb_led) {

// }
