#include <iostream>

#include "PostfixAndPrefixClass.h"


PostfixAndPrefixClass::PrePostFix* PostfixAndPrefixClass::prePostFixVoid() {

	PostfixAndPrefixClass::PrePostFix* prePostFix = new PrePostFix{};

	std::string str{};
	//std::string str2{};

	char* prefix = new char[20] {};
	char* postfix = new char[20] {};

	std::cout << "Enter Prefix: ";
	std::cin >> str;

	size_t str1_size = str.size();
	char* cstr1 = new char[str1_size + 1];
	strcpy_s(cstr1, str1_size + 1, str.c_str());

	std::cout << "Enter Postfix: ";
	std::cin >> str;

	size_t str2_size = str.size();
	char* cstr2 = new char[str2_size + 1];
	strcpy_s(cstr2, str2_size + 1, str.c_str());

	/*if (str1.empty()) {
		std::cout << "String is empty" << std::endl;
	}*/


	int  index = 0;
	bool numerating = true;
	bool exitBool = false;


	std::cout << "Need line numbering?: y/n: ";
	std::cin >> str;



	while (exitBool==false)
	{
		while (str[index] == ' ') {
			index++;
		}

		if (str[index] == 'y') {
			prePostFix->numerating = true;
			exitBool = true;
			continue;
		}
		else if (str[0] == 'n')
		{
			prePostFix->numerating = false;
			exitBool = true;
			continue;
		}
		else {
			system("cls");
			std::cout << "Need line numbering ? : y / n: ";
			std::cin >> str;
		}
		if (exitBool) {
			continue;
		}
	}

	prePostFix->prefix = cstr1;
	prePostFix->postfix = cstr2;


	return prePostFix;
};

PostfixAndPrefixClass::~PostfixAndPrefixClass() {

	std::cout << "fin;";
};

