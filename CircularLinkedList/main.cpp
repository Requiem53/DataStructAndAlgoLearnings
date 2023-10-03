// Warning: Do not modify this file.
// Go to linkedlist.h's remove method

#include <iostream>
#include "circularlinkedlist.h"

int main() {
	List* list = new CircularLinkedList();
    int input, pos, num;
    char op;
    do {
    	cout << "Enter op: ";
    	cin >> op;
    	switch (op) {
    		case 'a' :
		    	cin >> input;
		    	list->add(input);
		    	break;
		    case 'r':
		    	cin >> input;
                cout << "Removed position " << list->remove(input) << endl;
		    	break;
			case 't':
				cin >> pos;
                cout << "Removed " << list->removeAt(pos) << endl;
				break;
			case 'R':
                cin >> num;
                cout << "Removed " << list->removeAll(num) << " element/s" << endl;
				break;
			case '@':
                cin >> num >> pos;
                list->addAt(num, pos);
				break;
		    case 'p':
		    	list->print();
		    	break;
		    case 'x':
		    	cout << "Exiting";
		    	break;
		}
	} while (op != 'x');
    return 0;

}