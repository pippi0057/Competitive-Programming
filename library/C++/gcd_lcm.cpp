ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll binary_gcd(ll a, ll b){
    if(!a) return b; if(!b) return a;
    if(~a & 1 && ~b & 1) return binary_gcd(a / 2, b / 2) * 2;
    if(~a & 1) return binary_gcd(a / 2, b); if(~b & 1) return binary_gcd(a, b / 2);
    if(a < b) return binary_gcd(a, (b - a) / 2); return binary_gcd(b, (a - b) / 2);
}
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }
template <class T> ll gcd(vector<T>& v){ ll res = 0; for(auto x : v) res = gcd(res, x); return res; }
template <class T> ll lcm(vector<T>& v){ ll res = 1; for(auto x : v) res = lcm(res, x); return res; }
ll gcdExt(ll a, ll b, ll& x, ll& y){
    if(!b){ x = 1; y = 0; return a; }
    ll d = gcdExt(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
