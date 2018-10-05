#include <bits/stdc++.h>
using namespace std; 



long int a[1000];

long int bruteforce(int start,int end){

	long int ans = a[0];

	long int tmp;

	for(long int i=start;i<end;i++){
		tmp = 0;

		for(long int j=i;j<end;j++){
			tmp += a[j];

			if(tmp > ans)
				ans = tmp;
		}
	}

	return ans;
}

long int recursive(long int start,long int end){

	
	if( start == end ){	
		return bruteforce(start,end);
	}

	long int mid = (start+end)/2;

	long int t1 = recursive(start,mid);

	long int t2 = recursive(mid+1,end);

	long int t3;

	long int back = 0;
	long int front = 0;

	long int i = mid;

	long int tmp = 0;

	long int ans = a[mid] ;

	while(i>=start){

		tmp += a[i];

		if(tmp > ans)
			ans = tmp;

		i--;
	}

	back = ans;

	ans = a[mid+1];

	i = mid + 1;

	tmp = 0;	
	while(i<=end){

		tmp += a[i];

		if(tmp > ans)
			ans = tmp;

		i++;
	}

	t3 = back + ans;

	return( max( max(t1,t2), t3 ));
}

int main()
{	
	// #ifndef ONLINE_JUDGE
 //    // for getting input from input.txt
 //    freopen("input.txt", "r", stdin);
 //    // for writing output to output.txt
 //    freopen("output.txt", "w", stdout);
 //    #endif


	long int n = 2;

	for(long int i=0;i<1000;i++){
		a[i] = rand()%100;
	}

	// for(long int i=0;i<n;i++){
	// 	cout << a[i] << " "; 
	// }

	

	while(n<1000){
	clock_t t = clock();
		
	long int max1 = bruteforce(0,n);

	t = clock() - t;

	double diff1 = (double) t/CLOCKS_PER_SEC;

	//cout << diff1 << endl;

	t  = clock();	

	long int max2 = recursive(0,n-1);

	t = clock()-t;

	double diff2 = (double) t/CLOCKS_PER_SEC ;

	cout << diff1 << " " << diff2 << endl;
	if(diff1 > diff2){
		cout << "ans =" << n ;
		break;
	}
	
	n++;
	}		
	


	return 0;
}