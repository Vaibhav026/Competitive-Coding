#include <bits/stdc++.h>
using namespace std;


long int color[100001];
vector<long int> adj[100001];
bool visited[100001];

bool solve2(long int root,long int j,long int clr){

	long int siz = adj[j].size();


	visited[j] = true;

	if(color[j] != clr)
		return false;

	long int m;

	for(long int k=0;k<siz;k++){

		m = adj[j][k];

		if(!visited[m] && m!= root){
			if(!solve2(root,m,clr))
				return false;
		}
	}

	return true;
}

bool solve(long int i){

	long int siz = adj[i].size();

	long int v;
	for(long int j=0;j<siz;j++){

		v = adj[i][j];
		if(!solve2(i,v,color[v]))
			return false;
	
	}

	return true;

}

int main()
{
	long int n;

	cin >> n;

	
	long int u,v;

	for(long int i=1;i<n;i++){

		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);

	}


	

	for(long int i=1;i<=n;i++){
		cin >> color[i];
	}

	long int a = 0,b = 0;

	bool check = false;
	for(long int i=1;i<=n;i++){

		long int siz = adj[i].size();

		for(long int j=0;j<siz;j++){

			if(color[i] != color[adj[i][j]]){
				a = i;
				b = adj[i][j];
				check = true;
				break;
			}
		}

		if(check)
			break;
	}

	bool one = false;
	bool two = false;

	for(long int i=1;i<=n;i++)
		visited[i] = false;
	if(check){

		one = solve(a);

		for(long int i=1;i<=n;i++)
		visited[i] = false;

		two = solve(b);

		if(one){
			cout << "YES\n";
			cout << a;
		}
		else if(two){
			cout << "YES\n";
			cout << b;	
		}
		else
			cout << "NO";


	}
	else{
		cout << "YES\n";
		cout <<  "1";
	}




	return 0;
}