#include "header.h"
#include "Engine/Engine.h"
#include "Screens/TittleScreen/MainScreen.h"
#include "Screens/LoadScreen/LoadScreen.h"
#include "Screens/GameScreen/GameScreen.h"

int main() {
    constexpr static int mWindow_x = 960;
    constexpr static int mWindow_y = 540;

    sf::RenderWindow window(sf::VideoMode(mWindow_x, mWindow_y), "Minecraft", sf::Style::Close);

    gameState currentState = gameState::Menu;
    LoadState loadStatus = LoadState::ls_false;

    Engine game(window);
    MainScreen mainMenu(window, currentState, loadStatus);
    LoadScreen loadScreen(window, currentState, loadStatus);
    GameScreen gameScreen(window, currentState, loadStatus);

    while (window.isOpen()) {
        switch (currentState) {
            case gameState::Menu:
                mainMenu.run();
                break;

            case gameState::Loading:
                loadScreen.run();
                break;

            case gameState::SP_Gameplay:
                gameScreen.run();
                break;

            default:
                break;
        }
    }

    return 0x0;
}