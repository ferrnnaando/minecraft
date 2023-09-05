#include "Engine.h"

Engine::Engine(sf::RenderWindow& window) {
    mWindow = &window;
    mWindow->requestFocus();
    mWindow->setActive(true);
    mWindow->setVisible(true);
    mWindow->setFramerateLimit(60);
    mWindow->setVerticalSyncEnabled(true);

    init();

    mWindow->setIcon(ico_app.getSize().x, ico_app.getSize().y, ico_app.getPixelsPtr());
    s_click.setBuffer(sb_click);
    buttons_hoverColor = sf::Color(116, 164, 214);
    
    s_maintittle.setTexture(t_maintittle);
    s_maintittle.setScale(sf::Vector2f(0.3f, 0.3f));
    s_maintittle.setPosition(sf::Vector2f((mWindow->getSize().x / 2) - (s_maintittle.getGlobalBounds().width / 2), 60.0f));   

    s_copyright_edition.setTexture(t_copyright_editon);
    s_copyright_edition.setScale(sf::Vector2f(1.0f, 1.0f));
    s_copyright_edition.setPosition(sf::Vector2f(s_maintittle.getPosition().x + s_maintittle.getGlobalBounds().width / 2 - s_copyright_edition.getGlobalBounds().width / 2, s_maintittle.getPosition().x + s_maintittle.getGlobalBounds().height / 2 - s_copyright_edition.getGlobalBounds().width / 2.4));
}

void Engine::init() {
    if(!ico_app.loadFromFile("assets/images/icon_app.jpeg")) mWindow->close(); //radical quit
    if(!sb_click.loadFromFile("assets/sounds/effects/click.mp3")) mWindow->close();
    if(!c_hand.loadFromSystem(sf::Cursor::Hand)) mWindow->close();
    if(!c_default.loadFromSystem(sf::Cursor::Arrow)) mWindow->close();
    if(!t_button.loadFromFile("assets/images/button.jpg")) mWindow->close();
    if(!f_regular.loadFromFile("assets/fonts/regular.otf")) mWindow->close(); 
    if(!f_title1.loadFromFile("assets/fonts/title1.ttf")) mWindow->close();
    if(!t_maintittle.loadFromFile("assets/images/title.png")) mWindow->close();
    if(!t_copyright_editon.loadFromFile("assets/images/edition_copyright.png")) mWindow->close();
}

