#include "Serviсe.hpp"
#include "Storage.hpp"


size_t sizeSt = 0;
size_t* idArr = nullptr;
std::wstring* nameArr = nullptr;
size_t* countArr = nullptr;
double* priceArr = nullptr;
bool isStorageCreated = false;
double maxPrice = 1500000;

size_t maxStorageSize = 20000;
size_t currentStorageSize = 0;

void CreateStorage(int mode)
{
	if (mode == 0 && !isStorageCreated)
	{
		const size_t staticSize = 10;

		size_t idArrStatic[staticSize]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		std::wstring nameArrStatic[staticSize]
		{
			//Товары надо!!!!
		};
		size_t countArrStatic[staticSize]{ 14, 30, 9, 18, 23, 7, 22, 40, 10, 3 };
		double priceArrStatic[staticSize]{ 143.3, 210.4, 452.1, 377.3, 116.8, 287.2, 140.4, 210.3, 899.9, 1900.0 };

		sizeSt = staticSize;
		idArr = new size_t[sizeSt];
		nameArr = new std::wstring[sizeSt];
		countArr = new size_t[sizeSt];
		priceArr = new double[sizeSt];

		FillArray(idArrStatic, idArr, sizeSt);
		FillArray(nameArrStatic, nameArr, sizeSt);
		FillArray(countArrStatic, countArr, sizeSt);
		FillArray(priceArrStatic, priceArr, sizeSt);

		for (size_t i = 0; i < sizeSt; i++)
		{
			currentStorageSize += countArrStatic[i];
		}
		isStorageCreated = true;
	}

	else if (mode == 1)
	{
		// TO_DO
	}

	else
	{
		std::wcout << L"Склад уже создан\n\n";
		Sleep(500);
	}
}
void ShowStorage(int mode)
{
	if (mode == 0)
	{
		system("cls");

		std::wcout << L"\n\n\t\tТовары \"PMS\"\n\n";

		std::wcout << L"ID\t" << std::left << std::setw(40) << L"Название товара\t\t"
			<< L"Кол-во\t" << L"Цена\n\n";
		for (size_t i = 0; i < sizeSt; i++)
		{
		std::wcout << idArr[i] << L"\t" << std::setw(40) << nameArr[i]
			<< L"\t" << priceArr[i] << L"\n";

		}
		std::wcout << L"\n\n";
		system("pause");
	}
	else if (mode == 1)
	{
		system("cls");

		std::wcout << L"\n\n\t\tПополнение товаров \"PMS\"\n\n";

		std::wcout << L"ID\t" << std::left << std::setw(40) << L"Название товара\t\t"
			<< L"Кол-во\n\n";
		for (size_t i = 0; i < sizeSt; i++)
		{
			std::wcout << idArr[i] << L"\t" << std::setw(40) << nameArr[i];

		}
		std::wcout << L"\n\n";
		system("peuse");
	}
	else if (mode == 2)
	{

	}
	else if (mode == 3)
	{
		system("cls");

			std::wcout << L"";
	}
}
void AddProduct()
{
	std::wstring chooseId, chooseCount, choose;

	while (true)
	{
		ShowStorage(1);

		std::wcout << L"Введите ID товары или \"exit\" для выхода: ";
		Getline(chooseId);

		if (chooseId == L"exit" || chooseId == L"Exit")
		{
			std::wcout << L"Завершение операции пополнения товара\n\n";
			Sleep(1500);
			return;

		}
		else if (IsNumber(chooseId))
		{
			int id = std::stoi(chooseId) - 1;
			if (id < 0 || id > sizeSt - 1)
			{
				Err();
			}
			else
			{
				std::wcout << L"Введите кол-во товара для пополнения: ";
				Getline(chooseCount);
				if (IsNumber(chooseCount))
				{
					size_t count = std::stoull(chooseCount);
					if (count < 0)
					{
						size_t count = std::stoull(chooseCount);
						if (count < 0 || count > maxStorageSize - currentStorageSize)
						{
							std::wcout << L"Некорректное кол-во! НА складе " <<
								maxStorageSize - currentStorageSize << L"Свободных мест\n\n";
							Sleep(2000);
						}
						else
						{
							while (true)
							{
								system("cls");
								std::wcout << nameArr[id] << L"\t" << countArr[id] << L"------> "
									<< countArr[id] + count << L"\n\n";
								std::wcout << L"Подтердить?\n1 - Да\n2 - Нет\n\nВвод: ";
								Getline(choose);
							}
							if (choose == L"1")
							{
								std::wcout << L"";
							}

						}

					}

				}

			}

		}

	}

}

