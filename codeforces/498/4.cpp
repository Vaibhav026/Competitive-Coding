#include <bits/stdc++.h>
using namespace std;

std::vector<int> adj[200005];
std::vector<int> ans;
int children[200005];

int dfs(int i){

	
	int v;
	int l = adj[i].size();
	int x;
//	ans.push_back(i);
	children[i] = 0;
	for(int j = 0;j<l;j++){

		v = adj[i][j];

		ans.push_back(v);
		
		x = dfs(v);	
		children[i] += 1+x;

	}
	// ans.push_back(-i);

	return children[i];
}

int main()
{
	int n,q;
	cin >> n >> q;

	
	int x;

	for(int i=1;i<n;i++){

		cin >> x;

		adj[x].push_back(i+1);
	}

	ans.push_back(1);

	dfs(1);

	int index[n+1];
	for(int i=0;i<ans.size();i++){

		index[ans[i]] = i ;
	}

	int u,k;

	for(int i=0;i<q;i++){

		cin >> u >> k;

		if(k > (1+children[u]))
			cout << "-1\n";
		else{

			cout << ans[index[u] + k -1] << "\n";
		}

	}



}