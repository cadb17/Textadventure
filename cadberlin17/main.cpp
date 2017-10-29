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
	std::cout << std::to_string(scene) << std::endl;
}

inline void draw(int &scene, sf::Time &t, sf::RenderWindow &window, sf::Texture &texture1, sf::Sprite &sprite1, sf::Texture &texture2, sf::Sprite &sprite2, sf::Font &header, sf::Font &standard, sf::Text &text1, sf::Text &text2, int &lastScene, sf::Sound &sound, sf::SoundBuffer &sound_buffer) {
	window.clear();
	std::string text;
	sf::RectangleShape black;
	int lScene = scene;
	bool playSound = false;
	double t2;
	switch (scene)
	{
	case -1:
		if (scene != lastScene) {
			texture1.loadFromFile("brennendes_Haus.png");
			sprite1.setTexture(texture1);
			text1.setFont(header);
			text1.setPosition(window.getSize().x * 0.26f, window.getSize().y * 0.8f);
			text1.setCharacterSize(120);
			text1.setString("Press a key to start!");
		}
		window.draw(sprite1);
		window.draw(text1);
		break;
	case 0:
		if (t.asMilliseconds() >= 5000) {
			++scene;
			t = t.Zero;
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
		if (t.asMilliseconds() >= 17010) {
			++scene;
			t = t.Zero;
			return;
		}
		if (scene != lastScene) {
			sound_buffer.loadFromFile("sturm.ogg");
			sound.setBuffer(sound_buffer);
			playSound = 1;
			texture1.loadFromFile("brennendes_Haus.png");
			sprite1.setTexture(texture1);
		}
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
			text += "Elise schluchzt.";
			text2.setString(text);
		}
		window.draw(text2);
		break;
	case 4:
		if (t.asMilliseconds() >= 8010) {
			++scene;
			t = t.Zero;
			return;
		}
		if (scene != lastScene) {
			texture1.loadFromFile("keller_heller.png");

			sprite1.setTexture(texture1);
		}
		window.draw(sprite1);
		if (t.asMilliseconds() >= 6000) {
			t2 = t.asSeconds() - 6;
			t2 = 255 * t2 / 2;
			if (t2 > 255) {
				t2 = 255;
			}
			std::cout << std::to_string(t2) << std::endl;
			black.setFillColor(sf::Color(0, 0, 0, t2));
			black.setSize(sf::Vector2f(1920, 1080));
			window.draw(black);
		}
		break;
	case 5:
		if (scene != lastScene) {
			text2.setFont(standard);
			text2.setPosition(window.getSize().x * 0.05f, window.getSize().y * 0.1f);
			text2.setCharacterSize(45);

			text = "Wieso tut sie mir dass nur an?\n";
			text += "Ich verstehe es nicht!\n";
			text += "Und dieser Traum, er hört einfach nicht auf mich zu verfolgen...\n";
			text += "Ich wünschte... Nanu? Was ist denn das? Ein rostiger Schmuckkasten?!\n";
			text += "*Knirsch*\n";
			text += "Scheint so als wäre im Kasten Platz für zwei Medaillons, jedoch ist nur eines vorhanden.\n";
			text += "Im inneren des Medaillons ist ein Bild einer Dame, neben ihr ist gerade noch eine Schulter\n";
			text += "zu erkennen, allerdings fehlt die andere Hälfte.\n";
			text += "*Elise betrachtet das Bild näher*\n";
			text += "Was? Das kann nicht. Darf nicht. Kann einfach nicht sein, aber das ist vielleicht doch meine Mutter!";
			text2.setString(text);
			
		}
		window.draw(text2);
		break;
	case 6:
		if (t.asMilliseconds() >= 8010) {
			++scene;
			t = t.Zero;
			return;
		}
		if (scene != lastScene) {
			texture1.loadFromFile("Waisenhaus.png");

			sprite1.setTexture(texture1);
		}
		window.draw(sprite1);
		if (t.asMilliseconds() >= 6000) {
			t2 = t.asSeconds() - 6;
			t2 = 255 * t2 / 2;
			if (t2 > 255) {
				t2 = 255;
			}
			std::cout << std::to_string(t2) << std::endl;
			black.setFillColor(sf::Color(0, 0, 0, t2));
			black.setSize(sf::Vector2f(1920, 1080));
			window.draw(black);
		}
		break;
	case 7:
		if (scene != lastScene) {
			text2.setFont(standard);
			text2.setPosition(window.getSize().x * 0.05f, window.getSize().y * 0.1f);
			text2.setCharacterSize(45);

			text = "Ich kann einfach nicht mehr. Hier halte ich es keine Sekunde länger aus.\n";
			text += "Das ist doch kein Leben!\n";
			text += "Maman sagte immer: \"Vis la vie comme tu veux\" (Lebe das Leben, so wie du es möchtest)\n";
			text += "Es reicht mir jetzt, ich breche aus!\n";
			text += "Ich hänge das Medaillon besser um meinen Hals.\n";
			text += "Und nun keinen Mux machen, damit ich nicht erwischt werde.\n";
			text += "Es ist wirklich kalt hier draußen, ich spüre meine Finger kaum noch.\n";
			text += "Brrr\n";
			text2.setString(text);

		}
		window.draw(text2);
		break;

	case 8:
		if (t.asMilliseconds() >= 8010) {
			++scene;
			t = t.Zero;
			return;
		}
		if (scene != lastScene) {
			texture1.loadFromFile("gasse_1.png");

			sprite1.setTexture(texture1);
		}
		window.draw(sprite1);
		if (t.asMilliseconds() >= 6000) {
			t2 = t.asSeconds() - 6;
			t2 = 255 * t2 / 2;
			if (t2 > 255) {
				t2 = 255;
			}
			std::cout << std::to_string(t2) << std::endl;
			black.setFillColor(sf::Color(0, 0, 0, t2));
			black.setSize(sf::Vector2f(1920, 1080));
			window.draw(black);
		}
		break;

	case 14:
		t = t.Zero;
		++scene;
		break;
	case 15:
		if (scene != lastScene) {
			t = t.Zero;
			texture1.loadFromFile("Waisenhaus.png");
			sprite1.setTexture(texture1);
		}
		t2 = t.asSeconds();
			if (t2 <= 2) {
				
				std::cout << std::to_string(t.asSeconds()) << std::endl;
				t2 = 1 - t2 / 4;
				sprite1.setScale(sf::Vector2f(t2, t2));
			}
			else {
				if (t2 != 0.5) {
					t2 = 0.5;
					sprite1.setScale(sf::Vector2f(t2, t2));
				}
			}
			
			
		
		window.draw(sprite1);
		break;
	}
	window.display();
	if (playSound) {
		sound.play();
		playSound = 0;
	}
	lastScene = lScene;
}


int main() {
	sf::RenderWindow window;
	window.create(/*sf::VideoMode::getFullscreenModes().at(0)*/sf::VideoMode(1920,1080), "Textadventure @ Code and Design"/*, sf::Style::Fullscreen*/);
	sf::Texture texture1;
	sf::Sprite sprite1;
	sf::Texture texture2;
	sf::Sprite sprite2;
	sf::Font headline;
	sf::Font stdfont;
	sf::Text text1;
	sf::Text text2;
	sf::Time timer;
	sf::Sound sound;
	sf::SoundBuffer sound_buffer;

	headline.loadFromFile("headline.ttf");
	stdfont.loadFromFile("times.ttf");


	sf::Event event;
	int currentScene = -1;
	int lastScene = -2;
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
		draw(currentScene, timer, window, texture1, sprite1, texture2, sprite2, headline, stdfont, text1, text2, lastScene, sound, sound_buffer);
	}
	return 0;

}

