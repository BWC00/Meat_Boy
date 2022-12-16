//
// Created by Mohammed Shakleya on 14/12/2022.
//

#ifndef INC_2022_PROJECT_BWC00_WINDOW_H
#define INC_2022_PROJECT_BWC00_WINDOW_H

#include <memory>
#include <SFML/Graphics.hpp>

namespace view {
    class Window {
    public:
        Window(const Window&) = delete;
        static std::shared_ptr<sf::RenderWindow>& getWindow();
        std::shared_ptr<sf::RenderWindow>& _getWindow();
    private:
        Window();
        std::shared_ptr<sf::RenderWindow> _window;
    };
}

#endif //INC_2022_PROJECT_BWC00_WINDOW_H
