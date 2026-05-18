#pragma once

#include<iostream>

#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"

using namespace std;

class clsTransferScreen : protected clsScreen
{

 private:

	 static void _PrintClientCard(const clsBankClient &Client)
	 {

		 cout << "\n+++ Client Card +++\n";

		 cout << "______________\n";
		 cout << "Full Name : " << Client.FullName() << endl;
		 cout << "Acc Number : " << Client.AccNumber() << endl;
		 cout << "Balance : " << Client.AccBalance() << endl;
		 cout << "______________\n\n";

	 }

	 static char _ConfirmTransfer()
	 {

		 char Choice;

		 cout << "\nAre you sure you want to transfer this amount ? (y/n) : ";
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

		 string SenderAccNum, ReceiverAccNum;

		 float TransferAmount;

		 char Choice;

		 _ShowScreenHeader("+++ Transfer Screen +++");

		 cout << "Please Enter Account Number to Transfer From : ";
		 SenderAccNum = clsInputValidate::ReadString();

		 while (!clsBankClient::IsClientExist(SenderAccNum))
		 {
			 cout << "\nClient Doesn't Exist! ,Try Again : ";
			 SenderAccNum = clsInputValidate::ReadString();
		 }

		 clsBankClient Sender = clsBankClient::Find(SenderAccNum);
		 _PrintClientCard(Sender);

		 cout << "\nPlease Enter Account Number to Transfer To : ";
		 ReceiverAccNum = clsInputValidate::ReadString();

		 while (!clsBankClient::IsClientExist(ReceiverAccNum))
		 {
			 cout << "\nClient Doesn't Exist! ,Try Again : ";
			 SenderAccNum = clsInputValidate::ReadString();
		 }

		 clsBankClient Receiver = clsBankClient::Find(ReceiverAccNum);
		 _PrintClientCard(Receiver);

		 cout << "\nPlease Enter Transfer Amount : ";
		 TransferAmount = clsInputValidate::ReadFloatNumber();

		 while (TransferAmount > Sender.AccBalance())
		 {
			 cout << "\nAmount Exceeds The Available Balance, Enter another amount : ";
			 TransferAmount = clsInputValidate::ReadFloatNumber();
		 }

		 Choice = _ConfirmTransfer();


		 if (toupper(Choice) == 'Y')
		 {

			 Sender.WithDraw(TransferAmount);
			 Receiver.Deposit(TransferAmount);

			 cout << "\nTransfer Done Succeffully !!!";

			 _PrintClientCard(Sender);
			 _PrintClientCard(Receiver);
		 }

		 else
		 {
			 cout << "\nTransfer Wasn't Performed as you wanted !!!";
		 }
	 }
};

