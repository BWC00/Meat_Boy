//
// Created by student on 1/12/22.
//

#ifndef INC_2022_PROJECT_BWC00_DATA_H
#define INC_2022_PROJECT_BWC00_DATA_H

#include <string>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>

namespace view {
    namespace Data {
        inline sf::Texture MeatBoyTexture;
        inline sf::Texture ConcreteWallTexture;
        inline sf::Texture MeatGirlTexture;
        inline sf::Font font;

        void load();
        template<typename T>
        void loadAsset(T &asset, const std::string &path) {
            if (!asset.loadFromFile(path)) {
                //throw MissingAsset(path);
            }
        }
    };
}

#endif //INC_2022_PROJECT_BWC00_DATA_H
