#include <bits/stdc++.h>
using namespace std;

int n;
vector< pair<int,int> > adj[100001];

bool visited[100001];

vector<int> ans;

int solve(int root){

	int l = adj[root].size();

	visited[root] = true;

	pair<int,int> p;

	int soln = 0;

	int a ,t;

	int temp;

	for(int i=0;i<l;i++){

		p = adj[root][i];

		a = p.first;
		t = p.second;

		if(!visited[a]){

			temp = solve(a);

			if(temp == 0 && t == 2){
				soln++;
				ans.push_back(a);
			}

			soln += temp;
		}


	}

	return soln;
}

int main()
{	
	

	cin >> n;


	int a,b,t;
	for(int i=1;i<n;i++){

		cin >> a >> b >> t;

		adj[a].push_back(make_pair(b,t));
		adj[b].push_back(make_pair(a,t));
	}



	int l = solve(1);



	cout << l << endl;

	for(int i=0;i<l;i++)
		cout << ans[i] << " ";






	return 0;
}