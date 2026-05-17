#pragma once

#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include"clsInputValidate.h"
#include"clsMainScreen.h"

#include"Global.h"

using namespace std;

class clsLoginScreen : protected clsScreen
{

 private:

	 static bool _Login()
	 {

		 bool LoginFailed = false;
		 short AvailableTries = 3;

		 string UserName;
		 string Password;
	
		 do
		 {

			 if (LoginFailed == true)
			 {
				 cout << "\nInvalid UserName/Password !!!\n";

				 AvailableTries--;
				 cout << "You Have " << AvailableTries << " Try(s) Left !!!\n\n";
			 }

			 if (AvailableTries == 0)
			 {
				 cout << "You are Locked After 3 Failed Tries !!!\n\n";
				 return false;
			 }

			 cout << "Please Enter UserName : ";
			 UserName = clsInputValidate::ReadString();

			 cout << "Please Enter Password : ";
			 Password = clsInputValidate::ReadString();

			 CurrentUser = clsUser::Find(UserName, Password);

			 LoginFailed = CurrentUser.IsEmpty();

		 } while (LoginFailed);

		 clsMainScreen::ShowMainMenu();
		 return true;
	 }

 public:


	 static bool Show()
	 {
       
		 system("cls");

		 _ShowScreenHeader("+++ Login Screen +++");

		 return _Login();
	 }
};

