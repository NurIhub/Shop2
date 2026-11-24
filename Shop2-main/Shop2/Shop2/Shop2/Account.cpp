#include "Accounts.hpp"

extern size_t usersSize = 3;
extern size_t currentid = 0;
extern std::wstring currentStatus;

extern std::wstring* loginArr = new std::wstring[userSize]{ L"admin", L"user1", L"user2" };
extern std::wstring* passArr = new std::wstring[userSize]{ L"admin", L"user1", L"user2" };
extern std::wstring* statusArr = new std::wstring[userSize]{ L"SuperAdmin", L"Admin", L"User" };
size_t* userIdArr = new size_t[userSize]{ 0, 1, 2 };

