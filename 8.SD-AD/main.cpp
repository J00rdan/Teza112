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
int ST[100];
int DR[100];
struct nodes *arbore = NULL;

void read(){
    fin >> n;
    for(int i = 1; i <= n; i++) fin >> INF[i];
    for(int i = 1; i <= n; i++) fin >> ST[i];
    for(int i = 1; i <= n; i++) fin >> DR[i];
}

nodes* make_tree(nodes* tree, int node){
    tree = new nodes;
    tree->value = INF[node];
    if(ST[node] != 0)
        tree->left = make_tree(tree->left, ST[node]);

    if(DR[node] != 0)
        tree->right = make_tree(tree->right, DR[node]);

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
