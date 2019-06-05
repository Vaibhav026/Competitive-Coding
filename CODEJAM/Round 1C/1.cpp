#include<bits/stdc++.h>
using namespace std;




int main(){

	// #ifndef ONLINE_JUDGE    
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif

	int t;

	cin >> t;

	int A;

	

	string s[260];

	int it[260];

	int len[260];
	bool rock,paper,scis;

	vector<char> ans;

	bool won[260];

	bool lost,jeet;

	for(int i=1;i<=t;i++){

		cin >> A;

		lost = false;
		jeet = false;

		for(int j=0;j<A;j++){
			it[j] = 0;
			won[j] = false;
		}

		for(int j=0;j<A;j++)
			cin >> s[j];

		for(int j=0;j<A;j++){
			len[j] = s[j].length();
		}

		for(int k=0;k<500;k++){

			rock = false;
			paper = false;
			scis = false;

			for(int j=0;j<A;j++){

				if(won[j]){
					continue;
				}

				if(s[j][it[j]] == 'R'){
					rock = true;
				}
				else if(s[j][it[j]] == 'P'){
					paper = true;
				}
				else{
					scis = true;
				}

				//it[j] = (it[j] +1)%len[j]; 
			}

			if(rock && paper && scis){
				lost = true;
			}
			else if(rock && paper && !scis){

				for(int j=0;j<A;j++){

					if(won[j]){
						continue;
					}

					if(s[j][it[j]] == 'R'){
						won[j] = true;
					}
					else{
						it[j] = (it[j] +1)%len[j];	
					}

				}

				ans.push_back('P');	
			}
			else if(!rock && paper && scis){

				for(int j=0;j<A;j++){

					if(won[j]){
						continue;
					}

					if(s[j][it[j]] == 'P'){
						won[j] = true;
					}
					else{
						it[j] = (it[j] +1)%len[j];	
					}

				}

				ans.push_back('S');	
			}
			else if(rock && !paper && scis){

				for(int j=0;j<A;j++){

					if(won[j]){
						continue;
					}

					if(s[j][it[j]] == 'S'){
						won[j] = true;
					}
					else{
						it[j] = (it[j] +1)%len[j];	
					}

				}

				ans.push_back('R');


			}
			else if(rock){
				jeet = true;
				ans.push_back('P');

			}
			else if(paper){
				jeet = true;
				ans.push_back('S');
			}
			else{
				jeet = true;
				ans.push_back('R');
			}

			if(jeet){
				cout  << "Case #" << i << ": ";
				for(int z=0;z<ans.size();z++){
					cout << ans[z];
				}
				cout << "\n";

				break;
			}

			if(lost){
				cout  << "Case #" << i << ": ";
				cout << "IMPOSSIBLE\n";
				break;
			}
		}
		
		if(!jeet && !lost){
			cout  << "Case #" << i << ": ";
			cout << "IMPOSSIBLE\n";
			break;
		}
		ans.clear();


	}


	return 0;
}


