#include<bits/stdc++.h>
using namespace std;



int main(){

	long int n,m,x,y;

	cin >> n >> m >> x >> y;

	long int white_cnt[m+1];

	long int sum[n+1];

	for(int i=0;i<=m;i++)
		white_cnt[i] = 0;

	char ch;

	for(int i=1;i<=n;i++){

		for(int j=1;j<=m;j++){

			cin >> ch;

			if(ch == '.')
				white_cnt[j]++;

		}
	
	}

	sum[0] = 0;

	for(int i=1;i<=m;i++)
		sum[i] = sum[i-1] + white_cnt[i];


	long int w_dp[m+5];

	long int b_dp[m+5];


	w_dp[m+1] = 0;
	b_dp[m+1] = 0;

	

	int siz = 0;
	
	while(siz < x-1){
		w_dp[m-siz] = -1;
		b_dp[m-siz] = -1;

		siz++;
	}

	for(long int i=m-x+1;i>0;i--){

		long int j = x-1;

		long int temp = 1000000000;
		long int temp1;

		

		

		while(j<y && (i+j)<= m ){

			temp1 =( (j+1)*n - (sum[i+j] - sum[i-1]) ) + w_dp[i+j+1];

			

			if(w_dp[i+j+1] != -1 && temp1 < temp)
				temp = temp1;

			j++;	 
		} 

		b_dp[i] = temp;

		
		 j = x-1;

		temp = 1000000000;

		while(j<y && (i+j)<=m ){

			temp1 = sum[i+j] - sum[i-1] + b_dp[i+j+1];

			

			if(b_dp[i+j+1] != -1 && temp1 < temp)
				temp = temp1;

			j++;	 
		} 

		w_dp[i] = temp;
	}


	// for(int i=1;i<=m;i++){
	// 	cout << w_dp[i] << " "; 
	// }
	// cout << endl;
	
	// for(int i=1;i<=m;i++){
	// 	cout << b_dp[i] << " "; 
	// }

//	cout << min(w_dp[1],b_dp[1]);

	if(w_dp[1]<b_dp[1])
		cout << w_dp[1];
	else
		cout << b_dp[1];

	// cout << "A";




	return 0;
}