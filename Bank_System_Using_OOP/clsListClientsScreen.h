#pragma once

#include<iostream>
#include<string>
#include<iomanip>
#include"clsScreen.h"
#include"clsBankClient.h"

using namespace std;

class clsListClientsScreen : protected clsScreen
{
 
 private:

	 static void _PrintClientRecordInfo(const clsBankClient& Client)
	 {

		 cout << "|" << left << setw(16) << Client.AccNumber()
			 << "|" << left << setw(13) << Client.PinCode()
			 << "|" << left << setw(19) << Client.FirstName()
			 << "|" << left << setw(19) << Client.LastName()
			 << "|" << left << setw(19) << Client.PhoneNumber()
			 << "|" << left << setw(22) << Client.Email()
			 << "|" << left << setw(14) << Client.AccBalance() << endl;
	 }
  
 public:

	 static void ListClients()
	 {

		 vector <clsBankClient> vClients;
		 vClients = clsBankClient::GetClientsList();


		 if (vClients.size() == 0)
		 {
			 cout << "\nThe File Is Currently Empty !!!\n";
		 }

		 else
		 {

			 string Title = "+++ List Clients Screen +++";
			 string SubTitle = "+++ List Has " + to_string(vClients.size()) + " Client(s) +++";
			 
			 _ShowScreenHeader(Title, SubTitle);

			 cout << "|________________|_____________|___________________|___________________|___________________|______________________|______________\n";
			 cout << "| Account Number | PinCode     | First Name        | Last Name         | Phone Number      | Email                | Balance      \n";
			 cout << "|________________|_____________|___________________|___________________|___________________|______________________|______________\n";

			 for (const clsBankClient& C : vClients)
			 {
				 _PrintClientRecordInfo(C);
			 }

			 cout << "|________________|_____________|___________________|___________________|___________________|______________________|______________\n\n";

		 }

	 }
};

