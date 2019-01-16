cmake_minimum_required(VERSION 3.9)

set(CMAKE_CXX_STANDARD 11)

project(SFMLnake VERSION 1.1.0)

include_directories("${PROJECT_BINARY_DIR}")

add_executable(SFMLnake
        media/sfml-logo-animation.ogg
        media/gameTextures.png
        media/menuButtons.png
        media/menuTheme.png
        media/score.png
        media/SFMLlogo.png
        sources/engine/engine.cpp
        sources/engine/engine.hpp
        sources/engine/game.cpp
        sources/engine/game.hpp
        sources/engine/textureManager.cpp
        sources/engine/textureManager.hpp
        sources/states/game/direction.hpp
        sources/states/game/fruit.cpp
        sources/states/game/fruit.hpp
        sources/states/game/gameSprites.cpp
        sources/states/game/gameSprites.hpp
        sources/states/game/score.cpp
        sources/states/game/score.hpp
        sources/states/game/spriteType.hpp
        sources/states/intro/stateIntroSFML.cpp
        sources/states/intro/stateIntroSFML.hpp
        sources/states/menu/buttonState.hpp
        sources/states/menu/menuButton.cpp
        sources/states/menu/menuButton.hpp
        sources/states/menu/stateMainMenu.cpp
        sources/states/menu/stateMainMenu.hpp
        sources/states/GameState.hpp
        sources/states/game/field.cpp
        sources/states/game/field.hpp
        sources/states/game/snake.cpp
        sources/states/game/snake.hpp
        sources/states/game/stateMainGame.cpp
        sources/states/game/stateMainGame.hpp
        sources/engine/soundManager.hpp
        sources/states/game/Collision.cpp
        sources/states/game/Collision.hpp
        sources/engine/soundManager.cpp
        main.cpp
        README.md sources/engine/Assets.cpp sources/engine/Assets.hpp)



set(SFML_DIR "${SFML_PATH}")

find_package(SFML 2.5 COMPONENTS graphics audio)
#window graphics audio
target_link_libraries(SFMLnake sfml-graphics sfml-audio)