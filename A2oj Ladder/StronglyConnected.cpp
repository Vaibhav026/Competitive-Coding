#include <bits/stdc++.h>
using namespace std;

std::vector<int> adj[100001];

std::vector<int> adjrev[100001];

std::vector<int> scc[100001];

long int  mini[100001];

long int mini_cnt[100001];

long int it = 0;

bool visited[100001];

stack<long int> S;

void dfs(int root){
	visited[root] = true;

	int siz = adj[root].size();

	int m;
	for(int i=0;i<siz;i++){

		m = adj[root][i];

		if(!visited[m])
			dfs(m);
	}

	S.push(root);


}

void dfsrev(int root){
	visited[root] = true;

	scc[it].push_back(root);

	int siz = adjrev[root].size();

	int m;
	for(int i=0;i<siz;i++){

		m = adjrev[root][i];

		if(!visited[m])
			dfsrev(m);
	}


}

int main()
{

	long int mod = 1000000007;
	long int n;

	cin >> n;

	long int cost[n+1];

	for(int i=1;i<=n;i++){

		cin >> cost[i];
	}
	
	long int m;

	cin >> m;
	int u,v;

	for(int i=0;i<m;i++){

		cin >> u >> v;

		adj[u].push_back(v);

		adjrev[v].push_back(u);


	}

	for(int i=0;i<=100000;i++){
		visited[i] = false;
		mini_cnt[i] = 0;
	}

	for(int i=1;i<=n;i++){

		if(!visited[i])
			dfs(i);
	}

	for(int i=0;i<=100000;i++){
		visited[i] = false;
	}

	int root;

	while(S.empty() == false){

		root = S.top();

		S.pop();

		if(!visited[root]){
			dfsrev(root);
			it++;
		}

	}


	
	for(int i=0;i<it;i++){

		mini[i] = cost[scc[i][0]];

		int siz = scc[i].size();

		for (int j = 0; j < siz; j++)
		{
			if(cost[scc[i][j]]<mini[i])
				mini[i] = cost[scc[i][j]];	
		}

		
	}

	long long int sum  = 0;

	for(int i=0;i<it;i++){

		sum += mini[i];
	}


	cout << sum << " ";

	for(int i=0;i<it;i++){

		

		int siz = scc[i].size();

		for (int j = 0; j < siz; j++)
		{
			if(cost[scc[i][j]] == mini[i])
				mini_cnt[i]++;	
		}

		
	}

	long long int num_ways = 1;

	for(int i = 0;i<it;i++){

		num_ways = (num_ways * mini_cnt[i])%mod; 
	}

	cout << num_ways;

	return 0;
}