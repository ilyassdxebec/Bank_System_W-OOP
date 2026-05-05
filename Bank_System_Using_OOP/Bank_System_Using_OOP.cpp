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

	switch (SavingResult)
	{

	 case clsBankClient::enSavingResults::svFailedEmptyObject :

		  cout << "\nCouldn't Update Client's Data Failed Because Of Empty Object!";
		  break;

     case clsBankClient::enSavingResults::svSuccedded :

		  cout << "\nClient's Inof Updated Successfully !!!";
		  Client.Print();
		  break;
	}

}

int main()
{

	UpdateClient();
}
