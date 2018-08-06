#include<bits/stdc++.h>
using namespace std;


vector<int> indexes;
 
#include <iostream>
#include <cstdlib>
 
using namespace std;
#define MAX_MATCHES 1000
 
// //Array to store matched indexes
int FOUND[MAX_MATCHES];
//variable to store last index in FOUND array
static int l = 0;

void search(string pat, string txt)
{
    int M = pat.length();
    int N = txt.length();
 
    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N - M; i++) {
        int j;
 
        /* For current index i, check for pattern match */
        for (j = 0; j < M; j++)
            if (txt[i + j] != pat[j])
                break;
 
        if (j == M) // if pat[0...M-1] = txt[i, i+1, ...i+M-1]
            indexes.push_back(i);
    }
}
 
//Partial match table
void kmp_table(string W, int *T )
{
 int pos = 2;
 int cnd = 0;
 int length = W.length();
  
 T[0] = -1;
 T[1] = 0;
  
 while( pos < length)
 {
  if(W[pos-1] == W[cnd])
  {
   T[pos] = cnd + 1;
   cnd++;
   pos++;
  }
  else if( cnd > 0)
   cnd = T[cnd];
  else
  {
   T[pos] = 0;
   pos++;
  }
 }
}
 
//Search function
void kmp_search(string S, string W)
{
  
 int m = 0; 
 int i = 0;
 int sizeS = S.length();
 int sizeW = W.length();
  
 int *T = new int[sizeof(int) * sizeW];
  
 kmp_table(W, T);
  
 while( (m + i) < sizeS)
 {
  if (W[i] == S[m + i]) 
  {
            if (i == (sizeW - 1))
            {
             //Add the start index of match in the FOUND table
             FOUND[l++] = m;
   }
     
            i++;
        }
        else
        {
            if (T[i] > -1)
            {
                m = m + i - T[i];
    i = T[i];
            }
            else
            {
                m = m + 1;
    i = 0;
            }
        }
 }
  
 delete(T);
}

int main()
{
	long int n,m,q;

	cin >> n >> m >> q;

	string s,t;

	cin >> s;
	cin >> t;

	//kmp_search(s,t);

	search(t,s);

	int left,right;

	int ans	;

	int ll =indexes.size();

	for(long int i=0;i<q;i++){

		ans = 0;
		cin >> left >> right;
		left = left-1;
		right = right-1;

		for(int j=0;j<ll;j++){

			if(left<=indexes[j] && (indexes[j]+m-1)<=right)
				ans++;

		}

		cout << ans << endl;

	}




}