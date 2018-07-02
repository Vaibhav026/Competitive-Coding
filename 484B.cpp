// Problem Name - Maximum value Round 276

#include <bits/stdc++.h>
using namespace std;

 int max( int a, int b)
{
	if(a<=b)
		return b;
	else
		return a;
}


void heapify(int arr[], int n, int i)
{
    int largest = i;  // Initialize largest as root
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
 
// main function to do heap sort
void heapSort( int arr[],  int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}
int main()
{
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
	#endif	


	int n;

	cin >> n;



	  int a[n];

	for(  int i=0;i<n;i++)
		cin >> a[i];

	heapSort(a,n);


	  int maxi = 2*a[n-1];

	  int lower[maxi+1];

	for( int i=0;i<=maxi;i++)	
		lower[i] = -1;

	for( int i=0;i<n;i++)	
		lower[a[i]] = a[i];

	 int temp = a[0];

	for( int i = a[0]+1;i<=maxi;i++){

		if(lower[i] == -1)
			lower[i] = temp;
		else
			temp = lower[i];
	}

	 int ans = 0;



	 if(a[0] == a[n-1])
	 	cout << "0";
	 else{
	for( int i=0;i<n;i++)
	{	

		 if(i!=0 && a[i] == a[i-1])
		 	continue;
		 		
		 int t = 2*a[i];

		while(t <= maxi){

			int x = lower[t];
				
			if(x == t)
				x =lower[t-1];

			int mod = x%a[i];
			ans = max(ans,mod);

			t = t + a[i];

		}

	}

	cout << ans;	
	}




	return 0;
}