//
// Created by student on 5/12/22.
//

#include "SimpleWall.h"
#include "Data.h"

view::SimpleWall::SimpleWall(const std::shared_ptr<logic::SimpleWall>& concreteWall, const std::string& textureName)
    : view::Wall(concreteWall) {
    _sprite->setTexture(view::Data::string2Texture[textureName]);
}