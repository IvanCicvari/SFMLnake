#ifndef STATEMAINMENU_H
#define STATEMAINMENU_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Event.hpp>

#include "buttonState.hpp"
#include "../GameState.hpp"
#include "../game/stateMainGame.hpp"
#include "../../engine/game.hpp"
#include "menuButton.hpp"

class StateMainMenu : public GameState {
    private:
        const int BUTTON_TEXTURE_ROWS = 2;
        const int BUTTON_TEXTURE_CELLS = 2;
        const int BUTTON_LOCATION_OFFSET = 10; //%

        sf::Sprite background;
        Game &game;

        MenuButton playButton;
        MenuButton quitButton;

        void createButtons();
        sf::Texture &getButtonsTexture();
        void prepareBackground();

    public:
        explicit StateMainMenu( Game &game );

        std::unique_ptr< GameState > nextState;
        void draw() override;
        void handleInput( sf::RenderWindow &window ) override;
        void update() override;
};

#endif // STATEMAINMENU_H
