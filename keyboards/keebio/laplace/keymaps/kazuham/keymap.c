#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "keymap_jp.h"
enum custom_keycodes {
    //diphthong codes for JP
    NL_KA= SAFE_RANGE,
    NL_KI,
    NL_KU,
    NL_KE,
    NL_KO,
    NL_SA,
    NL_SI,
    NL_SU,
    NL_SE,
    NL_SO,
    NL_TA,
    NL_TI,
    NL_TU,
    NL_TE,
    NL_TO,
    NL_NA,
    NL_NI,
    NL_NU,
    NL_NE,
    NL_NO,
    NL_HA,
    NL_HI,
    NL_HU,
    NL_HE,
    NL_HO,
    NL_MA,
    NL_MI,
    NL_MU,
    NL_ME,
    NL_MO,
    NL_YA,
    NL_YU,
    NL_YO,
    NL_RA,
    NL_RI,
    NL_RU,
    NL_RE,
    NL_RO,
    NL_WA,
    NL_WO,
    NL_NN,
    NL_GA,
    NL_GI,
    NL_GU,
    NL_GE,
    NL_GO,
    NL_ZA,
    NL_ZI,
    NL_ZU,
    NL_ZE,
    NL_ZO,
    NL_DA,
    NL_DI,
    NL_DU,
    NL_DE,
    NL_DO,
    NL_BA,
    NL_BI,
    NL_BU,
    NL_BE,
    NL_BO,
    NL_PA,
    NL_PI,
    NL_PU,
    NL_PE,
    NL_PO,
    NL_LA,
    NL_LI,
    NL_LU,
    NL_LE,
    NL_LO,
    NL_XA,
    NL_XU,
    NL_XO,
    NL_LTU,

    NM_LKK,
    NM_RKK,
    NM_LSK,
    NM_RSK,
    NM_LMK,
    NM_RMK,
    NM_LGK,
    NM_RGK,

    IM_EN,
    IM_JP,
    TO_MRK,
    TO_NUM,
    TO_NTM,

    THM_BL,
    THM_BR,

    AZIK_N,
    AZIK_K,
    AZIK_T,
    AZIK_S,
    AZIK_Y,
    AZIK_W,
    AZIK_M,
    AZIK_R,
    AZIK_H,
    AZIK_G,
    AZIK_D,
    AZIK_Z,
    AZIK_F,
    AZIK_J,
    AZIK_B,

    DI_UU,
    DI_AI,
    DI_OU,
    DI_EI,
    DI_UI,
    DI_AU,
    DI_OI,
    DI_IU,
    DI_AA,
    DI_AE,
    DI_OO,
    DI_OA,
    DI_II,
    DI_IA,
    DI_EA,
    DI_IO,

    //-n codes for JP
    DN_UNN,
    DN_ANN,
    DN_ONN,
    DN_INN,
    DN_ENN,

    //DN_WO, TSU
    DN_WO,
    DN_TSU,
    SNIT_BL,
    SNIT_BR,
    SNIT_L,
    SNIT_R,
    IM_JPM

};

enum {
    _BASE = 0,
    _MRKNUM,
    _NICOLA,
    _NICOLAL,
    _NICOLAR,
    _NICOLAB,
    _NIT,
    _NITL,
    _NITR,
    _NITB,
    _MRK2,
    _NUM2,
    _FN
};

// #define FN1 MO(_MRKNUM)
#define FN MO(_FN)
#define SP_MN LT(_MRKNUM, KC_SPACE)
// #define SP_FN2 LT(_FN2, KC_SPACE)
// #define BS_FN1 LT(_FN1, KC_BSPC)
// #define BS_FN2 LT(_FN2, KC_BSPC)
#define THM_L LT(_NICOLAL,KC_SPC)
#define THM_R LT(_NICOLAR,KC_ENT)
#define SNIT_L LT(_NITL,KC_SPC)
#define SNIT_R LT(_NITR,KC_ENT)
#define ON_NUM MO(_NUM2)

