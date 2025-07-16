add_library(apple_lib STATIC apple.h apple.cpp)

target_link_libraries(
  apple_lib
  PRIVATE
  sfml-graphics
  constants_lib
)

target_include_directories(apple_lib PRIVATE ${CMAKE_SOURCE_DIR}/lib)