#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("input.dat");

char C[37];
int length;
int V[37];
int n;
char H[37];
int H2[37];

int IsInC(char x){
    for(int i = 1; i <= length; i++)
        if(C[i] == x){
            V[i]++;
            return 1;
        }
    return 0;
}

void read(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        char c;
        fin >> c;
        if(IsInC(c) == 0){
            length ++;
            V[length] = 1;
            C[length] = c;
        }
    }
    for(int i = 1; i <= length; i++) cout << C[i] << " " << V[i] << endl;
}

void Insert_heap(int n, char c){
    int fiu = n;
    int tata = fiu / 2;
    while(tata && H2[tata] < V[n]){
        H[fiu] = H[tata];
        H2[fiu] = H2[tata];
        fiu = tata;
        tata = fiu / 2;
    }
    H[fiu] = c;
    H2[fiu] = V[n];
}

void create_heap(){
    for(int i = 1; i <= length; i++){
        Insert_heap(i, C[i]);
    }
}

int main()
{
    read();
    cout << endl;
    create_heap();
    for(int i = 1; i <= length; i++) cout << H[i] << " " << H2[i] << endl;
    return 0;
}
