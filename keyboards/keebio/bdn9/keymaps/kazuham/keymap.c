/* Copyright 2019 Danny Nguyen <danny@keeb.io>
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

enum custom_keycodes {
    //diphthong codes for JP
    CH_LYR= SAFE_RANGE,
    RRTEN_PS,
    ALT_OHR
};

#define KC_ZNRM LCTL(KC_P0) // zoom normal
#define KC_ZNRM2 LCTL(KC_0) // zoom normal
#define KC_RPS RRTEN_PS
// #define TX_C LCTL(KC_C)
// #define TX_V LCTL(KC_V)
// #define TX_X LCTL(KC_X)

int mx_layer = 9;
int mn_layer = 0;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Default layer
        | Knob 1: Vol Dn/Up |                       | Knob 2: レイヤ選択 |
        | Press: Mute       | Hold: Layer  change   | Press: Alt        |
        | PGUP              | Up                    | PGDN              |
        | Left              | Down                  | Right             |
     */
    [0] = LAYOUT(
        KC_MUTE , CH_LYR    , KC_RPS,
        KC_PGUP , KC_UP     , KC_PGDN,
        KC_LEFT , KC_DOWN   , KC_RGHT
    ),
////////////////////////////////////////////////////////////////
    /*zoom
        | Knob 1:zoom by +- |                   | Knob 2: zoom by scroll  |
        | zoom           | Hold: Layer  change  | no |
        | no             | no                   | no |
        | LCTL           | no                   | no |
     */
    [1] = LAYOUT(
        KC_ZNRM , _______   ,_______ ,
        KC_NO    , KC_NO      , KC_NO,
        KC_LCTL    , KC_NO      , KC_NO
    ),
/////////////////////////////////////////////////////////////////
    /*zoom -meeting software
        | Knob 1: Vol Dn/Up |                       | Knob 2: 参加者画像切替   |
        | Press: Mute       | Hold: Layer  change   | Press: ギャラリーモード  |
        | chat              | full screen           | raise my hand      |
        | participants      | video on/off          | voice on/off       |
     */
    [2] = LAYOUT(
        KC_MUTE , _______   ,  _______,
        C(S(KC_H)) , C(S(KC_F))   ,C(S(KC_Y)),
        C(S(KC_U)) , C(S(KC_V))  , C(S(A(KC_A)))
    ),
////////////////////////////////////////////////////////////////
    /*music center
        | Knob 1: Vol Dn/Up |                      | PgUp/Down   |
        | Mute              | Hold: Layer  change  | NO      |
        | add ney playlist  | stop                 | NO              |
        | Media Previous    | start/pause          | Media Next      |
     */
    [3] = LAYOUT(
        KC_MUTE , _______   , _______,
        C(S(KC_N))    , KC_F7      , KC_NO,
        C(KC_LEFT)   , KC_F6     , C(KC_RIGHT)
    ),
////////////////////////////////////////////////////////////////
    /*excel
        | Knob 1:横スクロール    |                      | Knob 2: zoom by scroll  |
        | HOME                  | Hold: Layer  change  | Ctrl                    |
        | NO                    | NO                   | NO                      |
        | NO                    | NO                   | change sheet name       |
*/
    [4] = LAYOUT(
        KC_HOME  , _______   , _______,
        KC_NO    , KC_NO      , KC_NO,
        KC_NO   , KC_NO     , ALT_OHR
    ),
////////////////////////////////////////////////////////////////
    /*word
        | Knob 1:単語移動 |                     | Knob 2: PgDn/Up  |
        | HOME           | Hold: Layer  change | C(HOME)          |
        | NO             | NO                  | NO               |
        | NO             | NO                  | NO               |
*/
    [5] = LAYOUT(
        KC_HOME  , _______   , _______,
        KC_NO    , KC_NO      , KC_NO,
        KC_NO   , KC_NO     , KC_NO
    ),
////////////////////////////////////////////////////////////////
    /*R studio
        | zoom          | Hold: Layer  change | script Tab change |
        | focus source  | show source outline | focus colsole     |
        | zoom left col | show all pane       | zoom right col    |
*/
    [6] = LAYOUT(
        KC_ZNRM2  , _______   , _______,
        C(KC_P1)   , C(S(KC_O))     , C(KC_P2),
        MEH(KC_F12)    , MEH(KC_0)    , MEH(KC_F11)
    ),
    /*premiere pro2
        | zoom  | Hold: Layer  change | ? |
        | up    | down                | M |
        | LSFT  | I                   | O |
*/

    [7] = LAYOUT(
        KC_ZNRM  , _______   , _______,
        KC_UP     , KC_DOWN, KC_M,
        KC_LSFT   , KC_I    , KC_O
    ),
    /*discord -chat software
        | Knob 1: Vol Dn/Up |                     | Knob 2: チャンネル切り替え |
        | Press: Mute       | Hold: Layer  change | Press: K                 |
        | chat scroll up    | NO                  | NO                       |
        | chat scroll down  | speaker mute on/off | mic mute on/off          |
     */
    [8] = LAYOUT(
        KC_MUTE , _______   , _______,
        KC_PGUP , KC_NO     , KC_NO,
        KC_PGDN , C(S(KC_D))  , C(S(KC_M))
    ),
