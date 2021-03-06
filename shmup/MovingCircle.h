#pragma once

#include <SFML/Graphics.hpp>
#include <list>

class MovingCircle
{
public:
  enum class Alignment
  {
    GOOD,
    BAD
  };

  MovingCircle();
  MovingCircle(float xPos, float yPos, float size, float speed, float xComponent, float yComponent, int damage);
  sf::FloatRect GetRect() const;
  const sf::CircleShape& GetShape() const;
  sf::Vector2f GetPosition() const;
  void SetColor(const sf::Color& color);
  void SetSpeed(float speed);
  void SetDirection(sf::Vector2f directionIn);
  void SetAlignment(Alignment alignment);
  void SetPosition(sf::Vector2f position);
  Alignment GetAlignment() const;
  void Move(float time);
  void MoveAwayFrom(const MovingCircle& other);
  void Draw(sf::RenderWindow& window) const;
  void SetCanRemove(bool canRemove);
  bool GetCanRemove() const;
  int GetDamage() const;

  bool Hits(const MovingCircle& other);

  void Update();

protected:
  //This will be normalised by the class when setting it.
  sf::Vector2f m_direction;
  sf::CircleShape m_shape;
  Alignment m_alignment;
  bool m_canRemove;
  int m_damage;
  sf::Vector2f m_position;
  float m_speed;
  bool m_removeWhenHittingWall;

};
