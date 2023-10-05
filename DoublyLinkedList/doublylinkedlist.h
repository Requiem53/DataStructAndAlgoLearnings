#include "list.h"
#include <iostream>
#include "node.h"
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
		if(pos == 1){
			addFirst(num);
		}else if(pos == size+1){
			add(num);
		}else{
			node* n = new node;
			n->elem = num;

			node* curr;
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
			n->next = curr->next;
			curr->next = n;	
			n->prev = curr;
			n->next->prev = n;
			size++;
		}
		return journey;
	}

	int removeAt(int pos){
		int journey = 0;
		int removed = 0;

		if(pos == 1){
			removed = head->elem;
			removeFirst();
		}else if(pos == size){
			removed = tail->elem;
			removeLast();
		}else{
			node* curr;
			if(pos <= size-pos){
				curr = head;
				int ctr = 1;
				while(ctr < pos){
					curr = curr->next;
					ctr++;
					journey++;
				}
			}else{
				curr = tail;
				int ctr = size;
				while(ctr >= pos+1){
					curr = curr->prev;
					ctr--;
					journey++;
				}
			}
			removed = curr->elem;
			curr->prev->next = curr->next;
			curr->next->prev = curr->prev;
			// free(curr);
			curr = nullptr;
			if(curr)cout << "Curr is sstill not null " << endl;
			size--;
		}
		
		return removed;
	}

	int removeAll(int num){
		int counter = 0;
		node* curr = head;
		if(size == 0){
			return 0;
		}

		while(curr){
			if(curr->elem == num){
				if(curr == head){
					head = head->next;
					if(head){
						head->prev = nullptr;
						curr = head;
					}else{
						tail = nullptr;
						curr = nullptr;
					}
				}else{
					curr->prev->next = curr->next;
					if(curr == tail){
						tail = curr->prev;
					}
					curr = nullptr;
					curr = curr->next;
					
				}
				size--;
				counter++;
			}else{
				curr = curr->next;
			}
		}
		return counter;
	}
	
	void removeFirst() {
		if (size == 0) {
			return;
		}
		head = head->next;
		if (head) {	
			// free(head->prev);
			head->prev = nullptr;
		} else {
			// free(tail);
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
			// free(tail->next);
			tail->next = nullptr;
		} else {
			// free(head);
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