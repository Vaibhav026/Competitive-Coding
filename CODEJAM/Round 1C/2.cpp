#include <bits/stdc++.h>
using namespace std;

vector<string> ans;

void permute(string str, string out) 
{ 
    // When size of str becomes 0, out has a 
    // permutation (length of out is n) 
    if (str.size() == 0) 
    { 	
    	bool t = false;

        for(int i=0;i<ans.size();i++){
        	if(ans[i] == out){
        		t =true;
        	}
        }

        if(!t){
        	cout << out << "\n";
        	cout.flush(); 
        	char ch;
        	cin >> ch;
        }


        //cout << out << endl; 
        return; 
    } 
  
    // One be one move all characters at 
    // the beginning of out (or result) 
    for (int i = 0; i < str.size(); i++) 
    { 
        // Remove first character from str and 
        // add it to out 
        permute(str.substr(1), out + str[0]); 
  
        // Rotate string in a way second character 
        // moves to the beginning. 
        rotate(str.begin(), str.begin() + 1, str.end()); 
    } 
} 
int main(){


	int t;

	cin >> t;


	int f;
	
	char ch;

	for(int i=1;i<=t;i++){

		vector<int> A,B,C,D,E;

		cin >> f;


		for(int j=1;j<=(119*5);j += 5){

			cout << j;
			cout.flush();

			cin >> ch;

			if(ch == 'A'){
				A.push_back(j);
			}
			else if(ch == 'B'){
				B.push_back(j);
			}
			else if(ch == 'C'){
				C.push_back(j);
			}
			else if(ch == 'D'){
				D.push_back(j);
			}
			else{
				E.push_back(j);
			}
		}

		

		if(A.size() == 23){
			for(int j=0;j<A.size();j++){
				string str = "";	
				for(int k=A[j]+1;k<A[j]+5;j++){
					cin  >> k;
					cout << ch;
					cout.flush();
					str += ch;
				}

				ans.push_back(str);
			}

			permute("BCDE","");
		}
		else if(B.size() == 23){

			for(int j=0;j<B.size();j++){
				string str = "";	
				for(int k=B[j]+1;k<B[j]+5;j++){
					cin  >> k;
					cout << ch;
					cout.flush();
					str += ch;
				}

				ans.push_back(str);
			}

			permute("ACDE","");

		}
		else if(C.size() == 23){
			for(int j=0;j<C.size();j++){
				string str = "";	
				for(int k=C[j]+1;k<C[j]+5;j++){
					cin  >> k;
					cout << ch;
					cout.flush();
					str += ch;
				}

				ans.push_back(str);
			}

			permute("ABDE","");

		}
		else if(D.size() == 23){
			for(int j=0;j<D.size();j++){
				string str = "";	
				for(int k=D[j]+1;k<D[j]+5;j++){
					cin  >> k;
					cout << ch;
					cout.flush();
					str += ch;
				}

				ans.push_back(str);
			}

			permute("ABCE","");

		}
		else{

			for(int j=0;j<E.size();j++){
				string str = "A";	
				for(int k=E[j]+1;k<E[j]+5;j++){
					cin  >> k;
					cout << ch;
					cout.flush();
					str += ch;
				}

				ans.push_back(str);
			}

			permute("ABCD","");


		}

		A.clear();
		B.clear();
		C.clear();
		D.clear();
			E.clear();
			ans.clear();
	}







	return 0;
}