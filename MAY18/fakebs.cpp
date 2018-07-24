#include <bits/stdc++.h>
using namespace std;

long int a[100000];

long int duplicate[100000];

int binarysearch(int n,int x)
{	
	int low = 0;

	int high = n-1;

	int mid;
	while(low<=high){

		mid = (low+high)/2;

		if(duplicate[mid] == x)
			return mid;
		else if(duplicate[mid] > x)
			high = mid -1;
		else
			low = mid+1;

	}

	return -1;
}

// C++ program for implementation of Heap Sort
#include <iostream>
using namespace std;
 
// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
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
void heapSort(int arr[], int n)
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
	int t;
	cin >> t;

	long int n,q;

	long int index	

	while(t--){


		cin >> n >> q;

		for(int i=0;i<n;i++){
			cin >> a[i];
			b[i] = a[i];
		}








	}






















	return 0;
}