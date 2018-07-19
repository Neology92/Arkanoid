#pragma once
#include <SFML/Graphics.hpp>											//do��czenie modu�u grficznego 

using namespace sf;														//przestrzenie nazw...

class Ball : public sf::Drawable										//dziedziczenie publiczne clasy Ball z klasy Drawable
{
public:
	Ball(float t_x, float t_y);											//utworzenie konstruktora
	Ball() = delete;													//usuni�cie domy�lnego konstruktora
	~Ball() = default;													//ustawienie destruktora na domy�lny

	void update();														//utworzenie metody do poruszania pi�k�

	void moveUp();														//metody do zmieniania kierunku poruszania sie pi�ki
	void moveDown();
	void moveRight();
	void moveLeft();

	Vector2f getPosition();

	float left();														//mertody sprwdzaj�ce gdzie znajduje si� dana cz�� pi�ki
	float right();
	float top();
	float bottom();
private:
	CircleShape shape;													//utworzenie obiektu shape klasy Circleshape (daje pi�ce kr�g�o�ci ^^)
	const float ballRadius{ 10.0f };									//promie� pi�ki
	const float ballVelocity{ 5.0f };									//pr�dko�� poruszania si� pi�ki
	Vector2f velocity{ ballVelocity, -ballVelocity };					//utworznie wektor�w (x i y) poruszania si� pi�ki r�wnych powy�szej pr�dko�ci 
	void draw(RenderTarget& target, RenderStates state) const override; //w sumie to nwm...
};

