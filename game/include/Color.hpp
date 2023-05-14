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
/* Use this data instead of native TCODColor::* as it is considered deprecated */

#pragma once

#include <libtcod.hpp>

namespace Color{

  static const TCODColor black        = tcod::ColorRGB{0,     0,   0};
  static const TCODColor darkestGrey  = tcod::ColorRGB{31,   31,  31};
  static const TCODColor darkerGrey   = tcod::ColorRGB{63,   63,  63};
  static const TCODColor darkGrey     = tcod::ColorRGB{95,   95,  95};
  static const TCODColor grey         = tcod::ColorRGB{127, 127, 127};
  static const TCODColor lightGrey    = tcod::ColorRGB{159, 159, 159};
  static const TCODColor lighterGrey  = tcod::ColorRGB{191, 191, 191};
  static const TCODColor lightestGrey = tcod::ColorRGB{223, 223, 223};
  static const TCODColor white        = tcod::ColorRGB{255, 255, 255};

  // sepia
  static const TCODColor darkestSepia  = tcod::ColorRGB{31,  24,  15};
  static const TCODColor darkerSepia   = tcod::ColorRGB{63,  50,  31};
  static const TCODColor darkSepia     = tcod::ColorRGB{94,  75,  47};
  static const TCODColor sepia         = tcod::ColorRGB{127, 101, 63};
  static const TCODColor lightSepia    = tcod::ColorRGB{158, 134, 100};
  static const TCODColor lighterSepia  = tcod::ColorRGB{191, 171, 143};
  static const TCODColor lightestSepia = tcod::ColorRGB{222, 211, 195};

  // standard colors
  static const TCODColor red        = tcod::ColorRGB{255,   0, 0};
  static const TCODColor flame      = tcod::ColorRGB{255,  63, 0};
  static const TCODColor orange     = tcod::ColorRGB{255, 127, 0};
  static const TCODColor amber      = tcod::ColorRGB{255, 191, 0};
  static const TCODColor yellow     = tcod::ColorRGB{255, 255, 0};
  static const TCODColor lime       = tcod::ColorRGB{191, 255, 0};
  static const TCODColor chartreuse = tcod::ColorRGB{127, 255, 0};
  static const TCODColor green      = tcod::ColorRGB{0,   255, 0};
  static const TCODColor sea        = tcod::ColorRGB{0,   255, 127};
  static const TCODColor turquoise  = tcod::ColorRGB{0,   255, 191};
  static const TCODColor cyan       = tcod::ColorRGB{0,   255, 255};
  static const TCODColor sky        = tcod::ColorRGB{0,   191, 255};
  static const TCODColor azure      = tcod::ColorRGB{0,   127, 255};
  static const TCODColor blue       = tcod::ColorRGB{0,     0, 255};
  static const TCODColor han        = tcod::ColorRGB{63,    0, 255};
  static const TCODColor violet     = tcod::ColorRGB{127,   0, 255};
  static const TCODColor purple     = tcod::ColorRGB{191,   0, 255};
  static const TCODColor fuchsia    = tcod::ColorRGB{255,   0, 255};
  static const TCODColor magenta    = tcod::ColorRGB{255,   0, 191};
  static const TCODColor pink       = tcod::ColorRGB{255,   0, 127};
  static const TCODColor crimson    = tcod::ColorRGB{255,   0, 63};

  // dark colors
  static const TCODColor darkRed        = tcod::ColorRGB{191,   0, 0};
  static const TCODColor darkFlame      = tcod::ColorRGB{191,  47, 0};
  static const TCODColor darkOrange     = tcod::ColorRGB{191,  95, 0};
  static const TCODColor darkAmber      = tcod::ColorRGB{191, 143, 0};
  static const TCODColor darkYellow     = tcod::ColorRGB{191, 191, 0};
  static const TCODColor darkLime       = tcod::ColorRGB{143, 191, 0};
  static const TCODColor darkChartreuse = tcod::ColorRGB{95,  191, 0};
  static const TCODColor darkGreen      = tcod::ColorRGB{0,   191, 0};
  static const TCODColor darkSea        = tcod::ColorRGB{0,   191, 95};
  static const TCODColor darkTurquoise  = tcod::ColorRGB{0,   191, 143};
  static const TCODColor darkCyan       = tcod::ColorRGB{0,   191, 191};
  static const TCODColor darkSky        = tcod::ColorRGB{0,   143, 191};
  static const TCODColor darkAzure      = tcod::ColorRGB{0,    95, 191};
  static const TCODColor darkBlue       = tcod::ColorRGB{0,     0, 191};
  static const TCODColor darkHan        = tcod::ColorRGB{47,    0, 191};
  static const TCODColor darkViolet     = tcod::ColorRGB{95,    0, 191};
  static const TCODColor darkPurple     = tcod::ColorRGB{143,   0, 191};
  static const TCODColor darkFuchsia    = tcod::ColorRGB{191,   0, 191};
  static const TCODColor darkMagenta    = tcod::ColorRGB{191,   0, 143};
  static const TCODColor darkPink       = tcod::ColorRGB{191,   0, 95};
  static const TCODColor darkCrimson    = tcod::ColorRGB{191,   0, 47};

