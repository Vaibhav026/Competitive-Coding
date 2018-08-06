#include <bits/stdc++.h>
using namespace std;

long int n;

long int cnt = 0 ;
long int a[100001];

int child[100001];

bool visited[100001];

vector< pair<int,long int> >adj[100001];


void dfs2(int root,long long int val){

	visited[root] = true;

	if(val > a[root]){
		// cout << root << endl;

		// cout << val << " " << a[root] << endl;	
		cnt += child[root];
		return;
	}

	pair<int,long int> p;

	int l = adj[root].size();

	int v;

	
	for(int i=0;i<l;i++){

		p = adj[root][i];

		v = p.first;

		
		
		if(!visited[v])
			dfs2(v,val+p.second);
	}
	


}
int dfs(int root){

	visited[root] = true;

	pair<int,long int> p;

	int l = adj[root].size();

	int v;

	int ans = 1;
	for(int i=0;i<l;i++){

		p = adj[root][i];

		v = p.first;

		if(!visited[v])
			ans += dfs(v);
	}
	
	child[root] = ans;

	return ans;

}

int main()
{
	cin >> n;

	for(int i=1;i<=n;i++)
		cin >> a[i];


	int v;
	long int val;

	for(int i=1;i<n;i++){

		cin >> v >> val;

		adj[i+1].push_back(make_pair(v,val));
		adj[v].push_back(make_pair(i+1,val));
	}

	for(int i=1;i<=n;i++)
		visited[i] = false;


	int z = dfs(1);

	for(int i=1;i<=n;i++)
		visited[i] = false;


	dfs2(1,0);

	cout << cnt;
	return 0;
}