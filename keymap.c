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
#define KC_______ KC_TRNS
#define KC_XXXXXX KC_NO

#define KC_C_Z LCTL(KC_Z)
#define KC_LOWER LOWER
#define KC_RAISE RAISE

#define KC_LSPC LT(_LOWER, KC_SPC)
#define KC_RSPC LT(_RAISE, KC_SPC)

#define KC_VU KC__VOLUP
#define KC_VD KC__VOLDOWN
#define KC_MU KC__MUTE

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_kc( \
  //,------+------+------+------+------+------+------.                  ,------+------+------+------+------+------+------.
      TAB  ,  Q   ,  W   ,  E   ,  R   ,  T   ,XXXXXX,                   XXXXXX,  Y   ,  U   ,  I   ,  O   ,  P   , MINS ,
  //|------+------+------+------+------+------+------|                  |------+------+------+------+------+------+------|
      LCTL ,  A   ,  S   ,  D   ,  F   ,  G   ,XXXXXX,                   XXXXXX,  H   ,  J   ,  K   ,  L   , SCLN , QUOT ,
  //|------+------+------+------+------+------+------+------.    ,------+------+------+------+------+------+------+------|
      LSFT ,  Z   ,  X   ,  C   ,  V   ,  B   ,      ,                         ,  N   ,  M   , COMM , DOT  , SLSH , BSLS ,
  //|------+------+------+------+------+------|      |      |    |      |      |------+------+------+------+------+------|
     XXXXXX,XXXXXX,XXXXXX,     LALT    , LCMD , LSFT , LSPC ,      RSPC , ENT  , BSPC ,             ,XXXXXX,XXXXXX,XXXXXX
  //`------+------+------+-------------+------+------+------'    `------+------+------+-------------+------+------+------'
  ),

  [_LOWER] = LAYOUT_kc(
  //,------+------+------+------+------+------+------.                  ,------+------+------+------+------+------+------.
      ESC  ,  1   ,  2   ,  3   ,  4   ,  5   ,XXXXXX,                   XXXXXX,  6   ,  7   ,  8   ,  9   ,  0   ,      ,
  //|------+------+------+------+------+------+------|                  |------+------+------+------+------+------+------|
           , EXLM , AT   , HASH , DLR  , PERC ,XXXXXX,                   XXXXXX, CIRC , AMPR , ASTR , LPRN , RPRN ,      ,
  //|------+------+------+------+------+------+------+------.    ,------+------+------+------+------+------+------+------|
           , PLUS , EQL  , LCBR , LBRC , LPRN ,      ,                         , RPRN , RBRC , RCBR , GRV  , TILD ,      ,
  //|------+------+------+------+------+------|      |      |    |      |      |------+------+------+------+------+------|
     XXXXXX,XXXXXX,XXXXXX,     LALT    , LCMD , LSFT , LSPC ,      RSPC , ENT  , BSPC ,             ,XXXXXX,XXXXXX,XXXXXX
  //`------+------+------+-------------+------+------+------'    `------+------+------+-------------+------+------+------'
  ),

  [_RAISE] = LAYOUT_kc(
  //,------+------+------+------+------+------+------.                  ,------+------+------+------+------+------+------.
      ESC  ,  F1  ,  F2  ,  F3  ,  F4  ,  F5  ,XXXXXX,                   XXXXXX,  F6  ,  F7  ,  F8  ,  F9  , F10  , F11  ,
  //|------+------+------+------+------+------+------|                  |------+------+------+------+------+------+------|
           ,  VD  ,  VU  ,  MU  ,      ,      ,XXXXXX,                   XXXXXX, LEFT , DOWN ,  UP  , RGHT ,      , F12  ,
  //|------+------+------+------+------+------+------+------.    ,------+------+------+------+------+------+------+------|
           , BRMD , BRMU ,      ,      ,      ,      ,                         , HOME , PGDN , PGUP , END  ,      ,      ,
  //|------+------+------+------+------+------|      |      |    |      |      |------+------+------+------+------+------|
     XXXXXX,XXXXXX,XXXXXX,     LALT    , LCMD , LSFT , LSPC ,      RSPC , ENT  , DEL  ,             ,XXXXXX,XXXXXX,XXXXXX
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
