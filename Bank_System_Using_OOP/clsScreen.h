#pragma once

#include<iostream>

using namespace std;

class clsScreen
{
 
 protected:

	 static void _ShowScreenHeader(const string &Title ,const string &SubTitle = "")
	 {

		 cout << "============================================" << endl;
		 cout << "         " <<Title<< endl;
		 
		 if (SubTitle != "")
		 {
			 cout << "\n         " << SubTitle << endl;
		 }

		 cout << "============================================\n\n";

	 }
};

