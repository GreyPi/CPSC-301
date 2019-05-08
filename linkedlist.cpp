#include "linkedlist.h"

linkedlist::linkedlist() {
	head = nullptr;
}

linkedlist::~linkedlist() {
    // RECURSIVE
}

int linkedlist::count() {
    return 0;// RECURSIVE
}

void linkedlist::addToFront(int n) {
	head = new node;
	head->data = n;
	
}

double linkedlist::average() {
    return 0;// uses sum and count functions
}

int linkedlist::sum() {
    return 0;// RECURSIVE
}

void linkedlist::writeInorder(string & file) {
	
}

void linkedlist::writeReversed(string & file) {
    // RECURSIVE
}
