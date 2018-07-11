#include <bits/stdc++.h>
using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
 
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);
 
    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);
 
	#endif

    int t;

    cin >> t;

    int x;

    int n;

    for(int i=1;i<=t;i++){

    	cin >> n;

    	for(int j=1;j<=(n+1);j++)
    		cin >> x;


    	if(n%2 == 0){
    		cout << "Case #"<<i<<": ";
    		cout << "0\n";
    	}
    	else
    	{	
    		cout << "Case #"<<i<<": ";
    		cout << "1\n";
    		cout << "0.000000\n";
    	}	
    }


	return 0;
}