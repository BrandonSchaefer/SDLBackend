//-*- Mode: C++; indent-tabs-mode: nil; tab-width: 2 -*-
/* * Copyright (C) 2015 Brandon Schaefer
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

#include <MainLoop.h>
#include <gtest/gtest.h>

namespace sbe = sdl_backend;

namespace
{
std::string const TITLE{"Testing"};
int const WIDTH{800};
int const HEIGHT{600};
}

class MockMainLoop : public testing::Test
{
public:
  MockMainLoop()
    : main_loop(TITLE, WIDTH, HEIGHT)
  {
  }

  sbe::MainLoop main_loop;
};

TEST_F(MockMainLoop, TestMainLoopInit)
{
  ASSERT_TRUE(main_loop.Renderer());
  ASSERT_TRUE(main_loop.Window());
}
