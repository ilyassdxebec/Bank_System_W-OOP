#pragma once

#include<iostream>
#include"clsScreen.h"
#include"clsListClientsScreen.h"
#include"clsAddNewClientScreen.h"
#include"clsDeleteClientScreen.h"
#include"clsInputValidate.h"
#include"clsUpdateClientScreen.h"
#include"clsFindClientScreen.h"
#include"clsTransactionsScreen.h"
#include"clsManageUsersScreen.h"
#include"Global.h"

using namespace std;

class clsMainScreen : protected clsScreen
{

 private:

	 enum enMenuChoice { eShow = 1, eAdd = 2, eDelete = 3, eUpdate = 4, eFind = 5, eTransactions = 6, eManageUsers = 7, eLogout = 8 };


	 static short _ReadMainMenuOption()
	 {

		 short Choice;

		 cout << "\nChoose what do you want to do ? [1-8] : ";

		 Choice = clsInputValidate::ReadShortNumberBetween(1, 8);

		 return Choice;
	 }

	 static void _GoBackToMainMenu()
	 {

		 cout << "\n\n+++ Press Any Key To Go Back To Main Menu +++";

		 system("pause>0");

		 ShowMainMenu();
	 }

	 static void _ShowAllClientsScreen()
	 { 
		 clsListClientsScreen::Show();
	 }


	 static void _ShowAddNewClientScreen()
	 {
		 clsAddNewClientScreen::Show();
	 }


	 static void _ShowDeleteClientScreen()
	 {
		 clsDeleteClientScreen::Show();
	 }


	 static void _ShowUpdateClientScreen()
	 {
		 clsUpdateClientScreen::Show();
	 }


	 static void _ShowFindClientScreen()
	 {
		 clsFindClientScreen::Show();
	 }


	 static void _ShowTransactionsMenu()
	 {
		 clsTransactionsScreen::ShowTransactionsMenu();
	 }


	 static void _ShowManageUsersMenu()
	 {
		 clsManageUsersScreen::ShowManageUsersMenu();
	 }


	 static void _Logout()
	 {
		 CurrentUser = clsUser::Find("", "");
	 }


	 static void _ManageMainMenuOption(const enMenuChoice &Choice)
	 {

		 switch (Choice)
		 {

		  case eShow:

			  system("cls");
			  _ShowAllClientsScreen();
			  _GoBackToMainMenu();
			  break;

		  case eAdd:

			  system("cls");
			  _ShowAddNewClientScreen();
			  _GoBackToMainMenu();
			  break;

		  case eDelete:

			  system("cls");
			  _ShowDeleteClientScreen();
			  _GoBackToMainMenu();
			  break;

		  case eUpdate:

			  system("cls");
			  _ShowUpdateClientScreen();
			  _GoBackToMainMenu();
			  break;

		  case eFind:

			  system("cls");
			  _ShowFindClientScreen();
			  _GoBackToMainMenu();
			  break;

		  case eTransactions:

			  system("cls");
			  _ShowTransactionsMenu();
			  _GoBackToMainMenu();
			  break;

		  case eManageUsers:

			  system("cls");
			  _ShowManageUsersMenu();
			  _GoBackToMainMenu();
			  break;

		  case eLogout:

			  system("cls");
			  _Logout();
			  break;
		 }

	 }


 public:


	 static void ShowMainMenu()
	 {

		 system("cls");

		 _ShowScreenHeader("+++ Main Menu Screen +++");

		 cout << "       [1] Show Client List." << endl;
		 cout << "       [2] Add New Client." << endl;
		 cout << "       [3] Delete Client." << endl;
		 cout << "       [4] Update Client Info." << endl;
		 cout << "       [5] Find Client Info." << endl;
		 cout << "       [6] TransactionsMenu." << endl;
		 cout << "       [7] Manage Users." << endl;
		 cout << "       [8] Logout." << endl;
		 cout << "============================================" << endl;

		 _ManageMainMenuOption((enMenuChoice)_ReadMainMenuOption());

	 }

};

