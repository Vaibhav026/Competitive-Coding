vector<nd> v;
vector<ll> a,b,c;
ll n,m;

int main()
{
	IOS;
	cin>>n>>m;
	v=vector<nd> (n);
	a=vector<ll> (m);
	multiset<ll> st;
	for(ll i=0;i<n;i++)
	{
		cin>>v[i].s>>v[i].val;
		if(v[i].s=="ATK")
		{
			b.pb(v[i].val);
		}
		else
		{
			c.pb(v[i].val);
		}
	}
	for(ll i=0;i<m;i++)
	{
		cin>>a[i];
		st.insert(a[i]);
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	sort(c.begin(),c.end());
	ll sz1=b.size();
	ll sz2=n-sz1;
	ll ans=0;
	for(ll count=sz1-1;count>=0;count--)
	{	
		ll tempans=0;
		bool chck=true;
		for(ll i=m-1,j=count;i>=0&&j>=0;i--,j--)
		{
			if(a[i]>=b[j])
			{
				tempans+=a[i]-b[j];
			}
			else
			{
				chck=false;
				break;
			}
		}
		if(!chck)
			continue;
		ans=max(ans,tempans);
	}




}	