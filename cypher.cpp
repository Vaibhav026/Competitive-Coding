#include <iostream>
#include <vector>
#include <string>
using namespace std;




int main()
{
	string s;

	long int a,b;
	cin >> s;
	cin >> a >> b;

	long int l = s.length();

	vector<int> N; 

	int z;
	for(long int i = 0;i<l;i++)
	{
		z =  s[i] - 48 ;
		N.push_back(z);
	}	

	long int modA[l];

	modA[0] = (N[0]%a);

	for(long int i=1;i<l;i++)
	{
		modA[i] = ((10*modA[i-1])%a + (N[i])%a)%a ;
	}

	// for(long int i=0;i<l;i++)
	// cout<<modA[i]<<" ";	
	
	long int modTen[l];

	modTen[0] = (1%b);

	for(long int i=1;i<l;i++)
	{
		modTen[i] =( (10)%b * (modTen[i-1]) ) % b;
	} 

	// for(long int i=0;i<l;i++)
	// cout << modTen[i] << " ";
	
	long int modB[l];

	modB[l-1] = N[l-1]%b;

	for(long int i = l-2;i>=0;i--)
	{	
		modB[i] = ( ( modTen[l-i-1]*(N[i])%b ) %b + modB[i+1] )%b;  

	}

	// for(long int i=0;i<l;i++)
	// cout << modB[i] << " ";

	bool ans = false;
	long int index ;
	for(long int i = 0;i<l-1;i++)
	{
		if(modA[i] == 0 && modB[i+1] == 0 && N[i+1]!=0)
		{
			ans = true;
			index = i;
			break;

		}	
	}  	

	if(ans)
	{	cout << "YES\n";
		
		for(long int i =0;i<=index;i++)
		cout << N[i];

		cout << "\n";

		for(long int i = index+1;i<l;i++)
		cout << N[i]; 	
	}
	else
	cout << "NO";	
	return 0;
}