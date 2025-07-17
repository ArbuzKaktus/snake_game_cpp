#include "game.h"

#include "constants.h"

#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/Text.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Window/VideoMode.hpp"

#include <cstddef>
#include <cstdlib>
#include <stdexcept>
#include <string>
#include <vector>
#include <random>


Game::Game()
  : 
  timeout_        (kTimeout), 
  window_         (sf::RenderWindow{
              sf::VideoMode(kScreenWidth, kScreenHeight), 
            "snake_game"}),
  is_lose_(false),
  score_(0)
{
  InitApples();
  InitText();
}


void Game::InitApples() {
  for (size_t i = 0; i != kApllesCount; ++i) {

    SpawnApple();

  }
}


void Game::SpawnApple() {
  std::vector<sf::Vector2f> free_cells = GetFreeCells();
  if (free_cells.empty()) {
    return;
  }

  Apple apple;

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<size_t> dist(0, free_cells.size() - 1);

  size_t rand_ind = dist(gen);
  sf::Vector2f position = free_cells[rand_ind];
  apple.shape_.setPosition(position);

  apples_.push_back(apple);

}


std::vector<sf::Vector2f> Game::GetFreeCells() {
  std::vector<sf::Vector2f> free_cells;

  size_t x_cells = kScreenWidth / kCellSize;
  size_t y_cells = kScreenHeight / kCellSize;

  for (size_t x = 0; x != x_cells; ++x) {
    for (size_t y = 0; y != y_cells; ++y) {
      sf::Vector2f position = {static_cast<float>(x * kCellSize), static_cast<float>(y * kCellSize)};

      bool occupied = false;
      
      for (const auto& element : snake_.snake_) {
        if (element.shape_.getPosition() == position) {
          occupied = true;
          break;
        }
      }

      if (!occupied) {
        for (const auto& apple : apples_) {
          if (apple.shape_.getPosition() == position) {
            occupied = true;
            break;
          }
        }
      }
      
      if (!occupied) {
        free_cells.push_back(position);
      }
    }
  }

  return free_cells;
}

void Game::ShowApples() {
  for (auto& elem: apples_) {
    window_.draw(elem.shape_);
  }
}

void Game::ShowAll() {
  window_.clear();

  snake_.ShowSnake(window_);
  ShowApples();
  window_.draw(text_);

  window_.display();
}

void Game::EatApple(const std::vector<Apple>::iterator& apple) {
  apples_.erase(apple);
  snake_.AddElement();
  SpawnApple();
  ++score_;
  text_.setString("scores: " + std::to_string(score_));
  text_.setOrigin(text_.getLocalBounds().width, 0);
  text_.setPosition(window_.getSize().x - 10, 0);
}

bool Game::IsEaten() {
  sf::Vector2f current_position = snake_.GetHeadPosition();
  
  for (const auto& apple : apples_) {
    if (apple.shape_.getPosition() == current_position) {
      return true;
    }
  }
  return false;
}

bool Game::IsHit() {
  return snake_.IsHit();
}

void Game::HandleGameEvents() {
  sf::Vector2f current_position = snake_.GetHeadPosition();
  
  if (IsEaten()) {
    auto apple_it = std::find_if(apples_.begin(), apples_.end(),
      [&current_position](const auto& apple) {
        return apple.shape_.getPosition() == current_position;
      });
    
    if (apple_it != apples_.end()) {
      EatApple(apple_it);
    }
  } else if (IsHit()) {
    GameOver();
  }
}

void Game::HandleInput(const sf::Event& event) {
  std::map<sf::Keyboard::Key, sf::Vector2f> directions = 
  {{sf::Keyboard::W, {0,-1}},
  {sf::Keyboard::S, {0,1}},
  {sf::Keyboard::A, {-1,0}},
  {sf::Keyboard::D, {1,0}}};

  sf::Vector2f new_direction = directions[event.key.code];
  snake_.SetDirection(new_direction);

  if (event.key.code == sf::Keyboard::Enter && is_lose_) {
    Restart();
  }
}

void Game::InitText() {
  std::string fontPath = std::string(FONT_PATH) + "/Adbnorm.ttf";
  if (!font_.loadFromFile(fontPath)) {
    throw std::runtime_error("Failed To Load Font in " + fontPath);
  }

  text_ = {"scores: " + std::to_string(score_), font_, kFontSize};
  text_.setFillColor(sf::Color::Red);
  text_.setOrigin(text_.getLocalBounds().width, 0);
  text_.setPosition(window_.getSize().x - 10, 0);
}

void Game::GameOver() {
  is_lose_ = true;
  text_.setString("lose. Score: " + std::to_string(score_) + 
                  "\n Enter to Restart");
  text_.setOrigin(text_.getLocalBounds().width, 0);
  text_.setPosition(window_.getSize().x - 10, 0);
}

void Game::HandleEvent() {
  sf::Event event;
  while (window_.pollEvent(event)) {

    switch (event.type) {

      case sf::Event::Closed:
        window_.close();
        break;

      case sf::Event::KeyPressed:
        HandleInput(event);
        break;

      default:
        break;
    }
  }
}

void Game::HandleTimer() {
  if (timer_.getElapsedTime().asSeconds() >= timeout_) {
    if (!is_lose_) {
      snake_.MakeMove();
    }
    timer_.restart();
  }
}


void Game::Start() {
  while (window_.isOpen()) {
    HandleEvent();
    HandleGameEvents();
    HandleTimer();
    ShowAll();
  }
}


void Game::Restart() {

  apples_.clear();

  score_ = 0;
  is_lose_ = false;

  timer_.restart();
  
  snake_ = Snake();

  InitApples();
  InitText();
}