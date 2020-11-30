struct UnionFind{
    vector<int> parent,siz;
    UnionFind(int n) : parent(n), siz(n,1){
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }
    int root(int x){
        while(parent[x] != x){
            x = parent[x] = parent[parent[x]];
        }
        return x;
    }
    bool unite(int x, int y){
        x = root(x);
        y = root(y);
        if(x == y) return false;
        if(siz[x] < siz[y]) swap(x,y);
        siz[x] += siz[y];
        parent[y] = x;
        return true;
    }
    bool same(int x, int y) {return root(x) == root(y); }
    int size(int x) {return siz[root(x)]; }
};
