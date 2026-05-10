#pragma once

#include<iostream>

using namespace std;

class clsScreen
{
 
 protected:

	 static void _ShowHeader(const string &Title)
	 {
		 cout << "============================================" << endl;
		 cout << "           "<<Title<<endl;
		 cout << "============================================" << "\n\n";
	 }
};

