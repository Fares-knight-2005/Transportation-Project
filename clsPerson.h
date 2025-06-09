#pragma once

#include <iostream>

using namespace std;

class clsPerson
{
private:



protected:

    short Age;
	string FirstName;
	string LastName;
	string PhoneNumber;
	string Email;
	

public:

	clsPerson(short Age, string FirstName, string LastName, string PhoneNumber , string Email)
	{
		this->Age = Age;
		this->FirstName = FirstName;
		this->LastName = LastName;
		this->PhoneNumber = PhoneNumber;
		this->Email = Email;
	}


};

