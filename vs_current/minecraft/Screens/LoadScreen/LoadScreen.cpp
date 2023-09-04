#include "LoadScreen.h"

LoadScreen::LoadScreen(sf::RenderWindow& window, gameState& currentState) : Engine(window), MainScreen(window, currentState) {
	mWindow = &window;
	currentStatus = &currentState;
}

void LoadScreen::init() {

}

void LoadScreen::windowEvents() {
	sf::Event event;
	while (mWindow->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			mWindow->close();
		}
	}
}

void LoadScreen::userEvents() {

}

void LoadScreen::update() {

}

void LoadScreen::render() {
	mWindow->clear();
	mWindow->display();
}

void LoadScreen::run() {
	windowEvents();
	userEvents();
	update();
	render();
}