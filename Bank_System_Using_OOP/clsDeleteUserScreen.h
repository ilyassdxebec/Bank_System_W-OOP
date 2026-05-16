#pragma once

#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include"clsInputValidate.h"

using namespace std;

class clsDeleteUserScreen : protected clsScreen
{
 
 private:


	 static char _ConfirmDeletion()
	 {

		 char Choice;

		 cout << "\nAre you sure you want to delete this User? (y/n) : ";
		 cin >> Choice;

		 while (toupper(Choice) != 'Y' && toupper(Choice) != 'N')
		 {
			 cout << "\nInvalid Choice! Enter a vaild choice (y/n) : ";
			 cin >> Choice;
		 }

		 return Choice;
	 }

	 static void _PrintUser(const clsUser& User)
	 {

		 cout << "\n\n++++++ User's Informations ++++++\n\n";

		 cout << "___________________________________\n";
		 cout << "First Name   : " << User.FirstName() << endl;
		 cout << "Last Name    : " << User.LastName() << endl;
		 cout << "Phone Number : " << User.PhoneNumber() << endl;
		 cout << "Email Adress : " << User.Email() << endl;
		 cout << "User Name    : " << User.UserName() << endl;
		 cout << "Password     : " << User.Password() << endl;
		 cout << "Permission   : " << User.Permission() << endl;
		 cout << "___________________________________\n\n";

	 }

 public:

	 static void Show()
	 {

		 _ShowScreenHeader("+++ Delete User Screen +++");

		 string UserName;
		 char Choice;

		 cout << "Please Enter User Name : ";
		 UserName = clsInputValidate::ReadString();

		 while (!clsUser::IsUserExist(UserName))
		 {
			 cout << "\nUser Doesn't Exist! Please Try Again : ";
			 UserName = clsInputValidate::ReadString();
		 }

		 clsUser User = clsUser::Find(UserName);

		 _PrintUser(User);

		 Choice = _ConfirmDeletion();

		 if (toupper(Choice) == 'Y')
		 {

			 if (User.Delete())
			 {
				 cout << "\nUser Was Deleted Successfully !!!\n";
				 _PrintUser(User);
			 }

			 else
			 {
				 cout << "\nError ,Couldn't Delete User!\n";
			 }
		 }

		 else
		 {
			 cout << "\nUser Wasn't Deleted as you wanted !\n";
		 }

	 }
};

