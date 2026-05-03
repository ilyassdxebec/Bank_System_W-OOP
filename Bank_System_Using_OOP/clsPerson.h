#pragma once

#include<iostream>


class clsPerson
{
 
 private:

	 string _FirstName;
	 string _LastName;
	 string _PhoneNumber;
	 string _Email;

 public:

	 clsPerson(const string &FirstName ,const string &LastName ,const string &PhoneNumber ,const string &Email)
	 {
		 _FirstName = FirstName;
		 _LastName = LastName;
		 _PhoneNumber = PhoneNumber;
		 _Email = Email;
	 }

	 string FirstName()
	 {
		 return _FirstName;
	 }

	 void SetFirstName(const string &FirstName)
	 {
		 _FirstName = FirstName;
	 }

	 string LastName()
	 {
		 return _LastName;
	 }

	 void SetLastName(const string& LastName)
	 {
		 _LastName = LastName;
	 }

	 string PhoneNumber()
	 {
		 return _PhoneNumber;
	 }

	 void SetPhoneNumber(const string& PhoneNumber)
	 {
		 _PhoneNumber = PhoneNumber;
	 }

	 string Email()
	 {
		 return _Email;
	 }

	 void SetEmail(const string& Email)
	 {
		 _Email = Email;
	 }
};

