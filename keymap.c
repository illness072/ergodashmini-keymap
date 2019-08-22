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

#define KC_ KC_NO
#define KC_____ KC_TRNS
#define KC_XXXX KC_NO

#define KC_C_Z LCTL(KC_Z)
#define KC_LOWER LOWER
#define KC_RAISE RAISE
#define KC_ADJ ADJUST

#define KC_VU KC__VOLUP
#define KC_VD KC__VOLDOWN
#define KC_MU KC__MUTE

#define KC_BRU KC_BRMU
#define KC_BRD KC_BRMD

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_kc( \
  //,------+------+------+------+------+------+------.                  ,------+------+------+------+------+------+------.
      TAB  ,  Q   ,  W   ,  E   ,  R   ,  T   , EQL  ,                    MINS ,  Y   ,  U   ,  I   ,  O   ,  P   , GRV  ,
  //|------+------+------+------+------+------+------|                  |------+------+------+------+------+------+------|
      LCTL ,  A   ,  S   ,  D   ,  F   ,  G   , LBRC ,                    RBRC ,  H   ,  J   ,  K   ,  L   , SCLN , QUOT ,
  //|------+------+------+------+------+------+------+------.    ,------+------+------+------+------+------+------+------|
      LSFT ,  Z   ,  X   ,  C   ,  V   ,  B   ,      ,                         ,  N   ,  M   , COMM , DOT  , SLSH , BSLS ,
  //|------+------+------+------+------+------|      |      |    |      |      |------+------+------+------+------+------|
      ESC  ,      , LALT ,    LOWER    , LCMD , LSFT , SPC  ,      SPC  , ENT  , BSPC ,    RAISE    ,      ,      ,
  //`------+------+------+-------------+------+------+------'    `------+------+------+-------------+------+------+------'
  ),

  [_LOWER] = LAYOUT_kc(
  //,------+------+------+------+------+------+------.                  ,------+------+------+------+------+------+------.
           ,  1   ,  2   ,  3   ,  4   ,  5   ,      ,                         ,  6   ,  7   ,  8   ,  9   ,  0   ,      ,
  //|------+------+------+------+------+------+------|                  |------+------+------+------+------+------+------|
           , EXLM , AT   , HASH , DLR  , PERC ,      ,                         , CIRC , AMPR , ASTR , LPRN , RPRN ,      ,
  //|------+------+------+------+------+------+------+------.    ,------+------+------+------+------+------+------+------|
           ,      ,      ,      ,      ,      ,      ,                         ,      ,      ,      ,      ,      ,      ,
  //|------+------+------+------+------+------|      |      |    |      |      |------+------+------+------+------+------|
           ,      ,      ,    LOWER    , LCMD , LSFT , SPC  ,      SPC  , ENT  , BSPC ,    RAISE    ,      ,      ,
  //`------+------+------+-------------+------+------+------'    `------+------+------+-------------+------+------+------'
  ),

  [_RAISE] = LAYOUT_kc(
  //,------+------+------+------+------+------+------.                  ,------+------+------+------+------+------+------.
           ,  F1  ,  F2  ,  F3  ,  F4  ,  F5  ,      ,                         ,  F6  ,  F7  ,  F8  ,  F9  , F10  , F11  ,
  //|------+------+------+------+------+------+------|                  |------+------+------+------+------+------+------|
           ,  VD  ,  VU  ,  MU  ,      ,      ,      ,                         , LEFT , DOWN ,  UP  , RGHT ,      , F12  ,
  //|------+------+------+------+------+------+------+------.    ,------+------+------+------+------+------+------+------|
           , BRD  , BRU  ,      ,      ,      ,      ,                         , HOME , PGDN , PGUP , END  ,      ,      ,
  //|------+------+------+------+------+------|      |      |    |      |      |------+------+------+------+------+------|
           ,      ,      ,    LOWER    , LCMD , LSFT , SPC  ,      SPC  , ENT  , DEL  ,    RAISE    ,      ,      ,
  //`------+------+------+-------------+------+------+------'    `------+------+------+-------------+------+------+------'
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
  }
  return true;
}
