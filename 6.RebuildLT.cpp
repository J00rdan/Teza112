#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("input.dat");

int n;
int RSD[100];
int SRD[100];
int TATA[100];
int DIST[100];
int INF[100];

int current_node;

void read(){
    fin >> n;

    for(int i = 1; i <= n; i++) fin >> RSD[i];
    for(int i = 1; i <= n; i++) fin >> SRD[i];

    for(int i = 1; i <= n; i++) cout << RSD[i] << " ";
    cout << endl;
    for(int i = 1; i <= n; i++) cout << SRD[i] << " ";
    cout << endl;
}

int searchhSRD(int node, int start, int endd){
    for(int i = start; i <= endd; i++) if(RSD[node] == SRD[i]) return i;
}

void build_tree(int father, int direction, int SRD_start, int SRD_end){

    int future_father = current_node;

    TATA[current_node] = father;
    DIST[current_node] = direction;

    if(SRD_start != SRD_end){
        int index_in_srd = searchhSRD(current_node, SRD_start, SRD_end);

        if(SRD_start <= index_in_srd - 1){
            current_node++;
            build_tree(future_father, -1, SRD_start, index_in_srd - 1);
        }

        if(index_in_srd + 1 <= SRD_end){
            current_node++;
            build_tree(future_father, 1, index_in_srd + 1, SRD_end);
        }
    }

}

int main()
{
    read();

    current_node = 1;
    build_tree(0, 0, 1, n);
    cout << endl;
    for(int i = 1; i <= n; i++) cout << TATA[i] << " ";
    cout << endl;
    for(int i = 1; i <= n; i++) cout << DIST[i] << " ";
    cout << endl;
    return 0;
}
