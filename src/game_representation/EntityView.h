//
// Created by student on 5/12/22.
//

#ifndef INC_2022_PROJECT_BWC00_ENTITYVIEW_H
#define INC_2022_PROJECT_BWC00_ENTITYVIEW_H

#include "../logic_library/Camera.h"
#include "../logic_library/EntityModel.h"
#include "../logic_library/Observer.h"
#include <SFML/Graphics.hpp>

namespace view {
class EntityView : public logic::Observer {
public:
    void update(logic::EVENT, logic::Subject*) override;

    explicit EntityView(const std::shared_ptr<logic::EntityModel>&);
    ~EntityView() override = default;

protected:
    std::unique_ptr<sf::Sprite> _sprite;
    std::weak_ptr<logic::EntityModel> _entityModel;
};
} // namespace view

#endif // INC_2022_PROJECT_BWC00_ENTITYVIEW_H
