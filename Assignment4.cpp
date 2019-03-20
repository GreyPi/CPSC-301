#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
using namespace std;

struct  PERSON 
{
    char  Name[20];
    float Balance; 
};

void Display(PERSON DisplayStruct[], int n);
void FindRichest(PERSON FindStruct[], int n);
void Deposit(char CustName[], PERSON DepositStruct[], int n);
void readData(PERSON *&RD);

int main()
{
	PERSON * readData(int & N);
	
	cout << * readData.Name << endl;
	//Display(P, N);
	//FindRichest(P, N);
	//Deposit(customer, P, N);
			
	return 0;
}

void readData(PERSON *&RD, int n)
{
	ifstream inData;
	inData.open("data.txt");
	char first[20];
	char last[20];
	
	int N = 0;
	string numRecords;
	while (getline(inData, numRecords))
	{
		N++;
	}
	inData.close();
	
	inData.open("data.txt");
		while(!inData.eof())
		{
			for (int i =0; i < n; i++)
				{
					inData >>  RD[i].Name;
					strcpy(first, RD[i].Name);
					inData >> RD[i].Name;
					strcpy(last, RD[i].Name);
					strcpy(RD[i].Name, first);
					strcat(RD[i].Name, " ");
					strcat(RD[i].Name, last);
					inData >> RD[i].Balance;
				}
		}
	
}

void Display(PERSON DisplayStruct[], int n)
{
	cout << "\tName \t Balance" << endl;
	cout << "---------------------------" << endl;
	for (int i=0; i<n; i++)
	{
		cout << "\t" << DisplayStruct[i].Name << " " << setprecision (2) << fixed << DisplayStruct[i].Balance << endl;
	}
	
}

void FindRichest(PERSON FindStruct[], int n)
{
	int high = 0;
	char winner[20];
	for (int i=0; i<n; i++)
		{
			if (FindStruct[i].Balance > high)
			{
				high = FindStruct[i].Balance;
				strcpy(winner, FindStruct[i].Name);
			}
		}
	cout << "\nThe customer with maximum balance is " << winner << "." << endl;
	cout << endl << endl;
}

void Deposit(char CustName[], PERSON DepositStruct[], int n)
{
	float value = 0;
	float total = 0;
	string recs;
	cout << "Enter your full name to deposit money: ";
	cin.getline(CustName, 20);
	
	for (int i=0; i<n; i++)
		{
			if (strcmp(CustName, DepositStruct[i].Name) == 0)
			{
				cout << DepositStruct[i].Name << 
				", how much would you like to deposit? ";
				cin >> value;
				total = value + DepositStruct[i].Balance;
				DepositStruct[i].Balance += value;
			}
		}
				ifstream inData;
				inData.open("data.txt");
				ofstream outData;
				outData.open("data.txt");
				while (!inData.eof())
				{
					for (int k = 0; k < n; k++)
					{
						outData << DepositStruct[k].Name;
						outData << "  ";
						outData << setprecision (2) << fixed << DepositStruct[k].Balance;
						outData << endl;
						getline(inData, recs);
					}
					inData.close();
					outData.close();
				}
				
			cout << "Now your new balance is " << total << endl;
			
}
