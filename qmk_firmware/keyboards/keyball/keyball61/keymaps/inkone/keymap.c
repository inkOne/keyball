/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "quantum.h"
#include "deferred_exec.h"
#include "keymap_german.h"
#include "rgblight/rgblight.h"


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_universal(
    KC_ESC   , DE_1     , DE_2     , DE_3     , DE_4     , DE_5     ,                                 DE_6     , DE_7     , DE_8     , DE_9     , DE_0     , KC_MINS  ,
    KC_TAB   , DE_Q     , DE_W     , DE_E     , DE_R     , DE_T     ,                                  DE_Z     , DE_U     , DE_I     , DE_O     , DE_P     , KC_LBRC  ,
    KC_LCTL   , DE_A     , DE_S     , DE_D     , DE_F     , DE_G     ,                                  DE_H     , DE_J     , DE_K     , DE_L     ,LT(1,KC_SCLN)  , KC_QUOT ,
    KC_LSFT    , DE_Y     , DE_X     , DE_C     , DE_V     , DE_B     , LT(2,KC_RBRC)  ,              KC_NUHS, DE_N     , DE_M     , DE_COMM  , DE_DOT   , DE_MINS  , KC_RSFT  ,
    MO(3)  , MO(1), KC_LCTL  , KC_LALT  , KC_LGUI, KC_SPC,   MO(2),                         LT(3 ,KC_ENT),LT(2,KC_BSPC),_______,KC_RGUI, _______ , KC_RALT  , _______
  ),


//  [1] = LAYOUT_universal(ö
//    S(KC_ESC), S(KC_1)  , KC_LBRC  , S(KC_3)  , S(KC_4)  , S(KC_5)  ,                             KC_EQL   , S(KC_6)  ,S(KC_QUOT), S(KC_8)  , S(KC_9)  ,S(KC_INT1),
//    S(KC_DEL), S(KC_Q)  , S(KC_W)  , S(KC_E)  , S(KC_R)  , S(KC_T)  ,                                  S(KC_Y)  , S(KC_U)  , S(KC_I)  , S(KC_O)  , S(KC_P)  ,S(KC_INT3),
//    S(KC_TAB), S(KC_A)  , S(KC_S)  , S(KC_D)  , S(KC_F)  , S(KC_G)  ,                                  S(KC_H)  , S(KC_J)  , S(KC_K)  , S(KC_L)  , KC_QUOT  , S(KC_2)  ,
//    _______  , S(KC_Z)  , S(KC_X)  , S(KC_C)  , S(KC_V)  , S(KC_B)  ,S(KC_RBRC),           S(KC_NUHS), S(KC_N)  , S(KC_M)  ,S(KC_COMM), S(KC_DOT),S(KC_SLSH),S(KC_RSFT),
//    _______  ,S(KC_LCTL),S(KC_LALT),S(KC_LGUI), _______  , _______  , _______  ,            _______  , _______  , _______  ,S(KC_RGUI), _______  , S(KC_RALT), _______
//  ),
[1] = LAYOUT_universal(
    KC_F1    ,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,                              KC_F7,    KC_F8,    KC_F9,    KC_F10,    KC_F11,    KC_F12,
    _______  ,    _______, _______,  _______ ,   _______,  _______,                             DE_CIRC,    DE_QUOT,    DE_GRV,    _______,    _______,   _______ ,
    _______  ,    DE_LABK, S(DE_LABK), DE_LPRN,    DE_RPRN, _______,                              DE_LABK,    DE_HASH,    DE_PLUS,    DE_MINS,    _______,    _______,
    _______,    DE_PERC, DE_CIRC, DE_LBRC,   DE_RBRC, _______,  S(KC_8)  ,          S(KC_9)  , KC_PGDN  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______   , _______  , _______  , _______  ,              _______  ,KC_DEL  , _______  , _______  , _______  , _______  , _______
  ),

  [2] = LAYOUT_universal(
    _______  , KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_F5    ,                                  KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   , KC_F11   ,
    _______  , _______  , KC_7     , KC_8     , KC_9     , _______  ,                                  _______  , _______  , _______    , _______  , _______  , KC_F12   ,
    _______  , _______  , KC_4     , KC_5     , KC_6     ,S(KC_SCLN),                                  KC_PGUP  , KC_BTN1  , KC_BTN3  , KC_BTN2  , _______  , _______  ,
    _______  , _______  , KC_1     , KC_2     , KC_3     ,S(KC_MINS), S(KC_8)  ,            S(KC_9)  , KC_PGDN  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , KC_0     , KC_DOT   , _______  , _______  , _______  ,             _______  ,KC_DEL  , _______  , _______  , _______  , _______  , _______
  ),

 // [3] = LAYOUT_universal(
 //   RGB_TOG  , _______  , _______  , _______  , _______  , _______  ,                                  RGB_M_P  , RGB_M_B  , RGB_M_R  , RGB_M_SW , RGB_M_SN , RGB_M_K  ,
