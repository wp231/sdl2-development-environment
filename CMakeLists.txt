cmake_minimum_required(VERSION 3.1)
project(game)

execute_process(
    COMMAND ${CMAKE_COMMAND} -E echo ${PROJECT_NAME}
    OUTPUT_FILE ${CMAKE_BINARY_DIR}/ProjectName.txt
)

# Source code files
file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "src/*.h")

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})

include(FindPkgConfig)

pkg_search_module(SDL2 REQUIRED sdl2)
pkg_search_module(SDL2_IMAGE REQUIRED SDL2_image)
pkg_search_module(SDL2_NET REQUIRED SDL2_net)
pkg_search_module(SDL2_TTF REQUIRED SDL2_ttf)
pkg_search_module(SDL2_MIXER REQUIRED SDL2_mixer)

include_directories(
    ${SDL2_INCLUDE_DIRS}
    ${SDL2_IMAGE_INCLUDE_DIR}
    ${SDL2_NET_INCLUDE_DIR}
    ${SDL2_TTF_INCLUDE_DIR}
    ${SDL2_MIXER_INCLUDE_DIR}
)

target_link_libraries(
    ${PROJECT_NAME}
    ${SDL2_LIBRARIES}
    ${SDL2_IMAGE_LIBRARIES}
    ${SDL2_NET_LIBRARIES}
    ${SDL2_TTF_LIBRARIES}
    ${SDL2_MIXER_LIBRARIES}
)

# Debug type for gdb
set(CMAKE_BUILD_TYPE Debug)
# Creat compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# Run File Path
# set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR})
