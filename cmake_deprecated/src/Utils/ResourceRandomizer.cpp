#include "ResourceRandomizer.h"

std::string_view Randomize_SlashMessage() {

    std::vector<std::string> messages = {
    "Craft, Explore, Survive!",
    "Unleash Your Creativity!",
    "New Adventures Await!",
    "Block-Building Fun Awaits!",
    "Discover Endless Worlds!",
    "Mine, Craft, Repeat!",
    "Forge Your Own Path!",
    "Build Your Dream World!",
    "Enter the Pixelated Realm!",
    "Embark on Epic Quests!",
    "Crafting Awaits Your Command!",
    "Adventure Awaits, Miner!",
    "Crafting and Building Galore!",
    "Dive into Blocky Wonders!",
    "Survive and Thrive in Minecraft!",
    "Un-Limitless Possibilities!",
    "Build Your Imagination!",
    "Construct Your Fantasy World!",
    "Explore, Create, Conquer!",
    "Brave the Blocks and Build!",
    "Begin Your Minecraft Journey!",
    "Snapshot, Smile!",
    "Mine Your Way to Glory!",
    "Crafting Your World, One Block at a Time!",
    "Adventure Beyond the Horizon!",
    "Infinite Creativity in Every Block!",
    "Build, Survive, Thrive!",
    "Unearth the Secrets of Minecraft!",
    "A World of Blocks Awaits Your Touch!",
    "Craft Your Legacy!",
    "Every Block Tells a Story!",
    "Master the Art of Mining and Crafting!",
    "Dream, Build, Explore!",
    "Your Imagination, Your World!",
    "Mine Deep, Build High!",
    "The Adventure Begins Here!",
    "A World to Create, A World to Explore!",
    "Minecraft: Where Blocks Come to Life!",
    "Crafting, Mining, and More!",
    "Uncover the Mysteries of Minecraft!",
    "Block by Block, You Shape the World!",
    "Craft Your Destiny!",
    "Adventure Beyond the Horizon!",
    "The World of Blocks Awaits!",
    "Dig Deep, Dream Big!",
    "Build the Impossible!",
    "Crafting Your Dreams into Reality!",
    "Mine Your Way to Greatness!",
    "Infinite Adventures Await!",
    "Minecraft: The Ultimate Sandbox!",
    "Creativity Unleashed!",
    "Explore the Endless Possibilities!",
    "Master the Craft of Building!",
    "Adventure Awaits in Every Block!",
    "Build, Survive, Thrive!",
    "Unleash Your Inner Builder!",
    "Craft Your World, One Block at a Time!",
    "Mine, Create, Discover!",
    "Embark on an Epic Journey!",
    "Where Imagination Meets Creation!",
    "The Adventure Begins Here!",
    "Crafting Dreams into Reality!",
    "A World of Blocks, Yours to Explore!",
    "Create Your Legacy in Minecraft!",
    "Mining, Crafting, and Beyond!",
    "Unlock the Secrets of Minecraft!",
    "Shape Your World, Block by Block!",
    "Craft Your Own Path!",
    "Building Adventures Await!",
    "Unearth the Wonders of Minecraft!",
    "Every Block Tells a Tale!",
    "Minecraft: Where Blocks Come Alive!",
    "Crafting, Mining, and More!",
    "Discover the Magic of Minecraft!",
    "Build Your Dreams!",
    "Adventure Beyond Imagination!",
    "The World of Blocks Awaits Your Touch!",
    "Dig Deep, Build Tall!",
    "Crafting the Future!",
    "Dream, Build, Explore!",
    "Create Your Reality, One Block at a Time!",
    "Mine Deep, Dream High!",
    "Craft Your Destiny!",
    "Endless Adventures Await!",
    "Minecraft: Your World, Your Way!",
    "Crafting Creations into Existence!",
    "Uncover the Marvels of Minecraft!",
    "Block by Block, You Shape Your World!",
    "Craft Your Own Adventure!",
    "Adventure Awaits Beyond the Horizon!",
    "Explore, Build, Thrive!",
    "Unleash Your Inner Architect!",
    "Discover Endless Possibilities!",
    "Master the Art of Building!",
    "The World of Blocks Beckons!",
    "Build, Survive, and Flourish!",
    "Unleash Your Creativity!",
    "Mining and Crafting: Your Path to Greatness!",
    "Enter a World of Blocks and Imagination!",
    "Craft Your World with Every Block!",
    "Mine, Create, Conquer!",
    "Embark on an Epic Journey!",
    "Where Imagination Meets Reality!",
    "The Adventure Awaits You!",
    "Crafting Dreams into Reality!",
    "A Universe of Blocks Awaits Exploration!",
    "Forge Your Path to Greatness!",
    "Building Marvels Await!",
    "Discover the Wonders of Minecraft!",
    "Unlock Secrets, One Block at a Time!",
    "Shape Your World, Block by Block!",
    "Crafting a Brighter Future!",
    "Dream, Build, Conquer!",
    "Create Your Legacy in Minecraft!",
    "Crafting: Your Journey Awaits!",
    "Mining, Crafting, Thriving!",
    "The World of Blocks, Yours to Explore!",
    "Crafting Adventures Begin!",
    "Unearth Hidden Treasures!",
    "Every Block Holds a Story!",
    "Minecraft: Blocks Brought to Life!",
    "Crafting, Mining, Exploring!",
    "Discover the Marvels of Minecraft!",
    "Build Your Dreams, One Block at a Time!",
    "Adventure Beyond Imagination!",
    "The World of Blocks Awaits Your Touch!",
    "Dig Deep, Build Tall!",
    "Crafting the Future!",
    "Dream, Build, Explore!",
    "Create Your Reality, One Block at a Time!",
    "Mine Deep, Dream High!",
    "Craft Your Destiny!",
    "Endless Adventures Await!",
    "Minecraft: Your World, Your Rules!",
    "Crafting Creations into Existence!",
    "Uncover the Wonders of Minecraft!",
    "Block by Block, You Shape Your World!",
    "Craft Your Own Adventure!",
    "Adventure Awaits Beyond the Horizon!",
    "Explore, Build, Thrive!",
    "Unleash Your Inner Architect!",
    "Discover Endless Possibilities!",
    "Master the Art of Building!",
    "The World of Blocks Beckons!",
    "Build, Survive, Flourish!",
    "Unleash Your Creativity!",
    "Mining and Crafting: Your Path to Greatness!",
    "Enter a World of Blocks and Imagination!",
    "Craft Your World, Block by Block!",
    "Mine, Create, Conquer!",
    "Embark on an Epic Journey!",
    "Where Imagination Meets Reality!",
    "The Adventure Awaits You!",
    "Crafting Dreams into Reality!",
    "A Universe of Blocks Awaits Exploration!",
    "Forge Your Path to Greatness!",
    "Building Marvels Await!",
    "Discover the Wonders of Minecraft!",
    "Unlock Secrets, One Block at a Time!",
    "Shape Your World, Block by Block!",
    "Crafting a Brighter Future!",
    "Dream, Build, Conquer!",
    "Create Your Legacy in Minecraft!",
    "Crafting: Your Journey Awaits!",
    "Mining, Crafting, Thriving!",
    "The World of Blocks, Yours to Explore!",
    "Crafting Adventures Begin!",
    "Unearth Hidden Treasures!",
    "Every Block Holds a Story!",
    "Minecraft: Blocks Brought to Life!",
    "Crafting, Mining, Exploring!",
    "Discover the Marvels of Minecraft!",
    "Build Your Dreams, One Block at a Time!",
    "Adventure Beyond Imagination!",
    "The World of Blocks Awaits Your Touch!",
    "Dig Deep, Build Tall!",
    "Crafting the Future!",
    "Dream, Build, Explore!",
    "Create Your Reality, One Block at a Time!",
    "Mine Deep, Dream High!",
    "Craft Your Destiny!",
    "Endless Adventures Await!",
    "Minecraft: Your World, Your Rules!",
    "Crafting Creations into Existence!",
    "Uncover the Wonders of Minecraft!",
    "Block by Block, You Shape Your World!",
    "Craft Your Own Adventure!",
    "Adventure Awaits Beyond the Horizon!",
    "Explore, Build, Thrive!",
    "Unleash Your Inner Architect!",
    "Discover Endless Possibilities!",
    "Master the Art of Building!",
    "The World of Blocks Beckons!",
    "Build, Survive, Flourish!",
    "Unleash Your Creativity!",
    "Mining and Crafting: Your Path to Greatness!",
    "Enter a World of Blocks and Imagination!",
    "Craft Your World, Block by Block!",
    "Mine, Create, Conquer!",
    "Embark on an Epic Journey!",
    "Where Imagination Meets Reality!",
    "The Adventure Awaits You!",
    "Crafting Dreams into Reality!",
    "A Universe of Blocks Awaits Exploration!",
    "Forge Your Path to Greatness!",
    "Building Marvels Await!",
    "Discover the Wonders of Minecraft!",
    "Unlock Secrets, One Block at a Time!",
    "Shape Your World, Block by Block!",
    "Crafting a Brighter Future!",
    "Dream, Build, Conquer!",
    "Create Your Legacy in Minecraft!",
    "Crafting: Your Journey Awaits!",
    "Mining, Crafting, Thriving!",
    "The World of Blocks, Yours to Explore!",
    "Crafting Adventures Begin!",
    "Unearth Hidden Treasures!",
    "Every Block Holds a Story!",
    "Minecraft: Blocks Brought to Life!",
    "Crafting, Mining, Exploring!",
    "Discover the Marvels of Minecraft!",
    "Build Your Dreams, One Block at a Time!"
};

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(0, messages.size());
    int random = distribution(gen);

    std::string_view fastStr { messages[random] };
    return fastStr;
}

sf::Texture Randomize_MainBackground() {
    std::vector<std::string> paths = { "assets/images/backgrounds/mainScreen_0.jpg", "assets/images/backgrounds/mainScreen_1.jpeg", "assets/images/backgrounds/mainScreen_2.png", 
    "assets/images/backgrounds/mainScreen_3.jpeg", "assets/images/backgrounds/mainScreen_4.jpeg", "assets/images/backgrounds/mainScreen_5.jpeg", 
    "assets/images/backgrounds/mainScreen_6.jpeg", "assets/images/backgrounds/mainScreen_7.jpeg" };

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(0, paths.size());
    int random = distribution(gen);

    sf::Texture t_background;
    t_background.loadFromFile(paths[random]);

    return t_background;
}