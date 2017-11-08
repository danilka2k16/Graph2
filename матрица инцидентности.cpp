#include <iostream>

using namespace std;

int main()
{
	int v,e;
	cin >> v>>e;
	bool a[v][e];
	for (int i=0; i<v; i++){
        for (int j=0; j<e; j++){
            a[i][j]=0;
        }
	}
	for (int k = 0; k<e; k++)
	{
	    int i,j;
        cin >> i;
        cin >> j;
        a[i-1][k]=1;
        a[j-1][k]=1;
		}
	for (int i=0; i<v; i++){
        for (int j=0; j<e; j++){
            cout << a[i][j];
            cout << " ";
        }
        cout << endl;
	}
	return 0;
}
