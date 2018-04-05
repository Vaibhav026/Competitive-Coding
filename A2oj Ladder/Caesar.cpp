#include<bits/stdc++.h>
using namespace std ;
//-------------------------------
typedef long long ll ;
typedef vector<int> vi ;
typedef pair<int,int> ii ;
//-------------------------------
#define _CRT_SECURE_NO_WARNINGS
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define rep(i,a,b) for(int i=(a) ; (i)<(b) ; ++i)
#define inf 2000000000
#define endl "\n"
#define de(x) cerr<<#x<<" is "<<x<<endl;
#define max(a,b) ( (a>b) ? (a) : (b)  )
#define min(a,b) ( (a<b) ? (a) : (b)  )
//------------------------------
int ri() { char c = getchar(); while(c<'0' || c>'9') c=getchar(); int ret = 0; while(c>='0' && c<='9') { ret=10*ret+c-48; c=getchar(); } return ret; }
const ll mod = 100000000LL ;
ll dp[104][104][15][15] ;
int k1,k2 ;
ll solve(int n1,int n2,int x1,int x2)
{
    if(n1==0 && n2==0) return 1 ;
    ll res = dp[n1][n2][x1][x2] ;
    if(res != -1LL) return res ;
    res = 0 ;
    if(n1>0 && x1<k1)
        res += solve(n1-1,n2,x1+1,0);
    if(n2>0 && x2<k2)
        res += solve(n1,n2-1,0,x2+1);
    res %= mod ;
    dp[n1][n2][x1][x2] = res ;
    return res ;
}
int main()
{
    //freopen("input.txt","r",stdin) ;
    memset(dp,-1,sizeof dp);
    int n1,n2 ;
    cin >> n1 >> n2 >> k1 >> k2 ;
    cout << solve(n1,n2,0,0) << endl ;
}