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

enum class MenuWidget { Title, Subtitle, Singleplayer, Multiplayer, Settings, Quit };
enum class gameState { Menu, Loading, SP_Gameplay, MP_Gameplay, Settings };