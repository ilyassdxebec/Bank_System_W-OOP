#pragma once

#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsUser.h"

using namespace std;

class clsAddNewUserScreen : protected clsScreen
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

		 return Permission;

	 }

	 static void _ReadUserData(clsUser &User)
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

	 static void _PrintUser(const clsUser &User)
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


		 _ShowScreenHeader("+++ Add New User Screen +++");

		 string UserName;

		 cout << "Please Enter A New UserName : ";
		 UserName = clsInputValidate::ReadString();

		 while (clsUser::IsUserExist(UserName))
		 {
			 cout << "\nUser Name Already Exist! Please Try Again : ";
			 UserName = clsInputValidate::ReadString();
		 }

		 clsUser User = clsUser::GetAddNewUserObject(UserName);


		 cout << "\n+++++ Adding New User +++++\n";

		 _ReadUserData(User);

		 clsUser::enSavingResults SavingResult;
		 SavingResult = User.Save();


		 switch (SavingResult)
		 {

		 case clsUser::enSavingResults::svFailedEmptyObject:

			 cout << "\nCouldn't Update User's Data Failed Because Of Empty Object!\n";
			 break;

		 case clsUser::enSavingResults::svAddSuccedded:

			 cout << "\nUser's Info Added Successfully !!!\n";
			 _PrintUser(User);
			 break;

		 case clsUser::enSavingResults::svFailedUserNameExists:

			 cout << "\nUser Already Exists!\n";
			 break;

		 default:
			 break;

		 }

	 }
};

