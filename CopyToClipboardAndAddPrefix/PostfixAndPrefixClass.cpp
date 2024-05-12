#include <iostream>

#include "PostfixAndPrefixClass.h"
#include "InputTextClass.h"

PostfixAndPrefixClass::PrePostFix* PostfixAndPrefixClass::prePostFixVoid() {
	InputTextClass InputTextClass;
	bool numbering = true;
	int  index = 0;
	bool exitBool = false;
	std::string str{};

		PrePostFix* prePostFix = new PrePostFix;
	
	///----------------------------------------------------------------------------------------- <summary>
	///					Здесь вызов функций заполнения двух строк структуры prePostFix - prefix и postfix
	///									InputTextVoid()			
	
	prePostFix->prefix = InputTextClass.InputTextVoid(CaptionsVec[0]);
	prePostFix->postfix = InputTextClass.InputTextVoid(CaptionsVec[1]);
///----------------------------------------------------------------------------------------- <returns></returns>
	


	///--------------------------------------------------------------------------------------------------- <summary>
	///					Здесь вызов функций, спрашивающей у пользователя, надо ли 
	///					нуменовать строки:: 	prePostFix->numbering				
	///											y - надо, n - нет
	/// 
	///--------------------------------------------------------------------------------------------------------
	
	
	while (exitBool == false)
	{
		if (InputTextClass.InputTextVoid(CaptionsVec[2])[0] == 'y') {
			prePostFix->numbering = true;
			exitBool = true;
			return prePostFix;
		}
		else if (InputTextClass.InputTextVoid(CaptionsVec[2])[0] == 'n')
		{
			prePostFix->numbering = false;
			exitBool = true;
			return prePostFix;
		}
		else {
			system("cls");
			std::cout << "Need line numbering ? : y / n: "; 
			std::cout << '\n';
		}
	};
}

PostfixAndPrefixClass::~PostfixAndPrefixClass() {
	std::cout << " ";
};


