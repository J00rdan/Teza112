#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("input.dat");

typedef struct edge
{
    int node1;
    int node2;
    int weight;
};

edge edges[100];
int n;
int m;
int sets[100];
int A[100];
int sol;

void read(){
    fin >> n >> m;
    for(int i = 1; i <= m; i++){
        fin >> edges[i].node1 >> edges[i].node2 >> edges[i].weight;
    }

    for(int i = 1; i <= n; i++) sets[i] = i;
}

void Sortare(){
    int isSorted = 0;
    do
    {
        isSorted = 1;
        for(int i = 1; i <= m - 1; i++){
            if(edges[i].weight > edges[i + 1].weight){
                isSorted = 0;
                swap(edges[i].node1, edges[i + 1].node1);
                swap(edges[i].node2, edges[i + 1].node2);
                swap(edges[i].weight, edges[i + 1].weight);
            }
        }
    }while(!isSorted);

    for(int i = 1; i <= m; i++) cout << edges[i].node1 << " " << edges[i].node2 << " " << edges[i].weight << endl;
    cout << endl;
}

int findd(int node){
    if(sets[node] == node)
        return node;
    return findd(sets[node]);
}

int isCyclic(int node1, int node2){
    int set1 = findd(node1);
    int set2 = findd(node2);

    if(set1 == set2) return 1;
    return 0;
}

void Union(int node1, int node2){
    int set1 = findd(node1);
    int set2 = findd(node2);

    sets[set1] = set2;
}

void APM(){
    int i = 0;

    while(sol != n - 1){
        i++;
        if(!isCyclic(edges[i].node1, edges[i].node2)){
            Union(edges[i].node1, edges[i].node2);
            A[++sol] = i;
        }
    }

    for(int i = 1; i <= sol; i++){
        cout << edges[A[i]].node1 << " " << edges[A[i]].node2 << " " << edges[A[i]].weight << endl;
    }
}

int main()
{
    read();
    Sortare();
    APM();
    return 0;
}
