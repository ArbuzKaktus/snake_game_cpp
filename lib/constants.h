#pragma once

#include "SFML/System/Vector2.hpp"
#include <cstddef>

const sf::Vector2f kScreenSize(800,600);
const sf::Vector2f kStartPosition(300, 100);
const sf::Vector2f kStartDirection(-1,0);
const size_t kCellSize = 40;
const float kAppleRadius = float(kCellSize) / 2;
const size_t kInitialSnakeSize = 4;
const size_t kApllesCount = 5;