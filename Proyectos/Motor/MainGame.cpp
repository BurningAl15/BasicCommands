#include "MainGame.h"
#include <iostream>
using namespace std;

//Initialize the window size for the game 
//(could be improved to multiple screens adaptability with some conditions)
MainGame::MainGame(): window(nullptr),width(1440),
					height(720),
					gameState(GameState::PLAY)
{
	/*window = nullptr;
	width = 800;
	height = 600;
	gameState = GameState::PLAY;*/
}

MainGame::~MainGame() {
}

void MainGame::init() {
	//Needed to initialize sdl
	SDL_Init(SDL_INIT_EVERYTHING);
	//Initialize the window
	//(name,x,y,w,h,UIint32 flag
	window =
		SDL_CreateWindow(
			//Window Name
			"Holi :D",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			width,
			height,
			SDL_WINDOW_OPENGL
		);
	//Check if window is still null
	if (window == nullptr) {
		//secayo
	}

	SDL_GLContext glContext =
		SDL_GL_CreateContext(window);
	
	/*GLenum error = glewInit();
	if (error != GLEW_OK) {
		//se cayo
	}*/
	
	//Create the double buffer
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	//Set color in the window to blue
	//(R,G,B,A)
	//(1,1,1,1) -> White
	//(0,0,0,1) -> Black
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
}

void MainGame::run() {
	init();
	update();
}

void MainGame::draw() {
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//se dibujaran los elementos en pantalla
	SDL_GL_SwapWindow(window);
}

void MainGame::update() {
	//while gamestate is not exit, game continues
	//In this case can get input and draws in screen
	while (gameState != GameState::EXIT)
	{
		processInput();
		draw();
	}
}

void MainGame::processInput()
{
	//Aparently, SDL manages the input of this engine
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type)
		{
		case SDL_QUIT:
			gameState = GameState::EXIT;
			break;
		case SDL_MOUSEBUTTONDOWN:
			cout
				<< "pos x " << event.motion.x
				<< " pos y " << event.motion.y
				<< endl;
			mousePress(event.button);
			break;
		case SDL_MOUSEMOTION:
			//If you move mouse over the window, then the position 
			//becomes an output in format (pos X: xVal,pos Y: yVal)
		
			//cout
			//	<< "pos x " << event.motion.x
			//	<< " pos y " << event.motion.y
			//	<< endl;
			break;
		}
	}
}

void MainGame::mousePress(SDL_MouseButtonEvent& button)
{
	//Here i mapped left and right buttons from mouse
	//Thinking in improve this to gamepad use
	if (button.button == SDL_BUTTON_LEFT)
	{
		cout<<"Im left"<< endl;
	}
	else if (button.button == SDL_BUTTON_RIGHT)
	{
		cout<< "Im right"<< endl;
	}
}

