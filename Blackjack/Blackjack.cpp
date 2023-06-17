#include <iostream>
#include <string>

using namespace std;
using std::cin;


string rankPicture[13] = { "2", "3", "4", "5", "6", "7", "8","9", "10", "V", "D", "K", "A"};
int points[13] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11};
string computer = "";
string user = "";

void showCart(int cart)
{
	char asciiChar = static_cast<char>(cart / 13 + 3);
	cout << asciiChar;
	cout << rankPicture[cart % 13];
}
int calculPoint(string pack) 
{
	int sum = 0;
	for (int i = 0; i < pack.length(); i++)
	{
		int card = pack[i];
		int rank = card % 13;
		int point = points[rank];
		if (point == 11 && sum > 10) point = 1;
		sum = sum + point;
	}
	return sum;

}
int main()
{
	setlocale(LC_ALL, "rus");
	cout << "    *******************************************************" << endl;
	cout << "    *           _______                     _______       *" << endl;
	cout << "    *          |8      |                   |8      |      *" << endl;
	cout << "    *          | V   V |                   | V   V |      *" << endl;
	cout << "    *          | V   V |                   | V   V |      *" << endl;
	cout << "    *          | V   V |                   | V   V |      *" << endl;
	cout << "    *          | V   V |      _______      | V   V |      *" << endl;
	cout << "    *          |       |     |9      |     |       |      *" << endl; 
	cout << "    *          |______8|     | V V V |     |______8|      *" << endl;
	cout << "    *                        |       |                    *" << endl;
	cout << "    *                        | V V V |                    *" << endl;	
	cout << "    *                        |       |                    *" << endl;
	cout << "    *                        | V V V |                    *" << endl;
	cout << "    *                        |______6|                    *" << endl;
	cout << "    *                                                     *" << endl;
	cout << "    *                                                     *" << endl;
	cout << "    *******************************************************" << endl;
	cout << "    *         Добро пожаловать в Blackjack(21-Очко)       *" << endl;
	cout << "    *             Правила: тянуть по 1 карте              *" << endl;
	cout << "    *      Главное не перебрать больше 21 очка в сумме    *" << endl;
	cout << "    *                                                     *" << endl;
	cout << "    *******************************************************" << endl;

	//Раздача карт
	srand(time(NULL));
	user = user + char(rand() % 52);
	computer = computer + char(rand() % 52);
	user = user + char(rand() % 52);
	computer = computer + char(rand() % 52);

	while(true)
	{
		cout << "************ Ваш ход ************\n";
		//Показываем карты	user		
		cout << "Ваши карты:      ";
		for (int i = 0; i < user.length(); i++)
		{
			showCart(user[i]);
			cout << " ";
		}
		cout << "\n";

		//Показываем карты	computer
		cout << "Карты компютера: ";
		showCart(computer[0]);
		cout << " **";
		cout << "\n";

		//Проверка пользыывателя
		int point = calculPoint(user);
		if (point == 21) 
		{
			if (user.length() > 2)
			{
				break;
			}
			cout << "User выиграл\n";
			return 0;
		}
		if (point > 21)
		{
			cout << "User проиграл\n";
			return 0;
		}

		//Запрашиваем действие user		
		char answer;
		cout << "Взять карту (y / n): ";
		cin >> answer;
		if (answer != 'y' && answer != 'Y')
		{
			break;
		} 
		cout << "\n";
		//Добавлем новую карту пользывателя
		user = user + char(rand() % 52);
	}
	while(true)
	{
		//Показываем карты	user		
		cout << "Ваши карты:      ";
		for (int i = 0; i < user.length(); i++)
		{
			showCart(user[i]);
			cout << " ";
		}
		cout << "\n";

		//Показываем карты	computer
		cout << "Карты компютера: ";
		for (int i = 0; i < computer.length(); i++)
		{
			showCart(computer[i]);
			cout << " ";
		}
		cout << "\n";

		int point = calculPoint(computer);
		
		if (point == 21)
		{
			cout << "Computer выиграл\n";
			return 0;
		}
		if (point > 21)
		{
			cout << "Computer проиграл\n";
			return 0;
		}
		int point_u = calculPoint(user);
		if (point >= 17) 
		{
			if (point > point_u)
			{
				cout << "Computer выиграл\n";
				return 0;
			}
			if (point == point_u)
			{
				cout << "Ничья\n";
				return 0;
			}
			if (point < point_u)
			{
				cout << "User выиграл\n";
				return 0;
			}
		}
		cout << "************ Ход компютера ************\n";
		computer = computer + char(rand() % 52);
	}
	
}
