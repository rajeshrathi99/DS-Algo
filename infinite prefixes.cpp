/*
  Vivek Rathi
  CSE 3rd Year
  MNNIT
  THUMB RULE - THINK FOR DP FIRST AND THEN GREEDY!!!
*/
#include<bits/stdc++.h>
using namespace std;
#define M 1000000007
#define ll long long int
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define debug1(x) cout<<#x<<" "<<x<<endl;
#define debug2(x,y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define present(c,x) ((c).find(x) != (c).end())
#define null NULL
#define mp make_pair
#define sz(x)	(ll)x.size()
#define fi first
#define se second
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define inf 1e18
#define flush fflush(stdout);
#define endl '\n'
//unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
//shuffle (foo.begin(), foo.end(), std::default_random_engine(seed));
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<ll, null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
ll modpower(ll a,ll b,ll c)
{
	ll res=1;
	while(b)
	{
		if(b&1LL)
			res=(res*a)%c;
		a=(a*a)%c;
		b>>=1;
	}
	return res;
}
//-------------------------------Template--Above-----------------------------------------------

int main()
{
	boost
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,x;
		cin>>n>>x;
		string s;
		cin>>s;
		ll cnt[n+1][2];
		memset(cnt,0,sizeof(cnt));
		map<ll,ll> m;
		for(ll i=0;i<n;i++)
		{
			cnt[i+1][s[i]-'0']++;
		}
		m[0]++;
		for(ll i=1;i<=n;i++)
		{
			cnt[i][0]+=cnt[i-1][0];
			cnt[i][1]+=cnt[i-1][1];
			m[cnt[i][0]-cnt[i][1]]++;
		}
		if(cnt[n][0]==cnt[n][1])
		{
			if(present(m,x))
			{
				cout<<-1<<endl;
				continue;
			}	
			else
			{
				cout<<0<<endl;
				continue;
			}
		}
		else if(x>0&&cnt[n][0]-cnt[n][1]<0)
		{
			cout<<m[x]<<endl;
			continue;
		}
		else if(x<0&&cnt[n][0]-cnt[n][1]>0)
		{
			cout<<m[x]<<endl;
			continue;
		}
		//debug1(x);
		if(x>=0)
		{
			ll first=max(0LL,x/(cnt[n][0]-cnt[n][1]));
			//ll flag=0;
			ll flag=0,flag2=0;
			if(x!=0&&x%(cnt[n][0]-cnt[n][1])==0)
			{
				flag=1;
			}
			if((x<((cnt[n][0]-cnt[n][1]))))
				flag2=1;
			x-=(x/(cnt[n][0]-cnt[n][1]))*(cnt[n][0]-cnt[n][1]);
			//debug1(x);
			if(flag2==1)
			{
				flag2=m[(cnt[n][0]-cnt[n][1])-x];
			}
			//debug2(flag,flag2);
			cout<<m[x]+m[(cnt[n][0]-cnt[n][1])-x]-flag-flag2<<endl;
		}
		else
		{
			ll first=max(0LL,x/(cnt[n][0]-cnt[n][1]));
			ll flag=0,flag2=0;
			if(x!=0&&abs(x)%abs(cnt[n][0]-cnt[n][1])==0)
			{
				flag=1;
			}
			if((abs(x)<abs((cnt[n][0]-cnt[n][1]))))
				flag2=1;
			x-=(x/(cnt[n][0]-cnt[n][1]))*(cnt[n][0]-cnt[n][1]);
			//debug1(x);
			if(flag2==1)
			{
				flag2=m[(cnt[n][0]-cnt[n][1])-x];
			}
			cout<<m[x]+m[(cnt[n][0]-cnt[n][1])-x]-flag-flag2<<endl;
		}
	}
	return 0;
}