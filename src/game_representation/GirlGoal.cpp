//
// Created by student on 7/12/22.
//

#include "GirlGoal.h"
#include "Data.h"

view::GirlGoal::GirlGoal(const std::shared_ptr<logic::GirlGoal>& girl_goal) : view::Goal(girl_goal) {
    _sprite.setTexture(view::Data::MeatGirlTexture);
}