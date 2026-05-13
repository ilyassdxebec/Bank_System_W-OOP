#pragma once

#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsUtil.h"
#include<iomanip>

using namespace std;

class clsTotalBalancesScreen : protected clsScreen
{
 
 private:

	 static void _PrintClientRecordBalanceLine(const clsBankClient& Client)
	 {

		 cout << "|" << left << setw(16) << Client.AccNumber()
			 << "|" << left << setw(25) << Client.FullName()
			 << "|" << left << setw(16) << Client.AccBalance() << endl;

	 }


 public:

	 static void Show()
	 {

		 vector <clsBankClient> vClients;
		 vClients = clsBankClient::GetClientsList();

		 if (vClients.size() == 0)
		 {
			 cout << "\nThe File Is Currently Empty !!!\n";
		 }

		 else
		 {

			 string Title = "+++ Total Balances Screen +++";
			 string SubTitle = "+++ List Has " + to_string(vClients.size()) + " Client(s) +++";

			 _ShowScreenHeader(Title,SubTitle);


			 cout << "|________________|_________________________|________________\n";
			 cout << "| Account Number | Full Name               | Balance        \n";
			 cout << "|________________|_________________________|________________\n";

			 for (clsBankClient& C : vClients)
			 {
				 _PrintClientRecordBalanceLine(C);
			 }

			 cout << "|________________|_________________________|________________\n\n";


			 double TotalBalances = clsBankClient::GetTotalBalances();

			 cout << "+++++ Total Balances : ( " << TotalBalances << " ) +++++\n\n";

			 cout << "Total Balances in words is --> " << clsUtil::NumberToString(TotalBalances) << endl;
		 }

	 }
};

