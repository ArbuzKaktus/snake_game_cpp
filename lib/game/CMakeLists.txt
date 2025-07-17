add_library(
  game_lib
  STATIC
  game.h
  game.cpp
)


target_link_libraries(
  game_lib
  PRIVATE
  sfml-graphics
  sfml-window
  sfml-system
  sfml-audio
  snake_lib
  apple_lib
)

target_include_directories(game_lib PRIVATE ${CMAKE_SOURCE_DIR}/lib)

target_compile_definitions(game_lib PRIVATE "FONT_PATH=\"${FONT_PATH}\"")