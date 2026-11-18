#ifndef _AUTHORIZATION_HPP_
#define _AUTHORIZATION_HPP_
#include "Servise.hpp"
#include "Accounts.hpp"
#include "Storage.hpp"




bool Login();

void SuperAdminMenu()
{
	std::wstring choose;

	while (true)
	{
		system("cls");
		std::wcout << L"1 - Начать продажу\n";
		std::wcout << L"2 - Покозать склад\n";
		std::wcout << L"3 - Пополнить товары\n";
		std::wcout << L"4 - Списать товары\n";
		std::wcout << L"5 - Изменить цены\n";
		std::wcout << L"6 - Редактировать склад\n";
		std::wcout << L"7 - Редактировать сотрудников\n";
		std::wcout << L"8 - Отчет о прибыли\n";
		std::wcout << L"0 - Выход\n\n";
		std::wcout << L"Ввод: ";
		Getline(choose);

		if (choose == L"1")
		{

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
		else if (choose == L"5")
		{

		}
		else if (choose == L"6")
		{

		}
		else if (choose == L"7")
		{

		}
		else if (choose == L"8")
		{

		}
		else if (choose == L"9")
		{

		}
		else
		{

		}
	}
}









#endif
