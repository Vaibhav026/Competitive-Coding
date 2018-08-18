#include<bits/stdc++.h>
using namespace std;

int main()
{	int n,m;
	cin >> n >> m;

	priority_queue < pair<long int,int> > pq;

	int p;
	long int c;

	long int cnt[m+1];

	for(int i=1;i<=n;i++){

		cin >> p >> c;

		if( p == 1)
			cnt[1]++;
		else{
			cnt[p]++;
			pq.push(make_pair(c,p));
		}

	}


	
	return 0;
}