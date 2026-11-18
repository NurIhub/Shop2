#ifndef _SERVISE_HPP_
#define _SERVISE_HPP_

#include <iostream>
#include <string>
#include <Windows.h>
#include <iomanip>

void Getline(std::wstring& str);
bool IsNumber(const std::wstring& str);

inline void Err()
{
	std::wcout << L"Некорректный ввод\n ";
	Sleep(1500);
}

template <class ArrType>
void FillArray(ArrType* staticArr, ArrType* dynamicArr, size_t commonSize)
{
	for (size_t i = 0; i < commonSize; i++)
	{
		dynamicArr[i] = staticArr[i];
	}
}


#endif
