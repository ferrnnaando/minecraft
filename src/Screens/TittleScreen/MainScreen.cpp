#include "MainScreen.h"

bool MainScreen::isEnabled() {
    return true;
}

void MainScreen::init() {
    if(!t_background_main.loadFromFile("assets/images/background.jpeg")) mWindow->close();
}

MainScreen::MainScreen(sf::RenderWindow& window) : Engine(window) {
    mWindow = &window;

    init();

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
}

void MainScreen::windowEvents() {
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

void MainScreen::userEvents() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        mWindow->close();
    }
}

void MainScreen::update() {

}

void MainScreen::render() {
    if(isEnabled()) {
        mWindow->clear();
        mWindow->setView(mWindow->getDefaultView());
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
    }
}

void MainScreen::run() {
    windowEvents();
    userEvents();
    update();
    render();
}






std::string MainScreen::random_message() {
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