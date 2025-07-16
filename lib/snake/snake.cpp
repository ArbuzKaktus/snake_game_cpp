#include "snake.h"

#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/System/Vector2.hpp"
#include "constants.h"
#include <cstddef>
#include <memory>
#include <vector>

Snake::Snake(): direction_(kStartDirection) {
  InitSnake();
}

void Snake::MakeMove() {
  sf::Vector2f prev_target = *(snake_.front().position_);
  sf::Vector2f new_position = prev_target + sf::Vector2f(direction_.x * kCellSize, direction_.y * kCellSize);
  snake_.front().SetBodyPosition(new_position);

  UpdatePosition(prev_target,++snake_.begin());
}

void Snake::UpdatePosition(const sf::Vector2f& new_target, std::list<Body>::iterator& curr_elem) {
  if (curr_elem == snake_.end()) {
    return;
  }

  sf::Vector2f prev_position = *(curr_elem->position_);
  curr_elem->SetBodyPosition(new_target);

  UpdatePosition(prev_position, ++curr_elem);
}

void Snake::InitSnake() {
  for (size_t i = 0; i != kInitialSnakeSize; ++i) {
    AddElement();
  }
}

void Snake::AddElement() {
  sf::Vector2f position;

  if (snake_.empty()) {
    position = kStartPosition;
  } else {
    position = *(snake_.back().position_) - sf::Vector2f(direction_.x * kCellSize, direction_.y);
  }

  sf::RectangleShape new_shape({kCellSize, kCellSize});
  new_shape.setPosition(position);
  Body new_element(new_shape, std::make_shared<sf::Vector2f>(position));
  snake_.push_back(new_element);
}

std::vector<std::shared_ptr<sf::Vector2f>> Snake::GetAllElementsPosPtr() {

  std::vector<std::shared_ptr<sf::Vector2f>> elements;

  for (auto& elem: snake_) {
    elements.push_back(elem.position_);
  }

  return elements;
}

std::shared_ptr<sf::Vector2f> Snake::GetLastElementPosPtr() {
  return snake_.back().position_;
}

void Snake::Body::SetBodyPosition(const sf::Vector2f& new_position) {
  *position_ = new_position;
  shape_.setPosition(new_position);
}

void Snake::ShowSnake(sf::RenderWindow& window){
  for (auto& elem: snake_) {

    window.draw(elem.shape_);

  }
}