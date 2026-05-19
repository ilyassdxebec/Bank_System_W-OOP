#pragma once

#include<iostream>

#include"clsMainScreen.h"
#include"clsScreen.h"
#include"clsListCurrenciesScreen.h"

using namespace std;

class clsCurrencyExchangeScreen : protected clsScreen
{

 private:

	 
	 enum enCurrencyExchangeMenu { eListCurrencies = 1, eFindCurrency = 2, eUpdateRate = 3, eCurrencyCalculator = 4, eReturnMainMenu = 5 };

	 static void _GoBackToCurrencyExchangeMenu()
	 {

		 cout << "\n\n+++ Press Any Key To Go Back To Currency Exchnage Menu +++";

		 system("pause>0");

		 ShowCurrencyExchangeMenu();
	 }

	 static void _ShowListCurrenciesScreen()
	 {
		 clsListCurrenciesScreen::Show();
	 }

	 static void _ShowFindCurrencyScreen()
	 {
		 
	 }

	 static void _ShowUpdateRateScreen()
	 {
		 
	 }

	 static void _ShowCurrencyCalculatorScreen()
	 {
		
	 }

	 static short _ReadCurrencyExchangeMenuOption()
	 {

		 short Choice;

		 cout << "\nChoose what do you want to do ? [1-5] : ";

		 Choice = clsInputValidate::ReadShortNumberBetween(1, 5);

		 return Choice;
	 }

	 static void _ManageCurrencyExchangeMenuOption(const enCurrencyExchangeMenu& Choice)
	 {

		 switch (Choice)
		 {

		 case eListCurrencies:

			 system("cls");
			 _ShowListCurrenciesScreen();
			 _GoBackToCurrencyExchangeMenu();
			 break;


		 case eFindCurrency:

			 system("cls");
			 _ShowFindCurrencyScreen();
			 _GoBackToCurrencyExchangeMenu();
			 break;


		 case eUpdateRate:

			 system("cls");
			 _ShowUpdateRateScreen();
			 _GoBackToCurrencyExchangeMenu();
			 break;


		 case eCurrencyCalculator:

			 system("cls");
			 _ShowCurrencyCalculatorScreen();
			 _GoBackToCurrencyExchangeMenu();
			 break;


		 case eReturnMainMenu:
			 break;

		 }
	 }

 public:


	 static void ShowCurrencyExchangeMenu()
	 {

		 if (!_ShowIsFeatureAvailable(clsUser::enMainMenuPermissions::pCurrencyExchange))
			 return;


		 system("cls");

		 _ShowScreenHeader("+++ Currency Exchange Menu +++");

		 cout << "       [1] List Currencies." << endl;
		 cout << "       [2] Find Currency." << endl;
		 cout << "       [3] Update Rate." << endl;
		 cout << "       [4] Currency Calculator." << endl;
		 cout << "       [5] Main Menu." << endl;
		 cout << "============================================" << endl;

		 _ManageCurrencyExchangeMenuOption((enCurrencyExchangeMenu)_ReadCurrencyExchangeMenuOption());
	 }

};

