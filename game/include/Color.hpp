/* BSD 3-Clause License
 *
 * Copyright © 2008-2021, Jice and the libtcod contributors.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

/* This file contains color info copied from src/libtcod/color.hpp of libtcod library */
/* Use this data instead of native TCODColor::[color name] as it is considered deprecated */

#pragma once

#include <libtcod.hpp>

namespace Color{

  static const TCOD_ColorRGB black        = tcod::ColorRGB{0,     0,   0};
  static const TCOD_ColorRGB darkestGrey  = tcod::ColorRGB{31,   31,  31};
  static const TCOD_ColorRGB darkerGrey   = tcod::ColorRGB{63,   63,  63};
  static const TCOD_ColorRGB darkGrey     = tcod::ColorRGB{95,   95,  95};
  static const TCOD_ColorRGB grey         = tcod::ColorRGB{127, 127, 127};
  static const TCOD_ColorRGB lightGrey    = tcod::ColorRGB{159, 159, 159};
  static const TCOD_ColorRGB lighterGrey  = tcod::ColorRGB{191, 191, 191};
  static const TCOD_ColorRGB lightestGrey = tcod::ColorRGB{223, 223, 223};
  static const TCOD_ColorRGB white        = tcod::ColorRGB{255, 255, 255};

  // sepia
  static const TCOD_ColorRGB darkestSepia  = tcod::ColorRGB{31,  24,  15};
  static const TCOD_ColorRGB darkerSepia   = tcod::ColorRGB{63,  50,  31};
  static const TCOD_ColorRGB darkSepia     = tcod::ColorRGB{94,  75,  47};
  static const TCOD_ColorRGB sepia         = tcod::ColorRGB{127, 101, 63};
  static const TCOD_ColorRGB lightSepia    = tcod::ColorRGB{158, 134, 100};
  static const TCOD_ColorRGB lighterSepia  = tcod::ColorRGB{191, 171, 143};
  static const TCOD_ColorRGB lightestSepia = tcod::ColorRGB{222, 211, 195};

  // standard colors
  static const TCOD_ColorRGB red        = tcod::ColorRGB{255,   0, 0};
  static const TCOD_ColorRGB flame      = tcod::ColorRGB{255,  63, 0};
  static const TCOD_ColorRGB orange     = tcod::ColorRGB{255, 127, 0};
  static const TCOD_ColorRGB amber      = tcod::ColorRGB{255, 191, 0};
  static const TCOD_ColorRGB yellow     = tcod::ColorRGB{255, 255, 0};
  static const TCOD_ColorRGB lime       = tcod::ColorRGB{191, 255, 0};
  static const TCOD_ColorRGB chartreuse = tcod::ColorRGB{127, 255, 0};
  static const TCOD_ColorRGB green      = tcod::ColorRGB{0,   255, 0};
  static const TCOD_ColorRGB sea        = tcod::ColorRGB{0,   255, 127};
  static const TCOD_ColorRGB turquoise  = tcod::ColorRGB{0,   255, 191};
  static const TCOD_ColorRGB cyan       = tcod::ColorRGB{0,   255, 255};
  static const TCOD_ColorRGB sky        = tcod::ColorRGB{0,   191, 255};
  static const TCOD_ColorRGB azure      = tcod::ColorRGB{0,   127, 255};
  static const TCOD_ColorRGB blue       = tcod::ColorRGB{0,     0, 255};
  static const TCOD_ColorRGB han        = tcod::ColorRGB{63,    0, 255};
  static const TCOD_ColorRGB violet     = tcod::ColorRGB{127,   0, 255};
  static const TCOD_ColorRGB purple     = tcod::ColorRGB{191,   0, 255};
  static const TCOD_ColorRGB fuchsia    = tcod::ColorRGB{255,   0, 255};
  static const TCOD_ColorRGB magenta    = tcod::ColorRGB{255,   0, 191};
  static const TCOD_ColorRGB pink       = tcod::ColorRGB{255,   0, 127};
  static const TCOD_ColorRGB crimson    = tcod::ColorRGB{255,   0, 63};

