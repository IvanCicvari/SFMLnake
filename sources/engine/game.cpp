#include "game.hpp"

Game::Game () {
    exitGame = false;

    createWindow();
    loadSounds();
    loadTextures();
}

Game::~Game () = default;

sf::RenderWindow &Game::getWindow () {
    return window;
};

TextureManager &Game::getTextureManager () {
    return textureManager;
};

void Game::setExitGame () {
    exitGame = true;
}

bool Game::isExitGame () {
    return exitGame;
}

void Game::loadSounds () {
    soundManager.addSound( Assets::Audio::SFML_INTRO );
    soundManager.addSound( Assets::Audio::EAT );
    soundManager.addSound( Assets::Audio::END );
}

void Game::loadTextures () {
    textureManager.addTexture( Assets::Texture::SFML_LOGO );
    textureManager.addTexture( Assets::Texture::MAIN_MENU_BACKGROUND );
    textureManager.addTexture( Assets::Texture::MAIN_MENU_BUTTONS );
    textureManager.addTexture( Assets::Texture::MAIN_GAME_TEXTURES );
    textureManager.addTexture( Assets::Texture::SCORE_TEXTURES );
    textureManager.addTexture( Assets::Texture::GAME_OVER );
    textureManager.addTexture( Assets::Texture::VICTORY );
}

void Game::createWindow () {
    window.create( sf::VideoMode( WIDTH, HEIGHT ), "SFMLnake");
    window.setFramerateLimit( FPS );
    window.setKeyRepeatEnabled( false );
}

SoundManager &Game::getSoundManager () {
    return soundManager;
}
