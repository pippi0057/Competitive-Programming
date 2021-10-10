template <class T> struct BIT{
    int n; vector<T> bit;
    BIT(int n){ this->n = n; bit.resize(n, 0); }
    BIT(vector<T> v) : BIT(v.size()) { rep(v.size()) add(i, v[i]); }
    inline void add(int i, T x){ for(; i < n; i = i | (i + 1)) bit[i] += x; }
    inline T sum(int i){
        T res = 0; i--;
        for(; i >= 0; i = (i & (i + 1)) - 1) res += bit[i];
        return res;
    }
};