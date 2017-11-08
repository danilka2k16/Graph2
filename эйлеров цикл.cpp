#include <iostream>

using namespace std;

const int MAXN = 1000;


int n,m;
int a[MAXN][MAXN];
bool flag=0;

void FindEuler(int v) {
    for (int i =0; i < m; i++){
        if (a[v][i]==1){
            a[v][i]=0;
            for (int j=0;j<n;j++){
                if (a[j][i]==1){
                    a[j][i]=0;
                    cout << j;
                    FindEuler(j);
                }
            }
        }
    }
}

int main() {

    cin >> n; //number of vertices
    cin >> m; //number of ribs

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];
    }

    for (int i = 0; i < m; ++i)
        visited[i] = 0;

    for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                a[i][m]+=a[i][j];
            }
            if (a[i][m]%2==1)
                flag=1;
    }
    if (flag==1)
        cout << "cycle not found";
    else {
            cout << 0;
            FindEuler(0);
    }
    return 0;
}
