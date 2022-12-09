//
// Created by student on 5/12/22.
//

#ifndef INC_2022_PROJECT_BWC00_ENTITYMODEL_H
#define INC_2022_PROJECT_BWC00_ENTITYMODEL_H


#include "Subject.h"
#include "INPUT.h"

namespace logic {
    class EntityModel : public logic::Subject {
    public:
        EntityModel(double x, double y);
        ~EntityModel() override = default;
        const std::pair<double, double>& getPosition();
        const std::pair<double, double>& getHitbox();
        void setPosition(const std::pair<double, double>& position);
        void setPosition(double x, double y);
        virtual void Update(logic::INPUT)=0;
    protected:
        std::pair<double, double> _position;
        std::pair<double, double> _hitBox;
    };
}


#endif //INC_2022_PROJECT_BWC00_ENTITYMODEL_H
