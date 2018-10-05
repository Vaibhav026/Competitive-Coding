
#include <bits/stdc++.h>
using namespace std;


int main()
{
	int n;

	cin >> n;

	long int app[100001];

	for(int i=0;i<=100001;i++)
		app[i] = 0;

	long int x,y;

	cin >> x >> y;

	int tmp = 0;

	for(long int j=1; j*j <= x;j++){

		if(x%j == 0){

			app[j] = 1;
			tmp++;

			if(x/j != j){
				app[x/j] = 1;
				tmp++;
			} 
		}
	}

	cout << tmp << endl; 


	for(long int i =2;i<=n;i++){

		tmp = 0;
		cin >> x >> y;

		for(long int j=1;j*j<= x;j++){

			if(x%j == 0){

				if(app[j] < (i-y)){
					tmp++;
				}

				app[j] = i;

				long int v = x/j;

				if( v!= j){

					if(app[v] < (i-y)){
						tmp++;
					}

					app[v] = i;
				
				}
			}
		}

		cout << tmp << endl;
	}











	return 0;
}