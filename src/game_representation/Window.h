//
// Created by Mohammed Shakleya on 14/12/2022.
//

#ifndef INC_2022_PROJECT_BWC00_WINDOW_H
#define INC_2022_PROJECT_BWC00_WINDOW_H

#include <SFML/Graphics.hpp>
#include <memory>

namespace view {
class Window {
public:
    // getters
    static std::unique_ptr<sf::RenderWindow>& getWindow();
    std::unique_ptr<sf::RenderWindow>& _getWindow();

    Window(const Window&) = delete;

private:
    Window();

    std::unique_ptr<sf::RenderWindow> _window;
};
} // namespace view

#endif // INC_2022_PROJECT_BWC00_WINDOW_H
