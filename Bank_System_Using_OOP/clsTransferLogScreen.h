#pragma once

#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include<iomanip>

using namespace std;

class clsTransferLogScreen : protected clsScreen
{
 
 private:

	 static void _PrintTransferLogRecordInfo(const clsBankClient::stTransferLog &Log)
	 {

		 cout << "|" << left << setw(25) << Log.Date
			 << "|" << left << setw(13) << Log.SenderAccNum
			 << "|" << left << setw(16) << Log.ReceiverAccNum
			 << "|" << left << setw(15) << Log.TransferAmount
			 << "|" << left << setw(19) << Log.SenderAccBalance
			 << "|" << left << setw(13) << Log.ReceiverAccBalance
			 << "|" << left << setw(11) << Log.CurrentUserName << endl;
	 }

 public:
  
	 static void Show()
	 {

		 vector <clsBankClient::stTransferLog> vLogs;
		 vLogs = clsBankClient::GetTransferLogsList();


		 if (vLogs.size() == 0)
		 {
			 cout << "\nThe File Is Currently Empty !!!\n";
		 }

		 else
		 {

			 string Title = "+++ Transfer Logs Screen +++";
			 string SubTitle = "+++ List Has " + to_string(vLogs.size()) + " Log(s) +++";

			 _ShowScreenHeader(Title, SubTitle);

			 //s stands for source and d stands for direction

			 cout << "|_________________________|_____________|________________|_______________|___________________|_____________|___________\n";
			 cout << "| Date                    | s.AccNum    | d.AccNum       | Amount        | s.Balance         | d.Balance   | Log      \n";
			 cout << "|_________________________|_____________|________________|_______________|___________________|_____________|____________\n";

			 for (const clsBankClient::stTransferLog &C : vLogs)
			 {
				 _PrintTransferLogRecordInfo(C);
			 }

			 cout << "|_________________________|_____________|________________|_______________|___________________|_____________|____________\n\n";

		 }


	 }
};