  // dark colors
  static const TCOD_ColorRGB darkRed        = tcod::ColorRGB{191,   0, 0};
  static const TCOD_ColorRGB darkFlame      = tcod::ColorRGB{191,  47, 0};
  static const TCOD_ColorRGB darkOrange     = tcod::ColorRGB{191,  95, 0};
  static const TCOD_ColorRGB darkAmber      = tcod::ColorRGB{191, 143, 0};
  static const TCOD_ColorRGB darkYellow     = tcod::ColorRGB{191, 191, 0};
  static const TCOD_ColorRGB darkLime       = tcod::ColorRGB{143, 191, 0};
  static const TCOD_ColorRGB darkChartreuse = tcod::ColorRGB{95,  191, 0};
  static const TCOD_ColorRGB darkGreen      = tcod::ColorRGB{0,   191, 0};
  static const TCOD_ColorRGB darkSea        = tcod::ColorRGB{0,   191, 95};
  static const TCOD_ColorRGB darkTurquoise  = tcod::ColorRGB{0,   191, 143};
  static const TCOD_ColorRGB darkCyan       = tcod::ColorRGB{0,   191, 191};
  static const TCOD_ColorRGB darkSky        = tcod::ColorRGB{0,   143, 191};
  static const TCOD_ColorRGB darkAzure      = tcod::ColorRGB{0,    95, 191};
  static const TCOD_ColorRGB darkBlue       = tcod::ColorRGB{0,     0, 191};
  static const TCOD_ColorRGB darkHan        = tcod::ColorRGB{47,    0, 191};
  static const TCOD_ColorRGB darkViolet     = tcod::ColorRGB{95,    0, 191};
  static const TCOD_ColorRGB darkPurple     = tcod::ColorRGB{143,   0, 191};
  static const TCOD_ColorRGB darkFuchsia    = tcod::ColorRGB{191,   0, 191};
  static const TCOD_ColorRGB darkMagenta    = tcod::ColorRGB{191,   0, 143};
  static const TCOD_ColorRGB darkPink       = tcod::ColorRGB{191,   0, 95};
  static const TCOD_ColorRGB darkCrimson    = tcod::ColorRGB{191,   0, 47};

  // darker colors
  static const TCOD_ColorRGB darkerRed        = tcod::ColorRGB{127,   0, 0};
  static const TCOD_ColorRGB darkerFlame      = tcod::ColorRGB{127,  31, 0};
  static const TCOD_ColorRGB darkerOrange     = tcod::ColorRGB{127,  63, 0};
  static const TCOD_ColorRGB darkerAmber      = tcod::ColorRGB{127,  95, 0};
  static const TCOD_ColorRGB darkerYellow     = tcod::ColorRGB{127, 127, 0};
  static const TCOD_ColorRGB darkerLime       = tcod::ColorRGB{95,  127, 0};
  static const TCOD_ColorRGB darkerChartreuse = tcod::ColorRGB{63,  127, 0};
  static const TCOD_ColorRGB darkerGreen      = tcod::ColorRGB{0,   127, 0};
  static const TCOD_ColorRGB darkerSea        = tcod::ColorRGB{0,   127, 63};
  static const TCOD_ColorRGB darkerTurquoise  = tcod::ColorRGB{0,   127, 95};
  static const TCOD_ColorRGB darkerCyan       = tcod::ColorRGB{0,   127, 127};
  static const TCOD_ColorRGB darkerSky        = tcod::ColorRGB{0,    95, 127};
  static const TCOD_ColorRGB darkerAzure      = tcod::ColorRGB{0,    63, 127};
  static const TCOD_ColorRGB darkerBlue       = tcod::ColorRGB{0,     0, 127};
  static const TCOD_ColorRGB darkerHan        = tcod::ColorRGB{31,    0, 127};
  static const TCOD_ColorRGB darkerViolet     = tcod::ColorRGB{63,    0, 127};
  static const TCOD_ColorRGB darkerPurple     = tcod::ColorRGB{95,    0, 127};
  static const TCOD_ColorRGB darkerFuchsia    = tcod::ColorRGB{127,   0, 127};
  static const TCOD_ColorRGB darkerMagenta    = tcod::ColorRGB{127,   0, 95};
  static const TCOD_ColorRGB darkerPink       = tcod::ColorRGB{127,   0, 63};
  static const TCOD_ColorRGB darkerCrimson    = tcod::ColorRGB{127,   0, 31};

