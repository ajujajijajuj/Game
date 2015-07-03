#include "GameWindow.h"
#include "GameObject.h"
#include "GameAudio.h"

int screenWidth = 800;
int screenHeight = 600;

GameWindow* bis;
GameObject* mc;
int mX, mY, speed, gravity;
bool startGame, Kleft, Kright;

void GameSetup()
{
	mX = 0;
	mY = 0;
	Kleft = false;
	Kright = false;
	speed = 5;

	mc = new GameObject(bis->GetRenderer());
	mc->Load("source/GameProject/Pstand.png");
	mc->GenerateClip(10, 22);
	mc->width = 80;
	mc->height = 100;
	mc->x = 100;
	mc->y = 100;
	mc->SetTimeScale(0.8);
	mc->SetAnimation(0, 8);
	mc->Play();
}

void Start()
{
	GameSetup();
	startGame = true;
}

void Update()
{
	if(startGame)
	{
		int i;

		if(Kleft)
		{
			mX = -speed;
			mc->SetFlip(FLIP_HORIZONTAL);
		}
		else if (Kright)
		{
			mX = speed;
			mc->SetFlip(FLIP_NONE);
		}
		else if(!Kleft && !Kright)
		{
			mX = 0;
		}
	}

	mc->Render();
}

void Event()
{
}

void Close()
{
	delete mc;
	mc = NULL;

	delete bis;
	bis = NULL;
}

int main(int argc, char* argv[])
{
	bis = new GameWindow();

	if(!bis->CreateWindow("Sample Game", screenWidth, screenHeight))
	{
		cerr << "Can't Create GameWindow" << endl;
	}else{
		bis->Run((void*)&Start, (void*)&Update, (void*)&Event);
	}

	Close();

	return 0;
}