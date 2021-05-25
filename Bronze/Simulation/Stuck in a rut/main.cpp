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

bool comp(int a,int b)
{
    return a< b;
}

/**************************************************/

struct cow
{
    char dir;
    ll x,y;
    bool stop = 0;
};




int main()
{
    int n;
    cin>>n;
    cow *cows = new cow[n];
    rep(i,n)
    {
        cin>>cows[i].dir>>cows[i].x>>cows[i].y;
    }
    vector<vector<pair<ll,ii>>> ans;
    rep(i,n)
    {
        vector<pair<ll,ii>> curr;
        rep(j,n)
        {
            if(cows[i].dir != cows[j].dir)
            {
                ll x,y;
                if(cows[i].dir=='E')
                {
                    if(cows[i].y-cows[j].y>=0 && cows[i].y - cows[j].y < cows[j].x - cows[i].x)
                    {
                        pair<ll,ii> point;
                        point.F = cows[j].x - cows[i].x;
                        point.S.F = cows[j].x;
                        point.S.S = cows[j].y;
                        curr.pb(point);
                    }
                }
                else
                {
                    if(cows[i].x - cows[j].x >=0 && cows[i].x - cows[j].x < cows[j].y - cows[i].y)
                    {
                        pair<ll,ii> point;
                        point.F = cows[j].y - cows[i].y;
                        point.S.F = cows[j].x;
                        point.S.S = cows[j].y;
                        curr.pb(point);
                    }
                }
            }
        }
        ans.pb(curr);
    }
    ll mini=99999999;
    int minp=-1;
    ll *grass = new ll[n];
    rep(i,n) grass[i]=-1;
    int i = 0;
    bool done = 1;
    while(done)
    {
        rep(i,ans.size())
        {
            rep(j,ans[i].size())
            {
                if(ans[i][j].F<=mini)
                {
                    mini = ans[i][j].F;
                    minp=i;
                }
            }
        }
        rep(l,ans.size())
        {
            rep(k,ans[l].size())
            {
                if(ans[l][k].S.F == cows[minp].x && ans[l][k].S.S == cows[minp].y)
                {
                    if(cows[l].dir == 'E'){
                        if(cows[minp].y + mini < cows[l].y){
                            ans[l].erase(ans[l].begin()+k);
                        }
                    }
                    else{
                        if(cows[minp].x + mini < cows[l].x){
                            ans[l].erase(ans[l].begin()+k);
                        }
                    }
                }
            }
        }
        grass[minp] = mini;
        mini=999999999;
        done = 0;
        ans[minp].clear();
        rep(i,ans.size())
        {
            if(!ans[i].empty())
            {
                done = 1;
                break;
            }
        }
    }
    rep(i,n){
        if(grass[i]==-1)
            cout<<"Infinity"<<endl;
        else cout<<grass[i]<<endl;
    }
}

