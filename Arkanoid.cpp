// Arkanoid.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

//wczytanie bibliotek i podłączenie plikow klas
#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Ball.h"
#include "Paddle.h"
#include "Block.h"

//przestrzenie nazw
using namespace sf;
using namespace std;

template <class T1, class T2>
bool isIntersecting(T1& A, T2& B)
{
	return A.right() >= B.left() && A.left() <= B.right()
		&& A.bottom() >= B.top() && A.top() <= B.bottom();
}

bool collisionTest(Paddle& paddle, Ball& ball)
{
	if (!isIntersecting(paddle, ball)) return false;

	if (ball.top() <= paddle.top())
	{
		ball.moveUp();
	}
	else if (ball.bottom() >= paddle.bottom())
	{
		ball.moveDown();
	}

	if (ball.left() <= paddle.left())
	{
		ball.moveLeft();
	}
	else if (ball.right() >= paddle.right())
	{
		ball.moveRight();
	}
	
}

bool collisionTest(Block& block, Ball& ball)
{
	if (!isIntersecting(block, ball)) return false;

	block.destroy();

	float overlapLeft{ ball.right() - block.left() };
	float overlapRight{ block.right() - ball.left() };

	float overlapTop{ ball.bottom() - block.top() };
	float overlapBottom{ block.bottom() - ball.top() };

	bool ballFromLeft(abs(overlapLeft) < abs(overlapRight));
	bool ballFromTop(abs(overlapTop) < abs(overlapBottom));

	float minOverlapX{ ballFromLeft ? overlapLeft : overlapRight };
	float minOverlapY{ ballFromTop ? overlapTop : overlapBottom };

		if (abs(minOverlapX) < abs(minOverlapY))
		{
			ballFromLeft ? ball.moveLeft() : ball.moveRight();

		}
		else
		{
			ballFromTop ? ball.moveUp() : ball.moveDown();
		}
}

int main()
{
	unsigned int height = 800, width = 600;

	Ball ball(400, 300);											//utworzenie obiektu klasy Ball
	Paddle paddle(400, 550);										//utworzenie obiektu klasy Paddle

	RenderWindow window{ VideoMode{height,width}, "Arcanoid" };		//ustalenie szerokości i wysokości okna
	window.setFramerateLimit(60);									//ilość klatek
	Event event;

	unsigned blocksX{ 10 }, blocksY{ 4 }, blockWidth{ 60 }, blockHeight{ 20 };

	vector<Block> blocks;

	for (int i = 0; i < blocksY; i++)
	{
		for (int j = 0; j < blocksX; j++)
		{
			blocks.emplace_back((j+1) * (blockWidth + 10), (i + 2) * (blockHeight + 5), blockWidth, blockHeight);
		}
	}

	while (true)													//główna pętla gry
	{
		window.clear(Color::Black);									//wyczyszczenie i wypełnienie okienka na czarno
		window.pollEvent(event);									//wzięcie eventu z okienkiem

		if (event.type == Event::Closed)							//zamknięcie okna
		{
			window.close();
			break;
		}

		ball.update();												//wywołanie metody poruszajacej piłką
		paddle.update();											//wywołanie metody poruszającej paletką
		collisionTest(paddle, ball);

		for (auto& block : blocks)
			if (collisionTest(block, ball)) break;

		auto iterator = remove_if(begin(blocks), end(blocks), [](Block& block) { return block.isDestroyed(); });
		blocks.erase( iterator , end(blocks) );

		window.draw(ball);											//narysowanie piłki na ekranie
		window.draw(paddle);										//nrysowanie paletki
		for (auto& block : blocks)
			window.draw(block);
		
		window.display();											//wyswietlenie wszystkiego od początku danej iteracji głównej pętli
	}

	return 0;
}

