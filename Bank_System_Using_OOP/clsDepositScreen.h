#pragma once

#include<iostream>
#include"clsInputValidate.h"
#include"clsBankClient.h"
#include"clsScreen.h"

class clsDepositScreen : protected clsScreen
{
 
 private:

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

     static void _ReadDepositAmount(float &Amount)
     {

         cout << "\nPlease Enter Deposit Amount : ";
         Amount = clsInputValidate::ReadFloatNumber();

         while (Amount < 0)
         {
             cout << "\nYou can't deposit negative number! , please try again : ";
             Amount = clsInputValidate::ReadFloatNumber();
         }

     }

     static char _ConfirmDeposit()
     {

         char Choice;

         cout << "\nAre you sure you want to performe this transaction (y/n) ?";
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

         system("cls");
         
         _ShowScreenHeader("+++ Deposit Screen +++");


         string AccNumber;
         float  Amount;
         char Choice;

         cout << "\nPlease enter Client's Account Number : ";
         AccNumber = clsInputValidate::ReadString();

         while (!clsBankClient::IsClientExist(AccNumber))
         {
             cout << "\nClient With Account Number Doesn't Exist! Please Try Again : ";
             AccNumber = clsInputValidate::ReadString();
         }

         clsBankClient Client = clsBankClient::Find(AccNumber);
         _PrintClient(Client);

         _ReadDepositAmount(Amount);

         Choice = _ConfirmDeposit();


         if (toupper(Choice) == 'Y')
         {

            if (Client.Deposit(Amount))
            {

                cout << "\nAmount Deposited Successfully !";

                cout << "\nNew Amount is : " << Client.AccBalance();

            }
            
            else
            {
                cout << "\nYou can't Deposit Amount less than 0!";
            }
         }

         else
         {
             cout << "\nDepositing Was Cancelled as you wanted!";
         }
     }
};

