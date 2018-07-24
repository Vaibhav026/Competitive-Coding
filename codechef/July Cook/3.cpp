#include <bits/stdc++.h>
using namespace std;



int main()
{
	int primes[] = {2,3,5,7,11,13,15,17,19,21,23,29,31};



	int t;
	cin >> t;

	int n;

	int factor[100000][9];

	long int a[100000];

	int ans[13];

	while(t--){

		cin >> n;

		for(int i=0;i<n;i++)
			cin >> a[i];

		for(int i=0;i<13;i++)
			ans[i] = 0;

		for(int i=0;i<n;i++){

			for(int j=0;j<13;j++){

				factor[i][j] = 0;
			}

		}

		for(int i=0;i<n;i++){

			for(int j=0;j<13;j++)
			{

				while(a[i]%primes[j] == 0){

					a[i] = a[i]/primes[j] ;

					factor[i][j]++;
				}
			}	

		}


		int min = 10000;
		int max = -1;
		for(int j=0;j<13;j++){

			for(int i=0;i<n;i++){

				if(factor[i])
				
			}
		}
		// for(int i=0;i<n;i++){

		// 	for(int j=0;j<5;j++)
		// 		cout << factor[i][j] << " ";

		// 	cout << endl;
 	// 	}


		int gcd = 1;

		int d;	
		for(int j=0;j<13;j++){

			d = (ans[j])/(2*n-1) ;

			gcd = gcd*pow(primes[j],d);
		}

		//cout << gcd << endl;

	}









}