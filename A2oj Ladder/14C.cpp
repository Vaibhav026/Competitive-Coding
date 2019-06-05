#include <bits/stdc++.h>
using namespace std;


int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif

    long long x1[4],y1[4],x2[4],y2[4];

    bool line[4];

    int xnum = 0;
    int ynum = 0;

    for(int i=0;i<4;i++){
    	cin >> x1[i]  >> y1[i] >> x2[i] >> y2[i];
    }

    for(int i=0;i<4;i++){
	    
	    if(x1[i] == x2[i] && y1[i]!= y2[i] ){
	    	line[i] = false;
	    	ynum++;
	    }
	    else if(y1[i] == y2[i] && x1[i] != x2[i]){
	    	line[i] = true;
	    	xnum++;
	    }
	    else{
	    	cout << "NO";
	    	return 0;
	    }
	}    

	if(xnum == 2 && ynum == 2){

		set <pair<long long,long long> > s;

		set <pair<long long,long long> > sx;

		set <pair<long long,long long> > sy;

		for(int i=0;i<4;i++){
    		s.insert(make_pair(x1[i],y1[i]));
    		s.insert(make_pair(x2[i],y2[i]));

    		if(line[i]){
    			sy.insert(make_pair(x1[i],y1[i]));
    			sy.insert(make_pair(x2[i],y2[i]));
    		}
    		else{
    			sx.insert(make_pair(x1[i],y1[i]));
    			sx.insert(make_pair(x2[i],y2[i]));	
    		}
    	}			

    	if(s.size() == 4 && sx.size() == 4 && sy.size() == 4){
    		cout << "YES";
    	}
    	else
    		cout << "NO";
	}
	else{
		cout << "NO";
		return 0;
	}


	return 0;
}