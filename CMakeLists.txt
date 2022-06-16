cmake_minimum_required(VERSION 3.22)
project(sdl_app)

set(CMAKE_CXX_STANDARD 17)

IF(APPLE)
ENDIF()

IF(MINGW)
    set(SDL2_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/SDL2-win/x86_64-w64-mingw32/include/SDL2)
    set(SDL2_LIB_DIR ${PROJECT_SOURCE_DIR}/SDL2-win/x86_64-w64-mingw32/lib)
ENDIF()

include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})

add_executable(sdl_app main.cpp)

target_link_libraries(${PROJECT_NAME} mingw32 SDL2main SDL2)

