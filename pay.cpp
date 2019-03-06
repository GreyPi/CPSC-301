
#include "person.cpp"
#include "person.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void readData(vector<Person> &employees); 

int main()
{
	vector<Person> employees;
	vector<string> companyNames;
	
	
	return 0;
}

void readData(vector<Person> &employees)
{
	ifstream inData;
	inData.open("input.txt");
	string fName;
	string lName;
	int id;
	string coName;
	float rate;
	float hours;
	while (!inData.eof())
	{
		inData >> fName;
		inData >> lName;
		inData >> id;
		inData >> coName;
		inData >> rate;
		inData >> hours;
		employees.setFirstName(fName);
		employees.setLastName(lName);
		employees.setEmployeeId(id);
		employees.setCompanyName(coName);
		employees.setPayRate(rate);
		employees.setHoursWorked(hours);
	}
}



