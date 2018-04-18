#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;



int main()
{
	long int t;
	cin>>t;

	long int n,s,y;

	long double v[21];

	long long int d[21];

	long double p[21];

	long double pos[15];

	int c[21];

	long double time;

	
	while(t--)
	{
		time = 0;
		cin >> n >> s >> y ;

		for(int i=1;i<=n;i++)
		cin >> v[i];	

		long double t = (double) y/s ;

		for(int i=1;i<=n;i++)
		cin >> d[i];	

		for(int i=1;i<=n;i++)
		{
			cin >> p[i];
			pos[i] = p[i];	
        }
		for(int i=1;i<=n;i++)
		cin >> c[i];	


		for(int i=1;i<=n;i++)
		{
			if(d[i]==1)
			{
				long double back = p[i] - c[i] ;

				if(back>= 0)
				{	if( back < 0.000001 )	
					time += (long double) (0.000001-back)/(v[i]) + t ;
					else
					time += t;  	
				}	
				else
				{
					if(p[i]>=0 && back <0)
					{
						time += (long double) ((-1)*back)/v[i] ;
						time += t;

						time += (long double) 1/((1000000)*v[i]);
					}
					else
					{
						if( (long double)(-p[i]-0.000001)/(v[i]) >= t )
						time += t;
						else
						{
							time += (long double) ((-1)*back)/v[i] ;
						    time += t;

						    time += (long double) 1/((1000000)*v[i])	;	
						}										

					}	
				}	
			}
			else
			{
				long double back = p[i] + c[i] ;

				if(back<= 0)
				{	if( -1*(back) < 0.000001 )	
					time += t + (long double) (0.000001+back)/(v[i]) ;
					else
					time += t;  	
				}	
				else
				{
					if(p[i]<=0 && back >0)
					{
						time += (long double) (back)/v[i] ;
						time += t;

						time += (long double) 1/((1000000)*v[i]);
					}
					else
					{	
						if( (long double) (p[i]-0.000001)/(v[i]) > t )
						{ time += t;
						  
						}	
						else
						{	
							time += (long double) (back)/v[i] ;
						    time += t;

						    time += (long double) 1/((1000000)*v[i])	;	
						}										

					}	
				}	





			}

			
		for(int j=1;j<=n;j++)
		{	
			if( d[j] == 1)
			p[j] = pos[j] + (long double) v[j]  * time ;
			else
			p[j] = pos[j] + (long double) v[j]  * -1 * time ;	
		}		

		
	  }	

	  std::cout << std::fixed;
	  std::cout << std::setprecision(5) << time<< endl;
	}	

return 0;	
}	













