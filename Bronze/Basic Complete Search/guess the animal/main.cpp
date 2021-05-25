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

ll allDigitsSum(ll n)
{
    ll temp = n;
    int sum = 0;
    while (temp > 0)
    {

        ll digit = temp % 10;
        sum+=digit;
        temp /= 10;
    }
    return sum;
}

bool comp(pair<int,char> a,pair<int,char> b)
{
    return a.F > b.F;
}

ll gcd(ll a, ll b)
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



int main()
{
    freopen("guess.in","r",stdin);
    freopen("guess.out","w",stdout);
    int n;
    cin>>n;
    vector<vector<string>> animals;
    rep(i,n)
    {
        string name;
        cin>>name;
        int x;
        cin>>x;
        vector<string>lis;
        rep(j,x){
            string in;
            cin>>in;
            lis.pb(in);
        }
        animals.pb(lis);
    }
    int ans = 0;
    rep(i,n){
        int maxi = 0;
        for(int j = 0;j<n;j++){
            if(i==j) continue;
            int ctr = 0;
            for(int k =0;k<animals[i].size();k++){
                for(int l = 0;l<animals[j].size();l++){
                    if(animals[i][k]==animals[j][l]) ctr++;
                }
            }
            maxi = max(ctr,maxi);
        }
        ans = max(maxi,ans);
    }
    cout<<ans+1;
}
