#pragma once

#include<iostream>

using namespace std;

class clsInterfaceCommunication
{
 
 public:

	 virtual void SendEmail(const string& Title, const string& Body) = 0;
	 virtual void SendFax(const string& Title, const string& Body) = 0;
	 virtual void SendSMS(const string& Title, const string& Body) = 0;

};

