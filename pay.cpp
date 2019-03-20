
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
	for (unsigned int i = 0; i < employees.size(); i++) // check company names, then check employee
	{
		outData.open(companyNames[i] + ".txt");
		
		for (unsigned int k =0; k < employees.size(); k++)
		{
		if (companyNames[i] == employees[k].getCompanyName())
		{
			outData << employees[k].fullName() << "\t"
			<< employees[k].getEmployeeId() << "\t" 
			<< companyNames[k] << "\t$" << fixed << setprecision(2) << employees[k].totalPay() << endl;
			total += employees[k].totalPay();
		}
		}
		outData << "Total $" << fixed << setprecision(2) << total;
		total = 0;
		outData.close();
	}
	
	/**/
}
