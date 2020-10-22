#include QMK_KEYBOARD_H
extern midi_config_t midi_config;

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _MRKNUM,
    _FN
};


#define FN MO(_FN)
#define SP_MN LT(_MRKNUM, KC_SPACE)
#define FN_MUTE LT(_FN, KC_MUTE)

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {

    // MIDI Chord Keycodes - Root notes

    MI_CH_Cr = SAFE_RANGE,
    MI_CH_Csr,
    MI_CH_Dbr = MI_CH_Csr,
    MI_CH_Dr,
    MI_CH_Dsr,
    MI_CH_Ebr = MI_CH_Dsr,
    MI_CH_Er,
    MI_CH_Fr,
    MI_CH_Fsr,
    MI_CH_Gbr = MI_CH_Fsr,
    MI_CH_Gr,
    MI_CH_Gsr,
    MI_CH_Abr = MI_CH_Gsr,
    MI_CH_Ar,
    MI_CH_Asr,
    MI_CH_Bbr = MI_CH_Asr,
    MI_CH_Br,

    // MIDI Chord Keycodes - Major

    MI_CH_C,
    MI_CH_Cs,
    MI_CH_Db = MI_CH_Cs,
    MI_CH_D,
    MI_CH_Ds,
    MI_CH_Eb = MI_CH_Ds,
    MI_CH_E,
    MI_CH_F,
    MI_CH_Fs,
    MI_CH_Gb = MI_CH_Fs,
    MI_CH_G,
    MI_CH_Gs,
    MI_CH_Ab = MI_CH_Gs,
    MI_CH_A,
    MI_CH_As,
    MI_CH_Bb = MI_CH_As,
    MI_CH_B,

    // MIDI Chord Keycodes Minor

    MI_CH_Cm,
    MI_CH_Csm,
    MI_CH_Dbm = MI_CH_Csm,
    MI_CH_Dm,
    MI_CH_Dsm,
    MI_CH_Ebm = MI_CH_Dsm,
    MI_CH_Em,
    MI_CH_Fm,
    MI_CH_Fsm,
    MI_CH_Gbm = MI_CH_Fsm,
    MI_CH_Gm,
    MI_CH_Gsm,
    MI_CH_Abm = MI_CH_Gsm,
    MI_CH_Am,
    MI_CH_Asm,
    MI_CH_Bbm = MI_CH_Asm,
    MI_CH_Bm,

    //MIDI Chord Keycodes Dominant Seventh

    MI_CH_CDom7,
    MI_CH_CsDom7,
    MI_CH_DbDom7 = MI_CH_CsDom7,
    MI_CH_DDom7,
    MI_CH_DsDom7,
    MI_CH_EbDom7 = MI_CH_DsDom7,
    MI_CH_EDom7,
    MI_CH_FDom7,
    MI_CH_FsDom7,
    MI_CH_GbDom7 = MI_CH_FsDom7,
    MI_CH_GDom7,
    MI_CH_GsDom7,
    MI_CH_AbDom7 = MI_CH_GsDom7,
    MI_CH_ADom7,
    MI_CH_AsDom7,
    MI_CH_BbDom7 = MI_CH_AsDom7,
    MI_CH_BDom7,

    // MIDI Chord Keycodes Diminished Seventh

    MI_CH_CDim7,
    MI_CH_CsDim7,
    MI_CH_DbDim7 = MI_CH_CsDim7,
    MI_CH_DDim7,
    MI_CH_DsDim7,
    MI_CH_EbDim7 = MI_CH_DsDim7,
    MI_CH_EDim7,
    MI_CH_FDim7,
    MI_CH_FsDim7,
    MI_CH_GbDim7 = MI_CH_FsDim7,
    MI_CH_GDim7,
    MI_CH_GsDim7,
    MI_CH_AbDim7 = MI_CH_GsDim7,
    MI_CH_ADim7,
    MI_CH_AsDim7,
    MI_CH_BbDim7 = MI_CH_AsDim7,
    MI_CH_BDim7,

};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT(
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,    KC_MINS,   KC_DEL,
    KC_LCTL,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_BSPC,
    KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
    FN_MUTE ,  KC_LALT,  KC_LGUI,  IM_EN ,  SP_MN,  KC_ENT ,   IM_JP , KC_RGUI,  KC_RALT,    KC_RCTL
  ),

  [_MRKNUM] = LAYOUT(
    KC_GRV ,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_EQL,  KC_BSLS,
    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,     KC_QUOT,     KC_LBRC,  KC_RBRC,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_PGUP,     KC_PGDN,     KC_HOME,     KC_UP,    KC_END,
    _______,  _______,  _______,  _______,          _______,  _______,                   _______,     KC_LEFT,  KC_DOWN,  KC_RGHT
  ),

  [_MUSE] = LAYOUT(
    _______ , _______,  _______,   MI_B_2,   MI_D_3,   MI_F_3,   MI_Ab_3, MI_B_3,   MI_D_4,   MI_F_4,   MI_Ab_4,  MI_B_4,     _______,
    _______,    _______,    MI_Bb_2,   MI_Db_3,   MI_E_3,   MI_G_3,  MI_Bb_3,  MI_Db_4,  MI_E_4,   MI_G_4,   MI_Bb_4,  _______,
    _______,         MI_A_2,   MI_C_3,   MI_Eb_3,  MI_Fs_3,  MI_A_3,  MI_C_4,   MI_Eb_4,  MI_Fs_4,   MI_A_4,    _______, _______,
    _______ ,  _______,  _______,  _______,          _______,  _______,                   _______,     _______,  _______,  _______
  ),

  [_FN] = LAYOUT(
    _______ ,   _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,  _______,
    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,     _______,     _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,     _______,     _______,     _______,    _______,
    _______,  TO(_MUSE),  TO(_BASE),  _______,          _______,  _______,                   _______,     _______,  _______,  _______
  ),

};

