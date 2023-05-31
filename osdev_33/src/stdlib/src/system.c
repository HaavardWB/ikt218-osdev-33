#include "system.h"

//koden til strlen AKA implimenterer libC funksjonen
size_t strlen(const char* str) 
{
	size_t len = 0;
	while (str[len])
		len++;
	return len;
}