#pragma once
#include "../header.h"

class Engine {
    public:
        Engine(sf::RenderWindow& window);
        ~Engine() {};

    protected:
        sf::RenderWindow* mWindow;

        virtual void run() {};
        virtual void init();

        int gridSizeX;
        int gridSizeY;

        sf::Vector2i mousePos_absolute;
        sf::Vector2f mousePos_relative;

        std::string game_version = "Minecraft 1.20.1";
        std::string game_disclaimer = "Not Mojang AB. Can distribute!";

        sf::Image ico_app;
        sf::Music m_C418;
        sf::SoundBuffer sb_click;
        sf::Sound s_click;
        sf::Cursor c_hand, c_default;
        sf::Font f_regular, f_title1;
        sf::Texture t_button;
        sf::Color buttons_hoverColor;

        sf::Texture t_maintittle, t_copyright_editon;
        sf::Sprite s_maintittle, s_copyright_edition;
};