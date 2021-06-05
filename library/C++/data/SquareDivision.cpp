namespace SquareDivision{
    template <class T> struct bucket{
        int m;
        vector<vector<T>> a;
        vector<T> sub;
        bucket(int n){ m = sqrt(n) + 1; a.resize(m, vector<T>(m)); sub.resize(m); }
        T operator[](int x){ return a[x/m][x%m]; }
        void add(int x){ a[x/m][x%m]++; sub[x/m]++; }
        void add(int x, int y){ a[x/m][x%m] += y; sub[x/m] += y; }
        void remove(int x){ a[x/m][x%m]--; sub[x/m]--; }
        void remove(int x, int y){ a[x/m][x%m] -= y; sub[x/m] -= y; }
        int get(int x){
            int p = 0;
            for(; p < m && sub[p] < x; p++) x -= sub[p];
            for(int i = 0; i < m; i++){ x -= a[p][i]; if(x <= 0) return p * m + i; }
            return -1;
        }
    };
}