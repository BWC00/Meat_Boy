//
// Created by student on 5/12/22.
//

#include "ConcreteWall.h"
#include "Data.h"

view::ConcreteWall::ConcreteWall(const std::shared_ptr<logic::ConcreteWall>& concrete_wall) : view::Wall(concrete_wall) {
    _sprite.setTexture(view::Data::ConcreteWallTexture);
}