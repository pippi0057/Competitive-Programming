/**
 *  binary indexed tree(BIT) [0-indexed]
 *  add(index, x) O(log n)
 *  sum(index) O(log n)
**/

template <class T> struct BIT{
    int n;
    vector<T> bit;
    BIT(int n) : n(n+1), bit(n, 0) {}
    void add(int ind, T x){
        for(int i = ind; i < n; i += ((i+1) & (-i-1)))
            bit[i] += x;
    }
    T sum(int ind){
        T res = 0;
        for(int i = ind-1; i >= 0; i -= ((i+1) & (-i-1)))
            res += bit[i];
        return res;
    }
};
