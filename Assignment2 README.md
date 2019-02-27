# CPSC-301
//begin person.h
#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;
class Person
{
private:
    string lastName;
    string firstName;
    float  payRate;
    float  hoursWorked;
public:
    Person();
    void setLastName(string lName);
    string getLastName();
    void setFirstName(string fName);
    string getFirstName();
    void setPayRate(float rate);
    float getPayRate();
    void setHoursWorked(float hours);
    float getHoursWorked();
    float totalPay();
    string fullName();
};
#endif // end person.h


#include "person.h"

Person::Person(){}

void Person::setLastName(string lName)
{
	lastName = lName;
	cout << lName << " ";
}

string Person::getLastName()
{
	
	return lastName;
}

void Person::setFirstName(string fName)
{
	firstName = fName;
	cout << fName << " ";
}

string Person::getFirstName() 
{
	return firstName;
}


void Person::setPayRate(float rate)
{
	payRate = rate;
	cout << rate << " ";
}

//float Person::getPayRate()
//{
	
//}

void Person::setHoursWorked(float hours)
{
	hoursWorked = hours;
	cout << hours << endl;
}

//float Person::getHoursWorked()
//{
	
//}

//float Person::totalPay()
//{
	
//}

//string Person::fullName()
//{
	
//}



#include "person.h"
#include "person.cpp"
#include <fstream>

int main()
{
	
	Person employees[20];
	
	ifstream myFile;
	myFile.open("input.txt");
	string FName;
	string LName;
	float PayRate;
	float HoursWorked;
	string loops;
	int n;

	while (!myFile.eof())
	{
		while (getline(myFile, loops)
		{
			n++;
		}
		for (int i = 0; i < 20; i++)
		{
			myFile >> FName;
			employees[i].setFirstName(FName);
			myFile >> LName;
			employees[i].setLastName(LName);
			myFile >> PayRate;
			employees[i].setPayRate(PayRate);
			myFile >> HoursWorked;
			employees[i].setHoursWorked(HoursWorked);
			
		}
	}
	
	return 0;
}
