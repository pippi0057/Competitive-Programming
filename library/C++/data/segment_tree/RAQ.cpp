template <class T> struct RAQ {
    int n;
    vector<T> seg;
    RAQ(int n) : n(n) { int x = 1; while(n > x) x *= 2; n = x; seg.resize(n * 2, 0); }
    RAQ(int n, int a) : n(n) { int x = 1; while(n > x) x *= 2; n = x; seg.resize(n * 2, a); }
    void add(int l, int r, T x){
        l += n + 1; r += n + 1;
        while(l < r){
            if(l % 2 == 1) seg[l] += x, l++; l /= 2;
            if(r % 2 == 1) seg[r-1] += x, r--; r /= 2;
        }
    }
    T get(int ind){
        ind += n + 1; T sum = 0; sum += seg[ind];
        while(1){ ind /= 2; if(ind == 0) break; sum += seg[ind]; }
        return sum;
    }
    T operator[](int ind){ return get(ind); }
};