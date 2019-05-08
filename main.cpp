#include <iostream>
#include <string>
#include "linkedlist.cpp"
#include <fstream>

using namespace std;

void readFile(linkedlist & list, string & file) 
{
	int lowest = 20;
	int highest = 0;
	node * inputPtr = new node;
	node * head = inputPtr;
	node * temp = head;
	ifstream inData;
	inData.open(file);
	while (!inData.eof())
	{
		inData >> inputPtr->data;
		if(inputPtr->data < lowest)
		{
			lowest = inputPtr->data;
			list.addToFront(lowest);
		}
		if (inputPtr->data > highest)
		{
			highest = inputPtr->data;
		}
		cout << inputPtr->data << endl;
		inputPtr = inputPtr->next;
		inputPtr = new node;
	}
	cout << endl << lowest << endl << highest << endl;
}

int main() 
{
	linkedlist list;
	string fileName = "list.txt";
	readFile(list, fileName);

    return 0;
}
