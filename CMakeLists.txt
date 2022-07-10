cmake_minimum_required(VERSION 3.22)
project(sdl_app)
set(CMAKE_CXX_STANDARD 17)

IF(APPLE)
    INCLUDE(FindPkgConfig)
    PKG_SEARCH_MODULE(SDL2 REQUIRED)
    PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED)
    set(OTHER_LIBS ${PROJECT_SOURCE_DIR}/lib)

    INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/src/headers ${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS} ${OTHER_LIBS})

    add_executable(sdl_app src/sources/main.cpp)

    target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY} ${SDL2IMAGE_LIBRARIES})
ENDIF()

IF(MINGW)
    set(SDL2_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/SDL2-win/include/SDL2)
    set(SDL2_LIB_DIR ${PROJECT_SOURCE_DIR}/SDL2-win/lib)
    set(OTHER_LIBS ${PROJECT_SOURCE_DIR}/lib)
    include_directories(${PROJECT_SOURCE_DIR}/src/headers ${SDL2_INCLUDE_DIR} ${OTHER_LIBS})
    link_directories(${SDL2_LIB_DIR})
    add_executable(sdl_app src/sources/main.cpp src/sources/graphics.cpp src/headers/game.h src/sources/game.cpp src/headers/input.h src/sources/input.cpp)
    target_link_libraries(${PROJECT_NAME} mingw32 SDL2main SDL2 SDL2_image)
ENDIF()

