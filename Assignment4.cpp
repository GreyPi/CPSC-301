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
void Deposit(PERSON arr[], int N, char custName[], float amount);
PERSON* readData(int & N);

void printmenu() {
    cout << "Please enter a choice:" << endl;
    cout << "1. Display records"<< endl;
    cout << "2. Deposit funds"<< endl;
    cout << "3. Find Highest Balance" << endl;
    cout << "4. Update records" << endl;
    cout << "5. Exit the program" << endl;
}

int main()
{
	int N = 0;
	char custName[20];
	float amt = 0;
	PERSON* P = new PERSON[N];
	P = readData(N);
	
	{
    int choice;
    do
    {
        printmenu();
        cin >> choice;
        switch(choice)
        {
            case 1:
                Display(P, N); // Act on display
                break;

            case 2:
                Deposit(P, N, custName, amt); // Act on deposit

                break;

            case 3:
                FindRichest(P, N); // Act highest balance
                break;

            case 4:
                // Act on update records
                break;

            case 5:
                // Must call update records here before exiting the program
                break;

            default:
                cout << "Invalid entry" << endl;
                break;
        }
        cout << endl;
   } while(choice != 5);
      	
	return 0;
}
}
}

PERSON* readData(int & N)
{
	ifstream inData;
	inData.open("data.txt");
	char first[20];
	char last[20];
	
	string numRecords;
	while (getline(inData, numRecords))
	{
		N++;
	}
	inData.close();
	
	PERSON * RD = new PERSON[N];
	
	inData.open("data.txt");
		while(!inData.eof())
		{
			for (int i =0; i < N; i++)
				{
					inData >>  RD[i].Name;
					strcpy(first, RD[i].Name);
					if (strlen(first) > 9)
					{
					cout << "The name is too long";
					}	
					else
					
					inData >> RD[i].Name;
					strcpy(last, RD[i].Name);
					if (strlen(last) > 10)
					{
					cout << "The name is too long";
					}
					else
					strcpy(RD[i].Name, first);
					strcat(RD[i].Name, " ");
					strcat(RD[i].Name, last);
					inData >> RD[i].Balance;
				}
		}
	return RD;
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

void Deposit(PERSON arr[], int N, char custName[], float amount)
{
	float value = 0;
	float total = 0;
	string recs;
	cout << "Enter your full name to deposit money: ";
	cin.getline(custName, 20);
	
	for (int i=0; i<N; i++)
		{
			if (strcmp(custName, arr[i].Name) == 0)
			{
				cout << arr[i].Name << 
				", how much would you like to deposit? ";
				cin >> value;
				total = value + arr[i].Balance;
				arr[i].Balance += value;
			}
		}
				ifstream inData;
				inData.open("OG.txt");
				ofstream outData;
				outData.open("OG.txt");
				while (!inData.eof())
				{
					for (int k = 0; k < N; k++)
					{
						outData << arr[k].Name;
						outData << "  ";
						outData << setprecision (2) << fixed << arr[k].Balance;
						outData << endl;
						getline(inData, recs);
					}
					inData.close();
					outData.close();
				}
				
			cout << "Now your new balance is " << total << endl;
			
}
