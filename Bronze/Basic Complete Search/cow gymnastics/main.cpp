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






int main()
{
    freopen("gymnastics.in","r",stdin);
    freopen("gymnastics.out","w",stdout);
    int k,n;
    cin>>k>>n;
    int arr[30][30];
    rep(i,k){
        rep(j,n) cin>>arr[i][j];
    }
    int pos[30][30];
    rep(i,k){
        rep(j,n){
            pos[i][arr[i][j]-1]=j;
        }
    }
    int pairs[200][200];
    rep(i,k){
        int ctr =0;
        rep(j,n){
            for(int x = j+1;x<n;x++){
                if(pos[i][j]>pos[i][x]) pairs[i][ctr]=2;
                else pairs[i][ctr]=1;
                ctr++;
            }
        }
    }
    int ans = n*(n-1)/2;
    rep(i,n*(n-1)/2){
        rep(j,k-1){
            if(pairs[j][i]!=pairs[j+1][i]){
                ans--;
                break;
            }
        }
    }
    cout<<ans;
}
