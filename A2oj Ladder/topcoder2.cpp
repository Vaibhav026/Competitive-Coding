#include <bits/stdc++.h>
using namespace std;


int main()
{	
	int n;
	cin >> n;

	int pcount[1001];
	int ncount[1001];

	for(int i=0;i<1001;i++){
		pcount[i] = 0;
		ncount[i] = 0;
	}
	

    int a[n];								

    for(int i=0;i<n;i++){
    	cin >> a[i];

    	if(a[i]>=0)
    	pcount[a[i]]++;
    	else
    	ncount[-1*a[i]]++;	
    }

    

    int sum = 0;

    int g = -1;
    for(int i=1000;i>1;i--){

    	if(pcount[i] >= 1){

    		if(g == -1){

    			if(pcount[i]%2 == 0){
    				sum += i*i*pcount[i]*(pcount[i]-1)/2 ;
    				g = -1;
    			}
    			else{
                    
                    pcount[i]--;
                    
                    // if(pcount[i] == 0)	
                    // g = -1;
                    // else
                    // g =i;
                    g = i;
                    sum += i*i*pcount[i]*(pcount[i]-1)/2 ; 
    		    }
    		}
    		else
    		{	//cout << i << endl;
    			sum += g*i;
    			//cout << sum<<endl;
    			pcount[i]--;

    			if(pcount[i]%2 == 0){
    				sum += i*i*pcount[i]*(pcount[i]-1)/2 ;
    				g = -1;
    			}
    			else{
                    
                    pcount[i]--;
                    // if(pcount[i] == 0)	
                    // g = -1;
                    // else
                    g =i;

                    sum += i*i*pcount[i]*(pcount[i]-1)/2 ; 
    		    }	 


    		}	

    	}	



    }

    if(g!= -1)
    	sum += g;

    sum += pcount[1];


    	g = -1;
    for(int i=1000;i>=1;i--){

    	if(ncount[i] >= 1){

    		if(g == -1){

    			if(ncount[i]%2 == 0)
    				sum += i*i*ncount[i]*(ncount[i]-1)/2 ;
    			else{
                    
                    ncount[i]--;
                    
                    // if(ncount[i] == 0)	
                    // g = -1;
                    // else
                    g =i;

                    sum += i*i*ncount[i]*(ncount[i]-1)/2 ; 
    		    }
    		}
    		else
    		{
    			sum += g*i;

    			ncount[i]--;
    			if(ncount[i]%2 == 0){
    				sum += i*i*ncount[i]*(ncount[i]-1)/2 ;
    				g = -1;
    			}
    			else{
                    
                    ncount[i]--;
                    
                    // if(ncount[i] == 0)	
                    // g = -1;
                    // else
                    g =i;

                    sum += i*i*ncount[i]*(ncount[i]-1)/2 ; 
    		    }	 


    		}	

    	}	




    }	

    if(g!=-1){

    	if(pcount[0] == 0)
    		sum += -1*g;
    }


    cout << sum;
	return 0;
    	
}