  // darkest colors
  static const TCOD_ColorRGB darkestRed        = tcod::ColorRGB{63,  0, 0};
  static const TCOD_ColorRGB darkestFlame      = tcod::ColorRGB{63, 15, 0};
  static const TCOD_ColorRGB darkestOrange     = tcod::ColorRGB{63, 31, 0};
  static const TCOD_ColorRGB darkestAmber      = tcod::ColorRGB{63, 47, 0};
  static const TCOD_ColorRGB darkestYellow     = tcod::ColorRGB{63, 63, 0};
  static const TCOD_ColorRGB darkestLime       = tcod::ColorRGB{47, 63, 0};
  static const TCOD_ColorRGB darkestChartreuse = tcod::ColorRGB{31, 63, 0};
  static const TCOD_ColorRGB darkestGreen      = tcod::ColorRGB{0,  63, 0};
  static const TCOD_ColorRGB darkestSea        = tcod::ColorRGB{0,  63, 31};
  static const TCOD_ColorRGB darkestTurquoise  = tcod::ColorRGB{0,  63, 47};
  static const TCOD_ColorRGB darkestCyan       = tcod::ColorRGB{0,  63, 63};
  static const TCOD_ColorRGB darkestSky        = tcod::ColorRGB{0,  47, 63};
  static const TCOD_ColorRGB darkestAzure      = tcod::ColorRGB{0,  31, 63};
  static const TCOD_ColorRGB darkestBlue       = tcod::ColorRGB{0,   0, 63};
  static const TCOD_ColorRGB darkestHan        = tcod::ColorRGB{15,  0, 63};
  static const TCOD_ColorRGB darkestViolet     = tcod::ColorRGB{31,  0, 63};
  static const TCOD_ColorRGB darkestPurple     = tcod::ColorRGB{47,  0, 63};
  static const TCOD_ColorRGB darkestFuchsia    = tcod::ColorRGB{63,  0, 63};
  static const TCOD_ColorRGB darkestMagenta    = tcod::ColorRGB{63,  0, 47};
  static const TCOD_ColorRGB darkestPink       = tcod::ColorRGB{63,  0, 31};
  static const TCOD_ColorRGB darkestCrimson    = tcod::ColorRGB{63,  0, 15};

  // light colors
  static const TCOD_ColorRGB lightRed        = tcod::ColorRGB{255,  63, 63};
  static const TCOD_ColorRGB lightFlame      = tcod::ColorRGB{255, 111, 63};
  static const TCOD_ColorRGB lightOrange     = tcod::ColorRGB{255, 159, 63};
  static const TCOD_ColorRGB lightAmber      = tcod::ColorRGB{255, 207, 63};
  static const TCOD_ColorRGB lightYellow     = tcod::ColorRGB{255, 255, 63};
  static const TCOD_ColorRGB lightLime       = tcod::ColorRGB{207, 255, 63};
  static const TCOD_ColorRGB lightChartreuse = tcod::ColorRGB{159, 255, 63};
  static const TCOD_ColorRGB lightGreen      = tcod::ColorRGB{63,  255, 63};
  static const TCOD_ColorRGB lightSea        = tcod::ColorRGB{63,  255, 159};
  static const TCOD_ColorRGB lightTurquoise  = tcod::ColorRGB{63,  255, 207};
  static const TCOD_ColorRGB lightCyan       = tcod::ColorRGB{63,  255, 255};
  static const TCOD_ColorRGB lightSky        = tcod::ColorRGB{63,  207, 255};
  static const TCOD_ColorRGB lightAzure      = tcod::ColorRGB{63,  159, 255};
  static const TCOD_ColorRGB lightBlue       = tcod::ColorRGB{63,   63, 255};
  static const TCOD_ColorRGB lightHan        = tcod::ColorRGB{111,  63, 255};
  static const TCOD_ColorRGB lightViolet     = tcod::ColorRGB{159,  63, 255};
  static const TCOD_ColorRGB lightPurple     = tcod::ColorRGB{207,  63, 255};
  static const TCOD_ColorRGB lightFuchsia    = tcod::ColorRGB{255,  63, 255};
  static const TCOD_ColorRGB lightMagenta    = tcod::ColorRGB{255,  63, 207};
  static const TCOD_ColorRGB lightPink       = tcod::ColorRGB{255,  63, 159};
  static const TCOD_ColorRGB lightCrimson    = tcod::ColorRGB{255,  63, 111};

