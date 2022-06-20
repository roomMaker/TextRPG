#pragma once
#include "System.h"

class Monster
{

public :
	void SelectMonster()
	{
		srand(time(NULL));
		_randMonster = rand() % 10;
		if (_randMonster <= 3)
		{
			Slime();
		}
		else if (_randMonster <= 6)
		{
			Goblin();
		}
		else if (_randMonster <= 8)
		{
			Fairy();
		}
		else if (_randMonster <= 9)
		{
			PoisonSpider();
		}
	}
	void SelectRareMonster()
	{
		srand(time(NULL));
		_randMonster = rand() % 21;
		if (_randMonster <= 3)
		{
			Slime();
		}
		else if (_randMonster <= 7)
		{
			Goblin();
		}
		else if (_randMonster <= 11)
		{
			Fairy();
		}
		else if (_randMonster <= 14)
		{
			PoisonSpider();
		}
		else if (_randMonster <= 17)
		{
			Undead();
		}
		else if (_randMonster == 19 && _isBossRoomOpen == false)
		{
			system("cls");
			_isBossRoomOpen = true;
			System::PrintSleepText("탐색을 하던 도중 알 수 없는 공간을 발견하였다...", 20, 10, 50);
			System::PrintSleepText("보스룸이 개방되었습니다..!!", 25, 12, 50);
			Sleep(1000);
		}
		else if (_randMonster <= 19)
		{
			Dragon();
		}
	}
	void RandAttack()
	{
		int randAttack;
		srand(time(NULL));
		randAttack = rand() % 4;
		if (randAttack > 0)
		{
			Attack();
		}
		else
		{
			DoubleAttack();
		}
	}
	void Attack()
	{
		_isDoubleAttack = false;
		System::SetCursor(5, 20);
		std::cout << _name << "의 공격! " << _power << "의 데미지를 받았다!!";
	}
	void DoubleAttack()
	{
		_isDoubleAttack = true;
		System::SetCursor(5, 20);
		std::cout << _name << "의 강력한 공격! " << _power * 2 << "의 데미지를 받았다!!";
	}
	bool GetIsDoubleAttack()
	{
		return _isDoubleAttack;
	}
	void PlayerUsedSkill2()
	{
		System::SetCursor(5, 20);
		std::cout << _name << "의 공격! 가드에 막혀 데미지를 받지 않았다!!";
	}
	
	void PlayerUsedSkill4()
	{
		System::SetCursor(5, 20);
		int randAttack;
		srand(time(NULL));
		randAttack = rand() % 4;
		if (randAttack > 0)
		{
			std::cout << _name << "의 공격! 반사 가드에 의해 " << _power << "의 데미지를 입혔다!!";
			_hp -= _power;
		}
		else
		{
			std::cout << _name << "의 강력한 공격! 반사 가드에 의해 " << _power * 2 << "의 데미지를 입혔다!!";
			_hp -= _power;
		}
		
	}
	void AttactFromPlayer(int playerPower)
	{
		_hp -= playerPower;
	}
	int GetHp()
	{
		return _hp;
	}
	int GetGold()
	{
		return _gold;
	}
	int GetPower()
	{
		return _power;
	}
	std::string GetName()
	{
		return _name;
	}
	void Dead()
	{
		Player player;
		System::SetCursor(20, 15);
		std::cout << "승리!" << _gold << "G를 얻었습니다!";
	}
	void PrintMonsterInfo()
	{
		
		System::SetCursor(5, 2);
		std::cout << _name;
		System::SetCursor(5, 3);
		std::cout << "HP : " << _hp << "/" << _maxHp;
		System::SetCursor(5, 4);
		std::cout << "공격력 : " << _power;
	}
	void SetMonsterState(std::string str, int hp, int maxHp, int power, int gold)
	{
		_name = str;
		_hp = hp;
		_maxHp = maxHp;
		_power = power;
		_gold = gold;
	}
	void Slime()
	{
		SetMonsterState("슬라임", 20, 20, 5, 10);
	}
	void Goblin()
	{
		SetMonsterState("고블린", 50, 50, 10, 30);
	}
	void Fairy()
	{
		SetMonsterState("요정", 20, 20, 50, 50);
	}
	void PoisonSpider()
	{
		SetMonsterState("독 거미", 100, 100, 35, 100);
	}
	void Undead()
	{
		SetMonsterState("언데드", 200, 200, 50, 200);
	}
	void Dragon()
	{
		SetMonsterState("드래곤", 500, 500, 100, 500);
	}
	void Boss()
	{
		SetMonsterState("???", 1000, 1000, 200, 100000);
	}
private :
	int		_hp;
	int		_maxHp;
	int		_power;
	int		_gold;
	int		_randMonster;
	bool	_isDoubleAttack = false;
	std::string	_name;
};