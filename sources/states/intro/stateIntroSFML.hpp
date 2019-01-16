#ifndef STATEINTROSFML_H
#define STATEINTROSFML_H

#include <SFML/Audio/Sound.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

#include "../GameState.hpp"
#include "../menu/stateMainMenu.hpp"
#include "../../engine/Assets.hpp"
#include "../../engine/game.hpp"

class StateIntroSFML : public GameState {
    private:
        Game &game;
        sf::Clock animationTime;
        sf::Sprite logoSpr;

        void centerLogoOrigin();
        void centerLogoPosition();
        void createLogoSprite();
        void prepareAnimation();
        void prepareLogo();

    public:
        explicit StateIntroSFML( Game &game );

        void draw() override;
        void handleInput( sf::RenderWindow &window ) override;
        void update() override;
};

#endif // INTROSFML_H
