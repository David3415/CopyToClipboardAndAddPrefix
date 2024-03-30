#include <iostream>
#include <strstream>
#include <windows.h>

#include "CopyFromClipboardClass.h"
#include "PostfixAndPrefixClass.h"


std::string CopyFromClipboardClass::CopyToClipboardVoid() {
	setlocale(LC_ALL, "rus");
	PostfixAndPrefixClass* postfixAndPrefixClass = new PostfixAndPrefixClass{};

	auto resStruct = postfixAndPrefixClass->prePostFixVoid();

	std::string text_from_Buffer_Temp{};
	std::string text_from_Buffer{};

	std::string fromClipboard;//в эту переменную сохраним текст из буфера обмена

	if (OpenClipboard(NULL))
	{
		HANDLE hData = GetClipboardData(CF_TEXT);
		char* chBuffer = (char*)GlobalLock(hData);

		int str_counter = 49;
		if (chBuffer != NULL) {
			//auto f = resStruct->prefix;
			/*if (wcslen(resStruct->postfix) != 0) {

			}*/

			std::istrstream cboard(chBuffer);
			while (!cboard.eof()) {
				getline(cboard, fromClipboard);
				if (fromClipboard.empty()) { continue; }
				text_from_Buffer = fromClipboard;
				size_t text_from_Buffer_size = fromClipboard.length();
				text_from_Buffer.erase(text_from_Buffer_size - 1, 1);
				text_from_Buffer_Temp += str_counter;
				text_from_Buffer_Temp += "  ";
				text_from_Buffer_Temp += resStruct->prefix;
				text_from_Buffer_Temp += "  ";
				text_from_Buffer_Temp += text_from_Buffer;
				text_from_Buffer_Temp += " ";
				text_from_Buffer_Temp += resStruct->postfix;
				text_from_Buffer_Temp += '\n';

				str_counter++;
			}
		}
		GlobalUnlock(hData);
		CloseClipboard();
	};

	text_from_Buffer.assign(text_from_Buffer_Temp);
	//std::cout << "text_from_Buffer_16::" << text_from_Buffer << '\n';
	return text_from_Buffer;
};


