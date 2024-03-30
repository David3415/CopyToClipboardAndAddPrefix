#include <iostream>

#include "PostfixAndPrefixClass.h"


PostfixAndPrefixClass::PrePostFix* PostfixAndPrefixClass::prePostFixVoid() {

	PostfixAndPrefixClass::PrePostFix* prePostFix = new PrePostFix{};

	std::string str1{};
	std::string str2{};

	char* prefix = new char[20] {};
	char* postfix = new char[20] {};

	std::cout << "Enter Prefix: ";
	std::cin >> str1;
	
	size_t str1_size = str1.size();
	char* cstr1 = new char[str1_size + 1];
	strcpy_s(cstr1, str1_size + 1, str1.c_str());
	
	std::cout <<  "Enter Postfix: ";
	std::cin >> str2;

	size_t str2_size = str2.size();
	char* cstr2 = new char[str2_size + 1];
	strcpy_s(cstr2, str2_size + 1, str2.c_str());

	/*if (str1.empty()) {
		std::cout << "String is empty" << std::endl;
	}*/

	
	

	prePostFix->prefix = cstr1;
	prePostFix->postfix = cstr2;

	return prePostFix;
};

PostfixAndPrefixClass::~PostfixAndPrefixClass() {

	std::cout << "fin;";
};

