#pragma once

#include<iostream>
#include"clsUser.h"
#include"clsScreen.h"
#include"clsInputValidate.h"

using namespace std;

class clsFindUserScreen : protected clsScreen
{
 
 private:

	 static void _PrintUser(const clsUser& User)
	 {

		 cout << "\n\n++++++ User's Informations ++++++\n\n";

		 cout << "___________________________________\n";
		 cout << "First Name   : " << User.FirstName() << endl;
		 cout << "Last Name    : " << User.LastName() << endl;
		 cout << "Phone Number : " << User.PhoneNumber() << endl;
		 cout << "Email Adress : " << User.Email() << endl;
		 cout << "UserName   : " << User.UserName() << endl;
		 cout << "Password     : " << User.Password() << endl;
		 cout << "Permission  : " << User.Permission() << endl;
		 cout << "___________________________________\n\n";

	 }

 public:
	
	 static void Show()
	 {

		 _ShowScreenHeader("+++ Find User Screen +++");

		 string UserName;

		 cout << "Please Enter User's User Name : ";
		 UserName = clsInputValidate::ReadString();

		 while (!clsUser::IsUserExist(UserName))
		 {
			 cout << "\nUser Doesn't Exist! Please Try Again : ";
			 UserName = clsInputValidate::ReadString();
		 }

		 clsUser User = clsUser::Find(UserName);

		 cout << "\n+++++ User Info +++++\n";

		 _PrintUser(User);
	 }
};

