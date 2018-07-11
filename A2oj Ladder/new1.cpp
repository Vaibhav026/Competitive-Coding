#include <iostream>
using namespace std;

int main()
{
  int n;

  cin >> n;

  int a[n];

  int count[101];

  for(int i=0;i<=100;i++)
  	count[i] = 0;

  for(int i=0;i<n;i++){

  	cin >> a[i];
  	count[a[i]]++;

  }
  
  int max = 0;

  for(int i=0;i<=100;i++){

  	if(max < count[i])
  		max = count[i];
  }
  		  

  cout << max;










	return 0;
}