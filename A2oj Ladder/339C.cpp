#include<iostream>
#include<vector>
using namespace std;
bool f[11]={0};
int m;
vector<int>list;
bool dfs(int d,int l,int n){
	if(n==m){
		cout<<"YES\n";
		for(int i=0;i<list.size();i++){
			cout<<list[i];
			if(i!=list.size()-1)cout<<" ";
		}
		return true;
	}
	for(int i=d+1;i<=10;i++)
		if(f[i]&&i!=l){
			list.push_back(i);
			if(dfs(i-d,i,n+1))return true;
			list.pop_back();
		}
	return false;
}
int main()
{
	char tmp;
	for(int i=1;i<=10;i++){
		cin>>tmp;
		if(tmp=='1')f[i]=true;
	}
	cin>>m;
	vector<int>list;
	if(!dfs(0,0,0))cout<<"NO";
	return 0;
}