#include QMK_KEYBOARD_H
#include "action_layer.h"
// extern midi_config_t midi_config;

// Defines names for use in layer keycodes and the keymap
enum {
    _BASE=0,
    _MRKNUM,
    _MUSE,
    _GTAB,
    _CODE,
    _FN
};


#define FN MO(_FN)
#define SP_MN LT(_MRKNUM, KC_SPACE)
#define _______ KC_TRNS

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {

    IM_EN= SAFE_RANGE,
    IM_JP,
    CO_SUS4,
    CO_ADD,
    CO_AUG,
    CO_MAJ,
    CO_DIM,
    CO_NAT,
    CPY_CODE,
    CPY_CODE_NS,
    TO_MUSE,
    TO_CODE,
    TAB_6_0,
    TAB_6_3,
    TAB_6_7,
    TAB_5_0,
    TAB_5_3,
    TAB_5_7,
    TAB_4_0,
    TAB_4_3,
    TAB_4_7,
    TAB_3_0,
    TAB_3_3,
    TAB_3_7,
    TAB_2_0,
    TAB_2_3,
    TAB_2_7,
    TAB_1_0,
    TAB_1_3,
    TAB_1_7
    // FR_10,
    // FR_11,
    // FR_12,
    // FR_13,
    // FR_14,
    // FR_15

};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT(
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,    KC_MINS,   KC_DEL,
    KC_LCTL,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_BSPC,
    KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
    FN   ,  KC_LALT,  KC_LGUI,  IM_EN ,  SP_MN,  KC_ENT ,   IM_JP , KC_RGUI,  KC_RALT,    KC_RCTL
  ),

  [_MRKNUM] = LAYOUT(
    KC_GRV ,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_EQL,  KC_BSLS,
    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,     KC_QUOT,     KC_LBRC,  KC_RBRC,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_PGUP,     KC_PGDN,     KC_HOME,     KC_UP,    KC_END,
    _______,  _______,  _______,  _______,          _______,  _______,                   _______,     KC_LEFT,  KC_DOWN,  KC_RGHT
  ),

  [_MUSE] = LAYOUT(
    KC_ESC ,   KC_0,     KC_Q,     KC_W,     S(KC_D),     S(KC_E),     S(KC_F),     S(KC_G),     S(KC_A),     S(KC_B),     S(KC_C),     S(KC_D),  A(KC_3),
    KC_LCTL,    KC_4,  KC_3,  KC_2,  KC_C,  KC_D,  KC_E,  KC_F,     KC_G,     KC_A,  KC_B,  KC_R,
    KC_LSFT,  KC_7,  KC_6,  KC_5,  KC_DOWN,  KC_UP,  C(KC_DOWN),  C(KC_UP),     C(KC_L),     S(C(KC_I)),     S(C(KC_S)),    TO_CODE,
    _______,  KC_LALT,  KC_DOT,  KC_PLUS,          KC_LEFT,  KC_RIGHT,                   C(KC_Z),     C(KC_X),  C(KC_C),  C(KC_V)
  ),

