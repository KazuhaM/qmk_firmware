#include QMK_KEYBOARD_H
#include "bootloader.h"
#include "action_layer.h"
// #include"keymap_jp.h"
#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

extern keymap_config_t keymap_config;

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum {
    MDVORAK = 0,
    SMDVORAK,
    MSKYTOUCH,
    SMSKYTOUCH,
    MARK,
    NUM, //
    FUNC,
    SFUNC,
    FUNCA,
    SFUNCA
    // TD_LANGN
};

enum custom_keycodes {
      //diphthong codes for JP
  AZIK_N= SAFE_RANGE,
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
  DN_NN,
  
  //mark codes
  DM_BRCT,
  DM_BRCTL,
  DM_BRCTM,
  DM_SSTT,

  //IME
  IM_EN,
  IM_JP,

  //function code
  DF_RNMSH,
  DF_WOXSET,
  DF_WOXML,
  DF_WOXGMSC,
  DF_WOXPASS,
  // DF_WOXLOCK,
  DF_CTR2,
  
  // OS change
  OS_CMA,
  OS_CMW,
  CL_FN,
  CL_FS,

  //layer change codes
  CL_NTM,
  //for paster
  DF_PST,

// layer change and modifier
  LMD_LCTL,
  LMD_LALT,
  LMD_LGUI

};

//layer shorthands
#define _MDVORAK 0
#define _SMDVORAK 1
#define _MSKYTOUCH 2
#define _SMSKYTOUCH 3
#define _MARK 4
#define _NUM 5
#define _FUNC 6
#define _SFUNC 7
#define _FUNCA 8
#define _SFUNCA 9
#define _QWERTY 10

#define KC____ KC_TRNS

//layer change
#define KC_SEN LT(1,KC_SPC)
#define KC_SJP LT(3,KC_SPC)
#define KC_MRK TT(4)
#define KC_NUM TT(5)
// #define KC_FNC MO(6)
// #define KC_SF MO(7)
#define KC_NTM CL_NTM
#define KC_CFN CL_FN
#define QWTY TO(10)
#define KC_BLCTL LMD_LCTL
#define KC_BLALT LMD_LALT
#define KC_BLGUI LMD_LGUI

//IME change
#define KC_CHIME LALT(KC_GRAVE)
// #define KC_LANN TD(TD_LANGN)
#define KC_IEN IM_EN
#define KC_IJP IM_JP

// AZIK keys
#define KC_AZN AZIK_N
#define KC_AZK AZIK_K
#define KC_AZT AZIK_T
#define KC_AZS AZIK_S
#define KC_AZY AZIK_Y
#define KC_AZW AZIK_W
#define KC_AZM AZIK_M
#define KC_AZR AZIK_R
#define KC_AZH AZIK_H
#define KC_AZG AZIK_G
#define KC_AZD AZIK_D
#define KC_AZZ AZIK_Z
#define KC_AZF AZIK_F
#define KC_AZJ AZIK_J
#define KC_AZB AZIK_B

//diphthong
#define KC_DUU DI_UU
#define KC_DAI DI_AI
#define KC_DOU DI_OU
#define KC_DEI DI_EI
#define KC_DUI DI_UI
#define KC_DAU DI_AU
#define KC_DOI DI_OI
#define KC_DIU DI_IU
#define KC_DAA DI_AA
#define KC_DAE DI_AE
#define KC_DOO DI_OO
#define KC_DOA DI_OA
#define KC_DII DI_II
#define KC_DIA DI_IA
#define KC_DEA DI_EA
#define KC_DIO DI_IO

//-n
#define KC_DUNN DN_UNN
#define KC_DANN DN_ANN
#define KC_DONN DN_ONN
#define KC_DINN DN_INN
#define KC_DENN DN_ENN

//DN_WO
#define KC_DWO DN_WO
#define KC_DTSU DN_TSU
#define KC_DNN DN_NN

//mark
#define KC_DBRCT DM_BRCT
#define KC_DBRCTL DM_BRCTL
#define KC_DBRCTM DM_BRCTM
#define KC_SSTT DM_SSTT

//function
#define KC_DRNSH DF_RNMSH
#define KC_WOXS DF_WOXSET
#define KC_WOXM DF_WOXML
#define KC_WOXG DF_WOXGMSC
#define KC_WOXP DF_WOXPASS
// #define KC_WOXL DF_WOXLOCK