void RemoveProduct()
{

}
void ChangePrice()
{
	std::wstring chooseId, chooseCount, choose;

	while (true)
	{
		ShowStorage(1);
			std::wcout << L"Введите ID товара или \"exit\" для выхода: ";
			Getline(chooseId);

			if (chooseId == L"exit" || chooseId == L"Exit")
			{

			}
	}
}
void ChangStoge()
{
	std::wstring choose;
	while (true)
	{
		system("cls");

		std::wcout << L"\t\tМеню Супер Администратора\n\n";
		std::wcout << L"1 - Добавить новый товар\n";
		std::wcout << L"2 - Изменить название товара\n";
		std::wcout << L"3 - Удаление товара\n";
		std::wcout << L"4 - Изменить лимиты склада\n";
		std::wcout << L"0 - Выход\n";
		Getline(choose);

		if (choose == L"1")
		{
			AddNewProduct();
		}
		else if (choose == L"2")
		{
			
		}
		else if (choose == L"3")
		{
			
		}
		else if (choose == L"4")
		{

		}
		else if (choose == L"0")
		{
			std::wcout << L"\nВыход из редактора скалда\n\n";
			Sleep(1500);
			break;
		}
		else
		{
			Err();
		}
	}
}
void AddNewProduct()
{
	std::wstring chooseName, chooseCount, choosePrice, choose;
	size_t count = 0;
	double price = 0;

	while (true)
	{
		while (true)
		{
			system("cls");

			std::wcout << L"Введите название нового товара или \"exit\" для выхода: ";
			Getline(chooseName);
			if (chooseName == L"exit" || chooseName == L"Exit")
			{
				std::wcout << L"Отмена добавления нового товара\n\n";
				Sleep(1500);
				return;
			}
			if (chooseName.size() > 40 || chooseName.size() < 3)
			{
				std::wcout << L"Ошибка длины названия товара\nДопустимое значение от 3 до 40 символов\n\n";
				Sleep(1500);
			}
			if (IsNotSame(chooseName, nameArr, sizeSt))
			{
				break;
			}
			else
			{
				std::wcout << L"Данный товар уже есть на складе\n\n";
			}
		}

		while (true)
		{
			system("cls");

			std::wcout << L"Введите название товара \"exit\" для выхода: ";
			Getline(chooseName);
			if (chooseName == L"exit" || chooseName == L"Exit")
			{
				std::wcout << L"Отмена добавления нового товара\n\n";
				Sleep(1500);
				return;
			}
			if (IsNumber(chooseCount))
			{
				size_t count = std::stoull(chooseCount);
				if (count < 0)
				{
					size_t count = std::stoull(chooseCount);
					if (count < 0 || count > maxStorageSize - currentStorageSize)
					{
						std::wcout << L"Некорректное кол-во! НА складе " <<
							maxStorageSize - currentStorageSize << L"Свободных мест\n\n";
						Sleep(2000);
					}
					else
					{
						break;
					}

				}

			}

		}

		while (true)
		{
			system("cls");

			std::wcout << L"Введите цену нового товара \"exit\" для выхода: ";
			Getline(chooseName);
			if (chooseName == L"exit" || chooseName == L"Exit")
			{
				std::wcout << L"Отмена добавления нового товара\n\n";
				Sleep(1500);
				return;
			}
				if (IsNumber(choosePrice))
				{
					std::wcout << L"Некоректная цена! Максимально возможная цена " <<
						maxPrice << L"рублей\n\n";
					Sleep(2000);
				}
				else
				{
					break;
				}
			
			
		}

		while (true)
		{
			system("cls");

			std::wcout << L"Новый товар: " << chooseName << L"\n";
			std::wcout << L"Кол-во: " << count << L"\n";
			std::wcout << L"Цена: " << price << L"\n";
			std::wcout << L"Подтвердить?\n 1 - Да\n2 - Нет\n\nВвод: ";
			Getline(choose);
			if (choose == L"1")
			{
				std::wcout << L"Загрузка новыйх данных в базу данных...";
				Sleep(2000);
				ArrPushBack(idArr, sizeSt);
				ArrPushBack(nameArr, sizeSt);
				ArrPushBack(countArr, sizeSt);
				ArrPushBack(priceArr, sizeSt);
				sizeSt++;
				idArr[sizeSt - 1] = sizeSt;
				nameArr[sizeSt - 1] = chooseName;
				countArr[sizeSt - 1] = count;
				priceArr[sizeSt - 1] = price;
				currentStorageSize += count;
				//:)
				std::wcout << L"\n\nНовый товар успешно добавлен!\n\n";
				Sleep(1500);
				break;
			}
			else if (choose == L"2")
			{
				std::wcout << L"Отмена\n\n";
				Sleep(1400);
				break;
			}
			else
			{
				Err();
			}

		}


	}


}
