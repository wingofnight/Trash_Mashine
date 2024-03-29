﻿// GhostHunter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <string>
#include <time.h>

using namespace std;
void FirstChoice();//Первый выбор игрока, который отправляет в функцию навигации, либо завершает игру.
void Navigation(int setNavigation);
void ConsolSize(); // Утснаваливает размер окна консоли. (подглядел в гугле, но пришлось повозится)
void BigText();// Выводит Лого игры.
void Disclaimer();// Выводит прочее при запуске игры.
void StartMenu();
void StartLocations();// Первая локация перед входом в замок, которая худо бедно объясняет пользователю, что к чему.
void TextWindow();// Рисует полоску в окне с текстом. 
void Die(); // Выводи на экран сообщение при смерти. 
void Interface();//Интерфейс игрока, отображает здоровье, ману, снаряжение и карту.
void Action();
void GenerateItem();
void ItemBox();
void Counter(int haw);
void Fight(int mobHeals, int mobDamage);
//Итемы (вещи)

//комнаты
void Chest();

void Room_Clear_Center();
void Room_Clear_Left();
void Room_Clear_Right();

void Room_A1();
void Room_A2();
void Room_A3();
void Room_A4();
void Room_A5();
void Room_A6();
void Room_A7();
void Room_A8();
void Room_A9();
void Room_A10();
void Room_A11();
void Room_A12();
void Room_A13();
void Room_A14();
void Room_A15();

void ItemFight();
void SkillsInFight(int lvl);
void Specialization(bool special);
bool mobId[15]{ true , true ,true ,true ,true ,true ,true ,true ,true ,true ,true ,true ,true ,true ,true };
bool chekCloseChest[15]{ true , true ,true ,true ,true ,true ,true ,true ,true ,true ,true ,true ,true ,true ,true };
int setItem[11];
int z = 0;
int playerHels = 3;
int playerMana = 5;
int choice, firstChoice;
int key, setNavigation, savePosition, choiceItem;//
char x = 127;
int expirience, mobExp, lvl;
bool speciolization;
bool lose = true;
int deferredDamage;
int newItemDamage[22];
int escapeJump;
int giveKey = 1;

string deathWariation[4]{ "снесло вам бошку","разорвало вас на части", "содрало с вас кожу и напялило на себя", "накормило вас не свежей шаурмой" };
string finishing[6]{ " сражен!"," разорван на части"," сожран вами", "нашинкован", "отформатирован", "ощутил на себе жестокое убийство" };
string playerName, sayItem, mobName;
string newItem[22];
//ох тут будет ща полная жопа xDDD(описание навыков)
string ratSkils[5]{ "Порез", "Сквозной порез", "Фаршмашина","Изничтожение","Ультимативная смерть" };
string magSkils[5]{ "Огненая стрела", "Огнехлыст", "Костяные шипы","Смерть с небес","Армагедон" };
string ratEqip[4]{ "Меч", "Коса", "Броня", "Шлем" };
string magEqip[4]{ "Посох", "Некрономикон", "Мантия", "Сфера стихий" };
string skils[5];
//"Яблоко","Зелье","Элексир","Свиток - Фаербол","Свиток Молния","Свиток ледяная стрела","Серебрянные дротики","Святая бомба", "Освященый сюрикен"
int itemDamage[10]{ 2,7,7,5,7,3,5,7,3,0 };
//"Порез", "Сквозной порез", "Фаршмашина","Изничтожение","Ультимативная смерть","Огненая стрела", "Огнехлыст", "Костяные шипы","Смерть с небес","Армагедон"
int skilsDamage[5]{ 1,5,9,14,20 };
int eqipDamage[8]{ 1,4,2,4,1,4,2,4 };
int giveMana;

int main()
{

	ConsolSize();
	setlocale(LC_ALL, "russian");

	Disclaimer();
	StartMenu();
	if (playerName == "satan") {
		key += 5;
		playerHels += 100;
		playerMana += 100;

	}
	FirstChoice();
	Room_Clear_Right();






}

void ConsolSize() {

	HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD crd = { 120,45 };
	SMALL_RECT src = { 0, 0, crd.X - 1, crd.Y - 1 };
	SetConsoleWindowInfo(out_handle, true, &src);
	SetConsoleScreenBufferSize(out_handle, crd);

}
void Disclaimer() {
	BigText();
	cout << endl << endl;
	cout << "\t\t\t\t\t";
	cout << "\t\t\t\t\t";
	cout << "(с) Компьютерная академи ШАГ. Воронеж" << endl;
	cout << "\t\t\t\t\t";
	cout << "\t\t\t\t\t";
	cout << "(c) Старинин Андрей, Питецкий Владимир" << endl;
	cout << endl;
	cout << "\t\t\t\t";
	cout << "		>>> Press Enter! <<<\n\n\n\n";
	system("pause");
	system("cls");
}
void TextWindow() {
	cout << "\t";
	for (int i = 0; i < 100; i++)
	{
		cout << '#';
	}
	cout << endl;

}

