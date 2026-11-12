#include "Authorization.hpp"

void Start()
{
	while (true)
	{
		if (Login())
		{
			system("pause");
		}
		else
		{

		}
	}



}

bool Login()
{
	std::wstring login, pass;
	while (true)
	{
		system("cls");
		std::wcout << "\n\n\n\t\tДобро пожаловать!";
		std::wcout << "\n\n\n\t\t\t\tPMS";
		std::wcout << L"ВВедите логин или \"exit\"для выхода: ";
		Getline(login);
		if (login == L"exit" || login == L"Exit")
		{
			return false;
		}
		else
		{
			std::wcout << L"Введите пароль: ";
			Getline(pass);
			for (size_t i = 0; i < userSize; i++)
			{
				if (login == loginArr[i] && pass == passArr[i])
				{
					std::wcout << L"Добро пожаловать " << loginArr[i] << L"\n";
					std::wcout << L"Ваш уровень доступа: " << statusArr[i] << L"\n";
					currentId = userIdArr[i];
					return true;
				}
			}
		}
	}
}