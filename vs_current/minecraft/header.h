#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <thread>
#include <chrono>
#include <map>
#include <random>
#include <vector>
#include <mutex>
#include <unordered_map>
#include <string_view>
#include <exception>
#include <stdexcept>
#include <memory>

#include "Utils/ResourceRandomizer.h"

enum class MenuWidget {  Title        = 1, 
						 Subtitle     = 2, 
						 Singleplayer = 3, 
						 Multiplayer  = 4, 
						 Settings     = 5, 
						 Quit         = 6 
					  };
//std::vector<int> MenuWidgetExtend = { 0 };
//std::vector<int> MenuWidgetExtend[];
enum class gameState { Menu, Loading, SP_Gameplay, MP_Gameplay, Settings };
enum class LoadState { ls_true, ls_false };