#pragma once

#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/System/Vector2.hpp"
#include <memory>

struct Apple {
  Apple();
  void SetApplePosition(const sf::Vector2f& new_position);

  sf::CircleShape shape_;
  std::shared_ptr<sf::Vector2f> position_;

};