#include "person.h"

Person::Person(){}

void Person::setLastName(string lName)
{
	lastName = lName;
	//cout << lName << " ";
}

string Person::getLastName()
{
	
	return lastName;
}

void Person::setFirstName(string fName)
{
	firstName = fName;
	//cout << fName << " ";
}

string Person::getFirstName() 
{
	return firstName;
}


void Person::setPayRate(float rate)
{
	payRate = rate;
	//cout << rate << " ";
}

float Person::getPayRate()
{
	return payRate;
}

void Person::setHoursWorked(float hours)
{
	hoursWorked = hours;
	//cout << hours << endl;
}

float Person::getHoursWorked()
{
	return hoursWorked;
}

float Person::totalPay()
{
	return payRate * hoursWorked;
	
}

string Person::fullName()
{

	return firstName + " " + lastName;
}

