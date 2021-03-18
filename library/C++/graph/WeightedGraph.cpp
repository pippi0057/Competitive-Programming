struct WeightedGraph{
    struct Edge { int to; ll cost; Edge(int to, ll cost) : to(to), cost(cost) {} };
    vector<vector<Edge>> g;
    WeightedGraph(int n) : g(n) {}
    vector<Edge> operator[](int a){ return g[a]; }
    operator vector<vector<Edge>>(){ return g; }
    auto begin(){ return g.begin(); }
    auto end(){ return g.end(); }
    int size(int x){ return g.size(); }
    void resize(int x){ g.resize(x); }
    void DirectConnect(int f, int t, ll c){ g[f].push_back({t, c}); }
    void Connect(int a, int b, ll c){ g[a].push_back({b, c}); g[b].push_back({a, c}); }
    vector<ll> dijkstra(int s){
        int n = g.size();
        vector<ll> dist(n, inf);
        priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> task;
        dist[s] = 0;
        task.push({dist[s], s});
        while(task.size()){
            pii p = task.top();
            task.pop();
            int v = p.second;
            if(dist[v] < p.first) continue;
            for(auto e : g[v]) if(chmin(dist[e.to], dist[v] + e.cost)) task.push({dist[e.to], e.to});
        }
        return dist;
    }
    vector<int> topo_sort(){
        int n = g.size();
        WeightedGraph copy(n);
        vector<int> deg(n), order;
        queue<int> task;
        rep(n) for(auto v : g[i]){
            copy.DirectConnect(v.to, i, v.cost);
            deg[i]++;
        }
        rep(n) if(!deg[i]) task.push(i);
        while(task.size()){
            int fv = task.front();
            task.pop();
            order.push_back(fv);
            for(auto nv : copy[fv]){
                deg[nv.to]--;
                if(!deg[nv.to]) task.push(nv.to);
            }
        }
        reverse(all(order));
        return order;
    }
};