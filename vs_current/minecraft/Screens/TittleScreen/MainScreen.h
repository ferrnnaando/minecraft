#pragma once
#include "../../header.h"
#include "../../Engine/Engine.h"

class MainScreen : public Engine {
    public:
        MainScreen(sf::RenderWindow& window, gameState& currentState);
        ~MainScreen() {};

        bool isMainScreen = true;
        void run() override;
        
    private:
        void init() override;
        virtual void windowEvents();
        virtual void userEvents();
        virtual void update();
        virtual void render();
    
        sf::RenderWindow* mWindow;
        gameState* currentStatus;
        
        std::string singleplayer_button_text_en = "Singleplayer";
        std::string multiplayer_button_text_en = "Multiplayer";
        std::string options_button_text_en = "Options...";
        std::string quit_button_text_en = "Quit game";

        sf::Texture t_background_main, t_copyright_editon, t_atlas;
        sf::Sprite s_background_main, s_button_singleplayer, s_button_multiplayer, s_button_settings, s_button_quit;
        sf::Text txt_version_info, txt_copyright_info, txt_content_singleplayer, txt_content_multiplayer, txt_content_settings, txt_content_quit, txt_random_message;

        bool isMessage_increasing = true;
        float randomMessage_speedScale = 0.005f;
  
};