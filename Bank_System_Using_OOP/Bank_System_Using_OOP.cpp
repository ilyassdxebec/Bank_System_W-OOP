#include <iostream>
#include"clsBankClient.h"

using namespace std;

int main()
{

	clsBankClient Client = clsBankClient::Find("A111");

	Client.Print();

}
