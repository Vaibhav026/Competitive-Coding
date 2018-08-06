#include<bits/stdc++.h>
using namespace std;

bool visited[1001];

std::vector<int> adj[1001];

void dfs(int root){

	visited[root] = true;

	int siz = adj[root].size();

	int m;

	for(int i=0;i<siz;i++){

		m = adj[root][i];

		if(!visited[m])
			dfs(m);
	}
}

int main()
{
	int n;
	cin >> n;

	int a[n],b[n];

	bool is[1001][1001];

	for(int i=0;i<=1000;i++){

		for(int j=0;j<=1000;j++)
			is[i][j] = false;
	}


	for(int i=0;i<=1000;i++)
		visited[i] = false;

	for(int i=0;i<n;i++){

		cin >> a[i] >> b[i];
		is[a[i]][a[i]] = true;
	}

	int levels = 0;

	for(int i = 1;i<=1000;i++){
		if(is[i][i])
			levels++;
	}

	

	int x,y;

	int connections = 0;

	for(int i = 0;i<n;i++){

		x = a[i];
		y = b[i];

		for(int j=i+1;j<n;j++){

			if(!is[x][a[j]] && a[j]!=x && y == b[j]){
				
				is[x][a[j]] = true;
				
				is[a[j]][x] = true;

				adj[x].push_back(a[j]);
				adj[a[j]].push_back(x);
				
				connections++;
			}
		}
	}

	

	int total_components =0;

	for(int i=1;i<=1000;i++){

		if(is[i][i] && !visited[i]){
			dfs(i);
			total_components++;
		}

	}

	cout << total_components-1;

	return 0;
}