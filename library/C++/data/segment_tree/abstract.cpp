template <class T> struct SegmentTree{
    using F = function<T(T, T)>;
    int n; vector<T> node; F combine; T identity;
    SegmentTree(int n, F combine, T identity) : n(n), node(n<<1, identity), combine(combine), identity(identity) {}
    T operator[](int ind){ return node[ind+n]; }
    void update(int i, int x){ node[i+=n] = x; while(i >>= 1) node[i] = combine(node[i<<1|0], node[i<<1|1]); }
    T get(int l, int r){
        T res = identity;
        for(l += n, r += n; l < r; l >>= 1, r >>= 1){
            if(l & 1) res = combine(res, node[l++]);
            if(r & 1) res = combine(node[--r], res);
        }
        return res;
    }
};