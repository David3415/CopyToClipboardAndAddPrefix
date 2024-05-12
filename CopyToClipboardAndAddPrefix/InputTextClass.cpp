#include <string>
#include <iostream>
#include <conio.h>

#include "InputTextClass.h"

std::string InputTextClass::EraseRSymbol(std::string str) {
	size_t _strLen = str.length();
	str.erase(_strLen - 1, 1);
	str.push_back('\0');
	return str;
}

char* InputTextClass::InputTextVoid(std::string str) {
	std::cout << str;
	char inpChar;
	bool firstChar = true;
	int lastSymb{};
	inputStr.clear();

	///----------------------------------------------------------------------------------------- <summary>
	///					
	//					����� �������� �����
	
	///----------------------------------------------------------------------------------------- <returns></returns>


	while (true)
	{
		inpChar = _getch();
		if ((121 == inpChar || 89 == inpChar) && firstChar == true) {////	���� ��� ������ ������ 'Y' � 								
			inputStr.push_back(inpChar);							 ////	����� ��� �� ���� firstChar == true
			std::cout << 'y' << std::endl;
			break;
		}
		if ((110 == inpChar || 78 == inpChar) && firstChar == true) {////	���� ��� ������ ������ 'N' � 
			inputStr.push_back(inpChar);							 ////	����� ��� �� ���� firstChar == true
			std::cout << 'n' << std::endl;
			break;
		}
		if (13 == inpChar && inpChar == ' ' && firstChar == true) {////	���� ����� ��� �� ����(inputStr ������) 
			inputStr.push_back(inpChar);						   //// �������� ������ �������� '\r' �� ������ ����� ������ '\0'
			inputStr = EraseRSymbol(inputStr);					   //// � ����� Enter � ������
			break;
		}
		if (13 == inpChar && inputStr.empty()) {
			std::cout << "Notice, string is empty" << std::endl;	////���� ����� ��� �� ����(inputStr ������) � ����� Enter
			inputStr = EraseRSymbol(inputStr);
			break;
		}

		if (13 == inpChar) {
			inputStr.push_back(inpChar);						////    ���� ���� ��� ���(inputStr �� ������) � ����� Enter
			std::cout << std::endl;
			inputStr = EraseRSymbol(inputStr);
			break;
		}
		if (8 == inpChar) {										////	����  ����� BS � ������ �� ������ ������� ������
			lastSymb = inputStr.length();						//		lastSymb - ������� ����� ������
			if (lastSymb != 0) {								//      ���� ������ �� ������ {����� ������ lastSymb != 0}
				std::cout << '\b';								//		�� ������� ������
				std::cout << ' ';
				std::cout << '\b';
				inputStr.erase(lastSymb - 1, 1);
			}
			continue;
		}

		if (' ' == inpChar && firstChar == true) {				 ////  ���� ����� ������ � ������ ���� ������
			continue;
		}
		if (inpChar > 32) {										 ////  ���� ��� ������� �� ��������� � ��������   
			inputStr.push_back(inpChar);						 ////  ������ inpChar > 32 �� ��������� inputStr

			std::cout << inpChar;
		}
	}


	size_t inputStr_size = inputStr.size();
	char* cstr1 = new char[inputStr_size + 1];
	strcpy_s(cstr1, inputStr_size + 1, inputStr.c_str());

	return cstr1;
};