  // lighter colors
  static const TCOD_ColorRGB lighterRed        = tcod::ColorRGB{255, 127, 127};
  static const TCOD_ColorRGB lighterFlame      = tcod::ColorRGB{255, 159, 127};
  static const TCOD_ColorRGB lighterOrange     = tcod::ColorRGB{255, 191, 127};
  static const TCOD_ColorRGB lighterAmber      = tcod::ColorRGB{255, 223, 127};
  static const TCOD_ColorRGB lighterYellow     = tcod::ColorRGB{255, 255, 127};
  static const TCOD_ColorRGB lighterLime       = tcod::ColorRGB{223, 255, 127};
  static const TCOD_ColorRGB lighterChartreuse = tcod::ColorRGB{191, 255, 127};
  static const TCOD_ColorRGB lighterGreen      = tcod::ColorRGB{127, 255, 127};
  static const TCOD_ColorRGB lighterSea        = tcod::ColorRGB{127, 255, 191};
  static const TCOD_ColorRGB lighterTurquoise  = tcod::ColorRGB{127, 255, 223};
  static const TCOD_ColorRGB lighterCyan       = tcod::ColorRGB{127, 255, 255};
  static const TCOD_ColorRGB lighterSky        = tcod::ColorRGB{127, 223, 255};
  static const TCOD_ColorRGB lighterAzure      = tcod::ColorRGB{127, 191, 255};
  static const TCOD_ColorRGB lighterBlue       = tcod::ColorRGB{127, 127, 255};
  static const TCOD_ColorRGB lighterHan        = tcod::ColorRGB{159, 127, 255};
  static const TCOD_ColorRGB lighterViolet     = tcod::ColorRGB{191, 127, 255};
  static const TCOD_ColorRGB lighterPurple     = tcod::ColorRGB{223, 127, 255};
  static const TCOD_ColorRGB lighterFuchsia    = tcod::ColorRGB{255, 127, 255};
  static const TCOD_ColorRGB lighterMagenta    = tcod::ColorRGB{255, 127, 223};
  static const TCOD_ColorRGB lighterPink       = tcod::ColorRGB{255, 127, 191};
  static const TCOD_ColorRGB lighterCrimson    = tcod::ColorRGB{255, 127, 159};

  // lightest colors
  static const TCOD_ColorRGB lightestRed        = tcod::ColorRGB{255, 191, 191};
  static const TCOD_ColorRGB lightestFlame      = tcod::ColorRGB{255, 207, 191};
  static const TCOD_ColorRGB lightestOrange     = tcod::ColorRGB{255, 223, 191};
  static const TCOD_ColorRGB lightestAmber      = tcod::ColorRGB{255, 239, 191};
  static const TCOD_ColorRGB lightestYellow     = tcod::ColorRGB{255, 255, 191};
  static const TCOD_ColorRGB lightestLime       = tcod::ColorRGB{239, 255, 191};
  static const TCOD_ColorRGB lightestChartreuse = tcod::ColorRGB{223, 255, 191};
  static const TCOD_ColorRGB lightestGreen      = tcod::ColorRGB{191, 255, 191};
  static const TCOD_ColorRGB lightestSea        = tcod::ColorRGB{191, 255, 223};
  static const TCOD_ColorRGB lightestTurquoise  = tcod::ColorRGB{191, 255, 239};
  static const TCOD_ColorRGB lightestCyan       = tcod::ColorRGB{191, 255, 255};
  static const TCOD_ColorRGB lightestSky        = tcod::ColorRGB{191, 239, 255};
  static const TCOD_ColorRGB lightestAzure      = tcod::ColorRGB{191, 223, 255};
  static const TCOD_ColorRGB lightestBlue       = tcod::ColorRGB{191, 191, 255};
  static const TCOD_ColorRGB lightestHan        = tcod::ColorRGB{207, 191, 255};
  static const TCOD_ColorRGB lightestViolet     = tcod::ColorRGB{223, 191, 255};
  static const TCOD_ColorRGB lightestPurple     = tcod::ColorRGB{239, 191, 255};
  static const TCOD_ColorRGB lightestFuchsia    = tcod::ColorRGB{255, 191, 255};
  static const TCOD_ColorRGB lightestMagenta    = tcod::ColorRGB{255, 191, 239};
  static const TCOD_ColorRGB lightestPink       = tcod::ColorRGB{255, 191, 223};
  static const TCOD_ColorRGB lightestCrimson    = tcod::ColorRGB{255, 191, 207};

