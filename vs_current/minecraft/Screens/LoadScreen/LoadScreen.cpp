#include "LoadScreen.h"

void LoadScreen::init() {

}

LoadScreen::LoadScreen(sf::RenderWindow& window, gameState& currentState) : Engine(window) {
	mWindow = &window;
	currentStatus = &currentState;

	init();

    loadoverworld_total.setSize(sf::Vector2f(500.0f, 15.0f));
    loadoverworld_total.setFillColor(sf::Color(161, 161, 161));
    loadoverworld_total.setPosition(sf::Vector2f(mWindow->getSize().x / 2 - loadoverworld_total.getGlobalBounds().width / 2, mWindow->getSize().y / 2));

    loadoverwold_process.setSize(sf::Vector2f(0.0f, 13.0f));
    loadoverwold_process.setFillColor(sf::Color(0, 222, 15));
    loadoverwold_process.setPosition(loadoverworld_total.getPosition().x + 1.0f, loadoverworld_total.getPosition().y + 1.0f);

    /*s_background_settings.setTexture(t_background_settings);
    s_background_settings.setScale(sf::Vector2f(static_cast<float>(mWindow->getSize().x) / t_background_settings.getSize().x, static_cast<float>(mWindow->getSize().y) / t_background_settings.getSize().y));
	*/
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

    load_clock.restart();
}

void LoadScreen::windowEvents() {
	sf::Event event;
	while (mWindow->pollEvent(event)) {
		switch (event.type) {
			case sf::Event::Closed:
				mWindow->close();
				break;

			default:
				break;
		}
	}
}

void LoadScreen::update() {
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
            *currentStatus = gameState::Menu;
        }
    }
}

void LoadScreen::render() {
    if (*currentStatus == gameState::Loading) {
        mWindow->clear();

        mWindow->draw(s_background_singleplayer_loading);
        mWindow->draw(s_maintittle); //main title
        mWindow->draw(s_copyright_edition); //title copyright
        mWindow->draw(txt_load_status);
        mWindow->draw(loadoverworld_total);
        mWindow->draw(loadoverwold_process);

        mWindow->display();
    }
}

void LoadScreen::run() {
	windowEvents();
	update();
	render();
}