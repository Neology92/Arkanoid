#pragma once
#include <SFML/Graphics.hpp>											//do³¹czenie modu³u grficznego 

using namespace sf;														//przestrzenie nazw...

class Ball : public sf::Drawable										//dziedziczenie publiczne clasy Ball z klasy Drawable
{
public:
	Ball(float t_x, float t_y);											//utworzenie konstruktora
	Ball() = delete;													//usuniêcie domyœlnego konstruktora
	~Ball() = default;													//ustawienie destruktora na domyœlny

	void update();														//utworzenie metody do poruszania pi³k¹

	void moveUp();														//metody do zmieniania kierunku poruszania sie pi³ki
	void moveDown();
	void moveRight();
	void moveLeft();

	Vector2f getPosition();

	float left();														//mertody sprwdzaj¹ce gdzie znajduje siê dana czœæ pi³ki
	float right();
	float top();
	float bottom();
private:
	CircleShape shape;													//utworzenie obiektu shape klasy Circleshape (daje pi³ce kr¹g³oœci ^^)
	const float ballRadius{ 10.0f };									//promieñ pi³ki
	const float ballVelocity{ 5.0f };									//prêdkoœæ poruszania siê pi³ki
	Vector2f velocity{ ballVelocity, -ballVelocity };					//utworznie wektorów (x i y) poruszania siê pi³ki równych powy¿szej prêdkoœci 
	void draw(RenderTarget& target, RenderStates state) const override; //w sumie to nwm...
};

