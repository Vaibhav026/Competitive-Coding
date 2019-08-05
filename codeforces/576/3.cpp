#include <bits/stdc++.h>
using namespace std;




int main(){

	#ifndef ONLINE_JUDGE    
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif


	long int n,I;

	cin >> n >> I;

	long int a[n];

	for(int i=0;i<n;i++)
		cin >> a[i];

	sort(a,a+n);

	vector<long int> values;

	vector<long int> cnt;

	values.push_back(a[0]);
	cnt.push_back(1);

	int j = 0;

	for(int i = 1; i < n; i++ ){

		if(a[i] == a[i-1]){
			cnt[j]++;
		}
		else{
			values.push_back(a[i]);
			cnt.push_back(1);
			j++;
		}
	}

	long int num = values.size();

	// cout << num << endl;

	if(num == 1){
		cout << "0";
		return 0;
	}

	long int sum_array[num];

	sum_array[0] = cnt[0];

	for(int j = 1; j < num ; j++ ){
		sum_array[j] = sum_array[j-1] + cnt[j]; 
	}

	// cout << sum_array[1] << endl;

 	long int start,end;

 	long int minn = n;


 	for(int i = 0 ; i < num ; i++ ){

 		// l  = i 
 		// range of r
 		start = i;
 		end = num-1;

 		while( start <= end ){

 			long int mid = (start + end)/2;

 			long double bits_req;

 			if( i == 0 ){
 				bits_req = (long double) ceil(  log2(mid-i+1)) *((long double)n) ;
 			}
 			else{
 				bits_req = (long double) ceil(  log2(mid-i+1) )*((long double)n);
 			}

 			bits_req = ceil(bits_req);

 			 // cout << bits_req << endl;
 			if(  bits_req  <= (I*8) ){

 				long int changes = 0;

 				changes += (sum_array[i] - cnt[i]);

 				changes += (sum_array[num-1] - sum_array[mid]);

 				if(changes  < minn){
 					minn = changes;
 				}

 				start = mid +1;
 			}
 			else{
 				end = mid-1;
 			}
 		}


 	}

 	cout << minn;
	return 0;
}	