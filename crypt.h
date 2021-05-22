#pragma once
class crypt
{
public:
	int FindLengthFile(); // Находим длину файла
	void setKeyToLowReg(int Length, char *Key); // Переводим ключ в нижний регистр
	void setStringToUpperReg(int Length, char* Array); // Переводим начальный текст в верхний регистр
	int ReadFile(char* Array, int FileLength); // Считываем текст, для шифрования
	void Encrypting(int FileLength, int KeyLength, char* Array, char* Key); // Шифруем
	void Decrypting(int FileLength, int KeyLength, char* Array, char* Key); // Дешифруем
	crypt();
	~crypt();	
};