/**
 *  dijkstra((グラフ名), (始点))
 *  O(e logv)
 *  負の辺があったら使えない
**/

struct Edge { int to; ll cost; Edge(int to, ll cost) : to(to), cost(cost) {} };
using Graph = vector<vector<Edge>>;

// pii, Edge, Graph

vector<ll> dijkstra(const Graph &g, int s){
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
        for(auto e : g[v])
            if(chmin(dist[e.to], dist[v] + e.cost)) task.push({dist[e.to], e.to});
    }
    return dist;
}
