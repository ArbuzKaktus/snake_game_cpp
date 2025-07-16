add_executable(
  ${PROJECT_NAME} main.cpp
)

target_link_libraries(
  ${PROJECT_NAME}
  PRIVATE
  sfml-graphics
  sfml-window
  sfml-system
  sfml-audio
  snake_lib
  apple_lib
)