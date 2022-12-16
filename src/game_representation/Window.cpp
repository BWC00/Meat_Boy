//
// Created by Mohammed Shakleya on 14/12/2022.
//

#include "Window.h"

view::Window::Window() {
    _window = std::make_shared<sf::RenderWindow>();
    _window->create(sf::VideoMode(1200, 1600), "Meat Boy");
    //_window.setIcon(m_app_icon.getSize().x, m_app_icon.getSize().y, m_app_icon.getPixelsPtr());
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    _window->setPosition(sf::Vector2i(desktop.width / 2 - _window->getSize().x/2, desktop.height/2 - _window->getSize().y/2));
}

std::shared_ptr<sf::RenderWindow>& view::Window::getWindow() {
    static Window instance;
    return instance._getWindow();
}

std::shared_ptr<sf::RenderWindow>& view::Window::_getWindow() {
    return _window;
}