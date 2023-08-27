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

    s_background.setTexture(t_background);
    s_background.setScale(sf::Vector2f(static_cast<float>(mWindow->getSize().x) / t_background.getSize().x, static_cast<float>(mWindow->getSize().y) / t_background.getSize().y));
    
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

    txt_content_singleplayer.setFont(f_regular);
    txt_content_singleplayer.setCharacterSize(15);
    txt_content_singleplayer.setFillColor(sf::Color::White);
    txt_content_singleplayer.setString("Singleplayer");
    //txt_content_singleplayer.setPosition(sf::Vector2f(s_maintitt));
}

void Engine::init() {
    if(!ico_app.loadFromFile("assets/images/icon_app.jpeg")) mWindow->close(); //radical quit
    if(!m_C418.openFromFile("assets/sounds/C418.mp3")) mWindow->close();
    if(!t_background.loadFromFile("assets/images/background_blured.jpg")) mWindow->close();
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

void Engine::processUserEvents() {

    return;
}

void Engine::update() {
    
    return;
}

void Engine::render() {
    mWindow->clear();
    mWindow->draw(s_background);

    mWindow->draw(txt_version_info);
    mWindow->draw(txt_copyright_info);

    mWindow->draw(s_maintittle); //main title
    mWindow->draw(s_copyright_edition); //title copyright
    mWindow->draw(s_button_singleplayer); //menu button for singleplayer
    mWindow->draw(txt_content_singleplayer); //singleplayer button 
    mWindow->display();
}

void Engine::run() {   
    //m_C418.play();
    while (mWindow->isOpen()) {
        processWindowEvents();
        processUserEvents();
        update();
        render();
    } 
}