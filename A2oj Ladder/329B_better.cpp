#include <bits/stdc++.h>
using namespace std;

bool visited[1001][1001];
char a[1001][1001];
int r,c;

int ans[1001][1001];

void bfs(int i,int j)
{	std::pair <int,int> m;

	std::queue < std::pair <int,int> > q;

	m.first = i;
	m.second = j;
	q.push(m);

	int x,y;

	ans[m.first][m.second] = 0;
	visited[m.first][m.second] = true;

	while(!q.empty()){

		x = (q.front()).first;
		y = (q.front()).second;

		q.pop();
		

		if(x+1<r && a[x+1][y]!='T' && !visited[x+1][y]){
			q.push(make_pair(x+1,y));
			ans[x+1][y] = ans[x][y] + 1;
			visited[x+1][y] = true;
		}

		if(x-1>=0 && a[x-1][y]!='T' && !visited[x-1][y]){
			q.push(make_pair(x-1,y));
			ans[x-1][y] = ans[x][y] + 1;
			visited[x-1][y] = true;
		}

		if(y+1<c && a[x][y+1]!='T' && !visited[x][y+1]){
			q.push(make_pair(x,y+1));
			ans[x][y+1] = ans[x][y] + 1;
			visited[x][y+1] = true;
		}

		if(y-1>=0 && a[x][y-1]!='T' && !visited[x][y-1]){
			q.push(make_pair(x,y-1));
			ans[x][y-1] = ans[x][y] + 1;
			visited[x][y-1] = true;
		}
	}

}
int main()
{
	

	cin >> r >> c;

	int manx,many;	
	int exitx,exity;							
	for(int i=0;i<r;i++){
		
		for(int j=0;j<c;j++){
			cin >> a[i][j];

			if(a[i][j] == 'S'){

				manx = i;
				many = j;
			}

			if(a[i][j] == 'E'){

				exitx = i;
				exity = j;
			}

		}
	}


	for(int i=0;i<r;i++){
		
		for(int j=0;j<c;j++){
			
			ans[i][j] = INT_MAX;
		}
	}

	bfs(exitx,exity);

	int mansteps = ans[manx][many];
		
	//cout << mansteps << endl;	
	int temp;

	int sum =0;
	int z;
	for(int i=0;i<r;i++){
		
		for(int j=0;j<c;j++){
			
			temp = ans[i][j];
			z = a[i][j] - '0';
			if(temp<= mansteps && z>0 && z<=9){
				sum += z;
			}

		}
	}																	


	cout << sum;
	return 0;
}