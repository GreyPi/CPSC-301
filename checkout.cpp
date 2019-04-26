//Gregory Pierot
//Section #2
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "person.cpp"
#include "book.cpp"

using namespace std;

void printMenu() 
{
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
		getline(inData,author);
		getline(inData, category);
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
	inData.close();
	return highest + 1;
}

Book * getBook(vector<Book *> & myBooks, int bkId)
{
	for (unsigned int i = 0; i < myBooks.size(); i++)
	{
		if (bkId == myBooks.at(i)->getId())
		{
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
	inData.open("rentals.txt");
	while (inData >> bkId >> crdId)
	{	
		Book * bookPtr = getBook(myBooks, bkId);
		Person * crdPtr = getCard(myCardholders, crdId);
		bookPtr->setPersonPtr(crdPtr);
	}
		
	inData.close();
}

void bookCheckOut(vector<Book *> & myBooks, vector<Person *> & myCardholders)
{
	int cId, bId;
	
	Book * bkPtr = nullptr;
	Person * pPtr = nullptr;
	cout << "Please enter the card ID: ";
	cin >> cId;
	Person * crdPtr = getCard(myCardholders, cId);
	if (crdPtr != nullptr)
	{
		bool found = false;
		cout << "CardHolder: " << crdPtr->fullName() << endl;
		cout << "Please enter the book ID: ";
		cin >> bId;
		bkPtr = getBook(myBooks, bId);
		if (bkPtr != nullptr && bkPtr->getPersonPtr() == nullptr)
		{
			cout << "Title: " << bkPtr->getTitle()
			<< endl << "Rental Completed" << endl;
			found = true;
			bkPtr->setPersonPtr(pPtr);
		}
		else if (found == false)
		{
			cout << "Book ID not found" << endl;
		}
		else if (bkPtr->getPersonPtr() != nullptr)
		{
			cout << "Book already checked out" << endl;
			found = true;
		}
		
	}
	else
		{
			cout << "Card ID not found" << endl;
		}
}

void bookReturn(vector<Book *> & myBooks, vector<Person *> & myCardholders)
{
	int bId;
	Person * pPtr = nullptr;
	cout << "Please enter the book ID to return: ";
	cin >> bId;
	Book * bkPtr = getBook(myBooks, bId);
	if (bId == bkPtr->getId())
	{
		cout << bkPtr->getTitle() << endl
		<< "Return completed" << endl;
		bkPtr->setPersonPtr(pPtr);
	}
	else
	{
		cout << "Book ID not found" << endl;
	}
}

void viewAv(vector<Book *> & myBooks)
{
	bool found = false;
	for (unsigned int i =0; i < myBooks.size(); i++)
	{
		if (myBooks.at(i)->getPersonPtr() == nullptr)
		{
			cout << endl << "Book ID: " << myBooks.at(i)->getId() << endl
			<< "Title: " << myBooks.at(i)->getTitle() << endl
			<< "Author: " << myBooks.at(i)->getAuthor() << endl
			<< "Category: " << myBooks.at(i)->getCategory() << endl
			<< endl;
			found = true;
		}
	}
	if (found == false)
		{
			cout << "No available booke" << endl;
		}
	
}

void viewOut(vector<Book *> & myBooks)
{
	bool found = false;
	for (unsigned int i =0; i < myBooks.size(); i++)
	{
		if (myBooks.at(i)->getPersonPtr() != nullptr)
		{
			cout << endl << "Book ID: " << myBooks.at(i)->getId() << endl
			<< "Title: " << myBooks.at(i)->getTitle() << endl
			<< "Author: " << myBooks.at(i)->getAuthor() << endl
			<< "Category: " << myBooks.at(i)->getCategory() << endl
			<< endl;
			found = true;
		}
	}
	if (found == false)
	{
		cout << "No outstanding rentals" << endl;
	}
}

void viewOutCrd(vector<Book *> & myBooks, vector<Person *> & myCardholders)
{
	int crdId;
	cout << "Please enter the card ID: ";
	cin >> crdId;
	Person * prsPtr = getCard(myCardholders, crdId);
	if(crdId == prsPtr->getId() && prsPtr->isActive() == true)
	{
	cout << "Cardholder: " << prsPtr->fullName() << endl;
	for (unsigned int i =0; i < myBooks.size(); i++)
	{
		if (myBooks.at(i)->getPersonPtr() == prsPtr)
		{
			cout << endl << "Book ID: " << myBooks.at(i)->getId() << endl
			<< "Title: " << myBooks.at(i)->getTitle() << endl
			<< "Author: " << myBooks.at(i)->getAuthor() << endl
			<< "Category: " << myBooks.at(i)->getCategory() << endl
			<< endl;
		}
		
	}
	}
	else
		cout << "No books currently checked out" << endl;
}

void openCrd(vector<Person *> & myCardholders, int id)
{
	bool act = true;
	string fName, lName;
	cout << "Please enter the first name: ";
	cin >> fName;
	cout << "Please enter the last name: ";
	cin >> lName;
	Person * newPtr = new Person(id, act, fName, lName);
	cout << "Card ID " << newPtr->getId() << " active" << endl;
	cout << "Cardholder: " << newPtr->fullName() << endl;
	myCardholders.push_back(newPtr);
}

void closeCrd(vector<Person *> & myCardholders)
{
	int crdId;
	char input;
	cout << "Please enter the card ID: ";
	cin >> crdId;
	Person * crdPtr = getCard(myCardholders, crdId);
	if(crdId != crdPtr->getId())
	{
		cout << "Card ID not found" << endl;
	}
	if (crdPtr->getId() == crdId && crdPtr->isActive() == true)
	{
		cout << "Cardholder: " << crdPtr->fullName() << endl;
		cout << "Are you sure you want to deactivate card" << endl
		<< "(y/n)? ";
		cin >> input;
		if (input == 'y')
		{
			cout << "Card ID deactivated" << endl;
			crdPtr->setActive(false);
		}
		else if (input == 'n')
		{
			cout << "Card is still active" << endl;
		}
	}
	else
	{
		cout << "Cardholder: " << crdPtr->fullName() << endl;
		cout << "Card ID is already inactive" << endl;
	}
}

void update(vector<Book *> & myBooks, vector<Person *> & myCardholders)
{
	ofstream outData; 
	outData.open("persons.txt");
	for (unsigned int i =0; i < myCardholders.size(); i++)
	{
		outData << myCardholders.at(i)->getId() 
		<< " " << myCardholders.at(i)->isActive()
		<< " " << myCardholders.at(i)->fullName() << endl;
	}
	outData.close();
	
	outData.open("rentals.txt");
	for (unsigned int k =0; k < myBooks.size(); k++)
	{
		outData << myBooks.at(k)->getId()
		<< " " << myCardholders.at(k)->getId() << endl; 
		
	}
	outData.close();
	
}

int main()
{
	int newId;
	vector<Book *> books;
	vector<Person *> cardholders;
	readBooks(books);
	newId = readPersons(cardholders);
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
			bookReturn(books, cardholders);// Book return
			break;

		case 3:
			viewAv(books);// View all available books
			break;

		case 4:
			viewOut(books);// View all outstanding rentals
			break;

		case 5:
			viewOutCrd(books, cardholders);// View outstanding rentals for a cardholder
			break;

		case 6:
			openCrd(cardholders, newId);// Open new library card
			break;

		case 7:
			closeCrd(cardholders);// Close library card
			break;

		case 8:
			update(books, cardholders);// Must update records in files here before exiting the program
			break;

		default:
			cout << "Invalid entry" << endl;
			break;
		}
		cout << endl;
	} while (choice != 8);
	return 0;
}
