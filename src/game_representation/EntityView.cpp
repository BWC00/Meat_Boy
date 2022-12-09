//
// Created by student on 5/12/22.
//

#include "EntityView.h"
#include "Data.h"

view::EntityView::EntityView(const std::shared_ptr<logic::EntityModel> &entity_model) {
    _entityModel = entity_model;
}
void view::EntityView::setView(std::shared_ptr<logic::Camera>& p) {
    _view = p;
}

void view::EntityView::setWindow(std::shared_ptr<sf::RenderWindow>& w) {
    _window = w;
}

void view::EntityView::Update(logic::EVENT e, logic::Subject* theChangedSubject) {
    if (e == logic::EVENT::MOVE) {
        std::pair<int, int> pixelPosition = _view->project(_entityModel.lock()->getPosition());
        _sprite.setPosition(pixelPosition.first, pixelPosition.second);
        _window->draw(_sprite);
    }
}