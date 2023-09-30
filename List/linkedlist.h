#include "list.h"
#include <iostream>
#include "node.h"
using namespace std;

class LinkedList : public List {
	node *head, *tail;
	int size;
	
public:
	void addHead(int num){
        node* n = (node*) calloc( 1, sizeof(node) );
		n->elem = num;
        n->next = head;
		if (size == 0) {
			head = n;
			tail = n;
		} else {
            n->next = head;
            head = n;
		}
		size++;
    }

    void addTail(int num){
        node* n = (node*) calloc( 1, sizeof(node) );
		n->elem = num;
		if (size == 0) {
			head = n;
			tail = n;
		} else {
			tail->next = n;
			tail = n;
		}
		size++;
    }
	
	//uses 'a' as operation
	void add(int num) {
		addTail(num);
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
	
	//uses 'r' as operation
	int remove(int num) {
		node* curr = head;
        node* prev;

        int ctr = 1;
		bool flag = false;

        while(ctr <= size){
            if(curr->elem == num){
                if(curr == head){
                    head = head->next;
                    free(curr);
                }else{
                    prev->next = curr->next;
                    if(curr == tail){
                        tail = prev;
                    }
                    free(curr);
                }
                size--;
				flag = true;
				break;
            }else{
                prev = curr;
                curr = curr->next;
            }
			ctr++;
        }

		if(!flag){ctr = -1;}

        return ctr;
	}
	

	//uses 't' as operation
	int removeAt(int pos){
		int removed;
		if(pos > size || pos <= 0){
			return -1;
		}

		if(pos == 1){
			removed = head->elem;
            node* newHead = head->next;
            free(head);
            head = newHead;
        }else{
            node* curr = head;
            node* prev;

    		int ctr = 1;
    		while (ctr != pos) {
                prev = curr;
    			curr = curr->next;
    			ctr++;
    		}
			removed = curr->elem;
            prev->next = curr->next;
            free(curr);

            if(pos == size){
                tail = prev;
            }

        }
        size--;
        return removed;
	}

	//uses 'R' as operation
	int removeAll(int num){
		int ctr = 0;
		node* curr = head;
		node* prev;

		while(curr){
            if(curr->elem == num){
                if(curr == head){
                    head = head->next;
                    free(curr); 
					curr = head;  
                }else{
                    prev->next = curr->next;
                    if(curr == tail){
                        tail = prev;
                    }
                    free(curr);
					curr = curr->next;
                }
                size--;
                ctr++;
            }else{
                prev = curr;
                curr = curr->next;
            }
        }
		return ctr;
	}

	void print() {
    	node* curr = head;
    	if (size == 0) {
    		cout << "Empty" << endl;
		} else {
	    	while (true) {
	    		cout << curr->elem;
	    		if (curr != tail) {
	    			cout << " -> ";
				} else {
					cout << endl;
                    break;
				}
	    		curr = curr->next;
			}
		}
    }
};