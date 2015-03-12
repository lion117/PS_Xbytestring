// X_bytestring_demo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Xbytestring.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	Xbytestring s1("hello world");
	Xbytestring s2("12344");
	Xbytestring s3 = s1+s2;
	cout<< s3.tostring().c_str()<<endl;
	u_int nsize = s3.size();
	for (u_int i =0; i< nsize; i++)
	{
		cout << s3[i]<<endl;
	}

	system("pause");
	return 0;
}

