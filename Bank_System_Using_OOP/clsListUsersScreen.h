#pragma once

#include<iostream>
#include<iomanip>
#include<string>
#include"clsScreen.h"
#include"clsUser.h"


using namespace std;

class clsListUsersScreen : protected clsScreen
{

 private:

	 static void _PrintUserRecordInfo(const clsUser &User)
	 {

		 cout << "|" << left << setw(16) << User.UserName()
			 << "|" << left << setw(13) << User.Password()
			 << "|" << left << setw(19) << User.FirstName()
			 << "|" << left << setw(19) << User.LastName()
			 << "|" << left << setw(19) << User.PhoneNumber()
			 << "|" << left << setw(27) << User.Email()
			 << "|" << left << setw(14) << " " + to_string(User.Permission()) << endl;
	 }

 public:

	 static void Show()
	 {

		 vector <clsUser> vUsers;
		 vUsers = clsUser::GetUsersList();


		 if (vUsers.size() == 0)
		 {
			 cout << "\nThe File Is Currently Empty !!!\n";
		 }

		 else
		 {

			 string Title = "+++ List Users Screen +++";
			 string SubTitle = "+++ List Has " + to_string(vUsers.size()) + " User(s) +++";

			 _ShowScreenHeader(Title, SubTitle);

			 cout << "|________________|_____________|___________________|___________________|___________________|___________________________|______________\n";
			 cout << "| User Name      | Password    | First Name        | Last Name         | Phone Number      | Email                     | Permissions  \n";
			 cout << "|________________|_____________|___________________|___________________|___________________|___________________________|______________\n";

			 for (const clsUser& C : vUsers)
			 {
				 _PrintUserRecordInfo(C);
			 }

			 cout << "|________________|_____________|___________________|___________________|___________________|___________________________|______________\n\n";

		 }

	 }
};

