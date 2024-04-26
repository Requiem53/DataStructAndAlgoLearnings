#include "mybinarytree.h"

class SplayTree {
	BinaryTree* tree = new MyBinaryTree();

	public:
	bool search(int num) {
		return search_node(tree->getRoot(), num);
	}

	bool search_node(node* n, int num) {
		if (n == NULL) {
			return false;
		}
		if (n->elem == num) {
			return true;
		}
		if (num > n->elem) {
			// proceed to right
			return search_node(n->right, num);
		} else {
			return search_node(n->left, num);
		}
	}

    node* findNode(int num){
        return node_finder(tree->getRoot(), num);
    }

    node* node_finder(node* n, int num) {
		if (n == NULL) {
			return nullptr;
		}
		if (n->elem == num) {
			return n;
		}
		if (num > n->elem) {
			// proceed to right
			return node_finder(n->right, num);
		} else {
			return node_finder(n->left, num);
		}
	}

    // TODO perform post-processing by checking for violation after insertion
    // from the node inserted (or from its parent) until the root
	node* insert(int num) {
		node* n = tree->getRoot();
		if (n == NULL) {
			return tree->addRoot(num);
		}
		node* inserted = insert_node(n, num);
        violationHelper(inserted);
        return inserted;
	}

    node* violationHelper(node* parent){
        if(parent == nullptr){
            return nullptr;
        }
        int diff = parent->left->height() - parent->right->height();
        diff = (diff < 0) ? diff*-1 : diff;
        if(diff > 1){
            restructure(parent);
            return nullptr;
        }
        return violationHelper(parent->parent);
    }

	node* insert_node(node* n, int num) {
		if (n == NULL) {
			return NULL;
		}
		if (n->elem == num) {
			return NULL;
		}
		if (num > n->elem) {
			if (!n->right) {
				return tree->addRight(n, num);
			} else {
				return insert_node(n->right, num);
			}
		} else {
			if (!n->left) {
				return tree->addLeft(n, num);
			} else {
				return insert_node(n->left, num);
			}
		}
	}


    // TODO perform post-processing by checking for violation after deletion
    // from the parent of the node removed until the root
    bool remove(int num) {
        bool removed = remove_node(tree->getRoot(), num);
        return removed;
    }

	bool remove_node(node* n, int num) {
		if (n == NULL) {
			return false;
		}
		if (n->elem == num) {
            if (n->left && n->right) {
                node* r = n->right;
                while (r->left) {
                    r = r->left;
                }
                node* par = r->parent;
                int rem = tree->remove(r);
                n->elem = rem;
                violationHelper(par);
            } else {
                node* par = n->parent;
    			tree->remove(n);
                violationHelper(par);
            }
            return true;
		}
		if (num > n->elem) {
			return remove_node(n->right, num);
		} else {
			return remove_node(n->left, num);
		}
	}

    // TODO copy and paste your completed restructure method here
    bool restructure(node* gp) {
        node* par; // parent
        // TODO find parent
        par = (gp->left->height() > gp->right->height()) ?
        gp->left : gp->right;

        
        // This is an indicator of the placement of grandparent to parent (gtop)
        bool gtop_right = false;
        if (gp->right == par) {
            gtop_right = true;
        }

        
        node* child;
        // TODO find child
        if(par->left == nullptr && par->right != nullptr){
            child = par->right;
        }else if(par->right == nullptr && par->left != nullptr){
            child = par->left;
        }else if(par->left->height() > par->right->height()){
            child = par->left;
        }else if(par->left->height() < par->right->height()){
            child = par->right;
        }else if(gtop_right){
            child = par->right;
        }else if(!gtop_right){
            child = par->left;
        }

        // This is an indicator of the placement of parent to child (ptoc)
        bool ptoc_right = false;
        if (par->right == child) {
            ptoc_right = true;
        }

        // FOR THE FOLLOWING: Write in each of the if statements a console output
        // on its corresponding operation (ZIGLEFT, ZIGRIGHT, ZIGZAGLEFT, or ZIGZAGRIGHT)

        // z
        //  \
        //   y
        //    \
        //     x
        if (gtop_right && ptoc_right) {
            // TODO call to either zigleft or zigright or both
            cout<<"ZIGLEFT" << endl;
            zigleft(par);
        }

        // z
        //   \
        //     y
        //    /
        //   x
        else if (gtop_right && !ptoc_right) {
            // TODO call to either zigleft or zigright or both
            cout<<"ZIGZAGLEFT" << endl;
            zigright(child);
            zigleft(child);
        }
        //     z
        //    /
        //   y
        //  /
        // x
        else if (!gtop_right && !ptoc_right) {
            // TODO call to either zigleft or zigright or both
            cout<<"ZIGRIGHT" << endl;
            zigright(par);
        }

        //      z
        //    /
        //  y
        //   \
        //    x
        else {
            // TODO call to either zigleft or zigright or both
            cout<<"ZIGZAGRIGHT" << endl;
            //cout<<"GRANDPARENT: " << gp->elem << endl;
            //cout<<"PARENT: " << par->elem << endl;
            //cout<<"CHILD: " << child->elem << endl;
            zigleft(child);
            zigright(child);
        }
        
        return true;
    }

    void zigleft(node* curr) {
        tree->zigleft(curr);
    }

    void zigright(node* curr) {
        tree->zigright(curr);
    }

	void print() {
		tree->print();
	}
};