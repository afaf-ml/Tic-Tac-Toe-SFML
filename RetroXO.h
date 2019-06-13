#ifndef RETROXO_H
#define RETROXO_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>


class Game {

private:
	int menuOption = 0;
	int player = 1;
	int flag[9] = { 0 };
	sf::SoundBuffer buffer;
	sf::SoundBuffer menuBuffer;
	sf::SoundBuffer creditBuffer;
	sf::Sound sound;
	sf::Sound menuBGM;
	sf::Sound credits;
	sf::Texture boardTexture;
	sf::Texture X;
	sf::Texture O;
	sf::Sprite board;
	sf::Sprite piece[9];
	sf::Text text;
	sf::Text gameTitle;
	sf::Text mNewGame;
	sf::Text mCredits;
	sf::Text showCredits;
	sf::Text mExit;
	sf::Text gExit;
	sf::Text playerWin;
	sf::Text playerPiece;
	sf::Font font;
	sf::RenderWindow mainScreen;
	sf::RenderWindow window;

public:

	Game();
	int playBGM();
	int playMenu();
	void loadTextures();
	int checkOption();
	int play();
	int checkWin();
	void newGame();
	void createWindow();
	void createMenu(); 
	void move();
	int menu();

};

#endif
