#include<bits/stdc++.h>
using namespace std;

int main()
{	
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
	#endif
	
	int a,b;

	cin >> a >> b;

	bool possible[1001];

	std::vector<int> len[2];

	for(int i=0;i<=1000;i++)
		possible[i] = false;
	
	int k ;

	double sq;

	int tmp ;
	long int tmp1;
	for(int i = 1;i<=1000;i++){
		
		for(int j=1;j<=1000;j++){

			k = i*i + j*j;

			sq = sqrt(k);

			tmp = floor(sq);

			tmp1 = tmp*tmp;

			if(tmp<= 1000 && tmp1 == k){
				
				possible[tmp] = true;
				

				if(tmp == a ){
					len[0].push_back(i);
					len[0].push_back(j);
					//cout << tmp << endl;
				}

				if(tmp == b){
					len[1].push_back(i);
					len[1].push_back(j);
					//cout << tmp << endl;
				}

			}

			

		}
	}
	// cout << len[0][0] << " " << len[0][1] << endl;
	// cout << len[1][0] << " " << len[1][1] << endl;

	// sort(len[0].begin(),len[0].end());

	// sort(len[1].begin(),len[1].end());

	long int x1,y1,x2,y2,x3,y3;
	x3 = 0;
	y3 = 0;

	//cout << len[0].size() << endl;
	if(possible[a] && possible[b]){

		for(int i=0;i<=(len[0].size()-2);i = i+2){
			for(int j=0;j<=(len[1].size()-2);j = j+2){
		long long int p1 = len[0][i]*len[1][j+1];

		long long int p2 = len[0][i+1]*len[1][j];

		long long int p3 = len[0][i]*len[1][j];
		long long int p4 = len[0][i+1]*len[1][j+1];
		
			if(p3 == p4){
				x1 = len[0][i];
				x2 = -1*len[1][j];

				y1 = len[0][i+1];
				y2 = len[1][j+1];

				if(y1 != y2){
					cout << "YES\n";

					cout << x1 << " " << y1 << "\n";
					cout << x2 << " " << y2 << "\n";
					cout << x3 << " " << y3 << "\n";	
					return 0;
				}	
				
				if(y1 == y2){

					x2 = -1*x2;

					if(x1 != x2){

						cout << "YES\n";

						cout << y1 << " " << x1 << "\n";
						cout << -1*y2 << " " << x2 << "\n";
						cout << x3 << " " << y3 << "\n";	
						return 0;

					}
				}	
			}
			
			if(p1 == p2){
				x1 = len[0][i];
				x2 = -1*len[1][j+1];

				y1 = len[0][i+1];
				y2 = len[1][j];

				if(y1 != y2){
					cout << "YES\n";

					cout << x1 << " " << y1 << "\n";
					cout << x2 << " " << y2 << "\n";
					cout << x3 << " " << y3 << "\n";	
					return 0;
				}

				if(y1 == y2){

					x2 = -1*x2;

					if(x1 != x2){

						cout << "YES\n";

						cout << y1 << " " << x1 << "\n";
						cout << -1*y2 << " " << x2 << "\n";
						cout << x3 << " " << y3 << "\n";	
						return 0;

					}
				}	
			}
			
			}

		}	
			cout << "NO";
			return 0;
			

			
	}
	else
		cout << "NO";








	return 0;
}