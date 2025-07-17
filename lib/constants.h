#pragma once

#include "SFML/System/Vector2.hpp"
#include <cstddef>

const size_t kScreenWidth = 800;
const size_t kScreenHeight = 600;
const sf::Vector2f kStartPosition(600, 400);
const sf::Vector2f kStartDirection(-1,0);
const size_t kCellSize = 40;
const size_t kInitialSnakeSize = 4;
const size_t kApllesCount = 5;
const float kAppleRadius = float(kCellSize) / 2;
const float kTimeout = 0.2f;
const size_t kFontSize = 30;