////////////////////////////////////////////////////////////////
    /*LED lighting
        | ON/OFF   | Hold: Layer  change  | NO |
        | Mode     | NO                   | NO |
        | Rev Mode | NO                   | NO |
    */

    [9] = LAYOUT(
        RGB_TOG  , _______   , _______,
        RGB_MOD , KC_NO      , KC_NO,
        RGB_RMOD   , KC_NO     , KC_NO
    ),
};

void matrix_init_user(void) {
  rgblight_enable();
  rgblight_setrgb(0x00,  0xFF, 0xFF);
};

// led color map for each layer
uint8_t rgbmap[][3] = {
    {0xff,  0xff, 0xff},    // layer 0  defualt
    {0xc4,  0x71, 0xc4},    // layer 1  zoom
    {0x00,  0xc9, 0xff},    // layer 2  zoom meeting
    {0xff,  0xc0, 0x00},    // layer 3  music center
    {0x3c,  0xff, 0x90},    // layer 4  excel
    {0x00,  0x50, 0xFF},    // layer 5  word
    {0xc8,  0x00, 0xff},    // layer 6  premiere pro 1
    {0xc8,  0x30, 0xff},    // layer 7  premiere pro 2
    {0x56,  0x8a, 0xd5},    // layer 8  discord
    {0x00,  0x00, 0x00},    // layer 9  LED off
};

void set_layer_led(int sel_layer){
    rgblight_setrgb(rgbmap[sel_layer][0], rgbmap[sel_layer][1], rgbmap[sel_layer][2]);
};

// layer variance indicating now on
int mk_layer = 0;
// variance indicating that layer change key is pushed or not
bool rten_chly = false;


void encoder_update_user(uint8_t index, bool clockwise) {
// layer change
    if (index == 1) {
        if (rten_chly){
            if (clockwise) {
                if (mk_layer < mx_layer){ mk_layer ++; }
            } else {
                if (mk_layer > mn_layer){ mk_layer --; }
            }
            layer_on(mk_layer);
            // rgblight_setrgb(rgbmap[mk_layer][0], rgbmap[mk_layer][1], rgbmap[mk_layer][2]);
            set_layer_led(mk_layer);
            for(int i=0; i < mx_layer; i++) {
                if (mk_layer != i) { layer_off(i); }
            }
        } else{
///////////////////////////////Right rotary encoder///////////////////////////////////////////////////////////////
            if (layer_state_is(0)){
                if (clockwise) {
                    tap_code(KC_TAB);
                } else {
                    register_code(KC_LSFT);
                    tap_code(KC_TAB);
                    unregister_code(KC_LSFT);
                }
            }else if (layer_state_is(1)){
                if (clockwise) {
                    tap_code(KC_WH_U);
                } else {
                    tap_code(KC_WH_D);
                }
            }else if (layer_state_is(2)) {
                if (clockwise) {
                    tap_code(KC_PGDN);
                } else {
                    tap_code(KC_PGUP);
                }
            }else if (layer_state_is(3)){
                if (clockwise) {
                    tap_code(KC_PGDN);
                } else {
                    tap_code(KC_PGUP);
                }
            }else if (layer_state_is(4)){
                if (clockwise) {
                    tap_code(KC_WH_U);
                } else {
                    tap_code(KC_WH_D);
                }
            }else if (layer_state_is(5)){
                if (clockwise) {
                    tap_code(KC_PGDN);
                } else {
                    tap_code(KC_PGUP);
                }
            }else if (layer_state_is(6)){
                if (clockwise) {
                    register_code(KC_LCTL);
                    tap_code(KC_TAB);
                    unregister_code(KC_LCTL);
                } else {
                    register_code(KC_LCTL);
                    register_code(KC_LSFT);
                    tap_code(KC_TAB);
                    unregister_code(KC_LSFT);
                    unregister_code(KC_LCTL);
                }
            }else if (layer_state_is(7)){
                if (clockwise) {
                    tap_code(KC_L);
                } else {
                    tap_code(KC_J);
                }
            }else if (layer_state_is(8)){
                if (clockwise) {
                    register_code(KC_LALT);
                    tap_code(KC_DOWN);
                    unregister_code(KC_LALT);
                } else {
                    register_code(KC_LALT);
                    tap_code(KC_UP);
                    unregister_code(KC_LALT);
                }
            // }else if (layer_state_is(8)){
            //     if (clockwise) {
            //         register_code(RGB_VAI);
            //         unregister_code(RGB_VAI);
            //     } else {
            //         register_code(RGB_VAD);
            //         unregister_code(RGB_VAD);

            //     }
            }
        }
    }
///////////////////////////////Left rotary encoder///////////////////////////////////////////////////////////////
    else if (index == 0) {
        if (layer_state_is(0)){
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        }else if (layer_state_is(1)){
            if (clockwise) {
                // SEND_STRING(SS_LCTRL("1")); // audacity zoom in
                SEND_STRING(SS_LCTRL("+")); // audacity zoom in
            } else {
                // SEND_STRING(SS_LCTRL("3")); // audacity zoom out
                SEND_STRING(SS_LCTRL("-")); // audacity zoom out
            }
        }else if (layer_state_is(2)) {
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        }else if (layer_state_is(3)){
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        }else if (layer_state_is(4)){
            if (clockwise) {
                register_code(KC_LALT);
                tap_code(KC_PGDN);
                unregister_code(KC_LALT);
            } else {
                register_code(KC_LALT);
                tap_code(KC_PGUP);
                unregister_code(KC_LALT);
            }
        }else if (layer_state_is(5)){
            if (clockwise) {
                register_code(KC_LCTL);
                tap_code(KC_RIGHT);
                unregister_code(KC_LCTL);
            } else {
                register_code(KC_LCTL);
                tap_code(KC_LEFT);
                unregister_code(KC_LCTL);
            }
        }else if (layer_state_is(6)){
            if (clockwise) {
                // SEND_STRING(SS_LCTRL("1")); // audacity zoom in
                SEND_STRING(SS_LCTRL("+")); // audacity zoom in
            } else {
                // SEND_STRING(SS_LCTRL("3")); // audacity zoom out
                SEND_STRING(SS_LCTRL("-")); // audacity zoom out
            }
        }else if (layer_state_is(7)){
            if (clockwise) {
                // SEND_STRING(SS_LCTRL("1")); // audacity zoom in
                SEND_STRING(SS_LCTRL("^")); // audacity zoom in
            } else {
                // SEND_STRING(SS_LCTRL("3")); // audacity zoom out
                SEND_STRING(SS_LCTRL("-")); // audacity zoom out
            }
        }else if (layer_state_is(8)) {
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        // }else if (layer_state_is(8)){
        //     if (clockwise) {
        //         tap_code(RGB_MOD);
        //     } else {
        //         tap_code(RGB_RMOD);
        //     }
        }
    }
}

