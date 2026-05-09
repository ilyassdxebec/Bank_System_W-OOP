#include <iostream>
#include<iomanip>
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

char ConfirmDeletion()
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

void DeleteClient()
{
    
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
	Client.Print();

	Choice = ConfirmDeletion();

	if (toupper(Choice) == 'Y')
	{

		if (Client.Delete())
		{
			cout << "\nClient Was Deleted Successfully !!!\n";
			Client.Print();
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


void PrintClientRecordInfo(const clsBankClient& Client)
{

   cout << "|" << left << setw(16) << Client.AccNumber()
		<< "|" << left << setw(13) << Client.PinCode()
		<< "|" << left << setw(19) << Client.FirstName()
		<< "|" << left << setw(19) << Client.LastName()
		<< "|" << left << setw(19) << Client.PhoneNumber()
		<< "|" << left << setw(22) << Client.Email()
		<< "|" << left << setw(14) << Client.AccBalance() << endl;
}

void ListClients()
{

	vector <clsBankClient> vClients;
	vClients = clsBankClient::GetClientsList();


	if (vClients.size() == 0)
	{
		cout << "\nThe File Is Currently Empty !!!\n";
	}

	else
	{

		cout << "\n++++++++++++Clients List has (" << vClients.size() << ") Client(s)++++++++++++\n\n";

		cout << "|________________|_____________|___________________|___________________|___________________|______________________|______________\n";
		cout << "| Account Number | PinCode     | First Name        | Last Name         | Phone Number      | Email                | Balance      \n";
		cout << "|________________|_____________|___________________|___________________|___________________|______________________|______________\n";

		for (const clsBankClient &C : vClients)
		{
			PrintClientRecordInfo(C);
		}

		cout << "|________________|_____________|___________________|___________________|___________________|______________________|______________\n\n";

	}
	
}

int main()
{

	ListClients();
}
