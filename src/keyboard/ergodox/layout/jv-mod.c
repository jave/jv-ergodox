/* ----------------------------------------------------------------------------
 * ergoDOX layout : QWERTY (modified from the Kinesis layout)
 * -----------------------------------------------------------------------------
 * Copyright (c) 2012 Ben Blazak <benblazak.dev@gmail.com>
 * Released under The MIT License (MIT) (see "license.md")
 * Project located at <https://github.com/benblazak/ergodox-firmware>
 * -------------------------------------------------------------------------- */
#include <stdint.h>
#include <stddef.h>
#include <avr/pgmspace.h>
#include "../../../lib/data-types/misc.h"
#include "../../../lib/usb/usage-page/keyboard--short-names.h"
#include "../../../lib-other/pjrc/usb_keyboard/usb_keyboard.h"
#include "../../../lib/key-functions/public.h"
#include "../../../lib/key-functions/private.h"
#include "../matrix.h"
#include "../layout.h"

#include "../../../lib/usb/usage-page/keyboard.h"
#include "../../../keyboard/layout.h"
#include "../../../main.h"


// FUNCTIONS ------------------------------------------------------------------
void kbfun_layer_pop_all(void) {
  kbfun_layer_pop_1();
  kbfun_layer_pop_2();
  kbfun_layer_pop_3();
  kbfun_layer_pop_4();
  kbfun_layer_pop_5();
  kbfun_layer_pop_6();
  kbfun_layer_pop_7();
  kbfun_layer_pop_8();
  kbfun_layer_pop_9();
  kbfun_layer_pop_10();
}

// DEFINITIONS ----------------------------------------------------------------
#define  kprrel   &kbfun_press_release
#define  ktog     &kbfun_toggle
#define  ktrans   &kbfun_transparent
#define  lpush1   &kbfun_layer_push_1
#define  lpush2   &kbfun_layer_push_2
#define  lpush3   &kbfun_layer_push_3
#define  lpush4   &kbfun_layer_push_4
#define  lpush5   &kbfun_layer_push_5
#define  lpush6   &kbfun_layer_push_6
#define  lpush7   &kbfun_layer_push_7
#define  lpush8   &kbfun_layer_push_8
#define  lpush9   &kbfun_layer_push_9
#define  lpush10  &kbfun_layer_push_10
#define  lpop     &kbfun_layer_pop_all
#define  lpop1    &kbfun_layer_pop_1
#define  lpop2    &kbfun_layer_pop_2
#define  lpop3    &kbfun_layer_pop_3
#define  lpop4    &kbfun_layer_pop_4
#define  lpop5    &kbfun_layer_pop_5
#define  lpop6    &kbfun_layer_pop_6
#define  lpop7    &kbfun_layer_pop_7
#define  lpop8    &kbfun_layer_pop_8
#define  lpop9    &kbfun_layer_pop_9
#define  lpop10   &kbfun_layer_pop_10
#define  dbtldr   &kbfun_jump_to_bootloader
#define  sshprre  &kbfun_shift_press_release
#define  s2kcap   &kbfun_2_keys_capslock_press_release
#define  slpunum  &kbfun_layer_push_numpad
#define  slponum  &kbfun_layer_pop_numpad

#define  IS_PRESSED    main_arg_is_pressed
void kbfun_altgr_press_release(void) {
  _kbfun_press_release(IS_PRESSED, KEY_RightAlt);
  kbfun_press_release();
  usb_keyboard_send();
}
#define  saltgrprre  &kbfun_altgr_press_release

void local_kbfun_macro00(void) {
  _kbfun_press_release(true,  _H);
  usb_keyboard_send();
  _kbfun_press_release(false, _H);
  _kbfun_press_release(true,  _I);
  usb_keyboard_send();
  _kbfun_press_release(false, _I);
}

void altx(void) {
  _kbfun_press_release(true,  KEY_LeftAlt);
  usb_keyboard_send();
  _kbfun_press_release(true, _X); 
  usb_keyboard_send();
  _kbfun_press_release(false,  _X);
  usb_keyboard_send();
  _kbfun_press_release(false, KEY_LeftAlt);
}

void ctrlx(void) {
  _kbfun_press_release(true,  KEY_LeftControl);
  usb_keyboard_send();
  _kbfun_press_release(true, _X);
  usb_keyboard_send();
  _kbfun_press_release(false,  _X);
  usb_keyboard_send();
  _kbfun_press_release(false, KEY_LeftControl);
}

void ctrlhome(void) {
  _kbfun_press_release(true,  KEY_LeftControl);
  usb_keyboard_send();
  _kbfun_press_release(true, _home);
  usb_keyboard_send();
  _kbfun_press_release(false,  _home);
  usb_keyboard_send();
  _kbfun_press_release(false, KEY_LeftControl);
}


void ctrlend(void) {
  _kbfun_press_release(true,  KEY_LeftControl);
  usb_keyboard_send();
  _kbfun_press_release(true, _end);
  usb_keyboard_send();
  _kbfun_press_release(false,  _end);
  usb_keyboard_send();
  _kbfun_press_release(false, KEY_LeftControl);
}



