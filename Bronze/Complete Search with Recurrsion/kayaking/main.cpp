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



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> arr;
    rep(i,2*n){
        int in;
        cin>>in;
        arr.pb(in);
    }
    sort(arr.begin(),arr.end());
    vector<int> diffs;
    rep(i,2*n-1){
        diffs.pb(abs(arr[i+1]-arr[i]));
    }
    int ans = 0;
    while(arr.size()>2){
        int mini = 9999;
        int minp = -1;
        rep(i,diffs.size()){
            if(mini>=diffs[i]){
                mini = diffs[i];
                minp = i;
            }
        }
        diffs.clear();
        arr.erase(arr.begin()+minp);
        arr.erase(arr.begin()+minp);
        rep(i,arr.size()-1) diffs.pb(abs(arr[i+1]-arr[i]));
        cout<<mini<<endl;
        ans+=mini;
    }
    cout<<ans;
}
