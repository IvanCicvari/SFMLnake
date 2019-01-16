#include "Assets.hpp"

const sf::Color Assets::Color::NONE = sf::Color( 0, 0, 0, 0 );
const sf::Color Assets::Color::MASK = sf::Color( 255, 0, 255 );

const std::string Assets::Texture::SFML_LOGO            = "./media/SFMLlogo.png";
const std::string Assets::Texture::MAIN_MENU_BUTTONS    = "./media/menuButtons.png";
const std::string Assets::Texture::MAIN_MENU_BACKGROUND = "./media/menuTheme.png";
const std::string Assets::Texture::MAIN_GAME_TEXTURES   = "./media/gameTextures.png";
const std::string Assets::Texture::SCORE_TEXTURES       = "./media/score.png";
const std::string Assets::Texture::GAME_OVER            = "./media/gameOver.png";
const std::string Assets::Texture::VICTORY              = "./media/victory.png";

const std::string Assets::Audio::SFML_INTRO = "./media/sfml-logo-animation.ogg";
const std::string Assets::Audio::GAME_THEME = "./media/gameTheme.ogg";
const std::string Assets::Audio::EAT = "./media/eat.ogg";
const std::string Assets::Audio::END = "./media/end.ogg";