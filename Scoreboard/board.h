#include "entry.h"

class Scoreboard {
	entry board[5];
	int size;

	public:
	bool add(entry e) {
		for (int i = 0; i < size; i++) {
			entry exist = board[i];
			if (e.score > exist.score) {
				for (int j = size; j >= i+1; j--) {
					if (j == 5) {
						continue;
					}
					board[j] = board[j-1];
				}
				board[i] = e;
				if (size < 5) {
					size++;
				}
				return true;
			}
		}
			if (size < 5) {
				board[size++] = e;
                return true;
			} else {
				cout << "PUNO NA" << endl;
                return false;
			}
    }

    // TODO add method banCollege here
    int banCollege(string college){
        int counter = 0;
        for(int i = size-1; i >= 0; i--){
            if(college.compare(board[i].college) == 0){
                for(int j = i; j < size; j++){
                    if(j < size-1){
                        board[j] = board[j+1];
                    }
                }
                size--;
                counter++;
            }
        }
        return counter;
    }

    void print() {
        for (int i = 0; i < 5; i++) {
            if (i >= size) {
                cout << i+1 << ". (none)" << endl;
            } else {
            	entry e = board[i];
                cout << i+1 << ". " << e.name << " (" << e.college << ")" << " - " << e.score << endl;
            }
        }
        cout << endl;
    }
};