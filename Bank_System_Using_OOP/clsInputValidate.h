#pragma once

#include<iostream>
#include"clsDate.h"
#include"clsString.h"

using namespace std;

class clsInputValidate
{

public:


	static bool IsNumberBetween(const int& Number, const int& From, const int& To)
	{
		return (Number >= From && Number <= To);
	}

	static bool IsNumberBetween(const double& Number, const double& From, const double& To)
	{
		return (Number >= From && Number <= To);
	}

	static bool IsNumberBetween(const short& Number, const short& From, const short& To)
	{
		return (Number >= From && Number <= To);
	}

	static bool IsNumberBetween(const float& Number, const float& From, const float& To)
	{
		return (Number >= From && Number <= To);
	}

	static bool IsDateBetween(const clsDate& Date, const clsDate& Date1, const clsDate& Date2)
	{

		if ((clsDate::IsDate1EqualDate2(Date, Date1) || clsDate::IsDate1EqualDate2(Date, Date2))
			|| (clsDate::IsDate1AfterDate2(Date, Date1) && clsDate::IsDate1BeforeDate2(Date, Date2))
			|| (clsDate::IsDate1AfterDate2(Date, Date2) && clsDate::IsDate1BeforeDate2(Date, Date1)))
			return true;

		return false;
	}

	static int ReadIntNumber(const string& message = "Invalid Input! ,Try again:")
	{
		int Number;

		while (true)
		{

			cin >> Number;

			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits <streamsize> ::max(), '\n');

				cout << message << endl;
			}

			else
				return Number;
		}
	}

	static int ReadShortNumber(const string& message = "Invalid Input! ,Try again:")
	{

		short Number;

		while (true)
		{

			cin >> Number;

			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits <streamsize> ::max(), '\n');

				cout << message << endl;
			}

			else
				return Number;
		}
	}

	static double ReadDoubleNumber(const string& message = "Invalid Input! ,Try again:")
	{
		double Number;

		while (true)
		{

			cin >> Number;

			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits <streamsize> ::max(), '\n');

				cout << message << endl;
			}

			else
				return Number;
		}
	}

	static float ReadFloatNumber(const string& message = "Invalid Input! ,Try again:")
	{
		float Number;

		while (true)
		{

			cin >> Number;

			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits <streamsize> ::max(), '\n');

				cout << message << endl;
			}

			else
				return Number;
		}
	}

	static int ReadIntNumberBetween(const int& From, const int& To, const string& message = "Invalid Input! ,Try again:")
	{

		int Number = ReadIntNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << message << endl;
			Number = ReadIntNumber();
		}

		return Number;
	}

	static int ReadShortNumberBetween(const short& From, const short& To, const string& message = "Invalid Input! ,Try again:")
	{

		short Number = ReadShortNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << message << endl;
			Number = ReadIntNumber();
		}

		return Number;
	}

	static double ReadDoubleNumberBetween(const double& From, const double& To, const string& message = "Invalid Input! ,Try again:")
	{

		double Number = ReadDoubleNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << message << endl;
			Number = ReadDoubleNumber();
		}

		return Number;
	}

	static bool IsValidDate(const clsDate& Date)
	{
		return clsDate::IsValid(Date);
	}

	static string ReadString()
	{

		string S1 = "";

		getline(cin >> ws, S1);
		return S1;
	}

};