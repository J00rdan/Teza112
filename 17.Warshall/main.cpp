#include <fstream>
#include <iostream>
using namespace std;

ifstream fin("input.dat");

int n;
int graph[100][100];

void read_data()
{
    fin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            fin>>graph[i][j];
}

int conversie()
{
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                if(i != k && j != k && i != j) graph[i][j] = min(graph[i][k], graph[k][j]);
            }
        }
    }
}

int main()
{
    read_data();
    conversie();
    cout<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<graph[i][j]<<" ";
        cout<<endl;
    }
}
