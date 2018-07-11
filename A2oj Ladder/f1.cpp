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
    for(int i=0;i<q;i++){

        for(j=0;j<=31;j++)
            binx[j] = 0;

        cin >> x;

        j = 0;

        while(x){
            binx[j] = x % 2;
            j++;
            x = x/2;
        }

        long int temp,req,sum =0 ;

        
        bool res = true;
        
        int done = 0;
        for(int k=31;k>=0;k--){

            long int tot = pow(2,k);
            long int curr = tot;
            if(binx[k] == 1){
                
                res = false;

                temp = 1;   
                for(int x = k;x>=0;x--){

                    temp = (tot-done)/curr;

                    if(powerc[x] >= temp){

                        powerc[x] = powerc[x] - temp;
                        sum += temp;
                        res = true;
                        break;
                    }
                    else
                    {   
                        done += curr*powerc[x];
                        sum += powerc[x];
                        powerc[x] = 0;
                         
                    }    

                    curr = curr/2 ;
                    //temp = temp*2;
                }   


            }

            if(res == false){

                break;
            }
        }

        if(res == false || sum < 0)
            cout << "-1\n";
        else
            cout << sum << "\n";



        for(int z=0;z<=31;z++){
            powerc[z] = dupl[z];
        }   

    }





    return 0;
}