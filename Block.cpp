#include "stdafx.h"
#include "Block.h"


Block::Block(float t_x, float t_y, float t_width, float t_height)
{
	shape.setPosition(t_x,t_y);
	shape.setSize({t_width ,t_height });
	shape.setFillColor(Color::Yellow);
	shape.setOrigin(t_width / 2.f, t_height / 2.f);
}

void Block::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->shape, state);
}

void Block::update()
{
	if (isDestroyed())
	{

	}
}

float Block::left()
{
	return this->shape.getPosition().x - shape.getSize().x / 2.f;
}

float Block::right()
{
	return this->shape.getPosition().x + shape.getSize().x / 2.f;
}

float Block::top()
{
	return this->shape.getPosition().y - shape.getSize().y / 2.f;
}

float Block::bottom()
{
	return this->shape.getPosition().y + shape.getSize().y / 2.f;
}

Vector2f Block::getPosition()
{
	return shape.getPosition();
}

bool Block::isDestroyed()
{
	return this->destroyed;
}

void Block::destroy()
{
	this->destroyed = true;
}

Vector2f Block::getSize()
{
	return shape.getPosition();
}