///////////////////////////////Macro///////////////////////////////////////////////////////////////
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // right rotary encoder changes layer when top center key is pushed
        case CH_LYR:
            if (record->event.pressed) {
                rten_chly = true;
            }else{
                rten_chly = false;
            }
            return false;
            break;
        // right encoder push key
        case RRTEN_PS:
            if (rten_chly){
                if (record->event.pressed) {
                    layer_clear();
                    layer_on(0);
                    set_layer_led(0);
                    mk_layer = 0;
                }
            }else{
                if (layer_state_is(0)){
                    if (record->event.pressed) {
                        register_code(KC_LALT);
                    }else{
                        unregister_code(KC_LALT);
                    }
                }else if (layer_state_is(1)) {
                    if (record->event.pressed) {
                        register_code(KC_LCTL);
                    } else{
                        unregister_code(KC_LCTL);
                    }
                }else if (layer_state_is(2)) {
                    if (record->event.pressed) {
                        register_code(KC_LCTL);
                        register_code(KC_LSFT);
                        tap_code(KC_F2);
                        unregister_code(KC_LSFT);
                        unregister_code(KC_LCTL);
                    }
                }else if (layer_state_is(3)) {
                    if (record->event.pressed) {
                    }
                }else if (layer_state_is(4)) {
                    if (record->event.pressed) {
                        register_code(KC_LCTL);
                    } else{
                        unregister_code(KC_LCTL);
                    }
                }else if (layer_state_is(5)) {
                    if (record->event.pressed) {
                        register_code(KC_LCTL);
                        tap_code(KC_HOME);
                        unregister_code(KC_LCTL);
                    }
                }else if (layer_state_is(6)) {
                    if (record->event.pressed) {
                        register_code(KC_LCTL);
                        register_code(KC_LSFT);
                        tap_code(KC_DOT);
                        unregister_code(KC_LSFT);
                        unregister_code(KC_LCTL);
                    }
                }else if (layer_state_is(7)) {
                    if (record->event.pressed) {
                        // tap_code(KC_K);
                    }
                }else if (layer_state_is(8)) {
                    if (record->event.pressed) {
                        tap_code(KC_K);
                    }
                }

            }
            return false;
            break;
        case ALT_OHR:
            if (record->event.pressed) {
                tap_code(KC_LALT);
            }else{
                tap_code(KC_O);
                tap_code(KC_H);
                tap_code(KC_R);
            }
            return false;
            break;
    }
    return true;
};
