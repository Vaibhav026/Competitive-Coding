#include <bits/stdc++.h>
using namespace std;

int ans = 0;

vector <int> visit;
vector <string> m;

bool visited(long int x)
{	
	int s = visit.size();

	for(int i=0;i<s;i++){

		if(visit[i] == x)
			return true;
	}

	return false;

}
bool isprime(long int n)
{
    // Corner cases
    if (n <= 1)  return false;
    if (n <= 3)  return true;
 
    // This is checked so that we can skip 
    // middle five numbers in below loop
    if (n%2 == 0 || n%3 == 0) return false;
 
    for (long int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
           return false;
 
    return true;
}

void solve(int total,long int prev,int curr,int sl)
{	
	if( curr == total )
	{
		if(!visited(prev) && isprime(prev) ){
			visit.push_back(prev);
			ans++;
			return;
		}
		else
			return;
	}	
	for(int i=0;i<sl;i++){
		
		int z = m[curr][i] - '0' ;
		solve(total,prev+pow(10,total-curr-1)*z,curr+1,sl);
	}

	return;

}	


int main()
{
	

	string s;

	for(int i=0;i<5;i++){
		cin >> s;
		m.push_back(s);
	}

	//vector <int> visited;

	int l = m.size();

	int sl  = m[0].size();
	
	//cout << l <<" "<< sl;


	 solve(l,0,0,sl);

	cout << ans;
	return 0;
}