#pragma once

#include <iostream>
#include "clsPerson.h"


using namespace std;

class clsBusDriver : clsPerson
{

public:

    enum enDriverMode {Working = 1 , TakingRest = 2 , OutOfWork = 3};

private:

   

	// clsBus BusToDrive
	int Salary;
	enDriverMode Mode;

public:

 enDriverMode GetMode()
 {
	 return Mode;
 }

 void setMode(enDriverMode Mode)
 {
	 this->Mode = Mode;
 }

 int GetSalary()
 {
	 return Salary;
 }

 void SetSalary(int Salary)
 {
	 this->Salary = Salary;
 }


};