#define IM_CH A(KC_GRV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT(
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,    KC_MINS,   KC_DEL,
    KC_LCTL,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_BSPC,
    KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
    FN   ,  KC_LALT,  KC_LGUI,  IM_CH ,  SP_MN,  KC_ENT ,   IM_JP , KC_RGUI,  KC_RALT,    KC_RCTL
  ),

  [_MRKNUM] = LAYOUT(
    KC_GRV ,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_EQL,  KC_BSLS,
    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,     KC_QUOT,     KC_LBRC,  KC_RBRC,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_PGUP,     KC_PGDN,     KC_HOME,     KC_UP,    KC_END,
    _______,  _______,  _______,  _______,          _______,  _______,                   _______,     KC_LEFT,  KC_DOWN,  KC_RGHT
  ),

  [_NICOLA] = LAYOUT(
    KC_TAB,   KC_DOT,     NL_KA,     NL_TA,     NL_KO,     NL_SA ,     NL_RA,     NL_TI,    NL_KU,     NL_TU,     KC_COMM,  KC_MINS,   KC_DEL,
    KC_LCTL,   KC_U,     NL_SI,     NL_TE,     NL_KE,    NL_SE,     NL_HA,     NL_TO,     NL_KI,     KC_I,     NL_NN,  KC_BSPC,
    KC_LSFT,  KC_COLN,     NL_HI,     NL_SU,     NL_HU,     NL_HE,     NL_ME,     NL_SO,     NL_NE,  NL_HO,   KC_SLSH,  KC_RSFT,
    _______,  KC_LALT,  KC_LGUI,   IM_EN ,  THM_L,   THM_R,   IM_CH , KC_RGUI,  KC_RALT,    KC_RCTL
  ),

  [_NICOLAL] = LAYOUT(
    KC_TAB,   NL_LA,     KC_E,     NL_RI,     NL_XA,     NL_RE ,     NL_PA,     NL_DI,    NL_GU,     NL_DU,     NL_PI,  _______,   KC_DEL,
    KC_LCTL,   NL_WO,     KC_A,     NL_NA,     NL_XU,    NL_MO,     NL_BA,     NL_DO,     NL_GI,     NL_PO,     NL_NN,  KC_BSPC,
    KC_LSFT,  NL_LU,     KC_MINS,     NL_RO,     NL_YA,     NL_LI,     NL_PU,     NL_ZO,     NL_PE,  NL_PO,   KC_UNDS,  KC_RSFT,
    _______,  KC_LALT,  KC_LGUI,  _______ ,  _______,   THM_BR,   _______ , KC_RGUI,  KC_RALT,    KC_RCTL
  ),

  [_NICOLAR] = LAYOUT(
    KC_TAB,   KC_DOT,     NL_GA,     NL_DA,     NL_GO,     NL_ZA ,     NL_YO,     NL_NI,    NL_RU,     NL_MA,     NL_LE,  _______,   _______,
    KC_LCTL,   KC_U,     NL_ZI,     NL_DE,     NL_GE,    NL_SE,     NL_MI,     KC_O,     NL_NO,     NL_XO,     NL_LTU,  KC_BSPC,
    KC_LSFT,  KC_SCLN,     NL_BI,     NL_ZU,     NL_BU,     NL_BE,     NL_NU,     NL_YU,     NL_MU,  NL_WA,   NL_LO,  KC_RSFT,
    _______,  KC_LALT,  KC_LGUI,  _______ ,  THM_BL,   THM_R,   _______ , KC_RGUI,  KC_RALT,    KC_RCTL
  ),

  [_NICOLAB] = LAYOUT(
    KC_GRV ,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_BSLS,  _______,
    _______,  KC_QUES,  KC_SLSH,  KC_TILD,  NM_LKK,  NM_RKK,  NM_LSK,  NM_RSK,     NM_LMK,     NM_RMK,  NM_LGK,  NM_RGK,
    _______,  KC_EXLM,    KC_NO,  KC_HASH,  KC_DLR,  KC_PERC, KC_AMPR,  KC_PGUP,     KC_PGDN,     KC_HOME,     KC_UP,    KC_END,
    _______,  _______,  _______,  _______,          THM_L,  THM_R,                   _______,     KC_LEFT,  KC_DOWN,  KC_RGHT
  ),

  [_NIT] = LAYOUT(
    KC_TAB,   KC_COMM,   AZIK_H,     AZIK_R,     AZIK_M,     AZIK_W ,     DI_UU, DI_AI, DI_OU, KC_DOT, DI_EI,  KC_MINS,   KC_LALT,
    KC_LGUI,  AZIK_Y,   AZIK_S,     AZIK_T,     AZIK_K,    AZIK_N,    KC_U  , KC_A  , KC_O  , KC_I  , KC_E,  KC_MINS,
    KC_LSFT,  KC_P,    KC_L,     DN_TSU,     DN_WO,     KC_DEL,    KC_BSPC, DI_AU, DI_OI, DI_II, DI_EA,  KC_RSFT,
    _______,  KC_LALT,  KC_LCTL,  _______ ,  SNIT_L,   SNIT_R,   _______ , KC_RGUI,  KC_RALT,    KC_RCTL
  ),

  [_NITL] = LAYOUT(
    KC_TAB,   KC_SCLN,  _______,     AZIK_J,    AZIK_F,     KC_Q ,     _______, _______, _______, _______, _______,  _______,   _______,
    KC_LGUI,  _______,   AZIK_Z,     AZIK_D,     AZIK_G,    _______,    _______  , _______  , _______  , _______  , _______,  _______,
    KC_LSFT,  AZIK_B,   KC_V,     KC_P,     AZIK_B,     _______,    _______, _______, _______, _______, _______,  _______,
    _______,  KC_LALT,  KC_LCTL,  _______ ,  _______,   SNIT_BR,   _______ , KC_RGUI,  KC_RALT,    KC_RCTL
  ),

  [_NITR] = LAYOUT(
    KC_TAB,   KC_COMM,   AZIK_H,     AZIK_R,     AZIK_M,     AZIK_W ,     DI_UI, DI_AA, DI_OO, KC_COLN, DI_IU,  KC_MINS,   _______,
    KC_LGUI,  AZIK_Y,   AZIK_S,     AZIK_T,     AZIK_K,    AZIK_N,    DN_UNN  , DN_ANN  , DN_ONN  , DN_INN  , DN_ENN,  _______,
    KC_LSFT,  KC_P,    KC_L,     DN_TSU,     DN_WO,     _______,    _______, DI_AE, DI_OA, DI_IA, DI_IO,  _______,
    _______,  KC_LALT,  KC_LCTL,  _______ ,  SNIT_BL,   SNIT_R,   _______ , KC_RGUI,  KC_RALT,    KC_RCTL
  ),

  [_NITB] = LAYOUT(
    KC_TAB,   KC_SCLN,  _______,     AZIK_J,    AZIK_F,     KC_Q  ,    _______, _______, _______, _______, _______,  _______,    KC_LALT,
    KC_LGUI,  _______,   AZIK_Z,     AZIK_D,     AZIK_G,    _______,    _______  , _______  , _______  , _______  , _______,  _______,
    KC_LSFT,  AZIK_B,   KC_V,     KC_P,     AZIK_B,     _______,   _______  , _______  , _______  , _______  , _______,  KC_RSFT,
    _______,  KC_LALT,  KC_LCTL,  _______ ,  SNIT_L,   SNIT_R,   _______ , KC_RGUI,  KC_RALT,    KC_RCTL
  ),

  [_MRK2] = LAYOUT(
    _______ , KC_LT  , KC_GT   , KC_LBRC , KC_RBRC , KC_AMPR , KC_EQL  , KC_EXLM , KC_BSLS , KC_PERC , KC_MINS  ,  KC_PAST, _______,
    _______, KC_QUOT , KC_DQT  , KC_LPRN  , KC_RPRN  , KC_DLR  , KC_COLN , KC_QUES , KC_AT   , KC_UNDS  , KC_PLUS , KC_PIPE ,
    _______,  KC_COMM , KC_GRV  , KC_LCBR  , KC_RCBR,  KC_DEL  ,  KC_BSPC , KC_TILD   , KC_HASH   , KC_SLSH   , KC_DOT  , _______ ,
    _______,  _______,  _______,  _______,          KC_NO ,  ON_NUM,                   _______,     _______,  _______,  _______
  ),

  [_NUM2] = LAYOUT(
    KC_GRV ,   KC_LPRN,  KC_HOME,  KC_UP,  KC_END,  KC_AMPR,  KC_EQL,  KC_7,   KC_8,    KC_9,     KC_MINUS,     KC_PAST,  _______,
    _______,    KC_RPRN,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_DLR,  KC_0,  KC_4,     KC_5,     KC_6,  KC_PLUS,  KC_PSLS,
    _______,      KC_COMM,  KC_PGUP,  KC_COLN,  KC_PGDN,  _______,  _______,  KC_1,     KC_2,     KC_3,   KC_DOT,    KC_CIRC,
    _______,  _______,  _______,  _______,          TO_NTM,  KC_NO,                   _______, KC_RGUI,  KC_RALT,    KC_RCTL
  ),

  [_FN] = LAYOUT(
    KC_ESC,   KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,  KC_F11,  KC_F12,
    KC_LCTL,  RGB_TOG,  RGB_M_P,  RGB_M_B,  RGB_M_R,  RGB_M_SW,   KC_INS,      KC_PSCR,  KC_SLCK,  KC_PAUS,  KC_CAPS,  KC_BSPC,
    KC_LSFT,  KC_NO,  RGB_M_SN,  RGB_M_K,  RGB_M_X,  RGB_M_G,   KC_NO,      KC_NLCK,  KC_NO,  KC_NO,  KC_NO ,KC_RSFT,
    _______,  KC_LALT,  KC_LGUI,  _______,            TO_MRK,   TO_NUM,                 IM_JPM,  KC_RGUI,  KC_RALT,  KC_RCTL
  )
};

