#include "../include/game.hpp"

Game::Game() : exitGame( false ) {
    window.create( sf::VideoMode( WIDTH, HEIGHT ), "SFMLnake" );
    window.setFramerateLimit( FPS );

    loadSounds();
    loadTextures();
    loadFonts();
}

Game::~Game() {
}

sf::RenderWindow& Game::getWindow( void ) {
    return window;
};

ResourceManager& Game::getResManager( void ) {
    return manager;
};

void Game::setExitGame( void ) {
    exitGame = true;
}

bool Game::isExitGame( void ) {
    return exitGame;
}

void Game::loadSounds( void ) {
    manager.addSound( Sound::SFML_INTRO );
}

void Game::loadTextures( void ) {
    manager.addTexture( Texture::SFML_LOGO );
}

void Game::loadFonts( void ) {
    manager.addFont( Font::VERDANA );
}