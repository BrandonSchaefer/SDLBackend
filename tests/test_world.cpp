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

#include <Entity.h>
#include <EntityLayer.h>
#include <World.h>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

namespace sbe = sdl_backend;

namespace
{
  sbe::Rect const RECT     = {0, 0, 200, 200};
  sbe::Rect const NEW_RECT = {0, 0, 400, 400};
}

class MockEntity : public sbe::Entity
{
public:
  typedef std::shared_ptr<MockEntity> Ptr;

  MockEntity(unsigned id)
    : Entity(id)
    , is_key_up(false)
  {
    key_up.connect([this] (int, int, int) {
      is_key_up = true;
    });
  }

  MOCK_METHOD1(Draw, void(sbe::GraphicsRenderer*));
  MOCK_METHOD1(Update, void(float));
  MOCK_METHOD1(UpdatePosition, void(std::shared_ptr<sbe::World> const&));

  bool is_key_up;
};

class MockWorld : public testing::Test
{
public:
  MockWorld()
    : world(RECT)
    , t_layer (std::make_shared<sbe::EntityLayer>())
    , t_entity(std::make_shared<MockEntity>(0))
  {
    t_layer->AddEntity(t_entity);
    world.AddLayerToTop(t_layer);
  }

  sbe::World world;
  sbe::EntityLayer::Ptr t_layer;
  MockEntity::Ptr       t_entity;
};

TEST_F(MockWorld, TestInit)
{
  EXPECT_EQ(RECT, world.Boundary());
}

TEST_F(MockWorld, TestChangeBoundary)
{
  world.SetBoundary(NEW_RECT);
  EXPECT_EQ(NEW_RECT, world.Boundary());
}

TEST_F(MockWorld, TestEntityDraw)
{
  EXPECT_CALL(*t_entity.get(), Draw(nullptr));
  world.Draw(nullptr);
}

TEST_F(MockWorld, TestEntityUpdate)
{
  EXPECT_CALL(*t_entity.get(), Update(1.0f));
  world.Update(1.0f);
}

TEST_F(MockWorld, TestEntityUpdatePosition)
{
  auto const& w_ptr = std::make_shared<sbe::World>(RECT);

  EXPECT_CALL(*t_entity.get(), UpdatePosition(w_ptr));
  world.UpdatePositions(w_ptr);
}

TEST_F(MockWorld, TestEntityKeyUpEvent)
{
  world.EmitKeyUp(0, 0, 0);

  EXPECT_TRUE(t_entity->is_key_up);
}
