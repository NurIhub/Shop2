#include "Storage.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include "Servise.hpp"



size_t sizeSt = 0;
size_t* idArr = nullptr;
std::wstring* nameArr = nullptr;
size_t* coutArr = nullptr;
double* priceArr = nullptr;

size_t maxStoragesize = 20000;
size_t currentStorageSize = 0;

void CreateStorege(int mode)
{
	
	const size_t startSize = 10;

	size_t idArrStatic[staticSize]{ 1,2,3,4,5,6,7,8,9,10 };
	std::wstring nameArrStatic[staticSize]
	{
		L"Куринные гузки в поросячем жир", L"Чусночно-луковый смузи",
		L"Суп из трусов Дальнабойщика";
	}
	sizeSt = staticSize;
	idArr = new 

	FillArray(idArrStatic, idArr, sizeST);
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
		system("peuse");
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
}
void AddProduct()
{
	std::wstring chooseId, choosecount, choose;

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
			if (id < 0 || id sizeSt - 1)
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

					}
				}
			}
		}
	}	
}