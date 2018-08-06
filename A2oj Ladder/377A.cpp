#include <bits/stdc++.h>
using namespace std;

char c[505][505];

int changes = 0;

int k;
int n,m;

int sum =0;

void dfs(int x,int y){

	if(changes == sum-k)
		return;

	c[x][y] = 'X';
	changes++;

	if(x+1<n && c[x+1][y] == '.')
		dfs(x+1,y);

	if(x-1>=0 && c[x-1][y] == '.')
		dfs(x-1,y);

	if(y+1 < m && c[x][y+1] == '.')
		dfs(x,y+1);

	if(y-1>=0 && c[x][y-1] == '.')
		dfs(x,y-1);

}
	

int main()
{
	

	cin >> n >> m >> k;

	int x;
	int y;

	

	for(int i=0;i<n;i++){

		for(int j=0;j<m;j++){
			cin >> c[i][j];
			
			if(c[i][j] == '.'){
				x = i;
				y =j;

				sum++;
			}

		}
	} 


	//cout << sum << " " << k << endl;

	dfs(x,y);

	for(int i=0;i<n;i++){

		for(int j=0;j<m;j++){
			
			if(c[i][j] == '.')
				cout << "X";
			else if(c[i][j] == 'X')
				cout << ".";
			else
				cout << "#";
		}

		cout << endl;
	} 






}