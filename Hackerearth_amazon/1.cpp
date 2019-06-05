#include<bits/stdc++.h>
using namespace std;

vector<int> adj[200005];

int n,q;

vector<long int> level[200005];


long int value[200005];

bool visited[200005];

int maxl;

void bfs(int root){
    
    queue < pair<int,int> > q;
    
    q.push(make_pair(root,0));
    
    
    for(int i=1;i<=n;i++){
        visited[i] = false;
    }
    
    visited[root] = true;
    
    
    while(!q.empty()){
        
        pair<int,int> p = q.front();
        
        q.pop();
        
        int curr_val = p.first;
        
        int curr_lev = p.second;
        
        level[curr_lev].push_back(value[curr_val]);
        
        for(int i=0;i<adj[curr_val].size();i++){
            
            if(!visited[adj[curr_val][i]]){
                
                q.push( make_pair(adj[curr_val][i],(curr_lev+1)) );
                visited[adj[curr_val][i]] = true;
            }
            
        }
        
        //maxl = curr_lev;
        
    }
    
    for(int i=0;i<200001;i++){
        
        if(level[i].size() == 0){
            maxl = i-1;
            break;
        }
    }
    //cout << maxl << endl;
    
    for(int i=0;i<=maxl;i++){
        
        sort(level[i].begin(),level[i].end());
    }
    
}
vector<long int> GreaterEqual (vector<long int> A, vector<long int> X, vector<int> u, vector<int> L, vector<int> v) {
   // Write your code here
    
    
    vector<long int> out;
    
    int j = 1;
    
    for(int i=0;i<n;i++){
        
        value[j] = A[i];    
        j++;
    }
    
    
    for(int i=1;i<n;i++){
        
        adj[u[i]].push_back(v[i]);
        adj[v[i]].push_back_back(u[i]);
    }
    
    bool find[n+1];
    
    for(int i=1;i<=n;i++){
        find[i] = false;
    }
    
    for(int i=1;i<n;i++){
        
        find[v[i]] = true;
    }
    
    int root;
    
    // for(int i=1;i<=n;i++){
        
    //     if(!find[i]){
            
    //         root = i;
    //         break;
            
    //     }    
        
    // }
    
    
    bfs(1);
    
    
    long int lvl;
    
    for(int i=0;i<q;i++){
        
        lvl = L[i]%(maxl+1);
        
        vector<long int>::iterator itr,itr2;
        
        int sz = level[lvl].size();
        
        itr  = upper_bound(level[lvl].begin(),level[lvl].end(),X[i]);
        
        //itr2  = itr - level[lvl].begin();
        
        if(level[lvl][sz-1]  == X[i]){
            out.push_back(X[i]);
        }
        else if(level[lvl][sz-1]  < X[i]){
            out.push_back(-1);
        }
        else{
            
            out.push_back(*itr);
        }
    }
   
    return out;
}
int main(){

	#ifndef ONLINE_JUDGE    
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int N, Q;
    cin >> N >> Q;
    
    n = N;
    
    q = Q;
    vector<long int> A(N);
    for(int i_A=0; i_A<N; i_A++)
    {
        cin >> A[i_A];
    }
    
    vector<int> u(N), v(N);
    
    for(int i_u=1; i_u<N; i_u++)
    {
        cin >> u[i_u] >> v[i_u];
    }
    
    vector<int> L(Q);
    vector<long int> X(Q);
    for(int i_L=0; i_L<Q; i_L++)
    {
        cin >> L[i_L] >> X[i_L];
    }
    vector<long int> out_;
    out_ = GreaterEqual(A, X, u, L, v);
    cout << out_[0];
    for(int i_out_=1; i_out_<out_.size(); i_out_++)
    {
        cout << "\n" << out_[i_out_];
    }








}