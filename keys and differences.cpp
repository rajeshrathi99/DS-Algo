/*
  Vivek Rathi
  CSE 2nd Year
  MNNIT
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
#define fi first
#define se second
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);
#define inf 1e17
int main()
{
	boost
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll a[n];
		for(ll i=0;i<n;i++)
		{
			cin>>a[i];
		}
		sort(a,a+n);
		ll b[n];
		if(n%2==0)
		{
			for(ll i=n/2-1,j=n/2,k=n-1,flag=0;k>=0;)
			{
				if(flag==0)
				{
					b[i]=a[k];
					k--;
					i--;
					flag=1;
				}
				else
				{
					b[j]=a[k];
					k--;
					j++;
					flag=0;
				}
			}
		}
		else
		{
			for(ll i=n/2,j=n/2+1,k=n-1,flag=0;k>=0;)
			{
				if(flag==0)
				{
					b[i]=a[k];
					k--;
					i--;
					flag=1;
				}
				else
				{
					b[j]=a[k];
					k--;
					j++;
					flag=0;
				}
			}
		}
		string s;
		for(ll i=0;i<n-1;i++)
		{
			s=s+to_string(abs(b[i]-b[i+1]));
		}
		if(n%2==1) s=s+to_string(abs(b[n-1]-b[0]));
		ll flag=0;
		for(ll i=0,j=s.length()-1;i<j;i++,j--)
		{
			if(s[i]!=s[j])
			{
				flag=1;
				break;
			}
		}
		reverse(s.begin(),s.end());
		if(flag==0)cout<<s<<endl;
		else cout<<"Key combination cannot be cracked"<<endl;
	}
	return 0;
}