void BigText() {

	char bigStringGost[7][25] = {
		{ '#','#','#','#',' ','#',' ',' ','#',' ','#','#','#','#',' ','#','#','#','#',' ','#','#','#','#','#' },
		{ '#',' ',' ','#',' ','#',' ',' ','#',' ','#',' ',' ','#',' ','#',' ',' ','#',' ',' ',' ','#',' ',' ' },
		{ '#',' ',' ',' ',' ','#',' ',' ','#',' ','#',' ',' ','#',' ','#',' ',' ',' ',' ',' ',' ','#',' ',' ' },
		{ '#',' ','#','#',' ','#','#','#','#',' ','#',' ',' ','#',' ','#','#','#','#',' ',' ',' ','#',' ',' ' },
		{ '#',' ',' ','#',' ','#',' ',' ','#',' ','#',' ',' ','#',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ' },
		{ '#',' ',' ','#',' ','#',' ',' ','#',' ','#',' ',' ','#',' ','#',' ',' ','#',' ',' ',' ','#',' ',' ' },
		{ '#','#','#','#',' ','#',' ',' ','#',' ','#','#','#','#',' ','#','#','#','#',' ',' ',' ','#',' ',' ' }
	};
	char bigStringHuner[7][32] = {
		{ '#',' ',' ','#',' ','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#','#','#','#','#',' ','#','#','#','#',' ','#','#','#','#','#' },
		{ '#',' ',' ','#',' ','#',' ',' ','#',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ','#' },
		{ '#',' ',' ','#',' ','#',' ',' ','#',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ','#',' ',' ',' ','#' },
		{ '#','#','#','#',' ','#',' ',' ','#',' ','#','#',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#','#','#',' ',' ','#','#','#','#','#' },
		{ '#',' ',' ','#',' ','#',' ',' ','#',' ','#',' ','#',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ','#','#','#',' ',' ' },
		{ '#',' ',' ','#',' ','#',' ',' ','#',' ','#',' ',' ','#','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ','#',' ','#',' ',' ','#',' ' },
		{ '#',' ',' ','#',' ','#','#','#','#',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#','#','#','#',' ','#',' ',' ',' ','#' }
	};
	cout << "\t\t\t\t\t";
	for (int t = 0; t < 7; t++)
	{
		for (int i = 0; i < 25; i++)
		{
			cout << bigStringGost[t][i];
		}
		cout << endl << "\t\t\t\t\t";
	}

	cout << endl;
	cout << "\t\t\t\t\t";
	for (int t = 0; t < 7; t++)
	{
		for (int i = 0; i < 32; i++)
		{
			cout << bigStringHuner[t][i];
		}
		cout << endl << "\t\t\t\t\t";;
	}

}


void StartMenu() {
	BigText();
	cout << endl << endl;
	cout << "\t\t\t\t";
	cout << "\t Сделайте свой первый выбор!\n" << "\t\t\t\t\t\t" << "1) Новая Игра!\n" << "\t\t\t\t\t\t" << "2) Выход\n\n";
	cin >> choice;

	switch (choice)
	{
	case 1:
		StartLocations();

		break;
	case 2:
		break;
	default:
		cout << "Неверный выбор!" << endl;
		main();
	}

}

void StartLocations() {
	int choiceClass;
	system("cls");

	TextWindow();
	//cout << "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_"; - 'это разметка текста.
	cout << "\t|                                                                                                  |";
	cout << "\n\t|\tДобро пожаловать в мир приключений. Прекрасный мир, полный опасностей, зомби               |" << endl << "\t|";
	cout << "и кровожадных монстров. Вы отважный искатель приключений, отправились в заброшенный замок,        |" << endl << "\t|";
	cout << "дабы спасти дракона. Дракона, что заточен в башне на вершине замка. Злобная принцесса,            |" << endl << "\t|";
	cout << "обманом заманила дракона в башню, где он попал в ловушку. Магические цепи тут же его              |" << endl << "\t|";
	cout << "сковали и прижали к полу. И чем сильнее пытался вырваться дракон, тем сильнее сжимались цепи.     |" << endl << "\t|";
	cout << "Сжимались до хруста костей. И в итоге дракон сдался.                                              |" << endl;
	cout << "\t|                                                                                                  |" << endl << "\t|";
	cout << "Испльзуя кровь дракона как источник бессмертия, и как материал для ужасающих эксперементов,       |" << endl << "\t|";
	cout << "принцесса сама не заметила, как превратилась в ужаснейшее чудовище. И все подданые, все все,      |" << endl << "\t|";
	cout << "кто населял замок, со временем стали монстрами, неупокоенными душами, тенями, что вынужденны      |" << endl << "\t|";
	cout << "скитатся по замку вечность. Таково проклятие дракона...                                           |" << endl;
	cout << "\t|                                                                                                  |" << endl;
	TextWindow();

	system("pause");
	system("cls");

	TextWindow();
	//cout << "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123|5678|__|"; - 'это разметка текста.
	cout << "\t|                                                                                                  |";
	cout << "\n\t|\tИ так, старнник, теперь узнав об этой истории, вы не можете пройти мимо!                   |" << endl << "\t|";
	cout << "Вам придется войти в замок, пройти три этажа, сразив на каждом своего босса, взабраться на        |" << endl << "\t|";
	cout << "башню, победить принцессу и освободить дракона. Освободить дракона любой ценой!                   |" << endl << "\t|";
	cout << "                                                                                                  |" << endl << "\t|";
	cout << "\tВ процессе приключения, вам будут встречать предметы, которые помогут вам в сражениях.     |" << endl << "\t|";// Смещение центровки на 5 символов из-за табуляции в начале!
	cout << "Так же, вы сможите отыскать сундуки с сокровищами, но что бы открыть их, понадобятся ключи.       |" << endl << "\t|";
	cout << "                                                                                                  |" << endl << "\t|";
	cout << "\tДля начала, давайте познакомимся!                                                          |" << endl << "\t|";
	cout << "                                                                                                  |" << endl;
	TextWindow();

	cout << "\t\t\t\tВведите имя (на английском) :";
	cin >> playerName;

	system("pause");
	system("cls");

	TextWindow();
	//cout << "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_12345678|__|"; - 'это разметка текста.
	cout << "\t|                                                                                                  |";
	cout << "\n\t|\tОтлично " << playerName << " А теперь выбери класс :" << endl << "\t|";
	cout << "\t1) Воин.                                                                                   |" << endl << "\t|";
	cout << "\t2) Маг.                                                                                    |" << endl << "\t|";
	cout << "                                                                                                  |" << endl << "\t|";
	cout << "\tВыбирай с умом. От выбора зависят харрактеристики предметов.                               |" << endl << "\t|";
	cout << "Маг получает усиление используя магические предметы, а воин ратные соответсвенно.                 |" << endl << "\t|";
	cout << "Также маг менее эфективно использует ратные предметы, как и воин магические.                      |" << endl << "\t|";
	cout << "У некоторых босов, может быть слабость или спротивление к магии, или ратному вооружению           |" << endl << "\t|";
	cout << "                                                                                                  |" << endl;
	TextWindow();

	cout << "\t\t\t\tВведите номер класса :";
	cin >> choiceClass;
	if (choiceClass == 1)
	{
		speciolization = false;
	}
	else
	{
		speciolization = true;
	}
	Specialization(speciolization);


	system("pause");
	system("cls");

	TextWindow();
	//cout << "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123|5678|__|"; - 'это разметка текста. Выровняй разметку по cout.
	cout << "\t|                                                                                                  |";
	cout << "\n\t|\tОтлично " << playerName << ", теперь ты полностью готов. " << endl << "\t|";
	cout << "Ты стоишь на пороге врат в замок. Что ожидает за ними? Смерть? Сокровища? Может быть любовбь?     |" << endl << "\t|";
	cout << "Решишся ли ты отворить врата? Или поддашся страху и убежишь как пугливый котенок?                 |" << endl << "\t|";
	cout << "Сделай выбор!                                                                                     |" << endl << "\t|";
	cout << "                                                                                                  |" << endl << "\t|";
	cout << "\t1) Распахнуть обветшалые врата ударом с ноги!                                              |" << endl << "\t|";
	cout << "\t2) Бежать как испуганный котенок...                                                        |" << endl << "\t|";
	cout << "                                                                                                  |" << endl;
	TextWindow();

	cout << "\t" << playerName << " выбирай! (Выбор производится вводом номера варианта) : ";
	cin >> firstChoice;
	system("pause");
	system("cls");

}

void FirstChoice() {

	cout << endl;
	if (firstChoice == 1)
	{
		TextWindow();
		//cout << "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123|5678|__|"; - 'это разметка текста.
		cout << "\t|                                                                                                  |" << endl << "\t|";
		cout << "\tРезким и жестким ударом ноги, трухлявая дверь сорвалась с петель. Спертый воздуг резко     |" << endl << "\t|";
		cout << "ударил в лицо, грязные окна не впускали свет внутрь помещения, а потолок украшала паутина.        |" << endl << "\t|";
		cout << "Сердце забилось чаще, но вы не струсили, и сделали свой первый шаг. Шаг в неведанное, в пустоту.  |" << endl << "\t|";
		cout << "                                                                                                  |" << endl << "\t|";
		cout << "\tШаг на встречу опасности...                                                                |" << endl << "\t|";
		cout << "                                                                                                  |" << endl;
		TextWindow();
		system("pause");
		system("cls");
		Room_A2();
	}
	else
	{
		TextWindow();
		//cout << "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123|5678|__|"; - 'это разметка текста.
		cout << "\t|                                                                                                  |" << endl << "\t|";
		cout << "\tТы стоял под гнетом стен ужасающего замка. Страшные звуки доносились из его глубин.        |" << endl << "\t|";
		cout << "В твоей голове, по кругу, мелькала одни лишь мысль - \"Опасность!\" Ты понимаешь, что               |" << endl << "\t|";
		cout << "оставаться тут нелья. И приняв единственное верное решение, кидаешься на утек.                    |" << endl << "\t|";
		cout << "                                                                                                  |" << endl << "\t|";
		cout << "\tОднако не пробежав и 20 метров, спотыкаешься о корень и падаешь в грязь. Ты в ужасе        |" << endl << "\t|";
		cout << "поднимаешь лицо. Вязкая грязь залила глаза, ты видишь силуэт над собой, но не можешь разобрать,   |" << endl << "\t|";
		cout << "что видишь. Только странные чавкающие звуки доносятся до тебя...                                  |" << endl << "\t|";
		cout << "                                                                                                  |" << endl << "\t|";
		cout << "  Тупая боль пробила грудь, и слезы неволей вырвались на ружу, небеса разорвал оглушающий крик.   |" << endl << "\t|";
		cout << "Это кречишь ты - " << playerName << "...И это последние мгновения твоей жизни...                        " << endl << "\t|";
		cout << "\tОстрая кость, что служила монстру рукой, или была ей когда то, пронзила тебя на сквозь...  |" << endl;
		TextWindow();
		Die();
		main();
	}
	system("pause");
	system("cls");

}

void Die() {
	char youDie_YOU[6][15]{
		{ '#',' ',' ',' ','#',' ','#','#','#','#',' ','#',' ',' ','#' },
		{ ' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ','#' },
		{ ' ',' ','#',' ',' ',' ','#',' ',' ','#',' ','#',' ',' ','#' },
		{ ' ',' ','#',' ',' ',' ','#',' ',' ','#',' ','#',' ',' ','#' },
		{ ' ',' ','#',' ',' ',' ','#',' ',' ','#',' ','#',' ',' ','#' },
		{ ' ',' ','#',' ',' ',' ','#','#','#','#',' ','#','#','#','#' }
	};

	char youDie_DIE[6][11]{
		{ '#','#',' ',' ',' ','#',' ','#','#','#','#' },
		{ '#',' ','#',' ',' ',' ',' ','#',' ',' ','#' },
		{ '#',' ',' ','#',' ','#',' ','#',' ',' ',' ' },
		{ '#',' ',' ','#',' ','#',' ','#','#','#',' ' },
		{ '#',' ',' ','#',' ','#',' ','#',' ',' ',' ' },
		{ '#','#','#',' ',' ','#',' ','#','#','#','#' }
	};

	char youDie_SKULL[12][8]{
		{ ' ',' ','#','#','#','#',' ',' ' },
		{ ' ','#','#','#','#','#','#',' ' },
		{ ' ','#',' ','#','#',' ','#',' ' },
		{ ' ','#','#','#','#','#','#',' ' },
		{ ' ',' ','*','#','#','*',' ',' ' },
		{ '#',' ',' ','#','#',' ',' ','#' },
		{ '#','*',' ',' ',' ',' ','*','#' },
		{ ' ',' ','*',' ',' ','*',' ',' ' },
		{ ' ',' ',' ','#','#',' ',' ',' ' },
		{ ' ',' ','*',' ',' ','*',' ',' ' },
		{ '#','*',' ',' ',' ',' ','*','#' },
		{ '#',' ',' ',' ',' ',' ',' ','#' }

	};

	cout << "\t\t\t\t\t";
	for (int t = 0; t < 6; t++)
	{
		for (int i = 0; i < 15; i++)
		{
			cout << youDie_YOU[t][i];
		}
		cout << endl << "\t\t\t\t\t";
	}

	cout << endl;
	cout << "\t\t\t\t\t  ";

	for (int t = 0; t < 6; t++)
	{
		for (int i = 0; i < 11; i++)
		{
			cout << youDie_DIE[t][i];
		}
		cout << endl << "\t\t\t\t\t  ";;
	}
	cout << endl << endl;

	cout << "\t\t\t\t\t   ";

	for (int t = 0; t < 12; t++)
	{
		for (int i = 0; i < 8; i++)
		{
			cout << youDie_SKULL[t][i];
		}
		cout << endl;
		cout << "\t\t\t\t\t   ";
	}
	cout << endl;
	cout << "\t\t\t\t\t";

	cout << "1) Новая Игра!\n" << "\t\t\t\t\t" << "2) Выход\n\n";
	cin >> choice;

	switch (choice)
	{
	case 1:
		StartLocations();

		break;
	case 2:
		break;
	default:
		cout << "Неверный выбор!" << endl;
		main();
	}



}
void GenerateItem() {
	string item[11]{ "Кек, здесь ни чего нет :-(", "Яблоко","Зелье","Элексир","Свиток - Фаербол","Свиток Молния","Свиток ледяная стрела","Серебрянные дротики","Святая бомба", "Освященый сюрикен","Кек, здесь ни чего нет :-(" };
	srand(time(NULL));//Обрати внимание!
	int x = rand() % 11;
	if (z < 22)
	{
		sayItem = item[x];
		setItem[x]++;

	}
	else {
		cout << "Вы не можете унести больше вещей, увы. Вам пришлось бросить эту затею!";
	}
	if (x > 0 && x < 11)
	{//itemDamage[10]{2,7,7,5,7,3,5,7,3,0};
		newItem[z] = item[x];
		newItemDamage[z] = itemDamage[x - 1];

		z++;

	}
}



void Navigation(int setNavigation) {
	escapeJump = savePosition;
	switch (setNavigation)
	{
	case 0:
		Chest();
		break;
	case 1:
		Room_A1();
		break;
	case 2:
		Room_A2();
		break;
	case 3:
		Room_A3();
		break;
	case 4:
		Room_A4();
		break;
	case 5:
		Room_A5();
		break;
	case 6:
		Room_A6();
		break;
	case 7:
		Room_A7();
		break;
	case 8:
		Room_A8();
		break;
	case 9:
		Room_A9();
		break;
	case 10:
		Room_A10();
		break;
	case 11:
		Room_A11();
		break;
	case 12:
		Room_A12();
		break;
	case 13:
		Room_A13();
		break;
	case 14:
		Room_A14();
		break;
	case 15:
		Room_A15();
		break;

	case 101:
		Room_Clear_Left();
		break;
	case 102:
		Room_Clear_Center();
		break;
	case 103:
		Room_Clear_Right();
		break;

	default:
		break;
	}

}

void Interface() {
	string coordinatePlayer[16]{ "zer0", "W1", "N1", "E1","W2", "N2", "E2", "W3", "N3", "E3", "W4", "N4", "E4", "W5", "N5", "E5" };
	string who;
	if (speciolization) {
		who = "Маг";
	}
	else {
		who = "Воин";
	}
	cout << "\n\tВаш уровень : " << lvl << ". Вы -\"" << who << "\". Ваше НР = " << playerHels << ". Вашe MP = " << playerMana << endl;
	cout << "\tВаш урон = " << skilsDamage[0] << " DMG." << " Ваши коардинаты = \"" << coordinatePlayer[savePosition] << "\"." << endl;
	cout << "\tУ вас в наличии : ";

	cout << "Колличество ключей : " << key << "." << endl << "\t";

	if (z > 0) {
		for (int i = 0; i < z; i++)
		{
			cout << newItem[i] << "  ";
			if (i > 2)
			{
				cout << endl << "\t";
			}
		}

	}
	cout << endl << "Боевой опыт : " << expirience << "." << endl;

}
////////////////////////////////////////////////////////////
void Specialization(bool special)
{
	if (special)
	{
		for (int i = 0; i < 4; i++)
		{

			itemDamage[i + 3]++;
			itemDamage[i + 7]--;
			eqipDamage[i]--;
			eqipDamage[i + 4]++;

		}

		for (int i = 0; i < 5; i++)
		{

			skils[i] = magSkils[i];
		}
		playerMana++;
		skilsDamage[0] = 1;

	}
	else {

		for (int i = 0; i < 4; i++)
		{

			itemDamage[i + 3] --;
			itemDamage[i + 7] ++;
			eqipDamage[i]++;
			eqipDamage[i + 4]--;
		}

		itemDamage[0]++;
		for (int i = 0; i < 5; i++)
		{
			skils[i] = ratSkils[i];
		}
		playerHels++;
		skilsDamage[0] = 1;//костыль. Непонятно каким образом, но при выборе мага, скилдемейдж становится 0, а при выборе война =2. Хз почему так. Все просмотрел по 10 раз, ни чего не могу найти!
	}

}
void Fight(int mobHeals, int mobDamage) {
	int choice;
rechoice:
	TextWindow();
	//cout << "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123|5678|__|"; - 'это разметка текста.
	cout << "\t|                                                                                                  |" << endl << "\t|";
	cout << "\t|" << mobName << " грозный противник. Так как ты застал его в расплох, то ходи первым!\n";
	cout << "\t|                                                                                                  |" << endl;
	cout << "\t| Выбери действие :                                                                                |" << endl;
	cout << "\t| 1) " << skils[0] << endl;
	cout << "\t| 2) Использовать навыки.                                                                          |" << endl;
	cout << "\t| 3) Использовать инвернтарь.                                                                      |" << endl;
	cout << "\t| 4) Бежать.                                                                                       |" << endl;
	TextWindow();
	Interface();
	cout << "\n\t\tВведите свой выбор : ";
	cin >> choice;
	switch (choice)
	{
	case 1:

		cout << "\n\t\tВы используете " << "-" << "\"" << skils[0] << "\"" << " на " << "\"" << mobName << "\"" << " и причиняете " << skilsDamage[0] << " урона!\n";
		mobHeals -= skilsDamage[0];

	chek:

		if (mobHeals > 0)
		{
			cout << endl << "\t" << mobName << " не умер, у него осталось - " << mobHeals << " НР. Но " << mobName << " разочарован вами! За это получите - " << mobDamage << " урона!\n";
			playerHels -= mobDamage;
			if (playerHels <= 0)
			{
				system("cls");

				int x;
				x = rand() % 4;

				cout << "\t\t\tМои глубочайшие соболезнования " << playerName << "...\n\t\t\tНо \"" << mobName << "\" " << deathWariation[x] << "!\n\n";

				Die();
			}
			system("pause");
			system("cls");
			goto rechoice;
		}
		else {
			int x = rand() % 6;
			cout << "\n\tПозравляем! " << mobName << " " << finishing[x] << endl;
			expirience += mobExp;
			playerMana += giveMana;
			mobId[savePosition] = false;
			if (expirience > 9)
			{
				lvl++;
				skilsDamage[0]++;
			}
			system("pause");
			system("cls");
			Navigation(savePosition);
		}

	case 2:
		lose = true;
		SkillsInFight(lvl);
		mobHeals -= deferredDamage;
		deferredDamage = 0;
		if (lose)
		{
			goto chek;
		}
		else {
			Fight(mobHeals, mobDamage);
		}
		break;
		//Выберите навык : скил 1 скил 2 скил 3 скил 4
	case 3:


		lose = true;
		ItemFight();
		mobHeals -= deferredDamage;
		deferredDamage = 0;
		if (lose)
		{
			goto chek;
		}
		else {
			Fight(mobHeals, mobDamage);
		}
		break;
	case 4:
		Navigation(escapeJump);///////////////////////
	default:
		break;
	}
}
/*void ItemBox(){




}*/
void ItemFight() {
	int choice;
	if (z > 0) {
		for (int i = 0; i < z; i++)
		{

			cout << "\t" << i + 1 << ") " << newItem[i] << "\t";
			if (i > 2)
			{
				cout << endl;
			}

		}
	}
	else {
		cout << "\n\tУ вас еще нет вещей! Вы получите шмотки как только вскорете сундук!" << endl;
		lose = false;
		system("pause");
		system("cls");
	}

	if (z > 0) {
		cout << "\n\tСделайте выбор : ";
		cin >> choice;
		if (newItem[choice - 1] == "Яблоко" || newItem[choice - 1] == "Зелье" || newItem[choice - 1] == "Элексир")
		{
			if (newItem[choice - 1] == "Элексир")
			{
				playerMana += newItemDamage[choice - 1];
			}
			playerHels += newItemDamage[choice - 1];

			for (int i = choice; i < z; i++)
			{

				newItem[i - 1] = newItem[i];
				newItemDamage[i - 1] = newItemDamage[i];
				if (i == z - 1)
				{
					newItem[z] = "clear";
					newItemDamage[z] = 0;

				}
			}
			//Counter(choice);
			z--;
		}
		else {
			deferredDamage = newItemDamage[choice - 1];

			for (int i = choice; i < z; i++)
			{
				newItem[i - 1] = newItem[i];
				newItemDamage[i - 1] = newItemDamage[i];
				if (i == z - 1)
				{
					newItem[z] = "clear";
					newItemDamage[z] = 0;

				}
			}
			//Counter(choice);
			z--;
		}
	}



}

/*void Counter(int haw) {

	string item[11]{ "Кек, здесь ни чего нет :-(", "Яблоко","Зелье","Элексир","Свиток - Фаербол","Свиток Молния","Свиток ледяная стрела","Серебрянные дротики","Святая бомба", "Освященый сюрикен","Кек, здесь ни чего нет :-(" };


	if (newItem[haw - 1] == "Яблоко") {
		setItem[1]--;
	}
	if (newItem[haw - 1] == "Зелье") {
		setItem[2]--;
	}
	if (newItem[haw - 1] == "Элексир") {
		setItem[3]--;
	}
	if (newItem[haw - 1] == "Свиток - Фаербол"){
		setItem[4]--;
	}
	if (newItem[haw - 1] == "Свиток Молния") {
		setItem[5]--;
	}
	if (newItem[haw - 1] == "Свиток ледяная стрела") {
		setItem[6]--;
	}
	if (newItem[haw - 1] == "Серебрянные дротики") {
		setItem[7]--;
	}
	if (newItem[haw - 1] == "Святая бомба") {
		setItem[8]--;
	}
	if (newItem[haw - 1] == "Освященый сюрикен") {
		setItem[9]--;
	}

}*/
void SkillsInFight(int lvl) {
rechoice:
	int choice;
	if (lvl < 5)
	{
		for (int i = 1; i < lvl + 1; i++)
		{
			cout << "\n\t" << i << ") " << skils[i];
		}
	}
	if (lvl < 1)
	{
		cout << "\n\tУ вас еще нет навыков! Вы получите навык как достигните 1 ровня, который дают за 10хр." << endl;
		lose = false;
		system("pause");
		system("cls");
	}
	else {
		cout << "\n\tСделайте выбор : ";
		cin >> choice;


		if (choice <= lvl && choice < 5)
		{

			switch (choice) {

			case 1:
				cout << "\n\t\tВы используете " << "-" << "\"" << skils[1] << "\"" << " на " << "\"" << mobName << "\"" << " и причиняете " << skilsDamage[1] << " урона!\n";
				deferredDamage = skilsDamage[1];
				playerMana -= 2;
				system("pause");
				system("cls");
				break;
			case 2:
				cout << "\n\t\tВы используете " << "-" << "\"" << skils[2] << "\"" << " на " << "\"" << mobName << "\"" << " и причиняете " << skilsDamage[2] << " урона!\n";
				deferredDamage = skilsDamage[2];
				playerMana -= 4;
				system("pause");
				system("cls");
				break;
			case 3:
				cout << "\n\t\tВы используете " << "-" << "\"" << skils[3] << "\"" << " на " << "\"" << mobName << "\"" << " и причиняете " << skilsDamage[3] << " урона!\n";
				deferredDamage = skilsDamage[3];
				playerMana -= 7;
				system("pause");
				system("cls");
				break;
			case 4:
				cout << "\n\t\tВы используете " << "-" << "\"" << skils[4] << "\"" << " на " << "\"" << mobName << "\"" << " и причиняете " << skilsDamage[4] << " урона!\n";
				deferredDamage = skilsDamage[4];
				playerMana -= 10;
				system("pause");
				system("cls");
				break;
			default:

				break;
			}
		}
		else {

			cout << "/n/tНе правильно набран номер! Попытйте счастье снова!";
			system("pause");
			system("cls");
			goto rechoice;

		}
	}
}
void Action(int roomType) {

	cout << endl;
	TextWindow();
	//cout << "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123|5678|__|"; - 'это разметка текста.
	cout << "\t|                                                                                                  |" << endl << "\t|";
	cout << "\tСделай выбор!!!                                                                            |" << endl << "\t|";
	cout << "\t1) Идти на Север.                                                                          |" << endl << "\t|";
	cout << "\t2) Идти на Запад.                                                                          |" << endl << "\t|";
	cout << "\t3) Идти на Восток.                                                                         |" << endl << "\t|";
	cout << "\t4) Отправится на юг.                                                                       |" << endl;
	switch (roomType)
	{

	case 0:
		TextWindow();
		break;
	case 1:
		cout << "\t|\t5) Открыть сундук!                                                                         |" << endl << "\t";
		cout << "|                                                                                                  |" << endl;
		TextWindow();

	default:
		break;
	}
}


//Комнаты!!!
void Chest() {

	system("cls");
	TextWindow();
	//cout << "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_|23456789_123|5678|__|"; - 'это разметка текста. Выровняй разметку по cout.
	cout << "\t|                                                                                                  |";
	cout << "\n\t|\tОтлично " << playerName << ", отакрыть сундук отличная идея, надеюсь у тебя есть ключ?. " << endl << "\t|";
	cout << "                                                                                                  |" << endl << "\t|";
	cout << "\tТы шаришь по карманам в поисках ключа...                                                   |" << endl << "\t|";
	if (key > 0) {
		GenerateItem();
		cout << "                                                                                                  |" << endl << "\t|";
		cout << "\tШикарно, вы нашли ключ!                                                                    |" << endl << "\t|";
		cout << "                                                                                                  |" << endl << "\t|";
		cout << "Теперь посмотрим чем вам удалось поживится. Тяжелая крышка старого сундука, со скрипом отворяется.|" << endl << "\t|";
		cout << "Вы неможите поверить своим глазам, вы нашли -\"" << sayItem << "\"" << endl << "\t| ";
		cout << "                                                                                                 |" << endl;
		TextWindow();
		key -= 1;
		chekCloseChest[savePosition] = false;

		system("pause");
		system("cls");
		Navigation(savePosition);

	}
	else {


		//cout << "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_|23456789_123|5678|__|"; - 'это разметка текста. Выровняй разметку по cout.
		cout << "                                                                                                  |" << endl << "\t|";
		cout << "\tПошарив по карманам, вы понимаете, что ключа у вас так и нет!                              |" << endl << "\t|";
		cout << "\tВаши попытки тщетны и вы остаетесь ни с чем!                                               |" << endl << "\t|";
		cout << "\tХорошо, хоть сундук не обратился монстром...                                               |" << endl << "\t|";
		cout << "                                                                                                  |" << endl;
		TextWindow();

		system("pause");
		system("cls");
		Navigation(savePosition);
	}

}

void Room_Clear_Center() {


	cout << "\n\t\t Вы подходите к окну. За ним вид на дорогу что ведет к замку.\n\tТуман стелится до самой земли, ваши попытки, что либо разглядеть дальше 5 метров провалились.\n\tВы тяжко вздыхаете, вспоминаете о вашем нелегком деле и возвращаетесь назад.\n";
	system("pause");
	system("cls");
	Navigation(savePosition);
}
void Room_Clear_Left() {

	cout << "\n\t\t Вы подходите к окну. За ним прекрасный вид на океан. Волны врезаются в прибрежные скалы\n\tи затем волны взрываются фонтаном. Даже до сюда доносится океаническая свежесть.\n\tВы вдыхаете полную грудь свежего воздуха и возвращаетесь назад.\n";
	system("pause");
	system("cls");
	Navigation(savePosition);
}
void Room_Clear_Right() {


	cout << "\n\t\t Вы подходите к окну. За ним вид скалы у подножья которых, щетиной расположился лес.\n\tКривые деревья которого наводят лишь ужас, он словно кричит \"Беги\"! Это мертвые земли.\n\tИ пока еще вы не мертвы, вы спешите вернуться назад.\n";
	system("pause");
	system("cls");
	Navigation(savePosition);
}
/*void corpse(char sroom[27][25]) {   \\ я пытался....

	for (int i = 16; i < 21; i++) {
		for (int j = 11; j < 16; j++)
		{
			sroom[i][j] = ' ';
		}
	}
	sroom[21][10] = ' ';
	sroom[21][14] = ' ';
	sroom[21][11] = '*';
	sroom[21][13] = '*';
	sroom[22][11] = 'X';
	sroom[22][13] = 'X';
	sroom[23][10] = '#';
	sroom[23][14] = '#';
	sroom[24][11] = '#';
	sroom[24][11] = ' ';
	sroom[24][13] = '#';
}*/

void Room_A1() {
	savePosition = 1;
	mobName = "Приведение";
	mobExp = 1;
	giveMana = 1;


	system("cls");

	char room[27][25]{

		{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' },//0
		{ '#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#' },//1
		{ '#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#' },//2
		{ '#',' ',' ','*',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','#' },//3
		{ '#',' ',' ',' ','*',' ',' ',' ',' ',' ','#','#','#','#','#',' ',' ',' ',' ',' ','*',' ',' ',' ','#' },//4
		{ '#',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#' },//5
		{ '#',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','/','|','\\',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','#' },//6
		{ '#',' ','#',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#',' ','#' },//7
		{ '#',' ','#','#',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ','#','#',' ','#' },//8
		{ '#',' ','#',' ','#',' ',' ',' ','#',' ','#','#','#','#','#',' ','#',' ',' ',' ','#',' ','#',' ','#' },//9
		{ '#',' ','#',' ','*','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },//10
		{ '#',' ','#','*','*','#',' ',' ','#',' ','#',' ',' ','*','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },//11
		{ '#',' ','#',' ','*','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },//12
		{ '#',' ','#',' ','*','#',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ','#','*',' ','#',' ','#' },//13
		{ '#',' ','#',' ','#',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#',' ',' ','#',' ','#' },//14
		{ '#',' ','#','#',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#',' ',' ','#',' ','#' },//15
		{ '#',' ','#',' ',' ','#',' ',' ',' ',' ',' ','*','#','*',' ',' ',' ',' ',' ','#',' ',' ','#',' ','#' },//16
		{ '#',' ',' ',' ','#',' ',' ',' ',' ',' ','*','#','#','#','*',' ',' ',' ',' ',' ','#',' ','#',' ','#' },//17
		{ '#',' ',' ','#',' ',' ',' ',' ',' ',' ','#',' ','#',' ','#',' ',' ',' ',' ',' ',' ','#','#',' ','#' },//18
		{ '#',' ','#',' ',' ',' ',' ',' ',' ',' ','#','#','#','#','#',' ',' ',' ',' ',' ',' ',' ','#',' ','#' },//19
		{ '#','*',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ','*','#' },//20
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },//21
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#','#','#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },//22
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },//23
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },//24
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },//25
		{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' }//26
		// 0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19  20  21  22  23  24
	};
	if (!mobId[1]) {
		for (int i = 16; i < 21; i++) {
			for (int j = 11; j < 16; j++)
			{
				room[i][j] = ' ';
			}
		}
		room[21][10] = ' ';
		room[21][14] = ' ';
		room[21][11] = '*';
		room[21][13] = '*';
		room[22][11] = 'X';
		room[22][13] = 'X';
		room[23][10] = '#';
		room[23][14] = '#';
		room[24][11] = '#';
		room[24][11] = ' ';
		room[24][13] = '#';
	}

	cout << "\t\t\t\t\t";
	for (int t = 0; t < 27; t++)
	{
		for (int i = 0; i < 25; i++)
		{
			cout << room[t][i];
		}
		cout << endl << "\t\t\t\t\t";
	}
	cout << endl;
	if (mobId[1])
	{
		TextWindow();
		//cout << "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123|5678|__|"; - 'это разметка текста.
		cout << "\t|                                                                                                  |" << endl << "\t|";
		cout << "\tВорвавшись в эту комнату ты натыкаешься на " << mobName << "! Очень жаль " << playerName << "." << endl;
		cout << "\t|Тебе придется сражаться!                                                                          |" << endl;
		cout << "\t|                                                                                                  |" << endl;
		TextWindow();

	rechoice:
		Fight(2, 1);
		Interface();
	}
	else {

		TextWindow();
		//cout << "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123|5678|__|"; - 'это разметка текста.
		cout << "\t|                                                                                                  |" << endl << "\t|";
		cout << "\tВ комнате остался лишь трупак " << mobName << "\bя. Зато вы находите ключ!" << playerName << " - ты везунчик!" << endl;

		key += giveKey;
		giveKey = 0;
		//Нужно прибавку ключа реализовать другим образом!! и кек ничего нет, тоже выпадает в инвентарь, надо починить.
		cout << "\t|                                                                                                  |" << endl;
		cout << "\t|Пора убираться от сюда! Куда отправимся?                                                          |" << endl;
		cout << "\t|                                                                                                  |" << endl;
		TextWindow();
		cout << "\t Сделайте выбор : ";
		Action(0);
		int choice;
		cin >> choice;

		switch (choice)
		{
		case 1:

			Navigation(4);
			break;
		case 2:
			Navigation(101);
			break;
		case 3:
			Navigation(2);
			break;
		case 4:
			Navigation(102);
			break;


		default:
			cout << "Неверный выбор";
			goto rechoice;
			break;
		}

	}




}
void Room_A2() {
	savePosition = 2;
	char room[27][25]{

		{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' },
		{ '#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#' },
		{ '#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#' },
		{ '#',' ',' ','*',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','#' },
		{ '#',' ',' ',' ','*',' ',' ',' ',' ',' ','#','#','#','#','#',' ',' ',' ',' ',' ','*',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','/','|','\\',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','#' },
		{ '#',' ','#',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#',' ','#' },
		{ '#',' ','#','#',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ','#','#',' ','#' },
		{ '#',' ','#',' ','#',' ',' ',' ','#',' ','#','#','#','#','#',' ','#',' ',' ',' ','#',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ','*','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ','*','#',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ','#','*',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#','*',' ',' ',' ','#','*','*','*','#',' ',' ',' ','*','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ',' ','#',' ',' ','*',' ',' ','#',' ',' ',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ','#',' ',' ',' ',' ','#','#','#','#','#','#','#',' ',' ',' ',' ','#',' ','#',' ','#' },
		{ '#',' ','#','#',' ',' ',' ',' ',' ','#',' ',' ','V',' ',' ','#',' ',' ',' ',' ',' ','#','#',' ','#' },
		{ '#',' ','#',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ','#',' ','#' },
		{ '#','*',' ',' ',' ',' ',' ',' ',' ','#','#','#','#','#','#','#',' ',' ',' ',' ',' ',' ',' ','*','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' }
	};


	cout << "\t\t\t\t\t";
	for (int t = 0; t < 27; t++)
	{
		for (int i = 0; i < 25; i++)
		{
			cout << room[t][i];
		}
		cout << endl << "\t\t\t\t\t";
	}
	cout << endl;
	TextWindow();
	//cout << "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123|5678|__|"; - 'это разметка текста.
	cout << "\t|                                                                                                  |" << endl << "\t|";
	cout << "\tВорвавшись в эту комнату ты наблюдаешь лишь сундук. Если есть ключ, попытай счастье!       |" << endl;
	cout << "\t|                                                                                                  |" << endl;
	TextWindow();

rechoice:
	Action(1);
	Interface();

	cout << endl << endl << "\t\t\t\t\tСделайте выбор : ";
	cin >> choice;
	switch (choice) {
	case 1:
		Navigation(5);
		break;
	case 2:
		Navigation(1);
		break;
	case 3:
		Navigation(3);
		break;
	case 4:
		cout << "\n\t\tЭй! " << playerName << ", пути назад уже нет. Только в перед!";
		system("pause");
		goto rechoice;
	case 5:
		if (chekCloseChest[2] == true) {
			Navigation(0);

		}
		else {

			cout << "\n\n\t\t\t\t Э-э-э, вообщето вы уже открывали этот сундук. Выберите, что ни будь другое!";
			system("pause");
			goto rechoice;
		}
		break;
	default:
		break;
	}

}
void Room_A3() {
	char room[27][25]{

		{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' },
		{ '#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#' },
		{ '#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#' },
		{ '#',' ',' ','*',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','#' },
		{ '#',' ',' ',' ','*',' ',' ',' ',' ',' ','#','#','#','#','#',' ',' ',' ',' ',' ','*',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','/','|','\\',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','#' },
		{ '#',' ','#',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#',' ','#' },
		{ '#',' ','#','#',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ','#','#',' ','#' },
		{ '#',' ','#',' ','#',' ',' ',' ','#',' ','#','#','#','#','#',' ','#',' ',' ',' ','#',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ','*','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ','*','#',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ','#','*',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ','#' },
		{ '#',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ','#' },
		{ '#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#' },
		{ '#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' }
	};


	cout << "\t\t\t\t\t";
	for (int t = 0; t < 27; t++)
	{
		for (int i = 0; i < 25; i++)
		{
			cout << room[t][i];
		}
		cout << endl << "\t\t\t\t\t";
	}
}
void Room_A4() {
	char room[27][25]{

		{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' },
		{ '#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#' },
		{ '#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#' },
		{ '#',' ',' ','*',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','#' },
		{ '#',' ',' ',' ','*',' ',' ',' ',' ',' ','#','#','#','#','#',' ',' ',' ',' ',' ','*',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','/','|','\\',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','#' },
		{ '#',' ','#',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#',' ','#' },
		{ '#',' ','#','#',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ','#','#',' ','#' },
		{ '#',' ','#',' ','#',' ',' ',' ','#',' ','#','#','#','#','#',' ','#',' ',' ',' ','#',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ','*','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ','*','#',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ','#','*',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ','#' },
		{ '#',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ','#' },
		{ '#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#' },
		{ '#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' }
	};


	cout << "\t\t\t\t\t";
	for (int t = 0; t < 27; t++)
	{
		for (int i = 0; i < 25; i++)
		{
			cout << room[t][i];
		}
		cout << endl << "\t\t\t\t\t";
	}
}
void Room_A5() {
	char room[27][25]{

		{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' },
		{ '#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#' },
		{ '#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#' },
		{ '#',' ',' ','*',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','#' },
		{ '#',' ',' ',' ','*',' ',' ',' ',' ',' ','#','#','#','#','#',' ',' ',' ',' ',' ','*',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','/','|','\\',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','#' },
		{ '#',' ','#',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#',' ','#' },
		{ '#',' ','#','#',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ','#','#',' ','#' },
		{ '#',' ','#',' ','#',' ',' ',' ','#',' ','#','#','#','#','#',' ','#',' ',' ',' ','#',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ','*','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ','*','#',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ','#','*',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ','#' },
		{ '#',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ','#' },
		{ '#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#' },
		{ '#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' }
	};


	cout << "\t\t\t\t\t";
	for (int t = 0; t < 27; t++)
	{
		for (int i = 0; i < 25; i++)
		{
			cout << room[t][i];
		}
		cout << endl << "\t\t\t\t\t";
	}
}
void Room_A6() {
	char room[27][25]{

		{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' },
		{ '#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#' },
		{ '#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#' },
		{ '#',' ',' ','*',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','#' },
		{ '#',' ',' ',' ','*',' ',' ',' ',' ',' ','#','#','#','#','#',' ',' ',' ',' ',' ','*',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','/','|','\\',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','#' },
		{ '#',' ','#',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#',' ','#' },
		{ '#',' ','#','#',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ','#','#',' ','#' },
		{ '#',' ','#',' ','#',' ',' ',' ','#',' ','#','#','#','#','#',' ','#',' ',' ',' ','#',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ','*','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ','*','#',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ','#','*',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ','#' },
		{ '#',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ','#' },
		{ '#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#' },
		{ '#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' }
	};


	cout << "\t\t\t\t\t";
	for (int t = 0; t < 27; t++)
	{
		for (int i = 0; i < 25; i++)
		{
			cout << room[t][i];
		}
		cout << endl << "\t\t\t\t\t";
	}
}
void Room_A7() {
	char room[27][25]{

		{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' },
		{ '#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#' },
		{ '#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#' },
		{ '#',' ',' ','*',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','#' },
		{ '#',' ',' ',' ','*',' ',' ',' ',' ',' ','#','#','#','#','#',' ',' ',' ',' ',' ','*',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','/','|','\\',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','#' },
		{ '#',' ','#',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#',' ','#' },
		{ '#',' ','#','#',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ','#','#',' ','#' },
		{ '#',' ','#',' ','#',' ',' ',' ','#',' ','#','#','#','#','#',' ','#',' ',' ',' ','#',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ','*','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ','*','#',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ','#','*',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ','#' },
		{ '#',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ','#' },
		{ '#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#' },
		{ '#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' }
	};


	cout << "\t\t\t\t\t";
	for (int t = 0; t < 27; t++)
	{
		for (int i = 0; i < 25; i++)
		{
			cout << room[t][i];
		}
		cout << endl << "\t\t\t\t\t";
	}
}
void Room_A8() {
	char room[27][25]{

		{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' },
		{ '#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#' },
		{ '#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#' },
		{ '#',' ',' ','*',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','#' },
		{ '#',' ',' ',' ','*',' ',' ',' ',' ',' ','#','#','#','#','#',' ',' ',' ',' ',' ','*',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','/','|','\\',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','#' },
		{ '#',' ','#',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#',' ','#' },
		{ '#',' ','#','#',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ','#','#',' ','#' },
		{ '#',' ','#',' ','#',' ',' ',' ','#',' ','#','#','#','#','#',' ','#',' ',' ',' ','#',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ','*','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ','*','#',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ','#','*',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ','#' },
		{ '#',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ','#' },
		{ '#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#' },
		{ '#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' }
	};


	cout << "\t\t\t\t\t";
	for (int t = 0; t < 27; t++)
	{
		for (int i = 0; i < 25; i++)
		{
			cout << room[t][i];
		}
		cout << endl << "\t\t\t\t\t";
	}
}
void Room_A9() {
	char room[27][25]{

		{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' },
		{ '#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#' },
		{ '#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#' },
		{ '#',' ',' ','*',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','#' },
		{ '#',' ',' ',' ','*',' ',' ',' ',' ',' ','#','#','#','#','#',' ',' ',' ',' ',' ','*',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','/','|','\\',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','#' },
		{ '#',' ','#',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#',' ','#' },
		{ '#',' ','#','#',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ','#','#',' ','#' },
		{ '#',' ','#',' ','#',' ',' ',' ','#',' ','#','#','#','#','#',' ','#',' ',' ',' ','#',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ','*','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ','*','#',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ','#','*',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ','#' },
		{ '#',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ','#' },
		{ '#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#' },
		{ '#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' }
	};


	cout << "\t\t\t\t\t";
	for (int t = 0; t < 27; t++)
	{
		for (int i = 0; i < 25; i++)
		{
			cout << room[t][i];
		}
		cout << endl << "\t\t\t\t\t";
	}
}
void Room_A10() {
	char room[27][25]{

		{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' },
		{ '#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#' },
		{ '#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#' },
		{ '#',' ',' ','*',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','#' },
		{ '#',' ',' ',' ','*',' ',' ',' ',' ',' ','#','#','#','#','#',' ',' ',' ',' ',' ','*',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','/','|','\\',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','#' },
		{ '#',' ','#',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#',' ','#' },
		{ '#',' ','#','#',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ','#','#',' ','#' },
		{ '#',' ','#',' ','#',' ',' ',' ','#',' ','#','#','#','#','#',' ','#',' ',' ',' ','#',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ','*','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ','*','#',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ','#','*',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ','#' },
		{ '#',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ','#' },
		{ '#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#' },
		{ '#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' }
	};


	cout << "\t\t\t\t\t";
	for (int t = 0; t < 27; t++)
	{
		for (int i = 0; i < 25; i++)
		{
			cout << room[t][i];
		}
		cout << endl << "\t\t\t\t\t";
	}
	cout << "Если ты попал сюда, то чо то не так.";
	system("pause");
	system("cls");
}
void Room_A11() {
	char room[27][25]{

		{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' },
		{ '#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#' },
		{ '#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#' },
		{ '#',' ',' ','*',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','#' },
		{ '#',' ',' ',' ','*',' ',' ',' ',' ',' ','#','#','#','#','#',' ',' ',' ',' ',' ','*',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','/','|','\\',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','#' },
		{ '#',' ','#',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#',' ','#' },
		{ '#',' ','#','#',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ','#','#',' ','#' },
		{ '#',' ','#',' ','#',' ',' ',' ','#',' ','#','#','#','#','#',' ','#',' ',' ',' ','#',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ','*','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ','*','#',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ','#','*',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ','#' },
		{ '#',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ','#' },
		{ '#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#' },
		{ '#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' }
	};


	cout << "\t\t\t\t\t";
	for (int t = 0; t < 27; t++)
	{
		for (int i = 0; i < 25; i++)
		{
			cout << room[t][i];
		}
		cout << endl << "\t\t\t\t\t";
	}
}
void Room_A12() {
	char room[27][25]{

		{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' },
		{ '#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#' },
		{ '#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#' },
		{ '#',' ',' ','*',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','#' },
		{ '#',' ',' ',' ','*',' ',' ',' ',' ',' ','#','#','#','#','#',' ',' ',' ',' ',' ','*',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','/','|','\\',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','#' },
		{ '#',' ','#',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#',' ','#' },
		{ '#',' ','#','#',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ','#','#',' ','#' },
		{ '#',' ','#',' ','#',' ',' ',' ','#',' ','#','#','#','#','#',' ','#',' ',' ',' ','#',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ','*','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ','*','#',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ','#','*',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ','#' },
		{ '#',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ','#' },
		{ '#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#' },
		{ '#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' }
	};


	cout << "\t\t\t\t\t";
	for (int t = 0; t < 27; t++)
	{
		for (int i = 0; i < 25; i++)
		{
			cout << room[t][i];
		}
		cout << endl << "\t\t\t\t\t";
	}
}
void Room_A13() {
	char room[27][25]{

		{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' },
		{ '#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#' },
		{ '#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#' },
		{ '#',' ',' ','*',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','#' },
		{ '#',' ',' ',' ','*',' ',' ',' ',' ',' ','#','#','#','#','#',' ',' ',' ',' ',' ','*',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','/','|','\\',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','#' },
		{ '#',' ','#',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#',' ','#' },
		{ '#',' ','#','#',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ','#','#',' ','#' },
		{ '#',' ','#',' ','#',' ',' ',' ','#',' ','#','#','#','#','#',' ','#',' ',' ',' ','#',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ','*','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ','*','#',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ','#','*',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ','#' },
		{ '#',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ','#' },
		{ '#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#' },
		{ '#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' }
	};


	cout << "\t\t\t\t\t";
	for (int t = 0; t < 27; t++)
	{
		for (int i = 0; i < 25; i++)
		{
			cout << room[t][i];
		}
		cout << endl << "\t\t\t\t\t";
	}
}
void Room_A14() {
	char room[27][25]{

		{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' },
		{ '#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#' },
		{ '#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#' },
		{ '#',' ',' ','*',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','#' },
		{ '#',' ',' ',' ','*',' ',' ',' ',' ',' ','#','#','#','#','#',' ',' ',' ',' ',' ','*',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','/','|','\\',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','#' },
		{ '#',' ','#',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#',' ','#' },
		{ '#',' ','#','#',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ','#','#',' ','#' },
		{ '#',' ','#',' ','#',' ',' ',' ','#',' ','#','#','#','#','#',' ','#',' ',' ',' ','#',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ','*','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ','*','#',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ','#','*',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ','#' },
		{ '#',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ','#' },
		{ '#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#' },
		{ '#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' }
	};


	cout << "\t\t\t\t\t";
	for (int t = 0; t < 27; t++)
	{
		for (int i = 0; i < 25; i++)
		{
			cout << room[t][i];
		}
		cout << endl << "\t\t\t\t\t";
	}
}
void Room_A15() {
	char room[27][25]{

		{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' },
		{ '#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#' },
		{ '#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#' },
		{ '#',' ',' ','*',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','#' },
		{ '#',' ',' ',' ','*',' ',' ',' ',' ',' ','#','#','#','#','#',' ',' ',' ',' ',' ','*',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','/','|','\\',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','#' },
		{ '#',' ','#',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#',' ','#' },
		{ '#',' ','#','#',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ','#','#',' ','#' },
		{ '#',' ','#',' ','#',' ',' ',' ','#',' ','#','#','#','#','#',' ','#',' ',' ',' ','#',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ','*','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ','*','#',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ','#','*',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','#',' ','#' },
		{ '#',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ','#' },
		{ '#',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ','#' },
		{ '#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#' },
		{ '#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#' },
		{ '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' }
	};


	cout << "\t\t\t\t\t";
	for (int t = 0; t < 27; t++)
	{
		for (int i = 0; i < 25; i++)
		{
			cout << room[t][i];
		}
		cout << endl << "\t\t\t\t\t";
	}
	cout << "Если ты попал сюда, то чо то не так.";
	system("pause");
	system("cls");
}


//закончились комнаты!!
