cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 23)

project(
  snake
  LANGUAGES CXX
)

include(FetchContent)

FetchContent_Declare(
  sfml
  GIT_REPOSITORY https://github.com/SFML/SFML.git
  GIT_TAG 2.6.1
)

set(SFML_USE_STATIC_STD_LIBS OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(sfml)


set(FONT_PATH "${CMAKE_SOURCE_DIR}/font" CACHE STRING "Path to font")

file(COPY ${FONT_PATH} DESTINATION ${CMAKE_BINARY_DIR})




add_subdirectory(lib)
add_subdirectory(bin)