  // darker colors
  static const TCODColor darkerRed        = tcod::ColorRGB{127,   0, 0};
  static const TCODColor darkerFlame      = tcod::ColorRGB{127,  31, 0};
  static const TCODColor darkerOrange     = tcod::ColorRGB{127,  63, 0};
  static const TCODColor darkerAmber      = tcod::ColorRGB{127,  95, 0};
  static const TCODColor darkerYellow     = tcod::ColorRGB{127, 127, 0};
  static const TCODColor darkerLime       = tcod::ColorRGB{95,  127, 0};
  static const TCODColor darkerChartreuse = tcod::ColorRGB{63,  127, 0};
  static const TCODColor darkerGreen      = tcod::ColorRGB{0,   127, 0};
  static const TCODColor darkerSea        = tcod::ColorRGB{0,   127, 63};
  static const TCODColor darkerTurquoise  = tcod::ColorRGB{0,   127, 95};
  static const TCODColor darkerCyan       = tcod::ColorRGB{0,   127, 127};
  static const TCODColor darkerSky        = tcod::ColorRGB{0,    95, 127};
  static const TCODColor darkerAzure      = tcod::ColorRGB{0,    63, 127};
  static const TCODColor darkerBlue       = tcod::ColorRGB{0,     0, 127};
  static const TCODColor darkerHan        = tcod::ColorRGB{31,    0, 127};
  static const TCODColor darkerViolet     = tcod::ColorRGB{63,    0, 127};
  static const TCODColor darkerPurple     = tcod::ColorRGB{95,    0, 127};
  static const TCODColor darkerFuchsia    = tcod::ColorRGB{127,   0, 127};
  static const TCODColor darkerMagenta    = tcod::ColorRGB{127,   0, 95};
  static const TCODColor darkerPink       = tcod::ColorRGB{127,   0, 63};
  static const TCODColor darkerCrimson    = tcod::ColorRGB{127,   0, 31};

  // darkest colors
  static const TCODColor darkestRed        = tcod::ColorRGB{63,  0, 0};
  static const TCODColor darkestFlame      = tcod::ColorRGB{63, 15, 0};
  static const TCODColor darkestOrange     = tcod::ColorRGB{63, 31, 0};
  static const TCODColor darkestAmber      = tcod::ColorRGB{63, 47, 0};
  static const TCODColor darkestYellow     = tcod::ColorRGB{63, 63, 0};
  static const TCODColor darkestLime       = tcod::ColorRGB{47, 63, 0};
  static const TCODColor darkestChartreuse = tcod::ColorRGB{31, 63, 0};
  static const TCODColor darkestGreen      = tcod::ColorRGB{0,  63, 0};
  static const TCODColor darkestSea        = tcod::ColorRGB{0,  63, 31};
  static const TCODColor darkestTurquoise  = tcod::ColorRGB{0,  63, 47};
  static const TCODColor darkestCyan       = tcod::ColorRGB{0,  63, 63};
  static const TCODColor darkestSky        = tcod::ColorRGB{0,  47, 63};
  static const TCODColor darkestAzure      = tcod::ColorRGB{0,  31, 63};
  static const TCODColor darkestBlue       = tcod::ColorRGB{0,   0, 63};
  static const TCODColor darkestHan        = tcod::ColorRGB{15,  0, 63};
  static const TCODColor darkestViolet     = tcod::ColorRGB{31,  0, 63};
  static const TCODColor darkestPurple     = tcod::ColorRGB{47,  0, 63};
  static const TCODColor darkestFuchsia    = tcod::ColorRGB{63,  0, 63};
  static const TCODColor darkestMagenta    = tcod::ColorRGB{63,  0, 47};
  static const TCODColor darkestPink       = tcod::ColorRGB{63,  0, 31};
  static const TCODColor darkestCrimson    = tcod::ColorRGB{63,  0, 15};

