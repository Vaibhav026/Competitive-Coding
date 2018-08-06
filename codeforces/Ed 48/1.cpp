#include<bits/stdc++.h>
using namespace std;


int main()
{
	long long int n,m;

	cin >> n >> m;

	long long int a[n];

	for(long int i=0;i<n;i++){
		cin >> a[i];
	}


	long long int curr = 1;
	long long int t;
	long long int sum = 0;

	long long int temp,rem;

	for(long int i=0;i<n;i++){

		sum += a[i];

		temp = sum/m ;

		rem = (sum)%m ;

		if(rem == 0){
			t = temp + 1;
		}
		else{

			long long int z = temp*m;
			
			if(sum > z)
				t = temp + 1;
			else
				t = temp; 	 	
		}	
		

		cout << t-curr << " ";

		curr = t;
		


	}






	return 0;
}