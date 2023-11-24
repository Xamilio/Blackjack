#include <iostream>
#include <string>

using namespace std;
using std::cin;

//Назначение символам карты(0-12)
string rankPicture[13] = { "2", "3", "4", "5", "6", "7", "8","9", "10", "V", "D", "K", "A"};
//Назначение ценности карты(0-12)
int points[13] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11};

//карты в руке дилера и плеера
string dealerPack = "";
string playersPack = "";

//Создаем функцию рисующию карту по ее номеру(0-52)
void showCart(int cart)
{
	int mast = cart / 13; //Номер масти
	int rank = cart % 13; //Номер карты в масте
	char mastChar = static_cast<char>(mast + 3);//Находим символ масти по номеру
	cout << mastChar;//выводим символ масти карты
	cout << rankPicture[rank];//выводим символ ценности карты
}
//Создаем функцию расчета очков в руке
int calculPoint(string pack) 
{
	int sum = 0;
	for (int i = 0; i < pack.length(); i++)
	{
		int card = pack[i];//Получаем номер карты
		int rank = card % 13;//Номер карты в масте
		int point = points[rank]; //Получаем ценность карты
		if (point == 11 && sum > 10) point = 1;//Уточняем ценность для туза
		sum = sum + point; //Формеруем суммму
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
	cout << "    *         Добро пожаловать в Blackjack(21)            *" << endl;
	cout << "    *             Правила: тянуть по 1 карте              *" << endl;
	cout << "    *      Главное не взять больше 21 очка в сумме        *" << endl;
	cout << "    *                                                     *" << endl;
	cout << "    *******************************************************" << endl;

	//Раздача карт
	srand(time(NULL));
	playersPack = playersPack + char(rand() % 52);
	dealerPack = dealerPack + char(rand() % 52);
	playersPack = playersPack + char(rand() % 52);
	dealerPack = dealerPack + char(rand() % 52);

	while(true)
	{
		cout << "************ Ваш ход ************\n";
		//1. Показываем карты	Игрока		
		cout << "Ваши карты:      ";
		for (int i = 0; i < playersPack.length(); i++)
		{
			showCart(playersPack[i]);
			cout << " ";
		}
		cout << "   У вас в руке: " << calculPoint(playersPack) << " Очков";
		cout << "\n";

		//2. Показываем карту дилера
		cout << "Карты компютера: ";
		showCart(dealerPack[0]);
		cout << " **";
		cout << "\n";

		//3. Проверяем на перебор
		if (calculPoint(playersPack) > 21)
		{
			cout << "Перебор! Игрок проиграл!\n";
			return 0;
		}

		//4. Запрашиваем действие Игрока	
		char answer;
		cout << "Взять карту (y / n): ";
		cin >> answer;
		if (answer != 'y' && answer != 'Y')
		{
			break;
		} 
		
		cout << "\n";
		//5. Добавлем новую карту Игроку
		playersPack = playersPack + char(rand() % 52);
	}
	while(true)
	{	
		cout << "************ Ход дилера ************\n";

		//1. Показываем карты	Игрока		
		cout << "Ваши карты:      ";
		for (int i = 0; i < playersPack.length(); i++)
		{
			showCart(playersPack[i]);
			cout << " ";
		}
		cout << "   У вас в руке: " << calculPoint(playersPack) << " Очков";
		cout << "\n";

		//2. Показываем карты дилера
		cout << "Карты компютера: ";
		for (int i = 0; i < dealerPack.length(); i++)
		{
			showCart(dealerPack[i]);
			cout << " ";
		}
		cout << "   У диллера: " << calculPoint(dealerPack) << " Очков";
		cout << "\n";

		//3. Проверка нужна ли карта дилеру
		if (calculPoint(dealerPack) > 16)
		{
			break;
		}

		//4. Диллер берет карты
		dealerPack = dealerPack + char(rand() % 52);
	}
	//Проверка кто выиграл 
	int dealers_point = calculPoint(dealerPack);
	int players_point = calculPoint(playersPack);
		if (dealers_point == 21)
		{
			cout << "*********************\n";
			cout << "Дилер выиграл\n";
			cout << "*********************\n";
			return 0;
		}
		if (dealers_point > 21)
		{
			cout << "*********************\n\n";
			cout << "Игрок выиграл\n\n";
			cout << "*********************\n";
			return 0;
		}
		if (dealers_point > players_point)
		{
			cout << "*********************\n";
			cout << "Игрок проиграл\n";
			cout << "*********************\n";
			return 0;
		}
		if (dealers_point == players_point)
		{
			cout << "*********************\n";
			cout << "Ничья\n";
			cout << "*********************\n";
			return 0;
		}
		if (dealers_point < players_point)
		{
			cout << "*********************\n";
			cout << "Игрок выиграл\n";
			cout << "*********************\n";
			return 0;
		}
}
