#include <bits/stdc++.h>
using namespace std;

/* Template file for Online Algorithmic Competitions */
/* Typedefs */
    /* Basic types */
    typedef long long           ll;
    typedef long double         ld;
    typedef unsigned long long ull;
    /* STL containers */
    typedef vector <int>    vi;
    typedef vector <ll>     vll;
    typedef pair <int, int> pii;
    typedef pair <ll, ll>   pll;
    typedef vector < pii >  vpii;
    typedef vector < pll >  vpll;
    typedef vector <string> vs;
    typedef vector < vi >   vvi;
    typedef vector < vll >  vvll;
    typedef vector < vpii > vvpii;
    typedef set <int>       si;
/* Macros */
    /* Loops */
    #define fl(i, a, b)     for(int i(a); i <= (b); i ++)
    #define rep(i, n)       fl(i, 1, n)
    #define loop(i, n)      fl(i, 0, n - 1)
    #define rfl(i, a, b)    for(int i(a); i >= (b); i --)
    #define rrep(i, n)      rfl(i, n, 1)
    /* Algorithmic functions */
    #define srt(v)          sort((v).begin(), (v).end())
    /* STL container methods */
    #define pb              push_back
    #define mp              make_pair
    #define eb              emplace_back
    /* String methods */
    #define dig(i)          (s[i] - '0')
    #define slen(s)         s.length()
    /* Shorthand notations */
    #define fr              first
    #define sc              second
    #define re              return 
    #define sz(x)           ((int) (x).size())
    #define all(x)          (x).begin(), (x).end()
    #define sqr(x)          ((x) * (x))
    #define fill(x, y)      memset(x, y, sizeof(x))
    #define clr(a)          fill(a, 0)
    #define endl            '\n'
    /* Mathematical */
    #define IINF            0x3f3f3f3f
    #define LLINF           1000111000111000111LL
    #define PI              3.14159265358979323
    /* Debugging purpose */
    #define trace1(x)                cerr << #x << ": " << x << endl
    #define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl
    #define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl
    #define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl
    #define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl
    #define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl
    /* Fast Input Output */
    #define FAST_IO                  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
/* Constants */
    const ll MOD = 1000000007LL;
    const ll MAX = 100010LL;
/* Templates */
template<class T> T abs(T x) { re x > 0 ? x : -x; }
template<typename T> T gcd(T a, T b){ if(b == 0) return a; return gcd(b, a % b); }
template<typename T> T power(T x, T y, ll m = MOD){T ans = 1; x %= m; while(y > 0){ if(y & 1LL) ans = (ans * x)%m; y >>= 1LL; x = (x*x)%m; } return ans%m; }

bool isSuffix(string s1, string s2) 
{ 
    int n1 = s1.length(), n2 = s2.length(); 
    if (n1 > n2) 
      return false; 
    for (int i=0; i<n1; i++) 
       if (s1[n1 - i - 1] != s2[n2 - i - 1]) 
           return false; 
    return true; 
} 

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
//    cout << "a";
    //FAST_IO;

    string s1,s2,virus;

    //cout << "a";
    cin >> s1;
    cin >> s2;
    cin >> virus;
    //cout << "a";

    int l1 = s1.length();

    string s1new = "e" + s1;
    string s2new = "e" + s2;
    int l2 = s2.length();

    int l3 = virus.length();

    int dp[l1+2][l2+2][l3+2];
    //cout << "a";
    string str[l1+2][l2+2][l3+2];

    //cout << "a";
    for(int j=0;j<=l2;j++){
        
        for(int k=0;k<l3;k++){
            dp[0][j][k] = 0;
            str[0][j][k] = "";
        }
    }

    for(int i=0;i<=l1;i++){
        
        for(int k =0;k<l3;k++){
            dp[i][0][k] = 0;
            str[i][0][k] = "";
        }    
        
    }


    for(int i=1;i<=l1;i++){

        for(int j=1;j<=l2;j++){

            
            
            for(int k=0;k<l3;k++){

                //cout << i << " " << j << " " <<endl;
                if( k == 0){

                    dp[i][j][k] = dp[i][j-1][k];
                        str[i][j][k] = str[i][j-1][k];

                    if(virus[0] != s2new[j]){
                        for(int z =i;z>=1;z--){

                            if(s1new[z] == s2new[j]){
                                
                                string tmp = "";
                                tmp += s2new[j];
                                
                                string tmp2 = str[z-1][j-1][0] + tmp;

                                    
                                        tmp2 = str[z-1][j-1][0] + tmp;
                                    if(dp[i][j][k] < (1 + dp[z-1][j-1][0])){
                                        dp[i][j][k] = (1 + dp[z-1][j-1][0]);
                                        str[i][j][k] = tmp2;
                                    }
                                    
                                }

                            }
                    }   
                    

                    //continue;
                }
                else{

                dp[i][j][k] = dp[i][j-1][k];
                str[i][j][k] = str[i][j-1][k];

                
                if(virus[k-1] == s2new[j]){

                    for(int z =i;z>=1;z--){

                        if(s1new[z] == s2new[j]){
                            
                            string tmp = "";
                            tmp += s2new[j];
                            
                            string tmp2 = str[z-1][j-1][k-1] + tmp;

                            
                            if( dp[z-1][j-1][k-1] >=(k-1) && dp[i][j][k] < (1 + dp[z-1][j-1][k-1]) ){
                                
                                dp[i][j][k] = (1 + dp[z-1][j-1][k-1]);
                                str[i][j][k] = tmp2;
                            }

                        }
                    }    
                }
                

                }   
                

              //  cout << i << " " << j << " " << k << " " << str[i][j][k] << endl;            
            }    
        }
    }

    
    int max = 0;

    int ind1;
    for(int k=0;k<l3;k++){
        if(dp[l1][l2][k] > max){
            max = dp[l1][l2][k];
            ind1 = k;
        }

        

    }

    if(max  == 0){
        cout << "0";
    }
    else{
        cout << str[l1][l2][ind1];
    }
    return 0;
}    