#pragma once

#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Vector2.hpp"
#include <SFML/Graphics.hpp>
#include <cstddef>
#include <forward_list>
#include <memory>
#include <unordered_map>

class Game;

class Snake {
public:
  Snake();
  void AddElement();
  void MakeMove();
  void SetDirection(const sf::Vector2f& new_direction);

  std::vector<std::shared_ptr<sf::Vector2f>> GetAllElementsPosPtr();
  std::shared_ptr<sf::Vector2f> GetLastElementPosPtr();

private:
  friend class Game;

  struct Body {
    sf::RectangleShape shape_;
    std::shared_ptr<sf::Vector2f> position_;

    void SetBodyPosition(const sf::Vector2f& new_position);
  };

  void ShowSnake(sf::RenderWindow& window);

  void UpdatePosition(const sf::Vector2f& new_target, std::list<Body>::iterator& curr_elem);

  void InitSnake();

  std::list<Body> snake_;

  sf::Vector2f direction_;
};