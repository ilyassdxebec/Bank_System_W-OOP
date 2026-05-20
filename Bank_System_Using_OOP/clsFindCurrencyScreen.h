#pragma once

#include<iostream>

#include"clsCurrency.h"
#include"clsScreen.h"
#include"clsInputValidate.h"

using namespace std;

class clsFindCurrencyScreen : protected clsScreen
{

 private:

	 static void _PrintCurrencyInfo(const clsCurrency &Currency)
	 {

		 cout << "\n\n++++++ Currency's Info ++++++\n\n";

		 cout << "___________________________________\n";
		 cout << "Country  : " << Currency.Country() << endl;
		 cout << "Code     : " << Currency.CurrencyCode() << endl;
		 cout << "Name     : " << Currency.CurrencyName()<< endl;
		 cout << "Rate(1$) : " << Currency.CurrencyRate() << endl;
		 cout << "___________________________________\n\n";
	 }

	 static void _ShowCurrencySearchResult(clsCurrency Currency)
	 {

		 if (Currency.IsEmpty())
		 {
			 cout << "\nCurrency Not Found!!!";
			 return;
		 }

		 cout << "\nCurrency Found !!!";
		 _PrintCurrencyInfo(Currency);
	 }

 public:

	 static void Show()
	 {

		 _ShowScreenHeader("+++ Find Currency Screen +++");

		 cout << "Find By : [1] : Currency Code [2] : Country : ";

		 short Choice;

		 Choice = clsInputValidate::ReadShortNumberBetween(1, 2);

		 if (Choice == 1)
		 {

			 string CurrencyCode;

			 cout << "\nPlease Enter Currency Code : ";

			 CurrencyCode = clsInputValidate::ReadString();

			 clsCurrency Currency = clsCurrency::FindByCurrencyCode(CurrencyCode);

			 _ShowCurrencySearchResult(Currency);
		 }

		 else
		 {

			 string Country;

			 cout << "\nPlease Enter Country : ";

			 Country = clsInputValidate::ReadString();

			 clsCurrency Currency = clsCurrency::FindByCountry(Country);

			 _ShowCurrencySearchResult(Currency);
		 }
	 }
};

