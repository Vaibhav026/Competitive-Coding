#include<bits/stdc++.h>
using namespace std;

void pairsort(int a[], int b[], int n) 
{ 
    pair<int, int> pairt[n]; 
  
    // Storing the respective array 
    // elements in pairs. 
    for (int i = 0; i < n; i++)  
    { 
        pairt[i].first = a[i]; 
        pairt[i].second = b[i]; 
    } 
  
    // Sorting the pair array. 
    sort(pairt, pairt + n); 
      
    // Modifying original arrays 
    for (int i = 0; i < n; i++)  
    { 
        a[i] = pairt[i].first; 
        b[i] = pairt[i].second; 
    } 
} 

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif


    int n;
    cin >> n;
    //cout << n << endl;

    string str[n];

    string x;
    getline(cin , x);

    for(int i=0;i<n;i++){
    	getline (cin, str[i]);
    	//cout << i << " " << str[i] << endl;
    }


    int arr[3];

    cin >> arr[0] >> arr[1] >> arr[2];

    //cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;
    bool friends[8][8];

    for(int i=0;i<8;i++){
    	for(int j=0;j<8;j++)
    		friends[i][j] = false;
    }

    for(int i=0;i<n;i++){

    	int j = 0;

    	string tt1 = "";

    	while(str[i][j] != ' '){
    		tt1 += str[i][j];
    		j++;
    	}

    	j++;

    	while(str[i][j] != ' '){
    		j++;
    	}

    	j++;

    	string tt2 = "";

    	while(j< str[i].length() && str[i][j] != ' '){
    		tt2 += str[i][j];
    		j++;
    	}

    	if(tt1 == "Anka"){

    		if(tt2 == "Chapay"){

    			friends[1][2] = true;
    		}
    		else if( tt2 == "Cleo"){
    			friends[1][3] = true;
    		}
    		else if( tt2 == "Troll"){
    			friends[1][4] = true;
    		}
    		else if( tt2 == "Dracul"){
    			friends[1][5] = true;
    		}
    		else if( tt2 == "Snowy"){
    			friends[1][6] = true;
    		}
    		else{
    			friends[1][7] = true;
    		}

		}
    	else if(tt1 == "Chapay"){

    		if(tt2 == "Anka"){

    			friends[2][1] = true;
    		}
    		else if( tt2 == "Cleo"){
    			friends[2][3] = true;
    		}
    		else if( tt2 == "Troll"){
    			friends[2][4] = true;
    		}
    		else if( tt2 == "Dracul"){
    			friends[2][5] = true;
    		}
    		else if( tt2 == "Snowy"){
    			friends[2][6] = true;
    		}
    		else{
    			friends[2][7] = true;
    		}
    	}
    	else if( tt1 == "Cleo"){

    		if(tt2 == "Anka"){
    			friends[3][1] = true;
    		}
    		else if(tt2 == "Chapay"){

    			friends[3][2] = true;
    		}
    		else if( tt2 == "Cleo"){
    			friends[3][3] = true;
    		}
    		else if( tt2 == "Troll"){
    			friends[3][4] = true;
    		}
    		else if( tt2 == "Dracul"){
    			friends[3][5] = true;
    		}
    		else if( tt2 == "Snowy"){
    			friends[3][6] = true;
    		}
    		else{
    			friends[3][7] = true;
    		}
    	}	
    	else if( tt1 == "Troll"){
    		if(tt2 == "Anka"){
    			friends[4][1] = true;
    		}
    		else if(tt2 == "Chapay"){

    			friends[4][2] = true;
    		}
    		else if( tt2 == "Cleo"){
    			friends[4][3] = true;
    		}
    		else if( tt2 == "Troll"){
    			friends[4][4] = true;
    		}
    		else if( tt2 == "Dracul"){
    			friends[4][5] = true;
    		}
    		else if( tt2 == "Snowy"){
    			friends[4][6] = true;
    		}
    		else{
    			friends[4][7] = true;
    		}
    	}
    	else if( tt1 == "Dracul"){
    		if(tt2 == "Anka"){
    			friends[5][1] = true;
    		}
    		else if(tt2 == "Chapay"){

    			friends[5][2] = true;
    		}
    		else if( tt2 == "Cleo"){
    			friends[5][3] = true;
    		}
    		else if( tt2 == "Troll"){
    			friends[5][4] = true;
    		}
    		else if( tt2 == "Dracul"){
    			friends[5][5] = true;
    		}
    		else if( tt2 == "Snowy"){
    			friends[5][6] = true;
    		}
    		else{
    			friends[5][7] = true;
    		}
    	}
    	else if( tt1 == "Snowy"){
    		if(tt2 == "Anka"){
    			friends[6][1] = true;
    		}
    		else if(tt2 == "Chapay"){

    			friends[6][2] = true;
    		}
    		else if( tt2 == "Cleo"){
    			friends[6][3] = true;
    		}
    		else if( tt2 == "Troll"){
    			friends[6][4] = true;
    		}
    		else if( tt2 == "Dracul"){
    			friends[6][5] = true;
    		}
    		else if( tt2 == "Snowy"){
    			friends[6][6] = true;
    		}
    		else{
    			friends[6][7] = true;
    		}
    	}	
    	else{

    		if(tt2 == "Anka"){
    			friends[7][1] = true;
    		}
    		else if(tt2 == "Chapay"){

    			friends[7][2] = true;
    		}
    		else if( tt2 == "Cleo"){
    			friends[7][3] = true;
    		}
    		else if( tt2 == "Troll"){
    			friends[7][4] = true;
    		}
    		else if( tt2 == "Dracul"){
    			friends[7][5] = true;
    		}
    		else if( tt2 == "Snowy"){
    			friends[7][6] = true;
    		}
    		else{
    			friends[7][7] = true;
    		}
    	}
    }







    sort(arr,arr+3);

    int tmp1 = arr[0];
    int tmp2 = arr[1];
    int tmp3 = arr[2]/5;

    int myints[] = {1,2,3,4,5,6,7};

    int diff1 = max(tmp1,max(tmp2,tmp3)) - min(tmp1,min(tmp2,tmp3));

    tmp1 = arr[0];
    tmp2 = arr[1]/2;
    tmp3 = arr[2]/4;

    int diff2 = max(tmp1,max(tmp2,tmp3)) - min(tmp1,min(tmp2,tmp3));

    tmp1 = arr[0];
    tmp2 = arr[1]/3;
    tmp3 = arr[2]/3;

    int diff3 = max(tmp1,max(tmp2,tmp3)) - min(tmp1,min(tmp2,tmp3));

    tmp1 = arr[0]/2;
    tmp2 = arr[1]/2;
    tmp3 = arr[2]/3;

    int diff4 = max(tmp1,max(tmp2,tmp3)) - min(tmp1,min(tmp2,tmp3));


    int minm = min(diff1,min(diff2,min(diff3,diff4)));

    cout << minm << " ";

    

    	int max_happiness1 = 0;

    	int tmp;
    	do {
   	 		
   	 		tmp = 0;

   	 		for(int i=2;i<7;i++){

   	 			for(int j=i+1;j<7;j++){
   	 				if(friends[myints[i]][myints[j]])
   	 					tmp++;
   	 				if(friends[myints[j]][myints[i]])
   	 					tmp++;
   	 			}
   	 		}

   	 		if(tmp > max_happiness1)
   	 			max_happiness1 = tmp;	

  		} while ( std::next_permutation(myints,myints+7) );

  		//cout << max_happiness;
    

    	int max_happiness2 = 0;

    	//int tmp;
    	do {
   	 		
   	 		tmp = 0;

   	 		if(friends[myints[0]][myints[1]])
   	 			tmp++;

   	 		if(friends[myints[1]][myints[0]])
   	 			tmp++;

   	 		for(int i=3;i<7;i++){

   	 			for(int j=i+1;j<7;j++){
   	 				if(friends[myints[i]][myints[j]])
   	 					tmp++;
   	 				if(friends[myints[j]][myints[i]])
   	 					tmp++;
   	 			}
   	 		}

   	 		if(tmp > max_happiness2)
   	 			max_happiness2 = tmp;	

  		} while ( std::next_permutation(myints,myints+7) );

  		//cout << max_happiness;

    
    

    	int max_happiness3 = 0;

    	//int tmp;
    	do {
   	 		
   	 		tmp = 0;

   	 		for(int i=1;i<4;i++){

   	 			for(int j=i+1;j<4;j++){
   	 				if(friends[myints[i]][myints[j]])
   	 					tmp++;
   	 				if(friends[myints[j]][myints[i]])
   	 					tmp++;
   	 			}
   	 		}
   	 		
   	 		for(int i=4;i<7;i++){

   	 			for(int j=i+1;j<7;j++){
   	 				if(friends[myints[i]][myints[j]])
   	 					tmp++;
   	 				if(friends[myints[j]][myints[i]])
   	 					tmp++;
   	 			}
   	 		}

   	 		if(tmp > max_happiness3)
   	 			max_happiness3 = tmp;	

  		} while ( std::next_permutation(myints,myints+7) );

  		//cout << max_happiness;	


                    
	

		//cout << diff4 << " ";

		int max_happiness4 = 0;

    	//int tmp;
    	do {
   	 		
   	 		tmp = 0;

   	 		for(int i=0;i<2;i++){

   	 			for(int j=i+1;j<2;j++){
   	 				if(friends[myints[i]][myints[j]])
   	 					tmp++;
   	 				if(friends[myints[j]][myints[i]])
   	 					tmp++;
   	 			}
   	 		}

   	 		for(int i=2;i<4;i++){

   	 			for(int j=i+1;j<4;j++){
   	 				if(friends[myints[i]][myints[j]])
   	 					tmp++;
   	 				if(friends[myints[j]][myints[i]])
   	 					tmp++;
   	 			}
   	 		}
   	 		
   	 		for(int i=4;i<7;i++){

   	 			for(int j=i+1;j<7;j++){
   	 				if(friends[myints[i]][myints[j]])
   	 					tmp++;
   	 				if(friends[myints[j]][myints[i]])
   	 					tmp++;
   	 			}
   	 		}

   	 		if(tmp > max_happiness4)
   	 			max_happiness4 = tmp;	

  		} while ( std::next_permutation(myints,myints+7) );

  		//cout << max_happiness;	
	

	int a[4];
	int b[4];

	a[0] = diff1;
	a[1] = diff2;
	a[2] = diff3;
	a[3] = diff4;

	b[0] = max_happiness1;
	b[1] = max_happiness2;
	b[2] = max_happiness3;
	b[3] = max_happiness4;


	pairsort(a,b,4);

	int it =0 ;

	int hap = 0;	
	while(it < 4){

		if(a[it] != minm){
			break;
		}

		if(b[it] > hap){
			hap = b[it];
		}

		it++;
	}

	cout << hap;
	return 0;
}