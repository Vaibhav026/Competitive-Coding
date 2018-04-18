#include <iostream>
#include <string>
using namespace std;


int main()
{

    int t;
    cin>>t;
   
    long long int d;
   
    long long int compute[32];

    long long int runn;
    string p;
   
    int l ;
    
    int v =1;
    
    while(v<=t){

    	
   	
   	cin >> d ;
   	cin >> p ;
   	l = p.length();

   	
    runn =0 ;
    
    bool ans = false ;

    compute[0] = 1 ; 

    
    	
   	for(int i=0;i<l;i++)
   	{
   		if(p[i] == 'S')
   		{
   			compute[i+1] = compute [i] ;

   			runn += compute[i+1];
   		}
   		else
   		{
   			compute[i+1] = 2*compute[i] ;
   		}	

   	}	

   	if(runn <= d) 
   	{
   		cout << "Case #"<<v<<": 0\n";
   	}	
   	else
   	{
   		int steps = 0;
   		
   		bool noresult = false ;
   		
   		bool flag = false ;

   		while(!flag)
   		{	
   			noresult = true ;

			for(int i = l-1; i>0;i--)
   			{
   				if( p[i] == 'S' && p[i-1] == 'C')
   				{
   					p[i-1] = 'S';
   					p[i] = 'C' ;

   					compute[i] = compute[i-1] ;
   					compute[i+1] = 2 * compute[i] ;

   					runn -= (compute[i+1] - compute[i]) ;
   					noresult = false; 
   					steps ++ ;
   					break ;
    		    }		

			}

			


			if(noresult == true)
			{
				cout << "Case #"<<v<<": IMPOSSIBLE\n";
				break;
			}

			if(runn <= d)
			{
				cout << "Case #"<<v<<": "<<steps<<endl;
				break;	
			}	

   		}	



   	}	
   

    v++;
   

   }	





return 0 ;




}