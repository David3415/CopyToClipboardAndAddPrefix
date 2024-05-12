#include <iostream>

#include "CopyFromClipboardClass.h"
#include "WriteClipboardClass.h"
#include "Utf8ToUtf16_Class.h"


int main() {
	system("chcp 1251");
	system("cls");
	setlocale(LC_ALL, "Russian_Russia.1251");

	std::string text_from_Buffer;	
	std::wstring text_from_Buffer_16;


	///----------------------------------------------------------------------------- <summary>
	/// �������� ����� � ����� ������, ������ � ������������ ������ �����, 
	/// ������� ������� � ������ ������ ������ - prefix (�������� "����� "), 
	/// ����� ������� ������� � ����� ������ ������ - postfix ("�������� "2024�."),
	/// � ������, ���� �� ���������� �������
	/// </summary>
	/// ����� ������ ���������� �� ����� �����, � ����. ������ ���������
	///----------------------------------------------------------------------------- <returns></returns>



	text_from_Buffer = CopyFromClipboardClass::CopyToClipboardVoid();	////  ������� �������




	////------------------------------------------------------------------------------
	////						������ �� ���������, ��������� �� �����

	Utf8ToUtf16_Class Utf8ToUtf16_Class{};
	text_from_Buffer_16 = Utf8ToUtf16_Class.Utf8ToUtf16Void(text_from_Buffer);
	WriteClipboardClass::WriteClipboardVoid(text_from_Buffer_16);
};

