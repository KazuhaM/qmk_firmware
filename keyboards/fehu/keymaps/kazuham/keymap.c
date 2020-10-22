#include QMK_KEYBOARD_H
#include "bootloader.h"
#include "action_layer.h"
#include"keymap_jp.h"
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
    SFUNC
    
    // TD_LANGN
};

enum custom_keycodes {
      //diphthong codes for JP
  DI_UU= SAFE_RANGE,
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
  DF_WOXLOCK,
  
  //layer change codes
  CL_NTM,
  //for paster
  DF_PST

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

#define KC____ KC_TRNS

//layer change
#define KC_SEN LT(1,KC_SPC)
#define KC_SJP LT(3,KC_SPC)
#define KC_MRK TT(4)
#define KC_NUM TT(5)
#define KC_FNC MO(6)
#define KC_SF MO(7)
#define KC_NTM CL_NTM


//IME change
#define KC_CHIME LALT(KC_GRAVE)
// #define KC_LANN TD(TD_LANGN)
#define KC_IEN IM_EN
#define KC_IJP IM_JP

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
#define KC_WOXL DF_WOXLOCK

//macros for numpad
#define KC_NP0 M(0)
#define KC_NP1 M(1)
#define KC_NP2 M(2)
#define KC_NP3 M(3)
#define KC_NP4 M(4)
#define KC_NP5 M(5)
#define KC_NP6 M(6)
#define KC_NP7 M(7)
#define KC_NP8 M(8)
#define KC_NP9 M(9)
#define KC_NPDOT M(10)
#define KC_NPEQL M(11)
#define KC_NPPLS M(12)
#define KC_NPMNS M(13)
#define KC_NPAST M(14)
#define KC_NPSLS M(15)


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
     KC_SEN , KC_FNC ,  KC_LCTL, LALT_T(KC_SPC) , KC_IEN , KC_CAPS              , KC_NLCK , KC_IJP  , KC_ENT  , KC_MRK  , KC_NUM  , KC_ENT
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
     KC____ , KC____ , KC____ , KC____ , KC____ , KC____                        , KC____  , KC_CHIME, KC____  , KC____  , KC____  , KC____
  //                                    `-------+--------+--------'    `--------+---------+--------'
  ),

  //Japanese base keymap based on sky touch
    [_MSKYTOUCH] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESC , F2 , F3 , F4 , F5 , F6                , F7 , F8 , F9 , F10, F11, F12,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
      ___,COMM, H  , R  , M  , W                 , DUU, DAI, DOU, DOT, DEI, ___,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
      ___, Y  , S  , T  , K  , N                 , U  , A  , O  , I  , E  ,MINS,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
      ___, P  , L  ,DTSU, DWO, DEL               ,BSPC, DAU, DOI, DII, DEA, ___,
  //`----+----+----+----+----+----+----/    \----+----+----+----+----+----+----'
      SJP, ___, ___, ___, IEN, ___               , ___, IJP, ___, ___, ___, ___
  //                  `----+----+----'        `----+----+----'
  ),
  
  //shifted Japanese keymap
    [_SMSKYTOUCH] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ___ , ___, ___, ___, ___, ___               , ___, ___, ___, ___, F23, F24,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     ___ ,SCLN, ___, J  , F  , Q                 , DUI, DAA, DOO,COLN, DIU, ___,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     ___ , ___, Z  , D  , G  , DNN               ,DUNN,DANN,DONN,DINN,DENN,SLSH,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     ___ , B  , V  , P  , B  , ___               ,___ , DAE, DOA, DIA, DIO, ___,
  //`----+----+----+----+----+----+----/    \----+----+----+----+----+----+----'
     ___ , ___, ___, ___,___ , ___               ,___ ,CHIME, ___, ___, ___, ___
  //                  `----+----+----'        `----+----+----'
  ),

  
  

  //mark (symbol) keymap for english (IME: off)
    [_MARK] = LAYOUT(
  //,-------+-----------+-----------+-----------+-----------+-----------.                           ,-----------+-----------+-----------+-----------+-----------+-----------.
     KC____ , KC____    , KC_SLSH   , KC_UNDS   , KC_MINS   , KC_EXLM                               , KC_BSLS   , KC_CIRC   , KC_SCLN   , KC_ASTR   , KC_SCLN   , KC_COLN  ,
  //|-------+-----------+-----------+-----------+-----------+-----------|                           |-----------+-----------+-----------+-----------+-----------+-----------|
     KC____ , KC_LT     , KC_GT     , KC_LBRC   , KC_RBRC   , KC_AMPR                               , KC_EQL    , KC_EXLM   , KC_BSLS   , KC_PERC   , KC_MINS   , KC____    ,
  //|-------+-----------+-----------+-----------+-----------+-----------|                           |-----------+-----------+-----------+-----------+-----------+-----------|
     KC____ , KC_QUOT	  , KC_DQT    , KC_LPRN   , KC_RPRN   , KC_DLR                                , KC_SSTT   , KC_QUES   , KC_AT     , KC_UNDS   , KC_PLUS   , KC_PIPE   ,
  //|-------+-----------+-----------+-----------+-----------+-----------+-----------.    ,----------|-----------+-----------+-----------+-----------+-----------+-----------|
     KC____ , KC_COMM   , KC_GRV    , KC_LCBR   , KC_RCBR   , KC____                                , KC____    , KC_TILD   , KC_HASH   , KC_SLSH   , KC_DOT    , KC____    ,
  //`-------+-----------+-----------+-----------+-----------+-----------+-----------/    \----------+-----------+-----------+-----------+-----------+-----------+-----------'
     KC_SPC , KC____    ,  KC____    , KC____    , KC____    , KC____                                , KC____    , KC____    , KC____    , KC____    , KC____    , KC____
  //                                             `----------+-----------+-----------'    `----------+-----------+-----------'
  ),

  //number and allows keymap for english (IME: off)
    [_NUM] = LAYOUT_kc(
  //,-------+-----------+-----------+-----------+-----------+-----------.                           ,-----------+-----------+-----------+-----------+-----------+-----------.
     ___    , ___       , ___       , ___       , ___       , ___                                   , BSLS      , CIRC      , NPSLS     , NPAST     , SCLN      , CALC      ,
  //|-------+-----------+-----------+-----------+-----------+-----------|                           |-----------+-----------+-----------+-----------+-----------+-----------|
     ___    , LPRN      , HOME      , UP        , END       , AMPR                                  , EQL       , NP7       , NP8       , NP9       , NPMNS     , ___       ,
  //|-------+-----------+-----------+-----------+-----------+-----------|                           |-----------+-----------+-----------+-----------+-----------+-----------|
     ___    , RPRN  	  , LEFT      , DOWN      , RGHT      , DLR                                   , NP0       , NP4       , NP5       , NP6       , NPPLS     , ___      ,
  //|-------+-----------+-----------+-----------+-----------+-----------+-----------.    ,----------|-----------+-----------+-----------+-----------+-----------+-----------|
     ___    , COMM      , PGUP      , COLN      , PGDN      , ___	                                  , ___       , NP1       , NP2       , NP3       , NPDOT     , ___       ,
  //`-------+-----------+-----------+-----------+-----------+-----------+-----------/    \----------+-----------+-----------+-----------+-----------+-----------+-----------'
     SPC    , ___       , ___       , ___       , ___       , ___                                   , ___       , ___       , ___       , NTM       , ___       , NP0
  //                                             `----------+-----------+-----------'    `----------+-----------+-----------'
  ),

  //function keymap for english (IME: off)
    [_FUNC] = LAYOUT(
  //,-------+-----------+-----------+-----------+-----------+-----------.                           ,-----------+-----------+-----------+-----------+-----------+-----------.
  LCA(KC_DEL), KC_F1    , KC_CAPS   , KC_INS    , KC_PSCR   , KC_NLCK                               , KC_MUTE   , KC_VOLD   , KC_VOLU   , KC_WOXG   , KC_WOXS   ,LCA(KC_DEL),
  //|-------+-----------+-----------+-----------+-----------+-----------|                           |-----------+-----------+-----------+-----------+-----------+-----------|
     KC____ , C(KC_Y)   , G(KC_R)   , C(KC_R)   , C(KC_F)   , KC_DRNSH                              , KC_WOXM   , KC_HOME   , KC_UP     , KC_END    , C(KC_P)   , KC____    ,
  //|-------+-----------+-----------+-----------+-----------+-----------|                           |-----------+-----------+-----------+-----------+-----------+-----------|
     KC____ , C(KC_A)   , C(KC_S)   , DF_PST    , A(KC_A)   , KC_WOXP                               , KC_NO     , KC_LEFT   , KC_DOWN   , KC_RGHT   , KC_NO     , KC_NO     ,
  //|-------+-----------+-----------+-----------+-----------+-----------+-----------.    ,----------|-----------+-----------+-----------+-----------+-----------+-----------|
     KC____ , C(KC_Z)   , C(KC_X)   , C(KC_C)   , C(KC_V)   , KC_SPC	                              , KC____    , KC_PGUP   , KC_NO     , KC_PGDN   , KC_NO     , KC____    ,
  //`-------+-----------+-----------+-----------+-----------+-----------+-----------/    \----------+-----------+-----------+-----------+-----------+-----------+-----------'
     KC_NO  , KC____    , KC____    , KC____    , KC____   , KC_SLEP                               , KC_WAKE   , KC____    , KC____    , KC_NO     , KC_SF     , KC_LCTL
  //                                             `----------+-----------+-----------'    `----------+-----------+-----------'
  ),

  //shifted function keymap for english (IME: off)
    [_SFUNC] = LAYOUT(
  //,-------+-----------+-----------+-----------+-----------+-----------.                           ,-----------+-----------+-----------+-----------+-----------+-----------.
     KC____ , KC____    , KC____    , S(KC_INS) , KC____    , KC____                                , KC____    , KC____    , KC____    , KC____    , KC____    , KC____    ,
  //|-------+-----------+-----------+-----------+-----------+-----------|                           |-----------+-----------+-----------+-----------+-----------+-----------|
     KC____ , C(S(KC_Z)), KC____    , KC____    , C(KC_H)   , KC____                                , KC____    , KC____    , KC____    , KC____    , KC____    , KC____    ,
  //|-------+-----------+-----------+-----------+-----------+-----------|                           |-----------+-----------+-----------+-----------+-----------+-----------|
     KC____ , KC____    , KC____    , KC_D      , KC____    , KC____                                , KC____    , KC____    , KC____    , KC____    , KC____    , KC____    ,
  //|-------+-----------+-----------+-----------+-----------+-----------+-----------.    ,----------|-----------+-----------+-----------+-----------+-----------+-----------|
     KC____ , KC____    , KC____    , KC____    , KC____    , KC____	                              , KC____    , KC____    , KC____    , KC____    , KC____    , KC____    ,
  //`-------+-----------+-----------+-----------+-----------+-----------+-----------/    \----------+-----------+-----------+-----------+-----------+-----------+-----------'
     KC____ , KC____    , KC____    , KC____    , KC____    , KC_PWR                                , KC____    , KC____    , KC____    , KC____    , KC____    , KC____
  //                                             `----------+-----------+-----------'    `----------+-----------+-----------'
  ),
};

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
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
  void set_keylog(uint16_t keycode, keyrecord_t *record);
  const char *read_keylog(void);
  const char *read_keylogs(void);
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
      matrix_write_ln(matrix, read_keylog());
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

