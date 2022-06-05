#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define int long long
#define NSN auto
#define ff first
#define ss second
#define eb emplace_back
#define pb push_back
#define pf push_front
#define m_p make_pair
#define ppb pop_back
#define ppf pop_front
#define pi 3.141592653589793238462643383279
#define eachr(v)   for (auto &i : v)   cin >> i
#define eachw(v)   for (auto i : v)    cout << i << ' '
#define For(i, l, r) for (ll i = l; i < r; i++)
#define fFor(i, n) for (ll i = n - 1; i >= 0; i--)
#define FOR(n) for (ll i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define vsort(v) sort(all(v))
#define gsort(v) sort(all(v), greater<>())
#define mn_el(v) *min_element(all(v))
#define mx_el(v) *max_element(all(v))
#define v_sum(v) accumulate(all(v), 0LL)
#define v_cnt(v, x) count(all(v), x)
#define VV vector<ll>
#define VP vector<pair<ll, ll>>
ll mod = 1000000007;
ll MAX = 1e9;

ll _gcd(ll a, ll b){
    return b < 1 ? a : _gcd(b, a % b);
}

NSN _lcm(ll a, ll b){
    return a * b / _gcd(a, b);
}

VV primes;
NSN _allprime(ll n){
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (ll p = 2; p * p <= n; p++)    {
        if (prime[p] == true)        {
            for (ll i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (ll p = 2; p <= n; p++)
        if (prime[p])primes.pb(p);
}

NSN _isprime1(ll x){
    if (x < 2)
        return false;
    for (ll i = 2; i * i <= x; ++i)    {
        if (x % i == 0)
            return false;
    }
    return true;
}

map<ll, ll> _factors;
NSN _primefactors(ll n){
    ll x = n;
    ll i = 2;
    while (i * i <= x)    {
        while (n % i == 0)        {
            _factors[i]++;
            n /= i;
        }
        i++;
    }
    if (n > 1)
        _factors[n]++;
}

NSN _binpow(ll x, ll n, ll mod){
    ll ans = 1;
    while (n != 0){
        if (n & 1)
            ans = ans * x % mod;
        x = x * x % mod;
        n = n >> 1;
    }
    return ans;
}

NSN _dist(ll x1, ll y1, ll x2, ll y2){
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

NSN _tobase(ll num, ll base){
    string ret = "";
    while (num > 0)    {
        ll mod = num % base;
        if (mod < 10)
            ret = to_string(mod) + ret;
        else
            ret = char(mod - 10 + 'a') + ret;
        num /= base;
    }
    return ret;
}

NSN _modinverse(ll a, ll b){
    ll b0 = b, t, q;
    NSN x0 = 0, x1 = 1;
    if (b == 1)
        return 1;
    while (a > 1)    {
        q = a / b;
        t = b, b = a % b, a = t;
        t = x0, x0 = x1 - q * x0, x1 = t;
    }
    if (x1 < 0)
        x1 += b0;
    return x1;
}
NSN _miillerTest(int d, int n)
{
  int a = 2 + rand() % (n - 4);

  int x = _binpow(a, d, n);

  if (x == 1  x == n-1)
  return true;
  while (d != n-1)
  {
    x = (x * x) % n;
    d *= 2;

    if (x == 1)   return false;
    if (x == n-1) return true;
  }
  return false;
}
NSN _isprime2(int n, int k = 4)
{
  if (n <= 1  n == 4) return false;
  if (n <= 3) return true;

  int d = n - 1;
  while (d % 2 == 0)
    d /= 2;
  for (int i = 0; i < k; i++)
    if (!_miillerTest(d, n))
      return false;

  return true;
}
NSN _solve(){
  ll n;
  cin >> n;
  VV v(n);
  eachr(v);
  gsort(v);
  cout << v[0] + v[1];
}
NSN main()->signed{
    mt19937 rnd(time(NULL));
    clock_t tStart = clock();
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    ll test = 1;
    cin >> test;
    while (test-- > 0)
        _solve(), cout << endl;
    clog << setprecision(5) << fixed << "Time: " << (double)(clock() - tStart) / CLOCKS_PER_SEC << " ms";
    return 0;
}
