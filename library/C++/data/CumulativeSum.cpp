namespace CumulativeSum{
    template <class T> struct CumulativeVector{
        vector<T> a;
        CumulativeVector(int n) : a(n, 0) {}
        CumulativeVector(vector<T> v){ a = v; }
        void build(){ for(int i = 1; i < a.size(); i++) a[i] += a[i-1]; }
        T& operator [](int ind){ return a[ind]; }
        operator vector<T>&() const{ return a; }
    };
    template <class T> struct imos1D{
        vector<T> a;
        imos1D(int n) : a(n, 0) {}
        void add(int l, int r, int x){ a[l] += x; a[r] -= x; }
        void build(){ for(int i = 1; i < a.size(); i++) a[i] += a[i-1]; }
        T operator[](int ind){ return a[ind]; }
        operator const vector<T>&() const{ return a; }
    };
    template <class T> struct imos2D{
        vector<vector<T>> a;
        imos2D(int h, int w) : a(h, vector<T>(w, 0)) {}
        void add(int lx, int ly, int rx, int ry, int x){ a[lx][ly] += x; a[rx+1][ry+1] += x; a[lx][ry+1] -= x; a[rx+1][ly] -= x; }
        void build(){
            for(int i = 0; i < a.size(); i++) for(int j = 1; j < a[i].size(); j++) a[i][j] += a[i][j-1];
            for(int j = 0; j < a[0].size(); j++) for(int i = 1; i < a.size(); i++) a[i][j] += a[i-1][j];
        }
        vector<T> operator[](int ind){ return a[ind]; }
        operator const vector<vector<T>>&() const{ return a; }
    };
}