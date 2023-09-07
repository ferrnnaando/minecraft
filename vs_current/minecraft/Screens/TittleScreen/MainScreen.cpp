#include "MainScreen.h"

void MainScreen::init() {
   t_background_main = Randomize_MainBackground();

   return;
}

MainScreen::MainScreen(sf::RenderWindow& window, gameState& currentState, LoadState& loadStatus) : Engine(window) {
    currentStatus = &currentState;
    canLoad = &loadStatus;

    init();

    MenuWidget currentWidget = MenuWidget::Title;
    if (currentWidget == MenuWidget::Title) {
        currentWidget = MenuWidget::Subtitle;
    } if (currentWidget == MenuWidget::Subtitle) {

        currentWidget = MenuWidget::Singleplayer;
    }
    if (currentWidget == MenuWidget::Singleplayer) {
        s_button_singleplayer.setTexture(t_button);
        s_button_singleplayer.setScale(sf::Vector2f(1.2f, 0.85f));
        s_button_singleplayer.setPosition(sf::Vector2f(s_maintittle.getPosition().x + s_maintittle.getGlobalBounds().width / 2 - s_button_singleplayer.getGlobalBounds().width / 2, s_maintittle.getPosition().y + s_maintittle.getGlobalBounds().height + txt_copyright_info.getGlobalBounds().height + 45.0f));

        currentWidget = MenuWidget::Multiplayer;
    }  if (currentWidget == MenuWidget::Multiplayer) {
        s_button_multiplayer.setTexture(t_button);
        s_button_multiplayer.setScale(sf::Vector2f(1.2f, 0.85f));
        s_button_multiplayer.setPosition(sf::Vector2f(s_maintittle.getPosition().x + s_maintittle.getGlobalBounds().width / 2 - s_button_singleplayer.getGlobalBounds().width / 2, s_button_singleplayer.getPosition().y + s_button_singleplayer.getGlobalBounds().height + 6.0f));

        currentWidget = MenuWidget::Settings;
    }
     if (currentWidget == MenuWidget::Settings) {
        s_button_settings.setTexture(t_button);
        s_button_settings.setScale(sf::Vector2f(0.58f, 0.85f));
        s_button_settings.setPosition(sf::Vector2f(s_maintittle.getPosition().x + s_maintittle.getGlobalBounds().width / 2 - s_button_multiplayer.getGlobalBounds().width / 2, s_button_multiplayer.getPosition().y + s_button_multiplayer.getGlobalBounds().height + 27.0f));

        currentWidget = MenuWidget::Quit;
    }
     if (currentWidget == MenuWidget::Quit) {
        s_button_quit.setTexture(t_button);
        s_button_quit.setScale(sf::Vector2f(0.58f, 0.85f));
        s_button_quit.setPosition(sf::Vector2f(s_button_settings.getPosition().x + s_button_settings.getGlobalBounds().width + 9.5f, s_button_multiplayer.getPosition().y + s_button_multiplayer.getGlobalBounds().height + 27.0f));
    }

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
    txt_random_message.setCharacterSize(30);
    txt_random_message.setFillColor(sf::Color(213, 222, 82));
    txt_random_message.setString(static_cast<std::string>(Randomize_SlashMessage()));
    txt_random_message.setPosition(sf::Vector2f(s_maintittle.getGlobalBounds().width + 20.0f, s_maintittle.getGlobalBounds().height + 50.0f));
    txt_random_message.setOutlineThickness(1);
    txt_random_message.setOutlineColor(sf::Color::Black);
    txt_random_message.rotate(-20);

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
                break;

            default:
                break;
        }
    }

    return;
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
         mousePos_absolute = sf::Mouse::getPosition(*mWindow);
         mousePos_relative = mWindow->mapPixelToCoords(mousePos_absolute);

         gridSizeX = mWindow->getSize().x / 16;
         gridSizeY = mWindow->getSize().y / 16;

         if(*currentStatus == gameState::Menu) {
             if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

             } else if (s_button_singleplayer.getGlobalBounds().contains(mousePos_relative)) {
                 mWindow->setMouseCursor(c_hand);
                 s_button_singleplayer.setColor(buttons_hoverColor);
                 txt_content_singleplayer.setFillColor(sf::Color(254, 255, 169));
                 if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                     if (s_click.getStatus() != sf::SoundSource::Playing) {
                         s_click.play();
                        // *canLoad = LoadState::ls_true;
                         *currentStatus = gameState::Loading;
                         return;
                     }
                 }
             } else if (s_button_settings.getGlobalBounds().contains(mousePos_relative)) {
                 mWindow->setMouseCursor(c_hand);
                 s_button_settings.setColor(buttons_hoverColor);
                 txt_content_settings.setFillColor(sf::Color(254, 255, 169));
                 if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                     if (s_click.getStatus() != sf::SoundSource::Playing) {
                         s_click.play();
                         return;
                     }
                 }
             }
             else if (s_button_quit.getGlobalBounds().contains(mousePos_relative)) {
                 mWindow->setMouseCursor(c_hand);
                 s_button_quit.setColor(buttons_hoverColor);
                 txt_content_quit.setFillColor(sf::Color(254, 255, 169));
                 if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                     if (s_click.getStatus() != sf::SoundSource::Playing) {
                         s_click.play();
                         *currentStatus = gameState::Quit;
                         return;
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
                 return;
             }
         }
         /*else if (settingsScreen) {
             mWindow->setMouseCursor(c_default);
         }
         else if (loading_overworldScreen) {
             mWindow->setMouseCursor(c_default);

             sf::Time elapsedTime = load_clock.restart();
             currentTime += elapsedTime.asSeconds();
             float progress = currentTime / totalLoadTime;

             progress = std::min(progress, 1.0f);

             float newWidth = loadoverworld_total.getSize().x * progress;
             loadoverwold_process.setSize(sf::Vector2f(newWidth, loadoverwold_process.getSize().y));

             if (loadoverwold_process.getSize().x <= 50.0f) {
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
             else if (loadoverwold_process.getSize().x >= 500) {
                 load_process_info = "Loading Overworld";
                 txt_load_status.setString(load_process_info);
                 if (enter_game.getElapsedTime().asSeconds() >= 0.f) {
                     load_clock.restart();
                     loadoverwold_process.setSize(sf::Vector2f(0.0f, 13.0f));
                     loading_overworldScreen = false;
                     singleplayerGameScreen = true;
                 }
             }
         }
         else if (singleplayerGameScreen) {

             if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                 load_clock.restart();
                 loadoverwold_process.setSize(sf::Vector2f(0.0f, 13.0f));
                 singleplayerGameScreen = false;
                 mainScreen = true;
             }
             else {
                 //We need to make this because if we just do getcenterx - 0 whe are checking for size in pixels, remember we are working with grids of 16x16
                 float leftMaxGrid = 0.5f * view.getSize().x;
                 float rightMaxGrid = gridSizeX - 0.5f * view.getSize().x;

                 if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && view.getCenter().x - leftMaxGrid > 0) {
                     view.move(sf::Vector2f(-2.0f, 0.0f));
                 }
                 else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && view.getCenter().x + rightMaxGrid < mWindow->getSize().x) {
                     view.move(sf::Vector2f(2.0f, 0.0f));
                 }
             }
         }*/
     }
     return;
}

void MainScreen::update() {

    return;
}

void MainScreen::render() {
    if(*currentStatus == gameState::Menu) {
        mWindow->clear(sf::Color(255, 255, 255, 20));
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

        mWindow->display();
    }

    return;
}

void MainScreen::run() {
    windowEvents();
    userEvents();
    update();
    render();

    return;
}