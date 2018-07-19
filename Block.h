#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;

class Block : public sf::Drawable
{
public:
	Block(float t_x, float t_y, float t_width, float t_height );

	Block() = delete;
	~Block() = default;

	void update();

	Vector2f getPosition();

	float right();
	float left();
	float top();
	float bottom();

	bool isDestroyed();
	void destroy();

	Vector2f getSize();

private:
	bool destroyed = false;
	RectangleShape shape;
	virtual void draw(RenderTarget& target, RenderStates state) const override;
};

