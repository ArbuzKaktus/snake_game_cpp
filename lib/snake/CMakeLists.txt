add_library(snake_lib STATIC snake.h snake.cpp)

target_link_libraries(
  snake_lib
  PRIVATE
  sfml-graphics
  constants_lib
)

target_include_directories(snake_lib PRIVATE ${CMAKE_SOURCE_DIR}/lib)