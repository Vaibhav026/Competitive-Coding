#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n;
	cin >> n;

	int p[n+1];

	for(int i=1;i<=n;i++)
		cin >> p[i];

	bool done[n+1];
	for(int i=1;i<=n;i++){

		for(int j=1;j<=n;j++)
			done[j] = false;

		int start = i;

		while(1){

			if(done[start] == true){
				cout << start << " ";
				break;
			}

			done[start] = true;
			start = p[start];

		}



	}












	return 0;
}