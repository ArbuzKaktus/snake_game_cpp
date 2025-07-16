add_library(constants_lib INTERFACE)

target_link_libraries(
  constants_lib
  INTERFACE
  sfml-graphics
  sfml-window
  sfml-system
  sfml-audio
)

target_include_directories(constants_lib INTERFACE ${CMAKE_SOURCE_DIR}/lib)
add_subdirectory(snake)
add_subdirectory(apple)
add_subdirectory(game)