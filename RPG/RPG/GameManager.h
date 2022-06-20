#pragma once
#include "Scene.h"



class GameManager
{
public :

	void Init()
	{
		PlaySound(TEXT("title.wav"), 0, SND_ASYNC | SND_LOOP);
	}

	void Update()
	{
		scene.CurrentScene(_curruntScene);
		system("cls");
	}

	void Render()
	{
		//
	}
	
private :
	Scene	scene;
	int		_curruntScene = 0;
};