const uint8_t PROGMEM _kb_layout[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {


  KB_MATRIX_LAYER(0, _esc, _8, _7, _0, _8, _0, _4, _altL, KEY_LeftBracket_LeftBrace, KEY_SingleQuote_DoubleQuote, KEY_Semicolon_Colon, _P, _Y, _comma, _ctrlL, _A, _O, _E, _U, _I, _shiftL, 50, _Q, _J, _K, _X, _comma, _guiL, 50, KEY_RightBracket_RightBrace, 2, 1, _ctrlL, _altL, 0, 0, _ctrlL, _bs, _tab, _shiftL, _6, 50, _9, 45, _9, _1, _3, _bracketL, _F, _G, _C, _R, _L, _altL, _D, _H, _T, _N, _S, _ctrlL, _period, _B, _M, _W, _V, _Z, _shiftL, 1, 2, 3, KEY_RightArrow, _guiR, _altL, _ctrlL, _ctrlL, 0, 0, _shiftL, _enter, _space),


  KB_MATRIX_LAYER(0, KEY_CapsLock, KEY_7_Ampersand, 0x2F, 0x30, 0, 0, 0, KEY_LeftAlt, 0, 0, KEY_UpArrow, KEY_PageUp, 0, 1, KEY_LeftControl, KEY_Home, KEY_LeftArrow, KEY_DownArrow, KEY_RightArrow, KEY_End, KEY_LeftShift, 0, 0, 0, KEY_PageDown, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, KEYPAD_NumLock_Clear, KEYPAD_Slash, KEYPAD_Asterisk, KEYPAD_Minus, 0, KEYPAD_Period_Delete, 0, _7_kp, _8_kp, _9_kp, KEYPAD_Plus, KEY_RightAlt, _0_kp, _4_kp, _5_kp, _6_kp, 0, KEY_RightControl, _0_kp, 0, _1_kp, _2_kp, _3_kp, 0, KEY_RightShift, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),


  KB_MATRIX_LAYER(0, 0, 0, 0, 0x64, 0x64, 0, 0, 0, 0, 0, _7, _0, 45, 0, 0, KEY_Slash_Question, KEY_Slash_Question, _8, _9, 0x64, 0, 45, _2, _8, _9, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, _F10, _F11, _F12, KEYPAD_Minus, 0, 0, 0, _F7, _F8, _F9, KEYPAD_Plus, 0, 0, _F4, _F5, _F6, KEYPAD_Plus, 0, 0, 0, _F1, _F2, _F3, KEY_ReturnEnter, 0, 0, 0, KEYPAD_Period_Delete, KEY_ReturnEnter, 0, 0, 0, 0, 0, 0, 0, 0, 0),


  KB_MATRIX_LAYER(0, _esc, _7, _5, _3, _1, _9, _esc, _altL, KEY_LeftBracket_LeftBrace, KEY_SingleQuote_DoubleQuote, KEY_Semicolon_Colon, _P, _Y, _comma, _ctrlL, _A, _O, _E, _U, _I, _shiftL, _2, _Q, _J, _K, _X, _comma, _guiL, 50, 0, 2, 1, _ctrlL, _altL, 0, 0, _ctrlL, _bs, _tab, _shiftL, 2, _0, _2, _4, _6, _8, _3, _bracketL, _F, _G, _C, _R, _L, _altL, _D, _H, _T, _N, _S, _ctrlL, _period, _B, _M, _W, _V, _Z, _shiftL, 1, 2, _arrowU, KEY_RightArrow, _guiR, _altL, _ctrlL, _ctrlL, 0, 0, _shiftL, _enter, _space),


  KB_MATRIX_LAYER(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),


  KB_MATRIX_LAYER(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),


  KB_MATRIX_LAYER(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),


  KB_MATRIX_LAYER(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),


  KB_MATRIX_LAYER(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
};

const void_funptr_t PROGMEM _kb_layout_press[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {


  KB_MATRIX_LAYER(NULL, kprrel, saltgrprre, saltgrprre, saltgrprre, sshprre, sshprre, saltgrprre, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, sshprre, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, lpush2, lpush1, kprrel, kprrel, NULL, NULL, kprrel, kprrel, kprrel, kprrel, sshprre, sshprre, sshprre, kprrel, saltgrprre, sshprre, sshprre, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, lpush1, lpush2, lpush3, kprrel, kprrel, kprrel, kprrel, kprrel, NULL, NULL, kprrel, kprrel, kprrel),


  KB_MATRIX_LAYER(NULL, kprrel, kprrel, sshprre, sshprre, NULL, NULL, NULL, kprrel, NULL, NULL, kprrel, kprrel, &ctrlhome, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, NULL, NULL, NULL, kprrel, &ctrlend, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, kprrel, kprrel, kprrel, kprrel, NULL, kprrel, NULL, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, NULL, kprrel, kprrel, NULL, kprrel, kprrel, kprrel, NULL, kprrel, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),


  KB_MATRIX_LAYER(dbtldr, NULL, NULL, NULL, kprrel, sshprre, NULL, NULL, NULL, NULL, NULL, saltgrprre, saltgrprre, saltgrprre, NULL, NULL, sshprre, kprrel, sshprre, sshprre, saltgrprre, NULL, sshprre, saltgrprre, saltgrprre, saltgrprre, saltgrprre, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, kprrel, NULL, kprrel, kprrel, kprrel, kprrel, NULL, NULL, NULL, kprrel, kprrel, kprrel, kprrel, NULL, NULL, kprrel, kprrel, kprrel, kprrel, NULL, NULL, NULL, kprrel, kprrel, kprrel, kprrel, NULL, NULL, NULL, kprrel, kprrel, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),


  KB_MATRIX_LAYER(NULL, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, sshprre, sshprre, sshprre, sshprre, sshprre, sshprre, kprrel, sshprre, sshprre, sshprre, sshprre, sshprre, kprrel, sshprre, sshprre, sshprre, sshprre, sshprre, kprrel, kprrel, kprrel, NULL, lpush2, lpush1, kprrel, kprrel, NULL, NULL, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, sshprre, kprrel, sshprre, sshprre, sshprre, sshprre, sshprre, kprrel, sshprre, sshprre, sshprre, sshprre, sshprre, kprrel, kprrel, sshprre, sshprre, sshprre, sshprre, sshprre, kprrel, lpush1, lpush2, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, NULL, NULL, kprrel, kprrel, kprrel),


  KB_MATRIX_LAYER(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),


  KB_MATRIX_LAYER(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),


  KB_MATRIX_LAYER(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),


  KB_MATRIX_LAYER(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),


  KB_MATRIX_LAYER(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
};

const void_funptr_t PROGMEM _kb_layout_release[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {


  KB_MATRIX_LAYER(
                  NULL, kprrel, saltgrprre, saltgrprre, saltgrprre, sshprre, sshprre, saltgrprre, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, sshprre, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, lpop2, lpop1, kprrel, kprrel, NULL, NULL, kprrel, kprrel, kprrel, kprrel, sshprre, sshprre, sshprre, kprrel, saltgrprre, sshprre, sshprre, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, lpop1, lpop2, lpop3, kprrel, kprrel, kprrel, kprrel, kprrel, NULL, NULL, kprrel, kprrel, 
                  kprrel
                  ),


  KB_MATRIX_LAYER(
                  NULL, kprrel, kprrel, sshprre, sshprre, NULL, NULL, NULL, kprrel, NULL, NULL, kprrel, kprrel, &ctrlhome, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, NULL, NULL, NULL, kprrel, &ctrlend, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, kprrel, kprrel, kprrel, kprrel, NULL, kprrel, NULL, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, NULL, kprrel, kprrel, NULL, kprrel, kprrel, kprrel, NULL, kprrel, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
                  NULL
                  ),


  KB_MATRIX_LAYER(
                  dbtldr, NULL, NULL, NULL, kprrel, sshprre, NULL, NULL, NULL, NULL, NULL, saltgrprre, saltgrprre, saltgrprre, NULL, NULL, sshprre, kprrel, sshprre, sshprre, saltgrprre, NULL, sshprre, saltgrprre, saltgrprre, saltgrprre, saltgrprre, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, kprrel, NULL, kprrel, kprrel, kprrel, kprrel, NULL, NULL, NULL, kprrel, kprrel, kprrel, kprrel, NULL, NULL, kprrel, kprrel, kprrel, kprrel, NULL, NULL, NULL, kprrel, kprrel, kprrel, kprrel, NULL, NULL, NULL, kprrel, kprrel, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
                  NULL
                  ),


  KB_MATRIX_LAYER(
                  NULL, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, sshprre, sshprre, sshprre, sshprre, sshprre, sshprre, kprrel, sshprre, sshprre, sshprre, sshprre, sshprre, kprrel, sshprre, sshprre, sshprre, sshprre, sshprre, kprrel, kprrel, kprrel, NULL, lpop2, lpop1, kprrel, kprrel, NULL, NULL, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, sshprre, kprrel, sshprre, sshprre, sshprre, sshprre, sshprre, kprrel, sshprre, sshprre, sshprre, sshprre, sshprre, kprrel, kprrel, sshprre, sshprre, sshprre, sshprre, sshprre, kprrel, lpop1, lpop2, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, NULL, NULL, kprrel, kprrel, 
                  kprrel
                  ),


  KB_MATRIX_LAYER(
                  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
                  NULL
                  ),


  KB_MATRIX_LAYER(
                  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
                  NULL
                  ),


  KB_MATRIX_LAYER(
                  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
                  NULL
                  ),


  KB_MATRIX_LAYER(
                  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
                  NULL
                  ),


  KB_MATRIX_LAYER(
                  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
                  NULL
                  ),
};
