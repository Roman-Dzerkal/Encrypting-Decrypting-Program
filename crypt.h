#pragma once
class crypt
{
public:
	int FindLengthFile(); // ������� ����� �����
	void setKeyToLowReg(int Length, char *Key); // ��������� ���� � ������ �������
	void setStringToUpperReg(int Length, char* Array); // ��������� ��������� ����� � ������� �������
	int ReadFile(char* Array, int FileLength); // ��������� �����, ��� ����������
	void Encrypting(int FileLength, int KeyLength, char* Array, char* Key); // �������
	void Decrypting(int FileLength, int KeyLength, char* Array, char* Key); // ���������
	crypt();
	~crypt();	
};