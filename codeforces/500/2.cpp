#include <bits/stdc++.h>
using namespace std;


int main()
{
	long int n,x;

	cin >> n >> x;

	long int a[n];

	long int cnt[100001];		

	for(int i=0;i<=100000;i++)
		cnt[i] = 0;

	for(int i=0;i<n;i++){

		cin >> a[i];

		
		cnt[a[i]]++;
	}

	//cout << endl;

	bool a1 = false;

	for(int i=0;i<=100000;i++){
		if(cnt[i] > 1){
			a1 = true;
			break;
		}

	}
		

	if(a1){
		cout << "0";
	}
	else{

		long int z;

		bool r2 = false;

		for(int i=n-1;i>=0;i--){

			//cout << a[i] << " ";
			z = a[i]&x;

			
			if(z!=a[i] && cnt[z] >= 1){
					
				r2 = true;
				break;
			}
		}

		//cout << endl;

		if(r2)
			cout << "1";
		else{

			bool a3 = false;

			for(int i=n-1;i>=0;i--){

				z = a[i]&x;

				if(z!=a[i])
					cnt[z]++;
			}

			for(int i=0;i<=100000;i++){
				
				if(cnt[i] > 1){
					a3 = true;
					break;
				}

			}


			if(a3)
				cout << "2";
			else
				cout << "-1";

		}



	}	


	






	return 0;
}

