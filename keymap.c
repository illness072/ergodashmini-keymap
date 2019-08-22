#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
};

#define EISU LALT(KC_GRV)
#define KCX_PW KC_POWER
#define KCX_VU KC__VOLUP
#define KCX_VD KC__VOLDOWN
#define KCX_MU KC__MUTE

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |   =  ||||||||||||||||||||||   -  |   Y  |   U  |   I  |   O  |   P  |   `  |
   * |------+------+------+------+------+------+------||||||||||||||||||||||------+------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  |   [  ||||||||||||||||||||||   ]  |   H  |   J  |   K  |   L  |   ;  |   '  |
   * |------+------+------+------+------+------+======+======||||||||======+======+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  | Raise|      ||||||||      | Lower|   N  |   M  |   ,  |   .  |   /  |   \  |
   * |-------------+------+------+------+======+------| Space|||||||| Space|------+======+------+------+------+------+------|
   * | Esc  |      |  Alt |||||||| Lower| Cmd  | Shift|      ||||||||      | Enter| Bksp | Raise||||||||      |      |Adjust|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT( \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_EQL ,                        KC_MINS, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_GRV , \
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LBRC,                        KC_RBRC, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    RAISE  ,                        LOWER  , KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS, \
    KC_ESC,  XXXXXXX, KC_LALT,          LOWER  , KC_LCMD, KC_LSFT, KC_SPC,       KC_SPC,  KC_ENT,  KC_BSPC, RAISE  ,          XXXXXXX, XXXXXXX, ADJUST   \
  ),

  /* Lower
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | Tab  |   1  |   2  |   3  |   4  |   5  |   +  ||||||||||||||||||||||   _  |   6  |   7  |   8  |   9  |   0  |   ~  |
   * |------+------+------+------+------+------+------||||||||||||||||||||||------+------+------+------+------+------+------|
   * | Ctrl |   !  |   @  |   #  |   $  |   %  |   {  ||||||||||||||||||||||   }  |   ^  |   &  |   *  |   (  |   )  |   "  |
   * |------+------+------+------+------+------+======+======||||||||======+======+------+------+------+------+------+------|
   * | Shift|      |      |      |      |      | Raise|      ||||||||      | Lower|      |      |   ,  |   .  |   /  |   |  |
   * |-------------+------+------+------+======+------| Space|||||||| Space|------+======+------+------+------+------+------|
   * | Esc  |      |  Alt |||||||| Lower| Cmd  | Shift|      ||||||||      | Enter| Bksp | Raise||||||||      |      |Adjust|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_LOWER] = LAYOUT(
    KC_TAB,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_PLUS,                        KC_UNDS, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TILD, \
    KC_LCTL, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_LCBR,                        KC_RCBR, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DQT,  \
    KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RAISE  ,                        LOWER  , XXXXXXX, XXXXXXX, KC_COMM, KC_DOT,  KC_SLSH, KC_PIPE, \
    KC_ESC,  XXXXXXX, KC_LALT,          LOWER  , KC_LCMD, KC_LSFT, KC_SPC,       KC_SPC,  KC_ENT,  KC_BSPC, RAISE  ,          XXXXXXX, XXXXXXX, ADJUST   \
  ),

  /* Raise
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | Tab  |  F1  |  F2  |  F3  |  F4  |  F5  |  F11 ||||||||||||||||||||||  F12 |  F6  |  F7  |  F8  |  F9  |  F10 |      |
   * |------+------+------+------+------+------+------||||||||||||||||||||||------+------+------+------+------+------+------|
   * | Ctrl |  F11 |  F12 |      |      |      |      ||||||||||||||||||||||      | Left | Down |  Up  | Right|      |      |
   * |------+------+------+------+------+------+======+======||||||||======+======+------+------+------+------+------+------|
   * | Shift|      |      |      |      |      | Raise|      ||||||||      | Lower| Home |PageDn|PageUp| End  |      |      |
   * |-------------+------+------+------+======+------| Space|||||||| Space|------+======+------+------+------+------+------|
   * | Esc  |      |  Alt |||||||| Lower| Cmd  | Shift|      ||||||||      | Enter|  Del | Raise||||||||      |      |Adjust|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_RAISE] = LAYOUT(
    KC_TAB,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11 ,                        KC_F12 , KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  XXXXXXX, \
    KC_LCTL, KC_F11 , KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, XXXXXXX, XXXXXXX, \
    KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RAISE  ,                        LOWER  , KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX, XXXXXXX, \
    KC_ESC,  XXXXXXX, KC_LALT,          LOWER  , KC_LCMD, KC_LSFT, KC_SPC,       KC_SPC,  KC_ENT,  KC_DEL,  RAISE  ,          XXXXXXX, XXXXXXX, ADJUST   \
    ),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
  }
  return true;
}
