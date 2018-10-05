#include <bits/stdc++.h>
using namespace std;


int partition(int arr[],int x,int n){

	int start = 0;
	int end = n;

	while((start+1) < (end-1) ){

		if(arr[end-1] <= x){
			swap(arr[start+1],arr[end-1]);
			start += 1;
		}
		else
			end -= 1;
	}


	if((start+1)<n && arr[start+1] <= x)
		start++;

	if((start+1)<n && arr[start+1] <= x)
		start++;

	return start;
}

int main()
{
	int n;

	cin >> n;

	int a[n];

	for(int i=0;i<n;i++)
		cin >> a[i];

	int index = partition(a,a[0],n);

	cout << index << endl;

	for(int i=0;i<n;i++)
		cout << a[i] << " ";



	return 0;
}