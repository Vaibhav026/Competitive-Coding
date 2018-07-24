#include <bits/stdc++.h>
using namespace std;


// C++ program for implementation of Heap Sort
#include <iostream>
using namespace std;
 
// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i,int index[])
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
 		swap(index[i],index[largest]);
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest,index);
    }
}
 
// main function to do heap sort
void heapSort(int arr[], int n,int index[])
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i,index);
 
    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);
 		swap(index[0],index[i]);
        // call max heapify on the reduced heap
        heapify(arr, i, 0,index);
    }
}


int main()
{
	int n , k;
	cin >> n >> k;

	int a[n];
	int index[n];

	int b[n];
	for(int i=0;i<n;i++){
		cin >> a[i];

		b[i] = a[i];
		index[i] = i;
	}

	heapSort(b,n,index);

	int sum = 0;
	int in[k];

	for(int i=n-1;i>=(n-k);i--){
		sum += b[i];
		in[n-1-i] = index[i];
	}

	cout << sum << endl;

	sort(in,in+k);

	// for(int i=0;i<k;i++)
	// 	cout << in[i] << " ";

	// cout << endl;
	int prev = 0;

	int size;
	for(int i=0;i<k;i++){

		if( i == k-1){
			cout << (n-prev);
		}
		else{
		size = in[i] - prev + 1;
		cout << size << " ";

		prev = in[i]+1;
		}
	}

	return 0;
}