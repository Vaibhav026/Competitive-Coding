#include <bits/stdc++.h>
using namespace std;


int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif

	string str;

	cin >> str;

	

	stack< pair<char,int> > stck;

	int i=0;
	int l = str.length();

	bool done = true;

	map<int,int> mp;

	int val[l];

	for(int i=0;i<l;i++)
		val[i] = -1;

	while(i<l){

		if(stck.size() == 0){
			
			if(str[i] == '(' || str[i] == '['){
				

				stck.push(make_pair(str[i],i));
			}
			
		}
		else{

			if( (stck.top()).first == '(' ){

				if(str[i] == ')'){
					val[stck.top().second] = i;
					stck.pop();

				}
				else if(str[i] == '(' || str[i] == '['){
					stck.push(make_pair(str[i],i));
				}
				else{

					
					while(!stck.empty()){
						stck.pop();
					}	
					
						
				}
			}
			else{

				if(str[i] == ']'){
					
					val[stck.top().second] = i;
					//num++;
					stck.pop();
				}
				else if(str[i] == '(' || str[i] == '['){
					stck.push(make_pair(str[i],i));
				}
				else{

					while(!stck.empty()){
						stck.pop();
					}	
					
				}

			}	


		}


		i++;
	}

	
	i = 0;


	
	
	int start = -2;
	int end = -2;

	int prev_num = 0;
	
	int prev_start = -2;
	int prev_end = -2;


	int num = 0;
    
    
    
	while(i < l){

		//cout << i <<" "<< val[i] << "/n";
		
		
		if(val[i] != -1){
            
            //cout << "ha" <<  endl;
            
			if(end + 1 == i){

				end = val[i];
			}
			else{
				start =  i;
            	end = val[i];	
			}
            
			for(int j=i;j<=val[i];j++){
				if(str[j] == '['){
					num++;
				}
			}

			

			if(num > prev_num){
				    //cout << num <<  "ha" << endl;
				prev_num  = num;
				prev_start = start;
				prev_end = end;
			}

			
			
			i = val[i] + 1;
			
			//cout << "vv " << i << endl;
		}
		else{
			i++;
			num = 0;
		}
	}
    
    
	
		cout << prev_num << endl;

		if(prev_num == 0)
			return 0;

		for(int j = prev_start;j<=prev_end;j++){
			cout << str[j];
		}
	


	return 0;
}