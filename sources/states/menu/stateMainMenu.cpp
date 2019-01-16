#include "stateMainMenu.hpp"

StateMainMenu::StateMainMenu( Game &game )
        : game( game ),
          playButton( getButtonsTexture()),
          quitButton( getButtonsTexture()) {
    this->nextState = nullptr;

    prepareBackground();
    createButtons();

    game.getSoundManager().playMusic();
}


void StateMainMenu::handleInput( sf::RenderWindow &window ) {
    sf::Event event;
    while ( window.pollEvent( event )) {
        switch ( event.type ) {
            case sf::Event::Closed :
                window.close();
                break;

            case sf::Event::KeyPressed :
                if ( sf::Keyboard::isKeyPressed( sf::Keyboard::M )) {
                    game.getSoundManager().changeMusicState();
                }
                break;

            default :
                break;
        }
    }
}

void StateMainMenu::update() {
    sf::RenderWindow &window = game.getWindow();
    if ( playButton.isClicked( window )) {
        std::unique_ptr< GameState > playGameState( new StateMainGame( game ));
        nextState = std::move( playGameState );

    } else if ( quitButton.isClicked( window )) {
        game.setExitGame();
    }
}

void StateMainMenu::draw() {
    sf::RenderWindow &window = game.getWindow();
    window.draw( background );

    playButton.draw( window );
    quitButton.draw( window );
}

void StateMainMenu::prepareBackground() {
    TextureManager &manager = game.getTextureManager();
    sf::Texture &texture = manager.getTexture( Assets::Texture::MAIN_MENU_BACKGROUND );
    sf::Vector2u windowSize = game.getWindow().getSize();
    sf::Vector2u textureSize = texture.getSize();

    background.setTexture( texture );
    background.setScale(
            ( float ) windowSize.x / textureSize.x,
            ( float ) windowSize.y / textureSize.y );
}

void StateMainMenu::createButtons() {
    sf::Texture &buttonTexture = getButtonsTexture();
    int buttonWidth = buttonTexture.getSize().x / BUTTON_TEXTURE_ROWS;
    int buttonHeight = buttonTexture.getSize().y / BUTTON_TEXTURE_CELLS;

    int windowWidth = game.getWindow().getSize().x;
    int windowHeight = game.getWindow().getSize().y;
    int offset = buttonHeight / BUTTON_LOCATION_OFFSET;

    playButton.setPosition(
            sf::Vector2f(( float ) windowWidth / BUTTON_TEXTURE_CELLS - buttonWidth,
                         windowHeight - buttonHeight - offset ));
    playButton.addSprite( sf::IntRect( 0, 0, buttonWidth, buttonHeight ), ButtonState::NORMAL );
    playButton.addSprite( sf::IntRect( buttonWidth, 0, buttonWidth, buttonHeight ), ButtonState::PRESSED );

    quitButton.setPosition(
            sf::Vector2f(( float ) windowWidth / BUTTON_TEXTURE_CELLS, windowHeight - buttonHeight - offset ));
    quitButton.addSprite( sf::IntRect( 0, buttonHeight, buttonWidth, buttonHeight ), ButtonState::NORMAL );
    quitButton.addSprite( sf::IntRect( buttonWidth, buttonHeight, buttonWidth, buttonHeight ),
                          ButtonState::PRESSED );
}

sf::Texture &StateMainMenu::getButtonsTexture() {
    TextureManager &manager = game.getTextureManager();
    return manager.getTexture( Assets::Texture::MAIN_MENU_BUTTONS );
}