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

/*class Engine  {
    public:
        Engine(sf::RenderWindow&);
        void run();
    private:
        sf::RenderWindow* mWindow;
        showWindow(main);
        
        
        bool mainScreen = true, settingsScreen = false, loading_overworldScreen = false, singleplayerGameScreen = false;
      
        //!main screen

        

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
        sf::View view;

     
        float terrainHeight;
        sf::RectangleShape terrain_size;
        sf::Texture t_background_game_view;
        sf::Sprite s_grass_block, s_dirt_block, s_stone_block, s_bedrock_block, s_singleplayer_background_viewscreen;

};  */