void matrix_init_user(void) {
  rgblight_enable();
  rgblight_setrgb (0x00,  0x00, 0xFF);
};

// led color map for each layer
uint8_t rgbmap[][3] = {
    {0x00,  0x00, 0xFF},    // layer 0  BASE
    {0x20,  0x00, 0xFF},    // layer 1  MRKNUM
    {0xFF,  0xFF, 0x00},    // layer 2  NICOLA
    {0xFF,  0xb0, 0x00},    // layer 3  NICOLAL
    {0xb0,  0xFF, 0x00},    // layer 4  NICOLAR
    {0xa0,  0xa0, 0x00},    // layer 5  NICOLAB
    {0xdd,  0xdd, 0xFF},    // layer 6  NIT
    {0x50,  0xdd, 0xFF},    // layer 7  NITL
    {0xdd,  0x50, 0xFF},    // layer 8  NITR
    {0xac,  0xac, 0xFF},    // layer 9  NITB
    {0x00,  0xac, 0xFF},    // layer 10  MARK
    {0xac,  0x20, 0x20},    // layer 11  NUMBER
    {0x00,  0xFF, 0x00},    // layer 12  FN
};

void set_layer_led(int sel_layer){
    rgblight_setrgb(rgbmap[sel_layer][0], rgbmap[sel_layer][1], rgbmap[sel_layer][2]);
};

uint32_t layer_state_set_user(uint32_t state) {
  switch (biton32(state)) {
    case _FN:
      set_layer_led(_FN);
      break;
    case _NUM2:
      set_layer_led(_NUM2);
      break;
    case _MRK2:
      set_layer_led(_MRK2);
      break;
    case _NITB:
      break;
    case _NITR:
      break;
    case _NITL:
      break;
    case _NIT:
      set_layer_led(_NIT);
      break;
    case _NICOLAB:
      break;
    case _NICOLAR:
      break;
    case _NICOLAL:
      break;
    case _NICOLA:
      set_layer_led(_NICOLA);
      break;
    case _MRKNUM:
      set_layer_led(_MRKNUM);
      break;
    case _BASE:
      set_layer_led(_BASE);
      break;
    default: //  for any other layers, or the default layer
        rgblight_setrgb (0xFF,  0xFF, 0xFF);
        break;
    }
  return state;
}

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

