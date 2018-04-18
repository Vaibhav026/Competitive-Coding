#include <iostream>
#include <string>
using namespace std;



int main()
{
   int t;
   cin>>t;

   string s;
   
   long long int n;
   
//   long long int ans;

   long long int l;
   
   long long int diff,suma,sumb;

   long long int ans[1001];

   long long int temp,out;
   while(t--)
   {  
      suma = 0 ;
      sumb = 0 ;
   	  diff = 0;
   	  out = 0;	
   	  cin >> s >> n ; 

   	  l = s.length();

   	  ans[0]=0;
   	  
   	  for(long long int i = 0 ; i<n*l; i++)
	  {
 		if(s[i%l] == 'a')
		suma++;
		else if(s[i%l] == 'b')
		sumb++;

		if(suma>sumb)
        out++;

    	temp = (i+1)/(l) ;

    	if( (i+1)%l == 0 )
    	{	
    		
    		ans[temp] = out ;

    	}	
	 	
	     

    	if( (i+1)%l == 0 && temp >=3  && (ans[temp]-ans[temp-1]) == (ans[temp-1]-ans[temp-2]) )
    	{
    		diff = ans[temp] - ans[temp-1] ;
    		out += diff*(n-temp);
    		
    		break;
    	}


	 		 
	  }






   	  cout << out << endl ;


   }	



 

	return 0;
}