//   RGB_TOG  , _______  , _______  , _______  , _______  , _______  ,                                  _______  , _______  , _______  , _______  , _______  , _______  ,
  //  RGB_MOD  , RGB_HUI  , RGB_SAI  , RGB_VAI  , _______  , _______ ,                                  _______  , _______  , _______  , _______  , _______  , _______  ,
  //  RGB_RMOD , RGB_HUD  , RGB_SAD  , RGB_VAD  , _______  , _______  ,                                  CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , KBC_SAVE , KBC_RST  ,
  //  _______  , _______  , SCRL_DVD , SCRL_DVI , SCRL_MO  , SCRL_TO  , EEP_RST  ,            EEP_RST  , KC_HOME  , KC_PGDN  , KC_PGUP  , KC_END   , _______  , _______  ,
  //  RESET    , _______  , KC_LEFT  , KC_DOWN  , KC_UP    , KC_RGHT  , _______  ,            _______  , KC_BSPC  , _______  , _______  , _______  , _______  , RESET
 // ),

  [3] = LAYOUT_universal(
    RGB_TOG  , _______  , _______  , _______  , _______  , _______  ,                                  KC_MPRV , KC_MPLY,    KC_MNXT, KC_MUTE, KC_VOLD , KC_VOLU ,
    _______  ,RGB_MOD  , RGB_HUI  , RGB_SAI  , RGB_VAI  ,  _______ ,                                   KC_HOME  , KC_PAGE_DOWN , KC_PAGE_UP,  KC_END  , KC_BRID,    KC_BRIU,
    _______  ,RGB_RMOD , RGB_HUD  , RGB_SAD  , RGB_VAD  , _______  ,                                  KC_LEFT,  KC_DOWN, KC_UP , KC_RGHT,  _______,    _______,
    _______  , _______  , SCRL_DVD , SCRL_DVI , SCRL_MO  , SCRL_TO  , EEP_RST  ,            EEP_RST  , _______  , _______  , _______  , _______ , _______ , _______  ,
     _______  ,CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , KBC_SAVE , KBC_RST  ,            _______  , _______  , _______  , _______  , _______ , _______ , _______
  ),
[4] = LAYOUT_universal(
    _______  , KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_F5    ,                                  KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   , KC_F11   ,
    _______  , DE_EXLM  , DE_AT    , DE_LCBR  , DE_RCBR  , DE_PIPE  ,                                  DE_QUOT  , DE_UDIA  , _______  , DE_ODIA  , DE_ASTR  , KC_F12   ,
    KC_CAPS  , DE_ADIA  , DE_SS    , DE_LPRN  , DE_RPRN  , DE_GRV   ,                                  DE_DQUO  , DE_DLR   , _______  , DE_HASH  , DE_SCLN  , KC_CAPS  ,
    _______  , DE_PERC  , DE_PLUS  , DE_LBRC  , DE_RBRC  , DE_TILD  , _______  ,            _______  , DE_AMPR  , DE_LABK  , DE_RABK  , _______  , DE_UNDS  , _______  ,
    _______  , _______  , DE_CIRC  , _______  , _______  , _______  , KC_DEL   ,            KC_INS   , DE_EQL   , XXXXXXX  , XXXXXXX  , XXXXXXX  , DE_BSLS  , _______
  ),
};
// clang-format on


//fooker magic
const rgblight_segment_t PROGMEM my_layer_caps[] = RGBLIGHT_LAYER_SEGMENTS(
        {0, RGBLED_NUM, HSV_PURPLE}
);

const rgblight_segment_t PROGMEM my_layer_symbols[] = RGBLIGHT_LAYER_SEGMENTS(
        {0, RGBLED_NUM, HSV_ORANGE}
);

const rgblight_segment_t PROGMEM my_layer_mouse[] = RGBLIGHT_LAYER_SEGMENTS(
        {0, RGBLED_NUM, HSV_PINK}
);

const rgblight_segment_t PROGMEM my_layer_move[] = RGBLIGHT_LAYER_SEGMENTS(
        {0, RGBLED_NUM, HSV_BLUE}
);

const rgblight_segment_t PROGMEM my_layer_conf[] = RGBLIGHT_LAYER_SEGMENTS(
        {0, RGBLED_NUM, HSV_YELLOW}
);

const rgblight_segment_t* const PROGMEM my_layers[] = RGBLIGHT_LAYERS_LIST(
    my_layer_caps,
    my_layer_symbols,
    my_layer_mouse,
    my_layer_move,
    my_layer_conf
);

void keyboard_post_init_user(void) {    // Enable the LED layers
    rgblight_layers = my_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}
layer_state_t layer_state_set_user(layer_state_t state) {
    keyball_set_scroll_mode(get_highest_layer(state) == 1);

    rgblight_set_layer_state(1, layer_state_cmp(state, 1));
    rgblight_set_layer_state(2, layer_state_cmp(state, 2));
    rgblight_set_layer_state(3, layer_state_cmp(state, 3));
    rgblight_set_layer_state(4, layer_state_cmp(state, 4));
    return state;
}

deferred_token mouse_layer_token = INVALID_DEFERRED_TOKEN;

uint32_t mouse_layer_cb(uint32_t trigger_time, void *cb_arg) {
    layer_off(2);
    mouse_layer_token = INVALID_DEFERRED_TOKEN;
    return 0;
}

report_mouse_t pointing_device_task_user(report_mouse_t report) {
    if (report.x != 0 && report.y != 0) {
        layer_on(2);
	if (mouse_layer_token == INVALID_DEFERRED_TOKEN) {
            mouse_layer_token = defer_exec(500, mouse_layer_cb, NULL);
	} else {
            extend_deferred_exec(mouse_layer_token, 500);
        }
    }
    return report;
}


#ifdef OLED_ENABLE
#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
}
#endif
