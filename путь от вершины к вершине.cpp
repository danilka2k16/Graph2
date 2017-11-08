#include <iostream>

using namespace std;

const int MAXN = 1000;


int n,k,m, a[MAXN][MAXN];
int visited[MAXN];
int P[MAXN][MAXN];


void dfs(int v) {
    for (int i = 0; i < n; i++){
        if ((a[v][i] == 1) && ((visited[i]==0) || (visited[i]>(visited[v]+1)))){
                visited [i]=visited[v]+1;
                z=visited[v];
                for (int k=0; k<z; k++){
                    P[i][k]=P[v][k];
                }
                P[i][z]=i;
                dfs(i);
        }
    }
}

int main() {

    cin >> n; 

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j]; 

    for (int i = 0; i < n; ++i)
        visited[i] = 0;

    cin >> k;
    visited[k]=1;
    P[k][0]=k;
    dfs(k);

    cin >> m;

    cout << visited[m]-1 << endl;
    z=visited[m];
    for (int i=0; i<z; i++){
        cout << P[m][i];
    }
    return 0;
}
