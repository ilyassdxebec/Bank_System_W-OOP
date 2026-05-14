#pragma once

#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"


using namespace std;

class clsManageUsersScreen : protected clsScreen
{

 private:

	 enum enManageUsersMenu { eListUsers = 1, eAddUser = 2, eDeleteUser = 3, eUpdateUser = 4, eFindUser = 5, eBackToMainMenu = 6 };

	 static void _GoBackToManageUsersMenu()
	 {

		 cout << "\n\n+++ Press Any Key To Go Back To Manage Users Menu +++";

		 system("pause>0");

		 ShowManageUsersMenu();

	 }

	 static void _ShowListUsersScreen()
	 {

	 }

	 static void _ShowAddNewUserScreen()
	 {

	 }

	 static void _ShowDeleteUserScreen()
	 {

	 }

	 static void _ShowUpdateUserScreen()
	 {

	 }

	 static void _ShowFindUserScreen()
	 {

	 }

	 static short _ReadManageUsersMenuOption()
	 {

		 short Choice;

		 cout << "\nChoose what do you want to do ? [1-6] : ";

		 Choice = clsInputValidate::ReadShortNumberBetween(1, 6);

		 return Choice;
	 }

	 static void _PerformManageUsersMenuOption(const enManageUsersMenu &Choice)
	 {

		 switch (Choice)
		 {

		 case eListUsers:

			 system("cls");
			 _ShowListUsersScreen();
			 _GoBackToManageUsersMenu();
			 break;

		 case eAddUser:

			 system("cls");
			 _ShowAddNewUserScreen();
			 _GoBackToManageUsersMenu();
			 break;

		 case eDeleteUser:

			 system("cls");
			 _ShowDeleteUserScreen();
			 _GoBackToManageUsersMenu();
			 break;


		 case eUpdateUser:

			 system("cls");
			 _ShowUpdateUserScreen();
			 _GoBackToManageUsersMenu();
			 break;

		 case eFindUser:

			 system("cls");
			 _ShowFindUserScreen();
			 _GoBackToManageUsersMenu();
			 break;

		 case eBackToMainMenu:
			 break;

		 }

	 }

 public:

	 static void ShowManageUsersMenu()
	 {

		 system("cls");

		 _ShowScreenHeader("+++ Manage Users Menu +++");

		 cout << "       [1] List Users." << endl;
		 cout << "       [2] Add New User." << endl;
		 cout << "       [3] Delete User." << endl;
		 cout << "       [4] Update User." << endl;
		 cout << "       [5] Find User." << endl;
		 cout << "       [6] Main Menu." << endl;
		 cout << "============================================" << endl;

		 _PerformManageUsersMenuOption((enManageUsersMenu)_ReadManageUsersMenuOption());
	 }
};

