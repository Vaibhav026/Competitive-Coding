#include <bits/stdc++.h>
using namespace std;



int main()
{
	long int t,n;

	long int a[100002];

	long int b[100002];

	cin >> t;

	while(t--){


		cin >> n;

		a[n+1] = 1000000001;
		a[0] = 1000000001;
		b[0] = a[0];
		b[n+1] = a[n+1];

		for(int i=1;i<=n;i++){
			cin >> a[i];
			b[i] = a[i];
		}

		for(int i=1;i<=n;i++){
			
			if(b[i]<b[i-1] && b[i]<b[i+1]){

				b[i] = -1*b[i];
				a[i] = b[i];
				b[i+1] += b[i]; 
			}
		}


		for(int i=1;i<=n;i++)
			cout << a[i] << " ";

		cout << endl;

	}














	return 0;
}