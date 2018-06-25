#include <bits/stdc++.h>

using namespace std;



int main()
{
	string s;

	cin >> s;

	long int l = s.length();

	long int even_a,even_b,odd_b,odd_a;

	even_a = 0;
	even_b = 0;
	odd_a = 0;
	odd_b = 0;
	for(long int i=0;i<l;i++)
	{
		if(s[i] == 'a')
		{	
			if(i%2 == 0)
			even_a++;
			else
			odd_a++;	
		}
		else
		{
			if(i%2 == 0)
			even_b++;
			else
			odd_b++;	
		}	
	}


	long long int evenans,oddans;

	evenans = even_a*odd_a + even_b*odd_b ;	

	oddans = odd_a*(odd_a-1)/2 + even_a*(even_a-1)/2 + odd_b*(odd_b-1)/2 + even_b*(even_b-1)/2  + l;



	cout << evenans << " " << oddans;







	return 0;
}