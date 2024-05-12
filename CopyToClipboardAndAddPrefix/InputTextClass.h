#pragma once
class InputTextClass
{
public:
	//InputTextClass(std::string str=NULL) :_str(str) {};
	char* InputTextVoid(std::string str);

	std::string EraseRSymbol(std::string _str);
	std::string _str;
	std::string inputStr;
};

