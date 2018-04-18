#include <iostream>
#include <algorithm>
using namespace std;


int main()
{

	int t;
	cin>>t;

	long int n;

	int a[100001];

	long int nhash[1001];
	long int phash[1001];

	int noduplicate[2001];

    long long int ans;
	int j;
	while(t--)
	{	 
        ans = 0;
		j=0;
		for(int i=0;i<=1000;i++)
		{ nhash[i]=0;	
          phash[i]=0;	
        } 
		cin>>n;

		for(int i=1;i<=n;i++)
		{
			cin >> a[i] ;

			if(a[i]>=0)
			{
				phash[a[i]]++ ;         // maintains count of positive and negative numbers
			}
			else
			{
				nhash[abs(a[i])]++;
			} 	
		}

       
        for(int i=0;i<=1000;i++)
        {
        	if(phash[i] != 0)
        	{   
                ans += phash[i]*(phash[i]-1)/2 ;   
        		noduplicate[j] = i ;
        		j++; 
        	}

        	if(nhash[i] != 0)
        	{   
                ans += nhash[i]*(nhash[i]-1)/2 ;   
        		noduplicate[j] = -1*i ;
        		j++; 
        	}	
        }	


        for(int i=0;i<j;i++)
        {

        	for(int k=i+1;k<j;k++)
        	{	
        		int temp = noduplicate[i] + noduplicate[k];
        		
        		long int c1,c2;

        		if(noduplicate[i]>=0)
        		c1= phash[noduplicate[i]];
        		else	
        		c1 = nhash[(-1*noduplicate[i])];	

        		if(noduplicate[k]>=0)
        		c2 = phash[noduplicate[k]];
        		else	
        		c2 = nhash[(-1*noduplicate[k])];


        		if(temp % 2 == 0)
        		{
        			if(temp >=0 && phash[temp/2] > 0 )
        			{    //cout << noduplicate[i] <<" "<<noduplicate[k]<<endl;
        				ans+= c1*c2 ; 
        			}
        			else if(temp<0  && nhash[abs(temp/2)] > 0)
        			{   //cout << noduplicate[i] <<" "<<noduplicate[k]<<endl;
        				ans += c1*c2;
        			}	
        		}	
        	}	
        }	



        cout << ans <<endl ;

	}	










	return 0;
}