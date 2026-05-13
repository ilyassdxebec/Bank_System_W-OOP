#pragma once

#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"

using namespace std;

class clsWithDrawScreen : protected clsScreen
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

     static void _ReadWithDrawAmount(float& Amount ,const clsBankClient &Client)
     {

         cout << "\nPlease Enter WithDraw Amount : ";
         Amount = clsInputValidate::ReadFloatNumber();

         while (Amount > Client.AccBalance() || Amount < 0)
         {
           
             if (Amount > Client.AccBalance())
             {
                 cout << "\nWithDraw Amount Exceeds Current Balance! , please try again : ";
                 Amount = clsInputValidate::ReadFloatNumber();
             }

             else
             {
                 cout << "\nYou Can't WithDraw Negative Amount! Try again : ";
                 Amount = clsInputValidate::ReadFloatNumber();
             }
         }

     }

     static char _ConfirmWithDraw()
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

         _ShowScreenHeader("+++ WithDraw Screen +++");


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

         _ReadWithDrawAmount(Amount ,Client);

         Choice = _ConfirmWithDraw();
        

         if (toupper(Choice) == 'Y')
         {

             if (Client.WithDraw(Amount))
             {

                 cout << "\nAmount WithDrawed Successfully !";

                 cout << "\nNew Amount is : " << Client.AccBalance();

             }

             else
             {
                 cout << "\nCan't Performe this Withdraw!";
             }
         }

         else
         {
             cout << "\nWithDrawing Was Cancelled as you wanted!";
         }
     }
	 
};

