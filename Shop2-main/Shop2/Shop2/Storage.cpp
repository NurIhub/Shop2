
#include "Storage.hpp"

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void SetColor(WORD color)
{
	SetConsoleTextAttribute(hConsole, color);
}

// категории: с какого индекса начинаются, название, цвет
const size_t catCount = 5;
const size_t catStart[catCount] = { 0, 5, 12, 16, 22 };
const wchar_t* catName[catCount] =
{
	L"Смартфоны и гаджеты",
	L"Компьютеры и комплектующие",
	L"ТВ и развлечения",
	L"Бытовая техника",
	L"Прочее"
};
const WORD catColor[catCount] = { 11, 10, 14, 13, 12 };


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
		const size_t staticSize = 30;

		size_t idArrStatic[staticSize]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25 };
		std::wstring nameArrStatic[staticSize]
		{
			L"Смартфоны и гаджеты",
			L"Смартфон Samsunk Galaxy Z Flip Flop 8/256GB Black",
			L"Смартфон Xiaomy Redmi Note 12 Pro Max Ultra Plus 12/512GB",
			L"Смартфон Appel iPhome 15 Pro Max 1TB Titanium",
			L"Смарт-часы Huavey Watch GT 4 Pro Картошка Edition",
			L"Наушники TWS Sonya WF-1000XM5 Шумоподавление Соседей",

			L"Компьютеры и комплектующие",
			L"Ноутбук ASOS ROG Strix G16 i9/32GB/RTX 4070/1TB",
			L"Ноутбук Lenova IdeaPad Slim 3 Тормозит но Дёшево 8/256GB",
			L"Монитор LG UltraGear 27\" 165Hz Чтобы Видеть Врагов",
			L"Видеокарта GigaByte GeForce RTX 4090 Только Для Богатых 24GB",
			L"Клавиатура Razor BlackWidow V4 Громче Чем Мысли",
			L"Мышь Logitek G502 Hero Ловит Только Мух",
			L"SSD Samsunk 990 Pro 2TB Для Хранения Фоток Кота",

			L"ТВ и развлечения",
			L"Телевизор Sunny Bravia 65\" 4K OLED Видно Даже Пыль на Экране",
			L"Игровая консоль Sonya PlayStation 5 Slim Для Тех Кто Не Выходит из Дома",
			L"Саундбар JBL Bar 500 Слышно Всем Подъездом",
			L"Проектор XGIMI Halo Plus Кино на Стене Без Ремонта",

			L"Бытовая техника",
			L"Холодильник Samsunk RB37 No Frost Хранит Только Пустоту",
			L"Стиральная машина Bosh Serie 6 Съедает Один Носок за Стирку",
			L"Робот-пылесос Roborok S8 Pro Ultra Боится Тапочек",
			L"Микроволновая печь Panasonik NN-ST34 Греет Всё Кроме Еды",
			L"Электрочайник Tefaal Ceramic 1.7L Кипит Как Преподаватель",
			L"Кофемашина DeLonghy Magnifica S Ночь Без Сна",

			L"Прочее",
			L"Игровое кресло Zone 51 Cobra Для Геймеров с Больной Спиной",
			L"Роутер TP-Linc Archer AX73 Wi-Fi 6 Пинг 999",
			L"Powerbank Xiaomy 20000mAh Заряжает Только Powerbank"
		};
		size_t countArrStatic[staticSize]{ 14, 30, 9, 18, 23, 7, 22, 40, 10, 3, 15, 25, 8, 17, 28, 6, 35, 12, 20, 4, 19, 33, 11, 29, 5 };
		double priceArrStatic[staticSize]
		{
			64990, 38990, 139990, 17490, 21990,
			189990, 41990, 22490, 189990, 12990, 5490, 14990,
			129990, 54990, 29990, 69990,
			74990, 44990, 59990, 8990, 3490, 36990,
			18990, 7990, 2990
		};

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

		std::wcout << L"ID\t" << std::left << std::setw(75) << L"Название товара\t\t"
			<< L"Цена\n\n";

		for (size_t i = 0; i < sizeSt; i++)
		{
			for (size_t k = 0; k < catCount; k++)
			{
				if (i == catStart[k])
				{
					SetColor(catColor[k]);
					std::wcout << L"\n  " << catName[k] << L"\n\n";
					SetColor(7);
				}
			}

			std::wcout << idArr[i] << L"\t" << std::setw(75) << nameArr[i]
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
			std::wcout << idArr[i] << L"\t" << std::setw(40) << nameArr[i] << L"\t" << countArr[i] << L"\t" << priceArr[i] << L"\n";
		}
		std::wcout << L"\n\n";
		std::wcout << L"Места на складе: " << currentStorageSize << L"/" << maxStorageSize << L"\n\n";
	}
	else if (mode == 2)
	{
		system("cls");

		std::wcout << L"Списание товаров \"Петы\"\n\n";

		std::wcout << L"ID\t" << std::left << std::setw(40) << L"Название товара\t\t\t\t" << L"Кол-во\t" << L"Цена\n\n";

		for (size_t i = 0; i < sizeSt; i++)
		{
			std::wcout << idArr[i] << L"\t" << std::left << std::setw(40) << nameArr[i] << L"\t" << countArr[i] << L"\t" << priceArr[i] << L"\n";
		}
		std::wcout << L"\n\n";
		std::wcout << L"Свободного метса: " << currentStorageSize << L" из " << maxStorageSize << L"\n\n";
	}
	else if (mode == 3)
	{
		system("cls");

		std::wcout << L"Изменение цен \"Петы\"\n\n";

		std::wcout << L"ID\t" << std::left << std::setw(40) << L"Название товара\t\t\t\t" << L"Цена\n\n";

		for (size_t i = 0; i < sizeSt; i++)
		{
			std::wcout << idArr[i] << L"\t" << std::fixed << std::left << std::setw(40) << nameArr[i] << L"\t" << countArr[i] << L"\t" << std::setprecision(2) << priceArr[i] << L"\n";
		}
		std::wcout << L"\n\n";
		system("pause");
	}
	else if (mode == 4)
	{
		system("cls");

		std::wcout << L"Переименование \"Техники\"\n\n";
		std::wcout << L"ID\t" << L"Название товара\t\t\t\t" << L"\n\n";

		for (size_t i = 0; i < sizeSt; i++)
		{
			std::wcout << idArr[i] << L"\t" << std::left << std::setw(40) << nameArr[i] << L"\t";
		}
		std::wcout << L"\n\n";
		system("pause");
	}
	else if (mode == 5)
	{
		system("cls");

		std::wcout << L"Удаление \"Техники\"\n\n";
		std::wcout << L"ID\t" << L"Название товара\t\t\t\t" << L"\n\n";

		for (size_t i = 0; i < sizeSt; i++)
		{
			std::wcout << idArr[i] << L"\t" << std::left << std::setw(40) << nameArr[i] << L"\t";
		}
		std::wcout << L"\n\n";
		system("pause");
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
					if (count < 0 || count > maxStorageSize - currentStorageSize)
					{
							std::wcout << L"Некорректное кол-во! На складе " <<
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
							std::wcout << L"Товар успешно пополнен\n\n";
							countArr[id] += count;
							currentStorageSize += count;
							std::wcout << L"Нажмите на любую клавишу для продолжения\n\n";
							system("pause");
							break;
						}
						if (choose == L"2")
						{
							std::wcout << L"Отмена пополнения" << nameArr[id] << L"\n";
							system("cls");
							std::wcout << L"Возват в меню пополнения товаров...\n\n";
							Sleep(1500);
						}
						else
						{
							Err();
						}

					}

					

				}

			}

		}

	}

}

