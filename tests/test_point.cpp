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

#include <Point.h>
#include <gtest.h>

int const X = 5;
int const Y = 4;

namespace sbe = sdl_backend;

class MockPoint : public testing::Test
{
public:
  MockPoint()
    : point(X, Y)
  {}

  sbe::Point point;
};

TEST_F(MockPoint, TestInit)
{
  sbe::Point p;

  EXPECT_EQ(p.x, 0);
  EXPECT_EQ(p.y, 0);
}

TEST_F(MockPoint, TestInitValue)
{
  EXPECT_EQ(point.x, X);
  EXPECT_EQ(point.y, Y);
}

TEST_F(MockPoint, TestCopy)
{
  sbe::Point p = point;

  EXPECT_EQ(p.x, X);
  EXPECT_EQ(p.y, Y);
}

TEST_F(MockPoint, TestEqualityOperator)
{
  sbe::Point p = point;

  EXPECT_TRUE(p == point);
}

TEST_F(MockPoint, TestInequalityOperator)
{
  sbe::Point p = point;
  p.x++;

  EXPECT_TRUE(p != point);
}
