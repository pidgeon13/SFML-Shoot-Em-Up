#pragma once

#include "Character.h"
#include "Global.h"
#include "ListContainer.hpp"
#include <SFML/Graphics.hpp>
#include "Inputs.h"

class Game
{
  size_t m_score;
  enum States {
    PLAYING,
    PAUSED,
    DEAD
  };

  States m_currentState;

  Character m_player;
  ListContainer<Character> m_enemies;
  ListContainer<MovingCircle> m_projectiles;

  sf::Clock m_clock;
  sf::Text m_scoreText;
  sf::Font m_font;
  sf::Text m_pauseText;
  sf::Text m_deadText;
  sf::Text m_restartText;
  sf::RenderWindow m_window;

  KeyboardInputs m_previousInputs;

  void Draw();
  void DoGameLogic(float elapsedTime);
  void RestartGame();

public:
  Game();
  void DoLoop();
};

