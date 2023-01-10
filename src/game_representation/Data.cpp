//
// Created by student on 1/12/22.
//

#include "Data.h"

void view::Data::load() {

    // textures
    string2Texture["meatboy"] = loadAsset(MeatBoyTexture, "./Data/Texture/meatboy.png");
    string2Texture["meatgirl"] = loadAsset(MeatGirlTexture, "./Data/Texture/meatgirl.png");
    string2Texture["concrete"] = loadAsset(ConcreteWallTexture, "./Data/Texture/concretewall.jpg");
    string2Texture["mud"] = loadAsset(MudWallTexture, "./Data/Texture/mudwall.png");
    string2Texture["levelbar"] = loadAsset(LevelBarTexture, "./Data/Texture/levelbar.jpeg");
    string2Texture["meatboymenubackground"] = loadAsset(MenuBackgroundTexture, "./Data/Texture/menubackground.jpg");
    string2Texture["cloudybackground"] = loadAsset(CloudyBackgroundTexture, "./Data/Texture/cloudybackground.png");
    string2Texture["lavabackground"] = loadAsset(LavaBackgroundTexture, "./Data/Texture/lavabackground.jpg");

    // fonts
    string2Font["arial"] = loadAsset(font, "./Data/Font/arial.ttf");
    string2Font["gooddog"] = loadAsset(levelFont, "./Data/Font/gooddog.ttf");
}