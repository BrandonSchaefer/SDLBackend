// -*- Mode: C++; indent-tabs-mode: nil; tab-width: 2 -*-
/*
 * Copyright (C) 2014 Brandon Schaefer
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Authored by: Brandon Schaefer <brandontschaefer@gmail.com>
 */

#ifndef COLOR_H
#define COLOR_H

#include <SDL2/SDL.h>

namespace sdl_backend
{

namespace color
{
  SDL_Color const RED   = {255, 0, 0, 255};
  SDL_Color const GREEN = {0, 255, 0, 255};
  SDL_Color const BLUE  = {0, 0, 255, 255};
  SDL_Color const WHITE  = {255, 255, 255, 255};
  SDL_Color const GREY   = {120, 120, 120, 255};
  SDL_Color const BLACK  = {  0,   0,   0, 255};
  SDL_Color const YELLOW = {255, 255,   0, 255};
  SDL_Color const DARK_GREY = {80, 80, 80, 255};
} // namespace color

class Color
{
public:
  Color(uint8_t r = 0, uint8_t g = 0, uint8_t b = 0, uint8_t a = 0);
  Color(SDL_Color const& color);

  void RandomizeRGB();

  SDL_Color SDLColor() const;

  uint8_t Red()   const;
  uint8_t Blue()  const;
  uint8_t Green() const;
  uint8_t Alpha() const;

private:
  uint8_t r_;
  uint8_t g_;
  uint8_t b_;
  uint8_t a_;

};

} // namespace sdl_backend

#endif // COLOR_H
