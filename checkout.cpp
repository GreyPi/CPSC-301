//Gregory Pierot
//Section #2
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "person.cpp"
#include "book.cpp"

using namespace std;

void printMenu() {
	cout << "----------Library Book Rental System----------" << endl;
	cout << "1.  Book checkout" << endl;
	cout << "2.  Book return" << endl;
	cout << "3.  View all available books" << endl;
	cout << "4.  View all outstanding rentals" << endl;
	cout << "5.  View outstanding rentals for a cardholder" << endl;
	cout << "6.  Open new library card" << endl;
	cout << "7.  Close library card" << endl;
	cout << "8.  Exit system" << endl;
	cout << "Please enter a choice: ";
}

/* You are not obligated to use these function declarations -
* they're just given as examples*/
void readBooks(vector<Book *> & myBooks)
{
	int id = 0;
	string title, author, category;
	string line;

	ifstream inData;
	inData.open("books.txt");
	while (inData >> id)
	{
		getline(inData, line);
		getline(inData,title);
		//getline(inData, line);
		getline(inData,author);
		//getline(inData, line);
		getline(inData, category);
		//getline(inData, line);
		Book * book = new Book(id, title, author, category);
		myBooks.push_back(book);
	}
	
}

int readPersons(vector<Person *> & myCardholders)
{
	int cardNo;
	bool act;
	string fName, lName, line;
	int highest = 0;

	ifstream inData;
	inData.open("persons.txt");
	while (inData >> cardNo)
	{
		inData >> act;
		inData >> fName;
		inData >> lName;
		Person * person = new Person(cardNo, act, fName, lName);
		myCardholders.push_back(person);
		if (highest < cardNo)
		{
			highest = cardNo;
		}
	}
	return highest + 1;
}

Book * getBook(vector<Book *> & myBooks, int bkId)
{
	cout << bkId << endl;
	for (unsigned int i = 0; i < myBooks.size(); i++)
	{
		cout << myBooks.at(i)->getId() << endl;
		if (bkId == myBooks.at(i)->getId())
		{
			cout << "Hello" << endl;
			return myBooks.at(i);
		}
	}
	return nullptr;
}

Person * getCard(vector<Person *> & myCardholders, int crdId)
{
	for (unsigned int i = 0; i < myCardholders.size(); i++)
	{
		if (crdId == myCardholders.at(i)->getId())
		{
			cout << "Hello" << endl;
			return myCardholders.at(i);
		}
	}
	return nullptr;
}

void readRentals(vector<Book *> & myBooks, vector<Person *> myCardholders)
{

	int bkId, crdId;
	string line;
	ifstream inData;
	inData.open("persons.txt");
	while (inData >> bkId)
	{	
		inData >> crdId;
		
		cout << bkId << " " << crdId << endl;
		/*for (unsigned int i = 0; i < myBooks.size(); i++)
		{
			if (bkId == myBooks.at(i)->getId())
			{
				if (crdId == myCardholders.at(i)->getId())
				{
					Person * ptr = myCardholders.at(i);
					myBooks.at(i)->setPersonPtr(ptr);
					myBooks.at(i)->getPersonPtr();
				}
			}*/
		Book * bookPtr = getBook(myBooks, bkId);
		Person * crdPtr = getCard(myCardholders, crdId);
		bookPtr->setPersonPtr(crdPtr);
		//bookPtr->getPersonPtr();
		}
		
	
inData.close();
}

/*void openCard(vector<Person *> & myCardholders, int nextID)
{
	string fName, lName;
	bool act = false;
	cout << "Please enter the first name: ";
	cin >> fName;
	cout << "Please enter the last name: ";
	cin >> lName;
	string fullN = fName + lName;
	for (unsigned int i = 0; i < myCardholders.size(); i++)
	{
		if (fullN == myCardholders.at(i)->fullName())
		{
			myCardholders.at(i)->setActive(true);
			return;
		}
	}
	Person * cardOp = new Person(nextID, act, fName, lName);
	myCardholders.push_back(cardOp);

}*/

void bookCheckOut(vector<Book *> & myBooks, vector<Person *> & myCardholders)
{
	int cId, bId;
	Book * bkPtr;
	//Person * prsnPtr;
	cout << "Please enter the card ID: ";
	cin >> cId;
	Person * crdPtr = getCard(myCardholders, cId);
	if (crdPtr->isActive() == true)
	{
		cout << "CardHolder: " << crdPtr->fullName() << endl;
		cout << "Please enter the book ID: " << endl;
		cin >> bId;
		bkPtr = getBook(myBooks, bId);
		cout << bkPtr->getId() << endl;
		//prsnPtr = bkPtr->getPersonPtr();
		
			cout << "Title: " << bkPtr->getTitle()
			<< endl << "Rental Completed" << endl;
		
	}
	else 
	{
		cout << "ID not found" << endl;
	}
	/**/
	
}

void bookReturn(vector<Book *> & myBooks, vector<Person *> & myCardholders)
{
	int bId;
	cout << "Please enter the book ID to return: " << endl;
	cin >> bId;
	Book * bkPtr = getBook(myBooks, bId);
	for (unsigned int i = 0; i < myBooks.size(); i++)
	{
		if (bkPtr->getTitle() == myBooks.at(i)->getTitle())
		{
		cout << "Title : " << bkPtr->getTitle()
		<< endl << "Return Completed" << endl;
		}
	}
}

int main()
{
	vector<Book *> books;
	vector<Person *> cardholders;
	readBooks(books);
	cout << "after books" << endl;
	readPersons(cardholders);
	cout << "after persons" << endl;
	readRentals(books, cardholders);

	int choice;
	do
	{
		// If you use cin anywhere, don't forget that you have to handle the <ENTER> key that 
		// the user pressed when entering a menu option. This is still in the input stream.
		printMenu();
		cin >> choice;
		switch (choice)
		{
		case 1:
			bookCheckOut(books, cardholders);// Book checkout
			break;

		case 2:
			// Book return
			break;

		case 3:
			// View all available books
			break;

		case 4:
			// View all outstanding rentals
			break;

		case 5:
			// View outstanding rentals for a cardholder
			break;

		case 6:
			// Open new library card
			break;

		case 7:
			// Close library card
			break;

		case 8:
			// Must update records in files here before exiting the program
			break;

		default:
			cout << "Invalid entry" << endl;
			break;
		}
		cout << endl;
	} while (choice != 8);
	return 0;
}
