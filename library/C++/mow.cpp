ll mow(ll x, ll n){ ll ret = 1; while(n > 0){ if(n & 1) ret = ret * x; x = x * x; n >>= 1; } return ret; }
ll mow(ll x, ll n, ll mod){ ll ret = 1; while(n > 0){ if(n & 1) ret = ret * x % mod; x = x * x % mod; n >>= 1; } return ret; }
