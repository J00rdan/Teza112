#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("input.dat");

struct node
{
    int value;
    struct node *left;
    struct node *right;
};

int n;
int V[100];
struct node *arbore = NULL;

node *make(node *tree, int new_value){
    if(tree == NULL){
        tree = new node;
        tree->value = new_value;
        tree->right = NULL;
        tree->left = NULL;
        return tree;
    }

    if(new_value < tree->value)
        tree->left = make(tree->left, new_value);
    else if(new_value > tree->value)
        tree->right = make(tree->right, new_value);
    return tree;
}

/*node *findd(node *tree, int search_value, node *father){
    if(tree == NULL) return NULL;
    if(tree->value == search_value){
        father = tree;
        return tree;
    }

    if(tree->value > search_value){
        father = tree;
        return findd(tree->left, search_value, father);
    }
    else if(tree->value < search_value){
        father = tree;
        return findd(tree->right, search_value, father);
    }
}*/

node *find_resolver(node *nasty){
    node *walker = nasty->left;
    while(walker->right != NULL) walker = walker->right;
    return walker;
}

node *deleteNode(node *tree, int delete_value){
    if(tree == NULL) return tree;

    if(tree->value > delete_value){
        tree->left = deleteNode(tree->left, delete_value);
    }
    else if(tree->value < delete_value){
        tree->right = deleteNode(tree->right, delete_value);
    }

    else{
        if(tree->left == NULL){
            node *temp = tree->right;
            delete(tree);
            return temp;
        }
        else{
            node *temp = tree->left;
            delete(tree);
            return temp;
        }
    }
    return tree;
}

int RSD(node *tree){
    if(tree != NULL){
        cout << tree->value << " ";
        RSD(tree->left);
        RSD(tree->right);
    }
}

node *deleteDiffNode(node *tree, int delete_value){
    if(tree == NULL) return tree;

    if(tree->value > delete_value){
        tree->left = deleteDiffNode(tree->left, delete_value);
    }
    else if(tree->value < delete_value){
        tree->right = deleteDiffNode(tree->right, delete_value);
    }

    else{
        node *temp = find_resolver(tree);
        temp->right = new node;
        temp->right->value = tree->right->value;
        temp->right->right = tree->right->right;
        temp->right->left = tree->right->left;
        tree->right = NULL;
        delete(tree->right);
    }
    return tree;
}

int SRD(node *tree){
    if(tree != NULL){
        SRD(tree->left);
        cout << tree->value << " ";
        SRD(tree->right);
    }
}


int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++){
        int value;
        fin >> value;
        arbore = make(arbore, value);
    }

    //node *father;
    //node *temp = findd(arbore, 20, father);
    //cout << temp->value << endl;
    //cout << father->value << endl;

    arbore = deleteDiffNode(arbore, 70);

    RSD(arbore);
    cout << endl;
    SRD(arbore);
    return 0;
}