int os_state_led = 190 ;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    //macros for diphthong
    case DI_UU:
      if (record->event.pressed) {
        // when keycode DI_UU is pressed
        SEND_STRING("uu");
      }
      return false;
      break;
    case DI_AI:
      if (record->event.pressed) {
        // when keycode DI_AI is pressed
        SEND_STRING("ai");
      }
      return false;
      break;
    case DI_OU:
      if (record->event.pressed) {
        // when keycode DI_OU is pressed
        SEND_STRING("ou");
      }
      return false;
      break;
    case DI_EI:
      if (record->event.pressed) {
        // when keycode DI_EI is pressed
        SEND_STRING("ei");
      }
      return false;
      break;
    case DI_UI:
      if (record->event.pressed) {
        // when keycode DI_UI is pressed
        SEND_STRING("ui");
      }
      return false;
      break;
    case DI_AU:
      if (record->event.pressed) {
        // when keycode DI_AU is pressed
        SEND_STRING("au");
      }
      return false;
      break;
    case DI_OI:
      if (record->event.pressed) {
        // when keycode DI_OI is pressed
        SEND_STRING("oi");
      }
      return false;
      break;
    case DI_IU:
      if (record->event.pressed) {
        // when keycode DI_IU is pressed
        SEND_STRING("iu");
      }
      return false;
    case DI_AE:
      if (record->event.pressed) {
        // when keycode DI_AE is pressed
        SEND_STRING("ae");
      }
      return false;
      break;
    case DI_AA:
      if (record->event.pressed) {
        // when keycode DI_AA is pressed
        SEND_STRING("aa");
      }
      return false;
      break;
    case DI_OA:
      if (record->event.pressed) {
        // when keycode DI_OA is pressed
        SEND_STRING("oa");
      }
      return false;
      break;
    case DI_OO:
      if (record->event.pressed) {
        // when keycode DI_OO is pressed
        SEND_STRING("oo");
      }
      return false;
      break;
    case DI_IA:
      if (record->event.pressed) {
        // when keycode DI_IA is pressed
        SEND_STRING("ia");
      }
      return false;
      break;
    case DI_II:
      if (record->event.pressed) {
        // when keycode DI_II is pressed
        SEND_STRING("ii");
      }
      return false;
      break;
    case DI_EA:
      if (record->event.pressed) {
        // when keycode DI_IU is pressed
        SEND_STRING("ea");
      }
      return false;
      break;
    case DI_IO:
      if (record->event.pressed) {
        // when keycode DI_IO is pressed
        SEND_STRING("io");
      }
      return false;
      break;
  //macros for -n
    case DN_UNN:
      if (record->event.pressed) {
        // when keycode DI_UNN is pressed
        SEND_STRING("unn");
      }
      return false;
      break;
    case DN_ANN:
      if (record->event.pressed) {
        // when keycode DI_ANN is pressed
        SEND_STRING("ann");
      }
      return false;
      break;
    case DN_ONN:
      if (record->event.pressed) {
        // when keycode DI_ONN is pressed
        SEND_STRING("onn");
      }
      return false;
      break;
    case DN_INN:
      if (record->event.pressed) {
        // when keycode DI_INN is pressed
        SEND_STRING("inn");
      }
      return false;
      break;
    case DN_ENN:
      if (record->event.pressed) {
        // when keycode DI_ENN is pressed
        SEND_STRING("enn");
      }
      return false;
      break;
    case DN_WO:
      if (record->event.pressed) {
        // when keycode DI_WO is pressed
        SEND_STRING("wo");
      }
      return false;
      break;
    case DN_TSU:
      if (record->event.pressed) {
        // when keycode DI_TSU is pressed
        SEND_STRING("ltsu");
      }
      return false;
      break;
    case DN_NN:
      if (record->event.pressed) {
        // when keycode DN_NN is pressed
        SEND_STRING("nn");
      }
      return false;
      break;
    //macros for marks
    ///////////////////////////////////////////////// (not use)
    case DM_BRCT:
      if (record->event.pressed) {
        // when keycode DM_BRCT is pressed
        SEND_STRING("()"SS_TAP(X_LEFT));
      }
      return false;
      break;
    case DM_BRCTL:
      if (record->event.pressed) {
        // when keycode DM_BRCTL is pressed
        SEND_STRING("[]"SS_TAP(X_LEFT));
      }
      return false;
      break;
    case DM_BRCTM:
      if (record->event.pressed) {
        // when keycode DM_BRCTM is pressed
        SEND_STRING("{}"SS_TAP(X_LEFT));
      }
      return false;
      break;
    //////////////////////////////////////////////////
    case DM_SSTT:
      if (record->event.pressed) {
        // when keycode DM_SSTT is pressed
        SEND_STRING("<-");
      }
      return false;
      break;
  //macros for function
    case DF_RNMSH:
      if (record->event.pressed) {
        // when keycode DF_RNMSH is pressed
        SEND_STRING(SS_LALT("ohr"));
      }
      return false;
      break;
      case DF_WOXSET:
      if (record->event.pressed) {
        // when keycode DF_WOXSET is pressed
        SEND_STRING(SS_LALT("s"));
      }else{
        SEND_STRING(SS_TAP(X_ENTER));
      }
      return false;
      break;
    case DF_WOXML:
      if (record->event.pressed) {
        // when keycode DF_WOXMLis pressed
        SEND_STRING(SS_LALT("m"));
      }else{
        SEND_STRING(SS_TAP(X_ENTER));
      }
      return false;
      break;
    case DF_WOXGMSC:
      if (record->event.pressed) {
        // when keycode DF_WOXGMSC is pressed
        SEND_STRING(SS_LALT("g"));
      }else{
        SEND_STRING(SS_TAP(X_ENTER));
      }
      return false;
      break;
    case DF_WOXPASS:
      if (record->event.pressed) {
        // when keycode DF_WOXPASS is pressed
        SEND_STRING(SS_LALT("p"));
      }else{
        SEND_STRING(SS_TAP(X_ENTER));
      }
      return false;
      break;
    case DF_WOXLOCK:
      if (record->event.pressed) {
        // when keycode DF_WOXPASS is pressed
        SEND_STRING(SS_LALT("l"));
      }else{
        SEND_STRING(SS_TAP(X_ENTER));
      }
      return false;
      break;
  //macros for layer
    case IM_EN:
      if (record->event.pressed) {
        // when keycode IM_EN is pressed
        persistent_default_layer_set(1UL<< 0) ;
        SEND_STRING(SS_TAP(X_F23));
        layer_clear();
        layer_on(0);
        layer_off(2);
      }
      return false;
      break;
    case IM_JP:
      if (record->event.pressed) {
        // when keycode IM_JP is pressed
        //SEND_STRING(SS_TAP(X_LANG5));
        persistent_default_layer_set(1UL<< 2);
        SEND_STRING(SS_TAP(X_F24));
        layer_clear();
        layer_on(2);
        layer_off(0);
      }
      return false;
      break;
    case CL_NTM:
      if (record->event.pressed) {
        // when keycode DF_RNMSH is pressed
        layer_off(5);
        layer_on(4);
      }else{
        layer_off(4);
        layer_on(5);
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
        }
        register_code (KC_LCTL);
        register_code (KC_LALT);
        register_code (KC_G);
        unregister_code (KC_G);
        unregister_code (KC_LALT);
        unregister_code (KC_LCTL);
      }
      return false;
      break;
  }
  return true;
}

