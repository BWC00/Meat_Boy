//
// Created by Mohammed Shakleya on 12/12/2022.
//

#include "Level.h"
#include "Data.h"
#include "Window.h"

view::Level::Level(const std::string& name) : _name(name) {
    _sprite.setTexture(view::Data::LevelBarTexture);
    _spriteText.setFont(view::Data::levelFont);
    _spriteText.setCharacterSize(50);
    _spriteText.setFillColor(sf::Color::Black);
    _spriteText.setString(name);
}

const std::string& view::Level::getName() const {
    return _name;
}

int view::Level::getHeight() const {
    return _sprite.getTexture()->getSize().y;
}

int view::Level::getWidth() const {
    return _sprite.getTexture()->getSize().x;
}

sf::Sprite& view::Level::getSprite() {
    return _sprite;
}

sf::Text& view::Level::getText() {
    return _spriteText;
}

void view::Level::draw(int y) {
	_sprite.setPosition(1200/2-getWidth()/2, y);
	_spriteText.setPosition(1200/2-(_spriteText.getGlobalBounds().width/2),y+(getHeight()/2)-(_spriteText.getGlobalBounds().height/2));
    view::Window::getWindow()->draw(_sprite);
    view::Window::getWindow()->draw(_spriteText);
}