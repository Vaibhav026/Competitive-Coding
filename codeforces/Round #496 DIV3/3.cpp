#include <bits/stdc++.h>
using namespace std;

long int a[120005];

int binarySearch(int l, int r, int x)
{
   if (r >= l)
   {
        int mid = l + (r - l)/2;
 
        // If the element is present at the middle 
        // itself
        if (a[mid] == x)  
            return mid;
 
        // If element is smaller than mid, then 
        // it can only be present in left subarray
        if (a[mid] > x) 
            return binarySearch(l, mid-1, x);
 
        // Else the element can only be present
        // in right subarray
        return binarySearch(mid+1, r, x);
   }
 
   // We reach here when element is not 
   // present in array
   return -1;
}

int main()
{
	long int n;
	cin >> n;

	

	bool ans[n];
	for(int i=0;i<n;i++){

		cin >> a[i];

		ans[i] = false;
	}

	sort(a,a+n);

	long int power[33];

	long int p = 1;

	for(int i=0;i<=32;i++){

		power[i] = p;

		p = p*2;
	}

	long int temp,index;
	for(int i=0;i<n;i++){

		if(ans[i] == true)
			continue;

		for(int j=0;j<=32;j++){

			temp = power[j] - a[i];

			if(temp>=0){

				index = binarySearch(0,n-1,temp);

				if(index == i){

					if(i == 0){
						if(n>=2 && a[i] == a[i+1]){
							index++;
						}
					}
					else if(i == n-1){

						if(a[i] == a[i-1])
							index--;	
					}
					else{
						if(a[i] == a[i-1])
							index--;
						else if(a[i] == a[i+1])
							index++;
					}

				}

				if(index!=-1 && index!= i){
					ans[i] = true;
					ans[index] = true;
					break;
				}
			}
			
		}
	}

	

	long int sum = 0;

	for(int i =0;i<n;i++){

		if(ans[i] == false)
			sum++;
	}


	cout << sum;
	return 0;
}