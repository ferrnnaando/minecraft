#include "MainScreen.h"

bool MainScreen::isEnabled() {
    return true;
}

void MainScreen::init() {
   t_background_main = Randomize_MainBackground();
}

MainScreen::MainScreen(sf::RenderWindow& window) : Engine(window) {
    mWindow = &window;

    init();

    s_background_main.setTexture(t_background_main);
    s_background_main.setScale(sf::Vector2f(static_cast<float>(mWindow->getSize().x) / t_background_main.getSize().x, static_cast<float>(mWindow->getSize().y) / t_background_main.getSize().y));

    txt_version_info.setFont(f_regular);
    txt_version_info.setCharacterSize(15);
    txt_version_info.setFillColor(sf::Color(255, 255, 255));
    txt_version_info.setString(game_version);
    txt_version_info.setPosition(sf::Vector2f(8, mWindow->getSize().y - txt_version_info.getCharacterSize() - 5));

    txt_copyright_info.setFont(f_regular);
    txt_copyright_info.setCharacterSize(15);
    txt_copyright_info.setFillColor(sf::Color::White);
    txt_copyright_info.setString(game_disclaimer);
    txt_copyright_info.setPosition(sf::Vector2f(mWindow->getSize().x- txt_copyright_info.getGlobalBounds().width - 8, mWindow->getSize().y - txt_version_info.getCharacterSize() - 5));

    txt_random_message.setFont(f_regular);
    txt_random_message.setCharacterSize(20);
    txt_random_message.setFillColor(sf::Color(213, 222, 82));
    txt_random_message.setString(static_cast<std::string>(Randomize_SlashMessage()));
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
    s_button_settings.setScale(sf::Vector2f(0.58f, 0.85f));
    s_button_settings.setPosition(sf::Vector2f(s_maintittle.getPosition().x + s_maintittle.getGlobalBounds().width / 2 - s_button_multiplayer.getGlobalBounds().width / 2, s_button_multiplayer.getPosition().y + s_button_multiplayer.getGlobalBounds().height + 27.0f));

    s_button_quit.setTexture(t_button);
    s_button_quit.setScale(sf::Vector2f(0.58f, 0.85f));
    s_button_quit.setPosition(sf::Vector2f(s_button_settings.getPosition().x + s_button_settings.getGlobalBounds().width + 9.5f, s_button_multiplayer.getPosition().y + s_button_multiplayer.getGlobalBounds().height + 27.0f));

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
    if(isMessage_increasing) {
        txt_random_message.scale(1 + randomMessage_speedScale * 0.3f, 1 + randomMessage_speedScale * 0.3f);
    } else {
        txt_random_message.scale(1 - randomMessage_speedScale * 0.3f, 1 - randomMessage_speedScale * 0.3f);
    }

    if(txt_random_message.getScale().x > 1.25f || txt_random_message.getScale().x < 1.0f) {
        isMessage_increasing = !isMessage_increasing;
    }

     if(mWindow->hasFocus()) {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {}
            else if (s_button_singleplayer.getGlobalBounds().contains(mousePos_relative)) {
                mWindow->setMouseCursor(c_hand);
                s_button_singleplayer.setColor(buttons_hoverColor);
                txt_content_singleplayer.setFillColor(sf::Color(254, 255, 169));
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    if(s_click.getStatus() != sf::SoundSource::Playing) {
                        //load_clock.restart();
                        //enter_game.restart();
                        s_click.play();
                        //mainScreen = false;
                        //loading_overworldScreen = true;
                    }
                }
            }
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
    mWindow->display();
}

void MainScreen::run() {
    windowEvents();
    userEvents();
    update();
    render();
}