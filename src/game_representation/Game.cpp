//
// Created by student on 1/12/22.
//


#include "Game.h"
#include "Data.h"
#include "../logic_library/Stopwatch.h"
#include "Window.h"

view::Game::Game() : _running(true) {

    //init
    Data::load();
    view::Window::getWindow();
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
    sf::Event event;
    while(view::Window::getWindow()->pollEvent(event)){
        if(event.type == sf::Event::Closed){
            view::Window::getWindow()->close();
            _running = false;
        }
    }
    if (!_running) {
        _stateManager->exitKey();
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        _stateManager->rightKey();
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        _stateManager->leftKey();
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		_stateManager->upKey();
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		_stateManager->downKey();
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        _stateManager->spaceKey();
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
		_stateManager->enterKey();
    } else {
        _stateManager->noInput();
    }
}

void view::Game::Sleep() {
    logic::Stopwatch::sleep();
}

void view::Game::clearWindow() {
    view::Window::getWindow()->clear(sf::Color::Black);
}

void view::Game::createManager() {
    _stateManager = std::make_shared<view::StateManager>();
}

void view::Game::Display() {
    view::Window::getWindow()->display();
}
