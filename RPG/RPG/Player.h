#pragma once
#include "System.h"
using namespace std;
class Player
{
public :
	void SetName(string name)
	{
		_name = name;
	}
	string GetName()
	{
		return _name;
	}
	void Attack()
	{
		System::SetCursor(5, 18);
		cout << _name <<"�� ����! " << _power << "�� �������� �־���!!";

	}
	void DrinkPotion(int potion)
	{
		switch (potion)
		{
		case 1:
			System::SetCursor(5, 18);
			cout << _name << "�� HP���� ���! ü���� 25�ۼ�Ʈ ȸ���˴ϴ�";
			_hp += _maxHp / 4;
			Sleep(1000);
			if (_hp > _maxHp) _hp = _maxHp;
			break;
		case 2:
			System::SetCursor(5, 18);
			cout << _name << "�� MP���� ���! ������ 25�ۼ�Ʈ ȸ���˴ϴ�";
			_mp += _maxMp / 4;
			Sleep(1000);
			if (_mp > _maxMp) _mp = _maxMp;
			break;
		default:
			break;
		}
	}
	bool Skill1()
	{
		if (_mp < 40)
		{
			System::PrintSleepText("������ �����մϴ�", 5, 18, 20);
			return false;
		}
		System::SetCursor(5, 18);
		cout << _name << "�� ����ġ! " << _power * 2 << "�� �������� �־���!!";
		_mp -= 40;
		return true;
	}
	bool Skill2()
	{
		if (_mp < 40)
		{
			System::PrintSleepText("������ �����մϴ�", 5, 18, 20);
			return false;
		}
		System::SetCursor(5, 18);
		cout << _name << "�� ����� ����, ���� �� ü���� 10% ȸ���մϴ�";
		_mp -= 40;
		_hp += _maxHp / 10;
		if (_hp > _maxHp) _hp = _maxHp;
		return true;
	}
	void Skill3()
	{
		System::SetCursor(5, 18);
		cout << _name << "�� �Ƹ޸�ī�� �帵ŷ, ������ ȸ���Ǿ���";
		_mp += 50;
		if (_mp > _maxMp) _mp = _maxMp;
	}
	bool Skill4()
	{
		if (_mp < 100)
		{
			System::PrintSleepText("������ �����մϴ�", 5, 20, 20);
			return false;
		}
		System::SetCursor(5, 18);
		cout << _name << "�� �ݻ簡��! ���ظ� �ݻ��մϴ�";
		_mp -= 100;
		return true;
	}
	int UsingSkill()
	{
		
		System::SetCursor(60, 10);
		cout << "1. �� ��ġ";
		System::SetCursor(60, 12);
		cout << "2. ����� ����";
		System::SetCursor(60, 14);
		cout << "3. �Ƹ޸�ī�� ����";
		System::SetCursor(60, 16);
		cout << "4. �ݻ� ����";
		System::SetCursor(60, 18);
		cout << "5. ��ų�� ������� �ʴ´�";

		System::SetCursor(5, 23);
		cout << "1. �� ��ġ";
		System::SetCursor(5, 24);
		cout << "MP: 40 ���ݷ�X2�� �������� �ش�";
		System::SetCursor(50, 23);
		cout << "2. ����� ����";
		System::SetCursor(50, 24);
		cout << "MP: 40 ������ ����, HP�� ��ü�� 10% ȸ���Ѵ�";
		System::SetCursor(5, 26);
		cout << "3. �Ƹ޸�ī�� ����";
		System::SetCursor(5, 27);
		cout << "MP�� 50 ȸ���Ѵ�";
		System::SetCursor(50, 26);
		cout << "4. �ݻ� ����";
		System::SetCursor(50, 27);
		cout << "MP : 100 ������ ����, �� ��ġ��ŭ �������� �����ش�";

		System::SetCursor(57, 20);
		cout << "����� ��ų�� ����ּ��� : ";

		cin >> _input;

		return _input;
	}
	void BuyHpPotion()
	{
		_haveHpPotion++;
	}
	void UseHpPotion()
	{
		_haveHpPotion--;
	}
	void BuyMpPotion()
	{
		_haveMpPotion++;
	}
	void UseMpPotion()
	{
		_haveMpPotion--;
	}
	// ü�� ���׷��̵� �� �߻��ϴ� ��� ó��
	void HpUpgradePay()
	{
		if (_money >= 100 * _hpUpgradeCount)
		{
			_money -= 100 * _hpUpgradeCount;
			_maxHp += 10;
			_hpUpgradeCount++;
		}
		else
			return;
	}
	// ���� ���׷��̵� �� �߻��ϴ� ��� ó��
	void MpUpgradePay()
	{
		if (_money >= 100 * _mpUpgradeCount)
		{
			_money -= 100 * _mpUpgradeCount;
			_maxMp += 10;
			_mpUpgradeCount++;
		}
		else
			return;
	}
	// ���ݷ� ���׷��̵� �� �߻��ϴ� ��� ó��
	void PowerUpgradePay()
	{
		if (_money >= 100 * _powerUpgradeCount)
		{
			_money -= 100 * _powerUpgradeCount;
			_power++;
			_powerUpgradeCount++;
		}
		else
			return;
	}
	// ü�� ���׷��̵� ��� ����
	int GetHpUpgradeCost()
	{
		return _hpUpgradeCount * 100;
	}
	// ���� ���׷��̵� ��� ����
	int GetMpUpgradeCost()
	{
		return _mpUpgradeCount * 100;
	}
	// ���ݷ� ���׷��̵� ��� ����
	int GetPowerUpgradeCost()
	{
		return _powerUpgradeCount * 100;
	}
	// ���Ϳ��� ���� ������ ó��
	void AttactFromMonster(int monsterPower)
	{
		_hp -= monsterPower;
	}
	int GetHp()
	{
		return _hp;
	}
	int GetMp()
	{
		return _mp;
	}
	int GetPower()
	{
		return _power;
	}
	void GetMoney(int money)
	{
		_money += money;
	}
	bool Pay(int payMoney)
	{
		if (_money >= payMoney)
		{
			_money -= payMoney;
			return true;
		}
		else
		{
			return false;
		}
	}
	void Die()
	{
		_hp = _maxHp / 10;
		_mp = _maxMp / 10;
	}
	void Rest()
	{
		_hp = _maxHp;
		_mp = _maxMp;
	}
	void PrintState()
	{
		System::SetCursor(90, 1);
		cout << "Name : " << _name;
		System::SetCursor(90, 3);
		cout << "HP : " << _hp << "/" << _maxHp;
		System::SetCursor(90, 4);
		cout << "MP : " << _mp << "/" << _maxMp;
		System::SetCursor(90, 5);
		cout << "���ݷ� : " << _power;
		System::SetCursor(90, 7);
		cout << "������ : " << _money << "G";
		System::SetCursor(90, 9);
		cout << "HP ���� : " << _haveHpPotion << " ��";
		System::SetCursor(90, 10);
		cout << "MP ���� : " << _haveMpPotion << " ��";
	}
private :
	int		_input;
	int		_maxHp = 100;
	int		_hp = 100;
	int		_power = 5;
	int		_maxMp = 100;
	int		_mp = 100;

	int		_hpUpgradeCount = 1;
	int		_mpUpgradeCount = 1;
	int		_powerUpgradeCount = 1;

	int		_haveHpPotion = 0;
	int		_haveMpPotion = 0;

	int		_money = 100;
	int		_skill;
	string		_name;
};