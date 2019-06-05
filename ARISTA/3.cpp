#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
	Node* children[26];
	bool isEnd;
};

std::vector<string> v;

Node* getNode(){

	Node* root = new Node();

	for(int i=0;i<26;i++){
		root->children[i] = NULL;
	}
	root->isEnd = false;	
}

void insert(string s,Node* root){

	int l = s.length();

	for(int i=0;i<l;i++){
		int z = s[i]-'a';
		
		if(!root->children[z])
			root->children[z] = getNode();

		root = root->children[z];
	}

	root->isEnd = true;	
}

bool find(Node* root,string s){
	int l = s.length();

	int z;

	for(int i=0;i<l;i++){
		z = s[i] -	'a';

		if(!root->children[z])
			return false;

		root = root->children[z];
	}

	if(root->isEnd)
		return true;

	return false;		
}

void recur(Node* root,string pre){

	if(root->isEnd){
		v.push_back(pre);
	}

	char ch;

	for(int i=0;i<26;i++){
		if(root->children[i]){	
			ch = ('a') + i;
			recur(root->children[i],pre+ch);
		}
	}
}

void all(Node* root,string prefix){

	int l = prefix.length();

	int z;

	for(int i=0;i<l;i++){
		z = prefix[i] -	'a';

		if(!root->children[z])
			return;

		root = root->children[z];
	}

	recur(root,prefix);
} 
int main()
{
	#ifndef ONLINE_JUDGE	
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
   	#endif						



    Node* root = getNode();

    insert("heal",root);
    insert("hello",root);
    insert("bye",root);


    // cout << find(root,"hi") << endl;

    // cout << find(root,"hell") << endl;

    // cout << find(root,"hiee") << endl;

    all(root,"hello");
	for(int i=0;i<v.size();i++){
		cout << v[i] << endl;
	}    

	return 0;
}