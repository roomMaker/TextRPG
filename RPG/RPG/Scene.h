#pragma once
#include <string>
#include "System.h"
#include "Player.h"
#include "Monster.h"


using namespace std;

class Scene
{
public :

	void CurrentScene(int currnetScene)
	{
		system("cls");
		switch (currnetScene)
		{
		case 0 :
			Title();
			break;
		case 100:
			Intro();
			break;
		case 1:
			Town();
			break;
		case 2:
			Shop();
			break;
		case 101 :
			BuyItem();
			break;
		case 102 :
			UpState();
			break;
		case 3:
			Gamble();
			break;
		case 301:
			Lotto();
			break;
		case 302:
			ZeroOrOne();
			break;
		case 4:
			Dungeon();
			break;
		case 5:
			Fight();
			break;
		case 6:
			BossFight();
			break;
		default:
			break;
		}
	}
	void SetCurruntScene(int sceneNum)
	{
		CurrentScene(sceneNum);
	}
private :
	void Title()
	{
		System::SetCursor(40, 3);
		cout << "---RPG---";
		System::SetCursor(40, 10);
		cout << "1. ����";
		System::SetCursor(40, 12);
		cout << "2. ����";
		System::SetCursor(20, 15);
		cout << "�����Ͻ÷��� 1�� �����Ͻ÷��� 2���� �����ּ��� : ";
		cin >> _input;
		if (_input == '1')
		{
			CurrentScene(100);
		}
		else if(_input == '2')
		{
			system("cls"); 
			System::SetCursor(32, 10);
			cout << "����!";
			System::SetCursor(32, 28);
			exit(0);
		}
	}
	void Intro()
	{
		string playerName , str = "�ȳ��ϼ���... ";
		System::PrintSleepText("����� �̸��� �Է��ϼ��� (�ѱ� 3, ���� 7�� �̳� ���� �Ұ�) : ", 10, 10, 30);
		cin >> playerName;
		player.SetName(playerName);
		str += player.GetName();
		str += ".....";
		System::PrintSleepTextWithCls(str, 20, 10, 40);
		Sleep(1000);
		CurrentScene(1);
	}
	void Town()
	{
		if (_playBackGroundSound == true)
		{
			PlaySound(TEXT("title.wav"), 0, SND_ASYNC | SND_LOOP);
			_playBackGroundSound = false;
		}
		System::LodingText("������ ���� ��");
		cout << _defalutScene;
		player.PrintState();
		System::SetCursor(40, 3);
		cout << "---����---";
		System::SetCursor(20, 6);
		cout << "1. �������� ����";
		System::SetCursor(20, 8);
		cout << "2. �缳 ���������� ����";
		System::SetCursor(20, 10);
		cout << "3. �������� ����";
		System::SetCursor(20, 12);
		cout << "4. �������� �޽��Ѵ� 20G";
		System::SetCursor(20, 14);
		cout << "������ �ұ�? : ";
		cin >> _input;
		if (_input == '1')
		{
			CurrentScene(2);
		}
		else if (_input == '2')
		{
			CurrentScene(3);
		}
		else if (_input == '3')
		{
			CurrentScene(4);
		}
		else if (_input == '4')
		{
			system("cls");
			System::PrintSleepText("�������� ǫ ����.....", 20, 10, 50);
			player.Rest();
			player.Pay(20);
			CurrentScene(1);
		}
		else
		{
			CurrentScene(1);
		}
	}
	void Shop()
	{
		System::LodingText("�������� ���� ��");
		cout << _defalutScene;
		player.PrintState();
		System::SetCursor(40, 3);
		cout << "---����---";
		System::SetCursor(20, 6);
		cout << "1. ������ ����";
		System::SetCursor(20, 8);
		cout << "2. �ɷ�ġ ��ȭ";
		System::SetCursor(20, 10);
		cout << "3. ������ ���ư���";
		System::SetCursor(20, 12);
		cout << "������ �ұ�? : ";
		cin >> _input;
		if (_input == '1')
		{
			CurrentScene(101);
		}
		else if (_input == '2')
		{
			CurrentScene(102);
		}
		else if (_input == '3')
		{
			CurrentScene(1);
		}
		else
		{
			CurrentScene(2);
		}

	}
	void BuyItem()
	{

		cout << _defalutScene;
		player.PrintState();
		System::SetCursor(35, 3);
		cout << "---������ ����---";
		System::SetCursor(20, 6);
		cout << "1. ü������ ���� 10G";
		System::SetCursor(20, 8);
		cout << "2. �������� ���� 10G";
		System::SetCursor(20, 10);
		cout << "3. �������� ���ư���";
		System::SetCursor(20, 12);
		cout << "������ �ұ�? : ";
		cin >> _input;
		if (_input == '1')
		{
			if (player.Pay(10))
				player.BuyHpPotion();

			CurrentScene(101);
		}
		else if (_input == '2')
		{
			if(player.Pay(10))
				player.BuyMpPotion();

			CurrentScene(101);
		}
		else if (_input == '3')
		{
			CurrentScene(2);
		}
		else
		{
			CurrentScene(101);
		}
	}
	void UpState()
	{

		cout << _defalutScene;
		player.PrintState();
		System::SetCursor(30, 3);
		cout << "---�ɷ�ġ ���׷��̵�---";
		System::SetCursor(20, 6);
		cout << "1. ü�� ���׷��̵� +10 HP " << player.GetHpUpgradeCost() << "G";
		System::SetCursor(20, 8);
		cout << "2. ���� ���׷��̵� +10 MP " << player.GetMpUpgradeCost() << "G";
		System::SetCursor(20, 10);
		cout << "3. ���ݷ� ���׷��̵� +1 ATK " << player.GetPowerUpgradeCost() << "G";
		System::SetCursor(20, 12);
		cout << "4. �������� ���ư���";
		System::SetCursor(20, 14);
		cout << "������ �ұ�? : ";
		cin >> _input;
		if (_input == '1')
		{
			player.HpUpgradePay();
			System::LodingText("ü�� ���׷��̵� ��");
			CurrentScene(102);
		}
		else if (_input == '2')
		{
			player.MpUpgradePay();
			System::LodingText("���� ���׷��̵� ��");
			CurrentScene(102);
		}
		else if (_input == '3')
		{
			player.PowerUpgradePay();
			System::LodingText("���ݷ� ���׷��̵� ��");
			CurrentScene(102);
		}
		else if (_input == '4')
		{
			CurrentScene(2);
		}
		else
		{
			CurrentScene(102);
		}
	}
	void Gamble()
	{
		PlaySound(TEXT("Dobak.wav"), 0, SND_ASYNC | SND_LOOP);
		System::LodingText("���������� ������");
		cout << _defalutScene;
		player.PrintState();

		System::SetCursor(35, 3);
		cout << "---������---";
		System::SetCursor(20, 6);
		cout << "1. �ζ�";
		System::SetCursor(20, 8);
		cout << "2. Ȧ ¦";
		System::SetCursor(20, 10);
		cout << "3. ������ ���ư���";
		System::SetCursor(20, 12);
		cout << "������ �ұ�? : ";
		cin >> _input;
		if (_input == '1')
		{
			CurrentScene(301);
		}
		else if (_input == '2')
		{
			CurrentScene(302);
		}
		else if (_input == '3')
		{
			_playBackGroundSound = true;
			CurrentScene(1);
		}
		else
		{
			CurrentScene(3);
		}
	}
	void Lotto()
	{
		System::LodingText("�� �濡 �λ�����..");
		cout << _defalutScene;
		player.PrintState();

		System::SetCursor(35, 3);
		cout << "---!!LOTTO!!---";
		System::SetCursor(20, 6);
		cout << "1. �ζ� ����";
		System::SetCursor(20, 8);
		cout << "2. ���������� ���ư���";
		System::SetCursor(20, 12);
		cout << "������ �ұ�? : ";
		cin >> _input;
		if (_input == '1')
		{
			system("cls");
			cout << _defalutScene;
			player.PrintState();
			System::PrintSleepText("���ϴ� �ݾ����� �����ؼ� ũ�� ���� �ĺ���!!", 5, 6, 0);
			System::PrintSleepText("1 ~ 20 ������ 4���� ��ȣ�� ���� ������� �Է���, ���ߴ� �����Դϴ�.\n", 5, 7, 0);
			System::PrintSleepText("���᰹�� : 0 ~ 1�� == ��\n", 5, 8, 0);
			System::PrintSleepText("���᰹�� : 2�� == ���űݾ� ��ȯ\n", 5, 9, 0);
			System::PrintSleepText("���᰹�� : 3�� == ���űݾ� X 10\n", 5, 10, 0);
			System::PrintSleepText("���᰹�� : 4�� == ���űݾ� X 100\n", 5, 11, 0);
			System::PrintSleepText("���� �ݾ��� �Է� �� �ּ��� : ", 5, 13, 20);
			cin >> _inputLotto;
			if (player.Pay(_inputLotto))
			{
				_lottoCorrectCount = 0;
				System::PrintSleepText("�ζ� ��ȣ�� �Է����ּ���(���� �� ���� ū �� �������, ����� ����) : ", 5, 15, 0);
				System::PrintSleepText(">>  ", 5, 17, 0);
				System::GetLottoNum(_getLottoNum);
				for (int i = 0; i < 4; i++)
				{
					cin >> _lottoNum[i];
				}

				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						if (_getLottoNum[i] == _lottoNum[j])
						{
							_lottoCorrectCount++;
						}
					}
				}
				for (int i = 0; i < 4; i++)
				{
					for (int j = i+1; j < 4; j++)
					{
						if (_lottoNum[i] == _lottoNum[j])
						{
							System::PrintSleepTextWithCls("�ߺ� �� ��ȣ�� �����ϴ±���..? �ٽ� �� �ּ���", 20, 10, 10);
							Sleep(1000);
							_lottoCorrectCount = 0;
							CurrentScene(301);
							return;
						}
					}
				}
				System::PrintSleepText(_lottoResult, 3, 4, 1);
				for (int i = 0; i < 4; i++)
				{
					System::SetCursor(10 + i * 3, 4);
					Sleep(1000);
					cout << _getLottoNum[i];
				}
				Sleep(1000);
				system("cls");
				switch (_lottoCorrectCount)
				{
				case 0:
					System::PrintSleepText("0�� ���߼̽��ϴ�.. �������� ���߸� ���� ��!", 20, 10, 2);
					break;
				case 1:
					System::PrintSleepText("1�� ���߼̽��ϴ�.. ���� ��������?", 20, 10, 2);
					break;
				case 2:
					System::PrintSleepText("2�� ���߼̽��ϴ�~ ������ �ʳ׿� ��", 20, 10, 2);
					player.GetMoney(_inputLotto);
					break;
				case 3:
					System::PrintSleepText("3�� ���߼̽��ϴ�!! �� ������ �ص� �� �����Ű���!", 20, 10, 2);
					player.GetMoney(_inputLotto * 10);
					break;
				case 4:
					System::PrintSleepText("�ζ� ��÷!!! ��û�� ����� ������!! 100�谡 ����˴ϴ�.", 20, 10, 2);
					player.GetMoney(_inputLotto * 100);
					break;
				default:
					break;
				}
			}
			else
			{
				System::PrintSleepTextWithCls("���� ���ڶ��ϴ�....", 20, 10, 2);
			}
			Sleep(1000);
			
