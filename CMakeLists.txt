cmake_minimum_required(VERSION 3.10)

project(Sliding-Puzzle)
include_directories(include)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/sdl2-cmake-modules)

add_executable(${PROJECT_NAME}
    src/userInterface.cpp
    src/stopwatch.cpp
    src/tile.cpp
    src/main.cpp
)

# Add and link SDL2 library
find_package(SDL2 REQUIRED)
target_link_libraries(${PROJECT_NAME} SDL2::Main)

# Add and link SDL2_ttf library
find_package(SDL2_ttf REQUIRED)
target_link_libraries(${PROJECT_NAME} SDL2::TTF)

# Add SDL2_image library
# find_package(SDL2_image REQUIRED)
# target_link_libraries(${PROJECT_NAME} SDL2::Image)