// //macros for numpad
// #define KC_NP0 M(0)
// #define KC_NP1 M(1)
// #define KC_NP2 M(2)
// #define KC_NP3 M(3)
// #define KC_NP4 M(4)
// #define KC_NP5 M(5)
// #define KC_NP6 M(6)
// #define KC_NP7 M(7)
// #define KC_NP8 M(8)
// #define KC_NP9 M(9)
// #define KC_NPDOT M(10)
// #define KC_NPEQL M(11)
// #define KC_NPPLS M(12)
// #define KC_NPMNS M(13)
// #define KC_NPAST M(14)
// #define KC_NPSLS M(15)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  //English base keymap based on dvorak
	[_MDVORAK] = LAYOUT(
  //,-------+--------+--------+--------+--------+--------.                      ,---------+---------+---------+---------+---------+--------.
     KC_ESC , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6                         , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12 ,
  //|-------+--------+--------+--------+--------+--------|                      |---------+---------+---------+---------+---------+--------|
     KC_TAB , KC_X   , KC_Y   , KC_O   , KC_U   , KC_Q                          , KC_W    , KC_D    , KC_L    , KC_N    , KC_V    , KC_LALT,
  //|-------+--------+--------+--------+--------+--------|                      |---------+---------+---------+---------+---------+--------|
     KC_LGUI, KC_H   , KC_I   , KC_E   , KC_A   , KC_DOT                        , KC_G    , KC_S    , KC_T    , KC_R    , KC_P    , KC_F   ,
  //|-------+--------+--------+--------+--------+--------|                      |---------+---------+---------+---------+---------+--------|
     KC_LSFT, KC_COMM, KC_QUOT, KC_J   , KC_Z   , KC_DEL                        , KC_BSPC , KC_C    , KC_M    , KC_B    , KC_K    , KC_ENT ,
  //`-------+--------+--------+--------+--------+--------+--------/    \--------+---------+---------+---------+---------+---------+--------'
     KC_SEN , CL_FN  , KC_LCTL, OS_CMW , KC_IEN , KC_CAPS              , KC_NLCK, KC_IJP  , OS_CMA  , KC_MRK  , KC_NUM  , KC_ENT
  //                                    `-------+--------+--------'    `--------+---------+--------'
  ),

  //shifted English keymap
    [_SMDVORAK] = LAYOUT(
  //,-------+--------+--------+--------+--------+--------.                      ,---------+---------+---------+---------+---------+--------.
     KC____ , KC____ , KC____ , KC____ , KC____ , KC____                        , KC____  , KC____  , KC____  , KC____  , KC_F23  , KC_F24 ,
  //|-------+--------+--------+--------+--------+--------|                      |---------+---------+---------+---------+---------+--------|
     KC____ , S(KC_X), S(KC_Y), S(KC_O), S(KC_U), S(KC_Q)                       , S(KC_W) , S(KC_D) , S(KC_L) , S(KC_N) , S(KC_V) , KC____ ,
  //|-------+--------+--------+--------+--------+--------|                      |---------+---------+---------+---------+---------+--------|
     KC____ , S(KC_H), S(KC_I), S(KC_E), S(KC_A), KC_COLN                       , S(KC_G) , S(KC_S) , S(KC_T) , S(KC_R) , S(KC_P) , S(KC_F),
  //|-------+--------+--------+--------+--------+--------+--------.    ,--------|---------+---------+---------+---------+---------+--------|
     KC____ , KC_SCLN, KC_DQT , S(KC_J), S(KC_Z), KC____                        , KC____  , S(KC_C) , S(KC_M) , S(KC_B) , S(KC_K) , KC____ ,
  //`-------+--------+--------+--------+--------+--------+--------/    \--------+---------+---------+---------+---------+---------+--------'
     KC____ , KC_LALT, KC____ , KC____ , KC____ , KC____                        , KC____  , KC_CHIME, KC____  , KC____  , KC____  , KC____
  //                                    `-------+--------+--------'    `--------+---------+--------'
  ),

  //Japanese base keymap based on sky touch
    [_MSKYTOUCH] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESC , F2 , F3 , F4 , F5 , F6                , F7 , F8 , F9 , F10, F11, F12,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
      ___,COMM, AZH, AZR, AZM, AZW               , DUU, DAI, DOU, DOT, DEI, BLALT,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
    BLGUI, AZY, AZS, AZT, AZK, AZN               , U  , A  , O  , I  , E  ,MINS,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
      ___, P  , L  ,DTSU, DWO, DEL               ,BSPC, DAU, DOI, DII, DEA, ___,
  //`----+----+----+----+----+----+----/    \----+----+----+----+----+----+----'
      SJP, CFN, BLCTL, ___, IEN, ___               , ___, IJP, ___, ___, ___, ___
  //                  `----+----+----'        `----+----+----'
  ),
  
  //shifted Japanese keymap
    [_SMSKYTOUCH] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ___ , ___, ___, ___, ___, ___               , ___, ___, ___, ___, F23, F24,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     ___ ,SCLN, ___, AZJ, AZF, Q                 , DUI, DAA, DOO,COLN, DIU, ___,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     ___ , ___, AZZ, AZD, AZG, DNN               ,DUNN,DANN,DONN,DINN,DENN,SLSH,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     ___ , AZB, V  , P  , AZB, ___               ,___ , DAE, DOA, DIA, DIO, ___,
  //`----+----+----+----+----+----+----/    \----+----+----+----+----+----+----'
     ___ ,LALT, ___, ___,___ , ___               ,___ ,CHIME, ___, ___, ___, ___
  //                  `----+----+----'        `----+----+----'
  ),

  //mark (symbol) keymap for english (IME: off)
    [_MARK] = LAYOUT(
  //,-------+-----------+-----------+-----------+-----------+-----------.                           ,-----------+-----------+-----------+-----------+-----------+-----------.
     KC____ , KC____    , KC_SLSH   , KC_UNDS   , KC_MINS   , KC_EXLM                               , KC_BSLS   , KC_CIRC   , KC_SCLN   , KC_ASTR   , KC_SCLN   , KC_COLN  ,
  //|-------+-----------+-----------+-----------+-----------+-----------|                           |-----------+-----------+-----------+-----------+-----------+-----------|
     KC____ , KC_LT     , KC_GT     , KC_LBRC   , KC_RBRC   , KC_AMPR                               , KC_EQL    , KC_EXLM   , KC_BSLS   , KC_PERC   , KC_MINS   , KC_LALT   ,
  //|-------+-----------+-----------+-----------+-----------+-----------|                           |-----------+-----------+-----------+-----------+-----------+-----------|
     KC_LGUI, KC_QUOT	  , KC_DQT    , KC_LPRN   , KC_RPRN   , KC_DLR                                , KC_SSTT   , KC_QUES   , KC_AT     , KC_UNDS   , KC_PLUS   , KC_PIPE   ,
  //|-------+-----------+-----------+-----------+-----------+-----------+-----------.    ,----------|-----------+-----------+-----------+-----------+-----------+-----------|
     KC_LSFT, KC_COMM   , KC_GRV    , KC_LCBR   , KC_RCBR   , KC____                                , KC____    , KC_TILD   , KC_HASH   , KC_SLSH   , KC_DOT    , KC____    ,
  //`-------+-----------+-----------+-----------+-----------+-----------+-----------/    \----------+-----------+-----------+-----------+-----------+-----------+-----------'
     KC_SPC , CL_FN     ,  KC_LCTL  , KC____    , KC____    , KC____                                , KC____    , KC____    , KC____    , KC____    , KC____    , KC____
  //                                             `----------+-----------+-----------'    `----------+-----------+-----------'
  ),

  //number and allows keymap for english (IME: off)
    [_NUM] = LAYOUT_kc(
  //,-------+-----------+-----------+-----------+-----------+-----------.                           ,-----------+-----------+-----------+-----------+-----------+-----------.
     ___    , ___       , ___       , ___       , ___       , ___                                   , BSLS      , CIRC      , PSLS      , PAST      , SCLN      , CALC      ,
  //|-------+-----------+-----------+-----------+-----------+-----------|                           |-----------+-----------+-----------+-----------+-----------+-----------|
     ___    , LPRN      , HOME      , UP        , END       , AMPR                                  , EQL       , P7        , P8        , P9        , PMNS      , LALT      ,
  //|-------+-----------+-----------+-----------+-----------+-----------|                           |-----------+-----------+-----------+-----------+-----------+-----------|
     LGUI   , RPRN  	  , LEFT      , DOWN      , RGHT      , DLR                                   , P0        , P4        , P5        , P6        , PPLS      , ___      ,
  //|-------+-----------+-----------+-----------+-----------+-----------+-----------.    ,----------|-----------+-----------+-----------+-----------+-----------+-----------|
     LSFT   , COMM      , PGUP      , COLN      , PGDN      , ___	                                  , ___       , P1        , P2        , P3        , PDOT      , ___       ,
  //`-------+-----------+-----------+-----------+-----------+-----------+-----------/    \----------+-----------+-----------+-----------+-----------+-----------+-----------'
     SPC    , ___       , ___       , ___       , ___       , ___                                   , ___       , ___       , ___       , NTM       , ___       , P0
  //                                             `----------+-----------+-----------'    `----------+-----------+-----------'
  ),

  //function keymap for english (IME: off)
    [_FUNC] = LAYOUT(
  //,-------+-----------+-----------+-----------+-----------+-----------.                           ,-----------+-----------+-----------+-----------+-----------+-----------.
  LCA(KC_DEL), KC_F1    , KC_CAPS   , KC_INS    , KC_PSCR   , KC_NLCK                               , KC_MUTE   , KC_VOLD   , KC_VOLU   , KC_WOXG   , KC_WOXS   ,LCA(KC_DEL),
  //|-------+-----------+-----------+-----------+-----------+-----------|                           |-----------+-----------+-----------+-----------+-----------+-----------|
     KC____ , C(KC_Y)   , G(KC_R)   , C(KC_R)   , C(KC_F)   , KC_DRNSH                              , KC_WOXM   , KC_HOME   , KC_UP     , KC_END    , C(KC_P)   , KC_LALT   ,
  //|-------+-----------+-----------+-----------+-----------+-----------|                           |-----------+-----------+-----------+-----------+-----------+-----------|
     KC_LGUI, C(KC_A)   , C(KC_S)   , DF_PST    , A(KC_A)   , KC_WOXP                               , KC_NO     , KC_LEFT   , KC_DOWN   , KC_RGHT   , KC_NO     , KC_NO     ,
  //|-------+-----------+-----------+-----------+-----------+-----------+-----------.    ,----------|-----------+-----------+-----------+-----------+-----------+-----------|
     KC_LSFT, C(KC_Z)   , C(KC_X)   , C(KC_C)   , C(KC_V)   , KC_SPC	                              , KC____    , KC_PGUP   , KC_NO     , KC_PGDN   , KC_NO     , KC____    ,
  //`-------+-----------+-----------+-----------+-----------+-----------+-----------/    \----------+-----------+-----------+-----------+-----------+-----------+-----------'
     KC_LALT, KC____    , KC____    , KC____    , KC____   , KC_SLEP                               , KC_WAKE   , KC____    , KC____    , KC_NO     , CL_FS      , KC_LCTL
  //                                             `----------+-----------+-----------'    `----------+-----------+-----------'
  ),

  //shifted function keymap for english (IME: off)
    [_SFUNC] = LAYOUT(
  //,-------+-----------+-----------+-----------+-----------+-----------.                           ,-----------+-----------+-----------+-----------+-----------+-----------.
     KC____ , KC_1      , KC_2      , KC_3      , KC_4      , KC_5                                  , KC_6      , KC_7      , KC_8      , KC_9      , KC_0      , QWTY      ,
  //|-------+-----------+-----------+-----------+-----------+-----------|                           |-----------+-----------+-----------+-----------+-----------+-----------|
     KC____ , C(S(KC_Z)), KC____    , KC____    , C(KC_H)   , KC____                                , KC____    , KC____    , KC____    , KC____    , KC____    , KC____    ,
  //|-------+-----------+-----------+-----------+-----------+-----------|                           |-----------+-----------+-----------+-----------+-----------+-----------|
     KC_LGUI, KC____    , KC____    , KC_D      , KC____    , KC____                                , KC____    , KC____    , KC____    , KC____    , KC____    , KC____    ,
  //|-------+-----------+-----------+-----------+-----------+-----------+-----------.    ,----------|-----------+-----------+-----------+-----------+-----------+-----------|
     KC_LSFT, KC____    , KC____    , KC____    , DF_CTR2   , KC____	                              , KC____    , KC____    , KC____    , KC____    , KC____    , KC____    ,
  //`-------+-----------+-----------+-----------+-----------+-----------+-----------/    \----------+-----------+-----------+-----------+-----------+-----------+-----------'
     KC____ , KC____    , KC____    , KC____    , KC____    , KC_PWR                                , KC____    , KC____    , KC____    , KC____    , KC____    , KC____
  //                                             `----------+-----------+-----------'    `----------+-----------+-----------'
  ),

    //shifted function keymap for english (IME: off)
    [_QWERTY] = LAYOUT(
  //,-------+--------+--------+--------+--------+--------.                      ,---------+---------+---------+---------+---------+--------.
     KC____ , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6                         , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12 ,
  //|-------+--------+--------+--------+--------+--------|                      |---------+---------+---------+---------+---------+--------|
     KC____ , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T                          , KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    , KC_DEL,
  //|-------+--------+--------+--------+--------+--------|                      |---------+---------+---------+---------+---------+--------|
     KC_LGUI, KC_A   , KC_S   , KC_D   , KC_F   , KC_G                          , KC_H    , KC_J    , KC_K    , KC_L    , KC_SCLN , KC_BSPC,
  //|-------+--------+--------+--------+--------+--------|                      |--------+---------+---------+---------+---------+--------|
     KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B                          , KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , KC____ ,
  //`-------+--------+--------+--------+--------+--------+--------/    \--------+---------+---------+---------+---------+---------+--------'
     KC_SEN , CL_FN  , KC_LCTL, OS_CMW , KC_IEN , KC_CAPS              , KC_NLCK, KC_IJP  , OS_CMA  , KC_MRK  , KC_NUM  , KC_ENT
  //                                    `-------+--------+--------'    `--------+---------+--------'
  ),

    //function keymap for android
    [_FUNCA] = LAYOUT(
  //,-------+-----------+-----------+-----------+-----------+-----------.                           ,-----------+-----------+-----------+-----------+-----------+-----------.
     KC_NO  , KC_NO     , KC_CAPS   , KC_NO     , KC_NO     , KC_NO                                 , KC_MUTE   , KC_VOLD   , KC_VOLU   , KC_NO     , KC_NO     ,LCA(KC_DEL),
  //,-------+-----------+-----------+-----------+-----------+-----------.                           ,-----------+-----------+-----------+-----------+-----------+-----------.
     KC_ESC , C(KC_Y)   , G(KC_R)   , C(KC_R)   , C(KC_F)   , G(KC_BSPC)                            , G(KC_C)   , KC_HOME   , KC_UP     , KC_END    , C(KC_P)   , KC_LALT   ,
  //|-------+-----------+-----------+-----------+-----------+-----------|                           |-----------+-----------+-----------+-----------+-----------+-----------|
     KC_LGUI, C(KC_A)   , C(KC_S)   , G(KC_B)   , G(KC_ENT) , A(KC_TAB)                             , G(KC_N)   , KC_LEFT   , KC_DOWN   , KC_RGHT   , G(KC_A)   , KC_NO     ,
  //|-------+-----------+-----------+-----------+-----------+-----------+-----------.    ,----------|-----------+-----------+-----------+-----------+-----------+-----------|
     KC_LSFT, C(KC_Z)   , C(KC_X)   , C(KC_C)   , C(KC_V)   , KC_SPC	                              , G(KC_BSPC), KC_PGUP   , KC_NO     , KC_PGDN   , KC_NO     , KC_ENT   ,
  //`-------+-----------+-----------+-----------+-----------+-----------+-----------/    \----------+-----------+-----------+-----------+-----------+-----------+-----------'
     KC_NO  , KC____    , KC____    , KC____    , G(KC_SPC) , KC_SLEP                               , KC_WAKE   , A(KC_GRAVE), KC____    , KC_NO     , CL_FS     , KC_LCTL
  //                                             `----------+-----------+-----------'    `----------+-----------+-----------'
  ),

  //shifted function keymap for android
    [_SFUNCA] = LAYOUT(
  //,-------+-----------+-----------+-----------+-----------+-----------.                           ,-----------+-----------+-----------+-----------+-----------+-----------.
     KC____ , KC____    , KC____    , S(KC_INS) , KC____    , KC____                                , KC____    , KC____    , KC____    , KC____    , KC____    , KC____    ,
  //,-------+-----------+-----------+-----------+-----------+-----------.                           ,-----------+-----------+-----------+-----------+-----------+-----------.
     KC____ , C(S(KC_Z)), KC____    , KC____    , C(KC_H)   , KC____                                , KC____    , KC____    , KC____    , KC____    , KC____    , KC____    ,
  //|-------+-----------+-----------+-----------+-----------+-----------|                           |-----------+-----------+-----------+-----------+-----------+-----------|
     KC____ , KC____    , KC____    , KC_D      , KC____    , KC____                                , KC____    , KC____    , KC____    , KC____    , KC____    , KC____    ,
  //|-------+-----------+-----------+-----------+-----------+-----------+-----------.    ,----------|-----------+-----------+-----------+-----------+-----------+-----------|
     KC____ , KC____    , KC____    , KC____    , KC____    , KC____	                              , KC____    , KC____    , KC____    , KC____   , KC____    , KC____    ,
  //`-------+-----------+-----------+-----------+-----------+-----------+-----------/    \----------+-----------+-----------+-----------+-----------+-----------+-----------'
     KC____ , KC____    , KC____    , KC____    , S(KC_SPC) , KC_PWR                               , KC____    , KC_LANG5   , KC____    , KC____    , KC____    , KC____
  //                                             `----------+-----------+-----------'    `----------+-----------+-----------'
  ),
};

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// dening to change IME when already the layer is or
void IME_change_resist(uint8_t layer1) {
  if (IS_LAYER_ON(layer1)){
    
  } else {
    register_code(KC_LALT);
    tap_code(KC_GRAVE);
    unregister_code(KC_LALT);
  }
}

