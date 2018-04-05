/*Enter your code here. Read input from STDIN. Print your output to STDOUT*/
#include <iostream>
#include<vector>
using namespace std;

int main()
{
    int a[101];   // keeps track of parent of ith node
    
    int n;
    cin>>n;
    
    bool b[n];  // keeps track whether a node is lef or not
    
    vector<int> child[n];      // ith vector keeps track of all children of ith node
    
    for(int i=0;i<n;i++)
    b[i] = true;
    
    
    for(int i=0;i<n;i++)
    {   
        cin>>a[i];
        
        child[a[i]].push_back(i);
        
        if(a[i]!=-1)
        {
            b[a[i]] = false;                // if a[i] is parent of ith node then a[i] cannot be leaf
        }
        else
        {
            if(n==1)
            b[i]=true;
            else
            b[i]=false;
        }
    }
    
    int x;
    cin>>x;

	
}