  // light colors
  static const TCODColor lightRed        = tcod::ColorRGB{255,  63, 63};
  static const TCODColor lightFlame      = tcod::ColorRGB{255, 111, 63};
  static const TCODColor lightOrange     = tcod::ColorRGB{255, 159, 63};
  static const TCODColor lightAmber      = tcod::ColorRGB{255, 207, 63};
  static const TCODColor lightYellow     = tcod::ColorRGB{255, 255, 63};
  static const TCODColor lightLime       = tcod::ColorRGB{207, 255, 63};
  static const TCODColor lightChartreuse = tcod::ColorRGB{159, 255, 63};
  static const TCODColor lightGreen      = tcod::ColorRGB{63,  255, 63};
  static const TCODColor lightSea        = tcod::ColorRGB{63,  255, 159};
  static const TCODColor lightTurquoise  = tcod::ColorRGB{63,  255, 207};
  static const TCODColor lightCyan       = tcod::ColorRGB{63,  255, 255};
  static const TCODColor lightSky        = tcod::ColorRGB{63,  207, 255};
  static const TCODColor lightAzure      = tcod::ColorRGB{63,  159, 255};
  static const TCODColor lightBlue       = tcod::ColorRGB{63,   63, 255};
  static const TCODColor lightHan        = tcod::ColorRGB{111,  63, 255};
  static const TCODColor lightViolet     = tcod::ColorRGB{159,  63, 255};
  static const TCODColor lightPurple     = tcod::ColorRGB{207,  63, 255};
  static const TCODColor lightFuchsia    = tcod::ColorRGB{255,  63, 255};
  static const TCODColor lightMagenta    = tcod::ColorRGB{255,  63, 207};
  static const TCODColor lightPink       = tcod::ColorRGB{255,  63, 159};
  static const TCODColor lightCrimson    = tcod::ColorRGB{255,  63, 111};

  // lighter colors
  static const TCODColor lighterRed        = tcod::ColorRGB{255, 127, 127};
  static const TCODColor lighterFlame      = tcod::ColorRGB{255, 159, 127};
  static const TCODColor lighterOrange     = tcod::ColorRGB{255, 191, 127};
  static const TCODColor lighterAmber      = tcod::ColorRGB{255, 223, 127};
  static const TCODColor lighterYellow     = tcod::ColorRGB{255, 255, 127};
  static const TCODColor lighterLime       = tcod::ColorRGB{223, 255, 127};
  static const TCODColor lighterChartreuse = tcod::ColorRGB{191, 255, 127};
  static const TCODColor lighterGreen      = tcod::ColorRGB{127, 255, 127};
  static const TCODColor lighterSea        = tcod::ColorRGB{127, 255, 191};
  static const TCODColor lighterTurquoise  = tcod::ColorRGB{127, 255, 223};
  static const TCODColor lighterCyan       = tcod::ColorRGB{127, 255, 255};
  static const TCODColor lighterSky        = tcod::ColorRGB{127, 223, 255};
  static const TCODColor lighterAzure      = tcod::ColorRGB{127, 191, 255};
  static const TCODColor lighterBlue       = tcod::ColorRGB{127, 127, 255};
  static const TCODColor lighterHan        = tcod::ColorRGB{159, 127, 255};
  static const TCODColor lighterViolet     = tcod::ColorRGB{191, 127, 255};
  static const TCODColor lighterPurple     = tcod::ColorRGB{223, 127, 255};
  static const TCODColor lighterFuchsia    = tcod::ColorRGB{255, 127, 255};
  static const TCODColor lighterMagenta    = tcod::ColorRGB{255, 127, 223};
  static const TCODColor lighterPink       = tcod::ColorRGB{255, 127, 191};
  static const TCODColor lighterCrimson    = tcod::ColorRGB{255, 127, 159};