// // control IME
// void dance_langnime_finished (qk_tap_dance_state_t *state, void *user_data) {
//   if (state->count == 1) {
//     register_code (KC_F23);
//   } else {
//     register_code (KC_F24);
//   }
// }

// void dance_langnime_reset (qk_tap_dance_state_t *state, void *user_data) {
//   if (state->count == 1) {
//     unregister_code (KC_F23);
//   } else {
//     unregister_code (KC_F24);
//   }
// }

// qk_tap_dance_action_t tap_dance_actions[] = {
//   [TD_LANGN]   = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, dance_langnime_finished, dance_langnime_reset,500)
// };


bool OS_State_mode = false;
// int layer_state_tamp = 0;

void matrix_init_user(void) {
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

  // When add source files to SRC in rules.mk, you can use functions.
  const char *read_layer_state(void);
  const char *read_layer_state2(bool OS_State);
  //const char *read_logo(void);
  // void set_keylog(uint16_t keycode, keyrecord_t *record);
  // const char *read_keylog(void);
  // const char *read_keylogs(void);
  // const char *read_rgb_info(void);

  // const char *read_mode_icon(bool swap);
  const char *read_host_led_state(void);
  // void set_timelog(void);
  // const char *read_timelog(void);

  void matrix_scan_user(void) {
    iota_gfx_task();
  }

  void matrix_render_user(struct CharacterMatrix *matrix) {
    if (is_master) {
      // If you want to change the display of OLED, you need to change here
      matrix_write_ln(matrix, read_layer_state());
      // matrix_write_ln(matrix, read_keylog());
      // matrix_write_ln(matrix, read_keylogs());
      // matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
      matrix_write_ln(matrix, read_host_led_state());
      // matrix_write_ln(matrix, read_rgb_info());
      //matrix_write_ln(matrix, read_timelog());
    } else {
      matrix_write(matrix, read_layer_state2(OS_State_mode));
      //matrix_write(matrix, read_logo());
    }
  }

  void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
    if (memcmp(dest->display, source->display, sizeof(dest->display))) {
      memcpy(dest->display, source->display, sizeof(dest->display));
      dest->dirty = true;
    }
  }

  void iota_gfx_task_user(void) {
    struct CharacterMatrix matrix;
    matrix_clear(&matrix);
    matrix_render_user(&matrix);
    matrix_update(&display, &matrix);
  }
