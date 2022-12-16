//
// Created by student on 1/12/22.
//

#include "Data.h"

void view::Data::load() {
    loadAsset(MeatBoyTexture, "../Data/Texture/MeatBoy.png");
    loadAsset(MeatGirlTexture, "../Data/Texture/MeatGirl.png");
    loadAsset(ConcreteWallTexture, "../Data/Texture/ConcreteWall.jpg");
    loadAsset(LevelBarTexture, "../Data/Texture/LevelBar.jpeg");
    loadAsset(MenuBackgroundTexture, "../Data/Texture/MenuBackground.jpg");
    loadAsset(font, "../Data/Font/arial.ttf");
    loadAsset(levelFont, "../Data/Font/gooddog.ttf");
}