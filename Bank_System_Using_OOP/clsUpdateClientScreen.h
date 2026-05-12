#pragma once

#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"

using namespace std;

class clsUpdateClientScreen : protected clsScreen
{

 private:
 
	 static void _ReadClientData(clsBankClient& Client)
	 {

		 cout << "\nEnter Client's First Name : ";
		 Client.SetFirstName(clsInputValidate::ReadString());

		 cout << "\nEnter Client's Last Name : ";
		 Client.SetLastName(clsInputValidate::ReadString());

		 cout << "\nEnter Client's Phone Number : ";
		 Client.SetPhoneNumber(clsInputValidate::ReadString());

		 cout << "\nEnter Client's Email : ";
		 Client.SetEmail(clsInputValidate::ReadString());

		 cout << "\nEnter Client's Pin Code : ";
		 Client.SetPinCode(clsInputValidate::ReadString());

		 cout << "\nEnter Client's Account Balance : ";
		 Client.SetAccBalance(clsInputValidate::ReadFloatNumber());
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

	 static char _ConfirmUpdate()
	 {

		 char Choice;

		 cout << "\nAre you sure you want to Update this Client? (y/n) : ";
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

		 _ShowScreenHeader("+++ Update Client Screen +++");

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

		 Choice = _ConfirmUpdate();

		 if (toupper(Choice) == 'Y')
		 {
			 cout << "\n+++++ Update Client's Info +++++\n";

			 _ReadClientData(Client);

			 clsBankClient::enSavingResults SavingResult;
			 SavingResult = Client.Save();


			 switch (SavingResult)
			 {

			 case clsBankClient::enSavingResults::svFailedEmptyObject:

				 cout << "\nCouldn't Update Client's Data Failed Because Of Empty Object!\n";
				 break;


			 case clsBankClient::enSavingResults::svUpdateSuccedded:

				 cout << "\nClient's Info Updated Successfully !!!\n";
				 _PrintClient(Client);
				 break;


			 default:
				 break;
			 }
		 }

		 else
		 {
			 cout << "\nClient Wasn't Updated as you wanted !!!";
		 }
	 }
};

