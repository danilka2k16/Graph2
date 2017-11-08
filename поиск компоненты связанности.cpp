#include <iostream>

using namespace std;

const int MAXN = 1000;


int n,k, a[MAXN][MAXN], counter = 0;
int visited[MAXN];


void dfs(int v, int c) {
    for (int i = 0; i < n; i++)
    if ((a[v][i] == 1) && (!visited[i])){
            visited[i]=c;
            dfs(i,c);
    }
}


int main() {

    cin >> n; //количество вершин

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j]; // матрица смежности

    for (int i = 0; i < n; ++i)
        visited[i] = 0;

    cin >> k; // вершинв, которую ищем

    for (int i = 0; i < n; ++i)
        if (visited[i]==0) {
            counter++;
            dfs(i,counter);
        }

    cout << visited[k-1] << endl;

    return 0;
}
