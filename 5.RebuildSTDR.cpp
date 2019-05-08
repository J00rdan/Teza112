#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("input.dat");

int n;
int RSD[100];
int SRD[100];
int ST[100];
int DR[100];
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

    if(father != 0){
        if(direction == -1)
            ST[father] = current_node;
        else DR[father] = current_node;
    }

    int future_father = current_node;

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
    for(int i = 1; i <= n; i++) cout << ST[i] << " ";
    cout << endl;
    for(int i = 1; i <= n; i++) cout << DR[i] << " ";
    cout << endl;
    return 0;
}


6
100 50 20 60 170 190
20 50 60 100 170 190

