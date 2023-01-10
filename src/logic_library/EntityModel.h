//
// Created by student on 5/12/22.
//

#ifndef INC_2022_PROJECT_BWC00_ENTITYMODEL_H
#define INC_2022_PROJECT_BWC00_ENTITYMODEL_H

#include "Subject.h"
#include <string>

namespace logic {
class EntityModel : public logic::Subject {
public:
    // getters
    const std::pair<double, double>& getPosition();
    const std::pair<double, double>& getOriginalPosition() const;
    const std::pair<double, double>& getHitbox() const;
    const std::string& getTexture() const;

    // setters
    void setPosition(double x, double y);

    EntityModel(double x, double y, const std::string&);
    ~EntityModel() override = default;

protected:
    std::pair<double, double> _position;
    std::pair<double, double> _hitBox;
    const std::pair<double, double> _originalPosition;
    const std::string _textureName;
};
} // namespace logic

#endif // INC_2022_PROJECT_BWC00_ENTITYMODEL_H
