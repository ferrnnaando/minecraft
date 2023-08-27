#pragma once
#include "../header.h"

class Engine {
    public:
        Engine(sf::RenderWindow&);
        void run();

    private:
        sf::RenderWindow* mWindow;
        sf::Image ico_app;
        sf::Music m_C418;

        sf::Texture t_background, t_maintittle, t_copyright_editon, t_button;
        sf::Sprite s_background, s_maintittle, s_copyright_edition, s_button_singleplayer;

        sf::Font f_regular, f_title1;
        sf::Text txt_version_info, txt_copyright_info, txt_content_singleplayer;

        void init();
        void processWindowEvents();
        void processUserEvents();
        void update();
        void render();
};