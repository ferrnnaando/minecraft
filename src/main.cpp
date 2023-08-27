#include "header.h"
#include "Engine/Engine.h"

constexpr int mWindow_x = 960;
constexpr int mWindow_y = 540;

int main() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 2;
    sf::RenderWindow window(sf::VideoMode(mWindow_x, mWindow_y), "Minecraft", sf::Style::Default, settings);
    Engine game(window);
    
    game.run();
}