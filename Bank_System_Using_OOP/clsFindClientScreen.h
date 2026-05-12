#pragma once

#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"

using namespace std;

class clsFindClientScreen : protected clsScreen
{
 
 private:

	 static void _PrintClient(const clsBankClient& Client)
	 {

		 cout << "\n\n++++++ Client's Informations ++++++\n\n";

		 cout << "___________________________________\n";
		 cout << "First Name   : " << Client.FirstName() << endl;
		 cout << "Last Name    : " << Client.LastName() << endl;
		 cout << "Phone Number : " << Client.PhoneNumber() << endl;
		 cout << "Email Adress : " << Client.Email() << endl;
		 cout << "Acc Number   : " << Client.AccNumber() << endl;
		 cout << "Pin Code     : " << Client.PinCode() << endl;
		 cout << "Acc Balance  : " << Client.AccBalance() << endl;
		 cout << "___________________________________\n\n";

	 }


 public:

	 static void Show()
	 {

		 _ShowScreenHeader("+++ Find Client Screen +++");

		 string AccNumber;

		 cout << "Please Enter Client's Account Number : ";
		 AccNumber = clsInputValidate::ReadString();

		 while (!clsBankClient::IsClientExist(AccNumber))
		 {
			 cout << "\nClient With Account Number Doesn't Exist! Please Try Again : ";
			 AccNumber = clsInputValidate::ReadString();
		 }

		 clsBankClient Client = clsBankClient::Find(AccNumber);

		 cout << "\n+++++ Client Info +++++\n";

		 _PrintClient(Client);
	 }

};

