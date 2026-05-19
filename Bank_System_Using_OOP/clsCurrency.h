#pragma once

#include<iostream>
#include<vector>
#include<string>
#include<fstream>

#include"clsString.h"

using namespace std;

class clsCurrency
{

 private:

	 enum enMode { EmptyMode = 0, UpdateMode = 1};

	 enMode _Mode;

	 string _Country;
	 string _CurrencyCode;
	 string _CurrencyName;

	 float _Rate;

	 static clsCurrency _GetEmptyCurrencyObject()
	 {
		 return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	 }

	 static clsCurrency _ConvertLineToCurrencyObject(const string &Line, string delim = "#//#")
	 {

		 vector <string> vWords;
		 vWords = clsString::Split(Line, delim);

		 return clsCurrency(enMode::UpdateMode, vWords.at(0), vWords.at(1), vWords.at(2), stof(vWords.at(3)));
	 }

	 static string _ConvertCurrencyObjectToLine(clsCurrency &Currency, string delim = "#//#")
	 {

		 string Line = "";

		 Line += Currency._Country + delim;
		 Line += Currency._CurrencyCode + delim;
		 Line += Currency._CurrencyName + delim;
		 Line += to_string(Currency._Rate);

		 return Line;

	 }
	 static void _SaveCurrenciesObjectToFile(const string& FileName, vector <clsCurrency> &vCurrencies)
	 {

		 fstream MyFile;

		 MyFile.open(FileName, ios::out);

		 if (MyFile.is_open())
		 {
			 for (clsCurrency &C : vCurrencies)
			 {
				 MyFile << _ConvertCurrencyObjectToLine(C) << endl;
			 }

			 MyFile.close();
		 }
	 }

	 static vector <clsCurrency> _LoadCurrenciesDataFromFile(const string& FileName)
	 {

		 fstream MyFile;
		 vector <clsCurrency> vCurrencies;

		 MyFile.open(FileName, ios::in);

		 if (MyFile.is_open())
		 {
			 string Line;

			 while (getline(MyFile, Line))
			 {
				 vCurrencies.push_back(_ConvertLineToCurrencyObject(Line));
			 }

			 MyFile.close();
		 }

		 return vCurrencies;

	 }

	 void _Update()
	 {

		 vector <clsCurrency> vCurrencies;
		 vCurrencies = _LoadCurrenciesDataFromFile("Currencies.txt");

		 for (clsCurrency& C : vCurrencies)
		 {
			 if (C.CurrencyCode() == CurrencyCode())
			 {
				 C = *this;
				 break;
			 }
		 }

		 _SaveCurrenciesObjectToFile("Currencies.txt", vCurrencies);
	 }

 public:

	 clsCurrency(const enMode &Mode ,const string &Country ,const string &CurrencyCode ,const string &CurrencyName ,const float &Rate)
	 {
		 _Mode = Mode;
		 _Country = Country;
		 _CurrencyCode = CurrencyCode;
		 _CurrencyName = CurrencyName;
		 _Rate = Rate;
	 }

	 string Country() const
	 {
		 return _Country;
	 }

	 string CurrencyCode() const
	 {
		 return _CurrencyCode;
	 }

	 string CurrencyName() const
	 {
		 return _CurrencyName;
	 }

	 void Update(const float &Rate)
	 {

		 _Rate = Rate;
		 _Update();
	 }

	 static clsCurrency FindByCountry(const string &Country)
	 {

		 fstream MyFile;
		 vector <clsCurrency> vCurrencies;

		 MyFile.open("Currencies.txt", ios::in);

		 if (MyFile.is_open())
		 {
			 string Line;

			 while (getline(MyFile, Line))
			 {
				 clsCurrency Currency = _ConvertLineToCurrencyObject(Line);

				 if (clsString::UpperCaseString(Currency.Country()) == clsString::UpperCaseString(Country))
				 {
					 MyFile.close();
					 return Currency;
				 }
			 }

			 MyFile.close();
		 }

		 return _GetEmptyCurrencyObject();
	 }

	 static clsCurrency FindByCurrencyCode(const string &CurrencyCode)
	 {

		 fstream MyFile;
		 vector <clsCurrency> vCurrencies;

		 MyFile.open("Currencies.txt", ios::in);

		 if (MyFile.is_open())
		 {
			 string Line;

			 while (getline(MyFile, Line))
			 {
				 clsCurrency Currency = _ConvertLineToCurrencyObject(Line);

				 if (Currency.CurrencyCode() == clsString::UpperCaseString(CurrencyCode))
				 {
					 MyFile.close();
					 return Currency;
				 }
			 }

			 MyFile.close();
		 }

		 return _GetEmptyCurrencyObject();
	 }

	 bool IsEmpty()
	 {
		 return (_Mode == EmptyMode);
	 }

	 static bool IsCurrencyExist(const string &CurrencyCode)
	 {

		 clsCurrency Currency = clsCurrency::FindByCurrencyCode(CurrencyCode); 

		 return (!Currency.IsEmpty());
	 }

	 static vector <clsCurrency> GetCurrenciesList()
	 {
		 return _LoadCurrenciesDataFromFile("Currencies.txt");
	 }
};

