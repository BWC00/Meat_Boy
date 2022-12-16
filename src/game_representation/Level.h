//
// Created by Mohammed Shakleya on 12/12/2022.
//

#ifndef INC_2022_PROJECT_BWC00_LEVEL_H
#define INC_2022_PROJECT_BWC00_LEVEL_H

#include <string>
#include <SFML/Graphics.hpp>

namespace view {
    class Level {
    public:
        explicit Level(const std::string&);
        const std::string& getName() const;
        int getWidth() const;
        int getHeight() const;
        sf::Sprite& getSprite();
        sf::Text& getText();
        void draw(int y);
    private:
        std::string _name;
        sf::Sprite _sprite;
        sf::Text _spriteText;
    };
}


#endif //INC_2022_PROJECT_BWC00_LEVEL_H
