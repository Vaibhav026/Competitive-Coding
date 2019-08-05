#include <bits/stdc++.h>
using namespace std;



int val[12][12] = {-1};

vector<string> ans[12][12];

string a,b;
int l1,l2;

int solve(int i,int j){
  
  // case when i/j exceeds the string length
  if((i)>= l1 && (j) >= l2){
      return 0;
  }
  else if( (i) >= l1 ){
    return (l2-j);
  }
  else if( j >= l2 ){
    return (l1 - i);
  }
  
  if(val[i][j] != - 1){
    return val[i][j];
  }
  
  if(a[i] == b[j]){
    
    val[i][j] = solve(i+1,j+1);
    
    string tmp = "";
    tmp += a[i];

    // cout  << a[i] << endl;
    ans[i][j].push_back( tmp );
    // have to keep a check on index here
    if( (i+1) >= l1 && (j+1) >= l2 ){
      ;
    }
    else if( (i+1) >= l1 ){
      for(int k = j+1 ; k < l2;k++){
      	string tmp = "+";
      	tmp += b[k];
        ans[i][j].push_back(tmp);
      } 
    }
    else if( (j+1) >= l2 ){
       
      for(int k = i+1 ; k < l1;k++){
      	  string tmp = "-";
      	  tmp += a[k];	
          ans[i][j].push_back(tmp);
       } 
    
    }
    else{
        for(int v = 0 ; v < ans[i+1][j+1].size() ; v++)
          ans[i][j].push_back(ans[i+1][j+1][v]);  
    }
    
    
  }
  else{
      
      
      int tp1 = 1 + solve(i+1,j);
    
      int tp2 = 1 + solve(i,j+1);
    
      if(tp1 <= tp2 ){
        val[i][j] = tp1;
        
        string tmp = "-";
        tmp += a[i];
        ans[i][j].push_back(tmp);
        
        if( (i+1) >= l1 ){
          for(int k = j+1 ; k < l2;k++){

          	string tmp = "+";
          	tmp += b[k];
            ans[i][j].push_back(tmp);
          } 
        }
        else{
          for(int v = 0 ; v < ans[i+1][j].size() ; v++)
            ans[i][j].push_back(ans[i+1][j][v]);  
        }
         
         
      } 
      else{
        val[i][j] = tp2;
        
        string tmp = "+";
        tmp += b[j];
        ans[i][j].push_back(tmp);
        
        if( (j+1) >= l2 ){
          
          for(int k = i+1 ; k < l1;k++){
            string tmp = "-";
            tmp += a[k];
            ans[i][j].push_back(tmp);
          }
        }
        else{
          for(int v = 0 ; v < ans[i][j+1].size() ; v++)
            ans[i][j].push_back(ans[i][j+1][v]);  
        }
        
      }
      
      
    
  }
  
  return val[i][j];
}

vector<string> diffBetweenTwoStrings(const string& source, const string& target)
{	
  for(int i=0;i<12;i++){
    for(int j = 0 ; j < 12;j++){
      val[i][j] = -1;
    }
  }

	// your code goes here
  a = source;
  l1 = a.length();
  
  b = target;
  l2 = b.length();
  
  solve(0,0);
  
  return ans[0][0];
  
}

int main(){

	#ifndef ONLINE_JUDGE    
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	vector<string> chak;
  
  	chak = diffBetweenTwoStrings("ABCDEFG","ABDFFGH");
  
  	for(int i = 0; i < chak.size() ; i++ ){
    	cout << chak[i] << " ";
   	}

	// cout << ans[0][0][0];
	return 0;
}