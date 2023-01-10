//
// Created by student on 7/12/22.
//

#include "GirlGoal.h"
#include "Data.h"

view::GirlGoal::GirlGoal(const std::shared_ptr<logic::GirlGoal>& girlGoal, const std::string& textureName)
    : view::Goal(girlGoal) {
    _sprite->setTexture(view::Data::string2Texture[textureName]);
}