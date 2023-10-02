#include "list.h"
#include <iostream>
#include "node.h"
using namespace std;

class LinkedList : public List {
	node *head, *tail;
	int size;
	
public:
    void printTailNext(){
		cout << "Tail's next or head: " << tail->next->elem << endl;
	}
    void rotate(){
        tail = tail->next;
        head = head-> next;
    }
	
	//uses 'a' as operation
	void add(int num) {
		node* n = (node*) calloc( 1, sizeof(node) );
		n->elem = num;
		if (size == 0) {
			head = n;
			tail = n;
		} else {
			tail->next = n;
            tail = n;
		}
        tail->next = head;
		size++;
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

	//uses '@' with num and pos operation
	void addAt(int num, int pos){
        if(pos == 1 || pos == size+1){
            add(num);
        }else if(pos > size+1 || pos <= 0){
			cout << "Invalid position" << endl;
			return;
		}else{
			node* n = (node*) calloc( 1, sizeof(node) );
			n->elem = num;
            node* curr = head;
			int ctr = 1;
			while(ctr < pos-1){
				curr = curr->next;
				ctr++;
			}
            n->next = curr->next;
            curr->next = n;
			size++;
        }
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

        tail->next = head;

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
        tail->next = head;
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
        tail->next = head;
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
            printTailNext();
		}
    }
};