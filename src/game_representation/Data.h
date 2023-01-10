//
// Created by student on 1/12/22.
//

#ifndef INC_2022_PROJECT_BWC00_DATA_H
#define INC_2022_PROJECT_BWC00_DATA_H

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <string>

namespace view {
namespace Data {
inline sf::Texture MeatBoyTexture;
inline sf::Texture ConcreteWallTexture;
inline sf::Texture MudWallTexture;
inline sf::Texture MeatGirlTexture;
inline sf::Texture LevelBarTexture;
inline sf::Texture MenuBackgroundTexture;
inline sf::Texture CloudyBackgroundTexture;
inline sf::Texture LavaBackgroundTexture;

inline sf::Font font;
inline sf::Font levelFont;

void load();

inline std::map<std::string, sf::Texture> string2Texture;
inline std::map<std::string, sf::Font> string2Font;

template <typename T>
T& loadAsset(T& asset, const std::string& path) {
    if (!asset.loadFromFile(path)) {
        // throw MissingAsset(path);
    }
    return asset;
}
}; // namespace Data
} // namespace view

#endif // INC_2022_PROJECT_BWC00_DATA_H
