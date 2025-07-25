#pragma once

#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Vector2.hpp"
#include <SFML/Graphics.hpp>
#include <list>

class Game;

class Snake {
public:
  Snake();
  void AddElement();
  void MakeMove();
  void SetDirection(const sf::Vector2f& new_direction);
  
  const sf::Vector2f& GetHeadPosition();
  
  bool IsHit();

  void ShowSnake(sf::RenderWindow& window);

private:
  friend class Game;
  
  struct Body {
    sf::RectangleShape shape_;
    
    void SetBodyPosition(const sf::Vector2f& new_position);
  };


  void UpdatePosition(const sf::Vector2f& new_target, std::list<Body>::iterator& curr_elem);

  void InitSnake();

  std::list<Body> snake_;

  sf::Vector2f direction_;
};