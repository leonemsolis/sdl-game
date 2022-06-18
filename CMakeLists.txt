cmake_minimum_required(VERSION 3.22)
project(sdl_app)
set(CMAKE_CXX_STANDARD 17)

IF(APPLE)
    INCLUDE(FindPkgConfig)
    PKG_SEARCH_MODULE(SDL2 REQUIRED)
    PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED)
    set(OTHER_LIBS ${PROJECT_SOURCE_DIR}/lib)

    INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR} ${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS} ${OTHER_LIBS})

    add_executable(sdl_app src/main.cpp)

    target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY} ${SDL2IMAGE_LIBRARIES})
ENDIF()

IF(MINGW)
    set(SDL2_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/SDL2-win/include/SDL2)
    set(SDL2_LIB_DIR ${PROJECT_SOURCE_DIR}/SDL2-win/lib)
    set(OTHER_LIBS ${PROJECT_SOURCE_DIR}/lib)
    include_directories(${SDL2_INCLUDE_DIR} ${OTHER_LIBS})
    link_directories(${SDL2_LIB_DIR})
    add_executable(sdl_app src/main.cpp src/Game.cpp src/Game.h src/Input.cpp src/Input.h src/Constants.h)
    target_link_libraries(${PROJECT_NAME} mingw32 SDL2main SDL2 SDL2_image)
ENDIF()

