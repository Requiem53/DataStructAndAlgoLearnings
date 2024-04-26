struct node {
    node* parent;
    node* right;
    node* left;
    int elem;

    // TODO paste your height method here
    int height() {
        if(this == nullptr){
            return 0;
        }else{
            return (this->left->height()+1 > this->right->height()+1) ? 
            this->left->height()+1 : this->right->height()+1; 
        }
    }
};