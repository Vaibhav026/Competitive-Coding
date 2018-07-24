#include <bits/stdc++.h>
using namespace std;



int main()
{
	long int n;
	cin >> n;

	long int a[n];

	for(long int i=0;i<n;i++)
		cin >> a[i];

	long int d;

	if(n == 1)
		cout << "-1";
	else if(n == 2){

		sort(a,a+n);

		d = a[1] - a[0];

		if( d == 0){

			cout << "1\n";
			cout <<a[0];
		}
		else{
		long int num;

		if((a[0]+a[1])%2 == 0)
			num = 3;
		else
			num=2;
		
		cout << num<<"\n";

		cout << a[0]-d << " ";

		if(num ==3)
		cout << (a[0]+a[1])/2 << " ";

		cout << a[1]+d; 
	   }
	}
	else if(n == 3){

		sort(a,a+n);
		long int d1 = a[1]-a[0];
		long int d2 = a[2] - a[1];

		if(d1 == d2){
			
			if( d1 == 0){
 				cout << "1\n";
				cout <<a[0];
			}
			else{
			cout << "2\n";
			cout << a[0]-d1 << " " << a[2]+d1;
			}
		}
		else{

			if(d1 == 2*d2){
				cout << "1\n";

				cout <<  a[0]+d2 ;
			}
			else if(d2 == 2*d1){
				cout << "1\n";

				cout << a[1]+d1 ;
			}
			else
				cout << "0";
		}


	}
	else{

		long int d1,d2,d3;


		sort(a,a+n);

		bool done = false;

		d1 = a[1] - a[0];
		d2 = a[2] - a[1];
		d3 = a[3] - a[2];

		if(d1 == d2){
			d = d1;
		}
		else if(d2 == d3){
			d = d2;
		}
		else if(d1 == d3){
			d = d1;
		}
		else{
			cout << "0";
			done = true;    
		}

		long int dbig;

		long int bindex;

		long int sum = 1;

		bool ans = true;

		for(int i=1;i<n;i++){

			if(a[i]-a[i-1]!= d){
				dbig = a[i]-a[i-1];
				bindex = i;

				if(sum == 2){
					ans = false;
					break;

				}
				sum++;
			}

		}

		if(done == true){
			done = true;
		}
		else if(ans == false){
			cout << "0";
		}
		else if(sum == 1){
			
			if( d == 0){
				cout << "1\n";
				cout <<a[0];
			}
			else{
			cout << "2\n";

			cout << a[0]-d << " " << a[n-1]+d;
			}
		}
		else if(dbig<d)
			cout << "0";
		else if(dbig == 2*d)
		{

			cout << "1\n";

			//cout << a[0]-d << " ";

			cout << a[bindex]-d << " ";

			//cout << a[n-1]+d  << " ";
		}
		else{
			cout << "0";
		} 	


	}











	return 0;
}
		
