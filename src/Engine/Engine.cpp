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

    s_background_settings.setTexture(t_background_settings);

    s_background_main.setTexture(t_background_main);
    s_background_main.setScale(sf::Vector2f(static_cast<float>(mWindow->getSize().x) / t_background_main.getSize().x, static_cast<float>(mWindow->getSize().y) / t_background_main.getSize().y));
    
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

    s_button_singleplayer.setTexture(t_button);
    s_button_singleplayer.setScale(sf::Vector2f(0.85f, 0.85f));
    s_button_singleplayer.setPosition(sf::Vector2f(s_maintittle.getPosition().x + s_maintittle.getGlobalBounds().width / 2 - s_button_singleplayer.getGlobalBounds().width / 2,
                        s_maintittle.getPosition().x + s_maintittle.getGlobalBounds().height / 2 - s_button_singleplayer.getGlobalBounds().width / 3));

    s_button_settings.setTexture(t_button);
    s_button_settings.setScale(sf::Vector2f(0.85f, 0.85f));
    s_button_settings.setPosition(sf::Vector2f(s_maintittle.getPosition().x + s_maintittle.getGlobalBounds().width / 2 - s_button_settings.getGlobalBounds().width / 2,
                        s_maintittle.getPosition().x + s_maintittle.getGlobalBounds().height / 2 - s_button_settings.getGlobalBounds().width / 3 + (s_button_singleplayer.getGlobalBounds().height)*2 / 1.8));

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
    txt_content_settings.setString("Settings");
    txt_content_settings.setPosition(sf::Vector2f(s_button_settings.getPosition().x + s_button_settings.getGlobalBounds().width / 2 - txt_content_settings.getGlobalBounds().width / 2, 
                            s_button_settings.getPosition().y + s_button_settings.getGlobalBounds().height / 2 - txt_content_settings.getGlobalBounds().height));
    txt_content_settings.setOutlineThickness(1);
    txt_content_settings.setOutlineColor(sf::Color(0, 0, 0));
}

void Engine::init() {
    if(!ico_app.loadFromFile("assets/images/icon_app.jpeg")) mWindow->close(); //radical quit
    if(!m_C418.openFromFile("assets/sounds/C418.mp3")) mWindow->close();
    if(!c_hand.loadFromSystem(sf::Cursor::Hand)) mWindow->close();
    if(!c_default.loadFromSystem(sf::Cursor::Arrow)) mWindow->close();
    if(!t_background_settings.loadFromFile("assets/images/settings_screen.png")) mWindow->close();
    if(!t_background_main.loadFromFile("assets/images/background_blured.jpg")) mWindow->close();
    if(!t_maintittle.loadFromFile("assets/images/title.png")) mWindow->close();
    if(!t_copyright_editon.loadFromFile("assets/images/edition_copyright.png")) mWindow->close();
    if(!t_button.loadFromFile("assets/images/button.jpg")) mWindow->close();
    if(!f_regular.loadFromFile("assets/fonts/regular.otf")) mWindow->close();
    if(!f_title1.loadFromFile("assets/fonts/title1.ttf")) mWindow->close();
}

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
    sf::Vector2i mousePos = sf::Mouse::getPosition(*mWindow);

    if(mainScreen) {
        if (s_button_singleplayer.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
            mWindow->setMouseCursor(c_hand);
            s_button_singleplayer.setColor(sf::Color(188, 200, 255, 180));
            txt_content_singleplayer.setFillColor(sf::Color(254, 255, 169));
        } else if (s_button_settings.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
            mWindow->setMouseCursor(c_hand);
            s_button_settings.setColor(sf::Color(188, 200, 255, 180));
            txt_content_settings.setFillColor(sf::Color(254, 255, 169));
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                mainScreen = false;
                settingsScreen = true;
            }
        } else {
            s_button_singleplayer.setColor(sf::Color(255, 255, 255, 200));
            txt_content_singleplayer.setFillColor(sf::Color::White);
            s_button_settings.setColor(sf::Color(255, 255, 255, 200));
            txt_content_settings.setFillColor(sf::Color::White);
            mWindow->setMouseCursor(c_default);
        }
    } else if(settingsScreen) {
        mWindow->setMouseCursor(c_default);
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

        mWindow->draw(s_button_singleplayer); //menu button for singleplayer
        mWindow->draw(txt_content_singleplayer); //singleplayer button 

        mWindow->draw(s_button_settings);
        mWindow->draw(txt_content_settings);

    } else if(settingsScreen) {
        mWindow->draw(s_background_settings);
    }
    mWindow->display();
}

void Engine::run() {   
    //m_C418.play();
    while (mWindow->isOpen()) {
        processWindowEvents();
        update();
        render();
    } 
}