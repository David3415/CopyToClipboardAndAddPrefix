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
	//					Здесь проверка ввода
	
	///----------------------------------------------------------------------------------------- <returns></returns>


	while (true)
	{
		inpChar = _getch();
		if ((121 == inpChar || 89 == inpChar) && firstChar == true) {////	Если это первый символ 'Y' и 								
			inputStr.push_back(inpChar);							 ////	ввода ещё не было firstChar == true
			std::cout << 'y' << std::endl;
			break;
		}
		if ((110 == inpChar || 78 == inpChar) && firstChar == true) {////	Если это первый символ 'N' и 
			inputStr.push_back(inpChar);							 ////	ввода ещё не было firstChar == true
			std::cout << 'n' << std::endl;
			break;
		}
		if (13 == inpChar && inpChar == ' ' && firstChar == true) {////	Если ввода еще не было(inputStr пустой) 
			inputStr.push_back(inpChar);						   //// Заменяем символ возврата '\r' на символ конца строки '\0'
			inputStr = EraseRSymbol(inputStr);					   //// и введён Enter и пробел
			break;
		}
		if (13 == inpChar && inputStr.empty()) {
			std::cout << "Notice, string is empty" << std::endl;	////Если ввода еще не было(inputStr пустой) и введён Enter
			inputStr = EraseRSymbol(inputStr);
			break;
		}

		if (13 == inpChar) {
			inputStr.push_back(inpChar);						////    Если ввод уже был(inputStr не пустой) и введён Enter
			std::cout << std::endl;
			inputStr = EraseRSymbol(inputStr);
			break;
		}
		if (8 == inpChar) {										////	Если  введён BS и строка не пустая удаляем символ
			lastSymb = inputStr.length();						//		lastSymb - получим длину строки
			if (lastSymb != 0) {								//      Если строка не пустая {длина строки lastSymb != 0}
				std::cout << '\b';								//		то удаляем символ
				std::cout << ' ';
				std::cout << '\b';
				inputStr.erase(lastSymb - 1, 1);
			}
			continue;
		}

		if (' ' == inpChar && firstChar == true) {				 ////  Если введён пробел и строка была пустая
			continue;
		}
		if (inpChar > 32) {										 ////  Если все условия не сработали и введённый   
			inputStr.push_back(inpChar);						 ////  символ inpChar > 32 то дополняем inputStr

			std::cout << inpChar;
		}
	}


	size_t inputStr_size = inputStr.size();
	char* cstr1 = new char[inputStr_size + 1];
	strcpy_s(cstr1, inputStr_size + 1, inputStr.c_str());

	return cstr1;
};