#endif//SSD1306OLED
uint16_t pre_pressed_key;
// int os_state_led = 190 ;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
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
          case AZIK_R:
            SEND_STRING("aku");
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
          case AZIK_T:
            SEND_STRING("osi");
            pre_pressed_key = 0;
            break;
          case AZIK_Y:
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
          case AZIK_S:
            SEND_STRING("omo");
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
            SEND_STRING("ara");
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
            SEND_STRING("ara");
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
          case AZIK_F:
            SEND_STRING("uru");
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
          case AZIK_F:
            SEND_STRING("uji");
            pre_pressed_key = 0;
            break;
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
    case DN_NN:
      if (record->event.pressed) {
        // when keycode DN_NN is pressed
        SEND_STRING("nn");
        pre_pressed_key = keycode;
      }
      return false;
      break;
    //macros for marks
    ///////////////////////////////////////////////// (not use)
    // case DM_BRCT:
    //   if (record->event.pressed) {
    //     // when keycode DM_BRCT is pressed
    //     SEND_STRING("()"SS_TAP(X_LEFT));
    //   }
    //   return false;
    //   break;
    // case DM_BRCTL:
    //   if (record->event.pressed) {
    //     // when keycode DM_BRCTL is pressed
    //     SEND_STRING("[]"SS_TAP(X_LEFT));
    //   }
    //   return false;
    //   break;
    // case DM_BRCTM:
    //   if (record->event.pressed) {
    //     // when keycode DM_BRCTM is pressed
    //     SEND_STRING("{}"SS_TAP(X_LEFT));
    //   }
    //   return false;
    //   break;
    //////////////////////////////////////////////////
    case DM_SSTT:
      if (record->event.pressed) {
        // when keycode DM_SSTT is pressed
        SEND_STRING("<-");
        pre_pressed_key = keycode;
      }
      return false;
      break;
  //macros for function
    case DF_RNMSH:
      if (record->event.pressed) {
        // when keycode DF_RNMSH is pressed
        pre_pressed_key = keycode;
        SEND_STRING(SS_LALT("ohr"));
      }
      return false;
      break;
      case DF_WOXSET:
      if (record->event.pressed) {
        // when keycode DF_WOXSET is pressed
        pre_pressed_key = keycode;
        SEND_STRING(SS_LALT("s"));
      }else{
        SEND_STRING(SS_TAP(X_ENTER));
      }
      return false;
      break;
    case DF_WOXML:
      if (record->event.pressed) {
        // when keycode DF_WOXMLis pressed
        pre_pressed_key = keycode;
        SEND_STRING(SS_LALT("m"));
      }else{
        SEND_STRING(SS_TAP(X_ENTER));
      }
      return false;
      break;
    case DF_WOXGMSC:
      if (record->event.pressed) {
        // when keycode DF_WOXGMSC is pressed
        pre_pressed_key = keycode;
        SEND_STRING(SS_LALT("g"));
      }else{
        SEND_STRING(SS_TAP(X_ENTER));
      }
      return false;
      break;
    case DF_WOXPASS:
      if (record->event.pressed) {
        // when keycode DF_WOXPASS is pressed
        pre_pressed_key = keycode;
        SEND_STRING(SS_LALT("p"));
      }else{
        SEND_STRING(SS_TAP(X_ENTER));
      }
      return false;
      break;
    // case DF_WOXLOCK:
    //   if (record->event.pressed) {
    //     // when keycode DF_WOXPASS is pressed
    //     SEND_STRING(SS_LALT("l"));
    //   }else{
    //     SEND_STRING(SS_TAP(X_ENTER));
    //   }
    //   return false;
    //   break;
  //macros for layer
    case IM_EN:
      if (record->event.pressed) {
        if (OS_State_mode){
          persistent_default_layer_set(1UL<< 0) ;
          IME_change_resist(0);
          layer_clear();
          layer_on(0);
          layer_off(2);
          pre_pressed_key = keycode;
        }else{
          // when keycode IM_EN is pressed
          persistent_default_layer_set(1UL<< 0) ;
          SEND_STRING(SS_TAP(X_F23));
          layer_clear();
          layer_on(0);
          layer_off(2);
          pre_pressed_key = keycode;
        }
      }
      return false;
      break;
    case IM_JP:
      if (record->event.pressed) {
        if (OS_State_mode){
          persistent_default_layer_set(1UL<< 2);
          IME_change_resist(2);
          layer_clear();
          layer_on(2);
          layer_off(0);
          pre_pressed_key = keycode;
        }else{
          // when keycode IM_JP is pressed
          //SEND_STRING(SS_TAP(X_LANG5));
          persistent_default_layer_set(1UL<< 2);
          SEND_STRING(SS_TAP(X_F24));
          layer_clear();
          layer_on(2);
          layer_off(0);
          pre_pressed_key = keycode;
        }
      }
      return false;
      break;
    case CL_NTM:
      if (record->event.pressed) {
        // when keycode DF_RNMSH is pressed
        layer_off(5);
        layer_on(4);
        pre_pressed_key = keycode;
      }else{
        layer_off(4);
        layer_on(5);
        pre_pressed_key = keycode;
      }
      return false;
      break;
    case DF_PST:
      if (record->event.pressed) {
        // when keycode DF_RNMSH is pressed
        if ((layer_state / 4) % 2 == 1){
          persistent_default_layer_set(1UL<< 0) ;
          SEND_STRING(SS_TAP(X_F23));
          layer_clear();
          layer_on(0);
          layer_off(2);
          pre_pressed_key = keycode;
        }
        register_code (KC_LCTL);
        register_code (KC_LALT);
        register_code (KC_G);
        unregister_code (KC_G);
        unregister_code (KC_LALT);
        unregister_code (KC_LCTL);
        pre_pressed_key = keycode;
      }
      return false;
      break;
    case DF_CTR2:
      if (record->event.pressed) {
        register_code (KC_LCTL);
        unregister_code (KC_LCTL);
        register_code (KC_LCTL);
        unregister_code (KC_LCTL);
        pre_pressed_key = keycode;
      }
      return false;
      break;
    case OS_CMW:
      if (record->event.pressed) {
        OS_State_mode = false;
        register_code (KC_LCTL);
        register_code (KC_F13);
        unregister_code (KC_F13);
        pre_pressed_key = keycode;
      }else{
        unregister_code (KC_LCTL);
      }
      return false;
      break;
    case OS_CMA:
      if (record->event.pressed) {
        OS_State_mode = true;
        register_code (KC_LCTL);
        register_code (KC_F14);
        unregister_code (KC_F14);
        pre_pressed_key = keycode;
      }else{
        unregister_code (KC_LCTL);
      }
      return false;
      break;
    case CL_FN:
      if (OS_State_mode){
        if (record->event.pressed) {
          layer_on(8);
          pre_pressed_key = keycode;
        }else{
          layer_off(8);
        }
      }else{
        if (record->event.pressed) {
          layer_on(6);
          pre_pressed_key = keycode;
        }else{
          layer_off(6);
        }
      }
      return false;
      break;
    case CL_FS:
      if (OS_State_mode){
        if (record->event.pressed) {
          layer_on(9);
          pre_pressed_key = keycode;
        }else{
          layer_off(9);
        }
      }else{
        if (record->event.pressed) {
          layer_on(7);
          pre_pressed_key = keycode;
        }else{
          layer_off(7);
        }
      }
      return false;
      break;
  // 日本語入力レイヤにおいて、modifierキーを使用するときに英語レイヤに一時変更する
    case LMD_LCTL:
        if (record->event.pressed) {
          persistent_default_layer_set(1UL<< 0);
          layer_clear();
          layer_on(0);

          register_code (KC_LCTL);
          pre_pressed_key = keycode;
        }else{
          unregister_code (KC_LCTL);

          persistent_default_layer_set(1UL<< 2);
          layer_clear();
          layer_on(2);
        }
      return false;
      break;
    case LMD_LALT:
        if (record->event.pressed) {
          persistent_default_layer_set(1UL<< 0);
          layer_clear();
          layer_on(0);

          register_code (KC_LALT);
          pre_pressed_key = keycode;
        }else{
          unregister_code (KC_LALT);
          
          persistent_default_layer_set(1UL<< 2);
          layer_clear();
          layer_on(2);
        }
      return false;
      break;
    case LMD_LGUI:
        if (record->event.pressed) {
          persistent_default_layer_set(1UL<< 0);
          layer_clear();
          layer_on(0);

          register_code (KC_LGUI);
          pre_pressed_key = keycode;
        }else{
          unregister_code (KC_LGUI);
          
          persistent_default_layer_set(1UL<< 2);
          layer_clear();
          layer_on(2);
        }
      return false;
      break;
    case KC_SJP:
      break;
    default:
      pre_pressed_key = keycode;
      break;
  }
  return true;
}

