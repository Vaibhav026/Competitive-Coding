#include <iostream>
#include <cstring>
using namespace std;

long int match(string s,long int i,long int j,long int l)
{
	long int sum = 0;

	while(i<l && j<l && s[i] == s[j])
	{
		i++;
		j++;

		sum++;
	}	

	return sum;
}


long int Z[1000001];
void getZarr(string str)
{
    long int n = str.length();
    long int L, R, k;
 
    // [L,R] make a window which matches with prefix of s
    L = R = 0;
    for (long int i = 1; i < n; ++i)
    {
        // if i>R nothing matches so we will calculate.
        // Z[i] using naive way.
        if (i > R)
        {
            L = R = i;
 
            // R-L = 0 in starting, so it will start
            // checking from 0'th index. For example,
            // for "ababab" and i = 1, the value of R
            // remains 0 and Z[i] becomes 0. For string
            // "aaaaaa" and i = 1, Z[i] and R become 5
            while (R<n && str[R-L] == str[R])
                R++;
            Z[i] = R-L;
            R--;
        }
        else
        {
            // k = i-L so k corresponds to number which
            // matches in [L,R] interval.
            k = i-L;
 
            // if Z[k] is less than remaining interval
            // then Z[i] will be equal to Z[k].
            // For example, str = "ababab", i = 3, R = 5
            // and L = 2
            if (Z[k] < R-i+1)
                Z[i] = Z[k];
 
            // For example str = "aaaaaa" and i = 2, R is 5,
            // L is 0
            else
            {
                // else start from R and check manually
                L = i;
                while (R<n && str[R-L] == str[R])
                    R++;
                Z[i] = R-L;
                R--;
            }
        }
    }
}
 

int main()
{
	string s;
	cin>>s;

	getZarr(s);
	long int l = s.length();

	// long int z[l];

	// z[0] = 0;

	// long int start = -1 , end = -1 ;

	// z[1] = match(s,0,1,l);

	// for(long int i=2;i<l;i++)
	// {
	// 	if(start<i && i<end && z[i-start] + i -1 < end)
	// 	{	

	// 		z[i] = z[i-start];
	// 	}	
	// 	else
	// 	{
	// 		start = i;

			 
	// 		if(end == -1 || i == end )
	// 		{	
	// 			long int temp = match(s,0,start,l) ;
				
	// 			if( temp == 0)
	// 			{  end = -1;
	// 			   z[i] = 0 ;
	// 			}
	// 			else	
	// 			{	end = start + temp - 1;

	// 				z[i] = temp;
	// 			}	
	// 		}
	// 		else
	// 		{   end += match(s,end-start+1,end+1,l);
	// 		    z[i] = end-start +1;
	// 		}

	// 		if(start == end)
	// 		end = -1;			     
	// 	}	


	// }	

	long int ans = 0;
	long int index = -1;

	long int suffix = 0;
	for(long int i =1 ;i<l-1;i++)
	{	
		//cout << z[i] << " ";
		if(Z[i] > ans )
		{	
			
			ans = Z[i];
			index = i;
			
			if( i+Z[i]-1 == l-1 )
			ans = ans -1;	
	

		}
	
	}	

	long int suff = 0;
	for(long int i =1 ;i<l;i++)
	{	
		// cout << z[i] << " ";
		if(Z[i]<= ans && Z[i] > suff  && i+Z[i]-1 == l-1)
		{	
			
			suff = Z[i];
			index = i;
			
		}
	
	}

	long int in=0;
	if(suff>0)
	{
		while(suff--)
		{
			cout<<s[in];
			in++;
		}	
	}	
	else
	{
		cout<<"Just a legend";
	}	






	return 0;
}
