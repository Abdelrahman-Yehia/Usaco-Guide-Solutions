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
map<ll,ll> freq;
bool comp(ll a,ll b)
{
    return freq[a] > freq[b];
}

bool comp2(ll a,ll b)
{
    return a > b;
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

int power2(int a, unsigned int n, int p)
{
    int res = 1;      // Initialize result
    a = a % p;  // Update 'a' if 'a' >= p

    while (n > 0)
    {
        // If n is odd, multiply 'a' with result
        if (n & 1)
            res = (res*a) % p;

        // n must be even now
        n = n>>1; // n = n/2
        a = (a*a) % p;
    }
    return res;
}



// If n is prime, then always returns true, If n is
// composite than returns false with high probability
// Higher value of k increases probability of correct
// result.
bool isPrime(unsigned int n, int k)
{
    // Corner cases
    if (n <= 1 || n == 4)
        return false;
    if (n <= 3)
        return true;

    // Try k times
    while (k>0)
    {
        // Pick a random number in [2..n-2]
        // Above corner cases make sure that n > 4
        int a = 2 + rand()%(n-4);

        // Checking if a and n are co-prime
        if (gcd(n, a) != 1)
            return false;

        // Fermat's little theorem
        if (power2(a, n-1, n) != 1)
            return false;

        k--;
    }

    return true;
}

vector<int> primes;

void SieveOfEratosthenes(int n)
{
    // Create a boolean array
    // "prime[0..n]" and initialize
    // all entries it as true.
    // A value in prime[i] will
    // finally be false if i is
    // Not a prime, else true.
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++)
    {
        // If prime[p] is not changed,
        // then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples
            // of p greater than or
            // equal to the square of it
            // numbers which are multiple
            // of p and are less than p^2
            // are already been marked.
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    // Print all prime numbers
    for (int p = 2; p <= n; p++)
        if (prime[p])
            primes.pb(p);
}
/**************************************************/

using namespace std;

const int MAX = 100005;
int a[MAX];




int main()
{

    //freopen("tttt.in","r",stdin);
    //freopen("tttt.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char board[3][3];
    int ones = 0, twos = 0;
    rep(i,3){
        rep(j,3){
            cin>>board[i][j];
        }
    }
    vector<set<int>> rows;
    vector<set<int>> cols;
    rep(i,3){
        set<int> curr;
        rep(j,3){
            curr.insert(board[i][j]);
        }
        rows.pb(curr);
    }
    rep(i,3){
        set<int> curr;
        rep(j,3){
            curr.insert(board[j][i]);
        }
        cols.pb(curr);
    }
    set<int> dgl1;
    set<int> dgl2;
    rep(i,3){
        dgl1.insert(board[i][i]);
    }
    rep(i,3){
        dgl2.insert(board[i][3-i-1]);
    }

    rep(i,3){
        if(rows[i].size()==2) twos++;
        else if(rows[i].size()==1) ones++;
        if(cols[i].size()==2) twos++;
        else if(cols[i].size()==1) ones++;
    }
    if(dgl1.size()==2) twos++;
    else if(dgl1.size()==1) ones++;
    if(dgl2.size()==2) twos++;
    else if(dgl2.size()==1) ones++;
    cout<<ones<<endl;
    cout<<twos<<endl;
}
