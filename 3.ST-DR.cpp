#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("input.dat");

int INFO[100];
int ST[100];
int DR[100];
int n;

void read(){
    fin >> n;
    for(int i = 1; i <= n; i++) fin >> INFO[i];
    for(int i = 1; i <= n; i++) fin >> ST[i];
    for(int i = 1; i <= n; i++) fin >> DR[i];
}

void RSD(int node){
    if(INFO[node] != 0){
        cout << INFO[node] << " ";
        RSD(ST[node]);
        RSD(DR[node]);
    }
}

void SRD(int node){
    if(INFO[node] != 0){
        SRD(ST[node]);
        cout << INFO[node] << " ";
        SRD(DR[node]);
    }
}

void SDR(int node){
    if(INFO[node] != 0){
        SDR(ST[node]);
        SDR(DR[node]);
        cout << INFO[node] << " ";
    }
}

int main()
{
    read();
    RSD(1);
    cout << endl;
    SRD(1);
    cout << endl;
    SDR(1);
    cout << endl;
    return 0;
}


6
100 50 20 60 170 190
2 3 0 0 0 0
5 4 0 0 6 0
