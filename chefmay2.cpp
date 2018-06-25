#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;


int main()
{	
  int t;
  cin>>t; 

  long int n,k;

    while(t--){

  	cin>>n>>k;

  	int l = floor(log2(k)) ;

  	long int num = 1;
  	for(int i = l;i>=0;i--)
  	{
  		if( num > n)
  		break;
  		
  		cout<<pow(2,i)<<" ";	
  		num++;
  	}	

  	while(num<=n)
  	{
  		cout<<"1"<<" ";
  		num++;
  	}	
  	cout<<endl;
}





 return 0;
}