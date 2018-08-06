#include <bits/stdc++.h>
using namespace std;


int main()
{	
	long int n;

	cin >> n;

	long int a[n],b[n];	

	for(int i=0;i<n;i++){
		cin >> a[i];

		b[i] = a[i];
	}	

	sort(b,b+n);

	int sw = 0;
	for (int i = 0; i <n ; i++)
	{
		if(a[i] != b[i])
			sw++;
		//cout << a[i] << " " << b[i] << endl;

	}

	//cout << sw;
	if(sw <= 2){
		cout << "YES";
	}
	else
		cout << "NO";








	return 0;
}