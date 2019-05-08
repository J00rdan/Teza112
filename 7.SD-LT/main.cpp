#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("input.dat");

int n;
int ST[100];
int DR[100];
int TATA[100];
int FIU[100];

void read(){
    fin >> n;
    for(int i = 1; i <= n; i++) fin >> ST[i];
    for(int i = 1; i <= n; i++) fin >> DR[i];
}

void conversie(){
    for(int i = 1; i <= n; i++){
        TATA[ST[i]] = i;
        FIU[ST[i]] = -1;
        TATA[DR[i]] = i;
        FIU[DR[i]] = 1;
    }
}

int main()
{
    read();
    conversie();
    for(int i = 1; i <= n; i++) cout << TATA[i] << " ";
    cout << endl;
    for(int i = 1; i <= n; i++) cout << FIU[i] << " ";
    return 0;
}
