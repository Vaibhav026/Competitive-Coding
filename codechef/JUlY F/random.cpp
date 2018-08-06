#include <bits/stdc++.h>
using namespace std;


int main()
{
    long int n,q;

    cin >> n >> q;

    long int a[n];

    long int powerc[32],dupl[32];

    long int p;

    for(int i=0;i<=31;i++){
        powerc[i] = 0;
        dupl[i] = 0;
    }

    for(int i=0;i<n;i++){
        
        cin >> a[i];
        p = ceil(log2(a[i]));

        powerc[p]++;

        dupl[p]++;
    }

    long int x;

    int binx[32];
    int j;

    long long int count[32];

    for(int i=0;i<q;i++){

        for(j=0;j<=31;j++){
            count[j] = 0;
            binx[j] = 0;
        }

        cin >> x;

        
        j = 0;
        while(x){
            binx[j] = x % 2;
            count[j] = binx[j];
            j++;
            x = x/2;
        }

        int sum= 0;
        bool result = true;
        for(int j=31;j>=0;j--){

            if(count[j] > 0){

                if(powerc[j] >= count[j]){
                    sum += count[j];
                    powerc[j] -= count[j];
                }
                else{
                    
                    if(j == 0){
                        result = false;
                        break;
                    }
                    long long int diff = count[j] - powerc[j];
                    count[j-1] += 2*diff;
                }
            }


             

        }

        if(result)
            cout << sum << endl;
        else
            cout << "-1\n";

        


        for(int j=0;j<32;j++){
            powerc[j] = dupl[j];
        }
    }





    return 0;
}