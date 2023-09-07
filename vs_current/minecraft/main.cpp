//c++20
#include <SFML/Graphics.hpp>

#include "Engine/Engine.h"
#include "Screens/TittleScreen/MainScreen.h"
#include "Screens/LoadScreen/LoadScreen.h"
#include "Screens/GameScreen/GameScreen.h"

int main() {
    constexpr int mWindow_x = 960;
    constexpr int mWindow_y = 540;

    sf::RenderWindow window(sf::VideoMode(mWindow_x, mWindow_y), "Minecraft", sf::Style::Close);

    gameState currentState = gameState::Menu;
    LoadState loadStatus = LoadState::ls_false;

    Engine game(window);
    MainScreen menuScreen(window, currentState, loadStatus);
    LoadScreen loadScreen(window, currentState, loadStatus);
    GameScreen gameScreen(window, currentState, loadStatus);

    while (window.isOpen()) {
        switch (currentState) {
            case gameState::Menu:
                menuScreen.run();
                break;

            case gameState::Loading:
                loadScreen.run();
                break;

            case gameState::SP_Gameplay:
                gameScreen.run();
                break;

            default:
                window.close();
                break;
        }
    }

    return 0x0;
}