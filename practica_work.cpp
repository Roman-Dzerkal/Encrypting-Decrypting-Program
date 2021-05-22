#include "stdafx.h"
#include <string.h>
#include <locale.h>
#include <Windows.h>
#include "crypt.h"

int main(int argc, _TCHAR* argv[]) 
{
	setlocale(LC_ALL, "RUS");

	crypt obj;
	int L = obj.FindLengthFile();
	char* buffer = new char[L];

	char* key = (char*)argv[1];
    int LKey = strlen(key);

	obj.setKeyToLowReg(LKey, key);

	const int c = obj.ReadFile(buffer, L);

	obj.setStringToUpperReg(c, buffer);

	obj.Encrypting(c, LKey, buffer, key);

	char key2[256];
	printf("Шифрование завершено успешно! Введите ключ для расшифровки: ");
	gets(key2);
	if (strcmp(key, key2) == 0) { // Если ключи совпадают
		obj.Decrypting(c, LKey, buffer, key2); // Расшифровываем
		printf("Расшифровано!\n");
		
	} else {
		printf("Ключи не совпадают! Попробуйте в следующий раз!\n");
		return 0;
	}

	obj.~crypt(); delete[] buffer;

	system("pause");
	return 0;
}


// C:\Users\Roma\Desktop\practica_work\Debug\practica_work.exe CaTeRpIlLaR