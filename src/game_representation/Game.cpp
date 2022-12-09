//
// Created by student on 1/12/22.
//


#include "Game.h"
#include "Data.h"
#include "../logic_library/Stopwatch.h"

view::Game::Game(int windowWidth, int windowHeight) : _running(true) {

    //init
    Data::load();
    createWindow(windowWidth, windowHeight);
    createManager();

    //run
    run();
}

void view::Game::run() {
    _running = true;
    while(_running) { //zet in juiste volgorde
        clearWindow();
        Sleep();
        handleInput();
        Display();
    }
}

void view::Game::handleInput() {
    sf::Event event{};
    while(_window->pollEvent(event)){
        if(event.type == sf::Event::Closed){
            _window->close();
            _running = false;
        }
    }
    if (!_running) {
        _stateManager->handleInput(logic::INPUT::EXIT);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        _stateManager->handleInput(logic::INPUT::RIGHT);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        _stateManager->handleInput(logic::INPUT::LEFT);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        _stateManager->handleInput(logic::INPUT::SPACE);
    } else {
        _stateManager->handleInput(logic::INPUT::NONE);
    }
}

void view::Game::Sleep() {
    logic::Stopwatch::sleep();
}

void view::Game::clearWindow() {
    _window->clear(sf::Color::Black);
}

void view::Game::createManager() {
    _stateManager = std::make_shared<view::StateManager>();
}

void view::Game::Display() {
    _window->display();
}

void view::Game::createWindow(int width, int height) {
    _window = std::make_shared<sf::RenderWindow>();
    _window->create(sf::VideoMode(width, height), "Doodle Jump");
    //_window.setIcon(m_app_icon.getSize().x, m_app_icon.getSize().y, m_app_icon.getPixelsPtr());
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    _window->setPosition(sf::Vector2i(desktop.width / 2 - _window->getSize().x/2, desktop.height/2 - _window->getSize().y/2));
}