// //macros for numpad
// const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
//     if (record->event.pressed) {
//         switch(id) {
//             case 0:
//                 return MACRO(T(NLCK), T(P0), T(NLCK), END);
//             case 1:
//                 return MACRO(T(NLCK), T(P1), T(NLCK), END);
//             case 2:
//                 return MACRO(T(NLCK), T(P2), T(NLCK), END);
//             case 3:
//                 return MACRO(T(NLCK), T(P3), T(NLCK), END);
//             case 4:
//                 return MACRO(T(NLCK), T(P4), T(NLCK), END);
//             case 5:
//                 return MACRO(T(NLCK), T(P5), T(NLCK), END);
//             case 6:
//                 return MACRO(T(NLCK), T(P6), T(NLCK), END);
//             case 7:
//                 return MACRO(T(NLCK), T(P7), T(NLCK), END);
//             case 8:
//                 return MACRO(T(NLCK), T(P8), T(NLCK), END);
//             case 9:
//                 return MACRO(T(NLCK), T(P9), T(NLCK), END);
//             case 10:
//                 return MACRO(T(NLCK), T(PDOT), T(NLCK), END);
//             case 11:
//                 return MACRO(T(NLCK), T(PEQL), T(NLCK), END);
//             case 12:
//                 return MACRO(T(NLCK), T(PPLS), T(NLCK), END);
//             case 13:
//                 return MACRO(T(NLCK), T(PMNS), T(NLCK), END);
//             case 14:
//                 return MACRO(T(NLCK), T(PAST), T(NLCK), END);
//             case 15:
//                 return MACRO(T(NLCK), T(PSLS), T(NLCK), END);
//         }
//     }
//     return MACRO_NONE;
// };