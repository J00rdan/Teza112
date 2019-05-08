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
    for(int i = 1; i <= n; i++) fin >> TATA[i];
    for(int i = 1; i <= n; i++) fin >> FIU[i];
}

void conversie(){
    for(int i = 1; i <= n; i++){
        if(FIU[i] == -1){
            ST[TATA[i]] = i;
        }
        else if(FIU[i] == 1) DR[TATA[i]] = i;
    }
}

int main()
{
    read();
    conversie();
    for(int i = 1; i <= n; i++) cout << ST[i] << " ";
    cout << endl;
    for(int i = 1; i <= n; i++) cout << DR[i] << " ";
    return 0;
}
