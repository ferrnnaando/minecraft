#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <random>

#include "../../Engine/Engine.h"
#include "../../header.h"

class GameScreen : public Engine {
	public:
		GameScreen(sf::RenderWindow& window, gameState& currentState, LoadState& loadStatus);
		~GameScreen() {};

		void run() override;

	private:
		void init() override;
		void windowEvents(); //override;
		void update(); //override;
		void render(); //override;

		sf::View view;

		gameState* currentStatus;
		LoadState* canLoad;

		float terrainHeight;
		sf::RectangleShape terrain_size;
		sf::Texture t_background_game_view, t_blocks_atlas;
		sf::Sprite s_grass_block, s_dirt_block, s_stone_block, s_bedrock_block, s_singleplayer_background_viewscreen;

		sf::Texture t_player_atlas;
		sf::Sprite s_steve_idle;
};