#include <bits/stdc++.h>
using namespace std;

int main()
{
   ofstream ofile; 
   ofile.open ("text.txt");

   long int n = 200000;

   for(long int i=1;i<=n-1;i++)
   		ofile << "1 ";

   ofile << "1000000" << endl;
   cout << "Data written to file" << endl;
   ofile.close(); 
   return 0;







  return 0;
}