#include "SFML/Graphics.hpp"
#include<iostream>
#include<cstdlib>
#include<time.h>
#include<vector>
using namespace sf;
int Randf(int, int);
void initShape(RectangleShape& shape, Vector2f const& pos, Color const&  color);

int main()
{
	
	RenderWindow window(VideoMode(600, 600), "Bad Squerz");
	//set target Rrames pes second:
	window.setFramerateLimit(60);
	//Render objects :
	Event event;
	Vector2f startPos = Vector2f(50, 50);
	RectangleShape playerRect(Vector2f(50, 50));
	initShape(playerRect, startPos ,Color::Green);
	RectangleShape targetRect(Vector2f(50, 50));
	initShape(targetRect, Vector2f(400, 50), Color::Blue);
	RectangleShape badRect(Vector2f(50, 100));
	initShape(badRect, Vector2f(250, 50), Color::Red);





	while (window.isOpen())
	{
		//Handel events :
		while (window.pollEvent(event))
		{
			if (event.type == Event::EventType::Closed)
				window.close();

		}

		//Update Frame :
		
			if (Keyboard::isKeyPressed(Keyboard::Key::Up))
				playerRect.move(0, -5);
			if (Keyboard::isKeyPressed(Keyboard::Key::Down))
				playerRect.move(0, 5);
			if (Keyboard::isKeyPressed(Keyboard::Key::Right))
				playerRect.move(5,0);
			if (Keyboard::isKeyPressed(Keyboard::Key::Left))
				playerRect.move(-5,0);
		//target rich . win .exit.cout win 
			if (playerRect.getGlobalBounds().intersects(targetRect.getGlobalBounds())) 
			{
				std::cout<<"win !!!";
				window.close();
			}
		// Bad squer intersect. you lose . restart 
			if (playerRect.getGlobalBounds().intersects(badRect.getGlobalBounds()))
			{
				std::cout << "lose !!!\n Try again... \n\n";
				playerRect.setPosition(startPos);
				badRect.setPosition(Vector2f(100, 50));
			}
		// move bad squer 
			badRect.move((playerRect.getPosition().x-badRect.getPosition().x)*0.01,(playerRect.getPosition().y-badRect.getPosition().y)*0.01 );
		
		//Render Frame :
		
		window.clear(Color::Black);
		window.draw(badRect);
		window.draw(targetRect);
		window.draw(playerRect);
		window.display();
	}
	return 0;
}


int Randf(int a, int b)
{
	//sort a , b
	int temp;
	if (a > b)
	{
		temp = a;
		a = b;
		b = temp;
	}
	srand(rand() + time(0));
	return (rand()%(b-a))+a;
}

void initShape(RectangleShape& shape, Vector2f const& pos, Color const&  color)
{
	shape.setFillColor(color);
	shape.setPosition(pos);
	shape.setOrigin(shape.getSize() * 0.5f);
}


