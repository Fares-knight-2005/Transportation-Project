#pragma once

#include <iostream>

using namespace std;

class clsPerson
{
private:



protected:


	int Id;
	short Age;
	string FirstName;
	string LastName;
	string PhoneNumber;
	string Email;

public:

	clsPerson(int ID, short Age, string FirstName, string LastName, string PhoneNumber, string Eamil)
	{
		this->Id = ID;
		this->Age = Age;
		this->FirstName = FirstName;
		this->LastName = LastName;
		this->PhoneNumber = PhoneNumber;
		this->Email = Email;
	}


	clsPerson(short Age, string FirstName, string LastName, string PhoneNumber, string Eamil)
	{
		this->Age = Age;
		this->FirstName = FirstName;
		this->LastName = LastName;
		this->PhoneNumber = PhoneNumber;
		this->Email = Email;
	}

	string GetFirstName()
	{
		return FirstName;
	}

	void SetFirstName(string FirstName)
	{
		this->FirstName = FirstName;
	}

	string GetLastName()
	{
		return this->LastName;
	}

	void SetLastName(string LastName)
	{
		this->LastName = LastName;
	}

	short GetAge()
	{
		return this->Age;
	}

	void SetAge(short Age)
	{
		this->Age = Age;
	}

	string GetPhoneNumber()
	{
		return this->PhoneNumber;
	}

	void SetPhoneNumber(string PhoneNumber)
	{
		this->PhoneNumber = PhoneNumber;
	}

	string GetEmail()
	{
		return this->Email;
	}

	void SetEmail(string Eamil)
	{
		this->Email = Email;
	}

};
