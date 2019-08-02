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
  ADJUST,
};

#define EISU LALT(KC_GRV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |   -  |                    |   =  |   Y  |   U  |   I  |   O  |   P  |   \  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  |   [  |                    |   ]  |   H  |   J  |   K  |   L  |   ;  |   '  |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |   \  |                    |   `  |   N  |   M  |   ,  |   .  |   /  |   `  |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Esc  |      |  ALt |||||||| Cmd  | Lower| Shift| Space|||||||| Space| Enter| Raise| Bksp ||||||||      |   -  |   =  |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT( \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_MINS,                        KC_EQL , KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LBRC,                        KC_RBRC, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_BSLS,                        KC_GRV , KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_GRV , \
    KC_ESC,  XXXXXXX, KC_LALT,          KC_LCMD, LOWER,   KC_LSFT, KC_SPC,        KC_SPC, KC_ENT,  RAISE,   KC_BSPC,          XXXXXXX, KC_MINS, KC_EQL   \
  ),

  /* Lower
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | Tab  |   1  |   2  |   3  |   4  |   5  |   _  |                    |   +  |   6  |   7  |   8  |   9  |   0  |   |  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl |   !  |   @  |   #  |   $  |   %  |   {  |                    |   }  |   ^  |   &  |   *  |   (  |   )  |   "  |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|      |      |      |      |      |   |  |                    |   ~  |      |      |      |      |      |   ~  |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Esc  |      | ALt  |||||||| Cmd  | Lower| Shift| Space|||||||| Space| Enter| Raise|Delete||||||||      |   _  |   +  |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_LOWER] = LAYOUT(
    KC_TAB,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_UNDS,                        KC_PLUS, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PIPE,  \
    KC_LCTL, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_LCBR,                        KC_RCBR, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DQT,  \
    KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PIPE,                        KC_TILD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TILD, \
    KC_ESC,  XXXXXXX, KC_LALT,          KC_LCMD, LOWER,   KC_LSFT, KC_SPC,        KC_SPC, KC_ENT,  RAISE,   KC_DEL,           XXXXXXX, KC_UNDS, KC_PLUS  \
  ),

  /* Raise
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | Tab  |  F1  |  F2  |  F3  |  F4  |  F5  |   _  |                    |   +  |  F6  |  F7  |  F8  |  F9  |  F10 |   |  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl |  F11 |  F12 |      |      |      |   {  |                    |   }  | Left | Down |  Up  | Right|      |   "  |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|      |      |      |      |      |   |  |                    |   ~  | Home |PageDn|PageUp| End  |      |   ~  |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Esc  |      | Alt  |||||||| Cmd  | Lower| Shift| Space|||||||| Space| Enter| Raise|Delete||||||||      |   _  |   +  |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_RAISE] = LAYOUT(
    KC_TAB,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_UNDS,                        KC_PLUS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_PIPE,  \
    KC_LCTL, KC_F11 , KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, KC_LCBR,                        KC_RCBR, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, XXXXXXX, KC_DQT,  \
    KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PIPE,                        KC_TILD, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX, KC_TILD, \
    KC_ESC,  XXXXXXX, KC_LALT,          KC_LCMD, LOWER,   KC_LSFT, KC_SPC,        KC_SPC, KC_ENT,  RAISE,   KC_DEL,           XXXXXXX, KC_UNDS, KC_PLUS  \
    ),

  /* Adjust
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | POWER|      | PSCR |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      | VOL- | VOL+ | MUTE |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      | BRI- | BRI+ |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+-------------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      ||||||||      |      |      |      ||||||||      |      |      |      ||||||||      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_ADJUST] = LAYOUT(
    KC_POWER,XXXXXXX, KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX,KC__VOLDOWN,KC__VOLUP,KC__MUTE,XXXXXXX,XXXXXXX,XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, KC_BRMD, KC_BRMU, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX,XXXXXXX,XXXXXXX,         XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX  \
  )
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
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
