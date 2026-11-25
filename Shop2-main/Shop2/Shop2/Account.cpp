#include "Accounts.hpp"

extern size_t usersSize = 3;
extern size_t currentid = 0;
extern std::wstring currentStatus;

extern std::wstring* loginArr = new std::wstring[userSize]{ L"admin", L"user1", L"user2" };
extern std::wstring* passArr = new std::wstring[userSize]{ L"admin", L"user1", L"user2" };
extern std::wstring* statusArr = new std::wstring[userSize]{ L"SuperAdmin", L"Admin", L"User" };
size_t* userIdArr = new size_t[userSize]{ 0, 1, 2 };

size_t maxLogin = 12;
size_t minLogin = 5;
size_t maxPass = 16;
size_t minPass = 6;

std::unordered_set<wchar_t> loginSymbols;
std::unordered_set<wchar_t> passSymbols;

void ChangeAccounts()
{
	std::wstring choose;

	while (true)
	{
		system("cls");

		std::wcout << L"Редактор учетных записей\n\n";
		std::wcout << L"1 - Содать новый аккаунт\n";
		std::wcout << L"2 - Показать всех сотрудников\n";
		std::wcout << L"3 - Изменить пароль\n";
		std::wcout << L"4 - Изменить уровни доступа\n";
		std::wcout << L"5 - Редактировать премии и штрафы сотрудников\n";
		std::wcout << L"6 - Удалить аккаунт\n";
		std::wcout << L"0 - Выход\n";
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
		else if (choose == L"0")
		{
			std::wcout << L"Выход из редактора учетных записей\n\n";
			system("pasue");
			break;
		}
		else
		{
			Err();
		}
	}
}

void CreateNewAccount()
{
	std::wstring chooseLogin, choosePass, chooseStatus, choose;

	while (true)
	{
		while (true)
		{
			system("cls");
			std::wcout << L"Введите логин нового пользователя или \"exit\" для выхода: ";
			Getline(chooseLogin);
			if (chooseLogin == L"exit" || chooseLogin == L"Exit")
			{
				std::wcout << L"Отмена созания учётной записи\n\n";
				system("cls");
				return;
			}
			if (true)
			{
				break;
			}
			else
			{
				Err();
			}
		}
	}
}

void CreateSet()
{
	for (wchar_t i = L'0'; i <= L'9'; i++)
	{
		loginSymbols.insert(i);
	}
}

bool CheckLogin(const std::wstring& login)
{
	return false;
}