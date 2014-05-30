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
#include <Rect.h>
#include <Size.h>
#include <gtest.h>

int const X = 5;
int const Y = 4;
int const W = 10;
int const H = 20;

namespace sbe = sdl_backend;

class MockRect : public testing::Test
{
public:
  MockRect()
    : rect(X, Y, W, H)
  {}

  sbe::Rect rect;
};



TEST_F(MockRect, TestInit)
{
  sbe::Rect r;

  EXPECT_EQ(r.x(),      0);
  EXPECT_EQ(r.y(),      0);
  EXPECT_EQ(r.width(),  0);
  EXPECT_EQ(r.height(), 0);
}

TEST_F(MockRect, TestInitValue)
{
  EXPECT_EQ(rect.x(),      X);
  EXPECT_EQ(rect.y(),      Y);
  EXPECT_EQ(rect.width(),  W);
  EXPECT_EQ(rect.height(), H);
}

TEST_F(MockRect, TestInitWithPoint)
{
  sbe::Point p(X, Y);
  sbe::Rect r(p, W, H);

  EXPECT_EQ(r.x(),      X);
  EXPECT_EQ(r.y(),      Y);
  EXPECT_EQ(r.width(),  W);
  EXPECT_EQ(r.height(), H);
}

TEST_F(MockRect, TestInitWithSize)
{
  sbe::Size s(W, H);
  sbe::Rect r(X, Y, s);

  EXPECT_EQ(r.x(),      X);
  EXPECT_EQ(r.y(),      Y);
  EXPECT_EQ(r.width(),  W);
  EXPECT_EQ(r.height(), H);
}

TEST_F(MockRect, TestInitWithPointAndSize)
{
  sbe::Point p(X, Y);
  sbe::Size  s(W, H);
  sbe::Rect  r(p, s);

  EXPECT_EQ(r.x(),      X);
  EXPECT_EQ(r.y(),      Y);
  EXPECT_EQ(r.width(),  W);
  EXPECT_EQ(r.height(), H);
}

TEST_F(MockRect, TestConvertToSDLRect)
{
  SDL_Rect r = rect.sdl_rect();

  EXPECT_EQ(r.x, X);
  EXPECT_EQ(r.y, Y);
  EXPECT_EQ(r.w, W);
  EXPECT_EQ(r.h, H);
}

TEST_F(MockRect, TestSetX)
{
  rect.SetX(rect.x() * 2);

  EXPECT_EQ(rect.x(),      X*2);
  EXPECT_EQ(rect.y(),      Y);
  EXPECT_EQ(rect.width(),  W);
  EXPECT_EQ(rect.height(), H);
}

TEST_F(MockRect, TestSetY)
{
  rect.SetY(rect.y() * 2);

  EXPECT_EQ(rect.x(),      X);
  EXPECT_EQ(rect.y(),      Y*2);
  EXPECT_EQ(rect.width(),  W);
  EXPECT_EQ(rect.height(), H);
}

TEST_F(MockRect, TestSetWidth)
{
  rect.SetWidth(rect.width() * 2);

  EXPECT_EQ(rect.x(),      X);
  EXPECT_EQ(rect.y(),      Y);
  EXPECT_EQ(rect.width(),  W*2);
  EXPECT_EQ(rect.height(), H);
}

TEST_F(MockRect, TestSetHeight)
{
  rect.SetHeight(rect.height() * 2);

  EXPECT_EQ(rect.x(),      X);
  EXPECT_EQ(rect.y(),      Y);
  EXPECT_EQ(rect.width(),  W);
  EXPECT_EQ(rect.height(), H*2);
}

TEST_F(MockRect, TestIntersecting)
{
  sbe::Rect r(X + X/2, Y + Y/2, W, H);

  EXPECT_TRUE(r.Intersecting(rect));
}

TEST_F(MockRect, TestNotIntersecting)
{
  sbe::Rect r(X + W + 1, Y + H + 1, W, H);

  EXPECT_FALSE(r.Intersecting(rect));
}

TEST_F(MockRect, TestPointInside)
{
  sbe::Point p(X + X/2, Y + Y/2);

  EXPECT_TRUE(rect.PointInside(p));
}

TEST_F(MockRect, TestPointNotInside)
{
  sbe::Point p(X + W + 1, Y + H + 1);

  EXPECT_FALSE(rect.PointInside(p));
}

TEST_F(MockRect, TestShrink)
{
  int SHRINK = 10;
  rect.Shrink(SHRINK);

  EXPECT_EQ(rect.x(),      X + SHRINK);
  EXPECT_EQ(rect.y(),      Y + SHRINK);
  EXPECT_EQ(rect.width(),  W - SHRINK * 2);
  EXPECT_EQ(rect.height(), H - SHRINK * 2);
}

TEST_F(MockRect, TestExpand)
{
  int EXPAND = 10;
  rect.Expand(EXPAND);

  EXPECT_EQ(rect.x(),      X - EXPAND);
  EXPECT_EQ(rect.y(),      Y - EXPAND);
  EXPECT_EQ(rect.width(),  W + EXPAND * 2);
  EXPECT_EQ(rect.height(), H + EXPAND * 2);
}

TEST_F(MockRect, TestCopy)
{
  sbe::Rect r = rect;

  EXPECT_EQ(r, rect);
}

TEST_F(MockRect, TestEqualityOperator)
{
  sbe::Rect r = rect;

  EXPECT_TRUE(r == rect);
}

TEST_F(MockRect, TestInequalityOperator)
{
  sbe::Rect r = rect;
  r.SetX(r.x() + 1);

  EXPECT_TRUE(r != rect);
}
