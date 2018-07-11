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

	int Total = t;
	long long int n,k,v,temp;

	string a[53];

	long long int start,end; 
	while(t--){

		cin >> n >> k >> v;

		for(int i=0;i<n;i++)
			cin >> a[i];

		temp = v*k;
		start = (temp-k) % n ;

		end = (temp -1)% n ;

		cout << "Case #"<<(Total - t)<<": ";
		if(start <= end){

			for(int i=start;i<=end;i++)
				cout << a[i] << " ";

		}
 		else
 		{
 			for(int i=0;i<=end;i++)
 				cout << a[i] << " ";

 			for(int i=start;i<n;i++)
 				cout << a[i] << " ";
 		}

 		cout << endl;	

	}

	return 0;

}