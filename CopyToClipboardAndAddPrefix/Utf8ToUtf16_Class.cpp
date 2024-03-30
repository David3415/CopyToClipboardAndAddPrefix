#include <string>
#include <windows.h>

#include "Utf8ToUtf16_Class.h"
#include <iostream>


std::wstring Utf8ToUtf16_Class::Utf8ToUtf16Void(std::string _utf8str)
{
	const char* _utf8Char = _utf8str.c_str();
	size_t utf8CharSize = strlen(_utf8Char) + 1;
	size_t convertedChars = 0;//вообще не ясно чё за
	
	const size_t utf16CharSize = utf8CharSize * 2 + 10;
	wchar_t* Utf16Char = new wchar_t[200];
	mbstowcs_s(&convertedChars, Utf16Char, 200, _utf8Char, _TRUNCATE);

	std::wstring utf16Str(Utf16Char);
	
	return utf16Str;
};