void keyboard_post_init_user(void) {
    //  Set otave to MI_OCT_0
    midi_config.octave = MI_OCT_0 - MIDI_OCTAVE_MIN;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint16_t root_note = MIDI_INVALID_NOTE;  // Starting value for the root note of each chord

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
        // case MOFN:
        //     if (record->event.pressed) {
        //         layer_off();
        //         layer_on();
        //     }else{
        //         layer_on();
        //         layer_off();
        //     }
        //     return false;
        //     break;
        // MIDI Chord Keycodes, on the left side.
        case MI_CH_Cr ... MI_CH_Br:  // Root Notes
            root_note = keycode - MI_CH_Cr + MI_C_1;
            process_midi(root_note, record);
            process_midi(root_note + 12, record);  // -1 Octave
            // process_midi(root_note + 24, record);  // +1 Octave
            break;

        case MI_CH_C ... MI_CH_B:  // Major Chords
            root_note = keycode - MI_CH_C + MI_C_2;
            process_midi(root_note, record);
            process_midi(root_note + 4, record);  // Major Third Note
            process_midi(root_note + 7, record);  // Fifth Note
            break;

        case MI_CH_Cm ... MI_CH_Bm:  // Minor Chord
            root_note = keycode - MI_CH_Cm + MI_C_2;
            process_midi(root_note, record);
            process_midi(root_note + 3, record);  // Minor Third Note
            process_midi(root_note + 7, record);  // Fifth Note
            break;

        case MI_CH_CDom7 ... MI_CH_BDom7:  // Dominant 7th Chord
            root_note = keycode - MI_CH_CDom7 + MI_C_2;
            process_midi(root_note, record);
            process_midi(root_note + 4, record);   // Major Third Note
            process_midi(root_note + 10, record);  // Minor Seventh Note
            break;

        case MI_CH_CDim7 ... MI_CH_BDim7:                // Diminished 7th Chord
            root_note = keycode - MI_CH_CDim7 + MI_C_2;
            process_midi(root_note, record);
            process_midi(root_note + 3, record);  // Minor Third Note
            process_midi(root_note + 6, record);  // Diminished 5th Note
            break;
    }
    return true;
}
