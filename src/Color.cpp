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

#include "Color.h"

namespace sdl_backend
{

Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
  : r_(r)
  , g_(g)
  , b_(b)
  , a_(a)
{
}

Color::Color(SDL_Color const& color)
  : r_(color.r)
  , g_(color.g)
  , b_(color.b)
  , a_(color.a)
{
}

void Color::RandomizeRGB()
{
  r_ = rand() % 255;
  g_ = rand() % 255;
  b_ = rand() % 255;
}

SDL_Color Color::SDLColor() const
{
  return {r_, g_, b_, a_};
}

uint8_t Color::Red()   const
{
  return r_;
}

uint8_t Color::Green() const
{
  return g_;
}

uint8_t Color::Blue()  const
{
  return b_;
}

uint8_t Color::Alpha() const
{
  return a_;
}

} // namespace sdl_backend
