#include "../../header.h"
#include "../../Engine/Engine.h"
#include "../TittleScreen/MainScreen.h"

class LoadScreen : public Engine, public MainScreen {
    public:
        LoadScreen(sf::RenderWindow& window, gameState& currentState);
        ~LoadScreen() {};

        bool isLoadScreen = false;
        void run() override;

    private:
        sf::RenderWindow* mWindow;
        gameState* currentStatus;

        void init() override;
        void windowEvents() override;
        void userEvents() override;
        void update() override;
        void render() override;

};

/*

    loadoverworld_total.setSize(sf::Vector2f(500.0f, 15.0f));
    loadoverworld_total.setFillColor(sf::Color(161, 161, 161));
    loadoverworld_total.setPosition(sf::Vector2f(mWindow->getSize().x / 2 - loadoverworld_total.getGlobalBounds().width / 2, mWindow->getSize().y / 2));
    
    loadoverwold_process.setSize(sf::Vector2f(0.0f, 13.0f));
    loadoverwold_process.setFillColor(sf::Color(0, 222, 15));
    loadoverwold_process.setPosition(loadoverworld_total.getPosition().x + 1.0f, loadoverworld_total.getPosition().y + 1.0f);


    s_background_settings.setTexture(t_background_settings);
    s_background_settings.setScale(sf::Vector2f(static_cast<float>(mWindow->getSize().x) / t_background_settings.getSize().x, static_cast<float>(mWindow->getSize().y) / t_background_settings.getSize().y));





    s_background_singleplayer_loading.setTexture(t_background_singleplayer_loading);
    s_background_singleplayer_loading.setScale(sf::Vector2f(static_cast<float>(mWindow->getSize().x) / t_background_singleplayer_loading.getSize().x, static_cast<float>(mWindow->getSize().y) / t_background_singleplayer_loading.getSize().y));

    load_process_info = "...";
    txt_load_status.setFont(f_regular);
    txt_load_status.setCharacterSize(18);
    txt_load_status.setFillColor(sf::Color::White);
    txt_load_status.setString(load_process_info);
    txt_load_status.setPosition(sf::Vector2f(loadoverworld_total.getSize().x / 2 - txt_load_status.getGlobalBounds().width / 2, loadoverworld_total.getGlobalBounds().getPosition().y - 25.0f));
    txt_load_status.setOutlineThickness(1);
    txt_load_status.setOutlineColor(sf::Color(0, 0, 0));




    //game 
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