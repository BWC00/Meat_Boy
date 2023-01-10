//
// Created by student on 1/12/22.
//

#include "Game.h"
#include "../logic_library/Stopwatch.h"
#include "Data.h"
#include "MenuState.h"
#include "Window.h"
#include <iostream>

view::Game::Game() : _running(false), _stateManager(nullptr) {

    // init
    Data::load();
    view::Window::getWindow();
    _createManager();
}

void view::Game::run() {

    _running = true;

    // run game
    while (_running) {
        _clearWindow();
        _sleep();
        _handleInput();
        _display();
    }
    view::Window::getWindow()->close();
}

void view::Game::_handleInput() {
    sf::Event event;
    while (view::Window::getWindow()->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            _running = false;
        }
    }

    bool firstKey = true;
    bool noInput = true;

    if (!_running) {
        _stateManager->handleInput(logic::EVENT::EXIT, firstKey);
        firstKey = false;
        noInput = false;
        return;
    }

    if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space) {
        _stateManager->handleInput(logic::EVENT::SPACERELEASE, false);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        _stateManager->handleInput(logic::EVENT::ESC, firstKey);
        firstKey = false;
        noInput = false;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        _stateManager->handleInput(logic::EVENT::RIGHT, firstKey);
        firstKey = false;
        noInput = false;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        _stateManager->handleInput(logic::EVENT::LEFT, firstKey);
        firstKey = false;
        noInput = false;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        _stateManager->handleInput(logic::EVENT::UP, firstKey);
        firstKey = false;
        noInput = false;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        _stateManager->handleInput(logic::EVENT::DOWN, firstKey);
        firstKey = false;
        noInput = false;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && sf::Event::KeyReleased && sf::Keyboard::Space) {
        _stateManager->handleInput(logic::EVENT::SPACE, firstKey);
        firstKey = false;
        noInput = false;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
        _stateManager->handleInput(logic::EVENT::ENTER, firstKey);
        firstKey = false;
        noInput = false;
    }
    if (noInput) {
        _stateManager->handleInput(logic::EVENT::NONE, firstKey);
    }
}

void view::Game::_sleep() { logic::Stopwatch::sleep(); }

void view::Game::_clearWindow() { view::Window::getWindow()->clear(sf::Color::Black); }

void view::Game::_createManager() {
    _stateManager = std::make_shared<view::StateManager>();
    _stateManager->changeState(std::make_unique<view::MenuState>());
}

void view::Game::_display() { view::Window::getWindow()->display(); }
