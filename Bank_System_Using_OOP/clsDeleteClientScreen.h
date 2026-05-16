#pragma once

#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"

using namespace std;

class clsDeleteClientScreen : protected clsScreen
{
 
 private:

	 static char _ConfirmDeletion()
	 {

		 char Choice;

		 cout << "\nAre you sure you want to delete this Client? (y/n) : ";
		 cin >> Choice;

		 while (toupper(Choice) != 'Y' && toupper(Choice) != 'N')
		 {
			 cout << "\nInvalid Choice! Enter a vaild choice (y/n) : ";
			 cin >> Choice;
		 }

		 return Choice;
	 }

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


		 if (!_ShowIsFeatureAvailable(clsUser::enMainMenuPermissions::pDeleteClient))
			 return;

		 _ShowScreenHeader("+++ Delete Client Screen +++");

		 string AccNumber;
		 char Choice;

		 cout << "Please Enter Client's Account Number : ";
		 AccNumber = clsInputValidate::ReadString();

		 while (!clsBankClient::IsClientExist(AccNumber))
		 {
			 cout << "\nClient With Account Number Doesn't Exist! Please Try Again : ";
			 AccNumber = clsInputValidate::ReadString();
		 }

		 clsBankClient Client = clsBankClient::Find(AccNumber);
		 _PrintClient(Client);

		 Choice = _ConfirmDeletion();

		 if (toupper(Choice) == 'Y')
		 {

			 if (Client.Delete())
			 {
				 cout << "\nClient Was Deleted Successfully !!!\n";
				 _PrintClient(Client);
			 }

			 else
			 {
				 cout << "\nError ,Couldn't Delete Client!\n";
			 }
		 }

		 else
		 {
			 cout << "\nClient Wasn't Deleted as you wanted !\n";
		 }

	 }

};

