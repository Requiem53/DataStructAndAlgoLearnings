// Warning: Do not modify this file.
// Go to linkedlist.h's remove method
#include <iostream>
#include "doublylinkedlist.h"

using namespace std;

int main(int argc, char** argv) {
	DoublyLinkedList* list = new DoublyLinkedList();
	char op;
	int num, pos;
	do {
		cout << "Op: ";
		cin >> op;
		switch (op) {
			case '@':
                cin >> num >> pos;
                cout << "Length of traversal: " << list->addAt(num, pos) << endl;
				break;
			case 'h':
				cin >> num;
				list->addFirst(num);
				break;
			case 't':
				cin >> num;
				list->addLast(num);
				break;
			case 'r':
				cin >> pos;
				cout << "Removed: " << list->removeAt(pos) << endl; 
				break;
			case 'R':
				cin >> num;
				cout << "Removed " << list->removeAll(num) << " element/s" << endl;
				break;
			case 'F':
				list->removeFirst();
				break;
			case '=':
				cin >> num;
				cout << "Removed " << list->retain(num) << " element/s" << endl;
				break;
			case 'T':
				list->removeLast();
				break;
			case 'p':
				list->print();
				break;
			case 'g':
				cin >> num;
				cout << "Pos " << num << " is " << list->get(num) << endl;
				break;
			case 'x':
				cout << "Exiting";
				break;
		}
	} while (op != 'x');
	return 0;
}