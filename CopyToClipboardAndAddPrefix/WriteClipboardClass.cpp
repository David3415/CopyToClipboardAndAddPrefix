#include <iostream>
#include <strstream>
#include <string>
#include <windows.h>

#include "WriteClipboardClass.h"


int WriteClipboardClass::WriteClipboardVoid(std::wstring text_from_Buffer_16)
{

	if (OpenClipboard(NULL))
	{
		std::unique_ptr<wchar_t[]> p_text_from_Buffer_16(&text_from_Buffer_16[0]);
		EmptyClipboard();

		std::wcout << "text_from_Buffer_16::" << text_from_Buffer_16 << '\n';
		int bufferSize = lstrlenW(p_text_from_Buffer_16.get()) + 1; // (text_from_Buffer_16.length() + 2) *sizeof(wchar_t);
		bufferSize = (bufferSize < 1000) ? bufferSize : 2000;

		HGLOBAL hMemory = GlobalAlloc(GMEM_MOVEABLE, static_cast<SIZE_T>(bufferSize * sizeof(wchar_t) + 2));

		LPWSTR pData = static_cast<LPWSTR>(GlobalLock(hMemory));
		if (pData != NULL)
		{
			wcscpy_s(pData, bufferSize + 1, &p_text_from_Buffer_16[0]);
			GlobalUnlock(hMemory);
			SetClipboardData(CF_UNICODETEXT, hMemory);
		}
		CloseClipboard();
		exit(0);
	}
	return 0;
};

