#include <bits/stdc++.h>
using namespace std;

long int m[100005];

long int bin(long int start,long int end,long int value){

	long int mid;

	long int temp = value;

	long int index = -1;
	while(start<=end){

		mid = (start+end)/2 ;

		if(m[mid] < value){

			index = mid;
			start = mid + 1;
		}
		else
		{
			end = mid -1;
		}	
	}

	return index;
}
int main()
{
	long int n;
	cin >> n;

	long int a[n];

	


	for(long int i=0;i<n;i++)
		cin >> a[i];

	m[n-1] = a[n-1];

	for(long int i = n-2;i>=0;i--){

			 
			if(a[i] < m[i+1])
				m[i] = a[i];
			else
				m[i] = m[i+1];

	}


	long int ans[n];

	for(int i=0;i<n;i++){

		ans[i] = bin(i+1,n-1,a[i]);

		if(ans[i]!= -1){
			ans[i] = ans[i] - i - 1;
		}

	}

	for(long int i=0;i<n;i++)
		cout << ans[i] << " ";

}