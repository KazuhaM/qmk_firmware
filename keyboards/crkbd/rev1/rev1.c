#include "crkbd.h"


#ifdef AUDIO_ENABLE
    float tone_startup[][2] = SONG(STARTUP_SOUND);
    float tone_goodbye[][2] = SONG(GOODBYE_SOUND);
#endif

#ifdef SSD1306OLED
void led_set_kb(uint8_t usb_led) {
    // put your keyboard LED indicator (ex: Caps Lock LED) toggling code here
    //led_set_user(usb_led);
}
#endif

void matrix_init_kb(void) {

<<<<<<< HEAD
    #ifdef AUDIO_ENABLE
        _delay_ms(20); // gets rid of tick
        PLAY_SONG(tone_startup);
    #endif

	matrix_init_user();
};
=======
#ifdef RGB_MATRIX_ENABLE
    if (!isLeftHand) {
        g_led_config = (led_config_t){ {
            {  51,  50,  45,  44,  37,  36 },
            {  52,  49,  46,  43,  38,  35 },
            {  53,  48,  47,  42,  39,  34 },
            { NO_LED, NO_LED, NO_LED,  41,  40,  33 },
            {  24,  23,  18,  17,  10,   9 },
            {  25,  22,  19,  16,  11,   8 },
            {  26,  21,  20,  15,  12,   7 },
            { NO_LED, NO_LED, NO_LED,  14,  13,   6 }
        }, {
            { 139,  16 }, { 174,  13 }, { 208,  20 }, { 208,  38 }, { 174,  48 }, { 139,  52 }, { 129,  63 },
            { 139,  39 }, { 139,  21 }, { 139,   4 }, { 156,   2 }, { 156,  19 }, { 156,  37 }, { 144,  58 },
            { 164,  55 }, { 174,  35 }, { 174,  13 }, { 174,   0 }, { 191,   3 }, { 191,  20 }, { 191,  37 },
            { 208,  42 }, { 208,  24 }, { 208,   7 }, { 224,   7 }, { 224,  24 }, { 224,  41 }, {  85,  16 },
            {  50,  13 }, {  16,  20 }, {  16,  38 }, {  50,  48 }, {  85,  52 }, {  95,  63 }, {  85,  39 },
            {  85,  21 }, {  85,   4 }, {  68,   2 }, {  68,  19 }, {  68,  37 }, {  80,  58 }, {  60,  55 },
            {  50,  35 }, {  50,  13 }, {  50,   0 }, {  33,   3 }, {  33,  20 }, {  33,  37 }, {  16,  42 },
            {  16,  24 }, {  16,   7 }, {   0,   7 }, {   0,  24 }, {   0,  41 }
        }, {
            2, 2, 2, 2, 2, 2, 1,
            4, 4, 4, 4, 4, 4, 1,
            1, 4, 4, 4, 4, 4, 4,
            4, 4, 4, 1, 1, 1, 2,
            2, 2, 2, 2, 2, 1, 4,
            4, 4, 4, 4, 4, 1, 1,
            4, 4, 4, 4, 4, 4, 4,
            4, 4, 1, 1, 1
        } };
    }
#endif
    matrix_init_user();
}
>>>>>>> upstream/master

void shutdown_kb(void) {
    #ifdef AUDIO_ENABLE
        PLAY_SONG(tone_goodbye);
      	_delay_ms(150);
      	stop_all_notes();
    #endif
}
