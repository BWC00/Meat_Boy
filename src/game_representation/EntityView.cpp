//
// Created by student on 5/12/22.
//

#include "EntityView.h"
#include "Data.h"
#include "Window.h"

view::EntityView::EntityView(const std::shared_ptr<logic::EntityModel>& entityModel) : _entityModel(entityModel) {
    _sprite = std::make_unique<sf::Sprite>();
}

void view::EntityView::update(logic::EVENT e, logic::Subject* theChangedSubject) {
    if (e == logic::EVENT::TICK) {
        std::pair<int, int> pixelPosition = logic::Camera::getCamera().project(_entityModel.lock()->getPosition());
        _sprite->setPosition(pixelPosition.first, pixelPosition.second);
        view::Window::getWindow()->draw(*_sprite);
    }
}