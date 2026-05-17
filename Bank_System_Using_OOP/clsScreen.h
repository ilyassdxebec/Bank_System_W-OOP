#pragma once

#include<iostream>
#include"Global.h"
#include"clsDate.h"

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
			 cout << "\n         " << SubTitle << "\n";
		 }

		 cout << "============================================" << endl;

		 cout << "\nCurrent User : " << CurrentUser.UserName() << endl;
		 cout << "Current Date : " << clsDate::DateToString(clsDate());

		 cout << "============================================\n\n\n";

	 }

	 static bool _ShowIsFeatureAvailable(const short& FeatureNumber)
	 {

		 if (!CurrentUser.IsFeatureAvailable(FeatureNumber))
		 {

			 cout << "=========================================\n";
			 cout << "Access Denied,\n";
			 cout << "You Don't have permission to do this,\n";
			 cout << "Please Contact your admin!\n";
			 cout << "=========================================\n";

			 return false;
		 }

		 return true;
	 }
};

