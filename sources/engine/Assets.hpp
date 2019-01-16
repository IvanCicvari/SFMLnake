#ifndef SFMLNAKE_ASSETS_HPP
#define SFMLNAKE_ASSETS_HPP

#include <SFML/Graphics/Color.hpp>

#include <string>

class Assets {
    public:
        class Color {
            public:
                static const sf::Color NONE;
                static const sf::Color MASK;
        };

        class Texture {
            public:
                static const std::string SFML_LOGO;
                static const std::string MAIN_MENU_BUTTONS;
                static const std::string MAIN_MENU_BACKGROUND;
                static const std::string MAIN_GAME_TEXTURES;
                static const std::string SCORE_TEXTURES;
                static const std::string GAME_OVER;
                static const std::string VICTORY;
        };

        class Audio {
            public:
                static const std::string SFML_INTRO;
                static const std::string GAME_THEME;
                static const std::string EAT;
                static const std::string END;
        };
};


#endif //SFMLNAKE_ASSETS_HPP