  // lightest colors
  static const TCODColor lightestRed        = tcod::ColorRGB{255, 191, 191};
  static const TCODColor lightestFlame      = tcod::ColorRGB{255, 207, 191};
  static const TCODColor lightestOrange     = tcod::ColorRGB{255, 223, 191};
  static const TCODColor lightestAmber      = tcod::ColorRGB{255, 239, 191};
  static const TCODColor lightestYellow     = tcod::ColorRGB{255, 255, 191};
  static const TCODColor lightestLime       = tcod::ColorRGB{239, 255, 191};
  static const TCODColor lightestChartreuse = tcod::ColorRGB{223, 255, 191};
  static const TCODColor lightestGreen      = tcod::ColorRGB{191, 255, 191};
  static const TCODColor lightestSea        = tcod::ColorRGB{191, 255, 223};
  static const TCODColor lightestTurquoise  = tcod::ColorRGB{191, 255, 239};
  static const TCODColor lightestCyan       = tcod::ColorRGB{191, 255, 255};
  static const TCODColor lightestSky        = tcod::ColorRGB{191, 239, 255};
  static const TCODColor lightestAzure      = tcod::ColorRGB{191, 223, 255};
  static const TCODColor lightestBlue       = tcod::ColorRGB{191, 191, 255};
  static const TCODColor lightestHan        = tcod::ColorRGB{207, 191, 255};
  static const TCODColor lightestViolet     = tcod::ColorRGB{223, 191, 255};
  static const TCODColor lightestPurple     = tcod::ColorRGB{239, 191, 255};
  static const TCODColor lightestFuchsia    = tcod::ColorRGB{255, 191, 255};
  static const TCODColor lightestMagenta    = tcod::ColorRGB{255, 191, 239};
  static const TCODColor lightestPink       = tcod::ColorRGB{255, 191, 223};
  static const TCODColor lightestCrimson    = tcod::ColorRGB{255, 191, 207};

  // desaturated colors
  static const TCODColor desaturatedRed        = tcod::ColorRGB{127,  63, 63};
  static const TCODColor desaturatedFlame      = tcod::ColorRGB{127,  79, 63};
  static const TCODColor desaturatedOrange     = tcod::ColorRGB{127,  95, 63};
  static const TCODColor desaturatedAmber      = tcod::ColorRGB{127, 111, 63};
  static const TCODColor desaturatedYellow     = tcod::ColorRGB{127, 127, 63};
  static const TCODColor desaturatedLime       = tcod::ColorRGB{111, 127, 63};
  static const TCODColor desaturatedChartreuse = tcod::ColorRGB{95,  127, 63};
  static const TCODColor desaturatedGreen      = tcod::ColorRGB{63,  127, 63};
  static const TCODColor desaturatedSea        = tcod::ColorRGB{63,  127, 95};
  static const TCODColor desaturatedTurquoise  = tcod::ColorRGB{63,  127, 111};
  static const TCODColor desaturatedCyan       = tcod::ColorRGB{63,  127, 127};
  static const TCODColor desaturatedSky        = tcod::ColorRGB{63,  111, 127};
  static const TCODColor desaturatedAzure      = tcod::ColorRGB{63,   95, 127};
  static const TCODColor desaturatedBlue       = tcod::ColorRGB{63,   63, 127};
  static const TCODColor desaturatedHan        = tcod::ColorRGB{79,   63, 127};
  static const TCODColor desaturatedViolet     = tcod::ColorRGB{95,   63, 127};
  static const TCODColor desaturatedPurple     = tcod::ColorRGB{111,  63, 127};
  static const TCODColor desaturatedFuchsia    = tcod::ColorRGB{127,  63, 127};
  static const TCODColor desaturatedMagenta    = tcod::ColorRGB{127,  63, 111};
  static const TCODColor desaturatedPink       = tcod::ColorRGB{127,  63, 95};
  static const TCODColor desaturatedCrimson    = tcod::ColorRGB{127,  63, 79};

  // metallic
  static const TCODColor brass  = tcod::ColorRGB{191, 151, 96};
  static const TCODColor copper = tcod::ColorRGB{197, 136, 124};
  static const TCODColor gold   = tcod::ColorRGB{229, 191, 0};
  static const TCODColor silver = tcod::ColorRGB{203, 203, 203};

  // miscellaneous
  static const TCODColor celadon = tcod::ColorRGB{172, 255, 175};
  static const TCODColor peach   = tcod::ColorRGB{255, 159, 127};

}
