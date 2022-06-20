#pragma once
#include <Windows.h>
#include <iostream>
#pragma comment(lib,"winmm.lib")
#include <mmsystem.h>;
#pragma region defalutScene
static std::string		_defalutScene = "�������������������������������������������������������\n"
"��                                                                                    ��                  ��\n"
"��                                                                                    ��                  ��\n"
"��                                                                                    ��                  ��\n"
"��                                                                                    ��                  ��\n"
"��                                                                                    ��                  ��\n"
"��                                                                                    ��                  ��\n"
"��                                                                                    ��                  ��\n"
"��                                                                                    ��                  ��\n"
"��                                                                                    ��                  ��\n"
"��                                                                                    ��                  ��\n"
"��                                                                                    ��                  ��\n"
"��                                                                                    ������������\n"
"��                                                                                    ��                  ��\n"
"��                                                                                    ��                  ��\n"
"��                                                                                    ��                  ��\n"
"��                                                                                    ��                  ��\n"
"��                                                                                    ��                  ��\n"
"��                                                                                    ��                  ��\n"
"��                                                                                    ��                  ��\n"
"��                                                                                    ��                  ��\n"
"��                                                                                    ��                  ��\n"
"�������������������������������������������������������\n";;
#pragma endregion
static bool		_isBossRoomOpen = false;
class System
{
public :

	// �ڿ� ... �߰��ؼ� �ؽ�Ʈ ����ϴ� �Լ�
	static void LodingText(std::string str)
	{
		for (int i = 0; i < 3; i++)
		{
			SetCursor(25, 10);
			str += ".";
			std::cout << str;
			Sleep(150);
			system("cls");
		}
	}
	// ȭ�� ����� �� ���ھ� ����ϴ� �Լ�
	static void PrintSleepTextWithCls(std::string str, int posX, int posY, int sleepTime)
	{
		system("cls");
		SetCursor(posX, posY);
		for (int i = 0; i < str.length(); i++)
		{
			std::cout << str[i];
			Sleep(sleepTime);
		}
	}
	// �� ���ھ� ����ϴ� �Լ�
	static void PrintSleepText(std::string str, int posX, int posY, int sleepTime)
	{
		SetCursor(posX, posY);
		for (int i = 0; i < str.length(); i++)
		{
			std::cout << str[i];
			Sleep(sleepTime);
		}
	}
	// Ŀ�� ��ġ ����
	static void SetCursor(int x, int y)
	{
		COORD pos = { x,y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}
	// �ζ� ��ȣ �����
	static void GetLottoNum(int *lottoNums)
	{
		srand(time(NULL));
		int lottoNum[4] = {0};
		int lotto = 0;
		bool canInsert = true;
		for (int i = 0; i < 4;)
		{
			lotto = 1 + rand() % 20;
			for (int j = 0; j < i; j++)
			{
				if (lottoNum[j] == lotto)
				{
					canInsert = false;
				}
			}
			if (canInsert)
			{
				lottoNum[i] = lotto;
				i++;
			}
		}
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 3 - i; j++)
			{
				if (lottoNum[j] > lottoNum[j+1])
				{
					std::swap(lottoNum[j], lottoNum[j+1]);
				}
			}
		}
		for (int i = 0; i < 4; i++)
		{
			lottoNums[i] = lottoNum[i];
		}

	}
	// Ȧ ¦ �����
	static int ZeroOrOne()
	{
		int zeroOrOne = 0;
		srand(time(NULL));
		zeroOrOne = rand() % 2;
		return zeroOrOne;
	}
	
private :
	
};