#include <iostream>
using namespace std;

 
// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(long int arr[], long int n, long int i,long int index[])
{
    long int largest = i;  // Initialize largest as root
    long int l = 2*i + 1;  // left = 2*i + 1
    long int r = 2*i + 2;  // right = 2*i + 2
 
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
void heapSort(long int arr[], long int n,long int index[])
{
    // Build heap (rearrange array)
    for (long int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i,index);
 
    // One by one extract an element from heap
    for (long int i=n-1; i>=0; i--)
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
	int k;
	long int n;
	cin >> n>>k;

	long int p[n];

	long int c[n];

	long int index[n];

	for(long int i=0;i<n;i++)
	{
		cin >> p[i];
		index[i] = i;
	}	

	for(long int i=0;i<n;i++)
	{
		cin >> c[i];
	}

	long long int ans[n];

	heapSort(p,n,index);

	long int min = c[index[0]];
	
	ans[index[0]] = min;

	long int inside[10];

	long long int sum = min;

	inside[0] = min;

	int min_index;
	for(long int i=1;i<n-1;i++)
	{
		if(i<k)
		{	inside[i] = c[index[i]];

			ans[index[i]] = sum + c[index[i]];
			sum += c[index[i]];

			if(i == k-1)
			{
				ans[index[k]] = sum + c[index[k]];
			}

		}	
		else
		{	


			min = inside[0];
			min_index = 0;
			sum = 0;
			for(int j=0;j<k;j++)
			{	
				sum += inside[j];
				if(inside[j]<min)
				{
					min = inside[j];
					min_index = j;
				}	
			}

			if(i == k)
			{
				ans[index[i]] = sum + c[index[i]];
			}

			if(min<c[index[i]])
			{
				sum = sum - min + c[index[i]];
				inside[min_index] = c[index[i]];
				ans[index[i+1]] = sum + c[index[i+1]];
			}
			else
			{
				ans[index[i+1]] = sum + c[index[i+1]];
			}	

		}	


	}	
	if(k==0)
	{	
		for(long int i=0;i<n;i++)
		cout<<c[i]<<" ";
	}
	else
	{	
		for(long int i=0;i<n;i++)
		cout<<ans[i]<<" ";	
	}
	return 0;
}