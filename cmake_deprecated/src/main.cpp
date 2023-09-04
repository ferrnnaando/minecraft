#include "header.h"
#include "Engine/Engine.h"
#include "Screens/TittleScreen/MainScreen.h"
//#include "Screens/LoadScreen/LoadScreen.h"

int main() {
    constexpr int mWindow_x = 960;
    constexpr int mWindow_y = 540;

    sf::RenderWindow window(sf::VideoMode(mWindow_x, mWindow_y), "Minecraft", sf::Style::Close);

    Engine game(window);
    MainScreen mainMenu(window);
    //LoadScreen loadScreen(window);
    
    while(window.isOpen()) {
        if(mainMenu.isEnabled()) mainMenu.run();
        //else if(LoadScreen.isEnabled()) loadScreen.run();
    }

    return 0x0;
} 