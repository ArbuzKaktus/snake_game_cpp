#include "apple.h"

#include "constants.h"

#include "SFML/System/Vector2.hpp"
#include <memory>

Apple::Apple(): shape_({kAppleRadius}) {
  position_ = std::make_shared<sf::Vector2f>(shape_.getPosition());
}

void Apple::SetApplePosition(const sf::Vector2f& new_position) {
  shape_.setPosition(new_position);
  *position_ = new_position;
}