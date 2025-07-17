#include "apple.h"

#include "SFML/Graphics/Color.hpp"
#include "constants.h"

Apple::Apple(): shape_({kAppleRadius}) {
  shape_.setFillColor(sf::Color::Green);
}