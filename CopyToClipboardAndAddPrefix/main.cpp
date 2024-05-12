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
	/// Копируем текст в буфер обмена, просим у пользователя ввести текст, 
	/// который добавим в начало каждой строки - prefix (Например "Глава "), 
	/// текст который добавим в конец каждой строки - postfix ("Например "2024г."),
	/// и решить, надо ли нумеровать строчки
	/// </summary>
	/// Буфер обмена недоступен на время ввода, в след. версии исправить
	///----------------------------------------------------------------------------- <returns></returns>



	text_from_Buffer = CopyFromClipboardClass::CopyToClipboardVoid();	////  Главная функция




	////------------------------------------------------------------------------------
	////						Дальше не продумано, проверять не стоит

	Utf8ToUtf16_Class Utf8ToUtf16_Class{};
	text_from_Buffer_16 = Utf8ToUtf16_Class.Utf8ToUtf16Void(text_from_Buffer);
	WriteClipboardClass::WriteClipboardVoid(text_from_Buffer_16);
};

