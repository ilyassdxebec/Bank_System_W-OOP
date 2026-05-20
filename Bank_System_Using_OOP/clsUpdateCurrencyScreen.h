#pragma once

#include<iostream>

#include"clsCurrency.h"
#include"clsScreen.h"

using namespace std;

class clsUpdateCurrencyScreen : protected clsScreen
{

 private:


	 static void _PrintCurrencyInfo(const clsCurrency& Currency)
	 {

		 cout << "\n\n++++++ Currency's Info ++++++\n\n";

		 cout << "___________________________________\n";
		 cout << "Country  : " << Currency.Country() << endl;
		 cout << "Code     : " << Currency.CurrencyCode() << endl;
		 cout << "Name     : " << Currency.CurrencyName() << endl;
		 cout << "Rate(1$) : " << Currency.CurrencyRate() << endl;
		 cout << "___________________________________\n\n";
	 }

	 static clsCurrency _ReadCurrencyCode ()
	 {

		 string CurrencyCode;

		 cout << "\nPlease Enter Currency Code : ";

		 CurrencyCode = clsInputValidate::ReadString();

		 clsCurrency Currency = clsCurrency::FindByCurrencyCode(CurrencyCode);

		 while (Currency.IsEmpty())
		 {
			 cout << "\nCurrency Not Found ! please Enter Currency Code again : ";
			 CurrencyCode = clsInputValidate::ReadString();

			 clsCurrency Currency = clsCurrency::FindByCurrencyCode(CurrencyCode);
		 }

		 return Currency;
	 }

	 static char _ConfirmUpdate()
	 {

		 char Choice;

		 cout << "\nAre you sure you want to Update the rate of this Currency ? (y/n) : ";
		 cin >> Choice;

		 while (toupper(Choice) != 'Y' && toupper(Choice) != 'N')
		 {
			 cout << "\nInvalid Choice! Enter a vaild choice (y/n) : ";
			 cin >> Choice;
		 }

		 return Choice;
	 }

 public:

	 static void Show()
	 {

		 char Choice;

		 _ShowScreenHeader("+++ Update Currency Screen +++");

		 clsCurrency Currency = _ReadCurrencyCode();

		 _PrintCurrencyInfo(Currency);

		 Choice = _ConfirmUpdate();

		 if (toupper(Choice) == 'Y')
		 {

			 float NewRate;

			 cout << "\n+++ Updating Currency Rate +++\n";

			 cout << "Please Enter New Currency Rate : ";

			 NewRate = clsInputValidate::ReadFloatNumber();

			 Currency.Update(NewRate);

			 cout << "\nCurrency Rate Updated Successfully !!!\n";

			 _PrintCurrencyInfo(Currency);
		 }

		 else
		 {
			 cout << "\nCurrency Wasn't Updated as you wanted !";
		 }
	 }
};

