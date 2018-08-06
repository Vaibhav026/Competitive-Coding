#include <bits/stdc++.h>
using namespace std;


long int n; 

vector<long int> adj[100001];

bool visited[100001];

int init[100001];

int goal[100001];

vector<long int> ans;

void solve(long int v,long int even,long int odd,long int level){

	if(level%2 == 0){

		if(even%2 == 0){

			if(init[v] != goal[v]){
				ans.push_back(v);
				even++;
			}
		}
		else{

			if(init[v] == goal[v]){
				ans.push_back(v);
				even++;
			}

		}	


	}
	else{

		if(odd%2 == 0){

			if(init[v] != goal[v]){
				ans.push_back(v);
				odd++;
			}
		}
		else{

			if(init[v] == goal[v]){
				ans.push_back(v);
				odd++;
			}

		}	

	}

	visited[v] = true;

	long int siz = adj[v].size();

	long int m;
	for(int j=0;j<siz;j++){

		m = adj[v][j];

		if(!visited[m])
			solve(m,even,odd,level+1);
	}




}

int main()
{

	cin >> n;


	long int u,v;

	for(long int i=1;i<n;i++){

		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);

	}


	for(int i=1;i<=n;i++){

		cin >> init[i];
	}

	for(int i=1;i<=n;i++){

		cin >> goal[i];
	}

	solve(1,0,0,0);


	long int soln = ans.size();
	cout << soln << endl;

	for(long int j=0;j<soln;j++){
		cout << ans[j] <<endl;
	}


	return 0;
}