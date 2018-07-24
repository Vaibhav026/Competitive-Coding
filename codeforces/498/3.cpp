#include <bits/stdc++.h>
using namespace std;

long long int fw[200005];

long long int bc[200005];

long long int binarySearch(long int l, long int r, long long int x)
{
   if (r >= l)
   {
        long int mid = l + (r - l)/2;
 
        // If the element is present at the middle 
        // itself

        //cout << bc[mid] << " " << x << endl;
        if (bc[mid] == x)  
            return mid;
 
        // If element is smaller than mid, then 
        // it can only be present in left subarray
        if (bc[mid] > x) 
            return binarySearch( mid+1, r, x);
 
        // Else the element can only be present
        // in right subarray
        return binarySearch( l, mid-1, x);
   }
 
   // We reach here when element is not 
   // present in array
   return -1;
}	

int main()
{

	long int n;
	cin >> n;

	long int d[n];	


	for(long int i=0;i<n;i++)
		cin >> d[i];

	fw[0] = d[0];

	for(long int i=1;i<n;i++){

		fw[i] = fw[i-1] + d[i];
	}	

	bc[n-1] = d[n-1];

	for(long int i=n-2;i>=0;i--){

		bc[i] = bc[i+1] + d[i]; 
	}	

	// for(long int i=0;i<n;i++){

	// 	cout << fw[i] << " " << bc[i] << endl;
		
	// }	

	long long int sum = 0;

	for(int i=n-2;i>=0;i--){

		//cout << fw[i] << endl;	
		if(binarySearch(i+1,n-1,fw[i]) != -1 ){
			sum = fw[i];
			break;
		}

	}


	cout << sum;
	return 0;
}
