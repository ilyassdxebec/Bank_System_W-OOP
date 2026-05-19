#pragma once

#include<iostream>
#include<vector>
#include<iomanip>

#include"clsScreen.h"
#include"clsCurrency.h"

using namespace std;

class clsListCurrenciesScreen : protected clsScreen
{

 private:

	 static void _PrintCurrencyRecordInfo(const clsCurrency &Currency)
	 {

		 cout << "|" << left << setw(30) << Currency.Country()
			 << "|" << left << setw(16) << Currency.CurrencyCode()
			 << "|" << left << setw(45) << Currency.CurrencyName()
			 << "|" << left << setw(15) << " " + to_string(Currency.CurrencyRate()) << endl;
	 }

 public:

	 static void Show()
	 {

		 vector <clsCurrency> vCurrencies;
		 vCurrencies = clsCurrency::GetCurrenciesList();


		 if (vCurrencies.size() == 0)
		 {
			 cout << "\nThe File Is Currently Empty !!!\n";
		 }

		 else
		 {

			 string Title = "+++ List Currencies Screen +++";
			 string SubTitle = "+++ List Has " + to_string(vCurrencies.size()) + " Currency(s) +++";

			 _ShowScreenHeader(Title, SubTitle);

			 cout << "|______________________________|________________|_____________________________________________|_______________\n";
			 cout << "| Country Name                 | Currency Code  | Currency Name                               | Rate/(1$)     \n";
			 cout << "|______________________________|________________|_____________________________________________|_______________\n";

			 for (const clsCurrency &C : vCurrencies)
			 {
				 _PrintCurrencyRecordInfo(C);
			 }

			 cout << "|______________________________|________________|_____________________________________________|________________\n\n";

		 }

	 }
};

