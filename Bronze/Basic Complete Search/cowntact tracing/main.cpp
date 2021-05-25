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

struct shake
{
    int cow1,cow2,time;
};

bool comp(shake a,shake b)
{
    return a.time < b.time;
}
int main()
{
    freopen("tracing.in","r",stdin);
    freopen("tracing.out","w",stdout);
    int n,t;
    cin>>n>>t;
    string s;
    cin>>s;
    vector<shake> shakes;
    rep(i,t)
    {
        shake in;
        cin>>in.time>>in.cow1>>in.cow2;
        shakes.pb(in);
    }
    sort(shakes.begin(),shakes.end(),comp);

    char *arr = new char[n];
    int mini = 999, maxi = 0;
    vector<ii> bounds;
    int *numShakes = new int[n];
    rep(i,n)
    {
        int maxi = 0;
        int mini = 999;
        for(int k = 0; k<=t; k++)
        {
            int ctr = 0;
            rep(j,n) arr[j] = '0';
            arr[i] = '1';
            rep(j,n) numShakes[j] = 0;
            rep(j,t)
            {

                if(arr[shakes[j].cow1-1]=='1' || arr[shakes[j].cow2-1]=='1')
                {
                    if(k>numShakes[shakes[j].cow1-1] && arr[shakes[j].cow1-1]=='1')
                    {
                        numShakes[shakes[j].cow1-1]++;
                        if(arr[shakes[j].cow2-1]=='1' && numShakes[shakes[j].cow2-1]<k) numShakes[shakes[j].cow2-1]++;
                        arr[shakes[j].cow1-1]='1';
                        arr[shakes[j].cow2-1]='1';
                    }
                    else if(k>numShakes[shakes[j].cow2-1] && arr[shakes[j].cow2-1]=='1')
                    {
                        numShakes[shakes[j].cow2-1]++;
                        if(arr[shakes[j].cow1-1]=='1' && numShakes[shakes[j].cow1-1]<k) numShakes[shakes[j].cow1-1]++;
                        arr[shakes[j].cow1-1]='1';
                        arr[shakes[j].cow2-1]='1';
                    }
                }
            }
            bool f = 1;
            rep(j,n)
            {
                if(arr[j]!=s[j])
                {
                    f = 0;
                    break;
                }
            }
            if(f)
            {
                maxi = max(maxi,k);
                mini = min(mini,k);
            }
        }
        ii currBound;
        currBound.F = mini;
        currBound.S = maxi;
        bounds.pb(currBound);
    }
    int up = 0, maxp=-1, down=999;
    int ans = 0;
    rep(i,bounds.size())
    {
        down = min(bounds[i].F,down);
        if(up<=bounds[i].S)
        {
            up = bounds[i].S;
            maxp=i;
        }
        if(bounds[i].F!=999) ans++;
    }
    cout<<ans<<" "<<down<<" ";
    if(up == t)
        cout<<"Infinity";
    else
        cout<<up;
}
