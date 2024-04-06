#include <iostream>
#include <strstream>
#include <windows.h>

#include "CopyFromClipboardClass.h"
#include "PostfixAndPrefixClass.h"


std::string CopyFromClipboardClass::CopyToClipboardVoid() {

	PostfixAndPrefixClass* postfixAndPrefixClass = new PostfixAndPrefixClass{};

	auto resStruct = postfixAndPrefixClass->prePostFixVoid();

	std::string text_from_Buffer_Temp_16{};
	std::string text_from_Buffer{};
	std::string text_from_Buffer_16{};
	bool numerating=false;
	std::string fromClipboard;//в эту переменную сохраним текст из буфера обмена
	if (resStruct->numerating == true) {
		 numerating = true;
	};
	if (OpenClipboard(NULL))
	{
		int str_counter = 49;
		HANDLE hData = GetClipboardData(CF_TEXT);
		char* chBuffer = (char*)GlobalLock(hData);


		if (chBuffer != NULL) {

			std::istrstream cboard(chBuffer);
			while (!cboard.eof()) {
				getline(cboard, fromClipboard);
				if (fromClipboard.empty()) { continue; }
				text_from_Buffer = fromClipboard;

				size_t text_from_Buffer_size = fromClipboard.length();
				text_from_Buffer.erase(text_from_Buffer_size - 1, 1);
				if (numerating) {
					text_from_Buffer_Temp_16 += str_counter;
				}
				text_from_Buffer_Temp_16 += "  ";
				text_from_Buffer_Temp_16 += resStruct->prefix;
				text_from_Buffer_Temp_16 += "  ";
				text_from_Buffer_Temp_16 += text_from_Buffer;
				text_from_Buffer_Temp_16 += " ";
				text_from_Buffer_Temp_16 += resStruct->postfix;
				text_from_Buffer_Temp_16 += '\n';

				str_counter++;
			}
		}
		GlobalUnlock(hData);
		CloseClipboard();
	};

	text_from_Buffer.assign(text_from_Buffer_Temp_16);
	std::cout << "text_from_Buffer::" << text_from_Buffer << '\n';
	return text_from_Buffer;
};

