#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("input.dat");

int n;
int graph[100][100];

void read(){
    fin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) fin >> graph[i][j];
}

void Roy_Floyd(){
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(graph[i][j] > graph[i][k] + graph[k][j]) graph[i][j] = graph[i][k] + graph[k][j];
}

int main()
{
    read();
    Roy_Floyd();
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) cout << graph[i][j] << " ";
        cout << endl;
    }
    return 0;
}
