#include <iostream>
#include <vector>
#include <string>
using namespace std;



int main()
{	
	vector<char> c;
	vector<long int> freq;

	string s;
	cin >> s;

	long int l = s.length();

	c.push_back(s[0]);
	freq.push_back(1);

	long int j=0;

	for(long int i =1;i<l;i++)
	{  
        if( s[i-1] == s[i])
        {
        	freq[j]++;
        }
        else
        {
        	c.push_back(s[i]);
        	freq.push_back(1);
        	j++;
        }	
	}	

	long int steps = 0;
	for(long int i=0;i<=j;i++)
	{
		if(freq[i]>2)
		{  	
			freq[i] = 2;
		}	
	}	

	for(long int i=1;i<=j;i++)
	{
		if(freq[i] == 2 && freq[i-1] == 2)
		{
			freq[i] = 1;
			
		}	
	}

	long int it = 0 ;
	
	while(it<=j)
	{
		while(freq[it])
		{
			cout<<c[it];
			freq[it]--;
		}
		
		it++;	
	}	
	
	return 0;
}