//macros for numpad
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    if (record->event.pressed) {
        switch(id) {
            case 0:
                return MACRO(T(NLCK), T(P0), T(NLCK), END);
            case 1:
                return MACRO(T(NLCK), T(P1), T(NLCK), END);
            case 2:
                return MACRO(T(NLCK), T(P2), T(NLCK), END);
            case 3:
                return MACRO(T(NLCK), T(P3), T(NLCK), END);
            case 4:
                return MACRO(T(NLCK), T(P4), T(NLCK), END);
            case 5:
                return MACRO(T(NLCK), T(P5), T(NLCK), END);
            case 6:
                return MACRO(T(NLCK), T(P6), T(NLCK), END);
            case 7:
                return MACRO(T(NLCK), T(P7), T(NLCK), END);
            case 8:
                return MACRO(T(NLCK), T(P8), T(NLCK), END);
            case 9:
                return MACRO(T(NLCK), T(P9), T(NLCK), END);
            case 10:
                return MACRO(T(NLCK), T(PDOT), T(NLCK), END);
            case 11:
                return MACRO(T(NLCK), T(PEQL), T(NLCK), END);
            case 12:
                return MACRO(T(NLCK), T(PPLS), T(NLCK), END);
            case 13:
                return MACRO(T(NLCK), T(PMNS), T(NLCK), END);
            case 14:
                return MACRO(T(NLCK), T(PAST), T(NLCK), END);
            case 15:
                return MACRO(T(NLCK), T(PSLS), T(NLCK), END);
        }
    }
    return MACRO_NONE;
};