void RemoveProduct()
{
	std::wstring chooseId, chooseCount, choose;

	while (true)
	{
		ShowStorage(2);

		std::wcout << L"Введите ID товара или \"exit\" для выхода: ";
		Getline(chooseId);

		if (chooseId == L"exit" || chooseId == L"Exit")
		{
			std::wcout << L"Завершение операции списания товаров\n\n";
			system("pause");
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
				std::wcout << L"Введите кол-во товара для списания: ";
				Getline(chooseCount);
				if (IsNumber(chooseCount))
				{
					size_t count = std::stoull(chooseCount);
					if (count < 0 || count > countArr[id])
					{
						std::wcout << L"Некорректное кол-во! На складе всего: " << countArr[id] << L" едениц этого товара\n\n";
						system("pause");
					}

					else
					{
						while (true)
						{
							system("cls");
							std::wcout << nameArr[id] << L"\t" << countArr[id] << L"-----> " << countArr[id] + count << L"\n\n";
							std::wcout << L"Подтвердить?\n1 - Да\n2 - Нет\n\nВвод: ";
							Getline(choose);

							if (choose == L"1")
							{
								std::wcout << L"Товар успешно списан\n\n";
								countArr[id] += count;
								currentStorageSize += count;
								system("pause");
								break;
							}

							else if (choose == L"2")
							{
								std::wcout << L"Отмена списания " << nameArr[id] << L"\n";
								system("pause");
								break;
							}

							else
							{
								Err();
							}
						}
					}
				}
			}
		}
	}
}
void ChangePrice()
{
	std::wstring chooseId, choosePrice, choose;

	while (true)
	{
		ShowStorage(1);
		std::wcout << L"Введите ID товара или \"exit\" для выхода: ";
		Getline(chooseId);

		if (chooseId == L"exit" || chooseId == L"Exit")
		{
			std::wcout << L"Завершение операции изменения цены\n\n";
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
				std::wcout << L"Введите новую цену товара: ";
				Getline(choosePrice);
				if (IsNumber(choosePrice))
				{
					double price = std::stod(choosePrice);
					if (price < 0 || price > maxPrice)
					{
						std::wcout << L"Некорректная цена! Максимально возможная цена: " << maxPrice << L"\n\n";
						system("pause");
					}
					else
					{
						while (true)
						{
							system("cls");
							std::wcout << nameArr[id] << L"\t" << priceArr[id] << L"-----> " << price << L"\n\n";
							std::wcout << L"Подтвердить?\n1 - Да\n2 - Нет\n\nВвод: ";
							Getline(choose);
							if (choose == L"1")
							{
								std::wcout << L"Цена успешно изменена\n\n";
								priceArr[id] = price;
								system("pause");
								break;
							}
							else if (choose == L"2")
							{
								std::wcout << L"Отмена изменения цены " << nameArr[id] << L"\n";
								system("pause");
								break;
							}
							else
							{
								Err();
							}
						}
					}
				}
			}
		}
	}
}
void ChangeStorage()
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
		else if (choose == L"2" && sizeSt > 0)
		{
			ChangeProductName();
		}
		else if (choose == L"3" && sizeSt > 0)
		{
			DeleteProduct();
		}
		else if (choose == L"4")
		{
			ChangeStorageLimits();
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
				count = std::stoull(chooseCount);

				if (count < 0 || count > maxStorageSize - currentStorageSize)
				{
					std::wcout << L"Некорректное кол-во! На складе " <<
						maxStorageSize - currentStorageSize << L"Свободных мест\n\n";
					Sleep(2000);
				}
				else
				{
					break;
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
void ChangeProductName()
{
	std::wstring chooseId, chooseName, choose;

	while (true)
	{
		ShowStorage(4);

		std::wcout << L"Введите ID товара или \"exit\" для выхода: ";
		Getline(chooseId);

		if (chooseId == L"exit" || chooseId == L"Exit")
		{
			std::wcout << L"Завершение операции переименования товаров\n\n";
			system("pause");
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
				std::wcout << L"Введите новое название товара: ";
				Getline(chooseName);

				if (chooseName.size() > 40 || chooseName.size() < 2)
				{
					std::wcout << L"Ошибка длины названия товара\nДопустимое значение от 2 до 40 символов\n\n";
					system("pause");
				}

				if (!IsNotSame(chooseName, nameArr, sizeSt))
				{
					std::wcout << L"Данный товар уже есть на складе\n\n";
				}

				else
				{
					while (true)
					{
						system("cls");
						std::wcout << nameArr[id] << L"\t" << nameArr[id] << L"-----> " << chooseName << L"\n\n";
						std::wcout << L"Подтвердить?\n1 - Да\n2 - Нет\n\nВвод: ";
						Getline(choose);

						if (choose == L"1")
						{
							std::wcout << L"Товар успешно переименован\n\n";
							nameArr[id] = chooseName;
							system("pause");
							break;
						}

						else if (choose == L"2")
						{
							std::wcout << L"Отмена переименования товара: " << nameArr[id] << L"\n";
							system("pause");
							break;
						}

						else
						{
							Err();
						}
					}
				}
			}
		}
	}
}

void DeleteProduct()
{
	std::wstring chooseId, pass;

	while (true)
	{
		ShowStorage(5);

		std::wcout << L"Введите ID товара или \"exit\" для выхода: ";
		Getline(chooseId);

		if (chooseId == L"exit" || chooseId == L"Exit")
		{
			std::wcout << L"Завершение операции удаления товаров\n\n";
			system("pause");
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
				std::wcout << L"Подтвердите удаление товара: " << nameArr[id] << L"\nВведите пароль Супер Администратора: ";
				Getline(pass);

				if (pass == passArr[0])
				{
					std::wcout << L"Удаление товара";
					for (size_t i = 0; i < 5; i++)
					{
						Sleep(500);
						std::wcout << L" .";
					}
					Sleep(500);

					currentStorageSize -= countArr[id];
					ArrDeleteByIndex(idArr, sizeSt, id);
					ArrDeleteByIndex(nameArr, sizeSt, id);
					ArrDeleteByIndex(countArr, sizeSt, id);
					ArrDeleteByIndex(priceArr, sizeSt, id);
					sizeSt--;

					// :)

					for (size_t i = id; i < sizeSt; i++)
					{
						idArr[i] = i + 1;
					}

					std::wcout << L"\n\nТовар успешно удален\n\n";
					system("pause");
					if (sizeSt < 1)
					{
						std::wcout << L"Склад пуст!\n\n";
						system("pause");
						return;
					}
					continue;
				}
				else
				{
					Err();
				}
			}
		}
	}
}

void ChangeStorageLimits()
{
	std::wcout << L"\n\nВ процессе разработки\n\n";
	system("pause");
}