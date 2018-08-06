#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;

	cin >> n >> m;

	long int a[n];

	for(int i=0;i<n;i++)
		cin >> a[i];


	int val[n];

	bool edge[n];

	for(int i=0;i<n;i++)
		edge[i] = false;

	bool side;
	if(n > 1){

		if(a[1] >= a[0])
			side = true;
		else
			side = false;

		val[0] = 1;
		val[1] = 1;

	}

	for(int i=2;i<n;i++){

		if(a[i] == a[i-1]){
			val[i] = val[i-1];
		}
		else if(side == false){

			if(a[i] > a[i-1]){

				side = true;
				val[i] = val[i-1]+1;
				edge[i-1] = true;
			}
			else{

				val[i] = val[i-1];
			}
		}
		else{

			if(a[i] > a[i-1]){
				val[i] = val[i-1]; 
			}
			else{
				val[i] = val[i-1];
				side = false;
			}
		}


	}




	for(int i=n-1;i>0;i--){

		if(a[i] == a[i-1] && edge[i] == true)
			edge[i-1] = true;
	}

	// for(int i=0;i<n;i++)
	// 	cout << val[i] << " ";

	// cout << endl;

	// for(int i=0;i<n;i++)
	// 	cout << edge[i] << " ";

	int l,r;

	for(int i=0;i<m;i++){

		cin >> l >> r;
		l = l-1;
		r = r-1;

		if(val[l] == val[r])
			cout << "YES\n";
		else{
			if(edge[l] == true && (val[l] == val[r]-1))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}


	return 0;
}