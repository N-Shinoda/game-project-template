cmake_minimum_required(VERSION 3.25)

project(
    sdl3-game
    VERSION 0.1.0
    LANGUAGES CXX
)

# C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# dependencies
find_package(SDL3 REQUIRED CONFIG)

# executable
add_executable(${PROJECT_NAME}
    src/main.cpp
    src/game/game.cpp
)

# include directories
target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

# libraries
target_link_libraries(${PROJECT_NAME}
    PRIVATE
        SDL3::SDL3
)

# compiler warnings
if (CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
    target_compile_options(${PROJECT_NAME}
        PRIVATE
            -Wall
            -Wextra
            -Wpedantic
    )
elseif(MSVC)
    target_compile_options(${PROJECT_NAME}
        PRIVATE
            /W4
    )
endif()