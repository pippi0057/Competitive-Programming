template< typename T >
struct RMQ{
    const T inf = numeric_limits<T>::max();
    int n;
    vector<T> dat;
    RMQ(int n) : n(), dat(n * 4, inf){
        int x = 1;
        while(n > x) x *= 2;
        n = x;
    }
    void update(int i, T x){
        i += n - 1;
        dat[i] = x;
        while(i > 0){
            i = (i - 1) / 2;
            dat[i] = min(dat[i*2+1], dat[i*2+2]);
        }
    }
    T query(int a, int b){ return qs(a, b, 0, 0, n); }
    T qs(int a, int b, int k, int l, int r){
        if(r <= a || b <= l) return inf;
        else if(a <= l && r <= b) return dat[k];
        else{
            T vl = qs(a, b, k * 2 + 1, l, (l + r) / 2);
            T vr = qs(a, b, k * 2 + 2, (l + r) / 2, r);
            return min(vl, vr);
        }
    }
};