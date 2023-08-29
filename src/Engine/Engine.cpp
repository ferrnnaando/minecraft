#include "Engine.h"


std::string Engine::random_message() {
    int random = rand() % 21;
    std::string message;

    if(random == 0) {
        message = "Craft, Explore, Survive!";
    } else if(random == 1) {
        message = "Unleash Your Creativity!";
    } else if(random == 2) {
        message = "New Adventures Await!";
    } else if(random == 3) {
        message = "Block-Building Fun Awaits!";
    } else if(random == 4) {
        message = "Discover Endless Worlds!";
    } else if(random == 5) {
        message = "Mine, Craft, Repeat!";
    } else if(random == 6) {
        message = "Forge Your Own Path!";
    } else if(random == 7) {
        message = "Build Your Dream World!";
    } else if(random == 8) {
        message = "Enter the Pixelated Realm!";
    } else if(random == 9) {
        message ="Embark on Epic Quests!";
    } else if(random == 10) {
        message = "Crafting Awaits Your Command!";
    } else if(random == 11) {
        message = "Adventure Awaits, Miner!";
    } else if(random == 12) {
        message = "Crafting and Building Galore!";
    } else if(random == 13) {
        message = "Dive into Blocky Wonders!";
    } else if(random == 14) {
        message = "Survive and Thrive in Minecraft!";
    } else if(random == 15) {
        message = "Un-Limitless Possibilities!";
    } else if(random == 16) {
        message = "Build Your Imagination!";
    } else if(random == 17) {
        message = "Construct Your Fantasy World!";
    } else if(random == 18) {
        message = "Explore, Create, Conquer!";
    } else if(random == 19) {
        message = "Brave the Blocks and Build!";
    } else if(random == 20) {
        message = "Begin Your Minecraft Journey!";
    } else {
        message = "Snapshot, Smile!";
    }

    return message;
}


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

    s_background_main.setTexture(t_background_main);
    s_background_main.setScale(sf::Vector2f(static_cast<float>(mWindow->getSize().x) / t_background_main.getSize().x, static_cast<float>(mWindow->getSize().y) / t_background_main.getSize().y));
    
    buttons_hoverColor = sf::Color(116, 164, 214);
    
    txt_version_info.setFont(f_regular);
    txt_version_info.setCharacterSize(15);
    txt_version_info.setFillColor(sf::Color(255, 255, 255));
    txt_version_info.setString("Minecraft 1.20.1");
    txt_version_info.setPosition(sf::Vector2f(8, mWindow->getSize().y - txt_version_info.getCharacterSize() - 5));

    txt_copyright_info.setFont(f_regular);
    txt_copyright_info.setCharacterSize(15);
    txt_copyright_info.setFillColor(sf::Color::White);
    txt_copyright_info.setString("Not Mojang AB. Can distribute!");
    txt_copyright_info.setPosition(sf::Vector2f(mWindow->getSize().x- txt_copyright_info.getGlobalBounds().width - 8, mWindow->getSize().y - txt_version_info.getCharacterSize() - 5));

    s_maintittle.setTexture(t_maintittle);
    s_maintittle.setScale(sf::Vector2f(0.3f, 0.3f));
    s_maintittle.setPosition(sf::Vector2f((mWindow->getSize().x / 2) - (s_maintittle.getGlobalBounds().width / 2), 60.0f));   

    s_copyright_edition.setTexture(t_copyright_editon);
    s_copyright_edition.setScale(sf::Vector2f(1.0f, 1.0f));
    s_copyright_edition.setPosition(sf::Vector2f(s_maintittle.getPosition().x + s_maintittle.getGlobalBounds().width / 2 - s_copyright_edition.getGlobalBounds().width / 2,
    s_maintittle.getPosition().x + s_maintittle.getGlobalBounds().height / 2 - s_copyright_edition.getGlobalBounds().width / 2.4));

    txt_random_message.setFont(f_regular);
    txt_random_message.setCharacterSize(20);
    txt_random_message.setFillColor(sf::Color(213, 222, 82));
    txt_random_message.setString(random_message());
    txt_random_message.setPosition(sf::Vector2f(s_maintittle.getGlobalBounds().width + 20.0f, s_maintittle.getGlobalBounds().height + 50.0f));
    txt_random_message.setOutlineThickness(1);
    txt_random_message.setOutlineColor(sf::Color::Black);
    txt_random_message.rotate(-20);

    s_button_singleplayer.setTexture(t_button);
    s_button_singleplayer.setScale(sf::Vector2f(1.2f, 0.85f));
    s_button_singleplayer.setPosition(sf::Vector2f(s_maintittle.getPosition().x + s_maintittle.getGlobalBounds().width / 2 - s_button_singleplayer.getGlobalBounds().width / 2, s_maintittle.getPosition().y + s_maintittle.getGlobalBounds().height + txt_copyright_info.getGlobalBounds().height + 45.0f));

    s_button_multiplayer.setTexture(t_button);
    s_button_multiplayer.setScale(sf::Vector2f(1.2f, 0.85f));
    s_button_multiplayer.setPosition(sf::Vector2f(s_maintittle.getPosition().x + s_maintittle.getGlobalBounds().width / 2 - s_button_singleplayer.getGlobalBounds().width / 2, s_button_singleplayer.getPosition().y + s_button_singleplayer.getGlobalBounds().height + 6.0f));

    s_button_settings.setTexture(t_button);
    s_button_settings.setScale(sf::Vector2f(0.595f, 0.85f));
    s_button_settings.setPosition(sf::Vector2f(s_maintittle.getPosition().x + s_maintittle.getGlobalBounds().width / 2 - s_button_multiplayer.getGlobalBounds().width / 2, s_button_multiplayer.getPosition().y + s_button_multiplayer.getGlobalBounds().height + 27.0f));

    s_button_quit.setTexture(t_button);
    s_button_quit.setScale(sf::Vector2f(0.595f, 0.85f));
    s_button_quit.setPosition(sf::Vector2f(s_button_settings.getPosition().x + s_button_settings.getGlobalBounds().width + 8.0f, s_button_multiplayer.getPosition().y + s_button_multiplayer.getGlobalBounds().height + 27.0f));

    s_button_language.setTexture(t_button);
    s_button_language.setScale(sf::Vector2f(0.15f, 0.85f));
    s_button_language.setPosition(sf::Vector2f(s_button_settings.getPosition().x - s_button_language.getGlobalBounds().width - 8.0f, s_button_multiplayer.getPosition().y + s_button_multiplayer.getGlobalBounds().height + 27.0f));

    s_language_image.setTexture(t_language_button);
    s_language_image.setScale(sf::Vector2f(0.05f, 0.05f));
    s_language_image.setPosition(sf::Vector2f(s_button_language.getPosition().x + s_button_language.getGlobalBounds().width - 33.0f, s_button_language.getPosition().x + s_button_language.getGlobalBounds().height + 5.0f));

    txt_content_singleplayer.setFont(f_regular);
    txt_content_singleplayer.setCharacterSize(18);
    txt_content_singleplayer.setFillColor(sf::Color::White);
    txt_content_singleplayer.setString(singleplayer_button_text_en);
    txt_content_singleplayer.setPosition(sf::Vector2f(s_button_singleplayer.getPosition().x + s_button_singleplayer.getGlobalBounds().width / 2 - txt_content_singleplayer.getGlobalBounds().width / 2,  s_button_singleplayer.getPosition().y + s_button_singleplayer.getGlobalBounds().height / 2 - txt_content_singleplayer.getGlobalBounds().height));
    txt_content_singleplayer.setOutlineThickness(1);
    txt_content_singleplayer.setOutlineColor(sf::Color(0, 0, 0));

    txt_content_multiplayer.setFont(f_regular);
    txt_content_multiplayer.setCharacterSize(15);
    txt_content_multiplayer.setFillColor(sf::Color::White);
    txt_content_multiplayer.setString(multiplayer_button_text_en);
    txt_content_multiplayer.setPosition(sf::Vector2f(s_button_multiplayer.getPosition().x + s_button_multiplayer.getGlobalBounds().width / 2 - txt_content_multiplayer.getGlobalBounds().width / 2,  s_button_multiplayer.getPosition().y + s_button_multiplayer.getGlobalBounds().height / 2 - txt_content_multiplayer.getGlobalBounds().height));
    txt_content_multiplayer.setOutlineThickness(1);
    txt_content_multiplayer.setOutlineColor(sf::Color(0, 0, 0));

    txt_content_settings.setFont(f_regular);
    txt_content_settings.setCharacterSize(15);
    txt_content_settings.setFillColor(sf::Color::White);
    txt_content_settings.setString(options_button_text_en);
    txt_content_settings.setPosition(sf::Vector2f(s_button_settings.getPosition().x + s_button_settings.getGlobalBounds().width / 2 - txt_content_settings.getGlobalBounds().width / 2,  s_button_settings.getPosition().y + s_button_settings.getGlobalBounds().height / 2 - txt_content_settings.getGlobalBounds().height));
    txt_content_settings.setOutlineThickness(1);
    txt_content_settings.setOutlineColor(sf::Color(0, 0, 0));

    txt_content_quit.setFont(f_regular);
    txt_content_quit.setCharacterSize(15);
    txt_content_quit.setFillColor(sf::Color::White);
    txt_content_quit.setString(quit_button_text_en);
    txt_content_quit.setPosition(sf::Vector2f(s_button_quit.getPosition().x + s_button_quit.getGlobalBounds().width / 2 - txt_content_quit.getGlobalBounds().width / 2,  s_button_quit.getPosition().y + s_button_quit.getGlobalBounds().height / 2 - txt_content_quit.getGlobalBounds().height));
    txt_content_quit.setOutlineThickness(1);
    txt_content_quit.setOutlineColor(sf::Color(0, 0, 0));

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
}

