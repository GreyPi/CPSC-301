
#include "person.cpp"
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

void readData(vector<Person> &employees); 
void getCompanies(vector<Person> &employees, vector<string> &companyNames);
void printHighestPaid(vector<Person> &employees);
void separateAndSave(vector<Person> &employees, vector<string> &companyNames);

int main()
{
	vector<Person> employees;
	vector<string> companyNames;
	
	readData(employees);
	getCompanies(employees, companyNames);
	printHighestPaid(employees);
	separateAndSave(employees, companyNames);
	
	return 0;
}

void readData(vector<Person> &employees)
{
	Person temp;
	ifstream inData;
	inData.open("input.txt");
	string fName, lName, coName;
	int id;
	float rate, hours;
	while (!inData.eof())
	{
		inData >> fName;
		inData >> lName;
		inData >> id;
		inData >> coName;
		inData >> rate;
		inData >> hours;
		
		temp.setFirstName(fName);
		temp.setLastName(lName);
		temp.setEmployeeId(id);
		temp.setCompanyName(coName);
		temp.setPayRate(rate);
		temp.setHoursWorked(hours);
		
		employees.push_back(temp);
	}
	
}

void getCompanies(vector<Person> &employees, vector<string> &companyNames)
{
	string fName;
	for (unsigned int i = 0; i < employees.size(); i++)
	{
	fName = employees[i].getCompanyName();
	companyNames.push_back(fName);
	
	}
}

void printHighestPaid(vector<Person> &employees)
{
	float highest = 0;
	string fuName;
	int id;
	string company;
	
	for(int i=0; i<20; i++)
	{
	if(highest < employees[i].totalPay())
		{
			highest = employees[i].totalPay();
			fuName = employees[i].fullName();
			id = employees[i].getEmployeeId();
			company = employees[i].getCompanyName();
		}
	}
	cout << "Highest paid: " << fuName << endl;
	cout << "Employee ID: " << id << endl;
	cout << "Employer: " << company << endl;
	cout << "Total Pay: $" << fixed << setprecision(2) << highest << endl;
}

void separateAndSave(vector<Person> &employees, vector<string> &companyNames)
{
	float total = 0;
	ofstream outData;
	outData.open("Intel.txt");
	for (unsigned int i = 0; i < employees.size(); i++)
	{
	if ("Intel" == companyNames[i])
		{
			outData << employees[i].fullName() << "\t"
			<< employees[i].getEmployeeId() << "\t" 
			<< companyNames[i] << "\t$" << fixed << setprecision(2) << employees[i].totalPay() << endl;
			total += employees[i].totalPay();
		}
	}
	outData << "Total $" << total;
	outData.close();
	total = 0;
	
	outData.open("Boeing.txt");
	for (unsigned int i = 0; i < employees.size(); i++)
	{
	if ("Boeing" == companyNames[i])
		{
			outData << employees[i].fullName() << "\t"
			<< employees[i].getEmployeeId() << "\t" 
			<< companyNames[i] << "\t$" << fixed << setprecision(2) << employees[i].totalPay() << endl;
			total += employees[i].totalPay();
		}
	}
	outData << "Total $" << total;
	outData.close();
	total = 0;
	
	outData.open("Douglas.txt");
	for (unsigned int i = 0; i < employees.size(); i++)
	{
	if ("Douglas" == companyNames[i])
		{
			outData << employees[i].fullName() << "\t"
			<< employees[i].getEmployeeId() << "\t" 
			<< companyNames[i] << "\t$" << fixed << setprecision(2) << employees[i].totalPay() << endl;
			total += employees[i].totalPay();
		}
	}
	outData << "Total $" << total;
	outData.close();
	total = 0;
	
	outData.open("Raytheon");
	for (unsigned int i = 0; i < employees.size(); i++)
	{
	if ("Raytheon" == companyNames[i])
		{
			outData << employees[i].fullName() << "\t"
			<< employees[i].getEmployeeId() << "\t" 
			<< companyNames[i] << "\t$" << fixed << setprecision(2) << employees[i].totalPay() << endl;
			total += employees[i].totalPay();
		}
	}
	outData << "Total $" << total;
	outData.close();
	total = 0;
	
	outData.open("HealthTech.txt");
	for (unsigned int i = 0; i < employees.size(); i++)
	{
	if ("HealthTech" == companyNames[i])
		{
			outData << employees[i].fullName() << "\t"
			<< employees[i].getEmployeeId() << "\t" 
			<< companyNames[i] << "\t$" << fixed << setprecision(2) << employees[i].totalPay() << endl;
			total += employees[i].totalPay();
		}
	}
	outData << "Total $" << total;
	outData.close();
	total = 0;
}

