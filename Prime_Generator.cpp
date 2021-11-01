/*Editorial:-
This problem will be  solved using segmented seive.
Video link: https://youtu.be/MY0fXk-3BVQ
Code:-   */
// Please ignore the other parts of the code its the template that I use for Competitive Programming.
// Prithvijit Basak
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<queue>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
#include<deque>
#include<numeric>
#include<climits>
using namespace std;
typedef long long int ll;
const ll mod=1e9+7;
ll binpow(ll a, ll b)
{
    a %= mod;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
bool isprime(ll n)
{
	if(n==1)
		return false;
	for(ll i=2;i*i<=n;i++)
	{
		if(n%i==0)
			return false;
	}
	return true;
}
ll sz=1e6;
vector<bool> primes(sz+1);
void seive()
{
	for(ll i=2;i<=sz;i++)
	  primes[i]=true;
	for(ll i=2;i*i<=sz;i++)
	{
		if(primes[i]==true)
		{
			for(ll j=i*i;j<=sz;j+=i)
			{
				primes[j]=false;
			}
		}
	}
}
vector<ll> 	generateprimes(ll n)
{
	vector<ll> ds;
	for(ll i=2;i<=n;i++)
	{
		if(primes[i]==true)
		  ds.push_back(i);
	}
	return ds;
}
void solve()
{
	ll l,r;
	cin>>l>>r;
	vector<ll> nowprimes=generateprimes(sqrt(r));
	vector<ll> dummy(r-l+1);
	for(ll i=0;i<(r-l+1);i++)
	  dummy[i]=1;
	for(auto it:nowprimes)
	{
		ll fm=(l/it)*it;
		if(fm<l)
		  fm+=it;
		for(ll j=max(fm,it*it);j<=r;j+=it)
		{
			dummy[j-l]=0;
		}
	}
	for(ll i=l;i<=r;i++)
	{
		if(i==1)
		  continue;
		if(dummy[i-l]==true)
		  cout<<i<<"\n";
	}
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    seive();
    ll t;
    cin>>t;
    while(t--)
    {
       solve();
    }
}
