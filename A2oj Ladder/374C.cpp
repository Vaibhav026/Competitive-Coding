#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <algorithm>
#include <climits>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define gc getchar_unlocked
#define pc putchar_unlocked
#define MOD (1000000007)
#define INF 100000005
#define TREESIZE 302144
#define LEFT(n) (2*n)
#define RIGHT(n) (2*n+1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;

int r,c;
char arr[1002][1002];
int dp[1002][1002];
bool finished[1002][1002];
vector<ii> start;

int di[] = {-1,1,0,0}, dj[] = {0,0,-1,1};
char next1[500];

int dfs(int x, int y){
    
    if(finished[x][y])  return INF;
    
    if(dp[x][y]!=-1)    return dp[x][y];
    

    finished[x][y] = true;

    int temp = 0;
    for(int k=0;k<4;k++){
        int i,j;
        i=x+di[k];  j=y+dj[k];
        if(i<1 || i>r || j<1 || j>c)    continue;
        if(arr[i][j] == next1[arr[x][y]])    temp = max(temp, dfs(i,j));
    }

    finished[x][y] = false;
    return dp[x][y] = 1+temp;
    
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif

    memset(dp, -1, sizeof(dp));
    scanf("%d%d", &r, &c);

    next1['D']='I';
    next1['I']='M';
    next1['M']='A';
    next1['A']='D';

    int i,j;
    for(i=0;i<=r+1;i++) arr[i][0]=arr[i][c+1]='.';
    for(j=0;j<=c+1;j++) arr[0][j]=arr[r+1][j]='.';

    for(i=1;i<=r;i++){
        char str[10000];
        scanf("%s", str);
        for(j=1;j<=c;j++){
            arr[i][j] = str[j-1];
        }
    }
    
    int ans=0;  
    for(i=1;i<=r;i++){
        for(j=1;j<=c;j++){
            if(arr[i][j]=='D')  ans = max(ans, dfs(i,j));
            if(ans>=INF)    break;
        }
        if(ans>=INF)    break;
    }

    if(ans>=INF)    printf("Poor Inna!");
    else if(ans<4)  printf("Poor Dima!");
    else printf("%d", ans/4);

    return 0;
}