#include<bits/stdc++.h>
using namespace std;


int main()
{	
	string s1,s2;
	cin >> s1;
	cin >> s2;

	int l = s1.length();

	int count[l];

	for(int i=0;i<l;i++)
	{
		count[i] = 0;

		if(s1[i] == '0')
			count[i]++;

		if(s2[i] == '0')
			count[i]++;

	}

	int i = 0;
	
	int ans = 0;
	while(i<l-1)
	{
		if(count[i] == 2)
		{
			if(count[i+1] == 2)
			{	ans++;
				count[i] = 0;
				count[i+1] = 1;
			}
			else if(count[i+1] == 1){
				ans++;
				count[i] = 0;
				count[i+1] = 0;
			}	
		}
		else if(count[i] == 1)
		{
			if(count[i+1] == 2)
			{	ans++;
				count[i] = 0;
				count[i+1] = 0;
			}
		}
		
		i++;

	}	

	cout<<ans;
	return 0;
}