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

    s_background_settings.setTexture(t_background_settings);
    s_background_settings.setScale(sf::Vector2f(static_cast<float>(mWindow->getSize().x) / t_background_settings.getSize().x, static_cast<float>(mWindow->getSize().y) / t_background_settings.getSize().y));

    s_background_main.setTexture(t_background_main);
    s_background_main.setScale(sf::Vector2f(static_cast<float>(mWindow->getSize().x) / t_background_main.getSize().x, static_cast<float>(mWindow->getSize().y) / t_background_main.getSize().y));
    
    s_background_singleplayer_loading.setTexture(t_background_singleplayer_loading);
    s_background_singleplayer_loading.setScale(sf::Vector2f(static_cast<float>(mWindow->getSize().x) / t_background_singleplayer_loading.getSize().x, static_cast<float>(mWindow->getSize().y) / t_background_singleplayer_loading.getSize().y));
    
    buttons_hoverColor = sf::Color(100, 100, 255, 200);
    
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
    txt_random_message.setPosition(sf::Vector2f(s_maintittle.getGlobalBounds().width, s_maintittle.getGlobalBounds().height));
    txt_random_message.setOutlineThickness(1);
    txt_random_message.setOutlineColor(sf::Color::Black);
    txt_random_message.rotate(-20);

    if(mainScreen) {
        s_button_singleplayer.setTexture(t_button);
        s_button_singleplayer.setScale(sf::Vector2f(0.85f, 0.85f));
        s_button_singleplayer.setPosition(sf::Vector2f(s_maintittle.getPosition().x + s_maintittle.getGlobalBounds().width / 2 - s_button_singleplayer.getGlobalBounds().width / 2,
            s_maintittle.getPosition().y + s_maintittle.getGlobalBounds().height + txt_copyright_info.getGlobalBounds().height + 30.0f));

        s_button_settings.setTexture(t_button);
        s_button_settings.setScale(sf::Vector2f(0.425f, 0.85f));
        s_button_settings.setPosition(sf::Vector2f(s_maintittle.getPosition().x + s_maintittle.getGlobalBounds().width / 2 - s_button_settings.getGlobalBounds().width / 2,
                        s_button_singleplayer.getPosition().y + s_button_singleplayer.getGlobalBounds().height + 5.0f));

        s_button_quit.setTexture(t_button);
        s_button_quit.setScale(sf::Vector2f(0.425f, 0.85f));
        s_button_quit.setPosition(sf::Vector2f(s_maintittle.getPosition().x + s_maintittle.getGlobalBounds().width / 2 - s_button_settings.getGlobalBounds().width / 2,
                        s_button_singleplayer.getPosition().y + s_button_singleplayer.getGlobalBounds().height + 20.0f));

        txt_content_singleplayer.setFont(f_regular);
        txt_content_singleplayer.setCharacterSize(15);
        txt_content_singleplayer.setFillColor(sf::Color::White);
        txt_content_singleplayer.setString("Singleplayer");
        txt_content_singleplayer.setPosition(sf::Vector2f(s_button_singleplayer.getPosition().x + s_button_singleplayer.getGlobalBounds().width / 2 - txt_content_singleplayer.getGlobalBounds().width / 2, 
                                s_button_singleplayer.getPosition().y + s_button_singleplayer.getGlobalBounds().height / 2 - txt_content_singleplayer.getGlobalBounds().height));
        txt_content_singleplayer.setOutlineThickness(1);
        txt_content_singleplayer.setOutlineColor(sf::Color(0, 0, 0));

        txt_content_settings.setFont(f_regular);
        txt_content_settings.setCharacterSize(15);
        txt_content_settings.setFillColor(sf::Color::White);
        txt_content_settings.setString("Options...");
        txt_content_settings.setPosition(sf::Vector2f(s_button_settings.getPosition().x + s_button_settings.getGlobalBounds().width / 2 - txt_content_settings.getGlobalBounds().width / 2, 
                                s_button_settings.getPosition().y + s_button_settings.getGlobalBounds().height / 2 - txt_content_settings.getGlobalBounds().height));
        txt_content_settings.setOutlineThickness(1);
        txt_content_settings.setOutlineColor(sf::Color(0, 0, 0));
    }

    load_pending.setSize(sf::Vector2f(500.0f, 15.0f));
    load_pending.setFillColor(sf::Color(161, 161, 161));
    load_pending.setPosition(sf::Vector2f(mWindow->getPosition().x + (mWindow->getSize().x - load_pending.getSize().x) / 2,0.0f));

    mousePos = sf::Mouse::getPosition(*mWindow);
}

