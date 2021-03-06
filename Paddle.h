#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;
using namespace std;

class Paddle : public sf::Drawable
{
public:
	Paddle(float t_x, float t_y);

	Paddle() = delete;
	~Paddle() = default;

	void update();

	Vector2f getPosition();

	float left();
	float right();
	float top();
	float bottom();

private:
	RectangleShape shape;
	const float paddleWidth{ 80.0f };
	const float paddleHeight{ 20.0f };
	const float paddleVelocity{ 6.0f };
	Vector2f velocity{ paddleVelocity, 0 };
	void draw(RenderTarget& target, RenderStates state) const override;
};

