#pragma once

#include<iostream>
#include"clsScreen.h"

using namespace std;

class clsLoginRegisterScreen : protected clsScreen
{

 private:

	 static void _PrintLoginRegisterRecordInfo(const clsUser::stLogin &User)
	 {

		 cout << "|" << left << setw(21) << User.Date
			 << "|" << left << setw(16) << User.UserName
			 << "|" << left << setw(15) << User.Password
			 << "|" << left << setw(13) << " " + to_string(User.Permission) << endl;
	 }

 public:

	 static void Show()
	 {

		 if (!_ShowIsFeatureAvailable(clsUser::enMainMenuPermissions::pLoginRegister))
			 return;


		 vector <clsUser::stLogin> vLogins;
		 vLogins = clsUser::GetLoginRegisterList();


		 if (vLogins.size() == 0)
		 {
			 cout << "\nThe File Is Currently Empty !!!\n";
		 }

		 else
		 {

			 string Title = "+++ Login Register Screen +++";
			 string SubTitle = "+++ List Has " + to_string(vLogins.size()) + " User(s) +++";

			 _ShowScreenHeader(Title, SubTitle);

			 cout << "|_____________________|________________|_______________|_____________ \n";
			 cout << "| Date                | User Name      | Password      | Permissions  \n";
			 cout << "|_____________________|________________|_______________|_____________ \n";

			 for (const clsUser::stLogin &C : vLogins)
			 {
				 _PrintLoginRegisterRecordInfo(C);
			 }

			 cout << "|_____________________|________________|_______________|_____________\n\n";

		 }


	 }
};