void Engine::init() {
    std::vector<sf::Image*> ToLoad_Images = { &ico_app};
    std::vector<std::string> ImagesPath = { "assets/images/icon_app.jpeg" };

    std::vector<sf::Texture*> ToLoad_Textures = { &t_button, &t_background_main, &t_background_singleplayer_loading, &t_background_settings, &t_maintittle, &t_copyright_editon, &t_button };
    std::vector<std::string> TexturesPath = { "assets/images/icon_app.jpeg", "assets/images/background.jpeg", "assets/images/loading_singleplayer.png", 
    "assets/images/settings_screen.png", "assets/images/title.png", "assets/images/edition_copyright.png", "assets/images/button.jpg" };

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
        threads.emplace_back([&ToLoad_Images, &ImagesPath, i]() {
            ToLoad_Images[i]->loadFromFile(ImagesPath[i]); //t2
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

    //this simple example are loading all in the same thread  one by-one, not multi-threading

    for(auto& thread : threads) {
        thread.join();
    }

}

/*void Engine::init() {
    //std::map<std::string, load_struct> important_stuff;
    std::vector<LoadStruct> initPath = {
        { "assets/images/icon_app.jpeg", std::make_shared<TextureLoad>() }};
        // { "assets/sounds/C418.mp3", sf::Image() }, 
        // { "assets/sounds/effects/click.mp3", sf::Image() }, 
        // { sf::Cursor::Hand, sf::Image() }, 
        // { sf::Cursor::Arrow, sf::Image() }, 
        // { "assets/images/background.jpeg", sf::Image() }

    for(int i = 0; i < initPath.size(); i++) {
        try {
            initPath[i].var_name.loadFromFile(initPath[i].path);
        } 
        catch(std::exception& e) {
            std::cout << e.what();
            throw std::runtime_error("Textures wasnt correctly installed/loaded, appears to be corrupt. Please take the time to reinstall the game.");
        }
    }

    // //if(!music_1.openFromFile("assets/sounds/C418.mp3")) mWindow->close();
    // if(!sb_click.loadFromFile("assets/sounds/effects/click.mp3")) mWindow->close();
    // if(!c_hand.loadFromSystem(sf::Cursor::Hand)) mWindow->close();
    // if(!c_default.loadFromSystem(sf::Cursor::Arrow)) mWindow->close();
    // if(!t_background_main.loadFromFile("assets/images/background.jpeg")) mWindow->close();
    // if(!t_maintittle.loadFromFile("assets/images/title.png")) mWindow->close();
    // if(!t_copyright_editon.loadFromFile("assets/images/edition_copyright.png")) mWindow->close();
    // if(!t_button.loadFromFile("assets/images/button.jpg")) mWindow->close();
    // if(!t_language_button.loadFromFile("assets/images/language.png")) mWindow->close();
    // if(!f_regular.loadFromFile("assets/fonts/regular.otf")) mWindow->close(); 
    // if(!f_title1.loadFromFile("assets/fonts/title1.ttf")) mWindow->close();
    // if(!t_background_singleplayer_loading.loadFromFile("assets/images/loading_singleplayer.png")) mWindow->close();
    // if(!t_background_settings.loadFromFile("assets/images/settings_screen.png")) mWindow->close();
}*/

void Engine::processWindowEvents() {
    sf::Event event;

    while(mWindow->pollEvent(event)) {
        switch(event.type) {
            case sf::Event::Closed:
                mWindow->close();
                break;
            default:
                break;
        }
    }
}
void Engine::update() {
    sf::Vector2i mousePos_absolute = sf::Mouse::getPosition(*mWindow);
    sf::Vector2f mousePos_relative = mWindow->mapPixelToCoords(mousePos_absolute);

        if(isMessage_increasing) {
            txt_random_message.scale(1 + randomMessage_speedScale * 0.3f, 1 + randomMessage_speedScale * 0.3f);
        } else {
            txt_random_message.scale(1 - randomMessage_speedScale * 0.3f, 1 - randomMessage_speedScale * 0.3f);
        }

        if(txt_random_message.getScale().x > 1.25f || txt_random_message.getScale().x < 1.0f) {
            isMessage_increasing = !isMessage_increasing;
        }

        if(mWindow->hasFocus()) {
            if(mainScreen) {
                if (s_button_singleplayer.getGlobalBounds().contains(mousePos_relative)) {
                    mWindow->setMouseCursor(c_hand);
                    s_button_singleplayer.setColor(buttons_hoverColor);
                    txt_content_singleplayer.setFillColor(sf::Color(254, 255, 169));
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                        if(s_click.getStatus() != sf::SoundSource::Playing) {
                            load_clock.restart();
                            enter_game.restart();
                            s_click.play();
                            mainScreen = false;
                            loadgameScreen = true;
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
            else if(loadgameScreen) {
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
                        loadoverwold_process.setSize(sf::Vector2f(0.0f, 13.0f));
                        loadgameScreen = false;
                        gameScreen = true;      
                    }
                }
            } else if(gameScreen) {
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                    loadoverwold_process.setSize(sf::Vector2f(0.0f, 13.0f));
                    gameScreen = false;
                    mainScreen = true;
                }
            }
        }
    return;
}

void Engine::render() {
    mWindow->clear();
    if(mainScreen) {
        mWindow->draw(s_background_main);

        mWindow->draw(txt_version_info);
        mWindow->draw(txt_copyright_info);

        mWindow->draw(s_maintittle); //main title
        mWindow->draw(s_copyright_edition); //title copyright
        mWindow->draw(txt_random_message);

        mWindow->draw(s_button_singleplayer); //menu button for singleplayer
        mWindow->draw(txt_content_singleplayer); //singleplayer button 
        mWindow->draw(s_button_multiplayer);
        mWindow->draw(txt_content_multiplayer);
        mWindow->draw(s_button_settings);
        mWindow->draw(txt_content_settings);
        mWindow->draw(s_button_quit);
        mWindow->draw(txt_content_quit);
        mWindow->draw(s_button_language);
        mWindow->draw(s_language_image);

    } else if(settingsScreen) {
        mWindow->draw(s_background_settings);

        
    } else if(loadgameScreen) {
        mWindow->draw(s_background_singleplayer_loading);

        mWindow->draw(s_maintittle); //main title
        mWindow->draw(s_copyright_edition); //title copyright
        mWindow->draw(txt_load_status);
        mWindow->draw(loadoverworld_total);
        mWindow->draw(loadoverwold_process);
    }
    else if(gameScreen) {
        mWindow->clear(sf::Color::Green);
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
}