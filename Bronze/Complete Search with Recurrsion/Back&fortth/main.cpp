#include <bits/stdc++.h>
#include <string>
using namespace std;
#define pb push_back
#define F first
#define S second
#define rep(i,n) for(int i = 0; i < (n); i++)

#define input            freopen("input.in","r",stdin)
#define output           freopen("output.out","w",stdout)

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

using ll = long long;
using ld = long double;
using ul = unsigned long long;
using ii = pair<int, int>;

const ll mod7 = 1000000007,mod1 = 1000000000,OO = 0x3f3f3f3f;
const ld EPS = 1e-7;
double Pi=acos(-1);
const ld rad=Pi/180.0;

long long power(long long a, long long  b, ll mod)
{
    if(!b)
        return 1ll;
    if(b == 1)
        return a%mod;
    long long r = power(a, b/2ll,mod)%mod;
    if(b%2ll)
        return ((r*(a%mod)%mod)*r)%mod;
    else
        return (r*r)%mod;

}

ll nCr (ll n,ll m)
{
    return(m == 0)?1:n*nCr(n-1,m-1)/m;
}

bool checkDivisibility(ll n, int digit)
{
    return (digit == 0|| (digit != 0 && n % digit == 0));
}

bool allDigitsDivide(ll n)
{
    ll temp = n;
    while (temp > 0)
    {

        ll digit = temp % 10;
        if (!(checkDivisibility(n, digit)))
            return false;

        temp /= 10;
    }
    return true;
}

bool comp(string a,string b)
{
    return a.length() > b.length();
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}
/**************************************************/

using namespace std;

set<int> ans;

void solve(vector<int> vec1,vector<int> vec2,int day,int reading,bool turn)
{
    if(turn)
    {
        turn = !turn;
        for(int i=0; i<vec1.size(); i++)
        {
            int x = vec1[i];
            vector<int> newVec2 = vec2;
            newVec2.push_back(x);
            vector<int> newVec1= vec1;
            newVec1.erase(newVec1.begin() + i);
            solve(newVec1,newVec2,day+1,reading-x,turn);
        }
    }
    else
    {
        turn = !turn;

        for(int i=0; i<vec2.size(); i++)
        {
            int x = vec2[i];
            if(day == 4)
            {
                ans.insert(reading+x);
                continue;
            }
            vector<int> newVec1 = vec1;
            newVec1.push_back(x);
            vector<int> newVec2= vec2;
            newVec2.erase(newVec2.begin() + i);
            solve(newVec1,newVec2,day+1,reading+x,turn);
        }
    }

}

int main()
{
    freopen("backforth.in","r",stdin);
    freopen("backforth.out","w",stdout);
    vector<int> barn1;
    vector<int> barn2;
    rep(i,10)
    {
        int in;
        cin>>in;
        barn1.pb(in);
    }
    rep(i,10)
    {
        int in;
        cin>>in;
        barn2.pb(in);
    }
    solve(barn1,barn2,1,1000,1);
    cout<<ans.size();
}
