#include "person.h"
#include "person.cpp"
#include <fstream>
#include <iomanip>

void readData(Person employees[], int &size);
void writeData(Person employees[], int &size);

int main()
{
	string test;
	Person employees[20];
	int n=0;
	readData(employees, n);
	writeData(employees, n);
	
	
	return 0;
}

void readData(Person employees[], int &size)
{
	ifstream myFile;
	myFile.open("input.txt");
	
	string FName;
	string LName;
	float PayRate;
	float HoursWorked;
	string loops;
	int i = 0;
	
	while (!myFile.eof() && size < 20)
	{
			myFile >> FName;
			employees[i].setFirstName(FName);
			myFile >> LName;
			employees[i].setLastName(LName);
			myFile >> PayRate;
			employees[i].setPayRate(PayRate);
			myFile >> HoursWorked;
			employees[i].setHoursWorked(HoursWorked);
			i++;
			size++;
	}
	myFile.close();
}

void writeData(Person employees[], int &size)
{
	ofstream outFile;
	outFile.open("output.txt");
	
		for (int i=0; i<size; i++)
		{
			outFile << employees[i].fullName() << " ";
			outFile << fixed << setprecision(2) << employees[i].totalPay() << endl;
		}
	outFile.close();
}
