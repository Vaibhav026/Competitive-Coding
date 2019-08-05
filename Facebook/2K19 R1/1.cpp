#include<bits/stdc++.h>
using namespace std;


long int graph[51][51];

long int dist[51][51];
void F(int V)  
{  
    /* dist[][] will be the output matrix  
    that will finally have the shortest  
    distances between every pair of vertices */
    int i, j, k;  
  
    /* Initialize the solution matrix same  
    as input graph matrix. Or we can say  
    the initial values of shortest distances 
    are based on shortest paths considering  
    no intermediate vertex. */
    for (i = 1; i <= V; i++)  
        for (j = 1; j <= V; j++)  
            dist[i][j] = graph[i][j];  
  
    
    for (k = 1; k <= V; k++)  
    {  
        // Pick all vertices as source one by one  
        for (i = 1; i <= V; i++)  
        {  
            // Pick all vertices as destination for the  
            // above picked source  
            for (j = 1; j <= V; j++)  
            {  
                // If vertex k is on the shortest path from  
                // i to j, then update the value of dist[i][j]  
                
                if(dist[i][k] == -1 || dist[k][j] == -1)
                	continue;

                if (dist[i][j] == -1 || dist[i][k] + dist[k][j] < dist[i][j])  
                    dist[i][j] = dist[i][k] + dist[k][j];  
            }  
        }  
    }  
    
}  
int main() {

	#ifndef ONLINE_JUDGE    
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int t;

	cin >> t;

	int n,m;


	
	for(int i=1;i<=t;i++){

		cin >> n >> m;

		for(int j=1;j<=50;j++){

			for(int k=1;k<=50;k++){
				graph[j][k] = -1;
				dist[j][k] = -1;
			}
		}

		int v1[m+1],v2[m+1],w[m+1];

		for(int j=1;j<=m;j++){

			cin >> v1[j] >> v2[j] >> w[j];

			graph[v1[j]][v2[j]] = w[j];
			graph[v2[j]][v1[j]] = w[j];

		}

		F(n);

		// cout << "hi";
		bool ans = true;

		for(int j=1;j<=m;j++){

			if(dist[v1[j]][v2[j]] != w[j]){
				ans = false;
				break;
			}

		}

		cout << "Case #" << i << ": ";

		if(ans){

			cout << m << "\n";
			for(int j=1;j<=m;j++){

				cout << v1[j] << " " << v2[j] << " " << w[j] << "\n";
			}

			

		}
		else{

			cout << "Impossible\n";
		}
		 

		

		
	}


	return 0;
}	