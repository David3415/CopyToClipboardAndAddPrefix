#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <strstream>
#include <windows.h>

#include "CopyFromClipboardClass.h"
#include "PostfixAndPrefixClass.h"


std::string CopyFromClipboardClass::CopyToClipboardVoid() {

///----------------------------------------------------------------------------------------- <summary>
///					Вызов класса в котором добавляю к строкам нумерацию, prefix и postfix
//					Возвращает структуру  resStruct

		PostfixAndPrefixClass* postfixAndPrefixClass = new PostfixAndPrefixClass{};
		auto resStruct = postfixAndPrefixClass->prePostFixVoid();
///----------------------------------------------------------------------------------------- <returns></returns>




///----------------------------------------------------------------------------------------- <summary>
///					prefix и postfix и выбор нумерации уже введены в структуру resStruct, 	
///					теперь извлекаем текст, скопированный в буфер обмена
///					и в каждой строке добавляем  prefix и postfix и номер строки

///----------------------------------------------------------------------------------------- <summary>

	char* text_from_buf_res = new char[3000] {};
	const char* text_from_buf = new char[3000] {};
	std::string text_from_Buffer_16{};

	std::string fromClipboard;		//в эту переменную сохраним текст из буфера обмена
	bool _numbering{};
	if (resStruct->numbering == true) {
		_numbering = true;
	};

	if (OpenClipboard(NULL))
	{

		HANDLE hData = GetClipboardData(CF_TEXT);
		char* chBuffer = (char*)GlobalLock(hData);

		int str_count = 1;
		char  str_count_to_str[100];

		char space[] = { ' ','\0' };
		char term_null = '\0';
		char* p_space = space;
		char new_line[] = { '\n','\0' };
		char* p_term_null = &term_null;

		if (chBuffer != NULL) {

			std::istrstream cboard(chBuffer);
			while (!cboard.eof()) {
				getline(cboard, fromClipboard);
				if (fromClipboard.empty()) {
					std::cout << '\n' << "clipboard is empty" << std::endl;
					continue;
				}

				text_from_buf = fromClipboard.c_str();

				if (_numbering) {
					sprintf(str_count_to_str, "%d", str_count);					////  переводим нумерацию str_count в строку

					size_t sz_str_count_to_str = strlen(str_count_to_str);
					strcat_s(text_from_buf_res, 3000, str_count_to_str);		////	вставляем нумерацию в text_from_buf_res

					strcat_s(text_from_buf_res, 3000, p_space);					////	вставляем пробел
				}

				strcat_s(text_from_buf_res, 3000, resStruct->prefix);			//		Вставляем префикс
				strcat_s(text_from_buf_res, 3000, p_space);						////	вставляем пробел
				strcat_s(text_from_buf_res, 3000, text_from_buf);				//		Вставляем скопированный текст

				size_t text_from_buf_size = strlen(text_from_buf_res);
				text_from_buf_res[text_from_buf_size - 1] = *p_term_null;

				strcat_s(text_from_buf_res, 3000, p_space);						////	вставляем пробел
				strcat_s(text_from_buf_res, 3000, resStruct->postfix);			////	вставляем постфикс
				strcat_s(text_from_buf_res, 3000, new_line);
				
				str_count++;
			}
		}
		GlobalUnlock(hData);
		CloseClipboard();
	};
	return text_from_buf_res;
};



