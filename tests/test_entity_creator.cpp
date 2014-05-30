//-*- Mode: C++; indent-tabs-mode: nil; tab-width: 2 -*-
/* * Copyright (C) 2014 Brandon Schaefer
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

#include <EntityCreator.h>
#include <gtest.h>

namespace sbe = sdl_backend;

class MockEntityCreator : public testing::Test
{
public:
  MockEntityCreator()
  {}

  sbe::EntityCreator ec;
};

TEST_F(MockEntityCreator, TestUniqueID)
{
  int first_id = ec.GetUniqueId();
  EXPECT_EQ (first_id, ec.GetUniqueId() - 1);
}

TEST_F(MockEntityCreator, TestNoDuplicateID)
{
  sbe::EntityCreator ec2;
  int first_id  = ec.GetUniqueId();
  int second_id = ec2.GetUniqueId();

  EXPECT_NE (first_id, second_id);

  // The second generation should always be 1 more then the prev call.
  EXPECT_EQ (first_id, second_id - 1);
}
