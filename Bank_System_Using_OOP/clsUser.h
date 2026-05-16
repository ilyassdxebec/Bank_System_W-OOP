#pragma once

#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include"clsString.h"
#include"clsPerson.h"

using namespace std;

class clsUser : public clsPerson
{
 
 private:

	 enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };

	 string _UserName;
	 string _Password;
	 enMode _Mode;
	 short _Permission;
	 bool _MarkForDelete = false;


	 static clsUser _ConvertLineToUserObject(const string& Line, string delim = "#//#")
	 {

		 vector <string> vWords;
		 vWords = clsString::Split(Line, delim);

		 return clsUser(enMode::UpdateMode, vWords.at(0), vWords.at(1), vWords.at(2), vWords.at(3), vWords.at(4), vWords.at(5), (short)stoi(vWords.at(6)));
	 }

	 static vector <clsUser> _LoadUsersDataFromFile(const string& FileName)
	 {
		 fstream MyFile;
		 vector <clsUser> vUsers;

		 MyFile.open(FileName, ios::in);

		 if (MyFile.is_open())
		 {
			 string Line;

			 while (getline(MyFile, Line))
			 {
				 vUsers.push_back(_ConvertLineToUserObject(Line));
			 }

			 MyFile.close();
		 }

		 return vUsers;
	 }

	 static string _ConvertUserObjectToLine(clsUser &User, string delim = "#//#")
	 {

		 string Line = "";

		 Line += User.FirstName() + delim;
		 Line += User.LastName() + delim;
		 Line += User.PhoneNumber() + delim;
		 Line += User.Email() + delim;
		 Line += User.UserName() + delim;
		 Line += User.Password() + delim;
		 Line += to_string(User.Permission());

		 return Line;
	 }


	 static void _SaveUsersObjectToFile(const string& FileName, vector <clsUser> &vUsers)
	 {

		 fstream MyFile;

		 MyFile.open(FileName, ios::out);

		 if (MyFile.is_open())
		 {
			 for (clsUser &C : vUsers)
			 {
				 if (C._MarkForDelete != true)
				 {
					 MyFile << _ConvertUserObjectToLine(C) << endl;
				 }
			 }

			 MyFile.close();
		 }
	 }

	 static clsUser _GetEmptyUserObject()
	 {
		 return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	 }

	 void _Update()
	 {

		 vector <clsUser> vUsers;
		 vUsers = _LoadUsersDataFromFile("Users.txt");

		 for (clsUser &C : vUsers)
		 {
			 if (C.UserName() == UserName())
			 {
				 C = *this;
				 break;
			 }
		 }

		 _SaveUsersObjectToFile("Users.txt", vUsers);
	 }

	 void _AddNew()
	 {
		 _AddLineToFile(_ConvertUserObjectToLine(*this), "Users.txt");
	 }

	 static void _AddLineToFile(const string& Line, const string& FileName)
	 {
		 fstream MyFile;

		 MyFile.open(FileName, ios::app);

		 if (MyFile.is_open())
		 {
			 MyFile << Line << endl;
		 }

		 MyFile.close();
	 }


 public:

	 enum enMainMenuPermissions {
		 pAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
		 pUpdateClient = 8, pFindClient = 16, pTransactions = 32, pManageUsers = 64
	 };

	 clsUser(const enMode &Mode ,const string &FirstName ,const string &LastName ,const string &PhoneNumber ,const string &Email ,const string &UserName ,
		     const string &Password ,const short &Permission)
		 : clsPerson(FirstName ,LastName ,PhoneNumber ,Email)
	 {
		 _Mode = Mode;
		 _UserName = UserName;
		 _Password = Password;
		 _Permission = Permission;
	 }

	 string UserName() const
	 {
		 return _UserName;
	 }

	 void SetUserName(const string &UserName)
	 {
		 _UserName = UserName;
	 }

	 string Password() const 
	 {
		 return _Password;
	 }

	 void SetPassword(const string & Password)
	 {
		 _Password = Password;
	 }

	 short Permission() const
	 {
		 return _Permission;
	 }

	 void SetPermission(const short &Permission)
	 {
		 _Permission = Permission;
	 }

	 static clsUser Find(const string& UserName)
	 {

		 fstream MyFile;
		 vector <clsUser> vUsers;

		 MyFile.open("Users.txt", ios::in);

		 if (MyFile.is_open())
		 {
			 string Line;

			 while (getline(MyFile, Line))
			 {
				 clsUser User = _ConvertLineToUserObject(Line);

				 if (User.UserName() == UserName)
				 {
					 MyFile.close();
					 return User;
				 }
			 }

			 MyFile.close();
		 }

		 return _GetEmptyUserObject();
	 }

	 static clsUser Find(const string& UserName, const string& Password)
	 {

		 fstream MyFile;
		 vector <clsUser> Users;

		 MyFile.open("Users.txt", ios::in);

		 if (MyFile.is_open())
		 {
			 string Line;

			 while (getline(MyFile, Line))
			 {
				 clsUser User = _ConvertLineToUserObject(Line);

				 if (User.UserName() == UserName && User.Password() == Password)
				 {
					 MyFile.close();
					 return User;
				 }
			 }

			 MyFile.close();
		 }

		 return _GetEmptyUserObject();
	 }

	 bool IsEmpty()
	 {
		 return (_Mode == EmptyMode);
	 }

	 static bool IsUserExist(const string& UserName)
	 {

		 clsUser User = clsUser::Find(UserName);

		 return (!User.IsEmpty());
	 }

	 static clsUser GetAddNewUserObject(const string& UserName)
	 {

		 return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
	 }

	 static vector <clsUser> GetUsersList()
	 {
		 return _LoadUsersDataFromFile("Users.txt");
	 }

	 bool IsMarkedForDelete() const
	 {
		 return _MarkForDelete;
	 }

	 bool Delete()
	 {

		 vector <clsUser> vUsers;
		 vUsers = _LoadUsersDataFromFile("Users.txt");


		 for (clsUser &C : vUsers)
		 {
			 if (C.UserName() == UserName())
			 {

				 C._MarkForDelete = true;

				 _SaveUsersObjectToFile("Users.txt", vUsers);

				 *this = _GetEmptyUserObject();

				 return true;

			 }
		 }

		 return false;
	 }

	 enum enSavingResults { svFailedEmptyObject = 0, svUpdateSuccedded = 1, svAddSuccedded = 2, svFailedUserNameExists = 3 };


	 enSavingResults Save()
	 {

		 switch (_Mode)
		 {

		 case EmptyMode:

			 return svFailedEmptyObject;


		 case UpdateMode:

			 _Update();
			 return svUpdateSuccedded;


		 case AddNewMode:


			 if (IsUserExist(_UserName))
			 {
				 return svFailedUserNameExists;
			 }

			 else
			 {
				 _AddNew();
				 _Mode = UpdateMode;
				 return svAddSuccedded;

			 }
		 }
	 }
};