void Engine::init() {
    if(!ico_app.loadFromFile("assets/images/icon_app.jpeg")) mWindow->close();
    if(!music_1.openFromFile("assets/sounds/musics/main_music.mp3")) mWindow->close();
    if(!sb_click.loadFromFile("assets/sounds/effects/click.mp3")) mWindow->close();
    if(!c_hand.loadFromSystem(sf::Cursor::Hand)) mWindow->close();
    if(!c_default.loadFromSystem(sf::Cursor::Arrow)) mWindow->close();
    if(!t_background_settings.loadFromFile("assets/images/settings_screen.png")) mWindow->close();
    if(!t_background_main.loadFromFile("assets/images/background.jpeg")) mWindow->close();
    if(!t_maintittle.loadFromFile("assets/images/title.png")) mWindow->close();
    if(!t_copyright_editon.loadFromFile("assets/images/edition_copyright.png")) mWindow->close();
    if(!t_button.loadFromFile("assets/images/button.jpg")) mWindow->close();
    if(!f_regular.loadFromFile("assets/fonts/regular.otf")) mWindow->close(); 
    if(!t_background_singleplayer_loading.loadFromFile("assets/images/loading_singleplayer.png")) mWindow->close();
}


void Engine::processWindowEvents() {
    sf::Event event;

    while(mWindow->pollEvent(event)) {
        switch(event.type) {
            case sf::Event::Closed:
                break;
            default:
                break;
        }
    }
}


void Engine::update() {

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
            if (s_button_singleplayer.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                mWindow->setMouseCursor(c_hand);
                s_button_singleplayer.setColor(buttons_hoverColor);
                txt_content_singleplayer.setFillColor(sf::Color(254, 255, 169));
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    if(s_click.getStatus() != sf::SoundSource::Playing) {
                        s_click.play();
                        mainScreen = false;
                        gameScreen = true;
                    }
                }
            } 
            else if (s_button_settings.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
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
            } else if(s_button_quit.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                mWindow->setMouseCursor(c_hand);
                s_button_quit.setColor(buttons_hoverColor);
                //txt_content_quit.setFillColor(sf::Color(254, 255, 169));
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    mWindow->close();
                }
            }
            else {
                s_button_singleplayer.setColor(sf::Color(255, 255, 255, 200));
                txt_content_singleplayer.setFillColor(sf::Color::White);
                s_button_settings.setColor(sf::Color(255, 255, 255, 200));
                txt_content_settings.setFillColor(sf::Color::White);
                mWindow->setMouseCursor(c_default);
            }
        } 
        else if(settingsScreen) {
            mWindow->setMouseCursor(c_default);
        } 
        else if(gameScreen) {
            mWindow->setMouseCursor(c_default);
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

        mWindow->draw(s_button_settings);
        mWindow->draw(txt_content_settings);

    } else if(settingsScreen) {
        mWindow->draw(s_background_settings);

        mWindow->draw(txt_version_info);
        mWindow->draw(txt_copyright_info);
    } else if(gameScreen) {
        mWindow->draw(s_background_singleplayer_loading);

        mWindow->draw(s_maintittle); //main title
        mWindow->draw(s_copyright_edition); //title copyright
        mWindow->draw(load_pending);
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