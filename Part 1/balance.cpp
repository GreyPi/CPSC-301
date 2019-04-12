Gregory Pierot
Section 2
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
void updateRecords(PERSON arr[], int N, char custName[], float amount);

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
                updateRecords(P, N, custName, amt); // Act on update records
                break;

            case 5:
                updateRecords(P, N, custName, amt);// Must call update records here before exiting the program
                return 0;
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
	cout << "\nHighest balance: " << winner << "." << endl;
	cout << endl << endl;
	
}

void Deposit(PERSON arr[], int N, char custName[], float amount)
{
	cin.ignore();
	int a = 0;
	cout << "Enter name: ";
	cin.getline(custName, 20);		
	
	for (int i=0; i<N; i++)
		{
			if (strcmp(custName, arr[i].Name) == 0)
			{
				cout << "Amount: ";
				cin >> amount;
				arr[i].Balance += amount;
				cout << "New Balance: " << arr[i].Balance << endl;
				a = i;
			}
		}
		if (strcmp(custName, arr[a].Name) != 0)
		cout << "Record not found" << endl;
	}

void updateRecords(PERSON arr[], int N, char custName[], float amount)
{
	string recs;
	ifstream inData;
	inData.open("data.txt");
	ofstream outData;
	outData.open("data.txt");
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
				
			cout << "File updated... " << endl;
	
}
