#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n;

	cin >> n;

	int a[n];

	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	sort(a,a+n);

	int pile = 0;

	int above = 0;

	int i =0;

	int sum =0 ;

	while(sum < n){
		
		i = 0;
		above = 0;
		while(i<n){

			if(a[i]!=-1 && a[i]>=above)
			{

				//cout << a[i] << " "; 
				above++;

				a[i] = -1;
				sum++;
			}

			i++;

		}

		pile++;

	}
	cout << pile;






	return 0;
}