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


add_subdirectory(lib)
add_subdirectory(bin)
