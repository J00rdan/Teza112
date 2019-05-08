#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("input.dat");

struct nodes
{
    int value;
    struct nodes *left = NULL;
    struct nodes *right = NULL;
};

int n;
int INF[100];
int TATA[100];
int FIU[100];
struct nodes *arbore = NULL;

void read(){
    fin >> n;
    for(int i = 1; i <= n; i++) fin >> INF[i];
    for(int i = 1; i <= n; i++) fin >> TATA[i];
    for(int i = 1; i <= n; i++) fin >> FIU[i];
}

nodes* make_tree(nodes* tree, int node){
    tree = new nodes;
    tree->value = INF[node];

    for(int i = 1; i <= n; i++){
        if(TATA[i] == node){
            if(FIU[i] == -1){
                tree->left = make_tree(tree->left, i);
            }
            else tree->right = make_tree(tree->right, i);
        }
    }
    return tree;
}

int RSD(nodes *tree){
    if(tree != NULL){
        cout << tree->value << " ";
        RSD(tree->left);
        RSD(tree->right);
    }
}

int SRD(nodes *tree){
    if(tree != NULL){
        SRD(tree->left);
        cout << tree->value << " ";
        SRD(tree->right);
    }
}

int main()
{
    read();
    arbore = make_tree(arbore, 1);
    RSD(arbore);
    cout << endl;
    SRD(arbore);
    return 0;
}
