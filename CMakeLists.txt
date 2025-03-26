cmake_minimum_required(VERSION 3.29)
project(blackjack)

set(CMAKE_CXX_STANDARD 17)

add_executable(blackjack src/main.cpp
        src/card.cpp)


# SETUP FOR SFML
# cmake_minimum_required(VERSION 3.29)
# project(blackjack)
#
# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
#
# include(FetchContent)
# FetchContent_Declare(SFML
#         GIT_REPOSITORY https://github.com/SFML/SFML.git
#         GIT_TAG 3.0.0
#         GIT_SHALLOW ON
#         EXCLUDE_FROM_ALL
#         SYSTEM)
# FetchContent_MakeAvailable(SFML)
#
# add_executable(blackjack src/main.cpp)
# target_compile_features(blackjack PRIVATE cxx_std_17)
# target_link_libraries(blackjack PRIVATE SFML::Graphics)
