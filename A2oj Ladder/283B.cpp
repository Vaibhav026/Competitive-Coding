// Cow's Program 
// Just check i have not defined a[1] value(thought that it would matter for 1- state) but realised that 1- state is not attainable just think
// Found difficulty in implementing this , future vaibhav may find difficulty understanding the code but
// the main difficluty was how to do it O(N).

// Finally i did dfs on all nodes but for the nodes for which ans was already calculated was stored in dp array
// hence they were not calculated again
// I personally do not like the code,who knows this question may be useful for understanding something
// Chao! 

#include <bits/stdc++.h>
using namespace std;

long int n;

long int a[200001];
long long int dp[200001][2];

bool visited[200001][2];

long long int dfs(int i,bool state){

    if(i<=0 || i>n)
        return 0;

    int z;
    if(state) z = 1;
    else
    z = 0;
    

    if(dp[i][z]!=0){
        //visited[i][z] = false;
        return dp[i][z];
    }
    else if(visited[i][z]){
        dp[i][z] = -1;
        //visited[i][z] = false;
        return -1;
    }
     
    visited[i][z] = true;
    long long int temp;
    if(state){

        temp = dfs(i+a[i],!state);
        
        if(temp!=-1)
        dp[i][z] = a[i] + temp;
        else
        dp[i][z] = -1;    
    }
    else{

        temp = dfs(i-a[i],!state);

        if(temp!=-1)
        dp[i][z] = a[i] + temp;
        else
        dp[i][z] = -1;   
    }
    
    visited[i][z] = false;    
    return dp[i][z];
}

int main()
{
    

    

    cin >> n;

    

    for(int i=2;i<=n;i++){
        cin >> a[i];
    }

     for(int i=1;i<=n;i++){
        
        dp[i][0] = 0;
        dp[i][1] = 0;

        visited[i][0] = false; 
        visited[i][1] = false;

     }
                   
    // 1 means '+' state i.e it will go to higher state
    // 0 means '-' state i.e it will go to lower state
    //dfs(2,false);

     for(int i=1;i<=n;i++){
        
        dfs(i,false);

     }

     cout << a[1]<<"one"<<endl;
     long long int ans;
     for(int i=1;i<n;i++){
        visited[1][1] = true;
        //a[1] = i; 
        
        if(dp[i+1][0] == -1)
            ans = -1;
        else
            ans = i + dp[i+1][0];
        cout << ans << endl;

     }





    return 0;
}