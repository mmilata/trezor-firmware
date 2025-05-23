/*
 * This file is part of the Trezor project, https://trezor.io/
 *
 * Copyright (c) SatoshiLabs
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
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

#include <trezor_model.h>
#include <trezor_rtl.h>

#include <gfx/gfx_draw.h>
#include <io/display.h>
#include <io/display_utils.h>
#include <rtl/mini_printf.h>
#include "bootui.h"
#include "icon_done.h"
#include "icon_fail.h"
#include "icon_install.h"
#include "icon_welcome.h"
#include "icon_wipe.h"

#define BACKLIGHT_NORMAL 150

#define COLOR_BL_BG COLOR_WHITE  // background
#define COLOR_BL_FG COLOR_BLACK  // foreground

#ifdef RGB16
#define COLOR_BL_FAIL RGB16(0xFF, 0x00, 0x00)     // red
#define COLOR_BL_DONE RGB16(0x00, 0xAE, 0x0B)     // green
#define COLOR_BL_PROCESS RGB16(0x4A, 0x90, 0xE2)  // blue
#else
#define COLOR_BL_FAIL COLOR_BL_FG
#define COLOR_BL_DONE COLOR_BL_FG
#define COLOR_BL_PROCESS COLOR_BL_FG
#endif

#define COLOR_WELCOME_BG COLOR_WHITE  // welcome background
#define COLOR_WELCOME_FG COLOR_BLACK  // welcome foreground

// welcome UI

void ui_screen_welcome_third(void) {}

// install UI

void ui_screen_install_start(void) {
  gfx_draw_bar(gfx_rect_wh(0, 0, DISPLAY_RESX, DISPLAY_RESY), COLOR_BL_BG);
}

void ui_screen_install_progress_erase(int pos, int len) {}

void ui_screen_install_progress_upload(int pos) {}

// wipe UI

void ui_screen_wipe(void) {
  gfx_draw_bar(gfx_rect_wh(0, 0, DISPLAY_RESX, DISPLAY_RESY), COLOR_BL_BG);
}

void ui_screen_wipe_progress(int pos, int len) {}

// done UI

void ui_screen_done(int restart_seconds, secbool full_redraw) {
  if (sectrue == full_redraw) {
    gfx_draw_bar(gfx_rect_wh(0, 0, DISPLAY_RESX, DISPLAY_RESY), COLOR_BL_BG);
  }
  if (secfalse == full_redraw) {
    gfx_draw_bar(gfx_rect_wh(0, DISPLAY_RESY - 24 - 18, 240, 23), COLOR_BL_BG);
  }
}

// error UI

void ui_screen_fail(void) {
  gfx_draw_bar(gfx_rect_wh(0, 0, DISPLAY_RESX, DISPLAY_RESY), COLOR_BL_BG);
}

// general functions

void ui_fadein(void) { display_fade(0, BACKLIGHT_NORMAL, 1000); }

void ui_fadeout(void) { display_fade(BACKLIGHT_NORMAL, 0, 500); }
