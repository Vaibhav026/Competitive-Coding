#include <iostream>
using namespace std;

int b[9];

int sum;

void check(int a[],int b[],int n,int k)
{	
	bool ans = true;

	int greater = 0;

	for(int i=0;i<n;i++)
	{
		if(!(b[i] == 0 || a[i] == b[i]))
		{	ans = false;
			break;
		}	
	}

	if(ans)
	{
		for(int i=1;i<n;i++)
		{
			if(a[i] > a[i-1])
				greater++;
		}

		if(greater == k)
		sum++;	
	}	
}


void heapPermutation(int a[], int size, int n,int k)
{
    // if size becomes 1 then prints the obtained
    // permutation
    if (size == 1)
    {
        //printArr(a, n);
        check(a,b,n,k);
        return;
    }
 
    for (int i=0; i<size; i++)
    {
        heapPermutation(a,size-1,n,k);
 
        // if size is odd, swap first and last
        // element
        if (size%2==1)
            swap(a[0], a[size-1]);
 
        // If size is even, swap ith and last
        // element
        else
            swap(a[i], a[size-1]);
    }
}

int main()
{
	int t,n,k;

	cin >> t;

	int a[9];

	while(t--){

		sum = 0;
		cin >> n >> k;

		for(int i=0;i<n;i++)
		cin >>b[i];
			
		for(int i=0;i<n;i++)
		a[i] = i+1;
		
		heapPermutation(a,n,n,k);	
		cout << sum<<endl;

	}

	return 0;
}