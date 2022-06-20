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
		cout << "1. 시작";
		System::SetCursor(40, 12);
		cout << "2. 종료";
		System::SetCursor(20, 15);
		cout << "시작하시려면 1번 종료하시려면 2번을 눌러주세요 : ";
		cin >> _input;
		if (_input == '1')
		{
			CurrentScene(100);
		}
		else if(_input == '2')
		{
			system("cls"); 
			System::SetCursor(32, 10);
			cout << "종료!";
			System::SetCursor(32, 28);
			exit(0);
		}
	}
	void Intro()
	{
		string playerName , str = "안녕하세요... ";
		System::PrintSleepText("당신의 이름을 입력하세요 (한글 3, 영문 7자 이내 띄어쓰기 불가) : ", 10, 10, 30);
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
		System::LodingText("마을로 진입 중");
		cout << _defalutScene;
		player.PrintState();
		System::SetCursor(40, 3);
		cout << "---마을---";
		System::SetCursor(20, 6);
		cout << "1. 상점으로 간다";
		System::SetCursor(20, 8);
		cout << "2. 사설 도박장으로 간다";
		System::SetCursor(20, 10);
		cout << "3. 던전으로 간다";
		System::SetCursor(20, 12);
		cout << "4. 여관에서 휴식한다 20G";
		System::SetCursor(20, 14);
		cout << "무엇을 할까? : ";
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
			System::PrintSleepText("여관에서 푹 쉰다.....", 20, 10, 50);
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
		System::LodingText("상점으로 가는 중");
		cout << _defalutScene;
		player.PrintState();
		System::SetCursor(40, 3);
		cout << "---상점---";
		System::SetCursor(20, 6);
		cout << "1. 아이템 구매";
		System::SetCursor(20, 8);
		cout << "2. 능력치 강화";
		System::SetCursor(20, 10);
		cout << "3. 마을로 돌아간다";
		System::SetCursor(20, 12);
		cout << "무엇을 할까? : ";
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
		cout << "---아이템 구매---";
		System::SetCursor(20, 6);
		cout << "1. 체력포션 구매 10G";
		System::SetCursor(20, 8);
		cout << "2. 마나포션 구매 10G";
		System::SetCursor(20, 10);
		cout << "3. 상점으로 돌아간다";
		System::SetCursor(20, 12);
		cout << "무엇을 할까? : ";
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
		cout << "---능력치 업그레이드---";
		System::SetCursor(20, 6);
		cout << "1. 체력 업그레이드 +10 HP " << player.GetHpUpgradeCost() << "G";
		System::SetCursor(20, 8);
		cout << "2. 마나 업그레이드 +10 MP " << player.GetMpUpgradeCost() << "G";
		System::SetCursor(20, 10);
		cout << "3. 공격력 업그레이드 +1 ATK " << player.GetPowerUpgradeCost() << "G";
		System::SetCursor(20, 12);
		cout << "4. 상점으로 돌아간다";
		System::SetCursor(20, 14);
		cout << "무엇을 할까? : ";
		cin >> _input;
		if (_input == '1')
		{
			player.HpUpgradePay();
			System::LodingText("체력 업그레이드 중");
			CurrentScene(102);
		}
		else if (_input == '2')
		{
			player.MpUpgradePay();
			System::LodingText("마나 업그레이드 중");
			CurrentScene(102);
		}
		else if (_input == '3')
		{
			player.PowerUpgradePay();
			System::LodingText("공격력 업그레이드 중");
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
		System::LodingText("도박장으로 가는중");
		cout << _defalutScene;
		player.PrintState();

		System::SetCursor(35, 3);
		cout << "---도박장---";
		System::SetCursor(20, 6);
		cout << "1. 로또";
		System::SetCursor(20, 8);
		cout << "2. 홀 짝";
		System::SetCursor(20, 10);
		cout << "3. 마을로 돌아간다";
		System::SetCursor(20, 12);
		cout << "무엇을 할까? : ";
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
		System::LodingText("한 방에 인생역전..");
		cout << _defalutScene;
		player.PrintState();

		System::SetCursor(35, 3);
		cout << "---!!LOTTO!!---";
		System::SetCursor(20, 6);
		cout << "1. 로또 시작";
		System::SetCursor(20, 8);
		cout << "2. 도박장으로 돌아간다";
		System::SetCursor(20, 12);
		cout << "무엇을 할까? : ";
		cin >> _input;
		if (_input == '1')
		{
			system("cls");
			cout << _defalutScene;
			player.PrintState();
			System::PrintSleepText("원하는 금액으로 구매해서 크게 한탕 쳐보자!!", 5, 6, 0);
			System::PrintSleepText("1 ~ 20 사이의 4개의 번호를 작은 순서대로 입력해, 맞추는 게임입니다.\n", 5, 7, 0);
			System::PrintSleepText("맞춘갯수 : 0 ~ 1개 == 꽝\n", 5, 8, 0);
			System::PrintSleepText("맞춘갯수 : 2개 == 구매금액 반환\n", 5, 9, 0);
			System::PrintSleepText("맞춘갯수 : 3개 == 구매금액 X 10\n", 5, 10, 0);
			System::PrintSleepText("맞춘갯수 : 4개 == 구매금액 X 100\n", 5, 11, 0);
			System::PrintSleepText("구매 금액을 입력 해 주세요 : ", 5, 13, 20);
			cin >> _inputLotto;
			if (player.Pay(_inputLotto))
			{
				_lottoCorrectCount = 0;
				System::PrintSleepText("로또 번호를 입력해주세요(작은 수 부터 큰 수 순서대로, 띄어쓰기로 구분) : ", 5, 15, 0);
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
							System::PrintSleepTextWithCls("중복 된 번호가 존재하는군요..? 다시 해 주세요", 20, 10, 10);
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
					System::PrintSleepText("0개 맞추셨습니다.. 다음번에 맞추면 되죠 뭐!", 20, 10, 2);
					break;
				case 1:
					System::PrintSleepText("1개 맞추셨습니다.. 조금 슬플지도?", 20, 10, 2);
					break;
				case 2:
					System::PrintSleepText("2개 맞추셨습니다~ 나쁘지 않네요 뭐", 20, 10, 2);
					player.GetMoney(_inputLotto);
					break;
				case 3:
					System::PrintSleepText("3개 맞추셨습니다!! 이 정도만 해도 운 좋으신거죠!", 20, 10, 2);
					player.GetMoney(_inputLotto * 10);
					break;
				case 4:
					System::PrintSleepText("로또 당첨!!! 엄청난 행운의 소유자!! 100배가 적용됩니다.", 20, 10, 2);
					player.GetMoney(_inputLotto * 100);
					break;
				default:
					break;
				}
			}
			else
			{
				System::PrintSleepTextWithCls("돈이 모자랍니다....", 20, 10, 2);
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
		System::LodingText("홀 짝 게임으로 진입 중");
		cout << _defalutScene;
		player.PrintState();

		System::SetCursor(35, 3);
		cout << "---!!홀 짝!!---";
		System::SetCursor(20, 6);
		cout << "1. 홀 짝 시작";
		System::SetCursor(20, 8);
		cout << "2. 도박장으로 돌아간다";
		System::SetCursor(20, 12);
		cout << "무엇을 할까? : ";
		cin >> _input;

		if (_input == '1')
		{
			system("cls");
			cout << _defalutScene;
			player.PrintState();
			System::PrintSleepText("홀짝을 잘 맞춰서 돈을 불려보자~!", 5, 6, 0);
			System::PrintSleepText("일정 골드를 넣은 후 0 또는 1을 입력해서 맞추면 맞출수록 금액이 커집니다", 5, 7, 0);
			System::PrintSleepText("배팅 할 금액을 입력하세요 >> :", 5, 15, 20);
			cin >> _zeroOnePay;
			if (player.Pay(_zeroOnePay))
			{
				while (1)
				{
					system("cls");
					System::SetCursor(5, 5);
					cout << "누적 금액 >> : " << _zeroOnePay;
					System::SetCursor(20, 15);
					cout << "0 또는 1을 입력하세요, 그만 두시려면 2를 입력하세요 >> : ";
					cin >> _inputZeroOrOne;
					if (_inputZeroOrOne == 2)
					{
						player.GetMoney(_zeroOnePay);
						break;
					}
					else if (System::ZeroOrOne() == _inputZeroOrOne)
					{
						System::PrintSleepTextWithCls("결과는....정답!!!", 20, 10, 100);
						_zeroOnePay += _zeroOnePay;
						Sleep(500);
						continue;
					}
					else
					{
						System::PrintSleepTextWithCls("결과는... 오답!!! 아쉽네요...", 20, 10, 100);
						Sleep(500);
						break;
					}
				}
			}
			else
			{
				System::PrintSleepTextWithCls("돈이 모자랍니다....", 20, 10, 2);
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
		System::LodingText("던전으로 향하는 중");
		cout << _defalutScene;
		player.PrintState();
		System::SetCursor(40, 3);
		cout << "---던전---";
		System::SetCursor(20, 6);
		cout << "1. 주변을 탐색한다";
		System::SetCursor(20, 8);
		cout << "2. 사람을 고용하여 탐색한다 10G (레어 몬스터 출현 가능성 有)";
		if (_isBossRoomOpen == true)
		{
			System::SetCursor(20, 10);
			cout << "3. 마을로 돌아간다";
			System::SetCursor(20, 12);
			cout << "4. 보스 룸 진입";
			System::SetCursor(20, 14);
			cout << "무엇을 할까? : ";
		}
		else
		{
			System::SetCursor(20, 10);
			cout << "3. 마을로 돌아간다";
			System::SetCursor(20, 12);
			cout << "무엇을 할까? : ";
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
				System::PrintSleepTextWithCls("돈이 모자랍니다... 고용을 하지 않고 탐색합니다...", 20, 10, 40);
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
		System::LodingText("탐색 중");
		System::PrintSleepTextWithCls("야생의 "+ monster.GetName() + "의 등장!!!", 25, 10, 60);
		system("cls");
		while (monster.GetHp() > 0 && player.GetHp() > 0)
		{
			cout << _defalutScene;
			player.PrintState();
			monster.PrintMonsterInfo();
			System::SetCursor(40, 3);
			cout << "---전투---";
			System::SetCursor(5, 10);
			cout << "1. 공격한다";
			System::SetCursor(5, 12);
			cout << "2. 스킬사용";
			System::SetCursor(5, 14);
			cout << "3. 포션섭취";
			System::SetCursor(5, 16);
			cout << "4. 도망간다";
			System::SetCursor(5, 18);
			cout << "무엇을 할까? : ";
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
				cout << "1. HP 포션 섭취";
				System::SetCursor(60, 16);
				cout << "2. MP 포션 섭취";
				System::SetCursor(60, 18);
				cout << "3. 포션을 사용하지 않는다";
				System::SetCursor(57, 20);
				cout << "사용할 포션을 골라주세요 : ";

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
			System::PrintSleepTextWithCls("당신은 죽었습니다... 체력과 마나가 10%로 고정됩니다...", 15, 10, 20);
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
		System::LodingText("보스룸으로 이동 중");
		System::PrintSleepTextWithCls("싸늘한 기운이 느껴진다...", 25, 10, 60);
		system("cls");
		while (monster.GetHp() > 0 && player.GetHp() > 0)
		{
			cout << _defalutScene;
			player.PrintState();
			monster.PrintMonsterInfo();
			System::SetCursor(40, 3);
			cout << "---보스 룸---";
			System::SetCursor(5, 10);
			cout << "1. 공격한다";
			System::SetCursor(5, 12);
			cout << "2. 스킬사용";
			System::SetCursor(5, 14);
			cout << "3. 포션섭취";
			System::SetCursor(5, 16);
			cout << "4. 도망간다";
			System::SetCursor(5, 18);
			cout << "무엇을 할까? : ";
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
				cout << "1. HP 포션 섭취";
				System::SetCursor(60, 16);
				cout << "2. MP 포션 섭취";
				System::SetCursor(60, 18);
				cout << "3. 포션을 사용하지 않는다";
				System::SetCursor(57, 20);
				cout << "사용할 포션을 골라주세요 : ";

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
			System::PrintSleepTextWithCls("당신은 죽었습니다... 체력과 마나가 10%로 고정됩니다...", 15, 10, 20);
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
	string		_lottoResult = "결과 >> ";
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