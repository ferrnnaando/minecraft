#include "header.h"
#include "Engine/Engine.h"
#include "Screens/TittleScreen/MainScreen.h"

int main() {
    constexpr int mWindow_x = 960;
    constexpr int mWindow_y = 540;
    sf::ContextSettings settings;
    settings.antialiasingLevel = 2;

    sf::RenderWindow window(sf::VideoMode(mWindow_x, mWindow_y), "Minecraft", sf::Style::Close, settings);

    Engine game(window);
    MainScreen mainMenu(window);
    
    while(window.isOpen()) {
            mainMenu.run();
    }

    return 0x0;
} 