#include <bits/stdc++.h>
using namespace std;


vector <long long int> adj[100005];

bool visited[100005];

long long int v[100005];

pair<long long int,long long int> dfs(long long int i){

	int l = adj[i].size();
	
	long long int t1 = 0 , t2 = 0;

	pair<long long int ,long long int > p;

	long long int plusmax = 0,submax = 0;

	visited[i] = true;

	for(int j=0;j<l;j++){

		if(!visited[ adj[i][j] ]){
			
			p = dfs(adj[i][j]);

			t1 = p.first;
			t2 = p.second;

			if(t1 > plusmax)
				plusmax = t1;

			if(t2 > submax)
				submax = t2;
		}
	}

	long long int leftover = v[i] + plusmax - submax;

	pair<long long int,long long int> x;
	
	if(leftover >= 0){
		 x.first = plusmax ;
		 x.second = submax + leftover;
		 return x;
	}
	else
	{
		x.first =  plusmax -leftover;
		x.second = submax;

		return x;
	}	 

}


int main()
{
	long long int n;
	cin >> n;

	long long int a,b;

	

	for(long long int i=1;i<=n-1;i++){
		
		visited[i] = false;
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a); 
	}

	visited[n] = false;

	

	for(long long int i=1;i<=n;i++)
		cin >> v[i];

	pair <long long int,long long int > ans = dfs(1);

	long long int f = ans.first + ans.second;

	cout << f;

	return 0;
}