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

	 static void _Login()
	 {

		 bool LoginFailed = false;

		 string UserName;
		 string Password;

		 do
		 {

			 if (LoginFailed == true)
			 {
				 cout << "\nInvalid UserName/Password !!!\n";
			 }

			 cout << "Please Enter UserName : ";
			 UserName = clsInputValidate::ReadString();

			 cout << "Please Enter Password : ";
			 Password = clsInputValidate::ReadString();

			 CurrentUser = clsUser::Find(UserName, Password);

			 LoginFailed = CurrentUser.IsEmpty();

		 } while (LoginFailed);

		 clsMainScreen::ShowMainMenu();
	 }

 public:


	 static void Show()
	 {
       
		 system("cls");

		 _ShowScreenHeader("+++ Login Screen +++");

		 _Login();
	 }
};