/*Engine::Engine(sf::RenderWindow& window) { 

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

}

void Engine::init() {
    std::vector<sf::Image*> ToLoad_Images = { &ico_app};
    std::vector<std::string> ImagesPath = { "assets/images/icon_app.jpeg" };

    std::vector<sf::Texture*> ToLoad_Textures = { &t_button, &t_background_main, &t_background_singleplayer_loading, &t_background_settings, &t_maintittle, 
                                                                                &t_copyright_editon, &t_button, &t_atlas , &t_background_game_view};
std::vector<std::string> TexturesPath = { "assets/images/icon_app.jpeg", "assets/images/background.jpeg", "assets/images/loading_singleplayer.png", 
    "assets/images/settings_screen.png", "assets/images/title.png", "assets/images/edition_copyright.png", "assets/images/button.jpg" , "assets/images/texture_atlas.png", 
                                                        "assets/images/singleplayer_background.png"};

    std::vector<sf::Font*> ToLoad_Fonts = { &f_regular, &f_title1 };
    std::vector<std::string> FontsPath = { "assets/fonts/regular.otf", "assets/fonts/title1.ttf" };

    std::vector<sf::Cursor*> ToLoad_Cursor = { &c_default, &c_hand };
    std::vector<sf::Cursor::Type> CursorPath = { sf::Cursor::Arrow, sf::Cursor::Hand };

    std::vector<sf::SoundBuffer*> ToLoad_Buffer = { &sb_click };
    std::vector<std::string> BufferPath = { "assets/sounds/effects/click.mp3"};

    std::vector<sf::Music*> ToLoad_Music = { &m_C418 };
    std::vector<std::string> MusicPath = { "assets/sounds/musics/main_music.mp3" };

    std::vector<std::thread> threads; //what does emplace back
    std::mutex shared; //what is mutex

    for(int i = 0; i < ToLoad_Images.size(); i++) {
        threads.emplace_back([&ToLoad_Images, &ImagesPath, &shared, i]() {
             {
                std::lock_guard<std::mutex> lock(shared);
                ToLoad_Images[i]->loadFromFile(ImagesPath[i]);
            }
        });
    }

    for(int i = 0; i < ToLoad_Textures.size(); i++) {
        threads.emplace_back([&ToLoad_Textures, &TexturesPath, &shared, i]() {
            {
                std::lock_guard<std::mutex> lock(shared);
                ToLoad_Textures[i]->loadFromFile(TexturesPath[i]);
            }
        });
    }

    for(int i = 0; i < ToLoad_Fonts.size(); i++) {
        threads.emplace_back([&ToLoad_Fonts, &FontsPath, &shared, i](){
            {
                std::lock_guard<std::mutex> lock(shared);
                ToLoad_Fonts[i]->loadFromFile(FontsPath[i]); //t3
            }
        });
    }

    for(int i = 0; i < ToLoad_Cursor.size(); i++) {
        threads.emplace_back([&ToLoad_Cursor, &CursorPath, &shared, i](){
            {
                std::lock_guard<std::mutex> lock(shared);
                ToLoad_Cursor[i]->loadFromSystem(CursorPath[i]);
            }
        });
    }

    for(int i = 0; i < ToLoad_Buffer.size(); i++) {
        threads.emplace_back([&ToLoad_Buffer, &BufferPath, &shared, i](){
            {
                std::lock_guard<std::mutex> lock(shared);
                ToLoad_Buffer[i]->loadFromFile(BufferPath[i]);
            }
        });
    }
    
    for(int i = 0; i < ToLoad_Music.size(); i++) {
        threads.emplace_back([&ToLoad_Music, &MusicPath, &shared, i]() {
            {
                std::lock_guard<std::mutex> lock(shared);
                ToLoad_Music[i]->openFromFile(MusicPath[i]);
            }
        });
    }

    for(auto& thread : threads) {
        thread.join();
    }
}

void Engine::update() {
    gridSizeX = mWindow->getSize().x / 16;
    gridSizeY = mWindow->getSize().y / 16;

    sf::Vector2i mousePos_absolute = sf::Mouse::getPosition(*mWindow);
    sf::Vector2f mousePos_relative = mWindow->mapPixelToCoords(mousePos_absolute);


        if(mWindow->hasFocus()) {
            if(mainScreen) {
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    
                }
                else if (s_button_singleplayer.getGlobalBounds().contains(mousePos_relative)) {
                    mWindow->setMouseCursor(c_hand);
                    s_button_singleplayer.setColor(buttons_hoverColor);
                    txt_content_singleplayer.setFillColor(sf::Color(254, 255, 169));
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                        if(s_click.getStatus() != sf::SoundSource::Playing) {
                            load_clock.restart();
                            enter_game.restart();
                            s_click.play();
                            mainScreen = false;
                            loading_overworldScreen = true;
                        }
                    }
                } else if (s_button_settings.getGlobalBounds().contains(mousePos_relative)) {
                    mWindow->setMouseCursor(c_hand);
                    s_button_settings.setColor(buttons_hoverColor);
                    txt_content_settings.setFillColor(sf::Color(254, 255, 169));
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                        if(s_click.getStatus() != sf::SoundSource::Playing) {
                            s_click.play();
                            mainScreen = false;
                            settingsScreen = true;
                        }
                    }
                } else if(s_button_quit.getGlobalBounds().contains(mousePos_relative)) {
                    mWindow->setMouseCursor(c_hand);
                    s_button_quit.setColor(buttons_hoverColor);
                    txt_content_quit.setFillColor(sf::Color(254, 255, 169));
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                         if(s_click.getStatus() != sf::SoundSource::Playing) {
                            s_click.play();
                            mWindow->close();
                        }
                    }
                } 
                else {
                    s_button_singleplayer.setColor(sf::Color(255, 255, 255));
                    txt_content_singleplayer.setFillColor(sf::Color::White);
                    s_button_settings.setColor(sf::Color(255, 255, 255));
                    txt_content_settings.setFillColor(sf::Color::White);
                    s_button_quit.setColor(sf::Color::White);
                    txt_content_quit.setFillColor(sf::Color::White);
                    mWindow->setMouseCursor(c_default);
                }
            } 
            else if(settingsScreen) {
                mWindow->setMouseCursor(c_default);
            } 
            else if(loading_overworldScreen) {
                mWindow->setMouseCursor(c_default);

                sf::Time elapsedTime = load_clock.restart();
                currentTime += elapsedTime.asSeconds();
                float progress = currentTime / totalLoadTime;

                progress = std::min(progress, 1.0f);

                float newWidth = loadoverworld_total.getSize().x * progress;
                loadoverwold_process.setSize(sf::Vector2f(newWidth, loadoverwold_process.getSize().y));

                if(loadoverwold_process.getSize().x <= 50.0f) {
                    load_process_info = "Generating Terrain...";
                    txt_load_status.setString(load_process_info);
                } 
                else if (loadoverwold_process.getSize().x <= 300.0f) {
                    load_process_info = "Preparing Level...";
                    txt_load_status.setString(load_process_info);
                }
                else if (loadoverwold_process.getSize().x <= 420.0f) {
                    load_process_info = "Synthesizing World...";
                    txt_load_status.setString(load_process_info);
                } 
                else if(loadoverwold_process.getSize().x >= 500) {
                    load_process_info = "Loading Overworld";
                    txt_load_status.setString(load_process_info);
                    if(enter_game.getElapsedTime().asSeconds() >= 0.f) {
                        load_clock.restart();
                        loadoverwold_process.setSize(sf::Vector2f(0.0f, 13.0f));
                        loading_overworldScreen = false;
                        singleplayerGameScreen = true;      
                    }
                }
            } else if(singleplayerGameScreen) {

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                    load_clock.restart();
                    loadoverwold_process.setSize(sf::Vector2f(0.0f, 13.0f));
                    singleplayerGameScreen = false;
                    mainScreen = true;
                } else {
                    //We need to make this because if we just do getcenterx - 0 whe are checking for size in pixels, remember we are working with grids of 16x16
                    float leftMaxGrid = 0.5f * view.getSize().x;
                    float rightMaxGrid = gridSizeX - 0.5f * view.getSize().x;

                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && view.getCenter().x - leftMaxGrid > 0 ) {
                        view.move(sf::Vector2f(-2.0f, 0.0f));
                    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && view.getCenter().x + rightMaxGrid < mWindow->getSize().x) {
                        view.move(sf::Vector2f(2.0f, 0.0f));
                    }
                }
            }
        } 
        else {
            //std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    return;
}

void Engine::render() {

    } else if(settingsScreen) {
        mWindow->draw(s_background_settings);

        
    } else if(loading_overworldScreen) {
        mWindow->draw(s_background_singleplayer_loading);

        mWindow->draw(s_maintittle); //main title
        mWindow->draw(s_copyright_edition); //title copyright
        mWindow->draw(txt_load_status);
        mWindow->draw(loadoverworld_total);
        mWindow->draw(loadoverwold_process);
    } 
    else if (singleplayerGameScreen) {
        mWindow->setView(view);
        mWindow->clear(sf::Color::Green);
        mWindow->draw(s_singleplayer_background_viewscreen);
       // mWindow->draw(terrain_size);

        int generated_size = (mWindow->getSize().y - terrain_size.getSize().y) / 16; //grids for the generated rectangle shape

        for (int y = 0; y < gridSizeY; ++y) {
            for (int x = 0; x < gridSizeX; ++x) {
                float posX = x * 16.0f;
                float posY = y * 16.0f;

                if (y == gridSizeY - 1) {
                    s_bedrock_block.setPosition(posX, posY);
                    mWindow->draw(s_bedrock_block);
                } else if (y >= gridSizeY - generated_size) { //now we have 2 layouts restantz
                    s_stone_block.setPosition(posX, posY);
                    mWindow->draw(s_stone_block);
                }
            }
        }
    }
    mWindow->display();
}

void Engine::run() {   
    //music_1.play();
    while (mWindow->isOpen()) {
        processWindowEvents();
        update();
        render();
    } 
}*/