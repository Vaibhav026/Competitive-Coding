#include<bits/stdc++.h>
using namespace std;



struct sett
{
	int parent;
	int rank;
};

sett S[100001];

int find(int x){

	if(S[x].parent != x){
		S[x].parent = find(S[x].parent);
	}

	return S[x].parent;
}

void unn(int x,int y){

	int p1 = find(x);

	int p2 = find(y);

	if(S[p1].rank >  S[p2].rank){
		S[p2].parent = p1;
	}
	else if(S[p1].rank < S[p2].rank){
		S[p1].parent =  p2;
	}
	else{

		S[p2].parent = p1;
		S[p1].rank++; 
	}


}

int main()
{
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
   	#endif

    long int n,m,k;

    cin >> n >> m >> k;

    

    vector<long long int> cost;

    vector<int> vert1;
    vector<int> vert2;

    int u,v;
   	
   	long long int w;

   	long long int varc[m];

    for(int i=0;i<m;i++){
		cin >> u >> v >> w;
			
		vert1.push_back(u);
		vert2.push_back(v);
		cost.push_back(w);

		varc[i] = cost[i];
    }


    vector< pair<long long int,int> > vect1,vect2;
    
    for(int i=0;i<m;i++){
		vect1.push_back(make_pair(cost[i],vert1[i])); 	
    }

    sort(vect1.begin(),vect1.end());

    for(int i=0;i<m;i++){
		vect2.push_back(make_pair(cost[i],vert2[i])); 	
    }

    sort(vect2.begin(),vect2.end());

	// for(int i=0;i<m;i++){

 //    	cout << vect1[i].first << " " << vect1[i].second << " " << vect2[i].first << " " << vect2[i].second << endl;
 //    }

    //cout << endl;
    for(int i=1;i<=n;i++){

    	S[i].rank = 0;
    	S[i].parent = i;
    }	

    long long int prc =0;

    int edges;

    long long int ans1 = 0,ans2 = 0;
    for(int i=0;i<m;i++){
    	prc = vect1[i].first;
    	u = (vect1[i].second);

    	v = vect2[i].second;

    	if(find(u) != find(v)){

    		unn(u,v);
    		edges++;

    		if(edges <= k){
    		ans1 += prc;
    		}
    		else
    		ans2 += prc;
    	}

    	

    }

    cout << ans1 << " " << ans2;
    return 0;
}  