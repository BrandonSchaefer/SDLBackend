//-*- Mode: C++; indent-tabs-mode: nil; tab-width: 2 -*-
/* * Copyright (C) 2013-2014 Brandon Schaefer
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

#include <Color.h>
#include <gtest/gtest.h>

namespace sbe = sdl_backend;

uint8_t const RED   = 50;
uint8_t const GREEN = 100;
uint8_t const BLUE  = 145;
uint8_t const ALPHA = 255;

SDL_Color const SDL_COLOR = {RED, GREEN, BLUE, ALPHA};

class MockColor : public testing::Test
{
public:
  MockColor()
    : color(RED, GREEN, BLUE, ALPHA)
  {}

  sbe::Color color;
};

TEST_F(MockColor, TestDefaultInit)
{
  sbe::Color c;

  EXPECT_EQ(c.Red(),   0);
  EXPECT_EQ(c.Green(), 0);
  EXPECT_EQ(c.Blue(),  0);
  EXPECT_EQ(c.Alpha(), 0);
}

TEST_F(MockColor, TestInit)
{
  EXPECT_EQ(color.Red(),   RED);
  EXPECT_EQ(color.Green(), GREEN);
  EXPECT_EQ(color.Blue(),  BLUE);
  EXPECT_EQ(color.Alpha(), ALPHA);
}

TEST_F(MockColor, TestSDLColorInit)
{
  sbe::Color c(SDL_COLOR);

  EXPECT_EQ(c.Red(),   RED);
  EXPECT_EQ(c.Green(), GREEN);
  EXPECT_EQ(c.Blue(),  BLUE);
  EXPECT_EQ(c.Alpha(), ALPHA);
}

TEST_F(MockColor, TestSDLColor)
{
  SDL_Color sdl_color = color.SDLColor();

  EXPECT_EQ(sdl_color.r, RED);
  EXPECT_EQ(sdl_color.g, GREEN);
  EXPECT_EQ(sdl_color.b, BLUE);
  EXPECT_EQ(sdl_color.a, ALPHA);
}
