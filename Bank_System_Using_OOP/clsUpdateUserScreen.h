#pragma once

#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include"clsInputValidate.h"

using namespace std;

class clsUpdateUserScreen : protected clsScreen
{

 private:

	 static short _GiveUserPermissionOverClientList()
	 {

		 char Choice;
		 short Permission = 0;

		 cout << "\nDo you want to give full access : (y/n) ?";
		 cin >> Choice;

		 if (toupper(Choice) == 'Y')
			 return clsUser::pAll;

		 cout << "\nDo you want to give access to : \n\n";

		 cout << "Show Client List :  (y/n) ?";
		 cin >> Choice;
		 if (toupper(Choice) == 'Y') Permission = (clsUser::pListClients | Permission);

		 cout << "Add new CLient List : (y/n) ?";
		 cin >> Choice;
		 if (toupper(Choice) == 'Y') Permission = (clsUser::pAddNewClient | Permission);

		 cout << "Delete CLient List : (y/n) ?";
		 cin >> Choice;
		 if (toupper(Choice) == 'Y') Permission = (clsUser::pDeleteClient | Permission);

		 cout << "Update CLient List : (y/n) ?";
		 cin >> Choice;
		 if (toupper(Choice) == 'Y') Permission = (clsUser::pUpdateClient | Permission);

		 cout << "Find CLient List : (y/n) ?";
		 cin >> Choice;
		 if (toupper(Choice) == 'Y') Permission = (clsUser::pFindClient | Permission);

		 cout << "Transactions : (y/n) ?";
		 cin >> Choice;
		 if (toupper(Choice) == 'Y') Permission = (clsUser::pTransactions | Permission);

		 cout << "Manage Users : (y/n) ?";
		 cin >> Choice;
		 if (toupper(Choice) == 'Y') Permission = (clsUser::pManageUsers | Permission);

		 cout << "Show Login Register : (y/n) ?";
		 cin >> Choice;
		 if (toupper(Choice) == 'Y') Permission = (clsUser::pLoginRegister | Permission);

		 return Permission;

	 }

	 static void _ReadUserData(clsUser& User)
	 {

		 cout << "\nEnter User's First Name : ";
		 User.SetFirstName(clsInputValidate::ReadString());

		 cout << "\nEnter User's Last Name : ";
		 User.SetLastName(clsInputValidate::ReadString());

		 cout << "\nEnter User's Phone Number : ";
		 User.SetPhoneNumber(clsInputValidate::ReadString());

		 cout << "\nEnter User's Email : ";
		 User.SetEmail(clsInputValidate::ReadString());

		 cout << "\nEnter User's Password : ";
		 User.SetPassword(clsInputValidate::ReadString());

		 User.SetPermission(_GiveUserPermissionOverClientList());
	 }

	 static char _ConfirmUpdate()
	 {

		 char Choice;

		 cout << "\nAre you sure you want to Update this User? (y/n) : ";
		 cin >> Choice;

		 while (toupper(Choice) != 'Y' && toupper(Choice) != 'N')
		 {
			 cout << "\nInvalid Choice! Enter a vaild choice (y/n) : ";
			 cin >> Choice;
		 }

		 return Choice;
	 }


	 static void _PrintUser(const clsUser& User)
	 {

		 cout << "\n\n++++++ User's Informations ++++++\n\n";

		 cout << "___________________________________\n";
		 cout << "First Name   : " << User.FirstName() << endl;
		 cout << "Last Name    : " << User.LastName() << endl;
		 cout << "Phone Number : " << User.PhoneNumber() << endl;
		 cout << "Email Adress : " << User.Email() << endl;
		 cout << "User Name    : " << User.UserName() << endl;
		 cout << "Password     : " << User.Password() << endl;
		 cout << "Permission   : " << User.Permission() << endl;
		 cout << "___________________________________\n\n";

	 }


 public:

	 static void Show()
	 {

		 _ShowScreenHeader("+++ Update User Screen +++");

		 string UserName;
		 char Choice;

		 cout << "Please Enter User Name : ";
		 UserName = clsInputValidate::ReadString();

		 while (!clsUser::IsUserExist(UserName))
		 {
			 cout << "\nUser Doesn't Exist! Please Try Again : ";
			 UserName = clsInputValidate::ReadString();
		 }

		 clsUser User = clsUser::Find(UserName);
		 _PrintUser(User);

		 Choice = _ConfirmUpdate();

		 if (toupper(Choice) == 'Y')
		 {
			 cout << "\n+++++ Update User's Info +++++\n";

			 _ReadUserData(User);

			 clsUser::enSavingResults SavingResult;
			 SavingResult = User.Save();


			 switch (SavingResult)
			 {

			 case clsUser::enSavingResults::svFailedEmptyObject:

				 cout << "\nCouldn't Update User's Data Failed Because Of Empty Object!\n";
				 break;


			 case clsUser::enSavingResults::svUpdateSuccedded:

				 cout << "\nUser's Info Updated Successfully !!!\n";
				 _PrintUser(User);
				 break;


			 default:
				 break;
			 }
		 }

		 else
		 {
			 cout << "\nUser Wasn't Updated as you wanted !!!";
		 }
	 }
};

