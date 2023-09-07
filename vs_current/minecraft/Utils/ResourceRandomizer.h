#pragma once
#include "../header.h"
#include <string_view>
#include <string>
#include <vector>
#include <random>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

std::string_view Randomize_SlashMessage();
sf::Texture Randomize_MainBackground();
void open_web(const std::string url);