//   [_GTAB] = LAYOUT(
//     KC_ESC ,   KC_P1,     KC_P0,     KC_SCLN,     KC_7,     KC_8,     KC_9,     FR_10,     FR_11 ,    FR_12,    FR_13,     FR_14,  FR_15,
//     KC_LCTL,    KC_P4,  KC_P3,  KC_P2,  KC_0,  KC_1,  KC_2,  KC_3,     KC_4,     KC_5,  KC_6,  KC_R,
//     KC_LSFT,  KC_P7,  KC_P6,  KC_P5,  KC_DOWN,  KC_UP,  KC_NO,  KC_NO,     KC_NO,     KC_NO,     KC_NO,    TO_CODE,
//     _______,  KC_LALT,  KC_DOT,  KC_PLUS,          KC_LEFT,  KC_RIGHT,                   C(KC_Z),     C(KC_X),  C(KC_C),  C(KC_V)
//   ),

  [_GTAB] = LAYOUT(
    KC_ESC ,   KC_0,   KC_Q,   KC_W,   TAB_6_0,   TAB_5_0,  TAB_4_0,  TAB_3_0,   TAB_2_0,    TAB_1_0,  KC_N,    KC_DOWN,  KC_UP,
    KC_LCTL,    KC_4,  KC_3,  KC_2,  TAB_6_3,  TAB_5_3,  TAB_4_3,  TAB_3_3,     TAB_2_3,     TAB_1_3,  C(KC_UP),  KC_R,
    KC_LSFT,  KC_7,  KC_6,  KC_5,   TAB_6_7,  TAB_5_7,  TAB_4_7,    TAB_3_7,     TAB_2_7,     TAB_1_7,  C(KC_DOWN) ,  TO_CODE,
    _______,  KC_LALT,  KC_DOT,  KC_PLUS,          KC_LEFT,  KC_RIGHT,                   C(KC_Z),     C(KC_X),  C(KC_C),  C(KC_V)
  ),

  [_CODE] = LAYOUT(
    _______ ,  KC_7  , KC_8,     KC_9,      CO_ADD,    KC_SLSH,     CO_SUS4,  CO_DIM,     CO_AUG,    KC_NO,         KC_NO,     C(KC_SPC),  KC_BSPC,
    _______,    KC_4,  KC_5,  KC_6,  S(KC_C),  S(KC_D),  S(KC_E),  S(KC_F),     S(KC_G),     S(KC_A),  S(KC_B),  CPY_CODE_NS,
    _______,  KC_1,  KC_2,  KC_3,  KC_B,  KC_HASH, CO_NAT ,  KC_M,     KC_T,     KC_LPRN,    KC_RPRN,    TO_MUSE,
    _______,  _______,  S(KC_TAB),  S(KC_SCLN),          S(KC_SPC),  KC_SPC,                   KC_SCLN,     KC_TAB,  CPY_CODE,  _______
  ),

  [_FN] = LAYOUT(
    KC_N ,   _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,  _______,
    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,     _______,     _______,  _______,  _______,
    _______,  TO(_GTAB),  _______,  _______,  _______,  _______,  _______,  _______,     _______,     _______,     _______,    _______,
    _______,  TO(_MUSE),  TO(_BASE),  _______,          _______,  _______,                   _______,     _______,  _______,  _______
  ),

};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case IM_EN:
        if (record->event.pressed) {
            // persistent_default_layer_set(1UL<< 0) ;
            SEND_STRING(SS_TAP(X_F23));
            // for macOS
            SEND_STRING(SS_TAP(X_LANG2));
        }
        return false;
        break;
    case IM_JP:
        if (record->event.pressed) {
            // persistent_default_layer_set(1UL<< 2) ;
            SEND_STRING(SS_TAP(X_F24));
            // for macOS
            SEND_STRING(SS_TAP(X_LANG1));
        }
        return false;
        break;
    case TO_CODE:
        if (record->event.pressed) {
            layer_on (_CODE);
            register_code (KC_LCTL);
            tap_code (KC_K);
            unregister_code (KC_LCTL);
        }
        return false;
        break;
    case TO_MUSE:
        if (record->event.pressed) {
            layer_off(_CODE);
            layer_on(_MUSE);
            tap_code (KC_ESC);
        }
        return false;
        break;
    case CPY_CODE:
        if (record->event.pressed) {
            register_code (KC_LSFT);
            register_code (KC_LCTL);
            tap_code (KC_LEFT);
            unregister_code (KC_LCTL);
            unregister_code (KC_LSFT);
        }else{
            register_code (KC_LCTL);
            tap_code (KC_C);
            unregister_code (KC_LCTL);
        }
        return false;
        break;
    case CPY_CODE_NS:
        if (record->event.pressed) {
            register_code (KC_LSFT);
            register_code (KC_LCTL);
            tap_code (KC_LEFT);
            unregister_code (KC_LCTL);
            unregister_code (KC_LSFT);
        }else{
            register_code (KC_LCTL);
            tap_code (KC_C);
            unregister_code (KC_LCTL);
            tap_code (KC_TAB);
            register_code (KC_LCTL);
            tap_code (KC_V);
            unregister_code (KC_LCTL);
        }
        return false;
        break;
    case CO_SUS4:
        if (record->event.pressed) {
            SEND_STRING("sus4");
        }
        return false;
        break;
    case CO_MAJ:
        if (record->event.pressed) {
            SEND_STRING("maj");
        }
        return false;
        break;
    case CO_ADD:
        if (record->event.pressed) {
            SEND_STRING("add");
        }
        return false;
        break;
    case CO_AUG:
        if (record->event.pressed) {
            SEND_STRING("aug");
        }
        return false;
        break;
    case CO_DIM:
        if (record->event.pressed) {
            SEND_STRING("dim");
        }
        return false;
        break;
    case CO_NAT:
        if (record->event.pressed) {
            SEND_STRING("natural");
            register_code (KC_LCTL);
            tap_code (KC_SPC);
            unregister_code (KC_LCTL);
        }
        return false;
        break;
    case TAB_6_0:
        if (record->event.pressed) {
            tap_code (KC_E);
            register_code (KC_LCTL);
            tap_code (KC_DOWN);
            unregister_code (KC_LCTL);
        }
        return false;
        break;
    case TAB_6_3:
        if (record->event.pressed) {
            tap_code (KC_G);
            register_code (KC_LCTL);
            tap_code (KC_DOWN);
            unregister_code (KC_LCTL);
        }
        return false;
        break;
    case TAB_6_7:
        if (record->event.pressed) {
            tap_code (KC_B);
            register_code (KC_LCTL);
            tap_code (KC_DOWN);
            unregister_code (KC_LCTL);
        }
        return false;
        break;
    case TAB_5_0:
        if (record->event.pressed) {
            tap_code (KC_A);
            register_code (KC_LCTL);
            tap_code (KC_DOWN);
            unregister_code (KC_LCTL);
        }
        return false;
        break;
    case TAB_5_3:
        if (record->event.pressed) {
            tap_code (KC_C);
        }
        return false;
        break;
    case TAB_5_7:
        if (record->event.pressed) {
            tap_code (KC_E);
        }
        return false;
        break;
    case TAB_4_0:
        if (record->event.pressed) {
            tap_code (KC_D);
        }
        return false;
        break;
    case TAB_4_3:
        if (record->event.pressed) {
            tap_code (KC_F);
        }
        return false;
        break;
    case TAB_4_7:
        if (record->event.pressed) {
            tap_code (KC_A);
        }
        return false;
        break;
    case TAB_3_0:
        if (record->event.pressed) {
            tap_code (KC_G);
        }
        return false;
        break;
    case TAB_3_3:
        if (record->event.pressed) {
            tap_code (KC_A);

        }else{
            unregister_code (KC_LSFT);
            tap_code (KC_UP);
        }
        return false;
        break;
    case TAB_3_7:
        if (record->event.pressed) {
            tap_code (KC_D);
            register_code (KC_LCTL);
            tap_code (KC_UP);
            unregister_code (KC_LCTL);
        }
        return false;
        break;
    case TAB_2_0:
        if (record->event.pressed) {
            tap_code (KC_B);
        }
        return false;
        break;
    case TAB_2_3:
        if (record->event.pressed) {
            tap_code (KC_D);
            register_code (KC_LCTL);
            tap_code (KC_UP);
            unregister_code (KC_LCTL);
        }
        return false;
        break;
    case TAB_2_7:
        if (record->event.pressed) {
            tap_code (KC_F);
        }else{
            unregister_code (KC_LSFT);
            tap_code (KC_UP);
        }
        return false;
        break;
    case TAB_1_0:
        if (record->event.pressed) {
            tap_code (KC_E);
            register_code (KC_LCTL);
            tap_code (KC_UP);
            unregister_code (KC_LCTL);
        }
        return false;
        break;
    case TAB_1_3:
        if (record->event.pressed) {
            tap_code (KC_G);
            register_code (KC_LCTL);
            tap_code (KC_UP);
            unregister_code (KC_LCTL);
        }
        return false;
        break;
    case TAB_1_7:
        if (record->event.pressed) {
            tap_code (KC_B);
            register_code (KC_LCTL);
            tap_code (KC_UP);
            unregister_code (KC_LCTL);
        }
        return false;
        break;
    // case FR_10:
    //     if (record->event.pressed) {
    //         SEND_STRING("10");
    //     }
    //     return false;
    //     break;
    // case FR_11:
    //     if (record->event.pressed) {
    //         SEND_STRING("11");
    //     }
    //     return false;
    //     break;
    // case FR_12:
    //     if (record->event.pressed) {
    //         SEND_STRING("12");
    //     }
    //     return false;
    //     break;
    // case FR_13:
    //     if (record->event.pressed) {
    //         SEND_STRING("13");
    //     }
    //     return false;
    //     break;
    // case FR_14:
    //     if (record->event.pressed) {
    //         SEND_STRING("14");
    //     }
    //     return false;
    //     break;
    // case FR_15:
    //     if (record->event.pressed) {
    //         SEND_STRING("15");
    //     }
    //     return false;
    //     break;
    }

    return true;
};
