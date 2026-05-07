#include <iostream>
#include"clsBankClient.h"
#include"clsInputValidate.h"

using namespace std;

void ReadClientData(clsBankClient &Client)
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

void CheckSavingResults(const clsBankClient::enSavingResults &SavingResult , const clsBankClient &Client)
{

	switch (SavingResult)
	{

	 case clsBankClient::enSavingResults::svFailedEmptyObject:

		cout << "\nCouldn't Update Client's Data Failed Because Of Empty Object!\n";
		break;


	 case clsBankClient::enSavingResults::svUpdateSuccedded:

		cout << "\nClient's Info Updated Successfully !!!\n";
		Client.Print();
		break;

    
	 case clsBankClient::enSavingResults::svAddSuccedded:

		cout << "\nClient's Info Added Successfully !!!\n";
		Client.Print();
		break;


     case clsBankClient::enSavingResults::svFailedAccNumberExists:

		 cout << "\nClient Already Exists!\n";
		 break;


	 default:
		 break;
	}

}

void UpdateClient()
{

	string AccNumber;

	cout << "Please Enter Client's Account Number : ";
	AccNumber = clsInputValidate::ReadString();

	while (!clsBankClient::IsClientExist(AccNumber))
	{
		cout << "\nClient With Account Number Doesn't Exist! Please Try Again : ";
		AccNumber = clsInputValidate::ReadString();
	}

	clsBankClient Client = clsBankClient::Find(AccNumber);
	Client.Print();

	cout << "\n+++++ Update Client's Info +++++\n";

	ReadClientData(Client);

	clsBankClient::enSavingResults SavingResult;
	SavingResult = Client.Save();

	CheckSavingResults(SavingResult, Client);

}

void AddNewClient()
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

	ReadClientData(Client);

	clsBankClient::enSavingResults SavingResult;
	SavingResult = Client.Save();

	CheckSavingResults(SavingResult, Client);

}

int main()
{

	AddNewClient();
}
