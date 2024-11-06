#include "MainMenu.h"
void MainMenu::init()
{
	window->create(VideoMode(800, 600), "Main Menu");
	if (!font.loadFromFile("Roboto-Medium.ttf"))
	{
		cout << "Can't load font" << endl;
	}
	options = { "Start", "Exit" };
	textPositions = { Vector2f(300, 250), Vector2f(300, 100) };
//	buttonPositions = { Vector2f(400, 250), Vector2f(400, 350) };
	texts.resize(options.size());
	for (int i = 0; i < options.size(); i++)
	{
		texts[i].setFont(font);
		texts[i].setString(options[i]);
		texts[i].setCharacterSize(24);
		texts[i].setFillColor(Color::Black);
		texts[i].setPosition(textPositions[i]);
	}
}

Button MainMenu::getButton(int index)
{
	return buttons[index];
}

MainMenu::MainMenu()
{

	window = new RenderWindow();
	Button startGame = Button::createButton(Vector2f(200, 100), Vector2f(300, 250), Color::Yellow, Color::Blue, Color::Green,
		[]() {}); // thay start bằng hàm vô thẳng vào game
	buttons.push_back(startGame);
	Button exit = Button::createButton(Vector2f(200, 100), Vector2f(300, 100), Color::Yellow, Color::Blue, Color::Green,
		[this]() {window->close(); }); //thay exit bằng hàm thoát game
	buttons.push_back(exit);
	init();
}

MainMenu::~MainMenu()
{
	delete[] window;
}

void MainMenu::loopEvents()
{
	Event event;
	while (window->pollEvent(event))
	{
		if (event.type == Event::Closed)
		{
			window->close();
		}
		for (int i = 0; i < buttons.size(); i++)
		{
			buttons[i].handleEvent(event, *window);
		}
	}
}

void MainMenu::drawMenu()
{
	window->clear();
	for (int i = 0; i < buttons.size(); i++)
	{
		buttons[i].draw(*window);
	}

	for (int i = 0; i < texts.size(); i++)
	{
		window->draw(texts[i]);
	}
	window->display();
}

void MainMenu::runMenu()
{
	while (window->isOpen())
	{
		loopEvents();
		drawMenu();
	}
}
