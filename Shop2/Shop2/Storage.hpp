#ifndef _SROROGE_HPP_
#define _SROROGE_HPP_

#include "Service.hpp"
#include <string>
extern size_t sizeSt;
extern size_t* idArr;
extern std::wstring* nameArr;
extern size_t* coutArr;
extern double* priceArr;

extern size_t maxStoragesize;
extern size_t currentStorageSize;

void CreateStorage(int mode = 0);
void ShowStorage(int mode = 0);
void AddProduct();



#endif