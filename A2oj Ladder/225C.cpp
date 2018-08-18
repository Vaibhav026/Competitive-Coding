#include<bits/stdc++.h>
using namespace std;

int n,m,x,y;

long int sum[1001];

int solve(int start,int end,int prev){

	if(start == end+1)
		return 0;

	if(end - start < x-1)
		return INT_MAX;





	if(prev == 0){

		long int temp,temp1,temp2;

		int i = x-1;
		while(i<y && start+i<=end){

			temp1 = sum[start+i] - sum[start-1] + solve(start+i+1,end,1);

			temp2 = (i+1)*(n) - (sum[start+i] - sum[start-1]) + solve(start+i+1,end,2);

			long int t = min(temp1,temp2);

			if(t < temp)
				temp = t;

			i++;	 
		} 

	}
	else{


		if(prev == 1){

			long int temp,temp1,temp2;

			int i = x-1;
			while(i<y && start+i<=end){

				
				temp2 = (i+1)*(n) - (sum[start+i] - sum[start-1]) + solve(start+i+1,end,2);

				long int t = temp2;

				if(t < temp)
					temp = t; 

				i++;
			} 



		}
		else{

			long int temp,temp1,temp2;

			int i = x-1;

			while(i<y && start+i<=end){

				
				temp1 = (sum[start+i] - sum[start-1]) + solve(start+i+1,end,1);

				long int t = temp1;

				if(t < temp)
					temp = t;

				i++;	 
			} 


		}





	}				



}

int main()
{
	

	cin >> n >> m >> x >> y;

	int white_cnt[m+1];

	for(int i=0;i<=m;i++)
		cnt[i] = 0;

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


	solve(1,m,0);	





	return 0;
}