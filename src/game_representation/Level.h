//
// Created by Mohammed Shakleya on 12/12/2022.
//

#ifndef INC_2022_PROJECT_BWC00_LEVEL_H
#define INC_2022_PROJECT_BWC00_LEVEL_H

#include <SFML/Graphics.hpp>
#include <string>

namespace view {
class Level {
public:
    // getters
    const std::string& getName() const;
    const std::string& getBackgroundTextureName() const;
    int getWidth() const;
    int getHeight() const;

    // setters
    std::unique_ptr<sf::Sprite>& getSprite();
    std::unique_ptr<sf::Text>& getText();

    void draw(int y);
    bool operator<(const Level&);

    explicit Level(const std::string&);

private:
    std::unique_ptr<sf::Sprite> _sprite;
    std::unique_ptr<sf::Text> _spriteText;
    const std::string _name;
    std::string _backgroundTextureName;
};
} // namespace view

#endif // INC_2022_PROJECT_BWC00_LEVEL_H
