#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main()
{
	string s1,s2;

	cin>>s1>>s2;

	int l1 = s1.length();

	int l2 = s2.length();

	int m = min(l1,l2);

	vector <int> factors;

	for(int i = 1 ; i*i <= m ;i++)
	{
		if(m%i == 0)
		{
			factors.push_back(i);

			if(m != i*i)
			factors.push_back(m/i);	
		}

	}

	int f1,f2;

	int ans = 0 ;
	for(int i=0;i<factors.size();i++)
	{	
		string temp1,temp2;
		if(l1 % factors[i] == 0 && l2 % factors[i] == 0)
		{	
			
			bool flag = true;
			temp1 = s1.substr(0,factors[i]);

			

			for(int j = 0;j< l1;j++)
			{
				if(temp1[j%factors[i]] != s1[j])
				flag = false;	
			}

			for(int j = 0;j< l2;j++)
			{
				if(temp1[j%factors[i]] != s2[j])
				flag = false;	
			}

			if(flag)
			ans++;	

				
		}	

	}


	cout<<ans;

	return 0;
}