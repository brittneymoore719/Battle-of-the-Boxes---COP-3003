cmake_minimum_required(VERSION 3.28)
project(Battle-of-the-Boxes LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.2
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

file(GLOB_RECURSE
    SOURCE_FILES
    CONFIGURE_DEPENDS
    ${CMAKE_SOURCE_DIR}/src/*.cpp
)

add_executable(Battle-of-the-Boxes ${SOURCE_FILES}
        src/game/combat/CombatSequence.cpp
        src/game/combat/CombatSequence.h
        src/display/stage/Stage.h
        src/game/combat/combatant/Combatant.cpp
        src/game/combat/combatant/PlayerCombatant.cpp
        src/display/stage/battle/BattleStage.cpp
        src/display/stage/battle/BattleStage.h
        src/utils/RNG.cpp
        src/utils/RNG.h
)
configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/arial.ttf"
    "${CMAKE_CURRENT_BINARY_DIR}/arial.ttf"
    COPYONLY
)

target_include_directories(Battle-of-the-Boxes PRIVATE ${CMAKE_SOURCE_DIR}/src/)
target_compile_features(Battle-of-the-Boxes PRIVATE cxx_std_20)
target_link_libraries(Battle-of-the-Boxes PRIVATE SFML::Graphics)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Battle-of-the-Boxes)
