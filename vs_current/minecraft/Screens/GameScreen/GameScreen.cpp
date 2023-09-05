#include "GameScreen.h"

void GameScreen::init() {
	if (!t_background_game_view.loadFromFile("assets/images/backgrounds/SM_Background.png")) mWindow->close();
	if (!t_atlas.loadFromFile("assets/images/atlas/texture_atlas.png")) mWindow->close();

	return;
}

GameScreen::GameScreen(sf::RenderWindow& window, gameState& currentState, LoadState& loadStatus) : Engine(window) {
	mWindow = &window;
	currentStatus = &currentState;
	canLoad = &loadStatus;

	init();

	view.setCenter(mWindow->getSize().x / 2, mWindow->getSize().y / 2);
	view.setSize(540, 400);

	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_real_distribution<float> distribution(200.0f, 270.0f);
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

void GameScreen::windowEvents() {
	sf::Event event;
	while (mWindow->pollEvent(event)) {
		switch (event.type) {
			case sf::Event::Closed:
				*currentStatus = gameState::Menu;
				break;

			default:
				break;
		}
	}

	return;
}

void GameScreen::update() {
	if (mWindow->hasFocus()) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) *currentStatus = gameState::Menu;
	}
	return;
}

void GameScreen::render() {
	if (*currentStatus == gameState::SP_Gameplay) {
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
				}
				else if (y >= gridSizeY - generated_size) { //now we have 2 layouts restantz
					s_stone_block.setPosition(posX, posY);
					mWindow->draw(s_stone_block);
				}
			}
		}

		mWindow->display();
	}

	return;
}

void GameScreen::run() {
	windowEvents();
	update();
	render();

	return;
}