			CurrentScene(301);
			return;
		}
		else if (_input == '2')
		{
			CurrentScene(3);
		}
		else
		{
			CurrentScene(301);
		}
	}
	void ZeroOrOne()
	{
		System::LodingText("Ȧ ¦ �������� ���� ��");
		cout << _defalutScene;
		player.PrintState();

		System::SetCursor(35, 3);
		cout << "---!!Ȧ ¦!!---";
		System::SetCursor(20, 6);
		cout << "1. Ȧ ¦ ����";
		System::SetCursor(20, 8);
		cout << "2. ���������� ���ư���";
		System::SetCursor(20, 12);
		cout << "������ �ұ�? : ";
		cin >> _input;

		if (_input == '1')
		{
			system("cls");
			cout << _defalutScene;
			player.PrintState();
			System::PrintSleepText("Ȧ¦�� �� ���缭 ���� �ҷ�����~!", 5, 6, 0);
			System::PrintSleepText("���� ��带 ���� �� 0 �Ǵ� 1�� �Է��ؼ� ���߸� ������� �ݾ��� Ŀ���ϴ�", 5, 7, 0);
			System::PrintSleepText("���� �� �ݾ��� �Է��ϼ��� >> :", 5, 15, 20);
			cin >> _zeroOnePay;
			if (player.Pay(_zeroOnePay))
			{
				while (1)
				{
					system("cls");
					System::SetCursor(5, 5);
					cout << "���� �ݾ� >> : " << _zeroOnePay;
					System::SetCursor(20, 15);
					cout << "0 �Ǵ� 1�� �Է��ϼ���, �׸� �ν÷��� 2�� �Է��ϼ��� >> : ";
					cin >> _inputZeroOrOne;
					if (_inputZeroOrOne == 2)
					{
						player.GetMoney(_zeroOnePay);
						break;
					}
					else if (System::ZeroOrOne() == _inputZeroOrOne)
					{
						System::PrintSleepTextWithCls("�����....����!!!", 20, 10, 100);
						_zeroOnePay += _zeroOnePay;
						Sleep(500);
						continue;
					}
					else
					{
						System::PrintSleepTextWithCls("�����... ����!!! �ƽ��׿�...", 20, 10, 100);
						Sleep(500);
						break;
					}
				}
			}
			else
			{
				System::PrintSleepTextWithCls("���� ���ڶ��ϴ�....", 20, 10, 2);
				Sleep(1000);
			}
			CurrentScene(3);
		}
		else if (_input == '2')
		{
			CurrentScene(3);
		}
		else
		{
			CurrentScene(302);
		}
		
	}
	void Dungeon()
	{
		System::LodingText("�������� ���ϴ� ��");
		cout << _defalutScene;
		player.PrintState();
		System::SetCursor(40, 3);
		cout << "---����---";
		System::SetCursor(20, 6);
		cout << "1. �ֺ��� Ž���Ѵ�";
		System::SetCursor(20, 8);
		cout << "2. ����� ����Ͽ� Ž���Ѵ� 10G (���� ���� ���� ���ɼ� ��)";
		if (_isBossRoomOpen == true)
		{
			System::SetCursor(20, 10);
			cout << "3. ������ ���ư���";
			System::SetCursor(20, 12);
			cout << "4. ���� �� ����";
			System::SetCursor(20, 14);
			cout << "������ �ұ�? : ";
		}
		else
		{
			System::SetCursor(20, 10);
			cout << "3. ������ ���ư���";
			System::SetCursor(20, 12);
			cout << "������ �ұ�? : ";
		}
		
		cin >> _input;
		if (_input == '1')
		{
			monster.SelectMonster();
			CurrentScene(5);
		}
		else if (_input == '2')
		{
			if (player.Pay(10))
				monster.SelectRareMonster();
			else
			{
				System::PrintSleepTextWithCls("���� ���ڶ��ϴ�... ����� ���� �ʰ� Ž���մϴ�...", 20, 10, 40);
				monster.SelectMonster();
			}
			CurrentScene(5);
		}
		else if (_input == '3')
		{
			CurrentScene(1);
		}
		else if (_input == '4' && _isBossRoomOpen == true)
		{
			monster.Boss();
			CurrentScene(6);
		}
		else
		{
			CurrentScene(4);
		}
	}
	void MonsterRandAttack()
	{
		if (monster.GetIsDoubleAttack())
		{
			player.AttactFromMonster(monster.GetPower() * 2);
		}
		else
		{
			player.AttactFromMonster(monster.GetPower());
		}
	}
	void Fight()
	{
		System::LodingText("Ž�� ��");
		System::PrintSleepTextWithCls("�߻��� "+ monster.GetName() + "�� ����!!!", 25, 10, 60);
		system("cls");
		while (monster.GetHp() > 0 && player.GetHp() > 0)
		{
			cout << _defalutScene;
			player.PrintState();
			monster.PrintMonsterInfo();
			System::SetCursor(40, 3);
			cout << "---����---";
			System::SetCursor(5, 10);
			cout << "1. �����Ѵ�";
			System::SetCursor(5, 12);
			cout << "2. ��ų���";
			System::SetCursor(5, 14);
			cout << "3. ���Ǽ���";
			System::SetCursor(5, 16);
			cout << "4. ��������";
			System::SetCursor(5, 18);
			cout << "������ �ұ�? : ";
			cin >> _input;
			if (_input == '1')
			{
				player.Attack(); 
				monster.AttactFromPlayer(player.GetPower());
				Sleep(1000);
				monster.RandAttack();
				MonsterRandAttack();
				Sleep(1000);

			}
			else if (_input == '2')
			{
				switch (player.UsingSkill())
				{
				case 1: 
					if (player.Skill1())
					{
						monster.AttactFromPlayer(player.GetPower() * 2);
						Sleep(1000);
						monster.RandAttack();
						MonsterRandAttack();
					}
					Sleep(1000);
					break;
				case 2: 
					if (player.Skill2())
					{
						Sleep(1000);
						monster.PlayerUsedSkill2();
					}
					Sleep(1000);
					break;
				case 3: 
					player.Skill3();
					monster.AttactFromPlayer(player.GetPower());
					Sleep(1000);
					monster.Attack();
					MonsterRandAttack();
					Sleep(1000);
					break;
				case 4: 
					if (player.Skill4())
					{
						Sleep(1000);
						monster.PlayerUsedSkill4();
					}
					Sleep(1000);
					break;
				case 5: 
					break;
				default:
					break;
				}
				Sleep(1000);
			}
			else if (_input == '3')
			{
				System::SetCursor(60, 14);
				cout << "1. HP ���� ����";
				System::SetCursor(60, 16);
				cout << "2. MP ���� ����";
				System::SetCursor(60, 18);
				cout << "3. ������ ������� �ʴ´�";
				System::SetCursor(57, 20);
				cout << "����� ������ ����ּ��� : ";

				cin >> _inputPotion;
				player.DrinkPotion(_inputPotion);
			}
			else if (_input == '4')
			{
				CurrentScene(4);
			}
			else
			{
				CurrentScene(5);
			}
			system("cls");
		}
		if (player.GetHp() <= 0)
		{
			System::PrintSleepTextWithCls("����� �׾����ϴ�... ü�°� ������ 10%�� �����˴ϴ�...", 15, 10, 20);
			Sleep(1000);
			player.Die();
			CurrentScene(4);
		}
		monster.Dead();
		player.GetMoney(monster.GetGold());
		Sleep(1500);
		CurrentScene(4);
	}
	void BossFight()
	{
		System::LodingText("���������� �̵� ��");
		System::PrintSleepTextWithCls("�δ��� ����� ��������...", 25, 10, 60);
		system("cls");
		while (monster.GetHp() > 0 && player.GetHp() > 0)
		{
			cout << _defalutScene;
			player.PrintState();
			monster.PrintMonsterInfo();
			System::SetCursor(40, 3);
			cout << "---���� ��---";
			System::SetCursor(5, 10);
			cout << "1. �����Ѵ�";
			System::SetCursor(5, 12);
			cout << "2. ��ų���";
			System::SetCursor(5, 14);
			cout << "3. ���Ǽ���";
			System::SetCursor(5, 16);
			cout << "4. ��������";
			System::SetCursor(5, 18);
			cout << "������ �ұ�? : ";
			cin >> _input;
			if (_input == '1')
			{
				player.Attack();
				monster.AttactFromPlayer(player.GetPower());
				Sleep(1000);
				monster.Attack();
				MonsterRandAttack();
				Sleep(1000);

			}
			else if (_input == '2')
			{
				switch (player.UsingSkill())
				{
				case 1:
					if (player.Skill1())
					{
						monster.AttactFromPlayer(player.GetPower() * 2);
						Sleep(1000);
						monster.RandAttack();
						MonsterRandAttack();
					}
					Sleep(1000);
					break;
				case 2:
					if (player.Skill2())
					{
						Sleep(1000);
						monster.PlayerUsedSkill2();
					}
					Sleep(1000);
					break;
				case 3:
					player.Skill3();
					monster.AttactFromPlayer(player.GetPower());
					Sleep(1000);
					monster.Attack();
					MonsterRandAttack();
					Sleep(1000);
					break;
				case 4:
					if (player.Skill4())
					{
						Sleep(1000);
						MonsterRandAttack();
						monster.PlayerUsedSkill4();
					}
					Sleep(1000);
					break;
				case 5:
					break;
				default:
					break;
				}
				Sleep(1000);
			}
			else if (_input == '3')
			{
				System::SetCursor(60, 14);
				cout << "1. HP ���� ����";
				System::SetCursor(60, 16);
				cout << "2. MP ���� ����";
				System::SetCursor(60, 18);
				cout << "3. ������ ������� �ʴ´�";
				System::SetCursor(57, 20);
				cout << "����� ������ ����ּ��� : ";

				cin >> _inputPotion;
				player.DrinkPotion(_inputPotion);
			}
			else if (_input == '4')
			{
				CurrentScene(4);
			}
			else
			{
				CurrentScene(6);
			}
			system("cls");
		}
		if (player.GetHp() <= 0)
		{
			System::PrintSleepTextWithCls("����� �׾����ϴ�... ü�°� ������ 10%�� �����˴ϴ�...", 15, 10, 20);
			Sleep(1000);
			player.Die();
			CurrentScene(4);
		}
		monster.Dead();
		player.GetMoney(monster.GetGold());
		Sleep(1500);
		CurrentScene(4);
	}

private :
	Player		player;
	Monster		monster;
	string		_lottoResult = "��� >> ";
	bool		_isRest = true;
	bool		_playBackGroundSound = false;
	int			_curruntScene = 0;
	char		_input = 0;

	int			_inputLotto;
	int			_getLottoNum[4] = { 0 };
	int			_lottoNum[4] = { 0 };
	int			_lottoCorrectCount = 0;
	
	int			_inputZeroOrOne = 0;
	int			_zeroOnePay = 0;

	int			_inputPotion;
	
};