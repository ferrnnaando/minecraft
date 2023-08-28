#pragma once
#include "../header.h"

class Engine {
    public:
        Engine(sf::RenderWindow&);
        void run();

    private:
        sf::RenderWindow* mWindow;

        bool mainScreen = true, settingsScreen = false, gameScreen = false;
        //init global
        sf::Image ico_app;
        sf::Music m_C418;

        sf::SoundBuffer sb_click;
        sf::Sound s_click;

        sf::Cursor c_hand, c_default;
        sf::Font f_regular, f_title1;

        sf::Color buttons_hoverColor;
        //end global

        //!main screen
        sf::Texture t_background_main, t_maintittle, t_copyright_editon, t_button;
        sf::Sprite s_background_main, s_maintittle, s_copyright_edition, s_button_singleplayer, s_button_settings;
        sf::Text txt_version_info, txt_copyright_info, txt_content_singleplayer, txt_content_settings, txt_random_message;
        bool isMessage_increasing = true;
        float randomMessage_speedScale = 0.005f;

        // !settings screen

        sf::Texture t_background_settings;
        sf::Sprite s_background_settings;

        sf::Texture t_background_singleplayer_loading;
        sf::Sprite s_background_singleplayer_loading;

        sf::RectangleShape loadoverworld_total, loadoverwold_process;
        float totalLoadTime = 5.0f;
        float currentTime = 0.0f;
        sf::Clock load_clock;

        std::string random_message();
        void init();
        void processWindowEvents();
        void update();
        void render();
};