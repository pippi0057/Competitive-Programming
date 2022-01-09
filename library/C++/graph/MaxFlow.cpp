template <class T> struct NetWorkFlow{
    using Flow = T;
    const Flow INF = 999999999;
    struct Edge{ int to, rev; Flow cap; };
    vector<vector<Edge>> NetWork;
    NetWorkFlow(int n) : NetWork(n) {}
    void Connect(int from, int to, Flow cap){
        NetWork[from].emplace_back((Edge){to, int(NetWork[to].size()), cap});
        NetWork[to].emplace_back((Edge){from, int(NetWork[from].size() - 1), 0});
    }
    Flow MaxFlow(int s, int t){
        auto copy = NetWork;
        Flow res = 0;
        vector<bool> seen(NetWork.size());
        auto dfs = [&copy, &seen](auto& self, int v, int t, Flow now) -> Flow{
            if(v == t) return now;
            seen[v] = true;
            for(auto& [to, rev, cap] : copy[v]){
                if(!seen[to] && cap > 0){
                    Flow d = self(self, to, t, min(cap, now));
                    if(d > 0){ cap -= d; copy[to][rev].cap += d; return d; }
                }
            }
            return 0;
        };
        while(true){
            fill(seen.begin(), seen.end(), false);
            Flow f = dfs(dfs, s, t, INF);
            if(f == 0) return res; res += f;
        }
    }
};