pair<bool, vector<ll>> bellman_ford(const Graph& g, int s){
    vector<ll> dist(g.size(), inf);
    int cnt = g.size(); dist[s] = 0;
    while(cnt--){
        bool ok = 1;
        for(int from = 0; from < g.size(); from++) for(const auto& [to, cost] : g[from]){
            if(dist[from] != inf && chmin(dist[to], dist[from] + cost)) ok = 0;
        }
        if(ok) break;
    }
    return {cnt + 1, dist};
}