  // desaturated colors
  static const TCOD_ColorRGB desaturatedRed        = tcod::ColorRGB{127,  63, 63};
  static const TCOD_ColorRGB desaturatedFlame      = tcod::ColorRGB{127,  79, 63};
  static const TCOD_ColorRGB desaturatedOrange     = tcod::ColorRGB{127,  95, 63};
  static const TCOD_ColorRGB desaturatedAmber      = tcod::ColorRGB{127, 111, 63};
  static const TCOD_ColorRGB desaturatedYellow     = tcod::ColorRGB{127, 127, 63};
  static const TCOD_ColorRGB desaturatedLime       = tcod::ColorRGB{111, 127, 63};
  static const TCOD_ColorRGB desaturatedChartreuse = tcod::ColorRGB{95,  127, 63};
  static const TCOD_ColorRGB desaturatedGreen      = tcod::ColorRGB{63,  127, 63};
  static const TCOD_ColorRGB desaturatedSea        = tcod::ColorRGB{63,  127, 95};
  static const TCOD_ColorRGB desaturatedTurquoise  = tcod::ColorRGB{63,  127, 111};
  static const TCOD_ColorRGB desaturatedCyan       = tcod::ColorRGB{63,  127, 127};
  static const TCOD_ColorRGB desaturatedSky        = tcod::ColorRGB{63,  111, 127};
  static const TCOD_ColorRGB desaturatedAzure      = tcod::ColorRGB{63,   95, 127};
  static const TCOD_ColorRGB desaturatedBlue       = tcod::ColorRGB{63,   63, 127};
  static const TCOD_ColorRGB desaturatedHan        = tcod::ColorRGB{79,   63, 127};
  static const TCOD_ColorRGB desaturatedViolet     = tcod::ColorRGB{95,   63, 127};
  static const TCOD_ColorRGB desaturatedPurple     = tcod::ColorRGB{111,  63, 127};
  static const TCOD_ColorRGB desaturatedFuchsia    = tcod::ColorRGB{127,  63, 127};
  static const TCOD_ColorRGB desaturatedMagenta    = tcod::ColorRGB{127,  63, 111};
  static const TCOD_ColorRGB desaturatedPink       = tcod::ColorRGB{127,  63, 95};
  static const TCOD_ColorRGB desaturatedCrimson    = tcod::ColorRGB{127,  63, 79};

  // metallic
  static const TCOD_ColorRGB brass  = tcod::ColorRGB{191, 151, 96};
  static const TCOD_ColorRGB copper = tcod::ColorRGB{197, 136, 124};
  static const TCOD_ColorRGB gold   = tcod::ColorRGB{229, 191, 0};
  static const TCOD_ColorRGB silver = tcod::ColorRGB{203, 203, 203};

  // miscellaneous
  static const TCOD_ColorRGB celadon = tcod::ColorRGB{172, 255, 175};
  static const TCOD_ColorRGB peach   = tcod::ColorRGB{255, 159, 127};

}