uint16_t pre_pressed_key;
bool jp_mode = false;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case IM_EN:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<< 0) ;
        SEND_STRING(SS_TAP(X_F23));
        // for macOS
        SEND_STRING(SS_TAP(X_LANG2));
        layer_clear();
        layer_on(0);
      }
      return false;
      break;
    case IM_JP:
      if (record->event.pressed) {
        if(!jp_mode){
          persistent_default_layer_set(1UL<< 2) ;
          SEND_STRING(SS_TAP(X_F24));
          // for macOS
          SEND_STRING(SS_TAP(X_LANG1));
          layer_clear();
          layer_on(2);
          set_layer_led(_NICOLA);
        }else{
          persistent_default_layer_set(1UL<< 2) ;
          SEND_STRING(SS_TAP(X_F24));
          // for macOS
          SEND_STRING(SS_TAP(X_LANG1));
          layer_clear();
          layer_on(_NIT);
          set_layer_led(_NIT);
        }

      }
      return false;
      break;
    case IM_JPM:
      if (record->event.pressed) {
        if(jp_mode){
          persistent_default_layer_set(1UL<< 2) ;
          SEND_STRING(SS_TAP(X_F24));
          // for macOS
          SEND_STRING(SS_TAP(X_LANG1));
          layer_clear();
          layer_on(2);
          jp_mode = false;
          set_layer_led(_NICOLA);
        }else{
          persistent_default_layer_set(1UL<< 2) ;
          SEND_STRING(SS_TAP(X_F24));
          // for macOS
          SEND_STRING(SS_TAP(X_LANG1));
          layer_clear();
          layer_on(_NIT);
          jp_mode = true;
          set_layer_led(_NIT);
        }
      }
      return false;
      break;
    case TO_MRK:
      if (record->event.pressed) {
        layer_off(_FN);
        layer_on(_MRK2);
        set_layer_led(_MRK2);
      }else{
        layer_off(_MRK2);
        layer_on(_FN);
        set_layer_led(_FN);
      }
      return false;
      break;
    case TO_NUM:
      if (record->event.pressed) {
        layer_off(_FN);
        layer_on(_NUM2);
        set_layer_led(_NUM2);
      }else{
        layer_off(_NUM2);
        layer_on(_FN);
        set_layer_led(_FN);
      }
      return false;
      break;
    case TO_NTM:
      if (record->event.pressed) {
        layer_off(_NUM2);
        layer_on(_MRK2);
        set_layer_led(_MRK2);
      }else{
        layer_off(_MRK2);
        layer_on(_NUM2);
        set_layer_led(_NUM2);
      }
      return false;
      break;
    // push left thumb key when you already pushed right thumb key
    case THM_BL:
      if (record->event.pressed) {
        // when keycode DF_RNMSH is pressed
        layer_on(_NICOLAL);
        update_tri_layer(_NICOLAL, _NICOLAR, _NICOLAB);
        set_layer_led(_NICOLAB);
      }else{
        layer_off(_NICOLAL);
        update_tri_layer(_NICOLAL, _NICOLAR, _NICOLAB);
        set_layer_led(_NICOLAR);
      }
      return false;
      break;
    // push right thumb key when you already pushed left thumb key
    case THM_BR:
      if (record->event.pressed) {
        // when keycode DF_RNMSH is pressed
        layer_on(_NICOLAR);
        update_tri_layer(_NICOLAL, _NICOLAR, _NICOLAB);
        set_layer_led(_NICOLAB);
      }else{
        layer_off(_NICOLAR);
        update_tri_layer(_NICOLAL, _NICOLAR, _NICOLAB);
        set_layer_led(_NICOLAL);
      }
      return false;
      break;
    // push left thumb key when you are on _NICOLA layer
    case THM_L:
      if (record->event.pressed) {
        set_layer_led(_NICOLAL);
      }else{
        layer_off(_NICOLAL);
        update_tri_layer(_NICOLAL, _NICOLAR, _NICOLAB);
        if(layer_state_is(_NICOLAR)){
          set_layer_led(_NICOLAR);
        }else if(layer_state_is(_NICOLA)){
          set_layer_led(_NICOLA);
        }
      }
      break;
    // push right thumb key when you are on _NICOLA layer
    case THM_R:
      if (record->event.pressed) {
        set_layer_led(_NICOLAR);
      }else{
        layer_off(_NICOLAR);
        update_tri_layer(_NICOLAL, _NICOLAR, _NICOLAB);
        if(layer_state_is(_NICOLAL)){
          set_layer_led(_NICOLAL);
        }else if(layer_state_is(_NICOLA)){
          set_layer_led(_NICOLA);
        }
      }
      break;
    case SNIT_BL:
      if (record->event.pressed) {
        // when keycode DF_RNMSH is pressed
        layer_on(_NITL);
        update_tri_layer(_NITL, _NITR, _NITB);
        set_layer_led(_NITB);
      }else{
        layer_off(_NITL);
        update_tri_layer(_NITL, _NITR, _NITB);
        set_layer_led(_NITR);
      }
      return false;
      break;
    // push right thumb key when you already pushed left thumb key
    case SNIT_BR:
      if (record->event.pressed) {
        // when keycode DF_RNMSH is pressed
        layer_on(_NITR);
        update_tri_layer(_NITL, _NITR, _NITB);
        set_layer_led(_NITB);
      }else{
        layer_off(_NITR);
        update_tri_layer(_NITL, _NITR, _NITB);
        set_layer_led(_NITL);
      }
      return false;
      break;
    // push left thumb key when you are on _NIT layer
    case SNIT_L:
      if (record->event.pressed) {
        set_layer_led(_NITL);
      }else{
        layer_off(_NITL);
        update_tri_layer(_NITL, _NITR, _NITB);
        if(layer_state_is(_NITR)){
          set_layer_led(_NITR);
        }else if(layer_state_is(_NIT)){
          set_layer_led(_NIT);
        }
      }
      break;
    // push right thumb key when you are on _NIT layer
    case SNIT_R:
      if (record->event.pressed) {
        set_layer_led(_NITR);
      }else{
        layer_off(_NITR);
        update_tri_layer(_NITL, _NITR, _NITB);
        if(layer_state_is(_NITL)){
          set_layer_led(_NITL);
        }else if(layer_state_is(_NIT)){
          set_layer_led(_NIT);
        }
      }
      break;
    case NL_KA:
      if (record->event.pressed) {
        SEND_STRING("ka");
      }
      return false;
      break;
    case NL_KI:
      if (record->event.pressed) {
        SEND_STRING("ki");
      }
      return false;
      break;
    case NL_KU:
      if (record->event.pressed) {
        SEND_STRING("ku");
      }
      return false;
      break;
    case NL_KE:
      if (record->event.pressed) {
        SEND_STRING("ke");
      }
      return false;
      break;
    case NL_KO:
      if (record->event.pressed) {
        SEND_STRING("ko");
      }
      return false;
      break;
    case NL_SA:
      if (record->event.pressed) {
        SEND_STRING("sa");
      }
      return false;
      break;
    case NL_SI:
      if (record->event.pressed) {
        SEND_STRING("si");
      }
      return false;
      break;
    case NL_SU:
      if (record->event.pressed) {
        SEND_STRING("su");
      }
      return false;
      break;
    case NL_SE:
      if (record->event.pressed) {
        SEND_STRING("se");
      }
      return false;
      break;
    case NL_SO:
      if (record->event.pressed) {
        SEND_STRING("so");
      }
      return false;
      break;
    case NL_TA:
      if (record->event.pressed) {
        SEND_STRING("ta");
      }
      return false;
      break;
    case NL_TI:
      if (record->event.pressed) {
        SEND_STRING("ti");
      }
      return false;
      break;
    case NL_TU:
      if (record->event.pressed) {
        SEND_STRING("tu");
      }
      return false;
      break;
    case NL_TE:
      if (record->event.pressed) {
        SEND_STRING("te");
      }
      return false;
      break;
    case NL_TO:
      if (record->event.pressed) {
        SEND_STRING("to");
      }
      return false;
      break;
    case NL_NA:
      if (record->event.pressed) {
        SEND_STRING("na");
      }
      return false;
      break;
    case NL_NI:
      if (record->event.pressed) {
        SEND_STRING("ni");
      }
      return false;
      break;
    case NL_NU:
      if (record->event.pressed) {
        SEND_STRING("nu");
      }
      return false;
      break;
    case NL_NE:
      if (record->event.pressed) {
        SEND_STRING("ne");
      }
      return false;
      break;
    case NL_NO:
      if (record->event.pressed) {
        SEND_STRING("no");
      }
      return false;
      break;
    case NL_HA:
      if (record->event.pressed) {
        SEND_STRING("ha");
      }
      return false;
      break;
    case NL_HI:
      if (record->event.pressed) {
        SEND_STRING("hi");
      }
      return false;
      break;
    case NL_HU:
      if (record->event.pressed) {
        SEND_STRING("hu");
      }
      return false;
      break;
    case NL_HE:
      if (record->event.pressed) {
        SEND_STRING("he");
      }
      return false;
      break;
    case NL_HO:
      if (record->event.pressed) {
        SEND_STRING("ho");
      }
      return false;
      break;
    case NL_MA:
      if (record->event.pressed) {
        SEND_STRING("ma");
      }
      return false;
      break;
    case NL_MI:
      if (record->event.pressed) {
        SEND_STRING("mi");
      }
      return false;
      break;
    case NL_MU:
      if (record->event.pressed) {
        SEND_STRING("mu");
      }
      return false;
      break;
    case NL_ME:
      if (record->event.pressed) {
        SEND_STRING("me");
      }
      return false;
      break;
    case NL_MO:
      if (record->event.pressed) {
        SEND_STRING("mo");
      }
      return false;
      break;
    case NL_YA:
      if (record->event.pressed) {
        SEND_STRING("ya");
      }
      return false;
      break;
    case NL_YU:
      if (record->event.pressed) {
        SEND_STRING("yu");
      }
      return false;
      break;
    case NL_YO:
      if (record->event.pressed) {
        SEND_STRING("yo");
      }
      return false;
      break;
    case NL_RA:
      if (record->event.pressed) {
        SEND_STRING("ra");
      }
      return false;
      break;
    case NL_RI:
      if (record->event.pressed) {
        SEND_STRING("ri");
      }
      return false;
      break;
    case NL_RU:
      if (record->event.pressed) {
        SEND_STRING("ru");
      }
      return false;
      break;
    case NL_RE:
      if (record->event.pressed) {
        SEND_STRING("re");
      }
      return false;
      break;
    case NL_RO:
      if (record->event.pressed) {
        SEND_STRING("ro");
      }
      return false;
      break;
    case NL_WA:
      if (record->event.pressed) {
        SEND_STRING("wa");
      }
      return false;
      break;
    case NL_WO:
      if (record->event.pressed) {
        SEND_STRING("wo");
      }
      return false;
      break;
    case NL_NN:
      if (record->event.pressed) {
        SEND_STRING("nn");
      }
      return false;
      break;
    case NL_GA:
      if (record->event.pressed) {
        SEND_STRING("ga");
      }
      return false;
      break;
    case NL_GI:
      if (record->event.pressed) {
        SEND_STRING("gi");
      }
      return false;
      break;
    case NL_GU:
      if (record->event.pressed) {
        SEND_STRING("gu");
      }
      return false;
      break;
    case NL_GE:
      if (record->event.pressed) {
        SEND_STRING("ge");
      }
      return false;
      break;
    case NL_GO:
      if (record->event.pressed) {
        SEND_STRING("go");
      }
      return false;
      break;
    case NL_ZA:
      if (record->event.pressed) {
        SEND_STRING("za");
      }
      return false;
      break;
    case NL_ZI:
      if (record->event.pressed) {
        SEND_STRING("zi");
      }
      return false;
      break;
    case NL_ZU:
      if (record->event.pressed) {
        SEND_STRING("zu");
      }
      return false;
      break;
    case NL_ZE:
      if (record->event.pressed) {
        SEND_STRING("ze");
      }
      return false;
      break;
    case NL_ZO:
      if (record->event.pressed) {
        SEND_STRING("zo");
      }
      return false;
      break;
    case NL_DA:
      if (record->event.pressed) {
        SEND_STRING("da");
      }
      return false;
      break;
    case NL_DI:
      if (record->event.pressed) {
        SEND_STRING("di");
      }
      return false;
      break;
    case NL_DU:
      if (record->event.pressed) {
        SEND_STRING("du");
      }
      return false;
      break;
    case NL_DE:
      if (record->event.pressed) {
        SEND_STRING("de");
      }
      return false;
      break;
    case NL_DO:
      if (record->event.pressed) {
        SEND_STRING("do");
      }
      return false;
      break;
    case NL_BA:
      if (record->event.pressed) {
        SEND_STRING("ba");
      }
      return false;
      break;
    case NL_BI:
      if (record->event.pressed) {
        SEND_STRING("bi");
      }
      return false;
      break;
    case NL_BU:
      if (record->event.pressed) {
        SEND_STRING("bu");
      }
      return false;
      break;
    case NL_BE:
      if (record->event.pressed) {
        SEND_STRING("be");
      }
      return false;
      break;
    case NL_BO:
      if (record->event.pressed) {
        SEND_STRING("bo");
      }
      return false;
      break;
    case NL_PA:
      if (record->event.pressed) {
        SEND_STRING("pa");
      }
      return false;
      break;
    case NL_PI:
      if (record->event.pressed) {
        SEND_STRING("pi");
      }
      return false;
      break;
    case NL_PU:
      if (record->event.pressed) {
        SEND_STRING("pu");
      }
      return false;
      break;
    case NL_PE:
      if (record->event.pressed) {
        SEND_STRING("pe");
      }
      return false;
      break;
    case NL_PO:
      if (record->event.pressed) {
        SEND_STRING("po");
      }
      return false;
      break;
    case NL_LA:
      if (record->event.pressed) {
        SEND_STRING("la");
      }
      return false;
      break;
    case NL_LI:
      if (record->event.pressed) {
        SEND_STRING("li");
      }
      return false;
      break;
    case NL_LU:
      if (record->event.pressed) {
        SEND_STRING("lu");
      }
      return false;
      break;
    case NL_LE:
      if (record->event.pressed) {
        SEND_STRING("le");
      }
      return false;
      break;
    case NL_LO:
      if (record->event.pressed) {
        SEND_STRING("lo");
      }
      return false;
      break;
    case NL_XA:
      if (record->event.pressed) {
        SEND_STRING("lya");
      }
      return false;
      break;
    case NL_XU:
      if (record->event.pressed) {
        SEND_STRING("lyu");
      }
      return false;
      break;
    case NL_XO:
      if (record->event.pressed) {
        SEND_STRING("lyo");
      }
      return false;
      break;
    case NL_LTU:
      if (record->event.pressed) {
        SEND_STRING("ltsu");
      }
      return false;
      break;
    case NM_LKK:
      if (record->event.pressed) {
        SEND_STRING("[");
      }
      return false;
      break;
    case NM_RKK:
      if (record->event.pressed) {
        SEND_STRING("]");
      }
      return false;
      break;
    case NM_LSK:
      if (record->event.pressed) {
        SEND_STRING("{");
      }
      return false;
      break;
    case NM_RSK:
      if (record->event.pressed) {
        SEND_STRING("}");
      }
      return false;
      break;
    case NM_LMK:
      if (record->event.pressed) {
        SEND_STRING("(");
      }
      return false;
      break;
    case NM_RMK:
      if (record->event.pressed) {
        SEND_STRING(")");
      }
      return false;
      break;
    case NM_LGK:
      if (record->event.pressed) {
        SEND_STRING("\"");
      }
      return false;
      break;
    case NM_RGK:
      if (record->event.pressed) {
        SEND_STRING("\'");
      }
      return false;
      break;
    case AZIK_N:
      if (record->event.pressed) {
        switch (pre_pressed_key){
          case AZIK_T:
            SEND_STRING("une");
            pre_pressed_key = 0;
            break;
          case AZIK_Y:
            SEND_STRING("ouna");
            pre_pressed_key = 0;
            break;
          case AZIK_M:
            SEND_STRING("ono");
            pre_pressed_key = 0;
            break;
          case AZIK_N:
            SEND_STRING("n");
            pre_pressed_key = 0;
            break;
          default:
            tap_code (KC_N);
            pre_pressed_key = keycode;
            break;
        }
      }
      return false;
      break;
    case AZIK_K:
      if (record->event.pressed) {
        switch (pre_pressed_key){
          case AZIK_T:
            SEND_STRING("oka");
            pre_pressed_key = 0;
            break;
          case AZIK_S:
            SEND_STRING("oko");
            pre_pressed_key = 0;
            break;
          case AZIK_Y:
            SEND_STRING("oku");
            pre_pressed_key = 0;
            break;
          default:
            tap_code (KC_K);
            pre_pressed_key = keycode;
            break;
        }
      }
      return false;
      break;
    case AZIK_T:
      if (record->event.pressed) {
        switch (pre_pressed_key){
          case AZIK_N:
            SEND_STRING("iti");
            pre_pressed_key = 0;
            break;
          case AZIK_K:
            SEND_STRING("oto");
            pre_pressed_key = 0;
            break;
          case AZIK_S:
            SEND_STRING("ita");
            pre_pressed_key = 0;
            break;
          case AZIK_W:
            SEND_STRING("ata");
            pre_pressed_key = 0;
            break;
          case AZIK_M:
            SEND_STRING("ata");
            pre_pressed_key = 0;
            break;
          case AZIK_H:
            SEND_STRING("ito");
            pre_pressed_key = 0;
            break;
          case AZIK_G:
            SEND_STRING("oto");
            pre_pressed_key = 0;
            break;
          case AZIK_D:
            SEND_STRING("ati");
            pre_pressed_key = 0;
            break;
          case AZIK_B:
            SEND_STRING("ito");
            pre_pressed_key = 0;
            break;
          default:
            tap_code (KC_T);
            pre_pressed_key = keycode;
            break;
        }
      }
      return false;
      break;
    case AZIK_S:
      if (record->event.pressed) {
        switch (pre_pressed_key){
          case AZIK_N:
            SEND_STRING("asi");
            pre_pressed_key = 0;
            break;
          case AZIK_K:
            SEND_STRING("oso");
            pre_pressed_key = 0;
            break;
          case AZIK_Y:
            SEND_STRING("osi");
            pre_pressed_key = 0;
            break;
          case AZIK_T:
            SEND_STRING("osi");
            pre_pressed_key = 0;
            break;
          case AZIK_M:
            SEND_STRING("asu");
            pre_pressed_key = 0;
            break;
          case AZIK_R:
            SEND_STRING("asi");
            pre_pressed_key = 0;
            break;
          case AZIK_D:
            SEND_STRING("esu");
            pre_pressed_key = 0;
            break;
          default:
            tap_code (KC_S);
            pre_pressed_key = keycode;
            break;
        }
      }
      return false;
      break;
    case AZIK_Y:
      if (record->event.pressed) {
        tap_code (KC_Y);
        pre_pressed_key = keycode;
      }
      return false;
      break;
    case AZIK_W:
      if (record->event.pressed) {
        tap_code (KC_W);
        pre_pressed_key = keycode;
      }
      return false;
      break;
    case AZIK_M:
      if (record->event.pressed) {
        switch (pre_pressed_key){
          case AZIK_K:
            SEND_STRING("amo");
            pre_pressed_key = 0;
            break;
          case AZIK_T:
            SEND_STRING("ame");
            pre_pressed_key = 0;
            break;
          case AZIK_D:
            SEND_STRING("emo");
            pre_pressed_key = 0;
            break;
          default:
            tap_code (KC_M);
            pre_pressed_key = keycode;
            break;
        }
      }
      return false;
      break;
    case AZIK_R:
      if (record->event.pressed) {
        switch (pre_pressed_key){
          case AZIK_N:
            SEND_STRING("aru");
            pre_pressed_key = 0;
            break;
          case AZIK_K:
            SEND_STRING("ore");
            pre_pressed_key = 0;
            break;
          case AZIK_T:
            SEND_STRING("ara");
            pre_pressed_key = 0;
            break;
          case AZIK_S:
            SEND_STRING("uru");
            pre_pressed_key = 0;
            break;
          case AZIK_Y:
            SEND_STRING("oru");
            pre_pressed_key = 0;
            break;
          case AZIK_W:
            SEND_STRING("are");
            pre_pressed_key = 0;
            break;
          case AZIK_H:
            SEND_STRING("iru");
            pre_pressed_key = 0;
            break;
          case AZIK_G:
            SEND_STRING("oro");
            pre_pressed_key = 0;
            break;
          case AZIK_D:
            SEND_STRING("earu");
            pre_pressed_key = 0;
            break;
          case AZIK_Z:
            SEND_STRING("aru");
            pre_pressed_key = 0;
            break;
          default:
            tap_code (KC_R);
            pre_pressed_key = keycode;
            break;
        }
      }
      return false;
      break;
    case AZIK_H:
      if (record->event.pressed) {
        switch (pre_pressed_key){
          case AZIK_N:
            SEND_STRING("iha");
            pre_pressed_key = 0;
            break;
          default:
            tap_code (KC_H);
            pre_pressed_key = keycode;
            break;
        }
      }
      return false;
      break;
    case AZIK_G:
      if (record->event.pressed) {
        tap_code (KC_G);
        pre_pressed_key = keycode;
      }
      return false;
      break;
    case AZIK_D:
      if (record->event.pressed) {
        switch (pre_pressed_key){
          case AZIK_K:
            SEND_STRING("edo");
            pre_pressed_key = 0;
            break;
          case AZIK_N:
            SEND_STRING("ode");
            pre_pressed_key = 0;
            break;
          default:
            tap_code (KC_D);
            pre_pressed_key = keycode;
            break;
        }
      }
      return false;
      break;
    case AZIK_Z:
      if (record->event.pressed) {
        tap_code (KC_Z);
        pre_pressed_key = keycode;
      }
      return false;
      break;
    case AZIK_F:
      if (record->event.pressed) {
        tap_code (KC_F);
        pre_pressed_key = keycode;
      }
      return false;
      break;
    case AZIK_J:
      if (record->event.pressed) {
        switch (pre_pressed_key){
          default:
            tap_code (KC_J);
            pre_pressed_key = keycode;
            break;
        }
      }
      return false;
      break;
    case AZIK_B:
      if (record->event.pressed) {
        switch (pre_pressed_key){
          case AZIK_N:
            SEND_STRING("eba");
            pre_pressed_key = 0;
            break;
          case AZIK_T:
            SEND_STRING("abi");
            pre_pressed_key = 0;
            break;
          default:
            tap_code (KC_B);
            pre_pressed_key = keycode;
            break;
        }
      }
      return false;
      break;
    //macros for diphthong
    case DI_UU:
      if (record->event.pressed) {
        // when keycode DI_UU is pressed
        SEND_STRING("uu");
        pre_pressed_key = keycode;
      }
      return false;
      break;
    case DI_AI:
      if (record->event.pressed) {
        // when keycode DI_AI is pressed
        SEND_STRING("ai");
        pre_pressed_key = keycode;
      }
      return false;
      break;
    case DI_OU:
      if (record->event.pressed) {
        // when keycode DI_OU is pressed
        SEND_STRING("ou");
        pre_pressed_key = keycode;
      }
      return false;
      break;
    case DI_EI:
      if (record->event.pressed) {
        // when keycode DI_EI is pressed
        SEND_STRING("ei");
        pre_pressed_key = keycode;
      }
      return false;
      break;
    case DI_UI:
      if (record->event.pressed) {
        // when keycode DI_UI is pressed
        SEND_STRING("ui");
        pre_pressed_key = keycode;
      }
      return false;
      break;
    case DI_AU:
      if (record->event.pressed) {
        // when keycode DI_AU is pressed
        SEND_STRING("au");
        pre_pressed_key = keycode;
      }
      return false;
      break;
    case DI_OI:
      if (record->event.pressed) {
        // when keycode DI_OI is pressed
        SEND_STRING("oi");
        pre_pressed_key = keycode;
      }
      return false;
      break;
    case DI_IU:
      if (record->event.pressed) {
        // when keycode DI_IU is pressed
        SEND_STRING("iu");
        pre_pressed_key = keycode;
      }
      return false;
    case DI_AE:
      if (record->event.pressed) {
        // when keycode DI_AE is pressed
        SEND_STRING("ae");
        pre_pressed_key = keycode;
      }
      return false;
      break;
    case DI_AA:
      if (record->event.pressed) {
        // when keycode DI_AA is pressed
        SEND_STRING("aa");
        pre_pressed_key = keycode;
      }
      return false;
      break;
    case DI_OA:
      if (record->event.pressed) {
        // when keycode DI_OA is pressed
        SEND_STRING("oa");
        pre_pressed_key = keycode;
      }
      return false;
      break;
    case DI_OO:
      if (record->event.pressed) {
        // when keycode DI_OO is pressed
        SEND_STRING("oo");
        pre_pressed_key = keycode;
      }
      return false;
      break;
    case DI_IA:
      if (record->event.pressed) {
        // when keycode DI_IA is pressed
        SEND_STRING("ia");
        pre_pressed_key = keycode;
      }
      return false;
      break;
    case DI_II:
      if (record->event.pressed) {
        // when keycode DI_II is pressed
        SEND_STRING("ii");
        pre_pressed_key = keycode;
      }
      return false;
      break;
    case DI_EA:
      if (record->event.pressed) {
        // when keycode DI_IU is pressed
        SEND_STRING("ea");
        pre_pressed_key = keycode;
      }
      return false;
      break;
    case DI_IO:
      if (record->event.pressed) {
        // when keycode DI_IO is pressed
        SEND_STRING("io");
        pre_pressed_key = keycode;
      }
      return false;
      break;
  //macros for -n
    case DN_UNN:
      if (record->event.pressed) {
        // when keycode DI_UNN is pressed
        SEND_STRING("unn");
        pre_pressed_key = keycode;
      }
      return false;
      break;
    case DN_ANN:
      if (record->event.pressed) {
        // when keycode DI_ANN is pressed
        SEND_STRING("ann");
        pre_pressed_key = keycode;
      }
      return false;
      break;
    case DN_ONN:
      if (record->event.pressed) {
        // when keycode DI_ONN is pressed
        SEND_STRING("onn");
        pre_pressed_key = keycode;
      }
      return false;
      break;
    case DN_INN:
      if (record->event.pressed) {
        // when keycode DI_INN is pressed
        SEND_STRING("inn");
        pre_pressed_key = keycode;
      }
      return false;
      break;
    case DN_ENN:
      if (record->event.pressed) {
        // when keycode DI_ENN is pressed
        SEND_STRING("enn");
        pre_pressed_key = keycode;
      }
      return false;
      break;
    case DN_WO:
      if (record->event.pressed) {
        // when keycode DI_WO is pressed
        SEND_STRING("wo");
        pre_pressed_key = keycode;
      }
      return false;
      break;
    case DN_TSU:
      if (record->event.pressed) {
        // when keycode DI_TSU is pressed
        SEND_STRING("ltsu");
        pre_pressed_key = keycode;
      }
      return false;
      break;
    default:
      pre_pressed_key = keycode;
      break;
  }
  return true;
};
