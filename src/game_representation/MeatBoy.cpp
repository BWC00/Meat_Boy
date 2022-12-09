//
// Created by student on 7/12/22.
//

#include "MeatBoy.h"
#include "Data.h"

view::MeatBoy::MeatBoy(const std::shared_ptr<logic::MeatBoy>& meatboy) : view::Player(meatboy) {
    _sprite.setTexture(view::Data::MeatBoyTexture);
}