#pragma once
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

enum class gameState { Menu, Loading, SP_Gameplay, MP_Gameplay, Settings, Quit };
enum class LoadState { ls_true, ls_false };