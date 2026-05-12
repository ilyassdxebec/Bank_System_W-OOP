#include <iostream>

#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsMainScreen.h"
#include"clsUtil.h"

using namespace std;

//
//
//
//void PrintClientRecordBalanceLine(const clsBankClient &Client)
//{
//
//   cout << "|" << left << setw(16) << Client.AccNumber()
//		<< "|" << left << setw(25) << Client.FullName()
//		<< "|" << left << setw(16) << Client.AccBalance() << endl;
//
//}
//
//void ListTotalBalances()
//{
//  
//	vector <clsBankClient> vClients;
//	vClients = clsBankClient::GetClientsList();
//
//	if (vClients.size() == 0)
//	{
//		cout << "\nThe File Is Currently Empty !!!\n";
//	}
//
//	else
//	{
//		cout << "\n++++++++++++Balances List has (" << vClients.size() << ") Client(s)++++++++++++\n\n";
//
//		cout << "|________________|_________________________|________________\n";
//		cout << "| Account Number | Full Name               | Balance        \n";
//		cout << "|________________|_________________________|________________\n";
//
//		for (clsBankClient &C : vClients)
//		{
//			PrintClientRecordBalanceLine(C);
//		}
//
//		cout << "|________________|_________________________|________________\n\n";
//
//
//		double TotalBalances = clsBankClient::GetTotalBalances();
//
//		cout << "+++++ Total Balances : ( " << TotalBalances << " ) +++++\n\n";
//
//		cout << "Total Balances in words is --> " << clsUtil::NumberToString(TotalBalances) << endl;
//	}
//
//}

int main()
{
	clsMainScreen::ShowMainMenu();
}
