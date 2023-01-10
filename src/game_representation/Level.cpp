//
// Created by Mohammed Shakleya on 12/12/2022.
//

#include "Level.h"
#include "../json.hpp"
#include "../logic_library/CONSTANTS.h"
#include "CONSTANTS.h"
#include "Data.h"
#include "Window.h"
#include <fstream>

using json = nlohmann::json;

view::Level::Level(const std::string& name) : _name(name) {

    _sprite = std::make_unique<sf::Sprite>();
    _spriteText = std::make_unique<sf::Text>();

    std::ifstream f("./Data/Levels/" + name);
    json data = json::parse(f);
    _backgroundTextureName = data["background"];

    _sprite->setTexture(view::Data::string2Texture[view::constants::LEVELBAR_TEXTURE_NAME]);
    _spriteText->setFont(view::Data::string2Font[view::constants::LEVEL_TEXT_FONT_NAME]);
    _spriteText->setCharacterSize(view::constants::LEVEL_TEXT_CHARACTER_SIZE);
    _spriteText->setFillColor(view::constants::LEVEL_TEXT_COLOR);
    _spriteText->setString(name);
}

const std::string& view::Level::getName() const { return _name; }

const std::string& view::Level::getBackgroundTextureName() const { return _backgroundTextureName; }

int view::Level::getHeight() const { return _sprite->getTexture()->getSize().y; }

int view::Level::getWidth() const { return _sprite->getTexture()->getSize().x; }

std::unique_ptr<sf::Sprite>& view::Level::getSprite() { return _sprite; }

bool view::Level::operator<(const view::Level& l) { return (_name < l._name); }

std::unique_ptr<sf::Text>& view::Level::getText() { return _spriteText; }

void view::Level::draw(int y) {
    _sprite->setPosition(logic::constants::RENDERWINDOW_WIDTH / 2 - getWidth() / 2, y);
    _spriteText->setPosition(logic::constants::RENDERWINDOW_WIDTH / 2 - (_spriteText->getGlobalBounds().width / 2),
                             y + (getHeight() / 2) - (_spriteText->getGlobalBounds().height / 2));
    view::Window::getWindow()->draw(*_sprite);
    view::Window::getWindow()->draw(*_spriteText);
}