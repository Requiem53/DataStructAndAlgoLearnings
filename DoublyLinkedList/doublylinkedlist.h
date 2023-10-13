#include "list.h"
#include <iostream>
#include "node.h"
#include <cmath>
using namespace std;

class DoublyLinkedList : public List {
	node *head, *tail;
	int size;
	
public:
	void addFirst(int num) {
		// STEP 1: Create node
		node* n = (node*) calloc( 1, sizeof(node) );
		n->elem = num;
		// STEP 2: Set n's next to head
		n->next = head;
		if (head) {
			head->prev = n;
		}
		// STEP 3: Set head to n
		head = n;
		if (!tail) {
			tail = n;
		}
		// STEP 4: Update size
		size++;
	}
	
	void addLast(int num) {
		// STEP 1: Create the node...
		node* n = new node;
		n->elem = num;
		n->next = nullptr;
		// STEP 2: If tail...
		n->prev = tail;
		if (tail) {
			tail->next = n;
		} else {
			head = n;
		}
		// STEP 3: Set tail to n
		tail = n;
		// STEP 4: Update size
		size++;
	}

	int addAt(int num, int pos){
		int journey = 0;

		node* n = new node;
		n->elem = num;
		n->prev = nullptr;

		node* curr;

		//Adds head (and potentiall tail if only one element)
		if(pos == 1){
			n->next = head;
			if (head) {
			head->prev = n;
			}
			head = n;
			if (!tail) {
				tail = n;
			}
		}else{
		//Checks for fastest route
		//Unlike removeAt, this goes to the element PRECEDING pos so you insert in next
		if(pos <= size-pos){
			curr = head;
			int ctr = 1;
			while(ctr < pos-1){
				curr = curr->next;
				ctr++;
				journey++;
			}
		}else{
			curr = tail;
			int ctr = size;
			while(ctr >= pos){
				curr = curr->prev;
				ctr--;
				journey++;
			}
		
		}

		//Assigns respective pointers to fit n
		n->next = curr->next;
		curr->next = n;	
		n->prev = curr;

		//Checks if n is in the end then assign to tail, otherwise, change succedding n's prev to n
		if(pos == size+1){
			tail = n;
		}else{
			n->next->prev = n;
		}
		
		size++;
		}
		return journey;
	}

	int removeAt(int pos){
		int journey = 0;
		int removed = 0;

		node* curr;

		//Step 1: Check for fastest route
		if(pos <= size-pos || pos == ceil(size/2.0)){
			//Already has a starting point (head). This loops enough times to reach desired pos.
			curr = head;
			int ctr = 1;
			while(ctr < pos){
				curr = curr->next;
				ctr++;
				journey++;
			}
		}else{
			//Already has a starting point (tail). This loops enough times to reach desired pos.
			curr = tail;
			int ctr = size;
			while(ctr >= pos+1){
				curr = curr->prev;
				ctr--;
				journey++;
			}
		}

		removed = curr->elem;

		//Actual Removing Process v
		//Checks if the element is in the beginning
		if(curr == head){
			head = head->next;
			if(head){
				head->prev = nullptr;
			}else{
				//Head already null at this point
				tail = nullptr;
			}
		}else{
			//Step 2: Change next pointer of previous of curr to point to curr's next element, skipping curr
			curr->prev->next = curr->next;
			if(curr == tail){
				//Changes tail position to previous position but checks if this is the only element (for freeing)
				tail = tail->prev;
				if(tail){
					tail->next = nullptr;
				}else{
					//Tail is null at this point
					head = nullptr;
				}
			}else{
				//Curr is not at the last position, so succeeding element's prev is changed to skip curr
				curr->next->prev = curr->prev;
			}
			//Wonder what this does..
			free(curr);
			curr = nullptr;
		}
		size--;

		return removed;
	}

	int retain(int num){
    int count = 0;
    node* curr = head;

	//Maurice Taneca GOD code
	//Same explanation as removeAt but curr iterates through whole list
	while(curr) {
		if(curr->elem < num) {
			if(curr == head) {
                
				head = head->next;
				if(head){
                head->prev = NULL;
                } 
				else {
                tail = NULL;
                }
                free(curr);
				curr = head;
			} else {
				curr->prev->next = curr->next;
				if(curr == tail){
					if(tail){
						tail->next = NULL;
					}else{
						head = NULL;
					}
					tail->next = NULL;
				} 
				else{
					curr->next->prev = curr->prev;
				} 
				free(curr);
			}
				size--;
				count++;
			} else{
            curr = curr->next;
            } 
    }
    return count;
    }

	int removeAll(int num) {
    
	int count = 0;
    node* curr = head;

	//Maurice Taneca GOD code
	//Same explanation as removeAt but curr iterates through whole list
	while(curr) {
		if(curr->elem == num) {
			if(curr == head) {
				head = head->next;
				if(head) head->prev = nullptr;
				else tail = nullptr;
				free(curr);
				curr = head;
			} else {
				curr->prev->next = curr->next;
				if(curr == tail){
					tail = tail->prev;
					if(tail){
						tail->next = nullptr;
					}else{
						head = nullptr;
					}
					tail->next = nullptr;
				} 
				else{
					curr->next->prev = curr->prev;
				} 
				free(curr);
			}
				size--;
				count++;
			} else curr = curr->next;
    }
    return count;
}

void removeFirst() {
		if (size == 0) {
			return;
		}
		head = head->next;
		if (head) {	
			free(head->prev);
			head->prev = nullptr;
		} else {
			free(tail);
			tail = nullptr;
		}
		size--;
	}
	
	void removeLast() {
		if (size == 0) {
			return;
		}
		tail = tail->prev;
		if (tail) {	
			free(tail->next);
			tail->next = nullptr;
		} else {
			free(head);
			head = nullptr;
		}
		size--;
	}
	
	void add(int num) {
		addLast(num);
	}
	
	int get(int pos) {
		node* curr = head;
		int ctr = 1;
		while (ctr != pos) {
			curr = curr->next;
			ctr++;
		}
		return curr->elem;
	}
	
	int remove(int num) {
		return 0;
	}
	
	void print() {
		cout << "Size: " << size << endl;
		node* curr = head;
		cout << "From HEAD: ";
		while (curr) {
			cout << curr->elem << "->";
			curr = curr->next;
		}
		curr = tail;
		cout << endl << "From TAIL: ";
		while (curr) {
			cout << curr->elem << "<-";
			curr = curr->prev;
		}
		cout << endl;
	}
};