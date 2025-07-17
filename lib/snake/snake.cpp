#include "snake.h"

#include "constants.h"

#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/System/Vector2.hpp"
#include <cstddef>


Snake::Snake(): direction_(kStartDirection) {
  InitSnake();
}

void Snake::MakeMove() {
  sf::Vector2f prev_target = (snake_.front().shape_.getPosition());
  sf::Vector2f new_position = prev_target + sf::Vector2f(direction_.x * kCellSize, direction_.y * kCellSize);

  if (new_position.x < 0) {
    new_position.x = kScreenWidth - kCellSize;
  } else if (new_position.x >= kScreenWidth) {
    new_position.x = 0;
  }
  
  if (new_position.y < 0) {
    new_position.y = kScreenHeight - kCellSize;
  } else if (new_position.y >= kScreenHeight) {
    new_position.y = 0;
  }
  
  snake_.front().SetBodyPosition(new_position);
  UpdatePosition(prev_target, ++snake_.begin());
}

bool Snake::IsHit() {
  sf::Vector2f current_position = GetHeadPosition();
  auto it = snake_.begin();
  ++it;
  while (it != snake_.end()) {
    if (it->shape_.getPosition() == current_position) {
      return true;
    }
    ++it;
  }
  
  return false;
}


void Snake::UpdatePosition(const sf::Vector2f& new_target, std::list<Body>::iterator& curr_elem) {
  if (curr_elem == snake_.end()) {
    return;
  }

  sf::Vector2f prev_position = (curr_elem->shape_.getPosition());
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
    position = (snake_.back().shape_.getPosition()) - sf::Vector2f(direction_.x * kCellSize, direction_.y * kCellSize);
  }

  sf::RectangleShape new_shape({kCellSize, kCellSize});

  new_shape.setFillColor(sf::Color::White);
  new_shape.setPosition(position);

  Body new_element(new_shape);

  snake_.push_back(new_element);
}


void Snake::Body::SetBodyPosition(const sf::Vector2f& new_position) {
  shape_.setPosition(new_position);
}


void Snake::ShowSnake(sf::RenderWindow& window){
  for (auto& elem: snake_) {

    window.draw(elem.shape_);

  }
}

const sf::Vector2f& Snake::GetHeadPosition() {
  return snake_.front().shape_.getPosition();
}


  void Snake::SetDirection(const sf::Vector2f& new_direction) {
    if (new_direction.x != -direction_.x && new_direction.y != -direction_.y) {

      direction_ = new_direction;
    
    }
  }