#include "stdafx.h"
#include "Ball.h"


Ball::Ball(float t_x, float t_y) //konstruktor
{
	shape.setPosition(t_x, t_y);
	shape.setRadius(this->ballRadius);
	shape.setFillColor(Color::White);
	shape.setOrigin(this->ballRadius, this->ballRadius); //ustwienie origina na œrodku pi³ki
}

void Ball::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->shape, state);
}

void Ball::update()
{
	shape.move(this->velocity);

	if (this->left() < 0)
	{
		this->moveRight();
	}
	else if (this->right() > 800)
	{
		this->moveLeft();
	}

	if (this->top() < 0)
	{
		this->moveDown();
	}
	else if (this->bottom() > 600)
	{
		this->moveUp();
	}
}

float Ball::left()
{
	return this->shape.getPosition().x - shape.getRadius();
}

float Ball::right()
{
	return this->shape.getPosition().x + shape.getRadius();
}

float Ball::top()
{
	return this->shape.getPosition().y - shape.getRadius();
}

float Ball::bottom()
{
	return this->shape.getPosition().y + shape.getRadius();
}

void Ball::moveUp()
{
	this->velocity.y = -ballVelocity;
}

void Ball::moveDown()
{
	this->velocity.y = ballVelocity;
}

void Ball::moveLeft()
{
	this->velocity.x = -ballVelocity;
}

void Ball::moveRight()
{
	this->velocity.x = ballVelocity;
}

Vector2f Ball::getPosition()
{
	return shape.getPosition();
}