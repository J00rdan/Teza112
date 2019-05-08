#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("input.dat");

struct edge
{
    int node1;
    int node2;
};

int M[100][100];
int n;
int sets[100];
int distances[100];
int parent[100];

void read(){
    fin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) fin >> M[i][j];
    for(int i = 1; i <= n; i++) distances[i] = 10000, sets[i] = i;
}

int min_distance(){
    int minn = 10000;
    int min_index;

    for(int i = 1; i <= n; i++)
        if(distances[i] < minn  && sets[i] != 0) {
            minn = distances[i];
            min_index = i;
        }
    return min_index;
}

void BuildAPM(){
    distances[1] = 0;
    parent[1] = -1;

    for(int counter = 1; counter <= n; counter++){
        int node = min_distance();

        sets[node] = 0;

        for(int i = 1; i <= n; i++){
            if(M[node][i] && sets[i] != 0 && M[node][i] < distances[i])
                parent[i] = node, distances[i] = M[node][i];
        }
    }

    for(int i = 2; i <= n; i++) cout << parent[i] << " " << i << " " << M[i][parent[i]] << endl;
}

int main()
{
    read();
    BuildAPM();
    return 0;
}
