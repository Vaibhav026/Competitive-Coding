#include<bits/stdc++.h>
using namespace std;


int main()
{
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif


    int t;
    cin >> t;

    long int n;

    long int a[100001];
    long int b[100001];


    long int index[100001];
    
    while(t--){

    	cin >> n;

    	for(int i=1;i<=n;i++){
    		cin >> a[i];
    		b[i] = i;
    		index[a[i]] = i;
    	}

    	int steps = 0;

    	if(n == 1){
    		cout << "0\n";
    	}
    	else{

    		if(index[1] > index[2]){
    			swap(b[1],b[2]);
    			swap(index[1],index[2]);
    			steps++;
    		}

    		for(int i=3;i<=n;i++){

    			if(index[i] < index[i-1]){
    				swap(b[i],b[i-1]);
    				swap(index[i],index[i-1]);
    				steps++;

    			if(index[i-1] < index[i-2]){
					swap(b[i-2],b[i-1]);
    				swap(index[i-2],index[i-1]);
    				steps++;    					
    			}
    			
    			}
    		}

    		bool ans = true;

    		for(int i=1;i<=n;i++){

    			if(a[i] != b[i]){
    				ans = false;
    				break;
    			}
    		}

    		if(!ans)
    			cout << "Too chaotic\n";
    		else
    			cout << steps << "\n";
    	}
    	
    }

    return 0;
}