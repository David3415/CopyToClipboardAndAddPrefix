#pragma once


class PostfixAndPrefixClass
{
private:
	struct PrePostFix
	{
		char* prefix;
		char* postfix;

		PrePostFix() {
			prefix = NULL;
			postfix = NULL;
		}
	};
public:
	PrePostFix* prePostFix;
	PostfixAndPrefixClass()
	{
		prePostFix = NULL;
	}
	PrePostFix* prePostFixVoid();
	~PostfixAndPrefixClass();
};





















































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































