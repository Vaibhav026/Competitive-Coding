#include <bits/stdc++.h>
using namespace std;


int main()
{
	long int m;
	int n;

	cin >> m >> n;

	bool seq[n];

	int x;

	for(int i=0;i<n;i++){

		cout << m;

		fflush(stdout);
		
		cin >> x;

		if(x == 0){
			exit(0);
		}
		else{

			if(x == -1)
				seq[i] = true;
			else
				seq[i] = false;
		} 

	}

	long int l =1,r = m;

	long int cnt = 0;

	long int mid;
	  	
	while(l<=r){

		mid = (l+r)/2 ;

		cout << mid;

		fflush(stdout);

		cin >> x;


		if(x == 0)
			exit(0);
		else{


			if(x == -1){

				if(seq[cnt])
					r = mid-1;
				else
					l = mid+1;

				cnt++;
			}
			else{

				if(seq[cnt])
					l = mid+1;
				else
					r = mid-1;

				cnt++;
			}



		}



	}








	return 0;
}