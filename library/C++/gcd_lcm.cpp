int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a * b / gcd(a, b); }
template <class T> int gcd(vector<T>& v){ int res = 0; for(auto x : v) res = gcd(res, x); return res; }
