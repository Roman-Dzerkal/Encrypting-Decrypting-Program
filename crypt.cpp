#include "StdAfx.h"
#include <ctype.h>	 // ��� ������ � ��������� tolower() � toupper()
#include <locale.h>	 // ���������� ������� ����������� ������ � �����-���������
#include "crypt.h"

FILE *source, *_source, *Ckey, *CCrypt, *CDecrypt;

crypt::crypt()
{
	source = fopen("C:\\Users\\Roma\\Desktop\\text.txt", "r");		 // ����-��������
	_source = fopen("C:\\Users\\Roma\\Desktop\\text_.txt", "w+");	 // ������������� ����
	Ckey = fopen("C:\\Users\\Roma\\Desktop\\key.txt", "w+");		 // ���� � ������
	CCrypt = fopen("C:\\Users\\Roma\\Desktop\\crypt.txt", "w+");	 // ���� � ������������ �������
	CDecrypt = fopen("C:\\Users\\Roma\\Desktop\\decrypt.txt", "w+"); // ���� � ������������� �������
}

crypt::~crypt()
{
	fcloseall; // ��������� ��� ������
}

void crypt::setKeyToLowReg(int Length, char *M)
{
	for (int i = 0; i < Length; i++) {
        fprintf(Ckey, "%c", (char)tolower(M[i])); //��������� ������� ����� � ������ �������
    }
}

int crypt::FindLengthFile()
{
    fseek(source, 0, SEEK_END); // ������������� ������� ����������-��������� � ����� �����
    int lSize = ftell(source);	// ��������� ������� ����������-���������
    fseek(source, 0, SEEK_SET); // ������������� ������� ����������-��������� � ������ �����
	return lSize;
}

int crypt::ReadFile(char* Array, int FileLength)
{
	const int k = fread(Array, 1, FileLength, source); // ���������� k ������� ���������� ���� �� �����
	return k;
}

void crypt::setStringToUpperReg(int Len, char* Array)
{
   for (int i = 0; i < Len; i++) {
        fprintf(_source, "%c", (char)toupper(Array[i])); // ��������� �������� ����� � ������� �������
    }
}

void crypt::Encrypting(int FileLength, int KeyLength, char* Array, char* Key)
{
	for (int i = 0, j = 0; i < FileLength; i++) { 
        Array[i] ^= Key[j]; // Array[i] = Array[i] ^ Key[j]

		j < KeyLength - 1 ? j++ : j = 0; // ������� ����������� �����

        fputc(Array[i], CCrypt); 
		// ���������� ����������� � ���� crypt.txt
    }
}

void crypt::Decrypting(int FileLength, int KeyLength, char* Array, char* Key)
{
	for (int i = 0, j = 0; i < FileLength; i++) {
        Array[i] ^= Key[j];

		j < KeyLength - 1 ? j++ : j = 0;

        fprintf(CDecrypt, "%c", (char)toupper(Array[i]));
		// ���������� ������������� ������ � decrypt.txt
    }
}