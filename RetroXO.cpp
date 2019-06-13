#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include "RetroXO.h"

using namespace std;

Game::Game() {

	playMenu();
	loadTextures();
	createMenu();
	menu();

}
int Game::playBGM() {

	if (!buffer.loadFromFile("Assets/bgm.ogg"))
		return -1;
	sound.setLoop(true);
	sound.setVolume(100);
	/*for (int i = 80; i >= 0; i--) {
		sound.setVolume(i+20);
		for (int j = 0; j <= 3000000; j++) {}
	}*/
	sound.setBuffer(buffer);
	sound.play();

}
int Game::playMenu() {
	if (!menuBuffer.loadFromFile("Assets/menu.ogg"))
		return -1;
	menuBGM.setLoop(true);
	menuBGM.setBuffer(menuBuffer);
	menuBGM.play();
}
void Game::loadTextures() {
	X.loadFromFile("Assets/X.png");
	O.loadFromFile("Assets/O.png");
	boardTexture.loadFromFile("Assets/board1.png");
	font.loadFromFile("PressStart2P.ttf");

	text.setFont(font);
	text.setString("RETRO X&O");
	text.setCharacterSize(96);
	text.setFillColor(sf::Color::White);
	text.setPosition(905, 20);

	gameTitle.setFont(font);
	gameTitle.setString("RETRO X&O");
	gameTitle.setCharacterSize(90);
	gameTitle.setFillColor(sf::Color::White);
	gameTitle.setPosition(0, 0);

	mNewGame.setFont(font);
	mNewGame.setString("New Game");
	mNewGame.setCharacterSize(48);
	mNewGame.setFillColor(sf::Color::White);
	mNewGame.setPosition(100, 180);

	mCredits.setFont(font);
	mCredits.setString("Credits");
	mCredits.setCharacterSize(48);
	mCredits.setFillColor(sf::Color::White);
	mCredits.setPosition(100, 360);

	showCredits.setFont(font);
	showCredits.setString("Game Design: Afaf \n\nCoding: Afaf\n\nMusic: ...\n\nAssistant: Haris\n\nFeaturing legends such as:\n\n Afaf\n\n Hasnain\n\n Afaf\n\n Haris\n\n Haris\n\n Malik ");
	showCredits.setCharacterSize(21);
	showCredits.setFillColor(sf::Color::White);
	showCredits.setPosition(100, 150);

	mExit.setFont(font);
	mExit.setString("Exit");
	mExit.setCharacterSize(48);
	mExit.setFillColor(sf::Color::White);
	mExit.setPosition(100, 540);

	gExit.setFont(font);
	gExit.setString("Esc to exit");
	gExit.setCharacterSize(32);
	gExit.setFillColor(sf::Color::White);
	gExit.setPosition(905, 740);

	playerWin.setFont(font);
	playerWin.setCharacterSize(36);
	playerWin.setFillColor(sf::Color::White);
	playerWin.setPosition(20, 20);

}
int Game::checkOption() {

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(mainScreen).x >= 100 && sf::Mouse::getPosition(mainScreen).x <= 480 && sf::Mouse::getPosition(mainScreen).y <= 220 && sf::Mouse::getPosition(mainScreen).y >= 180) {
		return 1;
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(mainScreen).x >= 100 && sf::Mouse::getPosition(mainScreen).x <= 445 && sf::Mouse::getPosition(mainScreen).y <= 410 && sf::Mouse::getPosition(mainScreen).y >= 350) {
		return 2;
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(mainScreen).x >= 100 && sf::Mouse::getPosition(mainScreen).x <= 300 && sf::Mouse::getPosition(mainScreen).y <= 590 && sf::Mouse::getPosition(mainScreen).y >= 530) {
		return 3;
	}

}
int Game::play() {


	window.draw(board);
	sf::RectangleShape rectangle(sf::Vector2f(20, 800));
	rectangle.setPosition(sf::Vector2f(850, 0));

	window.draw(rectangle);
	window.draw(text);
	window.draw(gExit);


	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(window).x >= 180 && sf::Mouse::getPosition(window).x <= 360 && sf::Mouse::getPosition(window).y <= 330 && sf::Mouse::getPosition(window).y >= 150) {

		if (player == 1 && flag[0] == 0) {
			flag[0] = player;
			player = 2;
		}
		else if (player == 2 && flag[0] == 0) {
			flag[0] = player;
			player = 1;
		}


	}
	else

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(window).x >= 360 && sf::Mouse::getPosition(window).x <= 540 && sf::Mouse::getPosition(window).y <= 330 && sf::Mouse::getPosition(window).y >= 150) {

			if (player == 1 && flag[1] == 0 && !checkWin()) {
				flag[1] = player;
				player = 2;
			}
			else if (player == 2 && flag[1] == 0 && !checkWin()) {
				flag[1] = player;
				player = 1;
			}
		}
		else

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(window).x >= 540 && sf::Mouse::getPosition(window).x <= 720 && sf::Mouse::getPosition(window).y <= 330 && sf::Mouse::getPosition(window).y >= 150) {
				if (player == 1 && flag[2] == 0 && !checkWin()) {
					flag[2] = player;
					player = 2;
				}
				else if (player == 2 && flag[2] == 0 && !checkWin()) {
					flag[2] = player;
					player = 1;
				}
			}
			else

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(window).x >= 180 && sf::Mouse::getPosition(window).x <= 360 && sf::Mouse::getPosition(window).y <= 510 && sf::Mouse::getPosition(window).y >= 330) {
					if (player == 1 && flag[3] == 0 && !checkWin()) {
						flag[3] = player;
						player = 2;
					}
					else if (player == 2 && flag[3] == 0 && !checkWin()) {
						flag[3] = player;
						player = 1;
					}

				}
				else

					if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(window).x >= 360 && sf::Mouse::getPosition(window).x <= 540 && sf::Mouse::getPosition(window).y <= 510 && sf::Mouse::getPosition(window).y >= 330) {
						if (player == 1 && flag[4] == 0 && !checkWin()) {
							flag[4] = player;
							player = 2;
						}
						else if (player == 2 && flag[4] == 0 && !checkWin()) {
							flag[4] = player;
							player = 1;
						}
					}
					else

						if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(window).x >= 540 && sf::Mouse::getPosition(window).x <= 720 && sf::Mouse::getPosition(window).y <= 510 && sf::Mouse::getPosition(window).y >= 330) {
							if (player == 1 && flag[5] == 0 && !checkWin()) {
								flag[5] = player;
								player = 2;
							}
							else if (player == 2 && flag[5] == 0 && !checkWin()) {
								flag[5] = player;
								player = 1;
							}
						}
						else

							if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(window).x >= 180 && sf::Mouse::getPosition(window).x <= 360 && sf::Mouse::getPosition(window).y <= 690 && sf::Mouse::getPosition(window).y >= 510) {
								if (player == 1 && flag[6] == 0 && !checkWin()) {
									flag[6] = player;
									player = 2;
								}
								else if (player == 2 && flag[6] == 0 && !checkWin()) {
									flag[6] = player;
									player = 1;
								}
							}
							else

								if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(window).x >= 360 && sf::Mouse::getPosition(window).x <= 540 && sf::Mouse::getPosition(window).y <= 690 && sf::Mouse::getPosition(window).y >= 510) {
									if (player == 1 && flag[7] == 0 && !checkWin()) {
										flag[7] = player;
										player = 2;
									}
									else if (player == 2 && flag[7] == 0 && !checkWin()) {
										flag[7] = player;
										player = 1;
									}
								}
								else

									if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(window).x >= 540 && sf::Mouse::getPosition(window).x <= 720 && sf::Mouse::getPosition(window).y <= 690 && sf::Mouse::getPosition(window).y >= 510) {
										if (player == 1 && flag[8] == 0 && !checkWin()) {
											flag[8] = player;
											player = 2;
										}
										else if (player == 2 && flag[8] == 0 && !checkWin()) {
											flag[8] = player;
											player = 1;
										}
									}

	if (flag[0] == 1) {
		piece[0].setTexture(X);
		piece[0].setPosition(180, 150);

		window.draw(piece[0]);
	}
	else if (flag[0] == 2) {
		piece[0].setTexture(O);
		piece[0].setPosition(180, 150);
		window.draw(piece[0]);
	}

	if (flag[1] == 1) {
		piece[1].setTexture(X);
		piece[1].setPosition(360, 150);
		window.draw(piece[1]);
	}
	else if (flag[1] == 2) {
		piece[1].setTexture(O);
		piece[1].setPosition(360, 150);
		window.draw(piece[1]);
	}
	if (flag[2] == 1) {
		piece[2].setTexture(X);
		piece[2].setPosition(540, 150);
		window.draw(piece[2]);
	}
	else if (flag[2] == 2) {
		piece[2].setTexture(O);
		piece[2].setPosition(540, 150);
		window.draw(piece[2]);
	}
	if (flag[3] == 1) {
		piece[3].setTexture(X);
		piece[3].setPosition(180, 330);
		window.draw(piece[3]);
	}
	else if (flag[3] == 2) {
		piece[3].setTexture(O);
		piece[3].setPosition(180, 330);
		window.draw(piece[3]);
	}
	if (flag[4] == 1) {
		piece[4].setTexture(X);
		piece[4].setPosition(360, 330);
		window.draw(piece[4]);
	}
	else if (flag[4] == 2) {
		piece[4].setTexture(O);
		piece[4].setPosition(360, 330);
		window.draw(piece[4]);
	}
	if (flag[5] == 1) {
		piece[5].setTexture(X);
		piece[5].setPosition(540, 330);
		window.draw(piece[5]);
	}
	else if (flag[5] == 2) {
		piece[5].setTexture(O);
		piece[5].setPosition(540, 330);
		window.draw(piece[5]);
	}
	if (flag[6] == 1) {
		piece[6].setTexture(X);
		piece[6].setPosition(180, 510);
		window.draw(piece[6]);
	}
	else if (flag[6] == 2) {
		piece[6].setTexture(O);
		piece[6].setPosition(180, 510);
		window.draw(piece[6]);
	}
	if (flag[7] == 1) {
		piece[7].setTexture(X);
		piece[7].setPosition(360, 510);
		window.draw(piece[7]);
	}
	else if (flag[7] == 2) {
		piece[7].setTexture(O);
		piece[7].setPosition(360, 510);
		window.draw(piece[7]);
	}
	if (flag[8] == 1) {
		piece[8].setTexture(X);
		piece[8].setPosition(540, 510);
		window.draw(piece[8]);
	}
	else if (flag[8] == 2) {
		piece[8].setTexture(O);
		piece[8].setPosition(540, 510);
		window.draw(piece[8]);
	}

	if (player == 1) {
		playerPiece.setString("X");
	}
	else if (player == 2) {
		playerPiece.setString("O");
	}

	window.draw(playerPiece);



	if (checkWin() == 1)
	{
		if (player == 1)
			playerWin.setString("O wins");
		else if (player == 2)
			playerWin.setString("X wins");

		window.draw(playerWin);

	}
	if (checkWin() == -1)
	{
		playerWin.setString("Game Drawn");
		window.draw(playerWin);


	}

	return 1;
}
int Game::checkWin() {
	int draw = 0;

	if (flag[0] == flag[1] && flag[1] == flag[2] && flag[0] != 0)
		return 1;

	else if (flag[3] == flag[4] && flag[4] == flag[5] && flag[3] != 0)
		return 1;

	else if (flag[6] == flag[7] && flag[7] == flag[8] && flag[6] != 0)
		return 1;

	else if (flag[0] == flag[3] && flag[3] == flag[6] && flag[0] != 0)
		return 1;

	else if (flag[1] == flag[4] && flag[4] == flag[7] && flag[1] != 0)
		return 1;

	else if (flag[2] == flag[5] && flag[5] == flag[8] && flag[2] != 0)
		return 1;

	else if (flag[0] == flag[4] && flag[4] == flag[8] && flag[0] != 0)
		return 1;

	else if (flag[2] == flag[4] && flag[4] == flag[6] && flag[2] != 0)
		return 1;

	else if (1) {
		for (int i = 0; i < 9; i++) {
			if (flag[i] != 0) {
				draw++;
			}
		}
		if (draw == 9)
			return -1;
		else
			return 0;
	}

}
void Game::newGame() {
	board.setTexture(boardTexture);
	board.setPosition(sf::Vector2f(150, 120));
	board.setScale(sf::Vector2f(1.5f, 1.5f));

	for (int i = 0; i < 10; i++) {
		piece[i].setScale(sf::Vector2f(.40f, .40f));
	}


	if (!font.loadFromFile("PressStart2P.ttf"))
	{
		cout << "Error loading font" << endl;
	}



	playerPiece.setFont(font);
	playerPiece.setCharacterSize(300);
	playerPiece.setFillColor(sf::Color::White);
	playerPiece.setPosition(950, 180);

}
void Game::createWindow() {

	window.create(sf::VideoMode(1280, 800), "Play TicTacToe");
}
void Game::createMenu() {

	mainScreen.create(sf::VideoMode(800, 800), "Play TicTacToe");
}
void Game::move() {
	int gameState = 0;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::Black);


		play();

		window.display();


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) 
			window.close();
			

	}

}
int Game::menu() {
	


	int flag = 0;
	int NGflag = 0;
	while (mainScreen.isOpen())
	{
		sf::Event event;
		while (mainScreen.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				mainScreen.close();
				return 0;
			}
		}

		mainScreen.clear(sf::Color::Black);

		mainScreen.draw(gameTitle);
		mainScreen.draw(mNewGame);
		mainScreen.draw(mCredits);
		mainScreen.draw(mExit);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(mainScreen).x >= 0 && sf::Mouse::getPosition(mainScreen).x <= 800 && sf::Mouse::getPosition(mainScreen).y <= 100 && sf::Mouse::getPosition(mainScreen).y >= 0) {
			int c = (int)rand() % 8;
			for (int i = 0; i <= 100000000; i++) {}
					switch (c)
					{
					case 0:
						gameTitle.setFillColor(sf::Color::Blue);
						mainScreen.draw(gameTitle);
						break;

					case 1:
						gameTitle.setFillColor(sf::Color::Green);
						mainScreen.draw(gameTitle);
						break;

					case 2:
						gameTitle.setFillColor(sf::Color::Red);
						mainScreen.draw(gameTitle);
						break;

					case 3:
						gameTitle.setFillColor(sf::Color::Magenta);
						mainScreen.draw(gameTitle);
						break;

					case 4:
						gameTitle.setFillColor(sf::Color::Yellow);
						mainScreen.draw(gameTitle);
						break;
					case 5:
						gameTitle.setFillColor(sf::Color::White);
						mainScreen.draw(gameTitle);
						break;
					case 6:
						gameTitle.setFillColor(sf::Color::Cyan);
						mainScreen.draw(gameTitle);
						break;
					case 7:
						gameTitle.setString("YOU WIN!!");
						mainScreen.draw(gameTitle);
						break;
					
					default:
						break;
					}

			
			}

		if (checkOption() == 1) {
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				mainScreen.clear();
				NGflag = 1;
			}
		}
		if (checkOption() == 2) {
			mainScreen.clear();
			menuBGM.setVolume(15);
			creditBuffer.loadFromFile("Assets/credits.ogg");
			credits.setBuffer(creditBuffer);
			credits.setVolume(100);
			credits.play();
			flag = 1;
		}
		if (checkOption() == 3) {
			mainScreen.clear();
			mainScreen.close();
		}

		if (flag == 1) {
			mainScreen.clear();
			mainScreen.draw(showCredits);
			
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
				mainScreen.clear();
				menuBGM.setVolume(100);
				for (int i = 50; i >= 0; i--) {
					credits.setVolume(i);
					for (int j = 0; j <= 1000000; j++) {}
				}
				menu();
				flag = 0;
				
			}
		}
		if (NGflag == 1) {
			if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				mainScreen.close();
				menuBGM.stop();
				playBGM();
				newGame();
				for (int i = 80; i >= 0; i--) {
					sound.setVolume(i + 20);
					for (int j = 0; j <= 5000000; j++) {}
				}

				createWindow();
				move();

			}
		}

		mainScreen.display();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			mainScreen.close();



	}


	return 1;
}
