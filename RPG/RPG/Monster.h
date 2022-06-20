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
			System::PrintSleepText("Ž���� �ϴ� ���� �� �� ���� ������ �߰��Ͽ���...", 20, 10, 50);
			System::PrintSleepText("�������� ����Ǿ����ϴ�..!!", 25, 12, 50);
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
		std::cout << _name << "�� ����! " << _power << "�� �������� �޾Ҵ�!!";
	}
	void DoubleAttack()
	{
		_isDoubleAttack = true;
		System::SetCursor(5, 20);
		std::cout << _name << "�� ������ ����! " << _power * 2 << "�� �������� �޾Ҵ�!!";
	}
	bool GetIsDoubleAttack()
	{
		return _isDoubleAttack;
	}
	void PlayerUsedSkill2()
	{
		System::SetCursor(5, 20);
		std::cout << _name << "�� ����! ���忡 ���� �������� ���� �ʾҴ�!!";
	}
	
	void PlayerUsedSkill4()
	{
		System::SetCursor(5, 20);
		int randAttack;
		srand(time(NULL));
		randAttack = rand() % 4;
		if (randAttack > 0)
		{
			std::cout << _name << "�� ����! �ݻ� ���忡 ���� " << _power << "�� �������� ������!!";
			_hp -= _power;
		}
		else
		{
			std::cout << _name << "�� ������ ����! �ݻ� ���忡 ���� " << _power * 2 << "�� �������� ������!!";
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
		std::cout << "�¸�!" << _gold << "G�� ������ϴ�!";
	}
	void PrintMonsterInfo()
	{
		
		System::SetCursor(5, 2);
		std::cout << _name;
		System::SetCursor(5, 3);
		std::cout << "HP : " << _hp << "/" << _maxHp;
		System::SetCursor(5, 4);
		std::cout << "���ݷ� : " << _power;
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
		SetMonsterState("������", 20, 20, 5, 10);
	}
	void Goblin()
	{
		SetMonsterState("���", 50, 50, 10, 30);
	}
	void Fairy()
	{
		SetMonsterState("����", 20, 20, 50, 50);
	}
	void PoisonSpider()
	{
		SetMonsterState("�� �Ź�", 100, 100, 35, 100);
	}
	void Undead()
	{
		SetMonsterState("�𵥵�", 200, 200, 50, 200);
	}
	void Dragon()
	{
		SetMonsterState("�巡��", 500, 500, 100, 500);
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