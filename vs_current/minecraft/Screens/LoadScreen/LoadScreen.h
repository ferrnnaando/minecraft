#pragma once
#include "../../header.h"
#include "../../Engine/Engine.h"
#include "../TittleScreen/MainScreen.h"

class LoadScreen : public Engine {
    public:
        LoadScreen(sf::RenderWindow& window, gameState& currentState, LoadState& loadStatus);
        ~LoadScreen() {};

        void run() override;

    private:
        void init() override;
        void windowEvents(); //override;
        void update(); //override;
        void render(); //override;

        sf::RenderWindow* mWindow;
        gameState* currentStatus;
        LoadState* canLoad;

        sf::Texture t_background_singleplayer_loading;
        sf::Sprite s_background_singleplayer_loading;

        sf::RectangleShape loadoverworld_total, loadoverwold_process;

        sf::Clock load_clock, enter_game;

        float totalLoadTime = 13.5f;
        float currentTime = 0.0f;
        sf::Text txt_load_status;
        std::string load_process_info;
};

/*
    view.setCenter(mWindow->getSize().x / 2, mWindow->getSize().y / 2);
    view.setSize(540, 400);

    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<float> distribution(200.0f, 270.0f);
    terrainHeight = distribution(rng);

    terrain_size.setSize(sf::Vector2f(mWindow->getSize().x, terrainHeight));
    terrain_size.setFillColor(sf::Color::White);
    terrain_size.setPosition(sf::Vector2f(mWindow->getSize().x - mWindow->getSize().x, mWindow->getSize().y - terrain_size.getGlobalBounds().height - 16.0f));

    t_atlas.setRepeated(true); //what does this
    sf::IntRect grassRect(0, 0, 16, 16);
    s_grass_block.setTexture(t_atlas);
    s_grass_block.setTextureRect(grassRect);

    sf::IntRect dirtRect(16, 0, 16, 16);
    s_dirt_block.setTexture(t_atlas);
    s_dirt_block.setTextureRect(dirtRect);

    sf::IntRect stoneRect(48, 0, 16, 16);
    s_stone_block.setTexture(t_atlas);
    s_stone_block.setTextureRect(stoneRect);

    sf::IntRect bedrockRect(64, 0, 16, 16);
    s_bedrock_block.setTexture(t_atlas);
    s_bedrock_block.setTextureRect(bedrockRect);
    
    s_singleplayer_background_viewscreen.setTexture(t_background_game_view);
    s_singleplayer_background_viewscreen.setScale(sf::Vector2f(static_cast<float>(mWindow->getSize().x) / t_background_game_view.getSize().x, static_cast<float>(mWindow->getSize().y) / t_background_game_view.getSize().y));
    s_singleplayer_background_viewscreen.setPosition(sf::Vector2f(s_singleplayer_background_viewscreen.getPosition().x, -180.0f));

    gridSizeX = mWindow->getSize().x / 16;
    gridSizeY = mWindow->getSize().y / 16;
    */