cmake_minimum_required(VERSION 3.22)
project(sdl_app)

set(CMAKE_CXX_STANDARD 17)

IF(APPLE)
ENDIF()

IF(MINGW)
    set(SDL2_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/SDL2-win/include/SDL2)
    set(SDL2_LIB_DIR ${PROJECT_SOURCE_DIR}/SDL2-win/lib)
ENDIF()

include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})

add_executable(sdl_app src/main.cpp)

target_link_libraries(${PROJECT_NAME} mingw32 SDL2main SDL2 SDL2_image)

