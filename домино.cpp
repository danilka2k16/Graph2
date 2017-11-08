#include <iostream>

using namespace std;

const int MAXN = 1000;


int n,m;
int a[MAXN][MAXN];
bool visited[MAXN];
bool flag1=0;
int flag2=0;

void ms(int v,int e){
    for (int i=0; i<=(v+1); i++){
        for (int j=0; j<=v; j++){
            a[i][j]=0;
        }
	}
	for (int k = 0; k<e; k++)
	{
	    int i,j;
        cin >> i;
        cin >> j;
        a[i][j]+=1;
        a[j][i]+=1;
		}
}

void dfs(int v) {
    for (int i =0; i < n; i++){
        if ((a[v][i] != 0) && (visited[i]==0)){
                visited[i]=1;
                dfs(i);
        }
    }
}

int main() {

    cin >> m; //number of knuckles
    cin >> n; //maximum number on the knuckle

    ms(n,m);

    for (int i = 0; i <= n; ++i)
        visited[i] = 0;

    visited[n]=1;
    dfs(n);

    for (int i=0;i<=n;i++){
            for (int j=0;j<=n;j++){
                a[n+1][i]=a[n+1][i]+a[j][i];
            }
            if ((a[n+1][i]!=0) && (visited[i]==0))
                flag1=1;
            if (a[n+1][i]%2==1)
                flag2++;
        }

    if ((flag1==0) && (flag2==2))
        cout << "can";
    else cout << "can not";

    return 0;
}
