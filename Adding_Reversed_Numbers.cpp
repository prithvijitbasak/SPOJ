//Editorial: This is a easy problem everyone can get it.
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
void solve()
{
	ll a,b;
	cin>>a>>b;
	string s1,s2;
	s1=to_string(a);
	s2=to_string(b);
//	cout<<s1<<" "<<s2<<"\n";
	reverse(s1.begin(),s1.end());
	reverse(s2.begin(),s2.end());
//	cout<<s1<<" "<<s2<<"\n";
	ll x,y;
	x=stoi(s1);
	y=stoi(s2);
//	cout<<x<<" "<<y<<"\n";
	ll sum=x+y;
	string ans=to_string(sum);
	reverse(ans.begin(),ans.end());
	ll res=stoi(ans);
	cout<<res<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
       solve();
    }
}
