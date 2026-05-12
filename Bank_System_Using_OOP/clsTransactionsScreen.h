#pragma once

#include<iostream>
#include"clsScreen.h"

using namespace std;

class clsTransactionsScreen : clsScreen
{

 private:

	 enum enTransactionsMenu { eDeposit = 1, eWithdraw = 2, eTotalBalances = 3, eReturnMainMenu = 4 };

	 static void _GoBackToTransactionsMenu()
	 {

		 cout << "\n\n+++ Press Any Key To Go Back To Transactions Menu +++";

		 system("pause>0");

		 ShowTransactionsMenu();
	 }

	 static void _ShowDepositScreen()
	 {

	 }

	 static void _ShowWithDrawScreen()
	 {

	 }

	 static void _ShowTotalBalancesScreen()
	 {

	 }

	 static short _ReadTransactionsMenuOption()
	 {

		 short Choice;

		 cout << "\nChoose what do you want to do ? [1-4] : ";

		 Choice = clsInputValidate::ReadShortNumberBetween(1, 4);

		 return Choice;
	 }

	 static void _ManageTransactionsMenuOption(const enTransactionsMenu &Choice)
	 {

		 switch (Choice)
		 {

		 case eDeposit:

			 system("cls");
			 _ShowDepositScreen();
			 _GoBackToTransactionsMenu();
			 break;

		 case eWithdraw:

			 system("cls");
			 _ShowWithDrawScreen();
			 _GoBackToTransactionsMenu();
			 break;

		 case eTotalBalances:

			 system("cls");
			 _ShowTotalBalancesScreen();
			 _GoBackToTransactionsMenu();
			 break;


		 case eReturnMainMenu:
			 break;

		 }

	 }

 public:

	 static void ShowTransactionsMenu()
	 {

		 system("cls");

		 _ShowScreenHeader("+++ Transactions Menu +++");

		 cout << "       [1] Deposit." << endl;
		 cout << "       [2] Withdraw." << endl;
		 cout << "       [3] Total Balances." << endl;
		 cout << "       [4] Main Menu." << endl;
		 cout << "============================================" << endl;

		 _ManageTransactionsMenuOption((enTransactionsMenu)_ReadTransactionsMenuOption());
	 }
};

