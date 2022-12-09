//
// Created by student on 5/12/22.
//

#ifndef INC_2022_PROJECT_BWC00_ENTITYVIEW_H
#define INC_2022_PROJECT_BWC00_ENTITYVIEW_H

#include "../logic_library/Observer.h"
#include "../logic_library/Camera.h"
#include "../logic_library/EntityModel.h"
#include <SFML/Graphics.hpp>

namespace view {
    class EntityView : public logic::Observer {
    public:
        explicit EntityView(const std::shared_ptr<logic::EntityModel>& entity_model);
        EntityView() = default;
        ~EntityView() override = default;
        void setView(std::shared_ptr<logic::Camera>& p);
        void setWindow(std::shared_ptr<sf::RenderWindow>& w);
        void Update(logic::EVENT, logic::Subject*) override;
    protected:
        sf::Sprite _sprite;
        std::weak_ptr<logic::EntityModel> _entityModel;
        std::shared_ptr<logic::Camera> _view;
        std::shared_ptr<sf::RenderWindow> _window;
    };
}


#endif //INC_2022_PROJECT_BWC00_ENTITYVIEW_H
