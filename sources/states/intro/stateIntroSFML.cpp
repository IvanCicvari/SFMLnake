#include "stateIntroSFML.hpp"

StateIntroSFML::StateIntroSFML( Game &game ) : game( game ) {
    prepareLogo();
    prepareAnimation();

    game.getSoundManager().playSound( Assets::Audio::SFML_INTRO );
}

void StateIntroSFML::handleInput( sf::RenderWindow &window ) {
    sf::Event event;
    while ( window.pollEvent( event )) {
        switch ( event.type ) {
            case sf::Event::Closed :
                game.getSoundManager().stopSound( Assets::Audio::SFML_INTRO );
                window.close();
                break;

            case sf::Event::KeyPressed :
                game.getSoundManager().stopSound( Assets::Audio::SFML_INTRO );
                break;

            default :
                break;
        }
    }
}

void StateIntroSFML::update() {
    bool isIntroTheme = game.getSoundManager().isPlaying( Assets::Audio::SFML_INTRO );
    if ( !isIntroTheme ) {
        game.getSoundManager().stopSound( Assets::Audio::SFML_INTRO );

    } else {
        sf::Uint8 brightness = logoSpr.getColor().a;
        if ( brightness < 255 ) {
            brightness += 3;
        }

        sf::Color color = sf::Color( 255, 255, 255, brightness );
        logoSpr.setColor( color );
    }
}

void StateIntroSFML::draw() {
    sf::RenderWindow &window = game.getWindow();
    window.draw( logoSpr );
}

void StateIntroSFML::prepareLogo() {
    createLogoSprite();
    centerLogoOrigin();
    centerLogoPosition();
    logoSpr.setScale( 0.8f, 0.8f );
    logoSpr.setColor( Assets::Color::NONE );
}

void StateIntroSFML::prepareAnimation() {
    animationTime.restart();
}

void StateIntroSFML::createLogoSprite() {
    TextureManager &manager = game.getTextureManager();
    sf::Texture &logoTxr = manager.getTexture( Assets::Texture::SFML_LOGO );
    logoSpr.setTexture( logoTxr );

    int width = logoTxr.getSize().x;
    int height = logoTxr.getSize().y;
    logoSpr.setTextureRect( sf::IntRect( 0, 0, width, height ));
}

void StateIntroSFML::centerLogoOrigin() {
    float xCenter = logoSpr.getGlobalBounds().width / 2;
    float yCenter = logoSpr.getGlobalBounds().height / 2;
    logoSpr.setOrigin( xCenter, yCenter );
}

void StateIntroSFML::centerLogoPosition() {
    sf::RenderWindow &window = game.getWindow();
    int windowWidth = window.getSize().x;
    int windowHeight = window.getSize().y;
    logoSpr.setPosition( windowWidth / 2, windowHeight / 2 );
}