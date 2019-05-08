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

int findd(node *tree, int search_value){
    if(tree == NULL) return 0;
    if(tree->value == search_value) return 1;

    if(tree->value > search_value)
        return findd(tree->left, search_value);
    else if(tree->value < search_value)
        return findd(tree->right, search_value);
}

int RSD(node *tree){
    if(tree != NULL){
        cout << tree->value << " ";
        RSD(tree->left);
        RSD(tree->right);
    }
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

    cout << findd(arbore, 20);
    cout << endl << findd(arbore, 25);
    cout << endl;

    RSD(arbore);
    cout << endl;
    SRD(arbore);
    return 0;
}
