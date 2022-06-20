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
		cout << _name <<"의 공격! " << _power << "의 데미지를 주었다!!";

	}
	void DrinkPotion(int potion)
	{
		switch (potion)
		{
		case 1:
			System::SetCursor(5, 18);
			cout << _name << "의 HP포션 사용! 체력이 25퍼센트 회복됩니다";
			_hp += _maxHp / 4;
			Sleep(1000);
			if (_hp > _maxHp) _hp = _maxHp;
			break;
		case 2:
			System::SetCursor(5, 18);
			cout << _name << "의 MP포션 사용! 마나가 25퍼센트 회복됩니다";
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
			System::PrintSleepText("마나가 부족합니다", 5, 18, 20);
			return false;
		}
		System::SetCursor(5, 18);
		cout << _name << "의 강펀치! " << _power * 2 << "의 데미지를 주었다!!";
		_mp -= 40;
		return true;
	}
	bool Skill2()
	{
		if (_mp < 40)
		{
			System::PrintSleepText("마나가 부족합니다", 5, 18, 20);
			return false;
		}
		System::SetCursor(5, 18);
		cout << _name << "의 든든한 가드, 가드 후 체력을 10% 회복합니다";
		_mp -= 40;
		_hp += _maxHp / 10;
		if (_hp > _maxHp) _hp = _maxHp;
		return true;
	}
	void Skill3()
	{
		System::SetCursor(5, 18);
		cout << _name << "의 아메리카노 드링킹, 마나가 회복되었다";
		_mp += 50;
		if (_mp > _maxMp) _mp = _maxMp;
	}
	bool Skill4()
	{
		if (_mp < 100)
		{
			System::PrintSleepText("마나가 부족합니다", 5, 20, 20);
			return false;
		}
		System::SetCursor(5, 18);
		cout << _name << "의 반사가드! 피해를 반사합니다";
		_mp -= 100;
		return true;
	}
	int UsingSkill()
	{
		
		System::SetCursor(60, 10);
		cout << "1. 강 펀치";
		System::SetCursor(60, 12);
		cout << "2. 든든한 가드";
		System::SetCursor(60, 14);
		cout << "3. 아메리카노 섭취";
		System::SetCursor(60, 16);
		cout << "4. 반사 가드";
		System::SetCursor(60, 18);
		cout << "5. 스킬을 사용하지 않는다";

		System::SetCursor(5, 23);
		cout << "1. 강 펀치";
		System::SetCursor(5, 24);
		cout << "MP: 40 공격력X2의 데미지를 준다";
		System::SetCursor(50, 23);
		cout << "2. 든든한 가드";
		System::SetCursor(50, 24);
		cout << "MP: 40 공격을 막고, HP를 전체의 10% 회복한다";
		System::SetCursor(5, 26);
		cout << "3. 아메리카노 섭취";
		System::SetCursor(5, 27);
		cout << "MP를 50 회복한다";
		System::SetCursor(50, 26);
		cout << "4. 반사 가드";
		System::SetCursor(50, 27);
		cout << "MP : 100 공격을 막고, 그 수치만큼 데미지를 돌려준다";

		System::SetCursor(57, 20);
		cout << "사용할 스킬을 골라주세요 : ";

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
	// 체력 업그레이드 시 발생하는 비용 처리
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
	// 마나 업그레이드 시 발생하는 비용 처리
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
	// 공격력 업그레이드 시 발생하는 비용 처리
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
	// 체력 업그레이드 비용 리턴
	int GetHpUpgradeCost()
	{
		return _hpUpgradeCount * 100;
	}
	// 마나 업그레이드 비용 리턴
	int GetMpUpgradeCost()
	{
		return _mpUpgradeCount * 100;
	}
	// 공격력 업그레이드 비용 리턴
	int GetPowerUpgradeCost()
	{
		return _powerUpgradeCount * 100;
	}
	// 몬스터에게 받은 데미지 처리
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
		cout << "공격력 : " << _power;
		System::SetCursor(90, 7);
		cout << "소지금 : " << _money << "G";
		System::SetCursor(90, 9);
		cout << "HP 포션 : " << _haveHpPotion << " 개";
		System::SetCursor(90, 10);
		cout << "MP 포션 : " << _haveMpPotion << " 개";
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