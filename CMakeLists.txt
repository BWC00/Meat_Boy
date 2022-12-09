CMAKE_MINIMUM_REQUIRED(VERSION 3.22)
PROJECT(2022-project-BWC00)
SET(CMAKE_CXX_FLAGS "-Wall")
IF (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  SET (CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/installed" CACHE PATH "default install path" FORCE)
ENDIF()

# Look for SFML >= 2.0, with the specific subcomponents listed below
FIND_PACKAGE(SFML 2 COMPONENTS system window graphics audio)

# The source files to compile
SET(SRC src/main.cpp src/game_representation/Game.cpp src/game_representation/Game.h src/logic_library/INPUT.h src/logic_library/World.cpp src/logic_library/World.h src/game_representation/ConcreteFactory.cpp src/game_representation/ConcreteFactory.h src/logic_library/AbstractFactory.cpp src/logic_library/AbstractFactory.h src/game_representation/Data.cpp src/game_representation/Data.h src/logic_library/Stopwatch.cpp src/logic_library/Stopwatch.h src/logic_library/Camera.cpp src/logic_library/Camera.h src/logic_library/MeatBoy.cpp src/logic_library/MeatBoy.h src/logic_library/EntityModel.cpp src/logic_library/EntityModel.h src/logic_library/EVENT.h src/logic_library/Observer.cpp src/logic_library/Observer.h src/logic_library/Player.cpp src/logic_library/Player.h src/logic_library/Random.cpp src/logic_library/Random.h src/logic_library/Score.cpp src/logic_library/Score.h src/logic_library/Subject.cpp src/logic_library/Subject.h src/game_representation/EntityView.cpp src/game_representation/EntityView.h src/game_representation/Player.cpp src/game_representation/Player.h src/game_representation/Score.cpp src/game_representation/Score.h src/game_representation/Wall.cpp src/game_representation/Wall.h src/game_representation/Goal.cpp src/game_representation/Goal.h src/logic_library/Wall.cpp src/logic_library/Wall.h src/logic_library/Goal.cpp src/logic_library/Goal.h src/logic_library/ConcreteWall.cpp src/logic_library/ConcreteWall.h src/game_representation/ConcreteWall.cpp src/game_representation/ConcreteWall.h src/logic_library/GirlGoal.cpp src/logic_library/GirlGoal.h src/game_representation/GirlGoal.cpp src/game_representation/GirlGoal.h src/game_representation/MeatBoy.cpp src/game_representation/MeatBoy.h src/game_representation/MenuState.cpp)

# Add include dirs for SFML
INCLUDE_DIRECTORIES(${SFML_INCLUDE_DIR})

# The program we're compiling with the sources set above
ADD_EXECUTABLE(game ${SRC})

# Link target to SFML libs
TARGET_LINK_LIBRARIES(game sfml-system sfml-graphics sfml-window sfml-audio)

# Install our executable to the CMAKE_INSTALL_PREFIX/bin
INSTALL(TARGETS game DESTINATION bin)
