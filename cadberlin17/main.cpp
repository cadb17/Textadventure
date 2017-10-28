#pragma once
#include "game.h"

void handleEvent(sf::Keyboard::Key &key, int &scene) {
	switch (key)
	{
	case sf::Keyboard::Left:
		--scene;
		break;
	case sf::Keyboard::Right:
		++scene;
		break;
	default:
		break;
	}
}

void draw(int &scene, sf::Time &t, sf::RenderWindow &window, sf::Texture &texture1, sf::Sprite &sprite1, sf::Texture &texture2, sf::Sprite &sprite2, sf::Font &header, sf::Font &standard, sf::Text &text1, sf::Text &text2, int &lastScene) {
	window.clear();
	std::string text;
	sf::RectangleShape black;
	int lScene = scene;
	double t2;
	switch (scene)
	{
	case 0:
		if (t.asMilliseconds() >= 5000) {
			++scene;
			t = t.Zero;
			return;
		}
		
			text1.setFont(header);
			text1.setPosition(window.getSize().x * 0.37f, window.getSize().y * 0.3f);
			text1.setCharacterSize(194);
			text1.setString("1792");
			text2.setFont(header);
			text2.setPosition(window.getSize().x * 0.2f, window.getSize().y * 0.5f);
			text2.setCharacterSize(160);
			text2.setString("Irgendwo in Paris");
		window.draw(text1);
		window.draw(text2);

		break;
	case 1:
		if (t.asMilliseconds() >= 17200) {
			++scene;
			t = t.Zero;
			t = t.Zero;
		}
		//if (scene != lastScene) {
			texture1.loadFromFile("brennendes_Haus.png");
			sprite1.setTexture(texture1);
		//}
		window.draw(sprite1);
		if (t.asMilliseconds() >= 15000) {
			t2 = t.asSeconds() - 15;
			t2 = 255 * t2 / 2;
			if (t2 > 255) {
				t2 = 255;
			}
			std::cout <<std::to_string(t2)<< std::endl;
			black.setFillColor(sf::Color(0, 0, 0, t2));
			black.setSize(sf::Vector2f(1920, 1080));
			window.draw(black);
		}
		break;
	case 2:
		if (t.asMilliseconds() >= 5000) {
			++scene;
			t = t.Zero;
			return;
		}
		if (scene != lastScene) {
			text1.setFont(header);
			text1.setPosition(window.getSize().x * 0.18f, window.getSize().y * 0.3f);
			text1.setCharacterSize(194);
			text1.setString("10. Januar 1797");
			text2.setFont(header);
			text2.setPosition(window.getSize().x * 0.34f, window.getSize().y * 0.5f);
			text2.setCharacterSize(160);
			text2.setString("Bei Paris");
		}
		window.draw(text1);
		window.draw(text2);
		break;
	case 3:
		if (t.asMilliseconds() >= 10000) {
			++scene;
			t = t.Zero;
			return;
		}
		if (scene != lastScene) {
			text2.setFont(standard);
			text2.setPosition(window.getSize().x * 0.1f, window.getSize().y * 0.1f);
			text2.setCharacterSize(45);

			text = "Hausmutter: \"Elise! Schrei nicht so herum. Andere wollen nachts schlafen!\"\n";
			text += "Elise: \"Bitte Mama, ich werde nicht wieder schreien. Ich versprechs!\"\n";
			text += "Hausmutter: \"Natürlich wirst du das! Aber im Keller!\"\n";
			text += "Elise schluchst.";
			text2.setString(text);
		}
		window.draw(text2);
		break;
	case 4:
		if (scene != lastScene) {
			texture1.loadFromFile("keller.png");
		}
		sprite1.setTexture(texture1);
		window.draw(sprite1);
		break;
	case 5:
	}
	window.display();
	lastScene = lScene;
}


int main() {
	sf::RenderWindow window;
	window.create(/*sf::VideoMode::getFullscreenModes().at(0)*/sf::VideoMode(1920,1080), "Textadventure @ Code and Design", sf::Style::Fullscreen);
	sf::Texture texture1;
	sf::Sprite sprite1;
	sf::Texture texture2;
	sf::Sprite sprite2;
	sf::Font headline;
	sf::Font stdfont;
	sf::Text text1;
	sf::Text text2;
	sf::Time timer;
	headline.loadFromFile("headline.ttf");
	stdfont.loadFromFile("times.ttf");


	sf::Event event;
	int currentScene = 0;
	int lastScene = 0;
	sf::Clock clock;
	while (window.isOpen()) {
		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (event.type == sf::Event::KeyReleased) {
				handleEvent(event.key.code, currentScene);
			}
			if (event.type == sf::Event::MouseButtonReleased) {
				++currentScene;
			}
			
		}
		timer += clock.restart();
		draw(currentScene, timer, window, texture1, sprite1, texture2, sprite2, headline, stdfont, text1, text2, lastScene);
	}
	return 0;

}

