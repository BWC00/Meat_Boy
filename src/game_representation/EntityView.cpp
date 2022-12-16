//
// Created by student on 5/12/22.
//

#include "EntityView.h"
#include "Data.h"
#include "Window.h"
#include "../logic_library/Camera.h"

view::EntityView::EntityView(const std::shared_ptr<logic::EntityModel> &entity_model)  {
    _entityModel = entity_model;
}

void view::EntityView::Update(logic::EVENT e, logic::Subject* theChangedSubject) {
    if (e == logic::EVENT::MOVE) {
        std::pair<int, int> pixelPosition = logic::Camera::getCamera().project(_entityModel.lock()->getPosition());
        _sprite.setPosition(pixelPosition.first, pixelPosition.second);
        view::Window::getWindow()->draw(_sprite);
    }
}