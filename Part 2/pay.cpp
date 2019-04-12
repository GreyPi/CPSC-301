#include "person.h"
#include "person.cpp"
#include <fstream>
#include <iomanip>
#include <vector>

void readData(vector<Person> &employees);
void writeData(vector<Person> &employees);

int main()
{
	string test;
	vector <Person> employees;
	//unsigned int n=0;
	readData(employees);
	writeData(employees);
	
	
	return 0;
}

void readData(vector<Person> &employees)
{
	ifstream myFile;
	myFile.open("input.txt");
	
	string FName;
	string LName;
	float PayRate;
	float HoursWorked;
	string loops;
	//int i = 0;
	
	while (myFile >> FName)
	{
			myFile >> LName;
			myFile >> PayRate;
			myFile >> HoursWorked;
			//employees[i].setHoursWorked(HoursWorked);
			employees.emplace_back(FName, LName, PayRate, HoursWorked);
			//i++;
	} 

	myFile.close();
}

void writeData(vector<Person> &employees)
{
	ofstream outFile;
	outFile.open("output.txt");
		//for (vector<Person>::iterator it = employees.begin(); it != employees.end(); ++it){cout << *it << endl;}
	for (unsigned int i = 0; i < employees.size(); i++)
	{
		outFile << employees.at(i).fullName() << " ";
		outFile << fixed << setprecision(2) << employees.at(i).totalPay() << " " << endl;
	}
		
		
	outFile.close();
}
