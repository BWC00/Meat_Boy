CMAKE_MINIMUM_REQUIRED(VERSION 3.22)

PROJECT(2022-project-BWC00)

SET(CMAKE_CXX_FLAGS "-Wall")
SET(CMAKE_CXX_STANDARD 17)

IF (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  SET (CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/installed" CACHE PATH "default install path" FORCE)
ENDIF()

# Look for SFML >= 2.0, with the specific subcomponents listed below
FIND_PACKAGE(SFML 2 COMPONENTS system window graphics audio)

file(COPY "./Data" DESTINATION "${CMAKE_BINARY_DIR}")

ADD_EXECUTABLE(MeatBoy
        src/main.cpp
        src/game_representation/ConcreteFactory.cpp
        src/game_representation/ConcreteFactory.h
        src/game_representation/SimpleWall.cpp
        src/game_representation/SimpleWall.h
        src/game_representation/Data.cpp
        src/game_representation/Data.h
        src/game_representation/EntityView.cpp
        src/game_representation/EntityView.h
        src/game_representation/Game.cpp
        src/game_representation/Game.h
        src/game_representation/GirlGoal.cpp
        src/game_representation/GirlGoal.h
        src/game_representation/Goal.cpp
        src/game_representation/Goal.h
        src/game_representation/LevelState.cpp
        src/game_representation/LevelState.h
        src/game_representation/MeatBoy.cpp
        src/game_representation/MeatBoy.h
        src/game_representation/MenuState.cpp
        src/game_representation/MenuState.h
        src/game_representation/Player.cpp
        src/game_representation/Player.h
        src/game_representation/State.cpp
        src/game_representation/State.h
        src/game_representation/StateManager.cpp
        src/game_representation/StateManager.h
        src/game_representation/Wall.cpp
        src/game_representation/Wall.h
        src/game_representation/Level.cpp
        src/game_representation/Level.h
        src/game_representation/Window.cpp
        src/game_representation/Window.h
        src/game_representation/LevelsContext.cpp
        src/game_representation/LevelsContext.h
        src/game_representation/CONSTANTS.cpp
        src/game_representation/CONSTANTS.h)

ADD_LIBRARY(GameLogic STATIC
        src/logic_library/AbstractFactory.cpp
        src/logic_library/AbstractFactory.h
        src/logic_library/Camera.cpp
        src/logic_library/Camera.h
        src/logic_library/SimpleWall.cpp
        src/logic_library/SimpleWall.h
        src/logic_library/EntityModel.cpp
        src/logic_library/EntityModel.h
        src/logic_library/EVENT.h
        src/logic_library/GirlGoal.cpp
        src/logic_library/GirlGoal.h
        src/logic_library/Goal.cpp
        src/logic_library/Goal.h
        src/logic_library/MeatBoy.cpp
        src/logic_library/MeatBoy.h
        src/logic_library/Observer.cpp
        src/logic_library/Observer.h
        src/logic_library/Player.cpp
        src/logic_library/Player.h
        src/logic_library/Stopwatch.cpp
        src/logic_library/Stopwatch.h
        src/logic_library/Subject.cpp
        src/logic_library/Subject.h
        src/logic_library/Wall.cpp
        src/logic_library/Wall.h
        src/logic_library/World.cpp
        src/logic_library/World.h
        src/logic_library/CONSTANTS.cpp src/logic_library/CONSTANTS.h)

TARGET_LINK_LIBRARIES(MeatBoy GameLogic)

# Add include dirs for SFML
INCLUDE_DIRECTORIES(${SFML_INCLUDE_DIR})

# Link target to SFML libs
TARGET_LINK_LIBRARIES(MeatBoy sfml-system sfml-graphics sfml-window sfml-audio)

# Install our executable to the CMAKE_INSTALL_PREFIX/bin
INSTALL(TARGETS MeatBoy DESTINATION ${PROJECT_SOURCE_DIR}/bin)
