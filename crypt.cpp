#include "StdAfx.h"
#include <ctype.h>	 // Для работы с функциями tolower() и toupper()
#include <locale.h>	 // Подключаем русскую локализацию текста в файле-исходнике
#include "crypt.h"

FILE *source, *_source, *Ckey, *CCrypt, *CDecrypt;

crypt::crypt()
{
	source = fopen("C:\\Users\\Roma\\Desktop\\text.txt", "r");		 // Файл-исходник
	_source = fopen("C:\\Users\\Roma\\Desktop\\text_.txt", "w+");	 // Промежуточный файл
	Ckey = fopen("C:\\Users\\Roma\\Desktop\\key.txt", "w+");		 // Файл с ключём
	CCrypt = fopen("C:\\Users\\Roma\\Desktop\\crypt.txt", "w+");	 // Файл с зашифрованым текстом
	CDecrypt = fopen("C:\\Users\\Roma\\Desktop\\decrypt.txt", "w+"); // Файл с расшифрованым текстом
}

crypt::~crypt()
{
	fcloseall; // Закрываем все потоки
}

void crypt::setKeyToLowReg(int Length, char *M)
{
	for (int i = 0; i < Length; i++) {
        fprintf(Ckey, "%c", (char)tolower(M[i])); //Переводим символы ключа в нижний регистр
    }
}

int crypt::FindLengthFile()
{
    fseek(source, 0, SEEK_END); // Устанавливаем позицию индикатора-указателя в конец файла
    int lSize = ftell(source);	// Считываем позицию индикатора-указателя
    fseek(source, 0, SEEK_SET); // Устанавливаем позицию индикатора-указателя в начало файла
	return lSize;
}

int crypt::ReadFile(char* Array, int FileLength)
{
	const int k = fread(Array, 1, FileLength, source); // Возвращает k успешно прочитаных байт из файла
	return k;
}

void crypt::setStringToUpperReg(int Len, char* Array)
{
   for (int i = 0; i < Len; i++) {
        fprintf(_source, "%c", (char)toupper(Array[i])); // Переводим исходный текст в верхний регистр
    }
}

void crypt::Encrypting(int FileLength, int KeyLength, char* Array, char* Key)
{
	for (int i = 0, j = 0; i < FileLength; i++) { 
        Array[i] ^= Key[j]; // Array[i] = Array[i] ^ Key[j]

		j < KeyLength - 1 ? j++ : j = 0; // Условие цикличности ключа

        fputc(Array[i], CCrypt); 
		// Записываем шифросимвол в файл crypt.txt
    }
}

void crypt::Decrypting(int FileLength, int KeyLength, char* Array, char* Key)
{
	for (int i = 0, j = 0; i < FileLength; i++) {
        Array[i] ^= Key[j];

		j < KeyLength - 1 ? j++ : j = 0;

        fprintf(CDecrypt, "%c", (char)toupper(Array[i]));
		// Записываем расшифрованый символ в decrypt.txt
    }
}