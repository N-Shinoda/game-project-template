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

# game library
add_library(game
    src/game/game.cpp
)

target_include_directories(game
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(game
    PUBLIC
        SDL3::SDL3
)

# game executable
add_executable(${PROJECT_NAME}
    src/main.cpp
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        game
)

# compiler warnings
if (CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
    target_compile_options(${PROJECT_NAME}
        PRIVATE
            -Wall
            -Wextra
            -Wpedantic
    )

    target_compile_options(game
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

    target_compile_options(game
        PRIVATE
            /W4
    )
endif()

# GoogleTest
add_subdirectory(
    third_party/googletest
    ${CMAKE_BINARY_DIR}/googletest
)

enable_testing()

add_subdirectory(tests)