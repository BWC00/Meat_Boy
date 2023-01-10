//
// Created by Mohammed Shakleya on 14/12/2022.
//

#include "Window.h"
#include "../logic_library/CONSTANTS.h"

view::Window::Window() {
    _window = std::make_unique<sf::RenderWindow>();
    _window->create(sf::VideoMode(logic::constants::RENDERWINDOW_WIDTH, logic::constants::RENDERWINDOW_HEIGHT),
                    "Meat Boy");
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    _window->setPosition(
        sf::Vector2i(desktop.width / 2 - _window->getSize().x / 2, desktop.height / 2 - _window->getSize().y / 2));
}

std::unique_ptr<sf::RenderWindow>& view::Window::getWindow() {
    static Window instance;
    return instance._getWindow();
}

std::unique_ptr<sf::RenderWindow>& view::Window::_getWindow() { return _window; }