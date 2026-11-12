#include <iostream>
#include <io.h>
#include <fcntl.h>
#include "Authorization.hpp"

int main()
{
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stdout), _O_U16TEXT);


	Start();





	return 0;
}

