#include<bits/stdc++.h>
using namespace std;

int main()
{	
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);
    #endif

	int a[] = {6,6,7,8,9,10};

	int low = 1;

	int high = 5;

	int key = 10;

	while(low <= high){

		int mid = ((low+high)/2);

		if(a[mid] == key){
			cout << "Done";
			return 0;
		}
		else if(a[mid] < key)
			low = mid-1;
		else
			high = mid+1;

	}



	return 0;
}