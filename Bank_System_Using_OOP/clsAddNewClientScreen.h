#pragma once

#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"


using namespace std;

class clsAddNewClientScreen : protected clsScreen
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


	 static void _PrintClient(const clsBankClient &Client)
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

		 string AccNumber;

		 cout << "Please Enter Client's Account Number : ";
		 AccNumber = clsInputValidate::ReadString();

		 while (clsBankClient::IsClientExist(AccNumber))
		 {
			 cout << "\nClient With Account Number Already Exist! Please Try Again : ";
			 AccNumber = clsInputValidate::ReadString();
		 }

		 clsBankClient Client = clsBankClient::GetAddNewClientObject(AccNumber);


		 cout << "\n+++++ Adding New Client +++++\n";

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


		 case clsBankClient::enSavingResults::svAddSuccedded:

			 cout << "\nClient's Info Added Successfully !!!\n";
			 _PrintClient(Client);
			 break;


		 case clsBankClient::enSavingResults::svFailedAccNumberExists:

			 cout << "\nClient Already Exists!\n";
			 break;


		 default:
			 break;
		 }

	 }
};

