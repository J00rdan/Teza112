#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("input.dat");

int H[100];
int n;

void Insert_heap(int n, int value){
    int fiu = n;
    int tata = fiu / 2;
    while(tata && H[tata] < value){
        H[fiu] = H[tata];
        fiu = tata;
        tata = fiu / 2;
    }
    H[fiu] = value;
}

int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++){
        int value;
        fin >> value;
        Insert_heap(i, value);
    }

    for(int i = 1; i <= n; i++) cout << H[i] << " ";

    return 0;
}
