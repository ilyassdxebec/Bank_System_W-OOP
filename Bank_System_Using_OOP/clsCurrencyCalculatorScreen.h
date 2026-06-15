#pragma once

#include<iostream>

#include"clsScreen.h"
#include"clsCurrency.h"
#include"clsInputValidate.h"

using namespace std;

class clsCurrencyCalculatorScreen : protected clsScreen
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

	 static clsCurrency _ReadCurrencyCode()
	 {

		 string CurrencyCode;

		 cout << "\nPlease Enter Currency Code : ";

		 CurrencyCode = clsInputValidate::ReadString();

		 clsCurrency Currency = clsCurrency::FindByCurrencyCode(CurrencyCode);

		 while (Currency.IsEmpty())
		 {
			 cout << "\nCurrency Not Found ! please Enter Currency Code again : ";
			 CurrencyCode = clsInputValidate::ReadString();

			 Currency = clsCurrency::FindByCurrencyCode(CurrencyCode);
		 }

		 return Currency;
	 }

 public:

	 static void Show()
	 {

		 _ShowScreenHeader("+++ Currency Calculator Screen +++");


	 }
};

