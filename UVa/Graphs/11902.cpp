#include <bits/stdc++.h>
using namespace std;

bool adj[101][101];

bool visited[101];

bool np[101];

int n;

void dfs(int i,int na){

	if(i == na)
		return;

	visited[i] = true;

	int v;
	for(int j = 0;j<n;j++){

		v = adj[i][j];
		if(v && !visited[j])
			dfs(j,na);
	}

}

void print(int n){
	cout <<"+";
	int siz = 2*n -1;
	for(int i=1;i<=siz;i++)
		cout << "-";
	cout << "+";
}
int main()
{
	int t;

	cin >> t;


	


	for(int m = 1;m<=t;m++){

		cout << "Case " << m << ":\n";
		

		cin >> n;

		print(n);
        
        cout << endl;
		for(int i=0;i<n;i++){

			for(int j=0;j<n;j++){
				cin >> adj[i][j];
			}
		}

		dfs(0,-1);

		for(int i=0;i<n;i++){

			np[i] = !visited[i];
		}


		for(int i=0;i<n;i++)
			cout << "|Y";

		cout << "|";
		cout << endl;
		for(int i=1;i<n;i++){

			print(n);
			cout << endl;
			for(int j=0;j<n;j++){
				

				for(int x=0;x<=100;x++)
					visited[x] = false;


				if( i == j)
					cout << "|Y";
				else if(np[j])	
					cout << "|N";
				else{

					dfs(0,i);

					if(!visited[j])
						cout << "|Y";
					else
						cout << "|N";
				}
					
			

			}

			cout << "|";
			cout << endl;
		}


	}

	print(n);

	cout << endl;






	return 0;
}


