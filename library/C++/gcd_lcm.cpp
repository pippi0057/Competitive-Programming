ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }
template <class T> ll gcd(vector<T>& v){ ll res = 0; for(auto x : v) res = gcd(res, x); return res; }
template <class T> ll lcm(vector<T>& v){ ll res = 1; for(auto x : v) res = lcm(res, x); return res; }
ll gcdExt(ll a, ll b, ll& x, ll& y){
    if(!b){ x = 1; y = 0; return a; }
    ll d = gcdExt(b, a % b, y, x);
    y -= a / b * x;
    return d;
}