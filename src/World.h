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

#ifndef WORLD_H
#define WORLD_H

#include "Entity.h"
#include "EntityHashTable.h"
#include "EntityLayer.h"
#include "Rect.h"

#include <memory>
#include <vector>

namespace sdl_backend
{

class World
{
public:
  typedef std::shared_ptr<World> Ptr;

  World(Rect const& rect);

  Rect Boundary() const;
  void SetBoundary(Rect const& rect);

  void AddLayerToTop(EntityLayer::Ptr const& entity_layer);
  void AddLayerToMiddle(EntityLayer::Ptr const& entity_layer);
  void AddLayerToBottom(EntityLayer::Ptr const& entity_layer);

  Entity::Ptr GetEntity(unsigned id);
  void RemoveEntity(unsigned id);

  void UpdatePositions(World::Ptr const& world) const;
  void Update(float delta_time) const;
  void Draw(GraphicsRenderer* renderer) const;

  void EmitKeyDown(int keysym, int state, int repeat) const;
  void EmitKeyUp(int keysym, int state, int repeat) const;

  void EmitTextInput(std::string const& text) const;

  void EmitMouseDown(int x, int y, int button, int clicks) const;
  void EmitMouseUp(int x, int y, int button, int clicks) const;

  void EmitMouseMove(int x, int y, int xrel, int yrel, int state) const;

  void EmitMouseWheel(int x, int y) const;

  void EmitFingerMotion(int x, int y, int dx, int dy) const;
  void EmitFingerDown(int x, int y, int dx, int dy) const;
  void EmitFingerUp(int x, int y, int dx, int dy) const;

  void SetGameData(void* game_data);
  void* GameData();

private:
  std::vector<EntityLayer::Ptr> top_layers_;
  std::vector<EntityLayer::Ptr> middle_layers_;
  std::vector<EntityLayer::Ptr> bottom_layers_;
  void* game_data_;
  Rect rect_;
};

} // namespace sdl_backend

#endif // WORLD_H
