#pragma once

#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Text.hpp"
#include "SFML/System/Clock.hpp"
#include "SFML/System/Vector2.hpp"
#include <cstddef>
#include <vector>
#include "SFML/Window/Event.hpp"

#include "snake/snake.h"
#include "apple/apple.h"

class Game {
public:
  Game();
  void Start();
private:
  void ShowAll();

  void GameOver();
  void Restart();

  bool IsEaten();
  bool IsHit();

  void ShowApples();
  void EatApple(const std::vector<Apple>::iterator& apple);
  void SpawnApple();
  void InitApples();
  std::vector<sf::Vector2f> GetFreeCells();

  void HandleInput(const sf::Event& event);
  void HandleEvent();
  void HandleGameEvents();
  void HandleTimer();

  void InitText();

  
  std::vector<Apple> apples_;

  Snake snake_;

  
  sf::Clock timer_;
  sf::Font font_;
  sf::Text text_;
  const float timeout_;
  sf::RenderWindow window_;

  size_t score_;
  bool is_lose_;
};