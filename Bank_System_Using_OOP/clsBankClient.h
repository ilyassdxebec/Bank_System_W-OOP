#pragma once

#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include"clsString.h"
#include"clsPerson.h"

using namespace std;

class clsBankClient : public clsPerson
{

 private:
     
	 enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2};

	 string _AccNumber;	
	 string _PinCode;
	 enMode _Mode;
	 float _AccBalance;
	 bool _MarkForDelete = false;

	 static clsBankClient _ConvertLineToClientObject(const string& Line, string delim = "#//#")
	 {

		 vector<string> vWords;
		 vWords = clsString::Split(Line, delim);

		 return clsBankClient(enMode::UpdateMode, vWords.at(0), vWords.at(1), vWords.at(2), vWords.at(3), vWords.at(4), vWords.at(5), stod(vWords.at(6)) );
	 }

	 static vector <clsBankClient> _LoadClientsDataFromFile(const string& FileName)
	 {
		 fstream MyFile;
		 vector <clsBankClient> vClients;

		 MyFile.open(FileName, ios::in);

		 if (MyFile.is_open())
		 {
			 string Line;

			 while (getline(MyFile, Line))
			 {
				 vClients.push_back(_ConvertLineToClientObject(Line));
			 }

			 MyFile.close();
		 }

		 return vClients;
	 }

	 static string _ConvertClientObjectToLine(clsBankClient &Client, string delim = "#//#")
	 {

		 string Line = "";

		 Line += Client.FirstName() + delim;
		 Line += Client.LastName() + delim;
		 Line += Client.PhoneNumber() + delim;
		 Line += Client.Email() + delim;
		 Line += Client.AccNumber() + delim;
		 Line += Client.PinCode() + delim;
		 Line += to_string(Client.AccBalance());

		 return Line;
	 }


	 static void _SaveClientsObjectToFile(const string& FileName, vector <clsBankClient> &vClients)
	 {

		 fstream MyFile;

		 MyFile.open(FileName, ios::out);

		 if (MyFile.is_open())
		 {
			 for (clsBankClient &C : vClients)
			 {
				 if (C._MarkForDelete != true)
				 {
					 MyFile << _ConvertClientObjectToLine(C) << endl;
				 }
			 }

			 MyFile.close();
		 }
	 }

	 static clsBankClient _GetEmptyClientObject()
	 {
		 return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	 }

	 void _Update()
	 {

		 vector <clsBankClient> vClients;
		 vClients = _LoadClientsDataFromFile("Clients.txt");

		 for (clsBankClient &C : vClients)
		 {
			 if (C.AccNumber() == AccNumber())
			 {
				 C = *this;
				 break;
			 }
		 }

		 _SaveClientsObjectToFile("Clients.txt", vClients);
	 }

	 void _AddNew()
	 {
		 _AddLineToFile(_ConvertClientObjectToLine(*this) ,"Clients.txt");
	 }

	 static void _AddLineToFile(const string& Line, const string& FileName)
	 {
		 fstream MyFile;

		 MyFile.open(FileName, ios::app);

		 if (MyFile.is_open())
		 {
			 MyFile << Line << endl;
		 }

		 MyFile.close();
	 }

 public:

	 clsBankClient(const enMode &Mode ,const string& FirstName, const string& LastName, const string& PhoneNumber, const string& Email,
		           const string &AccNumber ,const string &PinCode ,const float &AccBalance)
		 :clsPerson(FirstName ,LastName ,PhoneNumber ,Email)
	 {
		 _Mode = Mode;
		 _AccNumber = AccNumber;
		 _PinCode = PinCode;
		 _AccBalance = AccBalance;
	 }

	 string AccNumber() const 
	 {
		 return _AccNumber;
	 }

	 string PinCode() const 
	 {
		 return _PinCode;
	 }

	 void SetPinCode(const string& PinCode)
	 {
		 _PinCode = PinCode;
	 }

	 float AccBalance() const
	 {
		 return _AccBalance;
	 }

	 void SetAccBalance(const float& AccBalance)
	 {
		 _AccBalance = AccBalance;
	 }
     
	 void Print () const
	 {
		 cout << "\n\n++++++ Client's Informations ++++++\n\n";

		 cout << "___________________________________\n";
		 cout << "First Name   : " << FirstName() << endl;
		 cout << "Last Name    : " << LastName() << endl;
		 cout << "Phone Number : " << PhoneNumber() << endl;
		 cout << "Email Adress : " << Email() << endl;
		 cout << "Acc Number   : " << _AccNumber << endl;
		 cout << "Pin Code     : " << _PinCode << endl;
		 cout << "Acc Balance  : " << _AccBalance << endl;
		 cout << "___________________________________\n\n";

	 }

	 static clsBankClient Find(const string& AccNumber)
	 {

		 fstream MyFile;
		 vector <clsBankClient> Clients;

		 MyFile.open("Clients.txt", ios::in);

		 if (MyFile.is_open())
		 {
			 string Line;

			 while (getline(MyFile, Line))
			 {
				 clsBankClient Client = _ConvertLineToClientObject(Line);

				 if (Client.AccNumber() == AccNumber)
				 {
					 MyFile.close();
					 return Client;
				 }
			 }

			 MyFile.close();
		 }

		 return _GetEmptyClientObject();
	 }

	 static clsBankClient Find(const string& AccNumber ,const string &PinCode)
	 {

		 fstream MyFile;
		 vector <clsBankClient> Clients;

		 MyFile.open("Clients.txt", ios::in);

		 if (MyFile.is_open())
		 {
			 string Line;

			 while (getline(MyFile, Line))
			 {
				 clsBankClient Client = _ConvertLineToClientObject(Line);

				 if (Client.AccNumber() == AccNumber && Client.PinCode() == PinCode)
				 {
					 MyFile.close();
					 return Client;
				 }
			 }

			 MyFile.close();
		 }

		 return _GetEmptyClientObject();
	 }

	 bool IsEmpty()
	 {
		 return (_Mode == EmptyMode );
	 }

	 static bool IsClientExist(const string &AccNumber)
	 {

		 clsBankClient Client = clsBankClient::Find(AccNumber);

		 return (!Client.IsEmpty()) ;
	 }

	 static clsBankClient GetAddNewClientObject(const string &AccNumber)
	 {

		 return clsBankClient(enMode::AddNewMode, "", "", "", "", AccNumber, "", 0);
	 }

	 static vector <clsBankClient> GetClientsList()
	 {
		 return _LoadClientsDataFromFile("Clients.txt");
	 }

	 static double GetTotalBalances()
	 {

		 vector <clsBankClient> vClients;
		 vClients = _LoadClientsDataFromFile("Clients.txt");

		 double TotalBalances = 0;

		 for (clsBankClient &C : vClients)
		 {
			 TotalBalances += C.AccBalance();
		 }

		 return TotalBalances;
	 }

	 bool Delete()
	 {

		 vector <clsBankClient> vClients;
		 vClients = _LoadClientsDataFromFile("Clients.txt");


		 for (clsBankClient& C : vClients)
		 {
			 if (C.AccNumber() == AccNumber())
			 {

				 C._MarkForDelete = true;

				 _SaveClientsObjectToFile("Clients.txt", vClients);

				 *this = _GetEmptyClientObject();

				 return true;

			 }
		 }

		  return false;
	 }

	 enum enSavingResults{svFailedEmptyObject = 0 ,svUpdateSuccedded = 1 ,svAddSuccedded = 2 , svFailedAccNumberExists = 3};


	 enSavingResults Save()
	 {

		 switch (_Mode)
		 {

		  case EmptyMode:

			   return svFailedEmptyObject;


		  case UpdateMode:

			   _Update();
			   return svUpdateSuccedded;


		  case AddNewMode:
			   

			  if (IsClientExist(_AccNumber))
			  {
				  return svFailedAccNumberExists;
			  }

			  else
			  {
				  _AddNew();
				  _Mode = UpdateMode;
				  return svAddSuccedded;

			  }
		 }
	 }
};