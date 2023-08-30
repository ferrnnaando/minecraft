#pragma once
#include "../header.h"
#include "../BaseResource/BaseResource.h"

class Engine  {
    public:
        Engine(sf::RenderWindow&);
        void run();
    private:
        sf::RenderWindow* mWindow;
        
         bool mainScreen = true, settingsScreen = false, loading_overworldScreen = false, singleplayerGameScreen = false;
        bool lang_en = true, lang_es = false;

        std::string singleplayer_button_text_en = "Singleplayer";
        std::string multiplayer_button_text_en = "Multiplayer";
        std::string options_button_text_en = "Options...";
        std::string quit_button_text_en = "Quit game";
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

        sf::Texture t_background_main, t_maintittle, t_copyright_editon, t_button, t_language_button, t_atlas;
        sf::Sprite s_background_main, s_maintittle, s_copyright_edition, s_button_singleplayer, s_button_multiplayer, s_button_settings, s_button_quit, s_button_language, s_language_image;
        sf::Text txt_version_info, txt_copyright_info, txt_content_singleplayer, txt_content_multiplayer, txt_content_settings, txt_content_quit, txt_random_message;
        bool isMessage_increasing = true;
        float randomMessage_speedScale = 0.005f;

        // !settings screen

        sf::Texture t_background_settings;
        sf::Sprite s_background_settings;

        sf::Texture t_background_singleplayer_loading;
        sf::Sprite s_background_singleplayer_loading;
        sf::RectangleShape loadoverworld_total, loadoverwold_process;
        sf::Clock load_clock, enter_game;
        float totalLoadTime = 0.5f;
        float currentTime = 0.0f;
        sf::Text txt_load_status;
        std::string load_process_info;


        //game render
        float terrainHeight;
        sf::RectangleShape terrain_size;
        sf::Texture t_background_game_view;
        sf::Sprite s_stone_block, s_dirt_block, s_singleplayer_background_viewscreen;

        std::string random_message();
        void init();
        void processWindowEvents();
        void update();
        void render();
};