#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a[] = {1,1,0,1,0,0};

	int i=0;

	int end = 5;


	while(i<end){

		if(a[i] == 1){
			swap(a[i],a[end]);
			end--;
		}
		else
			i++;

	}


	for(int j=0;j<=5;j++)
		cout << a[j] << " ";








	return 0;
}